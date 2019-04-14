/*

First: Bit functions (35 Points)

You have to write a program that will read a number followed by a series of bit operations from a
file and perform the given operations sequentially on the number. The operations are as follows:


set(x, n, v) sets the nth bit of the number x to v


comp(x, n) sets the value of the nth bit of x to its complement (1 if 0 and 0 otherwise)


get(x, n) returns the value of the nth bit of the number x


The least significant bit (LSB) is considered to be index 0.

Input format: Your program will take the file name as input. The first line in the file provides 
the value of the number to be manipulated. For the function calls this number can be considered
x. 

This number should be considered an unsigned short. 
The following lines will contain the operations to manipulate the number. 
The format of the operations will always be the command followed by 2 numbers with tabs in between each part. 
For the set(x, n, v) command, the value of the second number will always be either 0 or 1. For the comp(x, n) and get(x, n) command the
value of the second number will always be 0 and can be ignored.
Output format: Your output will be the resulting value of the number x after each operation,
each on a new line. The get(x, n) function should only print the value of the nth bit as the value
of x does not change.
Example Execution:
For example, a sample input file “file1.txt” contains:
5
get 0 0
comp 0 0
set 1 1
The result of the sample run is:
$./first file1.txt
1
4
6

*/

#include <stdio.h>



int main(int argc, char** argv){

    unsigned short Dec;

    FILE *fp = fopen(argv[1], "r");

    if (fp==NULL){
        return (0);
    }

    fscanf(fp, "%hd", &Dec);

    //print("the system scanned %d\n", Dec);


    char ch;
    while (!feof (fp)){
    fscanf(fp, "%c", &ch);

        //if its comp

        if (ch == 'c'){

            unsigned short mask = 1; 
            int CompPos;
            int z;
            fscanf(fp, "omp\t%d\t%d", &CompPos, &z);
            //print("COMP at %d \n", CompPos);



            //BIT OPERATION:
            Dec = Dec^(mask<<CompPos);


            printf("%d\n",Dec);


        //if its set
        }
        if (ch == 's'){
            int SetPos;
            unsigned short SetTo;


            fscanf(fp, "et\t%d\t%hd", &SetPos, &SetTo);
            
            //BIT OPERATION

            //Clear bit
            Dec = Dec & ~(1<<SetPos);

            //if the bit is one, then set the new bit, otherwise remain zero.
            Dec = Dec | (SetTo<<SetPos);
           
            printf("%d\n", Dec);
        }

        //if its get
        if (ch == 'g'){

            int GetPos;
            int zed;
            fscanf(fp, "et\t%d\t%d", &GetPos, &zed);

            //BIT OPERATION

            unsigned short getter;
            getter = (Dec>>GetPos)&1;


            printf("%hd\n", getter);
        }
}
return 0;
}
