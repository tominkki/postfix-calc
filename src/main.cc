#include <iostream>
#include "./postfix/postfix.h"

int main(int argc, char** argv) {
  Postfix *calc = new Postfix();

  calc->run(argc, argv);

  delete calc;

  return 0;
}
