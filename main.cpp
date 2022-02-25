/*********************************************
 * Name: Graziella Buitron
 * Coding 04
 * Purpose: To create a stack object that will 
 * work with a struct data type called Data.
 *********************************************/

#include "main.h"

int main(int argc, char **argv){
    // here for the rand_string() function
    // if you don't use it, get rid of this
    srand(time(NULL));

    
    //first if statement tests if user entered only 2 arguments in command line
    if (argc == 2){

        int size = atoi(argv[1]);


        //tests if size is valid - an integer and it is greater than or equal to 2
        //if size is valid, create the stack and begin testing
        if (size >= 2){

            //creating the stack 
            Stack stack(size);


            //allocating an empty Data struct to pass into peek() and pop() for testing purposes
            Data *data;
            data = new Data;

            //declaring variables we need for testing
            int testValue;
            std::string strtemp;


            std::cout << "Stack of maximum size " << size << " created" << std::endl << std::endl;
            std::cout << "BEGINNING TESTS.... " << std::endl;
            std::cout << "TESTING EMPTY OPERATIONS" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            //EMPTY TESTS

            //testing isEmpty on empty stack
            if (stack.isEmpty()){
                std::cout << "stack is empty" << std::endl;
            }
            else{
                std::cout << "stack is NOT empty" << std::endl;
            }

            std::cout << std::endl;
          
            //testing peek and then pop on empty stack
            //testing peek function
            if(stack.peek(data)){
                std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
            } 
            else{
                std::cout << "peek underflow error: stack is empty" << std::endl;
            }

            if (stack.pop(data)){
                std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
            }
            else {
                std::cout << "pop  underflow error... stack is empty" << std::endl;
            }
            std::cout << std::endl;

            /*******************************************
             ******** FILLING AND FULL TESTS ***********
             ******************************************/
            std::cout << "Testing full operations..." << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "Filling the stack.. " << std::endl;

         
            for(int i = 0; i < size*MULTIPLIER; i++){
                testValue = rand()%2 ? -(i + 1) : i+1;
                rand_string(&strtemp);

                if(stack.push(testValue, &strtemp)){
                    std::cout << "pushed.. id: " << testValue << " information: " << strtemp<< std::endl;
                }
                else if(testValue < 0 || strtemp.empty()){

                    std::cout << testValue << " " << strtemp << std::endl;
                    std::cout << "error. push requires non-negative int and non empty string." << std::endl;                }
                else {
                    std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                }
                    std::cout << std::endl;
            }
            std::cout << std::endl;

            //testing isEmpty on full stack
            if (stack.isEmpty()){
                std::cout << "stack is empty" << std::endl;
            }
            else{
                std::cout << "stack is NOT empty" << std::endl;
            }

            //testing peek() then pop() on full stack
            if(stack.peek(data)){
                std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
            } 
            else{
                std::cout << "peek underflow error: stack is empty" << std::endl;
            }

            if (stack.pop(data)){
                std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
            }
            else {
                std::cout << "pop  underflow error... stack is empty" << std::endl;
            }

            std::cout << std::endl;

            /*******************************************
             ******* EMPTYING AND EMPTY TESTS **********
             ******************************************/

            std::cout << "testing peek, pop and emptying the stack" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            for (int i = 0; i < MULTIPLIER*size; i++){
                if(stack.peek(data)){
                    std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
                } 
                else{
                    std::cout << "peek underflow error: stack is empty" << std::endl;
                }

                if (stack.pop(data)){
                    std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
                }
                else {
                    std::cout << "pop  underflow error... stack is empty" << std::endl;
                }
              std::cout << std::endl;  
            }

            //testing isEmpty on empty stack
            if (stack.isEmpty()){
                std::cout << "stack is empty" << std::endl;
            }
            else{
                std::cout << "stack is NOT empty" << std::endl;
            }

            //testing peek and then pop on empty stack
            if(stack.peek(data)){
                std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
            } 
            else{
                std::cout << "peek underflow error: stack is empty" << std::endl;
            }

            if (stack.pop(data)){
                std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
            }
            else {
                std::cout << "pop  underflow error... stack is empty" << std::endl;
            }
            std::cout << std::endl;


           /*******************************************
            ************ MID-STACK TESTS **************
            *******************************************/
            std::cout << "filling stack to halfway and testing in middle of stack.." << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            for (int i = 0; i < int(size/2); i++){
                testValue = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
                rand_string(&strtemp);

                if(stack.push(testValue, &strtemp)){
                    std::cout << "pushed.. id: " << testValue << " information: " << strtemp<< std::endl;
                }
                else if(testValue < 0 || strtemp.empty()){
                    std::cout << "error. cannot push. push requires non-negative int and non empty string." << std::endl; 
             }
                else {
                    std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                }
                std::cout << std::endl;
            }   

            //testing middle in a narrow band
            for (int i = 0; i < size*NARROW; i++){

                //testing isEmpty on empty stack
                if (stack.isEmpty()){
                 std::cout << "stack is empty" << std::endl;
                }
                else{
                    std::cout << "stack is NOT empty" << std::endl;
                }
                std::cout << std::endl;

                //testing peek and then pop
                if(stack.peek(data)){
                    std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
                } 
                else{
                    std::cout << "peek underflow error: stack is empty" << std::endl;
                }

                if (stack.pop(data)){
                    std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
                 }
                else {
                    std::cout << "pop  underflow error... stack is empty" << std::endl;
                }

                std::cout << std::endl;
                testValue = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);

                if(stack.push(testValue, &strtemp)){
                    std::cout << "pushed.. id: " << testValue << " information: " << strtemp<< std::endl;
                }
                else if(testValue < 0 || strtemp.empty()){
                    std::cout << "error. cannot push. push requires non-negative int and non empty string." << std::endl; 
                }
                else {
                    std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                }
                std::cout << std::endl;
            }

            /*******************************************
            ************ RANDOM TESTS ******************
            ********************************************/

            std::cout << "performing random testing" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

            //emptying the stack to begin random tests
            while (!stack.isEmpty()){   
                stack.pop(data);
            }

            //filling the stack half way with random numbers to begin random tests
            for (int i = 0; i < int(size/2); i++){
                testValue = rand() % MAX_INT + 1;
                rand_string(&strtemp);

                if(stack.push(testValue, &strtemp)){
                    std::cout << "pushed.. id: " << testValue << " information: " << strtemp<< std::endl;
                }
                else if(testValue < 0 || strtemp.empty()){
                    std::cout << "error. cannot push. push requires non-negative int and non empty string." << std::endl; 
                }
                else {
                    std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                }
                std::cout << std::endl;
            }


            std::cout << "Testing random operations..." << std::endl;
            //this will test random operations. push and pop tested twice as often peek and isempty
            int choice = rand() % CHOICES + 1;
            for (int i = 0; i < size*RANDOM_MULTIPLIER; i++){

                switch(choice){
                    case 1:
                    case 2:
                        //pushing
                        testValue = (rand() % MAX_INT) + 1;

                        if(stack.push(testValue, &strtemp)){
                            std::cout << "pushed.. id: " << testValue << " information: " << strtemp<< std::endl;
                        }
                        else if(testValue < 0 || strtemp.empty()){
                            std::cout << "error. cannot push. push requires non-negative int and non empty string." << std::endl; 
                        }
                        else {
                            std::cout << "overflow error.. could not push id: " << testValue << " information: " << strtemp << std::endl;
                        }
                        std::cout << std::endl;
                        break;

                    case 3:

                    case 4:
                        //popping
                        if (stack.pop(data)){
                            std::cout << "pop successful. popped... id: " << data->id << " information: " << data->information << std::endl;
                        }
                        else {
                            std::cout << "pop  underflow error... stack is empty" << std::endl;
                        }
                        std::cout << std::endl;
                        break;

                    case 5: 
                        //peek
                        if(stack.peek(data)){
                            std::cout << "peeking... id: " << data->id << " information: " << data->information << std::endl;
                        } 
                        else{
                            std::cout << "peek underflow error: stack is empty" << std::endl;
                        }
                        std::cout << std::endl;
                        break;

                    case 6:
                        //isEmpty testing
                        if (stack.isEmpty()){
                            std::cout << "stack is empty" << std::endl;
                        }
                        else{
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

            delete data;
        }
        else {
            std::cout << "Error.. can only accept an integer for stack size." << std::endl;
        }

    } else {
        std::cout << "Error.... Invalid amount of arguments. " << std::endl;
    }


    return 0;

    /* ***************************************************************
     * Use the number passed in from the command line and declare a stack
     * that uses that number as the size of the stack. NOTE: Make sure
     * your stack ALSO checks the number passed in to it. You cannot rely
     * on main checking the number first. This will be tested during grading.
     * ***************************************************************/

    
    /* ***************************************************************
     * Throughly test your stack. You must perform an exhaustive series
     * of tests on your stack. Show all possible ways your stack can be used
     * and abused and prove that your stack can gracefully handle ALL cases.
     * You must use automated testing (no user input). First cover all
     * explicit cases which you can think of, then execute random operations.
     * When generating test data, use random ints for ids and random short
     * strings for string. There is a string generator made for you in the
     * functions module. You are free to use it or make your own.
     * ***************************************************************/

    /* ***************************************************************
     * Below is some sample code for the random string function. It's
     * only here to demonstrate the function. DELETE it once you study
     * it and understand it and can use it yourself in your code.
     * ***************************************************************/
    
    // make 20 random strings, store them, display them
    /* std::string strtemp;
    for(int i=0; i<20; i++){
        rand_string(&strtemp);
        std::cout << strtemp << std::endl;
    } 
    */
    
    
    /* ***************************************************************
     * Your code will be tested by applying your stack to a custom main
     * designed to break your code. If it can be broken, you risk a
     * substantially reduced grade, up to and including a zero.
     * ***************************************************************/
    
    // WHEN YOU SUBMIT, DELETE ALL INSTRUCTIONAL COMMENTS



}
