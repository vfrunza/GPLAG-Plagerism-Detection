#include <stdio.h>


int dva_od_tri(int niz1[], int br1, int niz2[], int br2, int niz3[], int br3){
	int i,j,k,glavni=0,sporedni;
	
	for(i=0;i<br1;i++){
		for(j=i+1;j<br1;j++){
			if(niz1[i]==niz1[j]){
				niz1[j]=niz1[br1-1];
				br1--;
				j--;
			}
		}
	}
	for(i=0;i<br2;i++){
		for(j=i+1;j<br2;j++){
			if(niz2[i]==niz2[j]){
				niz2[j]=niz2[br2-1];
				br2--;
				j--;
			}
		}
	} 
	for(i=0;i<br3;i++){
		for(j=i+1;j<br3;j++){
			if(niz3[i]==niz3[j]){
				niz3[j]=niz3[br3-1];
				br3--;
				j--;
			}
		}
	}
	
	if(br1==0){
		for(i=0;i<br2;i++){
			for(j=0;j<br3;j++){
				if(niz2[i]==niz3[j])
					glavni++;
			}
		}
	}
	else if(br2==0){
		for(i=0;i<br1;i++){
			for(j=0;j<br3;j++){
				if(niz1[i]==niz3[j])
					glavni++;
			}
		}
	}
	else if(br3==0){
		for(i=0;i<br1;i++){
			for(j=0;j<br2;j++){
				if(niz1[i]==niz2[j])
					glavni++;
			}
		}
	}
	else{
		for(i=0;i<br1;i++){
			for(j=0;j<br2;j++){
				sporedni=0;
				if(niz1[i]==niz2[j]){
					for(k=0;k<br3;k++){
						if(niz3[k]==niz1[i])
							break;
						else
							sporedni++;
					}
				}
				if(sporedni==br3)
					glavni++;
			}
		}
		for(i=0;i<br1;i++){
			for(j=0;j<br3;j++){
				sporedni=0;
				if(niz1[i]==niz3[j]){
					for(k=0;k<br2;k++){
						if(niz2[k]==niz1[i])
							break;
						else	
							sporedni++;
						
					}
				}
				if(sporedni==br2)
					glavni++;
			}
		}
		for(i=0;i<br2;i++){
			for(j=0;j<br3;j++){
				sporedni=0;
				if(niz2[i]==niz3[j]){
					for(k=0;k<br1;k++){
						if(niz1[k]==niz2[i])
							break;
						else 
							sporedni++;
					}
				}
				if(sporedni==br1)
					glavni++;
			}
		}
	}
	return glavni;
}
int main() {
	
	return 0;
}
