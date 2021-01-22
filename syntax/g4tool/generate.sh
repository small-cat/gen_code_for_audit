#!/bin/bash
set -o errexit
java -jar ../../tool/antlr-4.7.1-complete.jar -Dlanguage=Cpp -listener -visitor -o ../generated/ AuditGenLexer.g4 AuditGenParser.g4
