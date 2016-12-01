#ifndef DES_LOGIC
#define DES_LOGIC

unsigned char *fillPadding(const unsigned char *msg);

unsigned char *cbcEncry(const unsigned char *msg, const unsigned char *keyText);

unsigned char *cbcDecrypt(const unsigned char *msg, const unsigned char *keyText, const int msgLength);

unsigned char * deletePadding(unsigned char *msg, size_t len);

#endif
