#include <stdio.h>
#include <stdlib.h>
int main()
{

    int vel;
    int niz[100]= {};
    int pomocni[100]= {};
    int finalni[1000]={};

    int i,j,f,l,pom,s,m,n,c;
    int brojac=0, brojac2=0;
    int ostatak=0, br=0;
    int k=0;

    printf("Unesite velicinu niza: ");
    scanf("%d",&vel);

    printf("Unesite clanove niza: ");
    for(i=0; i<vel; i++) {
        scanf("%d", &niz[i]);
        }

    for(j=0; j<vel; j++) {
        
        brojac=k;
        if(niz[j]==0){
        pomocni[k]=niz[j];
        continue;
        }
        else
        {
        
        while(niz[j]>0) {
       
            ostatak=niz[j]%10;
            pomocni[k]=ostatak;
            k++;
            
            if(niz[j]<10) {
        s=0;
                for(l=brojac; l<brojac+((k-brojac)/2); l++) {
                   
                    pom=pomocni[l];
                    pomocni[l]=pomocni[k-s-1];
                    pomocni[k-s-1]=pom;
                    s++;
                }
            }
            niz[j]=niz[j]/10;
        
        }
    }
    
    }
    
    brojac2=0;
    
    for(f=0; f<k; (f=f+br))
    {
      
              finalni[brojac2]=pomocni[f];
       br=1;
      
        for(m=f+1;m<k+1;m++)
    {
        if(pomocni[f]==pomocni[m])
        br++;
        
        else
        {
            
            finalni[brojac2+1]=br;
    brojac2=brojac2+2;
    m=k;
    
        
    }   
        
    }
    
    
   
    
    }
   // for(c=0;c<k;c++)
    //rintf("%d ", pomocni[c]);
    printf("Finalni niz glasi:\n");
    for(n=0;n<brojac2;n++)
        printf("%d ",finalni[n]);

    return 0;

}