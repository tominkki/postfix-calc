#include "postfix.h"

void Postfix::help(void) const {
  std::cout << "Postfix calculator using reverse-polish notation.\n"
    << "Usage: postfix [OPTION] or postfix [EXPRESSION]\n\n"
    << "Options:\n"
    << "\t-h\tPrints summarized message about usage.\n"
    << "\t-p\tStarts postfix calculator with prompt.\n\n"
    << "Commands:\n"
    << "\tq\tQuits prompt.\n"
    << "\tp\tPrints top entry of stack.\n"
    << "\tf\tPrints entries of whole stack.\n"
    << "\tc\tClears stack.\n"
    << "\tx\tExchanges values of two top entries together.\n\n"
    << "Arithmetic operations:\n"
    << "\t+\tPops two top entries from stack, sums them and pushes result to stack.\n"
    << "\t-\tPops two top entries from stack, subtracts first popped from second and pushes result to stack.\n"
    << "\t*\tPops two top entries from stack, multiplies them together and pushes result to stack. Use \\* when using as cli argument.\n"    
    << "\t/\tPops two top entries form stack, divides second popped with first popped and pushes result to stack.\n"
    << "\t%\tPops two top entries from stack, calculates remainder of division and pushes result to stack.\n"
    << "\t^\tPops two top entries from stack, calculates power by using first as exponent and second as base. Pushes result to stack.\n"
    << "\tv\tPops top entry from stack, calculates square root and pushes result to stack.\n"
    << "\ts\tPops all entries from stack, sums them and pushes result to stack.\n"
    << "\ta\tPops all entries from stack, calculates average and pushes result to stack.\n";
}

char Postfix::parse_arg(std::string arg) const {
  char parsed;

  if (arg.length() == 1) {
    parsed = arg[0];
  } else if (arg.length() == 2) {
    if (arg == "-h") {
      parsed = '@';
    } else if (arg == "-p") {
      parsed = '`';
    } else {
      parsed = '#';
    }
  } else {
    parsed = '#';
  }

  return parsed;
}

bool Postfix::is_double(const char* arg) const {
  bool result = true;
  try {
    double tmp = std::stod(arg);
  } catch (...) {
    result = false;
  }

  return result;
}

bool Postfix::is_option(const char* arg) const {
  std::string str(arg);
  if (str == "-h" || str == "-p") {
    return true;
  }
  return false;
}

bool Postfix::is_command(const char* arg) const {
  std::string str(arg);
  std::string commands[14] = {
    "q", "p", "f", "c", "x", "+", "-", "*", "/", "%", "^", "v", "s", "a"
  };

  for (auto command : commands) {
    if (str == command) {
      return true;
    }
  }

  return false;
}
