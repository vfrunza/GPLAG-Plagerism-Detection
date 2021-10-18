#include <stdio.h>
 
int dva_od_tri(int niz1[], int duz1, int niz2[], int duz2, int niz3[], int duz3){
	int i, j, k, l;
	int brojac=0;
	
	for (i=0; i<duz1; i++){
		for (j=0; j<i; j++){
			if (niz1[i]==niz1[j] && i!=j){
				break;
			}
		}
		
			if (i==j){
			
				for (k=0; k<duz2; k++){
					if (niz1[i]==niz2[k]){
						for (l=0; l<duz3; l++)//{
							if (niz2[k]==niz3[l]) break;
							if (l==duz3){
								brojac++;
								break;
							}
						
					}
				}
			}
		
	}
	
		for (i=0; i<duz2; i++){
			
		for (j=0; j<i; j++){
			if (niz2[i]==niz2[j] && i!=j){
			break;
			}
		}
			if (i==j){
					
				for (k=0; k<duz3; k++){
					if (niz2[i]==niz3[k]){
						for (l=0; l<duz1; l++)
							if (niz3[k]==niz1[l]) break;
							if (l==duz1){
								brojac++;
							break;
							}
						
					}
				}
			}
		
	}
	
		for (i=0; i<duz3; i++){
				
		for (j=0; j<i; j++){
			if (niz3[i]==niz3[j] && i!=j){
				break;
			}
		}
			if (i==j){
			
				for (k=0; k<duz1; k++){
					if (niz3[i]==niz1[k]){
						for (l=0; l<duz2; l++)
							if (niz1[k]==niz2[l]) break;
							if (l==duz2){
								brojac++;
								break;
							}
						
					}
				}
			}
		}
	
        return brojac;
}
   
        
        



	int main(){

        	return 0;
        }