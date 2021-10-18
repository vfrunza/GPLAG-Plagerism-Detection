#include<stdio.h>
int max(int matrica[100][100], int visina, int sirina){
int niz[10000];
int k=visina*sirina,i,j,i1,j1;
int c=0,Max,broj=0;
for( i1=0;i1<visina;i1++){
for( j1=0;j1<sirina;j1++)
{ niz[c]=matrica[i1][j1];
c++;
}
}
int br=1,tempbr;
int naj=niz[0];
int temp=0;
for(i=0;i<k;i++){
    temp=niz[i];
    tempbr=0;
    for(j=i+1;j<k-1;j++){
        if(temp==niz[j])
            tempbr++;
    }
    if(tempbr>br){
        naj=temp;
        br=tempbr;
    }
    else if(tempbr==br && naj>temp )
    {
        naj=temp;
        br=tempbr;
    }
}
return naj;
}

int izbaci_kolone(int matrica[100][100],int visina, int sirina, int N)
{
    int i,j,i1,j1,kol=sirina;
    for(j=0;j<sirina;j++){
        for(i=0;i<visina;i++)
        {

            if (matrica[i][j]==N && j!=sirina-1 )
            {   sirina=sirina-1;
               for(j1=j;j1<sirina;j1++){
                for(i1=0;i1<visina;i1++)
                {
                    matrica[i1][j1]=matrica[i1][j1+1];
                }
               }

j=j-1;
break;

            }
else if(matrica[i][j]==N && j==sirina-1)
{
    sirina=sirina-1;
    break;

}
        }


}
return sirina;
}

int main()
{
int A[100][100];
int a,b,i,j,z;
int prazno=0;
printf("Unesite sirinu i visinu matrice: ");
scanf("%d",&b);
scanf("%d",&a);

for( i=0;i<a;i++){
        printf("Unesite elemente %d . reda: ",i+1);
for( j=0;j<b;j++)
{
scanf("%d",&A[i][j]);
}




}
while(prazno==0)
{
    z=izbaci_kolone(A,a,b,max(A,a,b));
for( i=0;i<a;i++){
for( j=0;j<z;j++)
{
    printf("%d",A[i][j]);
}
printf("\n");
}

if (z==0)
{
    prazno=1;
}
}
}
