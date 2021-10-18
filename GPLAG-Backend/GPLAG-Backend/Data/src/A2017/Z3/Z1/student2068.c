#include <stdio.h>


int dva_od_tri(int niz1[],int vel1,int niz2[], int vel2,int niz3[],int vel3){
    int i,j,k,g;
    int brojac12=0,brojac13=0,brojac23=0,pomocni1[100]={0};
    
    for(i=0;i<vel1;i++){
        for(j=0;j<vel2;j++){
            
            if(niz1[i]==niz2[j]) { brojac12++; pomocni1[i]=niz2[j];}
                                
        }
    }

    
    for(i=0;i<vel1;i++){
        for(k=0;k<vel3;k++){
            if(niz3[k]==pomocni1[i])brojac12--;
            if(niz1[i]==niz3[k] && niz3[k]!=pomocni1[i])brojac13++;
        }
    }
    for(j=0;j<vel2;j++){
        for(k=0;k<vel3;k++){
            if(niz3[k]==pomocni1[j])brojac12--;
            if(niz2[j]==niz3[k] && niz3[k]!=pomocni1[i])brojac23++;
        }
    }
    g=brojac12+brojac13+brojac23;
    return g;
}
   

    int main() {
	int niz1[100],niz2[100],niz3[100],i,a,b,c,rez;
	
	printf("Unijeti broj clanova prvog niza: ");
    scanf("%d",&a);
    for(i=0;i<a;i++){
    	scanf("%d",&niz1[i]);
    }
    
    printf("Unijeti broj clanova drugog niza: ");
    scanf("%d",&b);
    for(i=0;i<b;i++){
    	scanf("%d",&niz2[i]);
    }
    printf("Unijeti broj clanova treceg niza: ");
    scanf("%d",&c);
    for(i=0;i<c;i++){
    	scanf("%d",&niz3[i]);
    }
    
    
    
    rez=dva_od_tri(niz1,a,niz2,b,niz3,c);
	printf("Broj je: %d",rez);
	
	return 0;
}
