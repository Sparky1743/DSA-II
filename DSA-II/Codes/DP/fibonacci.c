# include <stdio.h>

// int fibonacci(int n);

// int fibonacci(int n){ // Not an optimal way, time taken = 2^O(n).
//     if (n == 1){
//         return n;
//     }
//     if (n == 0){
//         return n;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// };


int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    // printf("%d", fibonacci(n));
    int fib[n];
    fib[0] = 1, fib[1] = 1;
    for (int i = 2; i < n; i ++ ){
        fib[i] = fib[i - 1] + fib[i - 2];
    };
    printf("%d", fib[n - 1]);
}


