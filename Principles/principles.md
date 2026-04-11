# Principles

<img width="1378" height="765" alt="translation_unit" src="https://github.com/user-attachments/assets/63a507c8-5b77-42cb-9ade-e5b7d1120d55" />


## 1. Compilation

> The compiler(g++/clang etc.) reads your ".cpp" file,
> checks for syntax errors,
> and translates it into **machine code**(stored in an **object file**) that the computer can understand.

triggered by "tasks.json"

```bash
g++ -c fileName.cpp -o virtual.o
```

> '-c' means compile, tells the compiler to *skip* the linking stage and produce an **Object file**
> '-o' means output
> '.o' is Object file

---

## 2. Linking

> Your code might call functions from standard libraries(like std::cout) or other files.
> The linker's job is to stitch your ".o" files and **pre-compiled system libraries** files together into a complete executable file.

triggered by "tasks.json"

```bash
g++ fileName.o -o fileName
```

> after this step, you'll get a executable file

---

## 3.Execution

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
