#include <stdio.h>

	int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
		int i,j,k,l;
		int br;
		int rez=0;
		for(i=0;i<vel1;i++){
			br=1;
			
			for(l=i+1;l<vel1;l++){
				if(niz1[i]==niz1[l]) i++;
			}
			
			
			for(k=0;k<vel2;k++){
				
				for(l=k+1;l<vel2;l++){
					if(niz2[k]==niz2[l]) k++;
				}
				
				if(niz1[i]==niz2[k]) br++;
				
			}
			
			for(j=0;j<vel3;j++){
				
				for(l=j+1;l<vel3;l++){
					if(niz3[j]==niz3[l]) j++;
				}
				
				if(niz1[i]==niz3[j]) br++;
				
			}
			if(br==2) rez++;
			
		}
		
		
		
		for(i=0;i<vel3;i++){
			br=1;
			
			for(l=i+1;l<vel3;l++){
				if(niz3[i]==niz3[l]) i++;
			}
			
			
			for(k=0;k<vel2;k++){
				
				for(l=k+1;l<vel2;l++){
					if(niz2[k]==niz2[l]) k++;
				}
				
				if(niz3[i]==niz2[k]) br++;
				
			}
			
			for(j=0;j<vel1;j++){
				
				for(l=j+1;l<vel1;l++){
					if(niz1[j]==niz1[l]) j++;
				}
				
				if(niz3[i]==niz1[j]) br++;
				
			}
			if(br==2) rez++;
			
		}
		
		
		
		
		for(i=0;i<vel2;i++){
			br=1;
			
			for(l=i+1;l<vel2;l++){
				if(niz2[i]==niz2[l]) i++;
			}
			
			
			for(k=0;k<vel1;k++){
				
				for(l=k+1;l<vel1;l++){
					if(niz1[k]==niz1[l]) k++;
				}
				
				if(niz2[i]==niz1[k]) br++;
				
			}
			
			for(j=0;j<vel3;j++){
				
				for(l=j+1;l<vel3;l++){
					if(niz3[j]==niz3[l]) j++;
				}
				
				if(niz2[i]==niz3[j]) br++;
				
			}
			if(br==2) rez++;
			
		}
		
		return rez/2;
	}

int main() {

	
	return 0;
}
