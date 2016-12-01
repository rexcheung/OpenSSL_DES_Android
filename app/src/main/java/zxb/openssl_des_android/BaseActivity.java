package zxb.openssl_des_android;

import android.support.v7.app.AppCompatActivity;
import android.view.View;

/**
 * Created by zxbin on 16-12-1.
 */

public class BaseActivity extends AppCompatActivity {

    protected <T extends View> T inject(int viewId){
        //noinspection unchecked
        return (T)findViewById(viewId);
    }
}
