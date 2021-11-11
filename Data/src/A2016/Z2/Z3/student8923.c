#include <stdio.h>
#define MAX 20
#define GRAN 19
#define MIN 0

int main() {
	int p,q,num,Ox,Oy;
	char N[MAX][MAX];
	
	/*inicijalizacija matrice*/
	for(p=0;p<MAX;p++){
		for(q=0;q<MAX;q++){
			N[p][q]=0;
		}
	}
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &num);
		if(num<=MIN || num>=11)
		  printf("Pogresan unos\n");
	}while(num<=MIN || num>=11);
	
	for(p=1;p<=num;p++){
		printf("Unesite %d. tacku: ", p);
		scanf("%d %d", &Ox,&Oy);
		if(Ox<MIN || Oy<MIN || Ox>GRAN || Oy>GRAN){
			printf("Pogresan unos\n");
			/*brojac smanji za jedan i ponovi unos*/
			p--;
		}else{
			/*postavlja zvjezdicu na unesene koordinate*/
		   N[Ox][Oy]='*';
		}
	}
	
	for(p=0;p<MAX;p++){
		for(q=0;q<MAX;q++){
			/*provjera da li se na tom mjestu [q][p] nalazi zvjezdica*/
			if(N[q][p]=='*')
			    /*ako se nalazi ispisi char(zvjezdicu) koja je pridruzena koordinatama*/
				printf("%c",N[Ox][Oy]);
		    else
		    /*u protivnom ispisi razmak*/
		        printf(" ");
		}
		printf("\n");
	}
	return 0;
}
