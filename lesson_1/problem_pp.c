#include <stdio.h>
#include <stdlib.h>

unsigned long long fib_mod(int n, int m)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    unsigned long long first = 0, second = 1, temp;
    for (int i = 2; i <= n; ++i)
    {
        temp = (first + second) % m; // берем остаток на каждом шаге
        first = second;
        second = temp;
    }
    return second;
}

int get_pizano(unsigned long long n)
{
    int first = 0, second = 1, temp, i;
    for (i = 1;; ++i)
    {
        temp = (first + second) % n;
        first = second;
        second = temp;
        
        if (first == 0 && second == 1)
            return i;
    }
}

int main()
{
    unsigned long long n, m;
    if (scanf("%llu%llu", &n, &m) != 2)
        abort();

    int pizano = get_pizano(m);
    printf("%llu %d\n", fib_mod(n % pizano, m), pizano);
}

