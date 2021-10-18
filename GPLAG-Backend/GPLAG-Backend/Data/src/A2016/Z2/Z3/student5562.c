#include <stdio.h>

int main() {
	
	int n, i, j, k;
	int x[10], y[10];
	int error = 0;

	
	do{ 
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		
		if (n < 1 || n > 10){
			printf("Pogresan unos\n");
		}
		
	} while (n < 1 || n > 10); //sve dok je unos nepravilan, trazi da se ponovo unese vrijednost
		
	
	
		
		for (i = 1; i <= n; i++){
			
			
			
			do{
				error = 0;
				
				printf("Unesite %d. tacku: ", i );
				
				scanf("%d %d", &x[i], &y[i]);
				
				if (x[i] < 0 || x[i] > 19 || y[i] < 0 || y[i] > 19 )
				{
					error = 1; //varijabla koje je 1 ako je unos nepravilan
					printf("Pogresan unos\n");
					
				}
			
			} while (error == 1); //sve dok je unos nepravilan, trazi da se ponovo unese vrijednost
			
		}
	
		
	 
		
		
	
	for (i = 0; i <= 19; i++){ //i i j ce proci kroz svaki moguci uredjeni  par (x, y)
		
		for(j = 0; j <= 19; j++){
			
			for(k = 1; k <= n; k++){ // petlja k sluzi da bi se proslo kroz sve unesene koordinate (x,y) i provjerilo da li se podudaraju sa koordinatama (j, i)
										
				if (i == y[k] && j == x[k]){ //ako postoji vise jednakih koordinata, bit ce ispisane samo jednom
					
					printf("*"); // ako se podudaraju koordinate, ispisi * i izlazi iz k petlje
					break;
					}
				
				else{
					
					if (k == n) // ako se ne podudaraju, i aKKo je petlja na kraju, ispisi razmak
						printf(" ");
				}
				
			}
				
		}
		
		printf("\n");
		
	}
	
	return 0;
}
