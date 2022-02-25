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
    if (enteredSize >= MIN_SIZE){
        size = enteredSize;
    } else {
        size = MIN_SIZE;
    }
    stack = new Data*[size];
    this->top = -1;
}

//STACK DESTRUCTOR- must add that destructor checks if the stack is empty, 
//if not must deallocate each pointer
//before deleting the entire array of pointers
Stack::~Stack(){
    if (!isEmpty()){
        for (int i = top; i >= 0; i--){
            delete stack[i];
        }
    }
    delete[] stack;
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

            //remove print statement later. this is for debugging to see if we pushed what we want
            std::cout << "ID: " << stack[top]->id << " Information: " << stack[top]->information << std::endl;
        }
    }
    return pushed;
}

bool Stack::pop(Data *ref){
    bool popped = false;

    //check if stack is empty. if not empty...
    if (!isEmpty()){

        //get data from top of stack and put it in struct data passed from caller
        //stack[top]->id = ref->id;
        //stack[top]->information = ref->information;

        ref->id = stack[top]->id;
        ref->information = stack[top]->information;


        //delete the allocated memory from the top of the stack
        delete stack[top];
        //decrement the stack counter
        top--; 

        //'return' data to caller but not actually
        //return true
        popped = true;

    }
     else{
        //fill passed Data struct with -1 and empty string
        ref->id = -1;
        ref->information = "";
        throw -1;
    }
    return popped;
}

bool Stack::isEmpty(){
    return top < 0;
}

//strictly for debugging purposes
void Stack::dumpStack(){
    std::cout << "Dumping the stack.. " << std::endl;
    if(!isEmpty()){
        for (int i = top; i >=0; i--){
            std::cout << "Stack at " << i << " ID: " << stack[i]->id << " Information: " << stack[i]->information << std::endl;
        }
    } else {
        std::cout << "The stack is empty! :(" << std::endl;
    }

}

bool Stack::peek(Data *ref){
    bool peek = false;

    if (!isEmpty()){
        //get data from top of stack and put it in struct data
        ref->id = stack[top]->id;
        ref->information = stack[top]->information;

        std::cout << "ID: " << ref->id << " Information: " << ref->information << std::endl;

        //'return' data to caller but not actually
        //return true
        peek = true;

    } else{
        //fill passed Data struct with -1 and empty string
        ref->id = -1;
        ref->information = "";
    }
    
    return peek;

}







