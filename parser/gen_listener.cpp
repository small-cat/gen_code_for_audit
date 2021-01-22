#include <string.h>

#include "gen_listener.hpp"

AuditGenListener::AuditGenListener(AuditGenParser * p) : parser_(p) {
  tokens_ = parser_->getTokenStream();
}

AuditGenListener::~AuditGenListener() {}

void AuditGenListener::enterHeader_stmt(AuditGenParser::Header_stmtContext * ctx) {
  auto parser_name_ctx = ctx->parser_lexer_name();
  if (parser_name_ctx) {
    parser_name_ = tokens_->getText(parser_name_ctx);
  }
}

void AuditGenListener::enterCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext * ctx) {
  auto rule_name_ctx = ctx->rule_name();
  gen_obj_.SetRuleName(tokens_->getText(rule_name_ctx));
}

void AuditGenListener::enterCfg_rule(AuditGenParser::Cfg_ruleContext * ctx) {
  // auto rule_comps = ctx->rule_component();
  // for (auto& comp : rule_comps) {
  //   if (comp->label_name()) {
  //     // label = rule_component
  //     std::string lb_name = tokens_->getText(comp->label_name());
  //     auto lb_val = comp->label_value;

  //     if (StrCmp(lb_name, AUDIT_OP)) {
  //       gen_obj_.SetOperate(tokens_->getText(lb_val));
  //     } else if (StrCmp(lb_name, AUDIT_TYPE)) {
  //       if (lb_val->paren_value) {
  //         // lb_val is : LPAREN rule_component* RPAREN, trim parenthesises
  //         std::string tmp = tokens_->getText(lb_val);
  //         tmp = TrimFront(tmp, "(");
  //         tmp = TrimTail(tmp, ")");
  //         gen_obj_.SetOperateType(tmp);
  //       } else {
  //         gen_obj_.SetOperateType(tokens_->getText(lb_val));
  //       }
  //     } else if (StrCmp(lb_name, AUDIT_OBJ)) {
  //       gen_obj_.SetObjectName(tokens_->getText(lb_val));
  //     }
  //   } 
  // }

  // auto label_def_ctx = ctx->label_def();
  // if (label_def_ctx) {
  //   gen_obj_.SetLabel(tokens_->getText(label_def_ctx->identifier()));
  // }
}

void AuditGenListener::exitCfg_rule(AuditGenParser::Cfg_ruleContext * ctx) {
  if (!gen_obj_.Empty()) {
    gen_objects_.push_back(gen_obj_);
    gen_obj_.Clear();
  }
}

void AuditGenListener::PrintObjects(const std::string& parser_name) {
  // print gen objects
  for (auto& obj : gen_objects_) {
    if (obj.Empty()) {
      continue;
    }
    obj.PrintObject(parser_name);
  }
}

std::string AuditGenListener::parser_name() {
  return parser_name_;
}

bool AuditGenListener::StrCmp(const std::string& lhs, const std::string& rhs) {
  return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

std::string AuditGenListener::ToUpperFirst(std::string str) {
  std::transform(str.begin(), str.begin(), str.begin(), 
      [](unsigned char c) {return c&0x1f;});

  return str;
}

std::string AuditGenListener::TrimFront(std::string str, const std::string& delim) {
  std::size_t pos;
  if ((pos = str.find(delim)) != std::string::npos) {
    return str.substr(pos+delim.length());
  }

  return str;
}

std::string AuditGenListener::TrimTail(std::string str, const std::string& delim) {
  std::size_t pos;
  if ((pos = str.rfind(delim)) != std::string::npos) {
    return str.substr(0, pos);
  }

  return str;
}
