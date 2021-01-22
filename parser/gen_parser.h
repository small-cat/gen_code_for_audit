#ifndef __GEN_PARSER_H__
#define __GEN_PARSER_H__

#include <fstream>

class GenParser {
public:
  GenParser();
  virtual ~GenParser();

  void GetFileName();
  void ParseG4File(const std::string& filename, const std::string& db_type);

  void WriteHeaderFileHead(const std::string& db_type);
  void WriteHeaderFileTail(const std::string& db_type);
  void WriteSrcFileHead();
  void WriteSrcFileTail();

  std::string header_file();
  std::string cpp_src_file();
private:
  std::string TrimStringTail(const std::string& str, const std::string& delim="Parser");

  std::string header_file_;
  std::string cpp_src_file_;

  std::string parser_name_;
  std::string class_name_;
};

#endif /* __GEN_PARSER_H__ */
