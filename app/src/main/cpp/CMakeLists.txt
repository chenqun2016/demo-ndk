# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.6.0)

# Declares and names the project.

project("demondk2")


# 设置变量  vasss
set(vasss hell0009o)
# 引用变量 vasss

message(${vasss})
# CMAKE_CURRENT_LIST_DIR:当前cmake目录路径 ：D:/workspace/demo/demondk2/app/src/main/cpp
message(${CMAKE_CURRENT_LIST_DIR})
# CMAKE_CURRENT_LIST_FILE：当前cmake文件路径 :D:/workspace/demo/demondk2/app/src/main/cpp/CMakeLists.txt
message(${CMAKE_CURRENT_LIST_FILE})

IF(TRUE)

ENDIF()
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

# 将 .cpp文件编译成 native-lib 动态库的语法
add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp )

add_library(
        people-lib
        SHARED
        People/People.cpp )

add_library(
        dynamic-lib
        SHARED
        jni/jni_dynamic_load.cpp
)
# 把 People/ 放到搜索路径中去，引用的时候直接 #include <People.h> 而不是 #include "People/People.h"
include_directories(People/)
include_directories(jni/)
include_directories(${CMAKE_SOURCE_DIR}/base/)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# 查找 android 系统中的 log库，并命名成 log-lib
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

# 将动态库进行关联
target_link_libraries( # Specifies the target library.
                       native-lib
                       people-lib
                       dynamic-lib
                       jnigraphics

        # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )