cmake_minimum_required(VERSION 3.10)
# 项目名，语言C
project(c_classic_100 C)

# 设置C99标准，支持循环内定义变量
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 注册头文件目录，代码中 #include "problems.h" 可直接识别
include_directories(include)

# 根目录的主入口文件（固定不变）
set(MAIN_FILE main.c)
# 自动扫描 src 下所有 .c 题目文件，新增题目无需修改此处
file(GLOB PROBLEM_SOURCES CONFIGURE_DEPENDS "src/*.c")
# 合并所有源码
set(SOURCES ${MAIN_FILE} ${PROBLEM_SOURCES})

# 生成控制台可执行程序
add_executable(c_100 ${SOURCES})
# 关键：标记为控制台程序，杜绝 undefined reference to WinMain 报错
set_target_properties(c_100 PROPERTIES WIN32_EXECUTABLE OFF)
