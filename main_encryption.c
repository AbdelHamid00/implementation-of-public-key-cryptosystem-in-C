#include "rsa.h"

// file - public key (e and n)



int main(int argc, char *argv[])
{
    unsigned int size;
    unsigned long long int e, n;
    unsigned char *mes, *mes_crypt;
    unsigned int size_mes_crypt;
    if (argc != 3)
    {
        printf("two arguments : name of the file you wanna crypte and the key\n");
        return (4);
    }
    int fd_key = open(argv[2], O_RDONLY);
    if (fd_key == -1)
    {
        printf("ERROR: %s does not existe ,you should first generate the keys!\n", argv[2]);
        return(-2);
    }
    mes = get_message_from_file(argv[1], fd_key, &size);
    file_to_values(&e, &n, fd_key);
    mes_crypt = incryption(e, n, mes, size, &size_mes_crypt);
    writing_in_file(mes_crypt, (unsigned char*)argv[1], size_mes_crypt, 1);
    return(69);
}