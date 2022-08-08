#include "rsa.h"

void    reading_value(unsigned long long int *e, int fd)
{
    int i;
    int r;
    unsigned char c;

    i = 0;
    while(i < 8)
    {
        r = read(fd, &c, 1);
        if (r == -1)
        {
            printf("EROOR: reading the key\n");
            exit(69);
        }
        *e += c;
        if (i != 7)
            *e = *e<<8;
        i++;
    }
}

void    file_to_values(unsigned long long int *e, unsigned long long int *n, int fd)
{
    *e = 0;
    reading_value(e, fd);
    *n = 0;
    reading_value(n, fd);
    close(fd);
}
void    keys_to_file(int fd, unsigned long long int n)
{
    int i;
    unsigned char c;
    unsigned char *key = malloc(sizeof(char) * 8);

    i = 7;
    while(i >= 0)
    {
        key[i] = (unsigned char)n;
        if (i != 0)
            n = n>>8;
        i--;
    }
    write(fd, key, 8);
    free(key);
}