int fib(int n, int& C, int &A)
{
    
    if (++C && n <= 1)
        return 1;
    return fib(n-1, C, A)+fib(n-2,C,A);
}