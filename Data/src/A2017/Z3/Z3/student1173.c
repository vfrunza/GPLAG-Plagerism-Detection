#include <stdio.h>
int izbaci_cifre(int broj,int *niz_cifara,int vel)
{
int x=broj;
if(broj<0)x=x*-1;
int i,j;
int brojac=0;
int temp=x;
int niz [1000];
int ZA=0;
int l=0,k=0;
for(l=0;l<vel;l++){
    if(niz_cifara[l]>9||niz_cifara[l]<0)return -99999;
}
for(l=0;l<vel-1;l++)
{
    for(k=l+1;k<vel;k++){
        if(niz_cifara[l]==niz_cifara[k])return -99999;
    }
}
    while(temp>0)
    {
        temp/=10;
        brojac++;
    }
    temp=x;
    int cifra;
    while(temp>0){
        cifra=temp%10;
        niz[ZA]=cifra;
        ZA++;
        temp=temp/10;
    }
    int ll=0;
    for(i=0;i<vel;i++)
    {
 
        for(ll=0;ll<brojac;ll++)
        {
            if(niz_cifara[i]==niz[ll])
            {
                for(j=ll;j<brojac-1;j++){
                    niz[j]=niz[j+1];
                }
                brojac--;
                ll--;
            }
       
        }
    }
     int o=0;
     for(i=0;i<brojac;i++)
     {
        o=o*10+niz[i];
     }
     int aa=0;
     int cifrica;
     while(o>0){
        cifrica=o%10;
        aa=aa*10+cifrica;
        o=o/10;
     }
   
    if(broj<0)aa*=-1;
    return aa;
   
   
}
int main() {
int x;
int niz[1000];
int i=0;
int s;
printf("Unesite broj: ");
scanf("%d",&x);
printf("Unesite niz cifara (-1 za kraj): ");
while(1){
    scanf("%d",&s);
    if(s==-1)break;
    niz[i++]=s;
}
int o=izbaci_cifre(x,niz,i);
 
if(o==-99999)printf("Neispravan unos");
 
printf("Broj bez cifara glasi: %d",o);
 
    return 0;
}