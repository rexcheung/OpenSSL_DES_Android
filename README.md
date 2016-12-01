# OpenSSL_DES_Android
#### 基于OpenSSL, 在Android实现DES加密   
* 加密方式：DES/CBC/PKCS5Padding    

* OpenSSL默认的补位不是PKCS5Padding格式，这个部分需要自己实现。

* 加密及解密的主要逻辑在logic/des_logic.c这个类里面。

#### 使用方法，直接调用即可:
* 加密 EncryUtils.decryptFromBase64(msg, key);
* 解密 EncryUtils.encryToBase64(msg, key);

#### 关于so:
* C代码编译的命令已经写成了脚本， main/jniSource/makeso.sh，修改里面的第一行的NDK路径即可
* 依赖库OpenSSL的so文件已经生成好，放在jniLibs下面: 包含了主流的arm架构文件，但没有x86结构的，因为不常用，生成OpenSSL for Android的so库可以参考文章底部的链接。


##### 依赖及参考项目：
[OpenSSL](https://www.openssl.org/)     
[OpenSSL Android 编译](https://wiki.openssl.org/index.php/Android)  
[Openssl Android 编译示例](http://blog.csdn.net/bupt073114/article/details/44565965)
