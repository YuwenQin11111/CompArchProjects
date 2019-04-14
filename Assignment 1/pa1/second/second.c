#include <stdio.h>
#include <stdlib.h>

/* Function to bubble sort the given linked list */

    //Defining the nodes:

    typedef struct node Node;
    struct node
    {
        int value;
        Node *nextpr;
    };



    //bubblesort method declaration
    void bubbleSort(struct node *begin); 
    //swap method declaration
    void swap(struct node *a, struct node *b); 
    //delete node method declaration 
    void deleteNode(struct node **head_ref, int key); 
    //remove duplicate declaration
    void removeDuplicates(struct node* head); 






int main (int argc, char** argv) {
    
    //declaring int and char file pointers
    int ivalue;
    char cvalue;

    //File Pointer Declaration
    FILE *fp = fopen(argv[1],"r");
        if (fp==NULL)   {
            printf("error");
            exit (0);
        }   
    


    //initializing the pointer and head node
    Node *cptr, *head;


    //For some reason the head node has to be initialized to a garbage value before the LL can be organized
    cptr= (Node *) malloc(sizeof(Node));
    cptr->nextpr=NULL;
    cptr->value=194456;         //Just a random value to be removed immediately after the creation of the LL
    head=cptr;





    /*
    * While the file is not at the end of file, take inputs that have the format:
    *
    * %c\t%d\n
    *
    * Equivalent to:
    * 
    * i 5
    * 
    * if the value of the first character is equal to 'i', for insert:
    * make a new node named cptr, dynamically allocated with Malloc 
    * set a pointer for the next pointer to the head, previously defined with a garbage value
    * 
    * set the value of the node equal to the value scanned in the file
    * 
    * set the head pointer to the next iteration.
    * 
    * 
    * OR
    * 
    * if the value of the first character is equal to 'd', for delete, then delete the node. (if it exists.)
    * 
    * 
    * 
    */


    while (!feof(fp)){
    fscanf(fp, "%c\t%d\n", &cvalue, &ivalue);

        //If the cvalue is i, then initialize a node and link it up.
        if (cvalue == 'i'){

            cptr = (Node *) malloc(sizeof(Node));
            cptr->nextpr=head;
            cptr->value=ivalue;
            head=cptr;

            
        //if the cvalue is d, then it should be deleted.

        } else if (cvalue == 'd'){
            deleteNode(&head, ivalue);
        }
    }



    //Remove the placeholder head that was initialized to appease the fsanatize constraint in the makefile
    deleteNode(&head, 194456); 




    //At this point, the Linked List has been created and the garbage header node has been deleted.

    //Additionally, the 'd' values have been removed, if applicable. 




    //COUNT THE LIST
    int count = 0;  // begin counter 
    struct node* tempcu1 = head;  // Initialize tempcu1 (tempcu already in use) 
    while (tempcu1 != NULL) 
    { 
        count++; 
        tempcu1 = tempcu1->nextpr; 
    } 

    //Print the count BEFORE sort and removal of duplicates.
    printf("%d\n", count);       



    //Sort the linked list.
    bubbleSort(head); 

    //remove any duplicates from the linked list.
    removeDuplicates(head);



    //PRINTS THE LIST       
    struct node *temp;
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->value);
            temp=temp->nextpr;
    }
    

    return 0;


}




//Function that will bubble sort a linked list
void bubbleSort(struct node *begin) 
{ 
    int moved; 
    struct node *temptr1; 
    struct node *temptr2 = NULL; 
  
    if (begin == NULL) 
        return; 
  
    do
    { 
        moved = 0; 
        temptr1 = begin; 
  
        while (temptr1->nextpr != temptr2) 
        { 
            if (temptr1->value > temptr1->nextpr->value) 
            {  
                swap(temptr1, temptr1->nextpr); 
                moved = 1; 
            } 
            temptr1 = temptr1->nextpr; 
        } 
        temptr2 = temptr1; 
    } 
    while (moved); 
} 

//function to swap the values of two input struct nodes  
void swap(struct node *a, struct node *b) 
{ 
    int temp = a->value; 
    a->value = b->value; 
    b->value = temp; 
} 

//function to delete a node
void deleteNode(struct node **head_ref, int key) 
{ 
    //create an initial head temp variable
    struct node* temp = *head_ref, *ante; 
  
    // If the head temp is a node that needs to be deleted, then remove it and reassign the pointer: 
    if (temp != NULL && temp->value == key) 
    { 
        *head_ref = temp->nextpr;   // temp header pointer 
        free(temp);               // free old temp variable 
        return; 
    } 
  
    // Loop through to find the node to be deleted
    // the ante pointer points to the next pointer enabling traversal of the list
    while (temp != NULL && temp->value != key) 
    { 
        ante = temp; 
        temp = temp->nextpr; 
    } 
    //error check for bad removal
    if (temp == NULL) return; 
  
    //remove the deletion node and free the memory
    ante->nextpr = temp->nextpr; 
  
    free(temp);  // Free memory 
} 


//Helper function to remove any duplicates found after sorting and removing of the specified removals:

void removeDuplicates(struct node* head)

{ 
    //traverals pointer
    struct node* tempcu = head; 
  
    //pointer that points to the node 2 spaces after
    struct node* twoafter;  
    
    //error check empty list
    if (tempcu == NULL)  
       return;  
  
    //list transversal
    while (tempcu->nextpr != NULL)  
    { 
       //evaluate
        if (tempcu->value == tempcu->nextpr->value)  
       {               
           twoafter = tempcu->nextpr->nextpr; 
           free(tempcu->nextpr); 
           tempcu->nextpr = twoafter;   
       } 
       else //ONLY ADVANCE if there is no if statement condition met. 
       { 
          tempcu = tempcu->nextpr;  
       } 
    } 
} 
