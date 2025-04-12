#pragma once

int BlockCipherEncrypt(const char* plaintext, int plaintext_len, int* key, int key_len, int alphabet_size, char* ciphertext, int* ciphertext_len);
int BlockCipherDecrypt(const char* plaintext, int plaintext_len, int* key, int key_len, int alphabet_size, char* ciphertext, int* ciphertext_len);
