#include <stdio.h>

int main() {
	int broj_redova,broj_kolona,sirina_kolone;
	int broj_redova_brojac=0,broj_kolona_brojac=0,sirina_kolone_brojac=0;
	printf("Unesite broj redova: ");
	scanf("%d",&broj_redova);
	printf("Unesite broj kolona: ");
	scanf("%d",&broj_kolona);
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina_kolone);
	
	if(broj_redova<=10 && broj_redova>0 && broj_kolona<=10 && broj_kolona>0 && sirina_kolone<=10 && sirina_kolone>0){
		  
	  do{
	  	broj_redova_brojac++;
	  	do{
	  		printf("+");
	  		broj_kolona_brojac++;
	      do{
	      	 printf("-");
	      	 sirina_kolone_brojac++;
	      }while(sirina_kolone_brojac<sirina_kolone);
	         sirina_kolone_brojac=0;
	         
	  	}while (broj_kolona_brojac<broj_kolona);
	  	  broj_kolona_brojac=0;
	  	  printf("+\n");
	  	  do{
	  	  	printf("|");
	  	  	broj_kolona_brojac++;
	  	  	do{
	  	  		printf(" ");
	  	  		sirina_kolone_brojac++;
	  	  	}while (sirina_kolone_brojac<sirina_kolone);
	  	  	    sirina_kolone_brojac=0;
	  	  	    
	  	  }while (broj_kolona_brojac<broj_kolona);
	  	     printf("|\n");
	  	     broj_kolona_brojac=0;
	  	 
	  } while (broj_redova_brojac<broj_redova);
	   
	   
	   do{
	  		printf("+");
	  		broj_kolona_brojac++;
	      do{
	      	 printf("-");
	      	 sirina_kolone_brojac++;
	      }while(sirina_kolone_brojac<sirina_kolone);
	         sirina_kolone_brojac=0;
	         
	  	}while (broj_kolona_brojac<broj_kolona);
	  	  printf("+\n");
	  	  
	} 
	
	    	
	  return 0;
}
