#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool da_li_se_ponavljaju(int niz2[],int vel2){
	int n_niz[100];
	int i;
	for(i=0;i<vel2;i++){
		n_niz[i]=niz2[i];
	}
	int j;
	int temp;
	for(i=0;i<vel2-1;i++){
		for(j=0;j<vel2-i-1;j++){
			if(n_niz[j]>n_niz[j+1]){
				temp=n_niz[j+1];
				n_niz[j+1]=n_niz[j];
				n_niz[j]=temp;
			}
		}
	}
	for(i=0;i<vel2-1;i++){	
	 	if(n_niz[i]==n_niz[i+1]){
	 	   return true;
	 	}
	}
	return false;
}
bool  izbaci_cifre(int niz1[],int vel1,int niz2[],int vel2){
	int i,j;
	bool da_li_je_neg=false;
	for(i=0;i<vel2;i++){
		if (niz2[i]<0|| niz2[i]>9) return false;
	}
	if(da_li_se_ponavljaju(niz2,vel2)) return false;
	for(i=0;i<vel1;i++){
		da_li_je_neg=false;
		if (niz1[i]<0) {
			da_li_je_neg=true;
		    niz1[i]*=-1;
		}
		int okrenuti;
		int cifra_o;
		int cifra;
		int n_broj=0;
		bool da_li_se_pojavila;
		while (niz1[i]!=0) {
			da_li_se_pojavila=false;
			cifra=niz1[i]%10;
	
		
			for(j=0;j<vel2;j++){
				
				if (niz2[j]==cifra) {
					da_li_se_pojavila=true;
				} 
			}
			if(da_li_se_pojavila){
				 niz1[i]=niz1[i]/10;
				 continue;
			}
			else{
				n_broj=n_broj*10+cifra;
			}
			niz1[i]=niz1[i]/10;
		}
	
		okrenuti=0;
	
		
		while(n_broj!=0) {
			cifra_o=n_broj%10;
			okrenuti=okrenuti*10+cifra_o;
			n_broj=n_broj/10;
		}
		if(da_li_je_neg)
		   okrenuti= okrenuti*-1;
		   niz1[i]=okrenuti;
    }
 return true;
 
}
int main() {
	int i;
	int brojevi[]={12345,-12345};
	int cifre[]={0,1,2,3,4,5,6,7,8,9,0,1,2,3,4};

izbaci_cifre(brojevi,2,cifre,10);
for(i = 0 ; i < 2; i++)
	printf("%d ", brojevi[i]);

	return 0;
}
