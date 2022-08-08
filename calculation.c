#include "rsa.h"

unsigned long long int power_modulo(unsigned long long int n,unsigned long long int p, unsigned long long int m)
{
    __int128_t b,tmp;

    b = n;
    tmp = 1;
    while(p != 0)
    {
        if (p % 2 == 1)
                tmp = (tmp * b) % m;
        b = (b * b) % m;
        p = p / 2;
    }
    return ((unsigned long long int) tmp);
}

unsigned int power(unsigned int n, unsigned int p)
{
    unsigned int i = 0;
    int tmp = 1;
    while(i < p)
    {
        tmp *= n;
        i++;
    }
    return (tmp);
}

unsigned long long int euclide_etendu(unsigned long long int a,unsigned long long int b, long long int *u,long long int *v)
 { 
    long long int tmp1,q,x,xx,y,yy;
    unsigned long long int tmp2;
    x = 1;
    xx = 0;
    y = 0;
    yy = 1;
    while(b != 0)
    { 
        q = a / b;
        tmp2 = a;
        a = b;
        b = tmp2 % b;
        tmp1 = xx;
        xx = x - q * xx;
        x = tmp1;
        tmp1 = yy;
        yy = y - q * yy;
        y = tmp1;
    }
    *u = x;
    *v = y;
    return (a);
}

int     ft_is_prime(unsigned long long int nb)
{
        unsigned int  i;

        i = 2;
        if (nb < 2 || nb % 2 == 0)
                return (0);
        else
        {
                while (i <= (nb / i))
                {
                        if (nb % i == 0)
                                return (0);
                        i++;
                }
                return (1);
        }
}

unsigned long long  int  prime(void)
{
    unsigned long long int number;
    while(1)
    {
        srand(time(NULL));
        number = rand() % 99999;
        if (ft_is_prime(number))
            break;
    }
    return(number);
}