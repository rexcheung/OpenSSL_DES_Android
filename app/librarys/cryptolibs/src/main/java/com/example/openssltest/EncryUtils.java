package com.example.openssltest;

import android.util.Base64;
import android.util.Log;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Objects;

/**
 * 加密的工具类。
 * Created by zxbin on 16-10-13.
 */
public class EncryUtils {

    private final Object sync=new Object();

    static {
        System.loadLibrary("openssl-jni");
    }

    public native byte[] encryJNI(String msg, String key);

    public native byte[] decryptJNI(byte[] msg, String key);

    public native String test(String msg, String key);


    public String decryptFromBase64(String msg, String key) {
        byte[] bytesrc = Base64.decode(msg, 0);
        String result = new String(decryptJNI(bytesrc, key));
        return result;
    }

    public String encryToBase64(String msg, String key){
        byte[] encryText = encryJNI(msg, key);
        return Base64.encodeToString(encryText, 0);
    }
}
