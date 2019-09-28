#include <io.h>
#include <stdlib.h>

void ft_lettre(char str)
{
    write(1,&str,1);
}

void ft_phrase(char *str)
{
    while(*str != '\0')
    {
        write(1,&*str,1);
        str++;
    }
    write(1,"\n",1);
}

int ft_taillePhrase(char *str)
{
    unsigned int taille;

    taille = 0;

    while (*str != '\0')
    {
        str++;
        taille++;
    }
    return(taille);
}

void ft_nombre(int nombre)
{
    int tmp;

    tmp = nombre;

    if (tmp < 0)
    {
        tmp *= -1;
        ft_lettre('-');
    }
    if (nombre > 9)
    {
        ft_nombre(tmp / 10);
    }
    ft_lettre(tmp % 10 + 48);
}

int ft_atoi(char *str)
{
    unsigned int num;
    int neg;
    unsigned int i;

    num = 0;
    neg = 1;
    i = 0;

    while (str[i] <= ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] + 48);
        i++;
    }
    return (num  * neg);
}

void ft_swapNombre(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

char *ft_implementationPhrase(char *source, char *destination)
{
    unsigned int i;

    i = 0;

    while (source[i] != '\0' && (ft_taillePhrase(source) < ft_taillePhrase(destination)))
    {
        destination[i] = source[i];
        i++;
    }
    if (ft_taillePhrase(source) > ft_taillePhrase(destination))
    {
        while (source[i] != '\0')
        {
            destination[i] = source[i];
            i++;
        }
        destination[i] == '\0';
    }
    return (destination);
}

void *ft_toutMajuscule(char *str)
{
    while (*str != '\0')
    {
        if ((*str >= 'A' && *str <= 'Z') || (*str < 'A' || *str > 'z') || (*str > 'Z' && *str < 'a'))
            str++;
        else
        {
            *str -= 32;
            str++;
        }
    }
}

void *ft_toutMinuscule(char *str)
{
    while (*str != '\0')
    {
        if ((*str >= 'a' && *str <= 'z') || (*str < 'A' || *str > 'z') || (*str > 'Z' && *str < 'a'))
            str++;
        else
        {
            *str += 32;
            str++;
        }
    }
}

int ft_comparatifphrase(char *s1, char *s2)
{
    unsigned int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if ((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0'))
        return (s1[i] - s2[i]);
    return (0);
}