void echanger(int *tableau, int a, int b)
{
    int tmp;

    tmp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = tmp;
}

void tri_rapide(int *tableau, int debut, int fin)
{
    int gauche  = debut - 1;
    int droite = fin + 1;
    const int pivot = tableau[debut];

    if(debut >= fin)
        return;

    while(1)
    {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);
        if (gauche < droite)
            echanger(tableau,gauche,droite);
        else
            break;
    }

    tri_rapide(tableau, debut, droite);
    tri_rapide(tableau, droite + 1, fin);
}