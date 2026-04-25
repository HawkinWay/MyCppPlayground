# Memory Layout (RAM)

32-bit OS
<img width="360" height="600" alt="32-bit OS Memory Layout" src="https://github.com/user-attachments/assets/0e4c0829-91a1-48ff-90e7-f2bc4364cbbd" />

Segments profixed with '.' (or in macOS '__')  indicate that they have identified the named section in the executable file in compiling and linking time(build time).  
Compiler will release this fixed-size memory space automatically.

## 1. Code Section(.text)
*can also be called Text Section* 

- Store Machine Code
- Fixed Size
- Read-only



## 2. Static Section

### 2.1 Read-only Data(.rodata)

> stores initialized read-only **constant**

### 2.2 Data(.data)

> stores initialized non-zero global variable

### 2.3 BSS(.bss)

> reserve space for global **uninitialized** or global variable with a value of 0



## 3. Dynamic Section

### 3.1 Heap

> growing from low address to high address

- Dynamic Allocation
- Large/flexible Size
- Manual Management(new/delete malloc/free)
- *Risk of Memory Leaks*

### 3.2 Stack

> growing from high address to low address

- Automatic management
- Stores locals & function calls
- LIFO
- Fast allocation
- Limited size
