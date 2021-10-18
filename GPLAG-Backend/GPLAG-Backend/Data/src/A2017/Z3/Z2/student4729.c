#include <stdio.h>
#include <math.h>

float zaokruzi (float nizr[], int b)
{
    int i;
    float y;
    for (i=0; i<b; i++){
        y=round(nizr[b]);
         return y;}
         
         return 0;
}

float preslozi (float nizr1[],int t, int c)
{
    float suma=0;
    int j,cif,k,temp;
    int max=0;
    zaokruzi(nizr1, t);
    for (j=0; j<t; j++) {
       cif=(int)nizr1[t]%10;
       suma+=cif;
       nizr1[t]=nizr1[t]/10;
    }

    for (j=0; j<t; j++) {
        max=j;
        for (k=j+1; k<t; k++)
            if (suma>=cif)
            max=j;
            temp=nizr1[j];
            nizr1[j]=nizr1[max];
            nizr1[max]=temp;
    }
    return nizr1[t];
}
int main()
{
    float niz_r[100]; 
    int s,k;
    do {
        scanf("%f ", &niz_r[100]);
    } while (niz_r[100]!='\n');
    s=sizeof(niz_r);
    scanf ("%d ", &k);
    printf ("%f ", preslozi(niz_r,s,k));
    return 0;
}
