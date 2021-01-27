#pragma once
#include "MathParser.h"
#include "MathLexer.h"
#include "MathParserBaseListener.h"
#include "IParser.h"
#include "item.h"
#include "get_operate_info_from_dag.h"

namespace math {
class GetMathOperateInfoListener : pubic MathParserBaseListener {
public:
  GetMathOperateInfoListener(MathParser* parser);
  virtual ~GetMathOperateInfoListener();

  std::vector<OperateInfo> operate_info_list();
  virtual void enterUnaryExpr(MathParser::UnaryExprContext * ctx);
  virtual void enterMulDivExpr(MathParser::MulDivExprContext * ctx);
  virtual void enterFuncExpr(MathParser::FuncExprContext * ctx);
  virtual void enterNumExpr(MathParser::NumExprContext * ctx);
  virtual void enterSqlExpr(MathParser::SqlExprContext * ctx);
private:
  MathParser *parser_;
  antlr4::TokenStream * tokens_;

  parser::OperateInfo operate_info_;
  std::vector<parser::OperateInfo> operate_info_list_;
};
} // end namespace math
