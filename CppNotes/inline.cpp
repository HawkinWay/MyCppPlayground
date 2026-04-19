// C++17 have inline variables, before C++17, such variables required a separate definition in a single source file to avoid linker erros.

// The benefits of inline functions
// Using inline functions can make your program faster because they eliminate the overhead associated with function calls
// Calling a function requires pushing the return address on the stack, pushing arguments onto the stack, jumping to the function body, and then executing a return instruction when the function finishes

// One Definition Rule(ODR) 单一定义原则
// Normally, a function can be declared multiple times but only be defined once across all translation units
// When a function is marked inline, it can be defined in multiple translation units(typically via a header file) if all the definitions are identical.
// The linker then selects one definition and discards the duplicates rather than reporting an error
// The ODR aspect is a practical necessity where the same header(containing an inline function definition) may be included in multiple source files

// Implicitly inline functions
// 1. functions defined at class scope are implicitly inline
// 2. constexpr functions are implicitly inline. Because they are typically defined in header files to allow compile-time evaluation,
// they must follow the same ODR rules as inline functions.
// 3. consteval functions are implicitly inline

// The following 4 member-functions are all inline functions

// account.h
class Account{
    public:
    Account(double initial_balance){
        balance = initial_balance;
    }
    
    double GetBalance() const{
        return balance;
    }
    inline double Deposit(double amount){
        balance += amount;
        return balance;
    }
    inline double WithDraw(double amount);
    private:
    double balance;
};

inline double Account::WithDraw(double amount){
    balance -= amount;
    return balance;
}


// When to use inline functions
// they are best used for small functions.
// Short functions are sensitive to the overhead of function calls
// Longer functions spend proportionately less time in the calling and returning sequence, so they benefit less from inlining
// The definition of inline function must in .h

class Point{
private:
    unsigned _x, _y;
public:
    unsigned& x();
    unsigned& y();
};

inline unsigned& Point::x(){
    return _x;
}

inline unsigned& Point::y(){
    return _y;
}


// When a function is declared as inline,the compiler attempts to "embed" the function's code directly into every place that calls it,
// rather than accessing it through address jumps
// inline typically saves the overhead on:
// function calls; preservation of caller's stack frame; new stack frame setup;
// ruturn-value communication; restoring the old stack frame; return

// # Stack Frame
// when your program calls a function, system will allocate a temporary space in stack area of memory, this space is stack frame
// stack frame stores local variables, arguments, return addresses and register backup
