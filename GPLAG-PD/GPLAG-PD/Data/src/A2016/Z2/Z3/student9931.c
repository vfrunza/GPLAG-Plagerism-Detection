#include <stdio.h>
int main() {
	int niz[20],nizz[20],i=0,j=0,t=0,n,w=0;
    do{printf("Unesite broj tacaka: ");
	  scanf("%d",&n);
	  if(n<1 || n>10){
	  	printf("Pogresan unos\n");
    }}while(n<1 || n>10);
    do{
    	printf("Unesite %d. tacku: ",i+1);
	    scanf("%d %d",&niz[i],&nizz[i]);
	    if(niz[i]<0 || niz[i]>=20 || nizz[i]<0 || nizz[i]>=20){
	    	printf("Pogresan unos\n");
	    	i--;
	    }
	    i++;
    }while (i<n);
    for(i=0;i<20;i++){
  	for(j=0;j<20;j++){
  		for(t=0;t<n;t++){
  		if(niz[t]==j && nizz[t]==i){
  				w++;
  				break;}
  		}
  		if(w>0)
    printf("*");
    else
    	printf(" ");
    	w=0;
    }
  		printf("\n");}
  		return 0;
}
