#include "postfix.h"

Postfix::Postfix(void) {}

Postfix::~Postfix() {}

void Postfix::run(int argc, char** argv) {
  try {
    if (argc == 2 && this->is_option(argv[1])) {
      this->execute(argv[1]);
    } else if (2 < argc) {
      for (int i = 1; i < argc; i++) {
        if (!this->is_double(argv[i]) && !this->is_command(argv[i])) {
          throw "Invalid arguments.";
        }
      }

      for (int i = 1; i < argc; i++) {
        this->execute(argv[i]);
      }
    } else {
      throw "Invalid arguments.";
    }
  } catch (const char* msg) {
    std::cerr << "Error: " << msg << " Use -h for help.\n";
  }
}

void Postfix::prompt(void) {
  std::cout << "Postfix calculator.\n"
    << "Input expression or option. Use -h for more information.\n";
    
  this->_prompt = true;

  while (this->_prompt) {
    std::string line;
    std::string arg;
    std::vector<std::string> args;

    std::cout << ">>> ";

    std::getline(std::cin, line);
    std::stringstream ss(line);

    while (std::getline(ss, arg, ' ')) {
      args.push_back(arg);
    }

    for (auto arg : args) {
      this->execute(arg);
    }
  }
}

void Postfix::execute(std::string arg) {
  try {
    double num = std::stod(arg);
    this->_stack.push(num);
  } catch (...) {
    switch (this->parse_arg(arg)) {
      case '@': {
        this->help();
        break;
      }
      case '`': {
        if (!this->_prompt) {
          this->prompt();
        }
        break;
      }
      case 'p': {
        this->print_top();
        break;
      }
      case 'f': {
        this->print_stack();
        break;
      }
      case 'c': {
        this->clear_stack();
        break;
      }
      case 'x': {
        this->exchange();
        break;
      }
      case '+': {
        this->add();
        break;
      }
      case '-': {
        this->subtract();
        break;
      }
      case '*': {
        this->multiply();
        break;
      }
      case '/': {
        this->divide();
        break;
      }
      case 's': {
        this->sum();
        break;
      }
      case 'a': {
        this->average();
        break;
      }
      case '%': {
        this->remainder();
        break;
      }
      case '^': {
        this->power();
        break;
      }
      case 'v': {
        this->sqroot();
        break;
      }
      case 'q': {
        this->_prompt = false;
        break;
      }
      default: {
        std::cerr << "> Error: Invalid command '" << arg << "'. Use -h for help.\n";
        break;
      }
    }
  }
}
