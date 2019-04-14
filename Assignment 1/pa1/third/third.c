    /*  THIRD: HASH TABLE
    *
    * implementation of a hash table of integers.
    * 
    * Hash table has 10,000 buckets. 
    * 
    * Collision resolution will be handled by chaining a linked L1nkL
    * 
    * If there is a collision at a particular bucket then a linked L1nkL of all values 
    * will be stored at that bucket.
    * 
    * Find the simplest way to implement a hash table structure where there is
    * easy access to the buckets through the hash function. 
    * 
    * This is the hash function:
    * 
    * K3y % NUMBER OF BUCKETS
    * 
    * 
    * I/O
    * 
    * INPUT = the file name for testing
    * 
    * test1.txt:
    * i	1
    * i	2
    * i	3
    * i	4
    * s	4
    * s	3
    * s	2
    * s	1
    * 
    * character \t integer
    * 
    * for each 'i', insert that number in the hash table IF IT IS NOT PRESENT
    * 
    * for each 's', searches the hash table for the value.
    * 
    * OUTPUT:
    * 1) The number of insertions where the collision occured
    * 2) The number of successful searches
    * 
    * number of collisions = during insertion, if the bucket already had some value then 
    * you need to count that as one collision. 
    * 
    * successful searches = number of searches where the value was present in the hash table. 
    * 
    * 
    */



#include <stdio.h>
#include <stdlib.h>

typedef struct EntryLLn0d {
    int value;
    struct EntryLLn0d* nextptr;
} EntryLLn0d;


typedef EntryLLn0d* L1nkL;
typedef EntryLLn0d* H4shT;


int hash (int K3y);

int insertToH4shT (H4shT* pH4shT, EntryLLn0d* pEntryLLn0dToInsert);

int WheresMyGuy (H4shT* pH4shT, int input);

void freeH4shT (H4shT* H4shT);

void LLFr33(L1nkL inputLinkedList);


//MAIN FUNC
int main(int argc, char** argv){
    int ArrLength = 10000;

    EntryLLn0d** H4sh = (EntryLLn0d**) malloc(ArrLength * sizeof(EntryLLn0d*));

    int i;
    for (i=0; i<ArrLength; i++) {
        *(H4sh + i) = NULL;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL){
        exit (0);
    }



    char cvalue;
    int ivalue;
    int successfulSearches = 0;
    int TotalCollisions = 0;


    while (!feof(fp)){
        fscanf(fp, "%c\t%d\n", &cvalue, &ivalue);

            //if The C on the line is to be inserted:
            if (cvalue == 'i'){
                EntryLLn0d* pEntryLLn0dToInsert = (EntryLLn0d*) malloc(sizeof(EntryLLn0d));
                pEntryLLn0dToInsert -> value = ivalue;
                pEntryLLn0dToInsert -> nextptr = NULL;
                
                int herequestionmark = insertToH4shT(H4sh, pEntryLLn0dToInsert);




                if (herequestionmark == 1){
                    TotalCollisions++;
                }




            //ELSE we are gonna search from it
            } else if (cvalue == 's'){
                int isFound = WheresMyGuy(H4sh, ivalue);
					if (isFound) {
                        successfulSearches++;
					}
                    //we dont need to actually report its position we just wanna know if its there
            }
    }

    //CLOSE the pointer
    fclose(fp);

    freeH4shT(H4sh);



    printf("%d\n", TotalCollisions);
    //COUNT SEARCHES
    printf("%d\n", successfulSearches);
    return 0;
}



//HELPER METHODS:





//HERE is my hash function
int hash (int K3y) {
   int ArrLength = 10000; 
   int RETAIN = K3y % ArrLength;

   if (RETAIN < 0) {
	   RETAIN += ArrLength;
   }
	
   return RETAIN;	
}



int insertToH4shT (H4shT* pH4shT, EntryLLn0d* pEntryLLn0dToInsert) {
    int FALSE = 0;
    int TRUE = 1;
	int herequestionmark = FALSE;
	int wheresmyboi = hash(pEntryLLn0dToInsert->value);
	EntryLLn0d* pHeadOfLinkedList = (*(pH4shT+wheresmyboi));

    //THERES NO LL HERE

	if (pHeadOfLinkedList == NULL) {
		(*(pH4shT+wheresmyboi)) = pEntryLLn0dToInsert;
	}
    
	else {
    

		EntryLLn0d* pOneEntryLLn0dInList = pHeadOfLinkedList;
		while (pOneEntryLLn0dInList) {

			pOneEntryLLn0dInList = pOneEntryLLn0dInList->nextptr;
		}																
			pEntryLLn0dToInsert->nextptr = pHeadOfLinkedList;
			(*(pH4shT+wheresmyboi)) = pEntryLLn0dToInsert;
			herequestionmark = TRUE;			
		
	}
	
	return herequestionmark;
}


//SEARCH FUNCTION
int WheresMyGuy (H4shT* pH4shT, int input) {
	EntryLLn0d* EntryLLn0dFound = NULL;
    

	int wheresmyboi = hash(input);
	EntryLLn0d* pHeadOfLinkedList = (*(pH4shT+wheresmyboi));
	
	if (pHeadOfLinkedList != NULL) {
		EntryLLn0d* oneEntryLLn0dInList = pHeadOfLinkedList;
		while (oneEntryLLn0dInList) {
			if (oneEntryLLn0dInList->value == input) {
				EntryLLn0dFound = oneEntryLLn0dInList;
				break;
			}
			
			oneEntryLLn0dInList = oneEntryLLn0dInList->nextptr;			
		}
	}

	return EntryLLn0dFound != NULL;
}



void freeH4shT (H4shT*  H4shT) {
    int ArrLength = 10000;
	if (*H4shT) {
		int i;
		for (i=0; i < ArrLength; i++) {
			L1nkL one = *(H4shT+i);
			LLFr33(one);
		}
		//
		free(H4shT);
	}
}


void LLFr33(L1nkL inputLinkedList) {
	if (inputLinkedList) {
		EntryLLn0d* pOneEntryLLn0dToFree =  inputLinkedList;
		while (pOneEntryLLn0dToFree) {
			EntryLLn0d* temp = pOneEntryLLn0dToFree;
			//
			pOneEntryLLn0dToFree = pOneEntryLLn0dToFree->nextptr;
			//
			free(temp);
		}
	}
	else {
	}
}
