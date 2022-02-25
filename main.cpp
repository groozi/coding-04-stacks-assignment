/*********************************************
 * Name: Graziella Buitron
 * Coding 04
 * Purpose: To create a stack object that will 
 * work with a struct data type called Data.
 *********************************************/

#include "main.h"

int main(int argc, char **argv){
    srand(time(NULL));

    //first if statement displays error message for invalid amount of arguments
    if (argc == 2){

        int size = atoi(argv[1]);

        //if statement checks for valid size. if size is valid, create the stack and conduct testing. if not, display error
        if (size >= 2){
            //create the stack and declaring what we need for stack testing
            Stack stack(size);

            Data *data; //creating pointer to Data struct to pass into peek() and pop()
            data = new Data; //allocating the empty Data struct

            int testValue;
            std::string strtemp;

            std::cout << "Stack of maximum size " << size << " created." << std::endl << std::endl;
            std::cout << "Beginning stack testing.... " << std::endl << std::endl;

            /*******************************************
             ******** TESTS ON EMPTY STACK** ***********
             ******************************************/
            std::cout << "TESTING OPERATIONS ON EMPTY STACK" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            //testing isEmpty, followed by peek, then pop on empty stack
            if (stack.isEmpty()){
                std::cout << "stack is empty" << std::endl;
            }else{
                std::cout << "stack is NOT empty" << std::endl;
            }
     
            if(stack.peek(data)){
                std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
            }else{
                std::cout << "peek underflow error: stack is empty" << std::endl;
            }

            if (stack.pop(data)){
                std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
            }else {
                std::cout << "pop underflow error... stack is empty" << std::endl;
            }
            std::cout << std::endl;

            /*******************************************
             *** STACK FILLING AND STACK FULL TESTS ***
             ******************************************/
            std::cout << "Testing full operations..." << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "Filling the stack.. " << std::endl;

            //loop fills stack by pushing random strings(empty and non empty) and random test values both positive and negative
            for(int i = 0; i < size*MULTIPLIER; i++){
                testValue = rand()%2 ? -(i + 1) : i+1;
                rand_string(&strtemp);

                if(stack.push(testValue, &strtemp)){
                    std::cout << "pushed.. id: " << testValue << " information: " << strtemp<< std::endl;
                }else if(testValue < 0 || strtemp.empty()){
                    std::cout << "error. push requires non-negative int and non empty string." << std::endl;                
                }else {
                    std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;

            //testing isEmpty followed by peek, then pop on full stack
            if (stack.isEmpty()){
                std::cout << "stack is empty" << std::endl;
            }else{
                std::cout << "stack is NOT empty" << std::endl;
            }

            if(stack.peek(data)){
                std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
            }else{
                std::cout << "peek underflow error: stack is empty" << std::endl;
            }

            if (stack.pop(data)){
                std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
            }else {
                std::cout << "pop  underflow error... stack is empty" << std::endl;
            }
            std::cout << std::endl;

            /*******************************************
             **** STACK EMPTYING AND EMPTY TESTS *******
             ******************************************/

            std::cout << "testing peek, pop and emptying the stack" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            for (int i = 0; i < MULTIPLIER*size; i++){
                if(stack.peek(data)){
                    std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
                }else{
                    std::cout << "peek underflow error: stack is empty" << std::endl;
                }

                if (stack.pop(data)){
                    std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
                }else {
                    std::cout << "pop  underflow error... stack is empty" << std::endl;
                }
                std::cout << std::endl;  
            }

            //testing isEmpty on empty stack followed by peek then pop
            if (stack.isEmpty()){
                std::cout << "stack is empty" << std::endl;
            }else{
                std::cout << "stack is NOT empty" << std::endl;
            }

            if(stack.peek(data)){
                std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
            }else{
                std::cout << "peek underflow error: stack is empty" << std::endl;
            }

            if (stack.pop(data)){
                std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
            }else{
                std::cout << "pop  underflow error... stack is empty" << std::endl;
            }
            std::cout << std::endl;

           /*******************************************
            ************ MID-STACK TESTS **************
            *******************************************/
            std::cout << "filling stack to halfway and testing the middle of the stack.." << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            for (int i = 0; i < int(size/2); i++){
                testValue = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
                rand_string(&strtemp);

                if(stack.push(testValue, &strtemp)){
                    std::cout << "pushed.. id: " << testValue << " information: " << strtemp<< std::endl;
                }else if(testValue < 0 || strtemp.empty()){
                    std::cout << "error. cannot push. push requires non-negative int and non empty string." << std::endl; 
                }else{
                    std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                }
                std::cout << std::endl;
            }   

            //testing middle in a narrow band
            for (int i = 0; i < size*NARROW; i++){
                testValue = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1); //randomizes testValue for push

                //testing isEmpty followed by peek then pop and push (pushes random testValue and random string)
                if (stack.isEmpty()){
                 std::cout << "stack is empty" << std::endl;
                }else{
                    std::cout << "stack is NOT empty" << std::endl;
                }

                if(stack.peek(data)){
                    std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
                }else{
                    std::cout << "peek underflow error: stack is empty" << std::endl;
                }

                if (stack.pop(data)){
                    std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
                }else{
                    std::cout << "pop  underflow error... stack is empty" << std::endl;
                }

                if(stack.push(testValue, &strtemp)){
                    std::cout << "pushed.. id: " << testValue << " information: " << strtemp<< std::endl;
                }else if(testValue < 0 || strtemp.empty()){
                    std::cout << "error. cannot push. push requires non-negative int and non empty string." << std::endl; 
                }else {
                    std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                }
                std::cout << std::endl;
            }

            /*******************************************
            ************ RANDOM TESTS ******************
            ********************************************/

            std::cout << "performing randomized testing" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            //emptying the stack for testing
            while (!stack.isEmpty()){   
                stack.pop(data);
            }

            //filling the stack to half way with random numbers and random strings
            for (int i = 0; i < int(size/2); i++){
                testValue = rand() % MAX_INT + 1;
                rand_string(&strtemp);

                if(stack.push(testValue, &strtemp)){
                    std::cout << "pushed.. id: " << testValue << " information: " << strtemp<< std::endl;
                }else if(testValue < 0 || strtemp.empty()){
                    std::cout << "error. cannot push. push requires non-negative int and non empty string." << std::endl; 
                }else {
                    std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                }
                std::cout << std::endl;
            }


            std::cout << "testing random execution of operations........" << std::endl;
            //tests all functions in randomized order with push and pop tested more frequently
            int choice = rand() % CHOICES + 1;
            for (int i = 0; i < size*RANDOM_MULTIPLIER; i++){

                switch(choice){
                    case 1:
                    case 2:
                        //push
                        testValue = (rand() % MAX_INT) + 1;

                        if(stack.push(testValue, &strtemp)){
                            std::cout << "pushed.. id: " << testValue << " information: " << strtemp << std::endl;
                        }else if(testValue < 0 || strtemp.empty()){
                            std::cout << "error. cannot push. push requires non-negative int and non empty string." << std::endl; 
                        }else{
                            std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                        }
                        std::cout << std::endl;
                        break;

                    case 3:

                    case 4:
                        //popping
                        if (stack.pop(data)){
                            std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
                        }else{
                            std::cout << "pop  underflow error... stack is empty" << std::endl;
                        }
                        std::cout << std::endl;
                        break;

                    case 5: 
                        //peek
                        if(stack.peek(data)){
                            std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
                        }else{
                            std::cout << "peek underflow error: stack is empty" << std::endl;
                        }
                        std::cout << std::endl;
                        break;

                    case 6:
                        //isEmpty
                        if (stack.isEmpty()){
                            std::cout << "stack is empty" << std::endl;
                        }else{
                            std::cout << "stack is NOT empty" << std::endl;
                        }
                        std::cout << std::endl;
                        break;
                }
                choice = rand() % CHOICES + 1;
                rand_string(&strtemp); 
                std::cout << std::endl; 
            }

            std::cout << std::endl;
            delete data;    //deallocates and deletes empty Data struct made for testing

        }else{
            std::cout << "Error.. can only accept an integer for stack size." << std::endl;
        }
    }else{
        std::cout << "Error.... Invalid amount of arguments. " << std::endl;
    }

    return 0;
}