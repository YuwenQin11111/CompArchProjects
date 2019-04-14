#include <stdio.h>
#include <stdlib.h>

void multiply(int unoColumn, int dosColumn, int mat1[][dosColumn], int UnoRow, int dosRow, int mat2[][dosRow]) 
{ 
    int counter1, counter2, counter3; 
    int FINALYAY[unoColumn][dosRow]; 


    //column1 counter
    for (counter2 = 0; counter2 < unoColumn; counter2++) 
    { 
        //row 2 counter
        for (counter3 = 0; counter3 < dosRow; counter3++) 
        { 
            //column1 AND row 2 because that's how matrix multiplication works

            FINALYAY[counter2][counter3] = 0; 

            for (counter1 = 0; counter1 < dosColumn; counter1++) 
            { 

                *(*(FINALYAY + counter2) + counter3) += *(*(mat1 + counter2) + counter1) **(*(mat2 + counter1) + counter3); 
            } 
        } 
    } 

    for (counter2 = 0; counter2 < unoColumn; counter2++) 
    { 
        for (counter3 = 0; counter3 < dosRow; counter3++) 
        { 
            printf("%d\t", *(*(FINALYAY + counter2) + counter3)); 
        } 
        printf("\n"); 
    } 
} 



int main (int argc, char** argv){
    //printf("\nNow reading %s:\n\n", argv[1]);


    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL){
        exit(0);
    }

    //CREATE MATRIX 1
    //int rowCounter=0;
    //int columnCounter=0;
    int scanCounter=0;
    int rows;
    int columns;
    //int toInsert;
    while(scanCounter<1){
            fscanf(fp, "%d\t%d", &rows, &columns);
            //printf("%d rows and %d columns for matrix 1\n", rows, columns);
            scanCounter++;
        }

    int MatrixOne[rows][columns];

    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0;j<columns;j++) {
            //printf("Enter value for MatrixOne[%d][%d]:\n", i, j);
            fscanf(fp, "%d\t", &MatrixOne[i][j]);
            //printf("%d\n", MatrixOne[i][j]);

      }
    }


    /*
    //printf("Matrix 1 successfully read as \n"); 
    for (i = 0; i < rows; i++) 
    { 
        //printf("[");
        for (j = 0; j < columns; j++) 
           //printf(" %d ", MatrixOne[i][j]); 
        //printf("]\n"); 
    } 
    */


    //CREATE MATRIX 2
    //int rowCounter=0;
    //int columnCounter=0;
    int scanCounter1=0;
    int rows1=0;
    int columns1=0;
    //int toInsert;
    while(scanCounter1<1){
            fscanf(fp, "%d\t%d", &rows1, &columns1);
            //printf("%d rows and %d columns for matrix 2\n", rows1, columns1);
            scanCounter1++;
        }

    int MatrixTwo[rows1][columns1];
    
    int i1, j1;
    for(i1=0; i1<rows1; i1++) {
        for(j1=0;j1<columns1;j1++) {
            //printf("Enter value for MatrixTwo[%d][%d]:\n", i1, j1);
            fscanf(fp, "%d\t", &MatrixTwo[i1][j1]);
            //printf("%d\n", MatrixTwo[i1][j1]);
      }
    }
    
    /*
    //printf("Matrix 2 successfully read as \n"); 
    for (i = 0; i < rows1; i++) 
    { 
        //printf("[");
        for (j = 0; j < columns1; j++) 
           //printf(" %d ", MatrixTwo[i][j]); 
        //printf("]\n"); 
    }
    */
    
    if (columns == rows1){
    multiply(rows, columns, MatrixOne, rows1, columns1, MatrixTwo); 
    } else {
        printf("bad-matrices");
    }



   return 0;
}
