#include "rsa.h"

int main(void)
{
    unsigned long long int n, f, e, p, q;
    long long int d, v;
    while(1)
    {
        p = prime();
        sleep(1);
        q = prime();
        n = p * q;
        if (n > 256 && p != q)
            break;
    }
    n = p * q;
    f = (p - 1) * (q -1);
    if (p > q)
        e = p + 1;
    else
        e = q + 1;
    while(1)
    {
        if (euclide_etendu(e, f, &d, &v) == 1)
        {
            if (d > 0)
                break ;
        }
        e++;
    }
    int fd_public = open("key_rsa.pub", O_RDWR | O_CREAT | O_TRUNC, 0644);
    int fd_privat = open("key_rsa", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd_privat == -1 || fd_public == -1)
    {
        printf("ERROR: fail to open file !\n");
        return(-1);
    }
    keys_to_file(fd_public, e);
    keys_to_file(fd_public, n);
    keys_to_file(fd_privat, d);
    keys_to_file(fd_privat, n);
    close(fd_privat);
    close(fd_public);
    printf("Keys generated succefuly !. your public key : 'key_rsa.pub' and the privat key : 'key_rsa'\n");
    return (0);
}
