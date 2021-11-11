#include <stdio.h>
#include <math.h>

int izbaci_cifre(int brojevi[],int m,int cifre[],int n){
	int i,j,b,k;
	int a;
	int temp[100];
    int logicka=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
		if(cifre[i]==cifre[j]) return logicka;
	}
	}
	for(i=0;i<n;i++)
	if(cifre[i]<0 || cifre[i]>9) return logicka;
	
		for(i=0;i<m;i++)
	temp[i]=fabs(brojevi[i]);
	for(i=0;i<m;i++){
		b=0;
		k=1;
		while(temp[i]>0){
			for(j=0;j<n;j++){
				if(temp[i]%10==cifre[j]){a=cifre[j]; break;}
			}
				if(temp[i]%10==a){
					b=b;
					temp[i]/=10;
				}
			else {
				b=b+(temp[i]%10)*k;
				k*=10;
				temp[i]/=10;
			}
			
		}
		if(brojevi[i]<0){
		brojevi[i]=(-1)*b;
		}
		else{ brojevi[i]=b;}
	}
	return 1;
}


int main() {
int m,n,i;
int brojevi[100],cifre[100];
scanf("%d%d",&m,&n);
for(i=0;i<m;i++)
scanf("%d",&brojevi[i]);
for(i=0;i<n;i++)
scanf("%d",&cifre[i]);
izbaci_cifre(brojevi,m,cifre,n);
for(i=0;i<m;i++)
printf("%d ",brojevi[i]);
	return 0;
}
