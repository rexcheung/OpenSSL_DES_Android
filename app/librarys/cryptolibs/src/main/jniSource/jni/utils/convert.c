//
// Created by zxbin on 16-9-27.
//

#include <string.h>
#include <stdio.h>
#include <jni.h>
#include "convert.h"
#include "logger.h"

const char *jString2Chars(JNIEnv *env, jstring javaString) {
    return (*env)->GetStringUTFChars(env, javaString, 0);
}

char *bytes2Chars(JNIEnv *env, jbyteArray jbytes) {
    return (char *) (*env)->GetByteArrayElements(env, jbytes, 0);
}

unsigned char *bytes2uchar(JNIEnv *env, jbyteArray jbytes) {
    jbyte *bBuffer = (*env)->GetByteArrayElements(env, jbytes, 0);
    unsigned char *buf = (unsigned char *) bBuffer;
    return buf;
}

unsigned char *jString2Uchars(JNIEnv *env, jstring javaString) {

}

jbyteArray uchars2jbytes(JNIEnv *env, unsigned char *msg) {
    int len = strlen(msg);
    jbyteArray *buf = (*env)->NewByteArray(env, len);
    (*env)->SetByteArrayRegion(env, buf, 0, len, msg);
    return buf;
}

char *uchar2char(const unsigned char *msg) {
    int length = strlen(msg);
    char *converted = malloc(length * 2 + 1);
    int i;
    for (i = 0; i < length; i++) {
        sprintf(&converted[i * 2], "%02X", msg[i]);
    }
    return converted;
}

jbyteArray uchars2jbyteArray(JNIEnv *env, unsigned char *msg, int len) {
    jbyteArray *buf = (*env)->NewByteArray(env, len);
    (*env)->SetByteArrayRegion(env, buf, 0, len, msg);
    return buf;
}