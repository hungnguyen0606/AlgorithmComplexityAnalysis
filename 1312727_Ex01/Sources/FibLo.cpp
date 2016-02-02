int fibonacci(int n, int& C, int& A)
{
    C = 0; 
    A = 0;

    
    if (++C && n <= 1) 
        return 1;

    int last = 1;           ++A;
    int nextToLast = 1;     ++A;
    int answer = 1;         ++A;

     ++A; //phep gan i = 2
    for(int i = 2 ; ++C && i <= n; ++i, ++A)  
    {
        answer = last + nextToLast;     ++A;
        nextToLast = last;              ++A;
        last = answer;                  ++A;
    }
    
    return answer;
}