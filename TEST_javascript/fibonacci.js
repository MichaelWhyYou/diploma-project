// Time complexity = O(n), Space complexity = O(1). Multi-variable loop with simple addition, IGNORE THIS CODE
function Fibonacci(n) {
    let a = BigInt(0), b = BigInt(1), temp = BigInt(0);
    for (let i = 0; i < n; i++) {
        temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}
    
Fibonacci(1000000);