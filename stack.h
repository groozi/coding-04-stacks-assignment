/*********************************************
 * Name: Graziella Buitron
 * Coding 04
 * Purpose: To create a stack object that will 
 * work with a struct data type called Data.
 *********************************************/

#ifndef STACK_H
#define STACK_H

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
//#include "main.h"
#include <iostream> //delete this later

#define MIN_SIZE 2  //minimum size for stack

class Stack {

public:

    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */

    //CONSTRUCTORS/DESTRUCTORS
    Stack(int); //constructor receives int for size
    ~Stack(); //destructor

    //function prototypes
    bool push(int, string*);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();

    
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need.
    // do not modify them or add any other attributes
    int top;
    int size;
    //this is a pointer to a pointer that points to struct datas
    Data **stack;
};

#endif //STACK_H
