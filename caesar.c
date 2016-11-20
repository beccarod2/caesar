/* program takes a single-char key from user and a message and then prints an encrypted message. */ 

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
 
   int ALPHA_LEN = 26; // # of chars in alphabet
   int ASCII_LOWER_LEN = 97; // starting int value of 'a'
   int ASCII_UPPER_LEN = 65; // starting int value of 'A'
   
// decalre var for key entered at command line
    int key = 0;
    
// ensure user types in a single key     
   if (argc !=2) 
   {
       printf("cipher key must be a single positive integer");
       return 1;
   }

   key = atoi(argv[1]);  //convert key to an integer
   
   string string_message = GetString();  // get message
   
   // declare int array for message
   int message_length = strlen(string_message);
   int int_message[message_length];
   
   //copy string array of message into an int array
   for (int i = 0; i < message_length; i++)
    {
     int_message[i] = string_message[i];  
     }

   //code message maintaining case
    for (int j = 0; j < message_length; j++)
    {
           if (isupper (int_message[j]) )
           {
               int_message[j] = ASCII_UPPER_LEN + (((int_message[j] - ASCII_UPPER_LEN) + key) % ALPHA_LEN);   
           }
           if (islower (int_message[j]) )
           {
               int_message[j] = ASCII_LOWER_LEN + (((int_message[j] - ASCII_LOWER_LEN) + key) % ALPHA_LEN);
        }
     }
   
   // print out coded message
   for (int a = 0; a < message_length; a++)
  {
      printf("%c", int_message[a]);
  }
   printf("\n");
   return 0;
}