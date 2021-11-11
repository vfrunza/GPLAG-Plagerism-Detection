#include <stdio.h>

double ck(char c)
{
	return c == 'P' ? 6.8 : c == 'H' ? 3.3 : 5.0;
}
double ct(char c)
{
	return c == 'P' ? 8.0 : c == 'H' ? 3.0 : 3.9;
}
double cl(char c)
{
	return c == 'P' ? 5.3 : c == 'H' ? 5.0 : 6.0;
}

int main()
{
    char t, b, m, novi_red;
    double k = 0, tr = 0, l = 0, n = 0, n1 = 0, i = 0, j = 0, _k = 0;
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &t);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &b);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &m);
    k = ck(t) + ck(b) + ck(m);
    tr = ct(t) + ct(b) + ct(m);
    l = cl(t) + cl(b) + cl(m);
    i = 0;
    n = k;
    if (tr < n && (i = 1)) n = tr;
    if (l < n && (i = 2)) n = l;
    printf("Najjeftiniji je ");
    switch ((int)i)
    {
        case 0:
            printf("Restoran \"Kod konja i konjusara\" (%.2f KM).", k);
            break;
        case 1:
            printf("Fast-food \"Trovac\" (%.2f KM).", tr);
            break;
        case 2:
            printf("Bistro \"Lorelei\" (%.2f KM).", l);
            break;
    }
    if (n == k)
        return 0;
    i = 0;
    if (t == 'P') i++;
    if (b == 'P') i++;
    if (m == 'P') i++;
    if (t == 'H') j++;
    if (b == 'H') j++;
    if (m == 'H') j++;
    _k = 3 - i - j;
    i *= .68;
    j *= .33;
    _k *= .5;
    n1 = i;
    if (j > n1) n1 = j;
    if (_k > n1) n1 = _k;
    if (k - n1 < n)
        printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", k - n1);
    return 0;
}