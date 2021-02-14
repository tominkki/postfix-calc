#include "stack.h"

template<typename T>
Stack<T>::Stack(void) {
  this->_stack = new T[this->_size];
}

template<typename T>
Stack<T>::~Stack() {}

template<typename T>
void Stack<T>::extend(void) {
  T* new_stack = new T[this->_size * 2];

  for(int i = 0; i < this->_size; i++) {
    new_stack[i] = this->_stack[i];
  }

  delete [] this->_stack;

  this->_stack = new_stack;
  this->_size = this->_size * 2;
}

template<typename T>
void Stack<T>::shrink(void) {
  T* new_stack = new T[this->_size / 2];

  for(int i = 0; i < this->_count; i++) {
    new_stack[i] = this->_stack[i];
  }

  delete [] this->_stack;

  this->_stack = new_stack;
  this->_size = this->_size / 2;
}

template<typename T>
T Stack<T>::top(void) const {
  if (this->empty()) {
    throw "Stack is empty.";
  }

  return this->_stack[this->_count - 1];
}

template<typename T>
bool Stack<T>::empty(void) const {
  return this->_count == 0;
}

template<typename T>
unsigned int Stack<T>::size(void) const {
  return this->_count;
}

template<typename T>
void Stack<T>::push(T entry) {
  if (this->_count == this->_size) {
    this->extend();
  }

  this->_stack[this->_count] = entry;
  this->_count++;
}

template<typename T>
T Stack<T>::pop(void) {
  if (this->empty()) {
    throw "Can not pop from empty stack.";
  }

  if (this->_count < this->_size / 2 - this->_size / 8 && 64 < this->_size) {
    this->shrink();
  }

  this->_count--;

  return this->_stack[this->_count];
}
