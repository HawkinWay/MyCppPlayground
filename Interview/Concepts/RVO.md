# RVO (Return Value Optimization)

A compiler optimization technique that allows the compiler to construct the return value of a function at the call site. The technique is also named "elision". C++98/03 standard doesn't require the compiler to provide RVO optimization, but most popular C++ compilers contain this optimization technique. This technique is included in the C++11 standard due to prevalence. As defined in Section 12.8 in the C++11 standard, the name of the technique is "copy elision".

Define a  class named BigObject, imagine its size could be so large that copying it would have high cost.

```cpp
class BigObject{
public:
    BigObject(){
        std::cout << "constructor." << '\n';
    }

    ~BigObject(){
        std::cout << "destructor." << '\n';
    }

    BigObject(const BigObject&){
        std::cout << "copy constructor." << '\n';
    }
};
```

We then define one function named foo to trigger the RVO optimization and use it in the main function to see what will happen.

```cpp
BigObject foo(){
    BigObject localObj;
    return localObj;    // NRVO(named return value optimization), needs to satisfy the requirement that all return paths return the same local object and that there is no complex control flow
}

int main(){
    BigObject obj = foo();
}
```

Compile and execute, the output:

```txt
constructor.
destructor.     // destructor from main() obj
```

Yeah, there's no copy constructor here. **When the cost of copying is high, RVO enables us to run the program much faster.**

However, when we modify a little, things will change:

```Cpp
BigObject foo(int n){
    BigObject localObj, anotherLocalObj;
    if(n > 2){
        return localObj;
    }else{
        return anotherLocalObj;
    }
}

int main(){
    BigObject obj = foo(1);
}
```

The output:

```txt
constructor.
constructor.
copy constructor.
destructor.
destructor.
destructor.
```

