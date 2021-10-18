#include <stdio.h>

//funkcija koja vraca sljedeci prost broj
int daj_prost(){
	
	int i,prost=1;
	
	//postavljamo broj na 1 jer cemo je odma uvecati i 2 ce biti prvi prost broj
	static int broj=1;
	broj++;
	
	for(i=2;i<broj;i++){
		if(broj%i==0){
			prost = 0;
			break;
		}
	}
	
	//ako je broj prosto vratimo ga ako nije zovemo rekurzivno fju
	if(prost==1){
		return broj;
	}else{
		return daj_prost();
	}
	
}

int main() {
	
	int A,B,suma=0,i,clan;
	
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
	
		if(A>=B){
			printf("A nije manje od B.\n");
		}else if((A<=0 && B<=0) || A<=0){
			printf("A nije prirodan broj.\n");
		}else if(B<=0){
			printf("B nije prirodan broj.\n");
		} 
		
	}while(A>=B || A<=0 || B<=0);
	
	//beskonacna petlja koju cemo prekinuti samo ako fja vrati broj koji je >=B
	while(1){
		
		clan = daj_prost();
		
		if(clan > A && clan < B){
			suma += clan;
		}
		
		if(clan >=B){
			break;
		}
		
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}



/* mogli smo i ovako napisati uslov gore direktno u prvoj while petlji
		else{
			for(i=0;i<B;i++){
				clan = daj_prost();
				if(clan>A && clan<B){
					suma+=clan;
				}
			}
		}
		*/
