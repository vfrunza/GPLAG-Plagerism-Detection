#include <stdio.h>

int main() {
    int i,j,p=0,c=0,f=0,vel,niz[100], cifre[10000], pom[10],final[10000], broj_pom=0,broj_cifara=0,brojac=1,broj_final=0; 
    
    do{
        printf("Unesite velicinu niza: ");
        scanf("%d",&vel);
    }while(vel<=0 || vel>100);
    
    printf("Unesite clanove niza: ");
    for(i=0;i<vel;i++) scanf("%d",&niz[i]);
    
    for(i=0;i<vel;i++) {
        if(niz[i]==0) {cifre[c]==0; c++; broj_cifara++; continue; }
        while(niz[i]!=0) {
            pom[p]=(niz[i]%10); 
            niz[i]/=10; 
            p++; 
            broj_pom++;
        }
        for(p=broj_pom-1;p>=0;p--) {
            cifre[c]=pom[p];
            c++; broj_cifara++;
        }
        p=0;broj_pom=0;
    }
    
    for(i=0;i<broj_cifara;i++) {
        if(i==broj_cifara-1) { final[f]=cifre[i]; final[f+1]=1; broj_final+=2; break;}
        for(j=i+1;j<broj_cifara;j++) {
           if(cifre[i]==cifre[j] && j!=broj_cifara) brojac++;
           else {
               final[f]=cifre[i]; final[f+1]=brojac;  f+=2; broj_final+=2; break;
           }
          }
          if(j==broj_cifara) { final[f]=cifre[i]; final[f+1]=brojac; broj_final+=2;}
          i+=brojac-1; brojac=1;
    }
    
    printf("Finalni niz glasi:\n");
    for(i=0;i<broj_final;i++) printf("%d ",final[i]);
    
    
    
	return 0;
}
