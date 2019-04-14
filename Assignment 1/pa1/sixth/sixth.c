//SIXTH.C


/*
*    Sixth: Binary Search Tree (20 points)
*    In the sixth part, you have to implement a binary search tree. The tree must satisfy the binary search tree property: the key in each node must be greater than all keys stored in the left sub-tree, and smaller than all keys in right sub-tree. You have to dynamically allocate space for each node and free the space for the nodes at the end of the program.
*    Input format:
*    This program takes a file name as an argument from the command line. The file is either blank or contains successive lines of input. Each line starts with a character, either ’i’, followed by a tab and then an integer. Your program should insert that number in the binary search tree if it is not already there. If it is already present, you will not change the tree.
*    Output format:
*    Your program will print all the elements in the tree in ascending order. To print elements in ascending order, you will need to traverse the tree in-order. In an in-order traversal you will visit the left child, then the parent and the right child. You can find more information about in-order traversal at:
*    https://en.wikipedia.org/wiki/Tree_traversal#In-order_(LNR)
*    The elements have to be printed in a single line separated by tabs. Your program should print “error” (and nothing else) if the input file does not exist.
*
*
*    Example Execution:
*    Lets assume we have a file file1.txt with the following contents:
*    i  5
     i  3 
     i  4
     i  3 
     i  6

*    Executing the program in the following fashion should produce the output shown below:
*    $./sixth file1.txt 
*    3  4   5   6


*/


#include <stdio.h>
#include <stdlib.h>


//make a node for insertion into the tree, with a value value and a struct called TheNode with both Left (L) and Right (R) Pointers


struct TheNode 
{ 
    int Value; 
    struct TheNode *L, *R; 
}; 
   


struct TheNode *CreateN(int item) 
{ 
    struct TheNode *pointr =  (struct TheNode *)malloc(sizeof(struct TheNode)); 
    pointr->Value = item; 
    pointr->L = pointr->R = NULL; 
    return pointr; 
} 
   


   
struct TheNode* push(struct TheNode* TheNode, int Value) 
{ 
    if (TheNode == NULL) return CreateN(Value); 
    if (Value < TheNode->Value) 
        TheNode->L  = push(TheNode->L, Value); 
    else if (Value > TheNode->Value) 
        TheNode->R = push(TheNode->R, Value);    
      return TheNode; 
} 




void Traverse(struct TheNode *begin) 
{ 
    if (begin != NULL) 
    { 
        Traverse(begin->L); 
        printf("%d\t", begin->Value); 
        Traverse(begin->R); 
    } 
} 

   
int main (int argc, char** argv){
    //printf("%s\n", argv[1]);

    FILE *fp = fopen (argv[1], "r");
    if (fp == NULL){

        printf("error");
        return 0;
    
    }

    char cvalue;
    int ivalue;
    struct TheNode *begin = NULL; 
    fscanf(fp, "%c\t%d\n", &cvalue, &ivalue);
        //printf ("%c, %d \n", cvalue, ivalue);
        if (cvalue == 'i'){
            int RootValue = ivalue;
            begin = push(begin, RootValue); 


        }

    
    while (!feof (fp)){
        fscanf(fp, "%c\t%d\n", &cvalue, &ivalue);
        //printf ("%c, %d \n", cvalue, ivalue);
        if (cvalue == 'i'){
            int toInsert = ivalue;
            push(begin, toInsert);

        }
    }

    Traverse(begin);
    
    
    return 0;
}
