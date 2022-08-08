#include "rsa.h"

int main(int argc, char *argv[])
{
    unsigned int size, new_size;
    if (argc != 3)
    {
        printf("two arguments : name of the file you wanna crypte and the key\n");
        return (4);
    }
    unsigned long long int d, n;
    unsigned char *mes, *mes_decrypt;
    unsigned int size_mes_crypt;
    int fd_key = open(argv[2], O_RDONLY);
    if (fd_key == -1)
    {
        printf("ERROR: %s does not existe ,you should first generate the keys!\n", argv[2]);
        return(-2);
    }
    mes = get_message_from_file(argv[1], fd_key, &size);
    file_to_values(&d, &n, fd_key);
    mes_decrypt = decryption(d, n, mes, size, &new_size);
    writing_in_file(mes_decrypt, (unsigned char*)argv[1], new_size, 2);
    close(fd_key);
    return(69);
}