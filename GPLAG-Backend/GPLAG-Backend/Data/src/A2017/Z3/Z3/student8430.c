#include <stdio.h>
#include <math.h>

int ispravno_dva( int *b,  int velb){
	int er1=0,er2=0,i,j;
	for(i=0;i<velb;i++){
		if(b[i]<0 || b[i]>9) er1++;
	}
	for(i=0;i<velb-1;i++){
		for(j=i+1;j<velb;j++){
			if(b[i]==b[j]) er2++;
		}
	}
	if(er1!=0 || er2!=0  ) return 0;
	else return 1;
}

int moze_bacat(int broj1, int sta){
	int kontrola=0,temp=fabs(broj1);
	while(temp!=0){
		if(temp%10==sta) kontrola++;
		temp/=10;
	}
	if(kontrola>0) return 1;
	else return 0;
}

int bacaj(int broj, int sta){
	int pro[1000]={0},temp=fabs(broj),i=0,novi=0,j,n;
	while(temp!=0){
		pro[i++]=temp%10;
		temp/=10;
	}
	 n=i;
	for(i=0;i<n;i++){
		if(pro[i]==sta){
			for(j=i;j<n-1;j++){
				pro[j]=pro[j+1];
			}n--;
			i--;}
		}
		for(i=0;i<n;i++){
			novi+=(pro[i]*pow(10,i));
		}
	
		
		if(broj>0) return novi;
		else return (-novi);
	}
	
	int izbaci_cifre(int *a, int vela,  int *b, int velb){
		int i,j,nvelb=velb;
		for(i=0;i<vela;i++){
			for(j=0;j<velb;j++){
				if(moze_bacat(a[i],b[j])){
					a[i]=bacaj((a[i]),b[j]);
				}
			}
		}
	return ispravno_dva(b,nvelb);
	}
	


int main() {
	int brojevi[] = {123, 456};
	int cifre3[]={0,1,2,3,4,5,6,7,8,9,0,1,2,3,4};
	int  rez;
	rez = izbaci_cifre(brojevi, 2, cifre3, 10);
	printf("%d\n", rez);
	return 0;
}
