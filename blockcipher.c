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
            int new_index = (k + ji) % alphabet_size;
            ciphertext[i] = IndexToLetter(new_index, alphabet_size);
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
            int new_index = (k - ji + alphabet_size) % alphabet_size;
            plaintext[i] = IndexToLetter(new_index, alphabet_size);
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