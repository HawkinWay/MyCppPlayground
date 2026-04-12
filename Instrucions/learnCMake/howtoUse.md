# How to use

## 1
```bash
cmake -S . -B cmake-build
```

> '-S' means Source, it tells CMake where to find the most important file "CMakeLists.txt"  
> '.' means current directory  
> '-B' means Build  
> '-B cmake-build' means put compiled files into a folder called 'cmake-build'. If the folder doesn't exist, CMake will build itself.  

---

## 2

```bash
cd cmake-build
make
./binaryFileName
```

> In 'cmake-build/' you'll see 'Makefile', use *make* to find it and run it  
> binaryFileName is written in 'CMakeLists.txt', at the line of 'project(binaryFileName)'

### find help

```bash
make help
```
