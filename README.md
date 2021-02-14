# Postfix calculator

Simple cli calculator using reverse Polish notation. Part of datastructures and algorithms course.

### Usage
**postfix [OPTION] or postfix [EXPRESSION]**

* Options:
  * **-h** Prints summarized message about usage.
  * **-p** Starts postfix calculator with prompt.

* Commands:
  * **q** Quits prompt.
  * **p** Prints top entry of stack.
  * **f** Prints entries of whole stack.
  * **c** Clears stack.
  * **x** Exchanges values of two top entries together.
  
* Arithmetic operations:
  * **\+** Pops two top entries from stack, sums them and pushes result to stack.
  * **\-** Pops two top entries from stack, subtracts first popped from second and pushes result to stack.
  * **\*** Pops two top entries from stack, multiplies them together and pushes result to stack. Use \\* when using as cli argument.
  * **/** Pops two top entries form stack, divides second popped with first popped and pushes result to stack.
  * **%** Pops two top entries from stack, calculates remainder of division and pushes result to stack.
  * **^** Pops two top entries from stack, calculates power by using first as exponent and second as base. Pushes result to stack.
  * **v** Pops top entry from stack, calculates square root and pushes result to stack.
  * **s** Pops all entries from stack, sums them and pushes result to stack.
  * **a** Pops all entries from stack, calculates average and pushes result to stack.

### Examples
```
$ postfix 12 10 * p 
> 120
```
```
$ postfix -p
>>> 2 3 + p 
> 5
>>> 4 5 6 f 
> 6
> 5
> 4 
> 5
>>> s p q
> 20
```