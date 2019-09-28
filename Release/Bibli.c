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
    int taille;

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
    int num;
    int neg;
    int i;

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

void ft_swapnombre(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void ft_implementationPhrase(char *source, char *destination)
{
    int i;

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
}

char *ft_toutMajuscule(char *str);