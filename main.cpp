/*********************************************
 * Name: Graziella Buitron
 * Coding 04
 * Purpose: To create a stack object that will 
 * work with a struct data type called Data.
 *********************************************/

#include "main.h"

int main(int argc, char **argv) {
    // here for the rand_string() function
    // if you don't use it, get rid of this
    srand(time(NULL));

    /* ***************************************************************
     * First get your arguments from the command line. Your program must
     * accept one and only one argument not including the program name
     * itself. That argument must be an integer between 2 and any
     * number (i.e. >= 2). If anything else is entered in any way,
     * terminate the program with a suitable error message telling the
     * user how to use your program correctly.
     * 
     * Remember, you may not use more than one return, even in main()
     * and you may not use exit() or anything like that.
     * ***************************************************************/

/*  MESSING AROUND WITH TESTING TO VALIDATE INPUT FROM COMMAND LINE
    int size;
    if (!argc == 2){
        size = atoi(argv[1]);
    }
    try {
        Stack myStack(size);
    }
    catch (...){
        std::cout << "CAUGHT ERROR. Invalid input. Must enter  integer greater than or equal to 2." << std::endl;
    }
*/

    //CURRENTLY TRYING
    int size = atoi(argv[1]);

    if (argc  != 2){

        std::cout << "Please pass an integer for your stack size." << std::endl;
    }

    try {
         Stack myStack(size);
    }
      catch (...){

        std::cout << "CAUGHT ERROR. Invalid input. Must enter 1 integer greater than or equal to 2." << std::endl;
    }


    /*
    size = atoi(argv[1]);

    if (size >= 2){
        std::cout << "Max size of the stack is: " << size << std::endl;
    } else {
        size = 0;
        std::cout << "Please pass only one integer for your stack size." << std::endl;
    }

    try {
        Stack myStack(size);
    }
    catch (...){
        std::cout << "CAUGHT ERROR. Invalid input. Must enter 1 integer greater than or equal to 2." << std::endl;
    }
*/

/*
    //variable size receives string input from command line turns to int
    int size = atoi(argv[1]);

    //if received argument is not valid, print error message
    if (argc == 2 && size >= 2){
        std::cout << "Maximum stack size is " << size << std::endl << std::endl;
    } 
    else {
      std::cout << "Invalid input.  Please enter an integer greater than or equal to 2 to make a stack." << std::endl;
    }
    
    try {
        Stack myStack(size);
    }
    catch (...){
        std::cout << "CAUGHT ERROR. Invalid input. Must enter  integer greater than or equal to 2." << std::endl;
    }
    */


    //creating the stack
    Stack stack(size);

    //testing push with random strings and int from 0 to size*1.5
    std::string strtemp;

    for(int i=0; i< size*1.5; i++){

        rand_string(&strtemp);
        std::cout << "Random String: " << strtemp << std::endl;
        std::cout << "Pushing... ";

        if (strtemp.empty() || i <= 0){
            std::cout << "Error. Int for id must be greater than 0 and string information cannot be empty." << std::endl;
        }
        else if(stack.push(i, &strtemp)){
            std::cout << "Push successful. " << std::endl;
        }
        else {
            std::cout << "Overflow error." << std::endl;
        }
        std::cout << std::endl;
    }

    stack.dumpStack();
    std::cout << std::endl;  

        //making pointer to an empty data struct to pass to pop
        Data *data;
        data = new Data;

        std::cout << "Tesing pop function.." << std::endl;

        if (stack.pop(data)){
            std::cout << "Pop successful!" << std::endl;
        }
        else {
            std::cout << "Underflow error :(" << std::endl;
        }
        std::cout << std::endl;

    stack.dumpStack();

        //stack.pop(data);
        //std::cout << "Data's id: " << data->id << " Data's info: " << data->information << std::endl;

       
       // std::cout << stack.peek(data)->id << stack.peek(data)->information << std::endl;
        //stack.pop(data);

        std::cout << "Testing pop again. Popping.... " << std::endl;
        std::cout << std::endl;
        stack.pop(data);
        stack.dumpStack();

        //Data *dataPtr;
        //dataPtr = new Data;

        std::cout << std::endl;
        std::cout << "Peeking...." << std::endl;

        if(stack.peek(data)){
            std::cout << data->id << " " << data->information << std::endl;
        } 
        else{
            std::cout << "Peek unsuccessful" << std::endl;
        }
        
        std::cout << std::endl;
        stack.dumpStack();



        



    
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

    
    
    return 0;



}
