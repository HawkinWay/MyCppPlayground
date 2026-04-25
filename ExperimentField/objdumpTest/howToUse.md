## 1. Compile 编译

```zsh
clang++ test.cpp -o test
```

## 2. Section Headers 查看段头部
*查看段段大小、在内存中的虚拟地址(VMA)、在文件中的偏移量以及对齐方式*

```zsh
objdump -h test
```

- Size: 该段的大小
- VMA/LMA: 虚拟内存地址/加在内存地址
- File off: 在二进制文件中的位置

## 3. Disassemble 反汇编
*查看可执行指令的内容*


```zsh
objdump -d test
```
