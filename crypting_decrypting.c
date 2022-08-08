#include "rsa.h"

unsigned int size_bytes(unsigned long long int a)
{
    int i = 64;
    while(a != 0)
    {
        a /= 2;
        i--;
    }
    return (8 - i / 8);
}

unsigned long long int    value_of_size_n(unsigned char c, int j)
{
    int i = j * 8;
    unsigned long long int tmp = 0;
    while(c)
    {
        if (c % 2 == 1)
            tmp = tmp + power(2, i);
        c /= 2;
        i++;
    }
    return (tmp);
}

void    new_to_message(unsigned long long int new, unsigned char *mes_c, unsigned int index)
{
    unsigned char c;
    unsigned int i = 0;
    unsigned int j = 0;
    while(j < index)
    {
        i = 0;
        c = (unsigned char) new;
        new = new>>8;
        *mes_c = c;
        mes_c--;
        j++;
    }
}

unsigned char *decryption(unsigned long long int d, unsigned long long int n, unsigned char *mes, unsigned int size_mes,unsigned int* size)
{
    unsigned char *mes_c;
    unsigned int j;
    int i;
    unsigned int ii;
    unsigned int size_n;
    unsigned int size_new;
    unsigned long long int c, new;

    i = size_mes - 1;
    size_n = size_bytes(n);
    size_new = size_mes - size_mes / size_n;
    *size = size_new;
    mes_c = malloc(sizeof(char) * (size_new + 1));
    mes_c[size_new] = 0;
    ii = size_new - 1;
    while(i > -1)
    {
        j = 0;
        c = 0;
        while(i > -1 && j < size_n)
        {
            c += value_of_size_n(mes[i], j);
            j++;
            i--;
            if (j == size_n ||  i == -1)
            {
                new = power_modulo(c, d, n);
                new_to_message(new, &mes_c[ii], size_n -1);
                ii -= size_n - 1;
                break ;
            }
        }
    }
    return(mes_c);
}

unsigned char *incryption(unsigned long long int e, unsigned long long int n, unsigned char *mes, unsigned int size_mes, unsigned int *size)
{
    unsigned char *mes_c;
    unsigned int j;
    int i;
    unsigned int ii;
    unsigned int size_n;
    unsigned int size_new;
    unsigned long long int old, new;

    size_n = size_bytes(n);
    size_new = (size_mes / (size_n - 1)) * size_n;
    if (size_mes % (size_n - 1))
        size_new += size_n;
    *size = size_new;
    mes_c = malloc(sizeof(char) * (size_new + 1));
    mes_c[size_new] = 0;
    ii = size_new - 1;
    i = size_mes - 1;
    while(i > -1)
    {
        j = 0;
        old = 0;
        while(i > -1 && j < size_n - 1)
        {
            old += value_of_size_n(mes[i], j);
            i--;
            j++;
            if (j == size_n - 1 ||  i == -1)
            {
                new = power_modulo(old, e, n);
                new_to_message(new, &mes_c[ii], size_n);
                ii -= size_n;
                break ;
            }
        }
    }
    return(mes_c);
}
