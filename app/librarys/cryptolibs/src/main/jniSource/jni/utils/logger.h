//
// Created by zxbin on 16-9-23.
//

#ifndef ANDROID_NDK_OPENSSL_MASTER_LOGGER_H
#define ANDROID_NDK_OPENSSL_MASTER_LOGGER_H

void logi(const char *tag, const char *msg);
void logw(const char *tag, const char *msg);
void loge(const char *tag, const char *msg);
void logger(const char *tag, const char *arg, const void *msg);
void loguchar(const char *tag, const unsigned char *msg);

#endif //ANDROID_NDK_OPENSSL_MASTER_LOGGER_H