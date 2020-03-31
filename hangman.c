#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

char *list = "coronavirus";

int main(void) {
   printf("The list of words is:\n");
   printf("coronavirus\n");
   int wordi, length, lives = 5;
   char word[25];

   int j = 0, correct, i = 0;
   char symb;
   srand((unsigned int) time(NULL));
   printf("Let's start. You have %d lives \n", lives);
   wordi = 0;

   length = strlen(&list[wordi]);
   for (j = 0; j < length; j++) {
      word[j] = '*';
   }

   word[length] = 0;
   printf("%s\n", word);
   while ((lives > 0) && (i < length)) {
      correct = 0;
      printf("Enter a letter: ");
      do {
         scanf("%c", & symb);
         symb = tolower(symb);
         if ((symb > ' ') && ((symb < 'a') || (symb > 'z'))) {
            printf("Invalid character\nEnter a letter: ");
         }
      } while ((symb < 'a') || (symb > 'z'));
      for (j = 0; j < length; j++) {
         if (symb == word[j]) {
            lives--;
            printf("Same letter typed. %i lives left.\n", lives);
            break;
         }
      }
      if (j == length) {

         for (j = 0; j < length; j++) {
            if (symb == list[j]) {
               word[j] = symb;
               i++;
               correct = 1;
            }
         }
         if (correct == 0) {
            lives--;
            if (lives > 0) {
               printf("Wrong. You have %i lives.\n", lives);
            } else {
               printf("You lose.\n");
               return 0;
            }
         } else {
            if (i < length) {
               printf("Correct.\n");
            } else {
               printf("Congratulations!\n");
            }
         }
         printf("The word is: %s\n", word);
      }
   }
}
