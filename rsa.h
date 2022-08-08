#ifndef RSA_H
#define RSA_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdint.h>

unsigned long long  int  prime(void);
int     ft_is_prime(unsigned long long int nb);
unsigned long long int euclide_etendu(unsigned long long int a,unsigned long long int b, long long int *u,long long int *v);
unsigned int power(unsigned int n, unsigned int p);
unsigned long long int power_modulo(unsigned long long int n,unsigned long long int p, unsigned long long int m);
unsigned int size_bytes(unsigned long long int a);
unsigned long long int    value_of_size_n(unsigned char c, int j);
void    new_to_message(unsigned long long int new, unsigned char *mes_c, unsigned int index);
unsigned char *decryption(unsigned long long int d, unsigned long long int n, unsigned char *mes, unsigned int size_mes,unsigned int* size);
unsigned char *incryption(unsigned long long int e, unsigned long long int n, unsigned char *mes, unsigned int size_mes, unsigned int *size);
unsigned int     ft_strlen(unsigned char *c);
unsigned char *path_case(unsigned char *s);
unsigned char	*ft_strjoin(unsigned char  *s1, char const *s2);
void    writing_in_file(unsigned char *mes, unsigned char *name, unsigned int size, int a);
int size_file(char *file, int err);
unsigned char*   get_message_from_file(char *file, int err, unsigned int *size);
void    keys_to_file(int fd, unsigned long long int n);
void    file_to_values(unsigned long long int *e, unsigned long long int *n, int fd);
void    reading_value(unsigned long long int *e, int fd);

#endif