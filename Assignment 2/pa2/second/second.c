//SECOND: Bit Count Functions:

/*


In this part, you have to determine the parity of a number and the amount of 1-bit pairs present in the number.

Parity refers to whether a number contains an even or odd number of 1-bits. 

1-bit pairs are defined by 2 adjacent 1’s without overlap with other pairs.

For example the number 3 has the binary sequence 111 and is considered to contain 1 pair 
while the sequence 101101111 has 3 pairs.

Input format: This program takes a single number as an argument from the command line. 

This number should be considered as an unsigned short.

Output format: Your program should print either “Even-Parity” if 
the input has an even amount of 1 bits and “Odd-Parity” otherwise, 
followed by a tab. 

Your program should then print the number of 1-bit pairs present in the number 
followed by a new line character.

Example Execution:

Some sample runs and results are:

$./second 12

Even-Parity   1


$./second 31

Odd-Parity    2

*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
    

    //if no arguments, exit.
    if (argv[1]==NULL){
        return 0;
    }

    //Store the number as the Dec variable
    unsigned short Dec =  atoi(argv[1]);

    //this short counts the number of pairs of 1s in the binary. 
    unsigned short pairs = 0;
    
    //This is my mask that looks like '11'. I will use this to make comparisons. 
    unsigned short mask = 3;
    
    //Test is what I will evaluate to determine if the window contains a '11' in the Dec
    unsigned short test;

    //shift count keeps track of how many times the window shifts.
    unsigned short shiftcount = 0;

    //parity counts the number of times the window sees either a 01 or a 10. If it does, it increases.
    unsigned short parity = 0;


    //keeps the mask from advancing left to infinity.
    //The loop will exit upon twice the Dec value (good for small numbers)
    //The loop will also exit should the shift count exceed the number, since the shifting should need MAX one half the number itself (since I am using a window and shift of 2).
    while (mask<=((Dec+1)*2)&&shiftcount<((Dec+1))){


        //if there are an odd number of bits then the number of bits need to be made even.
        //This is because the window size is 2, and the mask advances by 2
        //Therefore, the numeber of bits needs to be divisible by 2.
        //Shifting the number left will change the number and 0s but NOT the total number of 1s
        unsigned short oddBit = (short)(log(Dec)/log(2))+1;
        if (((oddBit%2)!=0)){
            Dec = Dec<<1;
        }
        //fringe case for if 1 is a test case
        if (Dec == 1){
             Dec = Dec<<1;
        }

        //fringe case for if 0 is a test case (probably dont need this)
        if (Dec == 0){
             Dec = Dec<<1;
        }


        //printf("Shift count is = %d\n", shiftcount);

        //BIT OPERATION to set the test variable to the AND of the mask and Dec at the current mask position.
        test = mask&Dec;
        //printf("test = %d\n", test);


        //BIT OPERATION to shift the window to the left by 2.
        mask = mask << 2;
        //printf("mask = %d\n", mask);






        //if the test decimal is divisible by 3, then that means it must contain a bitpair.
        //It will give a false positive if the test = 0.
        //This looks for a test leading '11'
        if (test%3==0 && test!=0){
            pairs++;
            //printf("bitpair found\n");
        }

        //If the test is anything OTHER than 0 or something divisible by 3, then it must contain the leading bitstring of 01 or 10, increasing the parity number.
        //this looks for a test leading '01' or '10'
        if (test!=0 && !(test%3==0)){
            parity++;
            //printf("parity count = %d\n", parity);
        }

        //this keeps track of how many times the window has been shifted.
        shiftcount++;
    }

    //since the parity counts the number of unpaired 1s, then if it is odd then the parity is odd
    //else, the parity is even. 
    if (parity%2==0){
        printf("Even-Parity\t");
    } else if (parity%2!=0){
        printf("Odd-Parity\t");
    }

    //Prints the number of pairs found. 
    printf("%d\n", pairs);
    return 0;
}
