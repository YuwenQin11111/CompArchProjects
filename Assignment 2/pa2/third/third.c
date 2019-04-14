/*

In this part, you have to determine whether a number’s bit representation is a palindrome. A palindrome is defined as a sequence that is the same both forwards and backwards.
We will be working with unsigned shorts which are 2 bytes or 16 bits. For example the num- ber 384 has the binary sequence 0000000110000000 and is thus a palindrome while the sequence 0100100010111011 is not.
You can and should use the same get(x, n) function that you created in part 1.
Input format: This program takes a single number as an argument from the command line.
This number should be considered as an unsigned short.
Output format: Your program should print either “Is-Palindrome” if the input is a palindrome and “Not-Palindrome” otherwise, followed by a new line character.
Example Execution:
Some sample runs and results are:

$./third 384
Is-Palindrome
$./third 1001
Not-Palindrome

*/

#include <stdio.h>
#include <stdlib.h>

unsigned short backwards(unsigned short num) 
{ 
    unsigned short  alloc = sizeof(num) * 8; 
    unsigned short backw = 0, k, tptr; 
  
    for (k = 0; k < alloc; k++) 
    {

        tptr = (num & (1 << k));

        if(tptr){

            backw = backw | (1 << ((alloc - 1) - k));

        }

    } 
   
    return backw; 
} 




int main(int argc, char** argv){
    

    //if no arguments, exit.
    if (argv[1]==NULL){
        return 0;
    }

    //Store the number as the Dec variable
    unsigned short Dec =  atoi(argv[1]);

    //printf("Scanned = %d\n", Dec);

    unsigned short rev = backwards(Dec); 
    

    if (Dec == rev){
        printf("Is-Palindrome");
    } else if (Dec != rev){
        printf("Not-Palindrome");
    }


return 0;
}
