// The program encrypts messages using a substitution cipher.

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool valid_key(string key);
void plaintext_subtitution_to_cyphertext(string p, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (valid_key(argv[1]))
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        plaintext_subtitution_to_cyphertext(plaintext, argv[1]);
    }
    else
    {
        return 1;
    }
    printf("\n");
}
bool valid_key(string key)
{
    int len = strlen(key)
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetical characters.\n");
            return false;
        }
        for (int j = 0; j < len; j++)
        {
            if (i == j)
            {
                continue;
            }
            else if (key[i] == key[j])
            {
                printf("Key must contain each letter exactly once.\n");
                return false;
            }
        }
    }
    return true;
}
void plaintext_subtitution_to_cyphertext(string p, string key)
{
    int m;
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isupper(p[i]))
        {
            m = ((int) p[i] - 'A') % 26;
            printf("%c", toupper(key[m]));
        }
        else if (islower(p[i]))
        {
            m = ((int) p[i] - 'a') % 26;
            printf("%c", tolower(key[m]));
        }
        else
        {
            printf("%c", p[i]);
        }
    }
}
