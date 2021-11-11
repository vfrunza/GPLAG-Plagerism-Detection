#include <stdio.h>


int dva_od_tri(int *prvi,int broj1, int *drugi, int broj2, int *treci,int broj3) {
	
int i,j,k=0;
int pomocni[1000]={0};
	
	for(i=0;i<broj1;i++) {             ///u prvom i drugom nizu
		
		for( j=0;j<broj2;j++) {
		
		if(prvi[i]==drugi[j])
		
		{
         pomocni[k]=prvi[i];
         k++;
		}
		
		}
	}

for( i=0;i<broj1;i++) {             ///u prvom i trecem nizu
		
		for( j=0;j<broj3;j++) {
		
		if(prvi[i]==treci[j])
		
		{
         pomocni[k]=prvi[i];
         k++;
		}
		
		}
	}
	
	
	
	for( i=0;i<broj2;i++) {             ///u drugom i trecem nizu
		
		for( j=0;j<broj3;j++) {
		
		if(drugi[i]==treci[j])
		
		{
         pomocni[k]=drugi[i];
         k++;
		}
		
		}
	}
	

	int brojac=0;
	int z=0;
for(i=0;i<k;i++) {
	
	for(j=i+1;j<k;j++) {
	
	if(pomocni[i]==pomocni[j]) {
		brojac++;
	}
	
	}
	
	if(brojac==1)
		z++;
	brojac=0;
}



	
	return z;

}



int main() {


	return 0;
}
