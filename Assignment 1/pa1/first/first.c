
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {

     int i;
     FILE *rfptr = fopen(argv[1], "r");

    if (rfptr==NULL){
      exit(0);
    }


    fscanf(rfptr, "%d", &i);


    //gets the array size and moves file pointer
    int ArraySize = i;
    int TheArray[ArraySize];


    //populates the array   
    int j = 0;
    while (!feof (rfptr)){
        fscanf(rfptr, "%d", &i);
        TheArray[j] = i;
        j++;
    }


  //initializes two arrays, one for the evens and one for the odds, then populates those arrays with zeroes.
   int even[ArraySize], odd[ArraySize];
   for (int loop1 = 0; loop1<ArraySize; loop1++){
     even[loop1]=0;
     odd[loop1]=0;
   }


  //Populates the odd and even arrays with their respective numbers from the origninal array TheArray
   int loop, ee, dd;
   int EvenCount = 0;
   int OddCount = 0;
   ee = dd = 0;
   
   for(loop = 0; loop < ArraySize; loop++) {
      if(TheArray[loop]%2 == 0) {
         EvenCount++;

         even[ee] = TheArray[loop];
         ee++;

      } else {
         OddCount++;

         odd[dd] = TheArray[loop];
         dd++;
      }
   }



  //create a consolidated even/odd array (shrinks the even and odd arrays down to the correct size)

  int ConsolEven[EvenCount];
  int ConsolOdd[OddCount];
  for (int ptr = 0; ptr < EvenCount; ptr++){
    ConsolEven[ptr] = even[ptr];
  }
  for (int ptr = 0; ptr < OddCount; ptr++){
    ConsolOdd[ptr] = odd[ptr];
  }





  //Now we can sort the seperate arrays for only even numbers and only odd numbers

        //Bubble Sort the ConsolEvens
          int ii = 0, jj = 0, tmp;
          for (ii = 0; ii < EvenCount; ii++) {   // loop n times - 1 per element
          for (jj = 0; jj < EvenCount - ii - 1; jj++) { // last i elements are sorted already            
            if (ConsolEven[jj] > ConsolEven[jj + 1]) {  // swop if order is broken
               tmp = ConsolEven[jj];
               ConsolEven[jj] = ConsolEven[jj + 1];
               ConsolEven[jj + 1] = tmp;
           }
       }
   }

       //Bubble Sort the ConsolOdds
          for (ii = 0; ii < OddCount; ii++) {   // loop n times - 1 per element
          for (jj = 0; jj < OddCount - ii - 1; jj++) { // last i elements are sorted already            
            if (ConsolOdd[jj] < ConsolOdd[jj + 1]) {  // swop if order is broken
               tmp = ConsolOdd[jj];
               ConsolOdd[jj] = ConsolOdd[jj + 1];
               ConsolOdd[jj + 1] = tmp;
           }
       }
   }




  //Now the the odds and evens have been seperated and sorted seperately, they can be recombined:

  int TheArrayFINAL[ArraySize];
  for (int ptr = 0; ptr < ArraySize; ptr++){
    if (ptr < EvenCount){
      TheArrayFINAL[ptr] = ConsolEven[ptr];
    } else {
      TheArrayFINAL[ptr] = ConsolOdd[ptr-EvenCount];
    }


  }

  //TheArrayFINAL is the FINAL ARRAY
  //FINAL PRINT STATEMENT:
  
      j=0;
      for (j = 0; j < ArraySize; j++ ) {
        if (j < ArraySize-1) {
           printf("%d\t", TheArrayFINAL[j]);
        }
        if (j==ArraySize-1){
          printf("%d\n", TheArrayFINAL[j]);
        }
      }




  fclose(rfptr);


  return 0;



}

