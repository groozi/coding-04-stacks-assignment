/*********************************************
 * Name: Graziella Buitron
 * Coding 04
 * Purpose: To create a stack object that will 
 * work with a struct data type called Data.
 *********************************************/

#include "stack.h"

//constructor for stack. if entered size is invalid, sets stack size to default minimum.. 2
Stack::Stack(int enteredSize){
    if (enteredSize >= MIN_SIZE){
        size = enteredSize;
    }else{
        size = MIN_SIZE;
    }
    stack = new Data*[size];
    this->top = -1;
}

//destructor dellocates each pointer in stack then deletes stack itself
Stack::~Stack(){
    for (int i = top; i >= 0; i--){
        delete stack[i];
    }
    delete[] stack;
}

bool Stack::push(int id, string *info){
    bool pushed = false;

    if (top < size - 1){
        //validation that id is non negative and string in non-empty
        if (id > 0 && !info->empty()){
            //creates the pointer to a Data struct then allocates the new Data struct
            Data *data;
            data = new Data;

            //assigning data to new Data struct
            data->id = id;
            data->information = *info;
            stack[++top] = data;
            pushed = true;
        }
    }
    return pushed;
}

bool Stack::pop(Data *ref){
    bool popped = false;

    if (!isEmpty()){
        //gets data from Data struct at top of stack and puts it in empty Data struct passed from caller
        ref->id = stack[top]->id;
        ref->information = stack[top]->information;

        //deletes allocated memory for Data struct at top of stack
        delete stack[top];
        top--; 
        popped = true;
    }else{
        ref->id = -1;
        ref->information = "";
    }
    return popped;
}

bool Stack::peek(Data *ref){
    bool peek = false;

    if (!isEmpty()){
        //get data from top of stack and puts it in struct data
        ref->id = stack[top]->id;
        ref->information = stack[top]->information;
        peek = true;
    }else{
        //fill passed Data struct with -1 and empty string
        ref->id = -1;
        ref->information = "";
    }   
    return peek;
}

bool Stack::isEmpty(){
    return top < 0;
}