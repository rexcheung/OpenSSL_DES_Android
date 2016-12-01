package com.example.openssltest;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_jni_debug);

        final EditText etText = (EditText) findViewById(R.id.et_text);
        final EditText etKey = (EditText) findViewById(R.id.et_key);

        final TextView tv_text = (TextView) findViewById(R.id.text);
        final TextView tv_encryText = (TextView) findViewById(R.id.encryText);

        final TextView javaencryText = (TextView) findViewById(R.id.javaencryText);

        final TextView decryptText = (TextView) findViewById(R.id.decryptText);

        Button textBtn = (Button) findViewById(R.id.btn_encry);
        textBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                final String textString = etText.getText().toString();
                final String keyString = etKey.getText().toString();
                tv_text.setText(textString);

                new AsyncTask<Void, Void, String>() {
                    @Override
                    protected String doInBackground(Void... params) {
                        String base64 = new EncryUtils().encryToBase64(textString, keyString);
                        return base64;
                    }

                    @Override
                    protected void onPostExecute(String s) {
                        super.onPostExecute(s);
                        tv_encryText.setText(s);

                        String s1 = new EncryUtils().decryptFromBase64(s, keyString);
                        decryptText.setText(s1);
                    }
                }.execute();


                new AsyncTask<Void, Void, String>() {
                    @Override
                    protected String doInBackground(Void... params) {
                        String base64Text = null;
                        try {
//                            byte[] encrypt = Des.encrypt(textString, keyString);
//                            logbytes("j encrypt",encrypt);
                            base64Text = Des.encrypt(textString, keyString);
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        return base64Text;
                    }

                    @Override
                    protected void onPostExecute(String s) {
                        super.onPostExecute(s);

                        if (!TextUtils.isEmpty(s)) {
                            javaencryText.setText(s);
                        }
                    }
                }.execute();
            }
        });
    }

    private void logbytes(String tab, byte[] encrypt) {
        StringBuilder sb = new StringBuilder();
        for (byte b : encrypt) {
            sb.append(Integer.toHexString(b & 0xff)+",");
        }
        sb.deleteCharAt(sb.length()-1);
        Log.e(tab, sb.toString());
    }
}
