#include "postfix.h"

void Postfix::print_top(void) const {
  try {
    double top = this->_stack.top();
    std::cout << "> " << top << '\n';
  } catch (const char* msg) {
    std::cerr << "> Error: " << msg << '\n';
  }
}

void Postfix::print_stack(void) {
  Stack<double> *tmp = new Stack<double>();
  double entry;

  while (!this->_stack.empty()) {
    entry = this->_stack.pop();
    tmp->push(entry);
    std::cout << "> " << entry << '\n';
  }

  while (!tmp->empty()) {
    this->_stack.push(tmp->pop());
  }

  delete tmp;
}

void Postfix::clear_stack(void) {
  while (!this->_stack.empty()) {
    this->_stack.pop();
  }
}

void Postfix::exchange(void) {
  double a, b;
  try {
    if (this->_stack.size() < 2) {
      throw "Stack must have atleast two entries for exchange.";
    }
    a = this->_stack.pop();
    b = this->_stack.pop();
    this->_stack.push(a);
    this->_stack.push(b);
  } catch (const char* msg) {
    std::cerr << "> Error in exchange: " << msg << '\n';
  }
}
