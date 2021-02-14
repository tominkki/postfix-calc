#include "postfix.h"

void Postfix::add(void) {
  double sum = 0;

  try {
     if (this->_stack.size() < 2) {
      throw "Stack must have atleast two entries for addition.";
    }

    sum += this->_stack.pop();
    sum += this->_stack.pop();
    this->_stack.push(sum);
  } catch (const char* msg) {
    std::cerr << "> Error in addition: " << msg << '\n';
  }
}

void Postfix::subtract(void) {
  double a, b;

  try {
     if (this->_stack.size() < 2) {
      throw "Stack must have atleast two entries for subtraction.";
    }

    b = this->_stack.pop();
    a = this->_stack.pop();
    this->_stack.push(a - b);
  } catch (const char* msg) {
    std::cerr << "> Error in subtraction: " << msg << '\n';
  }
}

void Postfix::multiply(void) {
  double result = 0;

  try {
     if (this->_stack.size() < 2) {
      throw "Stack must have atleast two entries for multiplication.";
    }

    result = this->_stack.pop();
    result *= this->_stack.pop();
    this->_stack.push(result);
  } catch (const char* msg) {
    std::cerr << "> Error in multiplication: " << msg << '\n';
  }
}

void Postfix::divide(void) {
  double a, b;

  try {
    if (this->_stack.size() < 2) {
      throw "Stack must have atleast two entries for division.";
    }

    b = this->_stack.pop();
    a = this->_stack.pop();
    this->_stack.push(a / b);
  } catch (const char* msg) {
    std::cerr << "> Error in division: " << msg << '\n';
  }
}

void Postfix::sum(void) {
  double result = 0;

  try {
    if (this->_stack.empty()) {
      throw "Can not sum empty stack.";
    }

    while (!this->_stack.empty()) {
      result += this->_stack.pop();
    }
    this->_stack.push(result);
  } catch (const char* msg) {
    std::cerr << "> Error in sum: " << msg << '\n';
  }
}

void Postfix::average(void) {
  double sum = 0;
  double divider = this->_stack.size();

  try {
    if (this->_stack.empty()) {
      throw "Can not count average of empty stack.";
    }

    while (!this->_stack.empty()) {
      sum += this->_stack.pop();
    }
    this->_stack.push(sum / divider);
  } catch (const char* msg) {
    std::cerr << "Error in average: " << msg << '\n';
  }
}
 
void Postfix::remainder(void) {
  double a,b;

  try {
    if (this->_stack.size() < 2) {
      throw "Stack must have atleast two entries for remainder.";
    }

    b = this->_stack.pop();
    a = this->_stack.pop();
    this->_stack.push(std::remainder(a, b));
  } catch (const char* msg) {
    std::cerr << "Error in remainder: " << msg << '\n';
  }
}

void Postfix::power(void) {
  double a,b;

  try {
    if (this->_stack.size() < 2) {
      throw "Stack must have atleast two entries for power.";
    }

    b = this->_stack.pop();
    a = this->_stack.pop();
    this->_stack.push(std::pow(a, b));
  } catch (const char* msg) {
    std::cerr << "Error in power: " << msg << '\n';
  }
}

void Postfix::sqroot(void) {
  double val;

  try {
    if (this->_stack.empty()) {
      throw "Stack must have atleast one entry for square root.";
    } else if (this->_stack.top() < 0) {
      throw "Can not compute square root from negative number.";
    }

    val = this->_stack.pop();
    this->_stack.push(std::sqrt(val));
  } catch (const char* msg) {
    std::cerr << "Error in square root: " << msg << '\n';
  }
}
