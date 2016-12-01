package zxb.openssl_des_android;

import android.graphics.Color;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.example.openssltest.Des;
import com.example.openssltest.EncryUtils;

public class MainActivity extends BaseActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final EditText etKey = inject(R.id.key);
        final EditText etMsg = inject(R.id.msg);
        final TextView tvEncCom = inject(R.id.enc_com);
        final TextView tvDecCom = inject(R.id.dec_com);
        final TextView tvNativeEncrypt = inject(R.id.native_encrypt);
        final TextView tvNativeDecrypt = inject(R.id.native_decrypt);
        final TextView tvJavaEncrypt = inject(R.id.java_encry);
        final TextView tvJavaDecrypt = inject(R.id.java_decrypt);

        final EncryUtils encryUtils = new EncryUtils();
        inject(R.id.action).setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                String key = etKey.getText().toString();
                String msg = etMsg.getText().toString();

                if (TextUtils.isEmpty(key) || TextUtils.isEmpty(msg)) {
                    Toast.makeText(MainActivity.this, "key or msg can't be empty.", Toast.LENGTH_SHORT).show();
                    return;
                }

                if (key.length() != 8) {
                    Toast.makeText(MainActivity.this, "Key length must 8.", Toast.LENGTH_SHORT).show();
                    return;
                }

                // 加密
                String nativeEncryptMsg = encryUtils.encryToBase64(msg, key);

                String javaEncryptMsg = null;
                try {
                    javaEncryptMsg = Des.encrypt(msg, key);
                } catch (Exception e) {
                    e.printStackTrace();
                }

                boolean encCom = javaEncryptMsg.equals(nativeEncryptMsg);
                if (encCom) {
                    tvEncCom.setTextColor(Color.BLUE);
                } else {
                    tvEncCom.setTextColor(Color.RED);
                }


                tvEncCom.setText(String.valueOf(encCom));
                tvNativeEncrypt.setText(nativeEncryptMsg);
                tvJavaEncrypt.setText(javaEncryptMsg);


                // 解密
                String nativeDecryptMsg = encryUtils.decryptFromBase64(nativeEncryptMsg, key);
                String javaDecryptMsg="";
                try {
                    javaDecryptMsg = Des.decrypt(javaEncryptMsg, key);
                } catch (Exception e) {
                    e.printStackTrace();
                }

                boolean decCom = javaDecryptMsg.equals(nativeDecryptMsg);
                if (decCom) {
                    tvDecCom.setTextColor(Color.BLUE);
                } else {
                    tvDecCom.setTextColor(Color.RED);
                }
                tvDecCom.setText(String.valueOf(decCom));
                tvNativeDecrypt.setText(nativeDecryptMsg);
                tvJavaDecrypt.setText(javaDecryptMsg);
            }
        });
    }
}
