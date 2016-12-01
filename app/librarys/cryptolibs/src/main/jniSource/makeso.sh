~/apps/android/ndk/./ndk-build NDK_PROJECT_PATH=./

 rm -fr ../jniLibs/*
 mv libs/* ../jniLibs/
 rm -fr libs/
 rm -fr obj/
