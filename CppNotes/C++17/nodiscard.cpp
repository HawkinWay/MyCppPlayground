// [[nodiscard]], mark a class or the return value of a function SHOULD NOT be discarded
// If it is discarded, the compiler will give a warning
// This is just a warning, not a error

[[nodiscard]] int add(int a, int b){
    return a + b;
}

int main(){
    add(1, 2);  // warning: discard the return value
    int res = add(1, 2);  // OK
    (void)add(1, 2);    // OK, explicit discard the return value
}