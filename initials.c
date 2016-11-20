/* program takes a name from user and outputs initials */ 

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = GetString();
    
    printf("%c", toupper(s[0]));

        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i] == 32)
            {
                  printf("%c", toupper(s[i+1]));
            }
        }
    printf("\n");    
}