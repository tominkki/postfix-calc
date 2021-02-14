#ifndef STACK_H
#define STACK_H

template<typename T>

class Stack {
  private:
    T* _stack;
    unsigned int _size = 256;
    unsigned int _count = 0;

    void extend(void);
    void shrink(void);

  public:
    Stack(void);
    ~Stack();
    T top(void) const;
    bool empty(void) const;
    unsigned int size(void) const;
    void push(T entry);
    T pop(void);
};

#include "stack.cc"
#endif
