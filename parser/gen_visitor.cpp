#include <string.h>

#include "gen_visitor.h"
#include "ast/rule_ele_with_label.h"
#include "ast/rule_ele_question.h"
#include "ast/rule_ele_multi.h"
#include "ast/rule_ele_normal.h"
#include "ast/rule_ele_alt.h"
#include "ast/rule_ele_block.h"

AuditGenVisitor::AuditGenVisitor(AuditGenParser *p) : parser_(p) {
  tokens_ = parser_->getTokenStream();
}

AuditGenVisitor::~AuditGenVisitor() {
  rule_ele_tracker_.Reset();
}

std::string AuditGenVisitor::ToUpperFirst(std::string str) {
  std::transform(str.begin(), str.begin(), str.begin(), 
      [](unsigned char c) {return c&0x1f;});

  return str;
}

bool AuditGenVisitor::StrCmp(const std::string& lhs, const std::string& rhs) {
  return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

std::string AuditGenVisitor::parser_name() {
  return parser_name_;
}

std::vector<AuditGenObject> AuditGenVisitor::GetObjects() {
  return gen_objects_;
}

antlrcpp::Any AuditGenVisitor::visitHeader_stmt(AuditGenParser::Header_stmtContext *ctx) {
  auto parser_name_ctx = ctx->parser_lexer_name();
  if (parser_name_ctx) {
    parser_name_ = tokens_->getText(parser_name_ctx);
  } // else parse syntax error

  return visitChildren(ctx);
}

antlrcpp::Any AuditGenVisitor::visitCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext *ctx) {
  std::string rname = tokens_->getText(ctx->rule_name());
  gen_obj_.SetRuleName(rname);

  auto rules_ctx = ctx->cfg_rule();
  for (auto r : rules_ctx) {
    visit(r);
    gen_objects_.push_back(gen_obj_);

    gen_obj_.Reset();
  }

  return visitChildren(ctx);
}

antlrcpp::Any AuditGenVisitor::visitCfg_rule(AuditGenParser::Cfg_ruleContext *ctx) {
  auto label_ctx = ctx->label_def();
  if (label_ctx) {
    std::string label_name = tokens_->getText(label_ctx->identifier());
    gen_obj_.SetLabel(label_name);
  }

  return visitChildren(ctx);
}

antlrcpp::Any AuditGenVisitor::visitLabel_component(AuditGenParser::Label_componentContext *ctx) {
  auto label_ele_ctx = ctx->label_element();
  ast::RuleElement *ele = visit(label_ele_ctx);

  auto closure_ctx = ctx->closure_sign();
  if (closure_ctx == nullptr) {
    return (antlrcpp::Any)ele;
  }

  if (closure_ctx->QUESTION()) {
    ele = rule_ele_tracker_.CreateInstance<ast::RuleEleQuestion>(ele, tokens_->getText(label_ele_ctx));
  } else {
    // *, +
    ele = rule_ele_tracker_.CreateInstance<ast::RuleEleMulti>(ele, tokens_->getText(label_ele_ctx));
  }

  return (antlrcpp::Any)(ele);
}

antlrcpp::Any AuditGenVisitor::visitAtom_component(AuditGenParser::Atom_componentContext *ctx) {
  auto atom_ctx = ctx->atom();
  ast::RuleElement *ele = visit(atom_ctx);

  auto closure_ctx = ctx->closure_sign();
  if (closure_ctx == nullptr) {
    return (antlrcpp::Any)ele;
  }

  if (closure_ctx->QUESTION()) {
    ele = rule_ele_tracker_.CreateInstance<ast::RuleEleQuestion>(ele, tokens_->getText(atom_ctx));
  } else {
    // *, +
    ele = rule_ele_tracker_.CreateInstance<ast::RuleEleMulti>(ele, tokens_->getText(atom_ctx));
  }

  return (antlrcpp::Any)(ele);
}

antlrcpp::Any AuditGenVisitor::visitBlock_component(AuditGenParser::Block_componentContext *ctx) {
  auto block_ctx = ctx->block();
  ast::RuleElement *ele = visit(block_ctx);

  auto closure_ctx = ctx->closure_sign();
  if (closure_ctx == nullptr) {
    return (antlrcpp::Any)ele;
  }

  if (closure_ctx->QUESTION()) {
    ele = rule_ele_tracker_.CreateInstance<ast::RuleEleQuestion>(ele, tokens_->getText(block_ctx));
  } else {
    // *, +
    ele = rule_ele_tracker_.CreateInstance<ast::RuleEleMulti>(ele, tokens_->getText(block_ctx));
  }

  return (antlrcpp::Any)(ele);
}

antlrcpp::Any AuditGenVisitor::visitLabel_element(AuditGenParser::Label_elementContext *ctx) {
  std::string lname = tokens_->getText(ctx->label_name());

  auto atom_ctx = ctx->atom();
  auto block_ctx = ctx->block();

  ast::RuleElement *ele = nullptr;
  if (atom_ctx) {
    ele = visit(atom_ctx);
  } else {
    ele = visit(block_ctx);
  }

  if (StrCmp(lname, AUDIT_OP)) {
    gen_obj_.SetOperate(ele);
  } else if (StrCmp(lname, AUDIT_TYPE)) {
    gen_obj_.SetOperateType(ele);
  } else if (StrCmp(lname, AUDIT_OBJ)) {
    gen_obj_.SetObject(ele);
  }

  ast::RuleElement *res = rule_ele_tracker_.CreateInstance<ast::RuleEleWithLabel>(ele, lname);
  return (antlrcpp::Any)res;
}

antlrcpp::Any AuditGenVisitor::visitAtom(AuditGenParser::AtomContext *ctx) {
  std::string name = tokens_->getText(ctx->identifier());
  ast::RuleElement *ele = rule_ele_tracker_.CreateInstance<ast::RuleEleNormal>(name);
  return (antlrcpp::Any)ele;
}

antlrcpp::Any AuditGenVisitor::visitBlock(AuditGenParser::BlockContext *ctx) {
  auto alters_ctx = ctx->alternative();
  std::vector<ast::RuleElement *> rule_list;
  for (auto alt_ctx : alters_ctx) {
    ast::RuleElement *ele = visit(alt_ctx);
    rule_list.push_back(ele);
  }

  ast::RuleElement *res = rule_ele_tracker_.CreateInstance<ast::RuleEleBlock>(rule_list);
  return (antlrcpp::Any)res;
}

antlrcpp::Any AuditGenVisitor::visitAlternative(AuditGenParser::AlternativeContext *ctx) {
  auto rules_ctx = ctx->rule_component();
  std::vector<ast::RuleElement *> rule_list;
  for (auto rc : rules_ctx) {
    ast::RuleElement *ele = visit(rc);
    rule_list.push_back(ele);
  }

  ast::RuleElement *res = rule_ele_tracker_.CreateInstance<ast::RuleEleAlt>(rule_list);
  return (antlrcpp::Any)res;
}