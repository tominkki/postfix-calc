#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

#include "../stack/stack.h"

class Postfix {
  private:
    Stack<double> _stack;
    bool _prompt = false;
  
    //postfix.cc
    void prompt(void);
    void execute(std::string command);

    //postfix.misc.cc
    void help(void) const;
    char parse_arg(std::string arg) const;
    bool is_double(const char* arg) const;
    bool is_option(const char* arg) const;
    bool is_command(const char* arg) const;

    //postfix.stack.cc
    void print_top(void) const;
    void print_stack(void);
    void clear_stack(void);
    void exchange(void);

    //postfix.arithmetic.cc
    void add(void);
    void subtract(void);
    void multiply(void);
    void divide(void);
    void sum(void);
    void average(void);
    void remainder(void);
    void power(void);
    void sqroot(void);

  public:
  
    //postfix.cc
    Postfix(void);
    ~Postfix();
    void run(int argc, char** argv);
};

#endif