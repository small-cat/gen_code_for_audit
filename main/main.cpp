// Copyright (C) 2019 secsmart
// author: owen lee

#include <unistd.h>
#include <iostream>
#include "../parser/gen_parser.h"

struct Options {
  std::string filename;
  std::string db_type;
};

void PrintUsage(const char* str);
void ParseFile(const Options &opt);

int main(int argc, char *argv[]) {
  if (5 != argc) {
    PrintUsage(argv[0]);
    return 0;
  }

  Options opts;
  int opt = 0;
  while ((opt = getopt(argc, argv, "f:t:")) != -1) {
    if (opt == 'f') {
      opts.filename = std::string(optarg);
    } else if (opt == 't') {
      opts.db_type = std::string(optarg);
    } else {
      PrintUsage(argv[0]);
      return 0;
    }
  }

  if (opts.filename.empty() || opts.db_type.empty()) {
    PrintUsage(argv[0]);
    return 0;
  }

  ParseFile(opts);
  
  return 0;
}

void PrintUsage(const char* str) {
  std::cout << "Usage: " << str << " [-f filename] [-t db_type]" << "\n";
  std::cout << "Options:" << std::endl;
  std::cout << "  -f specify grammar file" << std::endl;
  std::cout << "  -e specify database type" << std::endl;
}

void ParseFile(const Options &opt) {
  GenParser parser;
  parser.ParseG4File(opt.filename, opt.db_type);
}


