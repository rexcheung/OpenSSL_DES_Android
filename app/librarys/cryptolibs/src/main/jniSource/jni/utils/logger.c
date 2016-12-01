//
// Created by zxbin on 16-9-23.
//

#include <android/log.h>
#include "convert.h"

const char IS_LOG = 1;

void logi(const char *tag, const char *msg) {
    if (IS_LOG)
        __android_log_print(ANDROID_LOG_INFO, tag, "%s", msg);
}

void logw(const char *tag, const char *msg) {
    if (IS_LOG)
        __android_log_print(ANDROID_LOG_WARN, tag, "%s", msg);
}

void loge(const char *tag, const char *msg) {
    if (IS_LOG)

        __android_log_print(ANDROID_LOG_ERROR, tag, "%s", msg);
}

void logger(const char *tag, const char *arg, const void *msg) {
    if (IS_LOG)
        __android_log_print(ANDROID_LOG_ERROR, tag, arg, msg);
}

void loguchar(const char *tag, const unsigned char *msg) {
    if (IS_LOG){
        char *logtext = uchar2char(msg);
        __android_log_print(ANDROID_LOG_ERROR, tag,"%s", logtext);
    }
}
