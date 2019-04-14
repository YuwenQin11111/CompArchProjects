/*
 *
 * 
 * 
 * The fifth part requires you to read an input string representing a sentence, 
 * form a word whose letters are all the vowels in the given sentence, and print it.
 * Input and output format: This program takes a string of space-separated words, and 
 * should output a single word as the output.
 * 
 * 
 * $./fifth Hello World!
 * eoo
 * 
 * 
 * 
 * $./fifth Welcome to CS211
 * 
 * 
 * eoeo
 * 
 * 
 * $./fifth Rutgers Scarlet Knights
 * 
 * 
 * ueaei
 * 
 * 
 * 
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isCONST(char);

int main(int argc, char *argv[]){
    
    //READ # OF ARGUMENTS AND LOOP THROUGH TO DEAL WITH MULTIPLE ARGS
    for (int i = 1; i<argc; i++){

        char StrToPass[1000];

        strcpy(StrToPass, argv[i]);

        char t[1000];

        int COUNTER, COUNTER2 = 0;


        for(COUNTER = 0; StrToPass[COUNTER] != '\0'; COUNTER++) {
            if(isCONST(StrToPass[COUNTER]) == 0){
                t[COUNTER2] = StrToPass[COUNTER];
                COUNTER2++;
            }
        }


        t[COUNTER2] = '\0';         

        printf("%s", t);
}

printf("\n");
return 0;

}


//ARRAY TO CHECK AGAINST GARBAGE VALUES:
int isCONST(char ch)
{
    if (ch == 'b' || ch == 'B' || ch == 'c' || ch == 'C' || ch == 'd' || ch == 'D' || ch =='f' || ch=='F' || ch == 'g' 
    || ch == 'G'|| ch == 'h' || ch == 'H' || ch == 'j' || ch == 'J' || ch == 'k' || ch == 'K' || ch =='l' || ch=='L' || ch == 'm' 
    || ch == 'M' || ch == 'n' || ch == 'N' || ch == 'p' || ch == 'P' || ch == 'q' || ch =='Q' || ch=='r' || ch == 'R' 
    || ch == 's' || ch == 'S' || ch == 't' || ch == 'T' || ch == 'v' || ch == 'V' || ch =='w' || ch=='W' || ch == 'x' 
    || ch == 'X' || ch == 'y' || ch == 'Y' || ch == 'z' || ch == 'Z'|| ch == '!'|| ch == '?'|| ch == '.'|| ch == '1'
    || ch == '2'|| ch == '3'
    || ch == '4'|| ch == '5'|| ch == '6'|| ch == '7'|| ch == '8'|| ch == '9'|| ch == '0'|| ch == '@'|| ch == '#'|| ch == '$'|| ch == '%'
    || ch == '^'|| ch == '&'|| ch == '*'|| ch == '('|| ch == ')'|| ch == '-'|| ch == '_'|| ch == '+'|| ch == '='|| ch == '['|| ch == ']'
    || ch == '|'|| ch == ':'|| ch == ';'|| ch == '"'|| ch == ','|| ch == '.'|| ch == '`'|| ch == '~'){
    
    return 1;

    } else {

      return 0;

    }
}
