#include <stdio.h>

int dva_od_tri(int *niz1,int vel1,int *niz2,int vel2,int *niz3,int vel3){
    
    int i,j,k;
    int istina; //ako je 1 tada je OK,-1 nije OK,0 da se vec ponavljao
    int brojac=0;
    
    for(i=0;i<vel1;i++){
        istina=-1;
        
        for(k=0;k<i;k++) if(niz1[i]==niz1[k]) istina=0; 
       
        
        if(istina!=0){
            for(j=0;j<vel2;j++){
                if(niz1[i]==niz2[j]) {istina*=(-1);break;} // da nema break ako se taj broj nalazio vise puta u niz2 onda bi se istina obrnula vise puta nego sto treba
            }
            for(j=0;j<vel3;j++){
                if(niz1[i]==niz3[j]) {istina*=(-1);break;}
            }
        }
        if(istina==1) brojac++;
    }
    
    for(i=0;i<vel2;i++){
        istina=-1;
        for(k=0;k<i;k++) if(niz2[i]==niz2[k]) istina=0; // ponovio se u nizu 2
        for(k=0;k<vel1;k++) if(niz2[i]==niz1[k]) istina=0; // ponovio se u prijasnjem nizu 1
        
        if(istina!=0){
            for(j=0;j<vel1;j++){
                if(niz2[i]==niz1[j]) {istina*=(-1);break;}
            }
            for(j=0;j<vel3;j++){
                if(niz2[i]==niz3[j]) {istina*=(-1);break;}
            }
        }
        if(istina==1) brojac++;
    }
    
    return brojac;
}
   



int main()
{
    int a[]={1,2,3,5};
    int b[]={1,2,4,6,7};
    int c[]={1,3,4,8,9,10};
    
    printf("%d",dva_od_tri(a,4,b,5,c,6));
    
    return 0;
}