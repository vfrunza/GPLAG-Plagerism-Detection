#include <stdio.h>


void ubaci(int niz[], int n){
	int i,j,x,y=0,niz2[10],niz_1[10],temp=0;
	for(i=0;i<n;i++){
		if(niz[i]<0){
			return 0;
		}
	}
	
	for(i=0;i<n;i++){
		niz_1[i]=niz[i];
	}
	for(i=0;i<n;i++){
		temp=niz[i];
		y=0;
		while(temp!=0){
			x=temp%10;
			y+=x;
			temp=temp/10;
		}
		niz2[i]=y;
	}
	
	
	for(i=0;i<n;i++){
		niz[2*i]=niz_1[i];
		niz[2*i+1]=niz2[i];
		
	}
	
	
}

int izbaci(int niz[], int n){
	
	int niz_f[45],i,prvi=0,drugi=1,sljedeci,j,k;

	for(i=0;i<45;i++){
		if(i==1){
			sljedeci=i;
		} 
		else{
			sljedeci=prvi+drugi;
			prvi=drugi;
			drugi=sljedeci;
		}
		niz_f[i]=sljedeci;
	}
	for(i=0;i<n;i++){
		for(j=0;j<45;j++)
		if(niz[i]==niz_f[j]){
			niz[i]=0;
		}
		
	}
	
	for(i=0;i<n;i++){
		if(niz[i]<0){
			niz[i]=niz[i];
		}
	}
	
	for(i=0;i<n;i++){
		if(niz[i]==0){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	return n;
	
}



int main() {
	int i,k ,niz[20], n, niz3[40],s,d,j,zbroj=0,brojac2=0;
	n=20;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
		
	}
	

	
	
	
	ubaci(niz,i);

	
	k=izbaci(niz,i);

	printf("Modificirani niz glasi: ");
	for(i=0;i<k ;i++){
		if(i<k-1)
		printf("%d, ", niz[i]);
		if(i==k-1){
			printf("%d.", niz[i]);
		}
	}
	
	
	return 0;
}
