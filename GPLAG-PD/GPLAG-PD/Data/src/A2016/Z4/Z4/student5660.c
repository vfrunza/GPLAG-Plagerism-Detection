#include <stdio.h>
#include <math.h>
#define eps 0.0001

int DaLiJeIspravan (char* s)
{
	int brTacaka = 0, brBrojeva = 0, broj = 0;
	while (*s != '\0')
	{
	    brTacaka = 0;
	    brBrojeva = 0;
		if (*s != '(') 
		    return 0;
		s++;
		/* Ako nakon s++ bude *s == '\0' ovaj if nece biti ispunjen i uci ce u while, *s != ',' je T i desit ce se else */
		if (*s == '-') 
		    s++;
		broj = 0;
		while (*s != ',')
		{
			/* stavim pokazivac gdje je s trenutno, provjerim ima li tacku, 
			ako ima -> prije nje mora biti cifra
		    ako nema -> onda ide kao i do sad */
			if (*s == '.')
			{
			    brTacaka++;
			    if (!broj) return 0;
			}
			else if (*s >= '0' && *s <= '9')
			{
			    brBrojeva++;
			    broj = 1;
			}
			/* U ovom else bi trebali biti pokriveni slucajevi: 
			1) sta ako dodje do kraja i bude *s == '\0'; npr : (-2.34\0  
			2) sta ako bude *s != broja ili *s != tacke*/
			else return 0;
			s++;
		}
		/* Ako izmedju ( i , ima vise minusa od 1 ili vise tacaka od 1 ili nema brojeva s nije ispravan */
		if ((brTacaka > 1) || brBrojeva == 0)
            return 0;
		s++;
		brTacaka = 0;
		brBrojeva = 0;
		broj = 0;
		if (*s == '-') s++;
        while (*s != ')')
		{
		    if (*s == '.')
			{
			    brTacaka++;
			    if (!broj)
			        return 0;
			}
		    else if (*s >= '0' && *s <= '9')
			{
			    brBrojeva++;
			    broj = 1;
			}
			/* U ovom else bi trebao biti pokriven slucaj: sta ako dodje do kraja i bude *s == '\0'*/
			else return 0;
			s++;
		}
		if ((brTacaka > 1) || brBrojeva == 0)
		return 0;
		s++;
		if (*s == ',')
		{
		    s++;
		    if (*s == '\0') 
		        return 0;
		}
        else if (*s == '\0') return 1;
		/* Ovaj else je nepotreban jer kad se desi s++ krenut ce od pocetka ova petlja i prva provjera je da mora biti (, 
		ako nije prekida, al neka stoji, ne trazi jesti*/ 
		else return 0;
	}
	return 1;
}

int DaLiJeUnutarPravougaonika (float x, float y, float x1, float y1, float x2, float y2)
{
    if (((x1 < x) || fabsf(x1-x) < eps) &&
    ((x2 > x) || fabsf(x2-x) < eps) &&
    ((y1 < y) || fabsf(y1-y) < eps) &&
    ((y2 > y) || fabsf(y2-y) < eps))
    {
        return 1;
    }
    return 0;
}


char* obuhvat (char* s, float x1, float y1, float x2, float y2)
{
    char* pz1, *pz2, *pz1k, *cuvar, *pocetak = s;
    int minus;
    float x, y, desetke;
    if (*s == '\0') return s;
    if (!DaLiJeIspravan(s)) return 0;
	pz1 = s;
    while (*s != '\0')
    {
        x = 0;
        y = 0;
        pz2 = pz1;
        pz2++;
        while (*pz2 != '(' && *pz2 != '\0')
            pz2++;
        pz1k = pz1;
        pz1k++;
        if (*pz1k == '-')
        {
            minus = -1;
            pz1k++;
        }
        else minus = 1;
        cuvar = pz1k;
        desetke = 1;
        while (*pz1k != '.' && *pz1k != ',')
        {
            desetke *= 10;
            pz1k++;
        }
        desetke /= 10;
        pz1k = cuvar;
        while (*pz1k != '.' && *pz1k != ',')
        {
            x += (*pz1k - '0') * desetke;
            desetke /= 10;
            pz1k++;
        }
        if(*pz1k == '.')
        {
            pz1k++;
            desetke = 10;
            while (*pz1k != ',')
            {
                x += (*pz1k - '0') / desetke;
                desetke *= 10;
                pz1k++;
            }
        }
        x *= minus;
        pz1k++;
        /* Nakon ovog x bi trebao biti "sredjen" i sada ostaje jos y da se "sredi" + pz1k je pomjeren sa zareza na tacku ili broj*/
        if (*pz1k == '-')
        {
            minus = -1;
            pz1k++;
        }
        else minus = 1;
        cuvar = pz1k;
        desetke = 1;
        while (*pz1k != '.' && *pz1k != ')')
        {
            desetke *= 10;
            pz1k++;
        }
        desetke /= 10;
        pz1k = cuvar;
        while (*pz1k != '.' && *pz1k != ')')
        {
            y += (*pz1k - '0') * desetke;
            desetke /= 10;
            pz1k++;
        }
        if(*pz1k == '.')
        {
            pz1k++;
            desetke = 10;
            while (*pz1k != ')')
            {
                y += (*pz1k - '0') / desetke;
                desetke *= 10;
                pz1k++;
            }
        }
        y *= minus;
        if (!DaLiJeUnutarPravougaonika(x, y, x1, y1, x2, y2))
        {
            cuvar = pz1;
            while (*pz2 != '\0')
                *pz1++ = *pz2++;
            while (*pz1 != '\0')
                *pz1++ = '\0';
            pz1 = cuvar;
            s = cuvar;
        }
        else
        {
            pz1 = pz2;
            s = pz2;
        }
        }
        s = pocetak;
        while (*s != '\0')
            s++;
        s--;
        if (*s == ',')
            *s = '\0';
        return pocetak;
}

int main() {

    /* Interesantan primjer je ovo 0.001 i 0.0001 */
    char s[] = "(1.0,2.0)";
	char* pok = obuhvat(s,0,0,0,0);
	if (!DaLiJeIspravan(s)) printf ("nije ispravan\n");
	else printf ("jeste ispravan\n");
  /*  while (*pok != '\0')
        printf ("%c", *pok++);
*/	return 0;
}
