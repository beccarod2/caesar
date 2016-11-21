/* program re-writes the greedy from pset1 using an array */ 

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change_user;
    float change;
    int int_change;
    int counter = 0;
    int change_array[] = {25, 10, 5, 1};
    int no_coins = 4;
    
    do 
    {
        printf("How much change is owed?\n");
        change_user = GetFloat();
        change = roundf(change_user * 100); 
        int_change = change; 
    }
    while (change_user <= 0.0 ); // ensure user enters an amount more than 0
    
    for (int i = 0; i < no_coins; i++)
    {
        while (int_change >= change_array[i])
        {
            int_change -= change_array[i];
            counter += 1;  
        }
    }
   printf("%i\n", counter);
   
}
