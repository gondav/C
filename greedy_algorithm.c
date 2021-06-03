// The program that first asks the user how much change is owed and then prints the
// minimum number of coins with which that change can be made.
// quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // ask the user how much change is owed
    float change;
    do{
        change = get_float("Change owed: ");
    }
    while (change < 0);

    int cents = round(change * 100);

    int numcoins = 0;

    // sum minimum number of coins with which the change can be made
    do{
        // quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)
        if (cents >= 25){
            numcoins++;
            cents = cents - 25;
        }
        else if (cents >= 10){
            numcoins++;
            cents -= 10;
        }
        else if (cents >= 5){
            numcoins++;
            cents -= 5;
        }
        else if (cents >= 1){
            numcoins++;
            cents -= 1;
        }
    }
    while (cents > 0);
    printf("%i\n", numcoins);
}
