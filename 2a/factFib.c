int fact(int n)
{
    if(n==0) return 1;
    int fact=1;
    for(int i=1; i<=n; ++i)
        fact *= i;
    return fact;
}

int fib(int n)
{ 
    if(n==0) return 0;
    if(n==1) return 1;
    int f0=0, f1=1;
    for(int i=2; i<=n; ++i){
        int temp = f0;
        f0 = f1;
        f1 += temp;
    }
    return f1;
}
