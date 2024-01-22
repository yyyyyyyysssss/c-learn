# cmake最低版本要求
cmake_minimum_required(VERSION 3.25.1)

# 设置项目名称环境变量
set(PROJECT_NAME learn)

project(${PROJECT_NAME})

# 查到当前目录下的所有源文件并存入DIR_SRCS变量
# aux_source_directory(src DIR_SRCS)

# 递归遍历所有c文件和h文件并存入SOURCES变量中
file (GLOB_RECURSE SOURCES src/*.c include/*.h)

add_executable(${PROJECT_NAME} ${SOURCES})

# 添加动态链接库
target_link_libraries(${PROJECT_NAME} m)

add_definitions("-Wall -g")

