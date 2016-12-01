//
// Created by zxbin on 16-9-22.
//

#include <jni.h>
#include <stddef.h>
#include <string.h>
#include <android/log.h>
#include "utils/convert.h"
#include "logic/des_logic.h"
#include "utils/logger.h"

const char *TAG = "des.c";
const char DEBUG = JNI_FALSE;


JNIEXPORT jbyteArray JNICALL Java_com_example_openssltest_EncryUtils_encryJNI
        (JNIEnv *env, jobject obj, jstring msg, jstring keyStr){
    unsigned const char *msgChars = (const unsigned char *) jString2Chars(env, msg);
    unsigned const char *keyChars = (const unsigned char *) jString2Chars(env, keyStr);
    //loguchar("encryJNI msgChars = ", msgChars);
    unsigned char *result = cbcEncry(msgChars, keyChars);


    // 转换结果数据类型, unsigned char -> jbyteArray
    const size_t length = (strlen(msgChars) + 8) / 8 * 8;
    jbyteArray *buf = (*env)->NewByteArray(env, length);
    (*env)->SetByteArrayRegion(env, buf, 0, length, result);

//    loguchar("encryJNI result", result);
    free(result);

    return buf;

}

JNIEXPORT jbyteArray JNICALL Java_com_example_openssltest_EncryUtils_decryptJNI
    (JNIEnv *env, jobject obj, jbyteArray msg, jstring keyStr){

    //loge("decryptJNI", "1 入口");
    jsize len = (*env)->GetArrayLength(env, msg);
    //__android_log_print(ANDROID_LOG_ERROR, "decryptJNI length", "%d", (int)len);

    unsigned const char *msgChars = (const unsigned char *) bytes2uchar(env, msg);
    unsigned const char *keyChars = (const unsigned char *) jString2Chars(env, keyStr);

    //logger("decryptJNI size = ", "%lu", strlen(msgChars));

    //loge("decryptJNI", "2 解密前");
    unsigned char *result = cbcDecrypt(msgChars, keyChars, (int)len);

    //loge("decryptJNI", "3 转jbyteArray前");

    // 转换结果数据类型, unsigned char -> jbyteArray
    size_t inLength = strlen(result);
    //loge("decryptJNI", "3-1 ");
    jbyteArray *buf = (*env)->NewByteArray(env, inLength);
    //loge("decryptJNI", "3-2 ");
    (*env)->SetByteArrayRegion(env, buf, 0, inLength, result);
    //loge("decryptJNI", "3-3 ");


    // free(result);
    //loge("decryptJNI", "4 返回");

    return buf;
}

JNIEXPORT jstring JNICALL Java_com_example_openssltest_EncryUtils_test
        (JNIEnv *env, jobject obj, jstring msg, jstring keyStr){
    return (*env)->NewStringUTF(env, "OK");
}