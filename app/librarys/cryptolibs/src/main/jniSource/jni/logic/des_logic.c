#include <jni.h>
#include <string.h>
#include "../openssl/des.h"
#include "des_logic.h"
#include "../utils/logger.h"


const char DEBUG_MODE = JNI_FALSE;

unsigned char *fillPadding(const unsigned char *msg) {
    size_t inLength = strlen(msg);
    size_t outLength = (inLength + 8) / 8 * 8;

    unsigned char *newOutput = malloc(outLength + 1);
    memcpy(newOutput, msg, inLength);

    const int padding = 8 - inLength % 8;

    if (padding <= 8) {
        int i;
        for (i = inLength; i < outLength; i++) {
            newOutput[i] = (unsigned char) padding;
        }
    }

    newOutput[outLength] = 0x00;

    return newOutput;
}

unsigned char *cbcEncry(const unsigned char *msg, const unsigned char *keyText) {
    DES_cblock key;
    DES_key_schedule key_schedule;

    memcpy(key, keyText, 8);
    DES_set_key_unchecked(&key, &key_schedule);

    //填充字符串
    unsigned char *paddingStr = fillPadding(msg);

    //需要加密的字符串
    size_t len = (strlen(paddingStr) + 7) / 8 * 8;
    unsigned char *output = malloc(len + 1);

    //IV
    DES_cblock ivec;
    memcpy(ivec, keyText, strlen(keyText));

    //加密
    DES_ncbc_encrypt(paddingStr, output, strlen(paddingStr), &key_schedule, &ivec, DES_ENCRYPT);

    output[len] = 0x00;

    free(paddingStr);

    return output;
}

unsigned char *cbcDecrypt(const unsigned char *msg, const unsigned char *keyText, const int msgLength) {
    //loguchar("cbcDecrypt msg", msg);
    DES_cblock key;
    DES_key_schedule key_schedule;

    memcpy(key, keyText, 8);
    DES_set_key_unchecked(&key, &key_schedule);

    //需要加密的字符串
    size_t lastPos = (msgLength + 7) / 8 * 8;
    size_t length = lastPos + 1;
    unsigned char *output = malloc(length);
    //logger("cbcDecrypt size = ", "%lu", strlen(msg));


    //IV
    DES_cblock ivec;
    memcpy(ivec, keyText, strlen(keyText));

    //解密
    DES_ncbc_encrypt(msg, output, msgLength, &key_schedule, &ivec, DES_DECRYPT);

    //删除填充的字符。
    output[lastPos] = 0x00;
    unsigned char *deleteLateer = deletePadding(output, length);

    free(output);

    return deleteLateer;
}

unsigned char *deletePadding(unsigned char *msg, size_t len) {
    if (len < 2) return msg;

    // msg[len-1] == 0x00，所以要取msg[len-2]的值。
    int lastPos = len - 2;
    unsigned char lastChar = msg[lastPos];
    if (lastChar >= 0x01 && lastChar <= 0x08) {

        size_t length = len - lastChar;
        size_t lastCharPos = length - 1;
        unsigned char *newMsg = malloc(length);
        memcpy(newMsg, msg, lastCharPos);
        newMsg[lastCharPos] = 0x00;

        return newMsg;
    } else {
        return msg;
    }
}