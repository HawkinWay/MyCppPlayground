// 栈：函数、局部变量、形参
// 堆：new/delete malloc/free
// .bss: 全局未初始化/默认值变量
// .data: 全局已初始化变量
// .rodata: 只读的常量
// .text: 机器码

// Linux (ELF): 指令在 .text，常量在 .rodata。
// macOS (Mach-O): 指令在 __TEXT,__text，常量在 __TEXT,__const。


int a1;               // [__common]   BSS	4B (未初始化全局)
int a2 = 0;           // [__common]   BSS	4B (macOS 默认将初始化为0的全局变量也归入common)
int a3 = 1;           // [__data]     DATA	4B (非零初始化全局)

static int b1;        // [__bss]      BSS	4B (未初始化静态全局)
static int b2 = 0;    // [__bss]      BSS	4B (初始化为0的静态全局)
static int b3 = 1;    // [__data]     DATA	4B (非零初始化静态全局)

//c1 = 0 和 c2 = 1 是简单的 int 类型。在 ARM64 架构下，编译器通常会进行优化。
//__TEXT 段是只读的。为了节省内存页和提高安全性，macOS 将代码（指令）和只读数据（常量）都放在 __TEXT 这个大分类下。
const int c1 = 0;     // [__text段内]  TEXT	 4B (全局只读常量)
const int c2 = 1;     // [__text段内]  TEXT	 4B (全局只读常量)

int main(){
    int A1;           // [Stack]      STACK	 4B (运行时栈分配，不占二进制Section)
    int A2 = 0;       // [Stack]      STACK	 4B (运行时栈分配，指令赋值)
    int A3 = 1;       // [Stack]      STACK  4B (运行时栈分配)

    static int B1;    // [__bss]       BSS	  4B (未初始化静态局部，生存期等同全局)
    static int B2 = 0;// [__bss]       BSS	  4B (初始化为0的静态局部)
    static int B3 = 1;// [已优化/隐藏] 	        4B (通常进__data，但若未引用可能被优化)

    const int C1 = 0; // [Stack/Imm]  STACK	  4B (局部常量，通常直接优化为指令里的立即数)
    const int C2 = 1; // [Stack/Imm]  STACK	  4B (同上)
}