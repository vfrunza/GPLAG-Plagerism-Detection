#include <stdio.h>

int br_ponavljanja(int A[100], int velA, int B[100], int velB)
{
    int br_pon, brojac=0;
    int i, j, k;
    int test;
   
    for (i=0; i <velA; i++)
    {
        test = 0;
        br_pon = 0;
        for (k=i+1; k<velA; k++)
        {
            if (A[i] == A[k]) br_pon = 1;
        }
        if (br_pon == 1) continue;
        for (j=0; j<velB; j++)
        {
            if (A[i] == B[j]) test = 1;
        }
    }
    return brojac;
    
}
int same (int A[100], int velA, int B[100], int velB)
{
    int test, brojac = 0;
    int i, j;
    for (i=0; i<velA; i++)
    {
        test = 0;
        for (j=0; j<velB; j++)
        {
            if (A[i] == B[i]) test = 1;
        }
    }
    if (test == 1) brojac++;
    return brojac;
}

int dva_od_tri (int A[100], int velA, int B[100], int velB, int C[100], int velC)
{
    int br_pon, brojac=0;
    int i, j, k;
    int test;
    for (i=0; i <velA; i++)
    {
        test = 0;
        br_pon = 0;
        for (k=i+1; k<velA; k++)
        {
            if (A[i] == A[k]) br_pon = 1;
        }
        if (br_pon == 1) continue;
        for (j=0; j<velB; j++)
        {
            if (A[i] == B[j]) test = 1;
        }
        for (j=0; j<velC; j++)
        {
            if (A[i] == C[j]) test = 1; 
            //else if (B[j] == C[l]) test = 0;
        }
        //}
        if (test == 1) brojac++;
    }
    
    return brojac;
}


int main() 
{
    int a[100], b[100], c[100], vela, velb, velc;
    int i;
    printf ("Unesite velicinu niza a: ");
    scanf ("%d", &vela);
    printf ("Unesite elemente niza a: ");
    for (i=0; i<vela; i++)
    {
        scanf ("%d", &a[i]);
    }
    printf ("Unesite velicinu niza b: ");
    scanf ("%d", &velb);
    printf ("Unesite elemente niza b: ");
    for (i=0; i<velb; i++)
    {
        scanf ("%d", &b[i]);
    }
    printf ("Unesite velicinu niza c: ");
    scanf ("%d", &velc);
    printf ("Unesite elemente niza c: ");
    for (i=0; i<velc; i++)
    {
        scanf ("%d", &c[i]);
    }
    
    /*int rez = br_ponavljanja(a, vela, b, velb);
    printf ("%d", rez);
    printf ("\n");
    int rez1 = br_ponavljanja(a, vela, c, velc);
    printf ("%d", rez1);
    printf ("\n");*/
    
    
    int rez3 = dva_od_tri (a,vela, b, velb, c, velc);
    printf  ("%d", rez3);
    
	return 0;
}
