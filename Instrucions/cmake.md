# cmake instructions

## 指定要生成的可执行文件和其源文件

add_executable(<target> <source_files>...)

```CMakeLists
add_executable(execuName main.cpp otherFile.cpp)
```

---

## 创建一个库（静态库或动态库）及其源文件

add_library(<target> <source_files>...)

```CMakeLists
add_library(libName STATIC lib.cpp)
```

---

## 链接目标文件与其他库

target_link_libraries(<target> <libraries>...)

```CMakeLists
target_link_libraries(execuName libName)
```

---

## 添加头文件搜索路径

include_directories(<dirs>...)

```CMakeLists
include_directories(${PROJECT_SOURCE_DIR}/include)
```

---

## 设置变量的值

set(<variable> <value>...)

```CMakeLists
set(CMAKE_CXX_STANDARD 11)
```

---

## 设置目标属性

target_include_directories(TARGET target_name
                           [BEFORE | AFTER]
                           [SYSTEM] [PUBLIC | PRIVATE | INTERFACE]
                           [items1...])

```CMakeLists
target_include_directories(execuName PRIVATE ${PROJECT_SOURCE_DIR}/include)
```

---

## 安装规则

install(TARGETS target1 [target2 ...]
        [RUNTIME DESTINATION dir]
        [LIBRARY DESTINATION dir]
        [ARCHIVE DESTINATION dir]
        [INCLUDES DESTINATION [dir ...]]
        [PRIVATE_HEADER DESTINATION dir]
        [PUBLIC_HEADER DESTINATION dir])

```CMakeLists
install(TARGETS execuName RUNTIME DESTINATION bin)
```
