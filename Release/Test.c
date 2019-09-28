#include "Release/Bibli.c"
#include <stdio.h>

int main(int argc, char **argv)
{
    char phrase[] = "coucou";

    if (argc == 1)
    {
        ft_phrase(phrase);
        ft_taillePhrase(phrase);
    }
    else if (argc == 2)
    {
        ft_phrase(argv[1]);
        ft_taillePhrase(argv[1]);
    }
    
    return (0);
}