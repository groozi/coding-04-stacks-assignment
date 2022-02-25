/*********************************************
 * Name: Graziella Buitron
 * Coding 04
 * Purpose: To create a stack object that will 
 * work with a struct data type called Data.
 *********************************************/

#ifndef STACK_H
#define STACK_H

#include "data.h"

#define MIN_SIZE 2  //minimum size for stack

class Stack {

public:
    Stack(int);
    ~Stack();

    bool push(int, string*);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();
    
private:
    int top;
    int size;
    Data **stack;
};

#endif //STACK_H
