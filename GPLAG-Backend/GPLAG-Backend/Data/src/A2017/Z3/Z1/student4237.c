#include <stdio.h>

int dva_od_tri(int niz1[], int n1, int niz2[], int n2, int niz3[], int n3) {
	int i, j, k,l, br=0, br1=0, br2=0, bio=0,ukupno=0;

for(i=0;i<n1;i++) {
	for(l=0;l<i;l++){
		if(niz1[i]==niz1[l]){
			bio++;
		} 
	}
		if(bio==0){
			for(j=0;j<n2;j++){
				if(niz1[i]==niz2[j]) {
					br1++;
			  }
			}
			for(k=0;k<n3;k++){
				if(niz1[i]==niz3[k]) {
					br2++;
				}
			}
			
			if((br1>=1 && br2==0) || (br2>=1 && br1==0)){
				ukupno++;
			}
			br1=0;
			br2=0;
		}
		bio=0;
		
}
	for(i=0;i<n2;i++){
		for(j=0;j<n1;j++){
			if(niz1[j]==niz2[i]){
				br++;
			}
		}
			if(br==0) {
				for(l=0;l<i;l++){
					if(niz2[i]==niz2[l]){
						bio++;
					}
				}
				if(bio==0){
					for(k=0;k<n3;k++){
						if(niz2[i]==niz3[k]){
							br1++;
						}
						
					}
					if(br1>=1){
						ukupno++;
					}
					
				}
				br1=0;
			}
			bio=0;
			br=0;
		}


	return ukupno;
}

 int main (void) {
 int n1,n2,n3,niz1[100],niz2[100],niz3[100],br=0,i,rez;
 	
 		do {
	printf("Unesi n1: ");
	scanf("%d", &n1);
	} while (n1<=0 || n1>100);
	
		do {
	printf("Unesi n2: ");
    scanf("%d", &n2);
	} while (n2<=0 || n2>100);
	
		do {
	printf("Unesi n3: ");
    scanf("%d", &n3);
	} while (n3<=0 || n3>100);
	
	for(i=0;i<n1;i++){
printf("Unesite %d-ti clan niza: \n",i+1);
    scanf("%d",&niz1[i]);
}


	for(i=0;i<n2;i++){
printf("Unesite %d-ti clan niza: \n",i+1);
    scanf("%d",&niz2[i]);
   
}

	for(i=0;i<n3;i++){
printf("Unesite %d-ti clan niza: \n",i+1);
    scanf("%d",&niz3[i]);
 
}


rez=dva_od_tri(niz1, n1, niz2, n2, niz3, n3);
	printf("%d", br);
	
	
 return 0;	
 }
