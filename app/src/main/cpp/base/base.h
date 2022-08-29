//
// Created by 陈陈陈 on 2022/8/25.
//

#ifndef DEMONDK2_BASE_H
#define DEMONDK2_BASE_H

#include <android/log.h>
#include <jni.h>

#define TAG "jni_proctice"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)

#endif //DEMONDK2_BASE_H
