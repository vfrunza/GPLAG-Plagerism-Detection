#include <stdio.h>
int dva_od_tri(int * N1,int vel1,int * N2,int vel2,int * N3,int vel3)
{
    int brojac=0;
    int provjera;
    int i,j,k;
    for (i=0;i<vel1;i++) {
        provjera=0;
        for ( j=0;j<vel2;j++) {
            if(N1[i]==N2[j])
            {
                provjera=1;
                for ( k=0;k<vel3;k++) {
                    if(N1[i]==N3[k])
                    {
                        provjera=0;
                        break;
                    }
                }
            }
            else{
                for ( k=0;k<vel3;k++) {
                    if(N1[i]==N3[k])
                    {
                        provjera=1;
                    }
                }
            }
        }
        if(provjera==1)
        brojac++;
    }
    return brojac;
}
 
int main()
{
return 0;
}