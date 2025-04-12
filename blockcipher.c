#include "blockcipher.h"

int LetterToIndex(char c)
{
    return tolower(c) - 'a';
}

// returns the letter corresponding to the index in the alphabet
char IndexToLetter(int i, int MOD)
{
    return 'a' + (i % MOD);
}

int BlockCipherEncrypt(const char* plaintext, int plaintext_len, int* key, int key_len, int alphabet_size, char* ciphertext, int* ciphertext_len)
{
    for (int i = 0; i < plaintext_len; i++)
    {
        char c = tolower(plaintext[i]);
        if (isalpha(c))
        {
            int k = LetterToIndex(c);
            int ji = key[i % key_len];
            int a = (k + ji) % alphabet_size;
            ciphertext[i] = IndexToLetter(a, alphabet_size);

            if (i % key_len == 0)
                printf("\n");

            printf("a_%d(%d) = %d + %d (mod 26) = %d -> %c\n",
                (i % key_len) + 1, k, k, ji, a, ciphertext[i]);
        }
        else
        {
            ciphertext[i] = c; // skip non-alphabetic characters
        }
    }
    ciphertext[plaintext_len] = '\0';
    *ciphertext_len = plaintext_len; // length of ciphertext is the same as plaintext

    return 0;
}

int BlockCipherDecrypt(const char* ciphertext, int ciphertext_len, int* key, int key_len, int alphabet_size, char* plaintext, int* plaintext_len)
{
    for (int i = 0; i < ciphertext_len; i++)
    {
        char c = tolower(ciphertext[i]);
        if (isalpha(c))
        {
            int k = LetterToIndex(c);
            int ji = key[i % key_len];
            // int a = (k - ji + alphabet_size) % alphabet_size;
            // code below is equivalent to the above line
            int raw = k - ji;
            int a;

            if (i % key_len == 0)
                printf("\n");

            if (raw < 0)
            {
                a = (raw + alphabet_size) % alphabet_size;
                printf("a_%d^(-1)(%d) = %d - %d + 26 = %d -> %c\n",
                       (i % key_len) + 1, k, k, ji, a, IndexToLetter(a, alphabet_size));
            }
            else
            {
                a = raw % alphabet_size;
                printf("a_%d^(-1)(%d) = %d - %d = %d -> %c\n",
                       (i % key_len) + 1, k, k, ji, a, IndexToLetter(a, alphabet_size));
            }

            plaintext[i] = IndexToLetter(a, alphabet_size);
        }
        else
        {
            plaintext[i] = c;
        }
    }
    plaintext[ciphertext_len] = '\0';
    *plaintext_len = ciphertext_len;

    return 0;
}