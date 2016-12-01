//
// Created by zxbin on 16-9-27.
//

#ifndef ANDROID_NDK_OPENSSL_MASTER_CONVERT_H
#define ANDROID_NDK_OPENSSL_MASTER_CONVERT_H

#include <jni.h>

const char *jString2Chars(JNIEnv *env, jstring javaString);

char *bytes2Chars(JNIEnv *env, jbyteArray jbytes);

unsigned char *bytes2uchar(JNIEnv *env, jbyteArray jbytes);

unsigned char *jString2Uchars(JNIEnv *env, jstring javaString);

jbyteArray uchars2jbytes(JNIEnv *env, unsigned char *msg);

char *uchar2char(const unsigned char *msg);

jbyteArray uchars2jbyteArray(JNIEnv *env, unsigned char *msg, int len);

#endif //ANDROID_NDK_OPENSSL_MASTER_CONVERT_H
