#include <stdio.h>


void print_converted(unsigned n, unsigned base)
{
        unsigned int result[32] = {0};
        int i = 0;        
		while(n != 0)
        {
                result[i] = n % base;
                n /= base;
                i++;
        }
        --i;
        for(int j = i; j >= 0; --j)
        {
                 printf("%d", result[j]);
        }

}



int main()
{
        unsigned x,y;

        scanf("%d%d", &x,&y);

        print_converted(x,y);

        return 0;
}
                              
