/*********************************************
 * Name: Graziella Buitron
 * Coding 04
 * Purpose: To create a stack object that will 
 * work with a struct data type called Data.
 *********************************************/

#ifndef STACKS_MAIN_H
#define STACKS_MAIN_H

// you probably need all these,
// but if you don't get rid of what you don't need
#include <stdlib.h>   /* srand, rand */
#include <time.h>     /* time */
#include <iostream>   /* cout, endl */
#include <string>     /* string */
#include "functions.h"

/*
 * additional directives here
 * 
 */

#define MULTIPLIER 2.5 // used to test overflow and underflow
#define NARROW .30 // percent of the stack for a narrow band
#define RANDOM_MULTIPLIER 10
#define CHOICES 6 // used to pick random operations
#define MAX_INT 100000 

#include "stack.h"

#endif /* STACKS_MAIN_H */
