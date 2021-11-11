#include <stdio.h>


int izbaci_cifre(int x[],int vel1,int y[],int vel2){
	int i,j,p=0,temp,faktor,out;
	for(j=0;j<vel2;++j){
		if(y[j]<0||y[j]>9)
		 return 0;
		for(i=j+1;i<vel2;++i){
		if(y[i]==y[j])
			return 0;
	}
}
	for(i=0;i<vel1;++i){
		for(j=0;j<vel2;++j){
			p=x[i];
			faktor=1;
			out=0;
			temp=0;
		do{  /*ovdje ti kontinualno poredi sve cifre tekuceg integera 
		sa tekucom cifrom drugog niza */ 
		temp=p%10;
		if(temp<=0){
		temp*=-1;	
		}
		if(temp!=y[j]){
			out+=faktor*temp;
			faktor*=10;
		}
		p/=10;
		}while(p!=0);
		if(x[i]<0){
			out*=-1;
		}
		x[i]=out;
		}
	}
return 1;	
}

int main(void) {
int brojevi[] = {12345, -12345};
int cifre[] = {3,5};
izbaci_cifre(brojevi, 2, cifre, 2);
printf("%d %d", brojevi[0], brojevi[1]);
	return 0;
}
