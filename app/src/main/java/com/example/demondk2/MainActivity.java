package com.example.demondk2;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.demondk2.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());

        JNIDynamicLoad jniDynamicLoad = new JNIDynamicLoad();
        JNIBasicType jnibasictype = new JNIBasicType();

        String[] strings = {"apple","pear","banana"};
        Person person = new Person("龙傲天");

        Bitmap bitmap = BitmapFactory.decodeResource(getResources(),R.mipmap.ic_launcher);
        tv.setOnClickListener(v -> {
            String nativeString = jniDynamicLoad.getNativeString();
            Log.d("MainActivity",nativeString+"");

            int i = jnibasictype.callNativeInt(10);
            Log.d("MainActivity",i+"");

            String str = jnibasictype.callNativeString("我来自java");
            Log.d("MainActivity",str+"");

            jnibasictype.handleStringArray(strings);

            jnibasictype.accessInstanceField(person);
            jnibasictype.accessStaticField(person);
            Log.d("MainActivity",person.toString()+"");
            jnibasictype.accessInstanceMethod(person);
            jnibasictype.accessStaticMethod(person);

            jnibasictype.nativeCallback(() -> {
                Log.d("MainActivity","nativeCallback thread name is "+Thread.currentThread().getName());
            });
            jnibasictype.nativeThreadCallback(() -> {
                Log.d("MainActivity","thread name is "+Thread.currentThread().getName());
            });

            Log.d("MainActivity","name is "+jnibasictype.invokeAnimalConstructors().name);
            Log.d("MainActivity","name is "+jnibasictype.allocObjectConstructor().name);

            jnibasictype.errorCacheLocalReference();
            jnibasictype.useWeakGlobalReference();
            jnibasictype.cacheWithGlobalReference();

            jnibasictype.nativeInvokeJavaException();
            try{
                jnibasictype.nativeThrowException();
            }catch (Exception e){
                e.printStackTrace();
            }

            jnibasictype.createNativeThread();
            jnibasictype.createNativeThreadWithArgs();
            jnibasictype.joinNativeThread();
            jnibasictype.startProductAndConsumerThread();

        });

        binding.image.setOnClickListener(v -> {
            Bitmap b = jnibasictype.callNativeMirrorBitmap(bitmap);
            binding.image.setImageBitmap(b);
        });
        binding.tvThreadWait.setOnClickListener(v -> jnibasictype.waitNativeThread());
        binding.tvThreadNotify.setOnClickListener(v -> jnibasictype.notifyNativeThread());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native int getTotal();
}