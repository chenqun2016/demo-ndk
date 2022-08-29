#  ndk 开发
1：app:build.gradle 文件里增加：
externalNativeBuild {
        cmake {
            path file('src/main/cpp/CMakeLists.txt')
            version '3.6.0'
        }
    }

 externalNativeBuild {
            cmake {
                cppFlags '-std=c++11'
            }
        }

2：main目录下增加 cpp 目录及 CMakeLists.txt等文件

#动态库的函数注册
1：静态注册： java文件（MainActivity）中直接写好方法（public native int getTotal();）,
然后使用快捷方法生成本地方法到 native-lib.cpp；
2：动态注册：比静态注册 少了查找方法的过程，更快。参考类：JNIDynamicLoad
    System.loadLibrary("dynamic-lib");后会系统会回调动态库的 JNI_OnLoad 方法；
    在  JNI_OnLoad 中通过 jni.h 的 RegisterNatives 方法动态注册


# Java 和 JNI 的交互
1：JNI中的基本数据类型：jbyte,jchar,jint,jshort,jlong,jfloat,jdouble,jboolean
可以和 c 直接转换

2：JNI中的jstring：不可以和 c 直接转换，需要调用env->GetStringUTFChars()转换成 c 的string
3: 其它



# JNI 引用类型：全局引用，局部引用，弱引用
全局引用不会在程序退出后释放。
局部引用在程序退出后释放，局部引用过多会导致程序崩溃，能尽早回收就尽早回收；（env->DeleteLocalRef(localRefs);）


#JNI 线程操作
创建线程：int pthread_create(pthread_t* __pthread_ptr, pthread_attr_t const* __attr, void* (*__start_routine)(void*), void*);
 //参数：
    // 1，线程句柄，线程创建成功后返回。
    // 2，线程调度信息，堆栈大小，调度优先级。
    // 3，线程调用的函数。
    // 4，传给线程的参数。

    //互斥锁；
    pthread_mutex_t mutex;
    //条件变量；实现线程之间的唤醒和释放；
    pthread_cond_t cond;
