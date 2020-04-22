#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char *list = "coronavirus";

int main(void) {
   printf("The list of words is:\n");
   printf("coronavirus\n");

   //Variables

   int wordi, length, lives = 5;
   char word[25];
   int j = 0, correct, i = 0;
   char symb;

   printf("Let's start. You have %d lives \n", lives); //Show number of lives
   wordi = 0;

   length = strlen(&list[wordi]); //Assingning a value of length that is the measure of
   								 //the word in the list (coronavirus)
   for (j = 0; j < length; j++) { //First for to show an * per each letter of the word
      word[j] = '*';
   }

   word[length] = 0;
   printf("%s\n", word); //printing the word
   while ((lives > 0) && (i < length)) { //Repeate the loop while follow the condition
      correct = 0;
      printf("Enter a letter: "); //Ask for a letter
      do {
         scanf("%c", & symb); //Save letter in the variable symb
         symb = tolower(symb);  //Transform the letter in lower case with the function
         if ((symb > ' ') && ((symb < 'a') || (symb > 'z'))) { //Check if it is a word with space
            printf("Invalid character\nEnter a letter: ");    //If is the case print message
         }
      } while ((symb < 'a') || (symb > 'z')); //If the word is between a - z
      for (j = 0; j < length; j++) { //Compare the letter typed for each in the word to check
         if (symb == word[j]) { //if it was writted before
            lives--;	//if the case, user loses a life
            printf("Same letter typed. %i lives left.\n", lives);
            break;
         }
      }
      if (j == length) { //If the last for structure has been complete, the
		 	//following algorithm could be done

         for (j = 0; j < length; j++) { //Make a for until the length of the letter
            if (symb == list[j]) { //compare if the word typed is equal to some in the
            					 //principal word
               word[j] = symb;  //if is the case, replace the '*' for the letter
               i++;	//Add 1 to the variable i
               correct = 1; //assign a 1 value in the correct variable
            }
         }
         if (correct == 0) { //If isn't none of the letters assign value 0
         					//to correct
            lives--; //And the user loses a life
            if (lives > 0) { //Check if user still has lifes
               printf("Wrong. You have %i lives.\n", lives); //If the case print the message
            } else {
               printf("You lose.\n"); //If not, end game
               return 0;
            }
         } else {
            if (i < length) { //If i is less of the length of the word
               printf("Correct.\n");
            } else {
               printf("Congratulations!\n"); //If not, means that we don't have more
               								//letters to check and wins
            }
         }
         printf("The word is: %s\n", word); //Finally print the entire word
      }
   }
}
