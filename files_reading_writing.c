#include "rsa.h"

unsigned int     ft_strlen(unsigned char *c)
{
    int i = 0;
    while(c[i])
        i++;
    return(i);
}

unsigned char *path_case(unsigned char *s)
{
    int i = ft_strlen(s) - 1;
    while(i >= 0)
    {
        if (s[i] == '/')
            return(&s[i + 1]);
        i--;
    }
    return(s);
}

unsigned char	*ft_strjoin(unsigned char  *s1, char const *s2)
{
	unsigned char	*p;
	int		j;
	int		i;

	if (!s1 || !s2)
		return (0);
    s1 = path_case(s1);
	j = 0;
	i = 0;
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen((unsigned char *)s2) + 1));
	if (!p)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

void    writing_in_file(unsigned char *mes, unsigned char *name, unsigned int size, int a)
{
    unsigned char *new_name;
    if (a == 1)
        new_name = ft_strjoin(name, "_crypted");
    else
        new_name = ft_strjoin(name, "_decrypt");
    int fd = open((const char*)new_name, O_RDWR| O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        printf("Eroor opening file\n");
        return ;
    }
    printf("your file is encrypted successfully . name of file = '%s'\n", new_name);
    write(fd, mes, size);
    close(fd);
    free(new_name);
}

int size_file(char *file, int err)
{
    int fd;
    int r;
    int i;
    char c;

    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("ERROR: could not open the file %s", file);
        close(err);
        exit(3);
    }
    r = read(fd, &c, 1);
    if (r == -1)
    {
        printf("ERROR: fail to read file !\n");
        close(err);
        exit(4);
    }
    while(r)
    {
        i++;
        r = read(fd, &c, 1);
        if (r == -1)
        {
            printf("ERROR: fail to read file !\n");
            close(err);
            exit(5);
        }
    }
    close(fd);
    return (i);
}

unsigned char*   get_message_from_file(char *file, int err, unsigned int *size)
{
    int r;
    int i;
    int z;
    unsigned char *mes;
    int fd;

    i = 0;
    *size = size_file(file, err);
    z = *size;
    if (!z)
    {
        printf("ERROR : Theres no message!\n");
        exit(69);
    }
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("ERROR: could not open the file %s", file);
        close(err);
        exit(3);
    }
    mes = malloc(sizeof(char) * z);
    r = read(fd, mes, z);
    close(fd);
    return (mes);
}
