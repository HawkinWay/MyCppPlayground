# Principles

## 1. Compilation

> The compiler(g++/clang etc.) reads your ".cpp" file,
> checks for syntax errors,
> and translates it into binary instructions that the computer can understand.

triggered by "tasks.json"

```bash
g++ -c fileName.cpp -o virtual.o
```

> -c means compile
> .o is Object file

---

## 2. Linking

> Your code might call functions from standard libraries(like std::cout) or other files.
> The linker's job is to stitch your ".o" files and system library files together into a complete executable file.

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

``bash
./fileName
```
