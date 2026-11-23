LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := FreeAimCtrl
LOCAL_SRC_FILES := main.cpp
LOCAL_CPPFLAGS += -O2 -std=c++17 -fvisibility=hidden -fno-exceptions -fno-rtti
LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)
