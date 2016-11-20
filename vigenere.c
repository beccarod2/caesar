/* program takes a multi-char key from user and a message and then prints an 
encrypted message. */ 

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
 
// ensure user types in a single word for the key    
   if (argc !=2) 
   {
       printf("cipher key must be a single word\n");
       return 1;
   }

   int key_length = strlen(argv[1]);  //get key length
   
   //ensure user types in only letters for the key
   for (int y = 0; y < key_length; y++)
   {
    if (!isalpha(argv[1][y]))
    {
     printf("cipher key must be all letters\n");
     return 1;
    }
   }
   //declare int array for the key 
   int key_array[key_length];

  //convert key into an int array using all ower case chars
    for (int i = 0; i < key_length; i++)
     {
      key_array[i]=tolower(argv[1][i]);
     }
  //reduce key by ASCII value of lower case a so a = 0 etc.
    for (int i = 0; i < key_length; i++)
     {
      key_array[i]-= ASCII_LOWER_LEN;
     }
     
   string string_message = GetString();   // get message from user
   int message_length = strlen(string_message);  // declare int to hold length of message
   int int_message[message_length];  //declare array to hold message
   
   //copy string array of message into int array
   for (int i = 0; i < message_length; i++)
    {
     int_message[i] = string_message[i];  
     }

   //code message maintaining case and only increasing key array index (a) for chars (not spaces etc)
    for (int j = 0, a = 0; j < message_length; j++)
    {
           if (isupper (int_message[j]) && isalpha (int_message[j]))
           {
               int_message[j] = ASCII_UPPER_LEN + (((int_message[j] - ASCII_UPPER_LEN) + key_array[a%key_length]) % ALPHA_LEN); 
               a+=1;
           }
           else if (islower (int_message[j]) && isalpha (int_message[j]))
           {
               int_message[j] = ASCII_LOWER_LEN + (((int_message[j] - ASCII_LOWER_LEN) + key_array[a%key_length]) % ALPHA_LEN);
                a+=1;
           }
     }
 
   // print out coded message
   for (int c = 0; c < message_length; c++)
  {
      printf("%c", int_message[c]);
  }
   printf("\n");
   return 0;
}