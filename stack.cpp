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
Stack::Stack(int enteredSize){
    //if input isn't valid throw exception
    if (!enteredSize >= MIN_SIZE){
        throw -1;
    }
    //this line creates new array of pointers that each point to a data struct
    stack = new Data*[enteredSize];
    top = -1;
    size = enteredSize;
}

//STACK DESTRUCTOR- must add that destructor checks if the stack is empty, 
//if not must deallocate each pointer
//before deleting the entire array of pointers
Stack::~Stack(){
    //add implementation to destructor
}


//PUSH FUNCTION
bool Stack::push(int id, string *info){
    bool pushed = false;

    //checks to see if there is space for one more item to be added to stack
    if (top < size-1){

        if (id > 0 && !info->empty()){
            //create the pointer to data struct
            Data *data;

            //allocate the data structure
            data = new Data;

            //assign 
            data->id = id;
            data->information = *info;
            stack[++top] = data;
            pushed = true;

            std::cout << "ID: " << stack[top]->id << " Information: " << stack[top]->information << std::endl;
        }
    }
    
    return pushed;
}

bool Stack::isEmpty(){
    return top < 0;
}






