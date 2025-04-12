#include <stdio.h>
#include "blockcipher.h"

#define MAX_TEXT_LEN 256
#define MAX_KEY_LEN 10

int main()
{
    char plaintext[MAX_TEXT_LEN];
    int plaintext_len = 0;
    char ciphertext[MAX_TEXT_LEN];
    int ciphertext_len = 0;
    int alphabet_size = 26; // |X|
    int key_len = 0; // t
    int key[256]; // j_i
    int i = 0;

    // enter plaintext
    printf("Enter plaintext (max 256 symbols): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext_len = strlen(plaintext);
    if (plaintext[plaintext_len - 1] == '\n')
    {
        plaintext[plaintext_len - 1] = '\0';
        plaintext_len--;
    }

    // enter key (block) size
    printf("Enter block size (t <= %d): ", MAX_KEY_LEN);
    scanf("%d", &key_len);
    if (key_len <= 0 || key_len > MAX_KEY_LEN)
    {
        printf("Wrong block size\n");
        return 1;
    }

    // enter key (j array)
    printf("Enter key (space-separated integers, for example: 3 7 10): ");
    for (i = 0; i < key_len; i++)
    {
        scanf("%d", &key[i]);
    }

    printf("Cryptosystem parameters:\n");
    printf("Plaintext: %s\n", plaintext);
    printf("Key: j = {");
    for (i = 0; i < key_len; i++)
    {
        printf("%d", key[i]);
        if (i < key_len - 1)
            printf(", ");
    }
    printf("}\n");
    printf("Key length (block length): t = %d\n", key_len);
    printf("Alphabet size: |X|= %d\n", alphabet_size);

    int result = BlockCipherEncrypt(plaintext, plaintext_len, key, key_len, alphabet_size, ciphertext, &ciphertext_len);
    if (result != 0)
    {
        printf("Encryption failed\n");
        return 1;
    } 
    printf("Ciphertext: %.*s\n", ciphertext_len, ciphertext);

    result = BlockCipherDecrypt(ciphertext, ciphertext_len, key, key_len, alphabet_size, plaintext, &plaintext_len);
    if (result != 0)
    {
        printf("Decryption failed\n");
        return 1;
    }
    printf("Plaintext: %.*s\n", plaintext_len, plaintext);

    getchar();
    getchar();

    return 0;
}

