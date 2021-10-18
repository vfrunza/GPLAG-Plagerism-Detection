#include <stdio.h>

int main (){
	
	int niz_unos[1000];
	int niz2[1000], Nizz[1000], niz_konacni[1000];
	int i, clanova, pom, broj_za_niz3=0;
	int brojac=0, j=0, br, n;
	
	printf ("Unesite velicinu niza: ");
    scanf ("%d", &n);
    
	printf ("Unesite clanove niza: ");
	 for (i=0;i<n;i++){
	 	scanf("%d",&niz_unos[i]);
	 }
	 for (i=n-1;i>=0;i--){
	 	pom=niz_unos[i];
	 	if(niz_unos[i]==0){
	 		niz2[brojac]=0;
	 		brojac++;
	 		continue;
	 	}
	 	do {
	 		niz2[brojac]=pom%10;
	 		if(pom==0) break;
	 		pom/=10;
	 		brojac++;
	 	}while(1);
	 }
	 clanova=brojac;
	 for(i=0;i<brojac;i++){
	 	Nizz[i]=niz2[clanova-1];
	 	clanova--;
	 }
	 for(i=0;i<brojac;i++){
	 	niz_konacni[broj_za_niz3]=Nizz[i];
	 	broj_za_niz3++;
	 	br=1;
	 	for(j=i+1;j<brojac;j++){
	 		if(Nizz[j]==Nizz[i]){
	 			br++;
	 		}
	 		else {
	 			break;
	 		}
	 	}
	 	niz_konacni[broj_za_niz3]=br;
	 	broj_za_niz3++;
	 	i=j;
	 	i--;
	 }
	 
	 printf ("Finalni niz glasi: \n");
	   for(i=0;i<broj_za_niz3;i++){
	   	printf("%d ",niz_konacni[i]);
	   }
	   
	   return 0;
}