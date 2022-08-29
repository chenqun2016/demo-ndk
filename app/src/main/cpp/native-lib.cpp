#include <jni.h>
#include <string>
#include <People.h>
#include "base.h"
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <queue>
#include <android/bitmap.h>


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_demondk2_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from native";
    People people;
    return env->NewStringUTF(people.getString().c_str());
}
extern "C" JNIEXPORT jint JNICALL
Java_com_example_demondk2_MainActivity_getTotal(JNIEnv *env, jobject thiz) {

}extern "C"
JNIEXPORT jint JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeInt(JNIEnv *env, jobject thiz, jint n) {
    LOGD("java int value is %d", n);
    return n * 2;
}
extern "C"
JNIEXPORT jbyte JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeByte(JNIEnv *env, jobject thiz, jbyte b) {
    LOGD("java byte value is %c", b);
}extern "C"
JNIEXPORT jchar JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeChar(JNIEnv *env, jobject thiz, jchar b) {
    LOGD("java char value is %c", b);
}extern "C"
JNIEXPORT jshort JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeShort(JNIEnv *env, jobject thiz, jshort b) {
    LOGD("java short value is %c", b);
}extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeLong(JNIEnv *env, jobject thiz, jlong b) {
    LOGD("java long value is %d", b);
}extern "C"
JNIEXPORT jfloat JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeFloat(JNIEnv *env, jobject thiz, jfloat b) {
    LOGD("java short value is %f", b);
}extern "C"
JNIEXPORT jdouble JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeDouble(JNIEnv *env, jobject thiz, jdouble b) {
    LOGD("java double value is %f", b);
}extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeBoolean(JNIEnv *env, jobject thiz, jboolean b) {
    LOGD("java boolean value is %p", b);
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeString(JNIEnv *env, jobject thiz, jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);

    char buf[128];
    int len = env-> GetStringLength(str_);
    env->GetStringUTFRegion(str_,0,len,buf);

    LOGD("jstring is %s",buf);

    env->ReleaseStringUTFChars(str_,str);
    return env->NewStringUTF("我来自c");
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_demondk2_JNIBasicType_handleStringArray(JNIEnv *env, jobject thiz,
                                                         jobjectArray a) {
        int len = env->GetArrayLength(a);
    LOGD("len is %d",len);
    jstring firstStr = static_cast<jstring>(env->GetObjectArrayElement(a, 0));
    const  char *str = env->GetStringUTFChars(firstStr,0);
    LOGD("firstStr is %s",str);
    env->ReleaseStringUTFChars(firstStr,str);

    return env->NewStringUTF("str");
}extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_accessInstanceField(JNIEnv *env, jobject thiz,
                                                           jobject person) {
   jclass clas = env->GetObjectClass(person);
   jfieldID fid = env->GetFieldID(clas,"name","Ljava/lang/String;");
   jstring str = env->NewStringUTF("龙傲天的爸爸");
   env->SetObjectField(person,fid,str);
}extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_accessStaticField(JNIEnv *env, jobject thiz,
                                                         jobject person) {
    jclass clas = env->GetObjectClass(person);
    jfieldID fid = env->GetStaticFieldID(clas,"age","I");
    int age = env->GetStaticIntField(clas,fid);
    env->SetStaticIntField(clas,fid,++age);
}extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_accessStaticField2(JNIEnv *env, jclass clazz) {
    jfieldID fid = env->GetStaticFieldID(clazz,"num","I");
    int age = env->GetStaticIntField(clazz,fid);
    env->SetStaticIntField(clazz,fid,++age);
}extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_accessInstanceMethod(JNIEnv *env, jclass clazz,
                                                            jobject person) {
    jclass clas = env->GetObjectClass(person);
    jmethodID mid = env->GetMethodID(clas,"callMethod", "(Ljava/lang/String;)Ljava/lang/String;");
    jstring str = env->NewStringUTF("dddddd");
    env->CallObjectMethod(person,mid,str);
}extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_accessStaticMethod(JNIEnv *env, jclass clazz,
                                                          jobject person) {
    jclass clas = env->GetObjectClass(person);
    jmethodID mid = env->GetStaticMethodID(clas,"callStaticMethod","([Ljava/lang/String;I)Ljava/lang/String;");
    jstring str = env->NewStringUTF("dddddd");

    jclass strClass = env->FindClass("java/lang/String");
    int size = 2;
    jobjectArray strArray = env->NewObjectArray(size,strClass, nullptr);
    jstring  strItem;
    for(int i=0;i<size;i++){
        strItem = env->NewStringUTF("string in native");
        env->SetObjectArrayElement(strArray,i,strItem);
    }
    env->CallStaticObjectMethod(clas,mid,strArray,size);
}extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_nativeCallback(JNIEnv *env, jobject thiz, jobject callback) {
    jclass clas = env->GetObjectClass(callback);
    jmethodID mid = env->GetMethodID(clas,"callback", "()V");
    env->CallVoidMethod(callback,mid);
}


JNIEnv *env;
JavaVM *vm_;
static jobject threadObject;
static jclass threadClazz;
static jmethodID threadMethod;

/**
 * env 不能跨线程，只能通过vm 获取
 * AttachCurrentThread 和 DetachCurrentThread 一定要配套使用
 * @return
 */
void *threadCallback(void *){
    JNIEnv *env = nullptr;
    if(vm_->AttachCurrentThread(&env, nullptr) == 0){
        env->CallVoidMethod(threadObject,threadMethod);
        vm_->DetachCurrentThread();
    }
    return 0;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_nativeThreadCallback(JNIEnv *env, jobject thiz,
                                                            jobject callback) {
    threadObject = env->NewGlobalRef(callback);
    threadClazz = env->GetObjectClass(callback);
    threadMethod = env->GetMethodID(threadClazz,"threadCallback", "()V");
    pthread_t handle;
    pthread_create(&handle, nullptr,threadCallback, nullptr);
}

JNIEXPORT int JNICALL JNI_OnLoad(JavaVM *vm, void *unused) {
    LOGD("JNI_OnLoad...");
    vm_ = vm;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    return JNI_VERSION_1_6;
}



extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_demondk2_JNIBasicType_invokeAnimalConstructors(JNIEnv *env, jobject thiz) {
    jclass cls = env->FindClass("com/example/demondk2/Person");
    jmethodID mid = env->GetMethodID(cls,"<init>", "(Ljava/lang/String;)V");
    jstring name = env->NewStringUTF("龙傲天的弟弟1");
    jobject  person = env->NewObject(cls,mid,name);
    return person;

}extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_demondk2_JNIBasicType_allocObjectConstructor(JNIEnv *env, jobject thiz) {
    jclass cls = env->FindClass("com/example/demondk2/Person");
    jmethodID mid = env->GetMethodID(cls,"<init>", "(Ljava/lang/String;)V");
    jstring name = env->NewStringUTF("龙傲天的弟弟2");
    jobject person = env->AllocObject(cls);
    env->CallNonvirtualVoidMethod(person,cls,mid,name);
    return person;
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_demondk2_JNIBasicType_errorCacheLocalReference(JNIEnv *env, jobject thiz) {
    jclass localRefs = env->FindClass("java/lang/String");
    jmethodID mid = env->GetMethodID(localRefs,"<init>","(Ljava/lang/String;)V");
    jstring str = env->NewStringUTF("string");

    for(int i=0;i<1000;i++){
        jclass localRefs = env->FindClass("java/lang/String");
        env->DeleteLocalRef(localRefs);
    }
    return static_cast<jstring>(env->NewObject(localRefs, mid, str));

}extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_demondk2_JNIBasicType_cacheWithGlobalReference(JNIEnv *env, jobject thiz) {
    static jclass stringClass = nullptr;
    if(stringClass == nullptr){
        jclass cls = env->FindClass("java/lang/String");
        stringClass = static_cast<jclass>(env->NewGlobalRef(cls));
        env->DeleteLocalRef(cls);
    }else{
        LOGD("use cached");
    }
    jmethodID mid = env->GetMethodID(stringClass,"<init>","(Ljava/lang/String;)V");
    jstring str = env->NewStringUTF("string");
    return static_cast<jstring>(env->NewObject(stringClass, mid, str));

}extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_demondk2_JNIBasicType_useWeakGlobalReference(JNIEnv *env, jobject thiz) {
    static jclass stringClass = nullptr;
    if(stringClass == nullptr){
        jclass cls = env->FindClass("java/lang/String");
        stringClass = static_cast<jclass>(env->NewWeakGlobalRef(cls));
        env->DeleteLocalRef(cls);
    }else{
        LOGD("use cached");
    }
    jmethodID mid = env->GetMethodID(stringClass,"<init>","(Ljava/lang/String;)V");
    jboolean  isGc = env->IsSameObject(stringClass, nullptr);
    if(isGc){
        return nullptr;
    }
    jstring str = env->NewStringUTF("string");
    return static_cast<jstring>(env->NewObject(stringClass, mid, str));


}extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_nativeThrowException(JNIEnv *env, jobject thiz) {
    jclass cls = env->FindClass("java/lang/IllegalArgumentException");
    env->ThrowNew(cls,"异常来自于 native");

}extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_nativeInvokeJavaException(JNIEnv *env, jobject thiz) {
    jclass cls = env->FindClass("com/example/demondk2/JNIBasicType");
    jmethodID mid = env->GetMethodID(cls,"operation", "()I");
    jmethodID mid2 = env->GetMethodID(cls,"<init>", "()V");
    jobject  obj = env->NewObject(cls,mid2);
    env->CallIntMethod(obj,mid);

    jthrowable exc = env->ExceptionOccurred();
    if(exc){
        //打印出异常
        env->ExceptionDescribe();
        //清除异常，使程序不会崩溃
        env->ExceptionClear();
    }
}

void *printThreadHello(void *){
    LOGD("hello new thread");
    //手动退出线程；
    pthread_exit(0);
//    return nullptr;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_createNativeThread(JNIEnv *env, jobject thiz) {
    pthread_t handle;
    int result = pthread_create(&handle, nullptr,printThreadHello, nullptr);
    if(result == 0){
        LOGD("create thread success");
    }else{
        LOGD("create thread failed");
    }
}

struct ThreadRunArgs{
    int id;
    int result;
};
void *printThreadArgs(void *arg){
    ThreadRunArgs *args = static_cast<ThreadRunArgs *>(arg);
    LOGD("thread is is %d  result is %d",args->id,args->result);
    //执行return后线程自动退出
    return nullptr;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_createNativeThreadWithArgs(JNIEnv *env, jobject thiz) {
    pthread_t handle;
    ThreadRunArgs *args = new ThreadRunArgs;
    args->id = 2;
    args->result = 100;
    int result = pthread_create(&handle, nullptr,printThreadArgs, args);
    if(result == 0){
        LOGD("create thread success");
    }else{
        LOGD("create thread failed");
    }
}

void *printThreadJoin(void *arg){
    ThreadRunArgs *args = static_cast<ThreadRunArgs *>(arg);
    struct timeval begin;
    gettimeofday(&begin, nullptr);
    sleep(3);
    struct timeval end;
    gettimeofday(&end, nullptr);
    LOGD("Time used id %d",end.tv_sec - begin.tv_sec);

    return reinterpret_cast<void *>(args->result);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_joinNativeThread(JNIEnv *env, jobject thiz) {
    pthread_t handle;
    ThreadRunArgs *args = new ThreadRunArgs;
    args->id = 3;
    args->result = 300;
    int result = pthread_create(&handle, nullptr,printThreadJoin, args);
    void *ret = nullptr;
    //这个函数阻塞当前线程直到子线程运行结束，并拿到线程返回值；
    pthread_join(handle,&ret);
    LOGD("result is %d",ret);
}




pthread_mutex_t mutex;
pthread_cond_t cond;
pthread_t  waitHandle;
pthread_t notifyHandle;

int flag = 0;
void *waitThrad(void *arg){
    LOGI("wait thread lock");
    //加锁
    pthread_mutex_lock(&mutex);
    while(flag ==0){
        LOGI("waiting");
        //线程等待挂起；
        pthread_cond_wait(&cond,&mutex);
    }
    LOGI("wait thread unlock");
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}
void *notifyThread(void *){
    LOGI("notify thread lock");
    pthread_mutex_lock(&mutex);
    flag = 1;
    pthread_mutex_unlock(&mutex);
    //唤醒线程
    pthread_cond_signal(&cond);
    LOGI("notify thread unlock");
    pthread_exit(0);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_waitNativeThread(JNIEnv *env, jobject thiz) {
    pthread_mutex_init(&mutex, nullptr);
    pthread_cond_init(&cond, nullptr);
    pthread_create(&waitHandle, nullptr,waitThrad, nullptr);


}extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_notifyNativeThread(JNIEnv *env, jobject thiz) {
    pthread_create(&notifyHandle, nullptr,notifyThread, nullptr);
}


using namespace std;
std::queue<int> data;
pthread_mutex_t dataMutex;
pthread_cond_t dataCond;
void *productThrad(void *arg){

    while(data.size()<10){
        pthread_mutex_lock(&dataMutex);
        LOGD("生产物品");
        data.push(1);
        if(data.size()>0){
            LOGD("等待消费");
            pthread_cond_signal(&dataCond);
        }
        pthread_mutex_unlock(&dataMutex);
        sleep(3);
    }
    pthread_exit(0);
}
void *consumerThrad(void *arg){
    while (1){
        pthread_mutex_lock(&dataMutex);
        if(data.size()>0){
            LOGI("消费物品");
            data.pop();
        }else{
            LOGI("等待生产");
            pthread_cond_wait(&dataCond,&dataMutex);
        }
        pthread_mutex_unlock(&dataMutex);
        sleep(1);
    }
    pthread_exit(0);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_demondk2_JNIBasicType_startProductAndConsumerThread(JNIEnv *env, jobject thiz) {

    pthread_mutex_init(&dataMutex, nullptr);
    pthread_cond_init(&dataCond, nullptr);
    pthread_t productHandle;
    pthread_t consumerHandle;
    pthread_create(&productHandle, nullptr,productThrad, nullptr);
    pthread_create(&consumerHandle, nullptr,consumerThrad, nullptr);
}



/**
 * 创建bitmap
 * @param env
 * @param width
 * @param height
 * @return
 */
jobject generateBitmap(JNIEnv *env,uint32_t width,uint32_t height){
    jclass bitmapClass = env->FindClass("android/graphics/Bitmap");
    jmethodID createBitmapMethodID = env->GetStaticMethodID(bitmapClass,"createBitmap", "(IILandroid/graphics/Bitmap$Config;)Landroid/graphics/Bitmap;");
    jstring configName = env->NewStringUTF("ARGB_8888");
    jclass bitmapConfigClass = env->FindClass("android/graphics/Bitmap$Config");
    jmethodID valueOfBitmapConfigFunction = env->GetStaticMethodID(bitmapConfigClass, "valueOf",
                                                                   "(Ljava/lang/String;)Landroid/graphics/Bitmap$Config;");
    jobject bitmapConfig = env->CallStaticObjectMethod(bitmapConfigClass, valueOfBitmapConfigFunction, configName);
    jobject newBitmap = env->CallStaticObjectMethod(bitmapClass, createBitmapMethodID, width, height, bitmapConfig);
    return newBitmap;
}
extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_demondk2_JNIBasicType_callNativeMirrorBitmap(JNIEnv *env, jobject thiz,
                                                              jobject bitmap) {

    AndroidBitmapInfo bitmapInfo;
    AndroidBitmap_getInfo(env,bitmap,&bitmapInfo);

    LOGD("width is %d",bitmapInfo.width);
    LOGD("height is %d",bitmapInfo.height);

    void *bitmapPixels;
    AndroidBitmap_lockPixels(env,bitmap,&bitmapPixels);
    uint32_t newWidth = bitmapInfo.width;
    uint32_t newHeight = bitmapInfo.height;
    uint32_t *newBitmapPixels = new uint32_t[newWidth * newHeight];
    int whereToGet = 0;
    for(int y=0;y<newHeight;++y){
        for(int x=newWidth-1;x>=0;x--){
            uint32_t pixel = ((uint32_t *)bitmapPixels)[whereToGet++];
            newBitmapPixels[newWidth*y+x] = pixel;
        }
    }
    AndroidBitmap_unlockPixels(env,bitmap);

    jobject newBitmap = generateBitmap(env,newHeight,newWidth);
    void *resultBitmapPixels;
    AndroidBitmap_lockPixels(env,newBitmap,&resultBitmapPixels);
    memcpy(resultBitmapPixels,newBitmapPixels,sizeof(uint32_t)*newWidth * newHeight);
    AndroidBitmap_unlockPixels(env,newBitmap);

    delete [] newBitmapPixels;
    return newBitmap;
}