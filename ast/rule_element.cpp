#include "rule_element.h"

namespace ast {
int RuleElement::UNIQ_ID = 0;

std::string RuleElement::GetUniqId() {
  return std::to_string(UNIQ_ID++);
}
} /* ast */