// The program prompts the user for a credit card number and then reports
// whether it is a valid American Express, MasterCard, or Visa card number.

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int find_length(long n);
long first_two_digits(long credit_card_number);
int luhns_algorithm(long n);

int main(void)
{
    // prompt user for input + convert string input into long
    long cardnum = get_long("Number: ");

    // check the validity of card number
    if (luhns_algorithm(cardnum) % 10 == 0)
    {
        if (find_length(cardnum) == 15 && (first_two_digits(cardnum) == 37 ||  first_two_digits(cardnum) == 34))
        {
            printf("AMEX\n");
        }
        else if (find_length(cardnum) == 16 && first_two_digits(cardnum) >= 51 &&  first_two_digits(cardnum) <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (first_two_digits(cardnum) / 10 == 4 && (find_length(cardnum) == 13 || find_length(cardnum) == 16))
        {
            printf("VISA\n");
        }
        else printf("INVALID\n");
    }
    else printf("INVALID\n");
}
long first_two_digits(long credit_card_number)
{
    int l = find_length(credit_card_number);
    return credit_card_number / pow(10, (l - 2));
}
int find_length(long n)
{
    int len;
    for (len = 0; n != 0; n /= 10, len++);
    return len;
}
int luhns_algorithm(long n)
{
    int digits_sum1 = 0;
    int digits_sum2 = 0;
    int number;

    while (n > 0)
    {
        if (n % 100 / 10 > 4)
        {
            digits_sum1 += (n % 100 / 10) * 2 - 9;
        }
        else
        {
            digits_sum1 += (n % 100 / 10) * 2;
        }
        digits_sum2 += n % 10;
        n /= 100;
    }
    return digits_sum1 + digits_sum2;
}
