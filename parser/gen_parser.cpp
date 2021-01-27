#include <stdlib.h>
#include <unistd.h>

#include "gen_parser.h"
#include "../syntax/generated/AuditGenLexer.h"
#include "../syntax/generated/AuditGenParser.h"
#include "../syntax/generated/AuditGenParserBaseVisitor.h"
#include "gen_visitor.h"
#include "error_verbose_listener.h"

using namespace antlr4;

GenParser::GenParser() {}
GenParser::~GenParser() {}

void GenParser::GetFileName() {
  if (parser_name_.empty()) {
    std::cout << "Error: parser name is empty." << std::endl;
    exit(-1);
  }

  class_name_ = "Get" + parser_name_ + "OperateInfoListener";

  char buf[255] = {0};
  if (getcwd(buf, sizeof(buf)) == nullptr) {
    std::cout << "get current path failed." << std::endl;
    exit(-1);
  }

  header_file_ = std::string(buf) + "/" + class_name_ + ".h";
  cpp_src_file_ = std::string(buf) + "/" + class_name_ + ".cpp";
}

std::string GenParser::header_file() {
  return header_file_;
}

std::string GenParser::cpp_src_file() {
  return cpp_src_file_;
}

void GenParser::WriteHeaderFileHead(const std::string& db_type) {
  std::ofstream fhead;
  fhead.open(header_file_, std::ios::binary | std::ios::app | std::ios::out);

  fhead << "#pragma once" << "\n";

  std::string g4_parser = TrimStringTail(parser_name_, "Parser");

  fhead << "#include \"" << g4_parser << "Parser.h\"" << "\n";
  fhead << "#include \"" << g4_parser << "Lexer.h\"" << "\n";
  fhead << "#include \"" << g4_parser << "ParserBaseListener.h\"" << "\n";
  fhead << "#include \"IParser.h\"" << "\n";
  fhead << "#include \"item.h\"" << "\n";
  fhead << "#include \"get_operate_info_from_dag.h\"" << "\n";

  fhead << "\n";
  fhead << "namespace " << db_type <<" {" << "\n";
  fhead << "class " << class_name_ << " : pubic " << g4_parser << "ParserBaseListener {" << "\n";
  fhead << "public:" << "\n";
  fhead << "  " << class_name_ << "(" << g4_parser << "Parser* parser" << ");" << "\n";
  fhead << "  virtual ~" << class_name_ << "();" << "\n";

  fhead << "\n";
  fhead << "  std::vector<OperateInfo> operate_info_list();" << "\n";

  fhead.close();
}

std::string GenParser::TrimStringTail(const std::string& str, const std::string& delim) {
  std::string g4_parser;
  std::size_t pos;
  if ((pos = str.rfind(delim)) != std::string::npos) {
    g4_parser = str.substr(0, pos);
  } else {
    g4_parser = str;
  }

  return g4_parser;
}

void GenParser::WriteHeaderFileTail(const std::string& db_type) {
  std::ofstream fhead;
  fhead.open(header_file_, std::ios::binary | std::ios::app | std::ios::out);

  std::string g4_parser = TrimStringTail(parser_name_, "Parser");

  fhead << "private:" << "\n";
  fhead << "  " << g4_parser << "Parser *parser_;" << "\n";
  fhead << "  antlr4::TokenStream * tokens_;" << "\n";
  fhead << "\n";

  fhead << "  parser::OperateInfo operate_info_;" << "\n";
  fhead << "  std::vector<parser::OperateInfo> operate_info_list_;" << "\n";
  fhead << "};" << "\n";
  fhead << "} // end namespace " << db_type << "\n";

  fhead.close();
}

void GenParser::WriteSrcFileHead(const std::string& db_type) {
  std::ofstream fsrc;
  fsrc.open(cpp_src_file_, std::ios::binary | std::ios::app | std::ios::out);

  fsrc << "#include \"" << class_name_ + ".h"<< "\"\n";
  fsrc << "\n";

  fsrc << "namespace " << db_type << " {\n";
  // fsrc << "using namespace antlr4;\n";
  fsrc << "using namespace sqlparse;\n";

  // constructure and destructure
  std::string g4_parser = TrimStringTail(parser_name_, "Parser");
  fsrc << "\n";
  fsrc << class_name_ << "::" << class_name_ << "(" << g4_parser << "Parser * parser) : parser_(parser) {\n";
  fsrc << "  tokens_ = parser_->getTokenStream();\n";
  fsrc << "}\n";

  fsrc << class_name_ << "::~" << class_name_ << "() {}\n"; 
  fsrc << "\n";

  // common interface
  fsrc << "std::vector<parser::OperateInfo> " << class_name_ << "::" << "operate_info_list() {\n";
  fsrc << "  return operate_info_list_;\n";
  fsrc << "}\n";
  fsrc << "\n";

  fsrc.close();
}

void GenParser::WriteSrcFileTail(const std::string& db_type) {
  std::ofstream fsrc;
  fsrc.open(cpp_src_file_, std::ios::binary | std::ios::app | std::ios::out);

  // SetOperateInfo
  fsrc << "void " << class_name_ << "::" << "SetOperateInfo(parsre::OperateInfo& op, const std::string& operate, const std::string& objType) {\n";
  fsrc << "  op.clear();\n";
  fsrc << "  op.operate = operate;\n";
  fsrc << "  op.objectType = objType;\n";
  fsrc << "}\n";

  fsrc << "\n";
  fsrc << "parsre::OperateObject " << class_name_ << "::" << "CreateOperateObject(const std::string& objectName) {\n";
  fsrc << "  return {objectName, {}};\n";
  fsrc << "}\n";
  fsrc << "\n";

  fsrc << "} // end namespace " << db_type << " \n";

  fsrc.close();
}

void GenParser::ParseG4File(const std::string& filename, const std::string& db_type) {
  ANTLRFileStream input(filename);
  AuditGenLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    std::cout << token->toString() << "\n";
  }

  AuditGenParser parser(&tokens);
    // add a new error listener
  ErrorVerboseListener err_listener;
  parser.removeErrorListeners();
  parser.addErrorListener(&err_listener);

  auto multi_stmts_ctx = parser.multi_stmts();
  if (err_listener.has_error()) {
    std::cout << "Parse failed" << "\n";
    std::cout << err_listener.get_err_message() << "\n";
    std::cout << ((tree::ParseTree*)multi_stmts_ctx)->toStringTree(&parser) << "\n";
    
    return;
  }
  std::cout << ((tree::ParseTree*)multi_stmts_ctx)->toStringTree(&parser) << "\n";

  auto stmts_ctx = multi_stmts_ctx->stmt();
  for (auto& stmt_ctx : stmts_ctx) {
    AuditGenVisitor aud(&parser);
    aud.visitStmt(stmt_ctx);

    if (stmt_ctx->header_stmt()) {
      parser_name_ = aud.parser_name();
      GetFileName();
      WriteHeaderFileHead(db_type);
      WriteSrcFileHead(db_type);
    } else if (stmt_ctx->cfg_rule_stmt()) {
      auto objs = aud.GetObjects();
      for (auto obj : objs) {
        if (!obj.IsEmpty()) {
          obj.PrintObject(parser_name_);
        }
      }
    } else {
      continue;
    }
  }

  WriteHeaderFileTail(db_type);
  WriteSrcFileTail(db_type);
}
