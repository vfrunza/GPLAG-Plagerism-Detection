#include <stdio.h>
#include <math.h>
 
void zaokruzi1 (float niz[], int n){
    int i;
    for (i=0; i<n; i++){
        niz[i]=(round(niz[i]*10))/10;
    }
}
 
void preslozi (float niz[], int n, int k){
   
    int i,pom=1;
    int brojac1=0, brojac2=0,sum=0;
   
    float nizb1[100];
    for (i=0; i<100; i++)
    nizb1[i]=0;
   
    float nizb2[100];
    for (i=0; i<100; i++)
    nizb2[i]=0;
   
    for (i=0; i<n ;i++) {
   
    pom=niz[i]*10;
    while(pom>0){
        sum=sum+(pom%10);
        pom=pom/10;
    }
   
   
    zaokruzi1(niz,n);
   
    if(sum>=k){
        nizb1[brojac1]=niz[i];
        brojac1++;
    }
    if (sum<k){
        nizb2[brojac2]=niz[i];
        brojac2++;
    }
    }
   
 
    for (i=0; i<brojac1; i++) {
        niz[i]=nizb1[i];
    }
    for (i=0; i<brojac2; i++){
        niz[brojac1+i]=nizb2[i];
   
    }
}
 
int main() {
   
    float niz[100];
    int i,n,k;
   
    printf ("k=");
    scanf ("%d", &k);
    printf ("n=");
    scanf("%d",&n);
    printf ("Unesi niz: ");
    for (i=0; i<n; i++){
        scanf ("%f",&niz[i]);
    }
   
        preslozi(niz,n,k);
    printf("Niz glasi: ");
   
    for (i=0; i<n; i++)
         printf("%g ", niz[i]);
         
    return 0;
}