package com.example.demondk2;

/**
 * 创建时间：2022/8/24
 * 编写人： 陈陈陈
 * 功能描述：
 */
public class JNIDynamicLoad {
    static {
        System.loadLibrary("dynamic-lib");
    }

    public native int getRandomNum();

    public native String getNativeString();
}
