#include <stdio.h>

int main() {
	
	
	char a[20][20] ;
	int i,j ;
	int x,y;
	int pom1, pom2;
	char znak= '*';
	char prazno= ' ';
	int broj_tacaka;
	int tackex[10], tackey[10];
	
	for(i=0 ;i<20 ;i++) {
	for(j=0 ;j<20 ;j++) {
		a[i][j]= prazno ;
			}
	}
	
	/* unos broja tacaka*/
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&broj_tacaka);
		if(broj_tacaka<=0 || broj_tacaka>10){  
			printf("Pogresan unos \n");
			continue;
		}
		else break;
	} while(1);
	
	/* unos tacaka */
	for(i=0;i<broj_tacaka;i++){
		while(1){
				printf("Unesite %d. tacku: ",i+1);
				scanf("%d %d", &x, &y);
				if(x < 0 || x > 19 || y<0 || y>19){
					printf("Pogresan unos \n"); 
					continue;
				}
				else {
					tackex[i]=x; 
					tackey[i]=y;
					break;
				}
		}
	}
	/* tackex su x koordinate, a tackey su y koordinate tacaka */
	/* crtanje */
	
	for( i=0 ; i<broj_tacaka; i++){
		pom1= tackex[i];
		pom2= tackey[i];
		a[pom2][pom1]= znak;
	}
	
	/* ispis */
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	
	
	
	
    //for(i=0 ;i<5 ;i++)	{
	//scanf("%c %c",&n,&m) ;
	//a[m][n]= ˙*˙ ;
	//} 
	//for(i=0; i<20 ;i++)
     //      { printf("\n");
     //      for(j=0 ;j<20 ;j++) {
     //      	printf("%c",a[i][j]) ;
     //      }
           	
      //     }	

	return 0;
}
