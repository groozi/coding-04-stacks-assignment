/*********************************************
 * Name: Graziella Buitron
 * Coding 04
 * Purpose: To create a stack object that will 
 * work with a struct data type called Data.
 *********************************************/

// each cpp includes ONLY it's header directly
#include "stack.h"

/*
 * write all your stack methods here
 */

/*constructor for stack. receives int for size
 * when called, creates pointer 
 *
 */
Stack::Stack(int size){
    if (!size >= MIN_SIZE){
        throw -1;
    }
    //this line creates new array of pointers that each point to a data struct
    stack = new *Data[size];
}

