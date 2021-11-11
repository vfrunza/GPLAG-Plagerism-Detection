#include <stdio.h>
int dva_od_tri(int *prvi_niz, int broj_elemenata1, int *drugi_niz, int broj_elemenata2, int *treci_niz, int broj_elemenata3){
	
	int i,j,k,br1=0,element1,element2,element3,br2=0,br3=0;
	int *h = drugi_niz,*l=treci_niz,*o=prvi_niz;
	
	// Pronalazimo koliko se koji clan puta ponavlja
	int globalni_brojac=0;
		
		// Provjera prvog niza sa ostala dva //
		for(i=0;i<broj_elemenata1;i++){
			
			for(j=0;j<broj_elemenata2;j++){
			element1=*prvi_niz;
			element2=*drugi_niz;
			
			if((element1)==(element2)){
			br1++;}
			drugi_niz++;
		}
		
			for(k=0;k<broj_elemenata3;k++){
			element3=*treci_niz;
				
				if((element1)==(element3)){
				br1++;}
				treci_niz++;
		}
		
		drugi_niz=h;
		treci_niz=l;
		
								
			
								
		
		
		
		if(br1==1)
		globalni_brojac++;
		br1=0;
		
	
prvi_niz++;}
			
				drugi_niz=h;
				treci_niz=l;
				prvi_niz=o;
					
			for(i=0;i<broj_elemenata2;i++){
				element2=*drugi_niz;
				for(j=0;j<broj_elemenata1;j++){
			element1=*prvi_niz;
					
				if((element1)==(element2)){
			br2++;}
			prvi_niz++;
		}
		
			for(k=0;k<broj_elemenata3;k++){
			
				element3=*treci_niz;
				if((element2)==(element3)){
				br2++;}
				treci_niz++;
		}
		
								
				treci_niz=l;
				prvi_niz=o;
								
		
		
		
		if(br2==1)
		globalni_brojac++;
		br2=0;
		
	
drugi_niz++;}

			
				treci_niz=l;
				drugi_niz=h;
				prvi_niz=o;
			
				
				for(i=0;i<broj_elemenata3;i++){
				element3=*treci_niz;
				for(j=0;j<broj_elemenata1;j++){
				element1=*prvi_niz;
					
				if((element1)==(element3))
			br3++;
			prvi_niz++;
		}
			for(k=0;k<broj_elemenata2;k++){
					element2=*drugi_niz;
				if((element2)==(element3))
				br3++;
				drugi_niz++;
		}
		
				drugi_niz=h;
				prvi_niz=o;	
		
		
		
		if(br3==1)
		globalni_brojac++;
		br3=0;
		
	
treci_niz++;}

return globalni_brojac/2;
}
int main() {
/* AT2: Rad sa praznim nizom */
int niz1[] = {1, 2, 3, 4};
int niz2[] = {2, 3, 4, 5};
int niz3[] = {3, 4, 5, 6};
int niz4[1];
int rez = dva_od_tri(niz1, 4, niz4, 0, niz3, 4);
printf("%d ", rez);
rez = dva_od_tri(niz4, 0, niz2, 4, niz3, 4);
printf("%d ", rez);
rez = dva_od_tri(niz1, 4, niz2, 4, niz3, 4);
printf("%d ", rez);
	return 0;
}
