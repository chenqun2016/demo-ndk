package com.example.demondk2;

import android.util.Log;

/**
 * 创建时间：2022/8/25
 * 编写人： 陈陈陈
 * 功能描述：
 */
public class Person {
    public static int age = 18;
    public String name;

    public Person(String n) {
        name = n;
    }

    @Override
    public String toString() {
        return "Person{" +
                "age=" + age +
                ", name='" + name + '\'' +
                '}';
    }

    public String callMethod(String str) {
        if (str != null) {
            Log.d("jni_proctice", "call method with " + str);
        } else {
            Log.d("jni_proctice", "call method with null");
        }
        return "";
    }

    public static String callStaticMethod(String[] strs, int num) {
        if (strs != null) {
            for (String str : strs) {
                Log.d("jni_proctice", "str is:" + str);
            }
        }
        return "";
    }
}
