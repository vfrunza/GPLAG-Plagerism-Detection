#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int izbrisi_duplikate(int niz[],int vel){
	
	
	int i=0,j=0,k=0,br=0,temp=vel;
	while(br<temp){
	for(i=0;i<vel;i++)
		for(j=i+1;j<vel;j++){
			if(niz[j]==niz[i]){
				for(k=j;k<vel-1;k++){
					niz[k]=niz[k+1];
				}
				vel--;
			}
			else j++;
			}
		
		br++;
		
	}
	return vel;
}
int dva_od_tri(int niz1[], int velicina1, int niz2[], int velicina2,int niz3[], int velicina3)
{
	
	int i,j,k,brojac=0;

	velicina1=izbrisi_duplikate(niz1,velicina1);
	velicina2=izbrisi_duplikate(niz2,velicina2);
	velicina3=izbrisi_duplikate(niz3,velicina3);

	/*1->2*/
	for(i = 0; i < velicina1; i++)
	{
		for(j=0;j<velicina2; j++)

			if(niz1[i]==niz2[j]){
			for(k=0;k<velicina3;k++)
				if(niz1[i]==niz3[k]){
					brojac--;
				}
				
				brojac++;
			}
	}
	/*1->3*/
	for(i = 0; i < velicina1; i++)
	{
		for(j=0;j<velicina3; j++)

			if(niz1[i]==niz3[j]){
			for(k=0;k<velicina2;k++)
				if(niz1[i]==niz2[k]){
					brojac--;
				}
				
				brojac++;
			}
	}
	/*2->3*/
	for(i = 0; i < velicina2; i++)
	{
		for(j=0;j<velicina3; j++)

			if(niz2[i]==niz3[j]){
			for(k=0;k<velicina1;k++)
				if(niz2[i]==niz1[k]){
					brojac--;
				
					if(brojac<0)return 0;
				}
				
				brojac++;
			}
	}
	
	
	
	return brojac;
}


int main() {
	
	int niz1[11]={2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, niz2[5]={3, 3, 3, 2, 2},niz3[3]={1,3,4},a;
	
	
	a = dva_od_tri(niz1,11,niz2,5,niz3,3);
	
	printf("Broj a je : %d",a);
	
	
	return 0;
}
