# Principles

<img width="1378" height="765" alt="translation_unit" src="https://github.com/user-attachments/assets/63a507c8-5b77-42cb-9ade-e5b7d1120d55" />

## 1. Processing    预处理

> A processor processes all instructions that begin with ‘#’  
> For 'main.cpp': When it sees #include "mylib.h", it will directly copy and paste the entire contents of "mylib.h" into the header of main.cpp  
> The expanded code is called a **translation unit**
> If you have two '.cpp' files, the compiler will see two independent compilation units. At this step, they are completely unaware of each other's existence

---

## 2. Compilation   编译

> The compiler(g++/clang++/MSVC etc.) reads your ".cpp" file,
> checks for syntax errors,
> and translates it into **machine code**(stored in an **object file**) that the computer can understand.  
> *constexpr* function should be calculated in this stage

triggered by "tasks.json"

```bash
g++ -c fileName.cpp -o virtual.o
```

> '-c' means compile, tells the compiler to *skip* the linking stage and produce an **Object file**  
> '-o' means output  
> '.o' is Object file  

---

## 3. Linking   链接

> Your code might call functions from standard libraries(like std::cout) or other files.
> The linker's job is to stitch your ".o" files and **pre-compiled system libraries** files together into a complete executable file.

triggered by "tasks.json"

```bash
g++ fileName.o -o fileName
```

> after this step, you'll get a executable file

---

## 4.Execution  运行

> The operating system(OS) loads executable file from the hard drive into memory,
> allocates CPU resources, and begins executing instructions line by line.

triggered by "launch.json"(GDB)

```bash
./fileName
```

## *Compile directly into an executable file*

```bash
g++ fileName.cpp -o fileName
./fileName
```
