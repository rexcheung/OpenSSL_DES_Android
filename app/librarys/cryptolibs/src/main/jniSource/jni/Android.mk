# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := cryptoqh
LOCAL_SRC_FILES := openssl/lib/$(TARGET_ARCH)/libcrypto.so
LOCAL_EXPORT_C_INCLUDES := crypto
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := openssl-jni
LOCAL_SRC_FILES :=  utils/logger.c      \
                    utils/convert.c     \
                    logic/des_logic.c   \
                    desc.c
# LOCAL_ALLOW_UNDEFINED_SYMBOLS := true
LOCAL_SHARED_LIBRARIES := cryptoqh
LOCAL_LDLIBS    := -llog
include $(BUILD_SHARED_LIBRARY)