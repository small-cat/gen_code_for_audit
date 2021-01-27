#include "GetMathOperateInfoListener.h"

namespace math {
using namespace sqlparse;

GetMathOperateInfoListener::GetMathOperateInfoListener(MathParser * parser) : parser_(parser) {
  tokens_ = parser_->getTokenStream();
}
GetMathOperateInfoListener::~GetMathOperateInfoListener() {}

std::vector<parser::OperateInfo> GetMathOperateInfoListener::operate_info_list() {
  return operate_info_list_;
}

void GetMathOperateInfoListener::enterUnaryExpr(MathParser::UnaryExprContext * ctx) { 
  std::string opstr;
  opstr = ctx->UNARY_EXPR()->getText();

  std::string opty_str;
  opty_str = "TABLE";

  SetOperateInfo(operate_info_, opstr, opty_str);
  operate_info_list_.push_back(operate_info_);
}

void GetMathOperateInfoListener::enterMulDivExpr(MathParser::MulDivExprContext * ctx) { 
  std::string opstr;
  opstr = ctx->BINARY_EXPR()->getText();

  std::string opty_str;
  std::string tmp_opty;
  if (ctx->MUL()) {
    tmp_opty = tokens_->getText(ctx->MUL());
  } else  if (ctx->DIV()) {
    tmp_opty = tokens_->getText(ctx->DIV());
  }
  opty_str = tmp_opty;

  SetOperateInfo(operate_info_, opstr, opty_str);
  operate_info_list_.push_back(operate_info_);
}

void GetMathOperateInfoListener::enterFuncExpr(MathParser::FuncExprContext * ctx) { 
  std::string opstr;
  opstr = ctx->CREATE()->getText();

  std::string opty_str;
  opty_str = ctx->FUNCTION()->getText();

  std::string objstr;
  objstr = tokens_->getText(ctx->ID());
  auto obj = CreateOperateObject(objstr);
  operate_info_.objects.push_back(obj);

  SetOperateInfo(operate_info_, opstr, opty_str);
  operate_info_list_.push_back(operate_info_);
}

void GetMathOperateInfoListener::enterNumExpr(MathParser::NumExprContext * ctx) { 
  std::string opstr;
  opstr = ctx->NUM()->getText();

  std::string opty_str;
  opty_str = "TABLE";

  std::string objstr;
  std::string tmp_obj;
  if (ctx->tablename()) {
    tmp_obj = tokens_->getText(tablename);
  }
  objstr = tmp_obj;
  auto obj = CreateOperateObject(objstr);
  operate_info_.objects.push_back(obj);

  SetOperateInfo(operate_info_, opstr, opty_str);
  operate_info_list_.push_back(operate_info_);
}

void GetMathOperateInfoListener::enterSqlExpr(MathParser::SqlExprContext * ctx) { 
  std::string opstr;
  std::string tmp_op;
  if (ctx->CREATE()) {
    tmp_op = tokens_->getText(ctx->CREATE());
  } else  if (ctx->DELETE()) {
    tmp_op = tokens_->getText(ctx->DELETE());
  } else  if (ctx->UPDATE()) {
    tmp_op = tokens_->getText(ctx->UPDATE());
  }
  opstr = tmp_op;

  std::string opty_str;
  std::string tmp_opty;
  if (ctx->TABLE()) {
    std::string tmp_opty_var;
    if (ctx->TEMPORARY()) {
      tmp_opty_var = ctx->TEMPORARY()->getText();
    }
    tmp_opty += tmp_opty_var;
    tmp_opty_var = ctx->TABLE()->getText();
    tmp_opty += " " + tmp_opty_var;
  } else  if (ctx->VIEW()) {
    tmp_opty = tokens_->getText(ctx->VIEW());
  } else  if (ctx->TEMP() && ctx->TRIGGER()) {
    std::string tmp_opty_var;
    tmp_opty_var = ctx->TEMP()->getText();
    tmp_opty += tmp_opty_var;
    tmp_opty_var = ctx->TRIGGER()->getText();
    tmp_opty += " " + tmp_opty_var;
  }
  opty_str = tmp_opty;

  std::string objstr;
  objstr = tokens_->getText(ctx->identifier());
  auto obj = CreateOperateObject(objstr);
  operate_info_.objects.push_back(obj);

  SetOperateInfo(operate_info_, opstr, opty_str);
  operate_info_list_.push_back(operate_info_);
}

void GetMathOperateInfoListener::SetOperateInfo(parsre::OperateInfo& op, const std::string& operate, const std::string& objType) {
  op.clear();
  op.operate = operate;
  op.objectType = objType;
}

parsre::OperateObject GetMathOperateInfoListener::CreateOperateObject(const std::string& objectName) {
  return {objectName, {}};
}

} // end namespace math 
