cmake_minimum_required(VERSION 3.10)
# 项目名，语言C
project(c_classic_100 C)

# 设置C99标准，支持循环内定义变量
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 注册头文件目录，代码中 #include "problems.h" 可直接识别
include_directories(include)

# 收集所有源码：
# 1. 根目录的main.c（唯一入口）
# 2. src文件夹下所有题目 .c 文件
set(SOURCES
    main.c
    src/problem_001.c
    src/problem_002.c
    src/problem_003.c
)

# 生成控制台可执行程序
add_executable(c_100 ${SOURCES}
    src/problem_003.c)
# 关键：标记为控制台程序，杜绝 undefined reference to WinMain 报错
set_target_properties(c_100 PROPERTIES WIN32_EXECUTABLE OFF)