#include <stdio.h>
int dva_od_tri(int *a,  int duzinaA, int *b, int duzinaB, int *c, int duzinaC)
{
    int i,j,k;
    int brojac=0;
    for(i=0;i<duzinaA;i++)
    {
        for(j=i+1;j<duzinaA;j++)
        {
            if(a[i]==a[j])
            {
                for(k=j;k<duzinaA-1;k++)
                {
                    a[k]=a[k+1];
                }
                duzinaA--;
                j--;
            }   
        }
    }
    for(i=0;i<duzinaB;i++)
    {
        for(j=i+1;j<duzinaB;j++)
        {
            if(b[i]==b[j])
            {
                for(k=j;k<duzinaB-1;k++)
                {
                    b[k]=b[k+1];
                }
                duzinaB--;
                j--;
            }   
        }
    }
    for(i=0;i<duzinaC;i++)
    {
        for(j=i+1;j<duzinaC;j++)
        {
            if(c[i]==c[j])
            {
                for(k=j;k<duzinaC-1;k++)
                {
                    c[k]=c[k+1];
                }
                duzinaC--;
                j--;
            }   
        }
    }
    int niz[300];
    for(i=0;i<duzinaA+duzinaB+duzinaC;i++)
    {
        if(i<duzinaA)
        niz[i]=a[i];
        if(i>=duzinaA && i<duzinaA+duzinaB)
        niz[i]=b[i-duzinaA];
        if(i>=duzinaA+duzinaB)
        niz[i]=c[i-duzinaA-duzinaB];
    }
    for(i=0;i<duzinaA+duzinaB+duzinaC;i++)
    {
        int pombr=0;
        int ponavljase=0;
        for(j=0;j<i;j++)
        {
            if(niz[i]==niz[j])
            ponavljase=1;
        }
        for(j=i+1;j<duzinaA+duzinaB+duzinaC;j++)
        {
            if(ponavljase)
            break;
            if(niz[i]==niz[j])
            pombr++;
        }
        if(pombr==1)
        brojac++;
    }
    return brojac;
}
int main() {
    int i=0;
    int a[100],b[100],c[100],duzinaA,duzinaB,duzinaC;
    do{
    	scanf("%d", &a[i]);
    }
    while(a[i]!=-1 || i++<100);
    duzinaA=i;
    i=0;
    do{
    	scanf("%d", &b[i]);
    }
    while(b[i]!=-1 || i++<100);
    duzinaB=i;
    i=0;
    do{
    	scanf("%d", &c[i]);
    }
    while(c[i]!=-1 || i++<100);
    duzinaC=i;
	return 0;
}
