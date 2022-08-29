package com.example.demondk2;

import android.graphics.Bitmap;

/**
 * 创建时间：2022/8/25
 * 编写人： 陈陈陈
 * 功能描述：
 */
public class JNIBasicType {
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * 基本类型
     * @param n
     * @return
     */
    public native int callNativeInt(int n);

    public native byte callNativeByte(byte b);

    public native char callNativeChar(char b);

    public native short callNativeShort(short b);

    public native long callNativeLong(long b);

    public native float callNativeFloat(float b);

    public native double callNativeDouble(double b);

    public native boolean callNativeBoolean(boolean b);

    /**
     * java与JNI String类型转换
     * @param n
     * @return
     */
    public native String callNativeString(String n);

    /**
     * java与JNI引用类型转换
     * @return
     */
    public native String handleStringArray(String[] array);

    /**
     * JNI 访问java类的字段
     * @param person
     */
    public native void accessInstanceField(Person person);

    /**
     * JNI 访问java类静态字段
     * @param person
     */
    public native void accessStaticField(Person person);

    public static int num = 99;
    /**
     * JNI 修改当前类的静态变量
     */
    public static native void accessStaticField2();

    /**
     * JNI 访问java类实例方法
     */
    public static native void accessInstanceMethod(Person person);

    /**
     * JNI 访问java类的静态方法
     */
    public static native void accessStaticMethod(Person person);

    /**
     * JNI 函数通过接口参数回调java方法：跟 JNI 访问java类实例方法 一样
     * JNI 子线程如何回调java的主线程方法？
     */
    public native void nativeCallback(ICallback callback);
    public native void nativeThreadCallback(IThreadCallback callback);

    /**
     * JNI 创建java类
     * 通过调用类的构造方法创建java类
     * 有两种实现方式
     */
    public native Person invokeAnimalConstructors();
    public native Person allocObjectConstructor();


    /**
     * 引用类型:
     * 局部引用，全局引用，弱引用
     */
    public native String errorCacheLocalReference();
    public native String cacheWithGlobalReference();
    public native String useWeakGlobalReference();

    /**
     * 异常处理：在native 调用 有异常的java代码
     */
    public native void nativeInvokeJavaException();

    /**
     * native 向java中抛出异常
     */
    public native void nativeThrowException();
    private int operation(){
        //2/0会导致崩溃
        return 2/0;
    }

    /**
     * 创建线程
     */
    public native void createNativeThread();
    public native void createNativeThreadWithArgs();
    public native void joinNativeThread();

    public native void waitNativeThread();
    public native void notifyNativeThread();

    public native void startProductAndConsumerThread();

    /**
     * bitmap 图像操作
     */
    public native Bitmap callNativeMirrorBitmap(Bitmap bitmap);
}