#include <stdio.h>


int dva_od_tri(int a[], int vel1, int b[], int vel2, int c[], int vel3){
	int i, j, s=0, l=0;
	int k[1000], p[1000]={0};
	
	for(i=0; i<vel1; i++){
		l=0;
		for(j=0; j<s; j++){
			if(k[j]==a[i])
			{
				l=1;
				break;
			}
		}
		if(l==0){
			k[s]=a[i];
			s++;
		}
	}
	
	for(i=0; i<vel2; i++){
		l=0;
		for(j=0; j<s; j++){
			if(k[j]==b[i]){
				l=1;
				break;
			}
		}
		if(l==0){
			k[s]=b[i];
			s++;
		}
	}
	
	
	for(i=0; i<vel3; i++){
		l=0;
		for(j=0; j<s; j++){
			if(k[j]==c[i]){
				l=1; 
				break;
			}
		}
		if(l==0){
			k[s]=c[i];
			s++;
		}
	}
	
	
	for(i=0; i<s; i++){
		for(j=0; j<vel1; j++){
			if(a[j]==k[i]){
				p[i]++;
				break;
			}
		}
	}
	
	for(i=0; i<s; i++){
		for(j=0; j<vel2; j++){
			if(b[j]==k[i]){
				p[i]++;
				break;
			}
		}
	}
	
	for(i=0; i<s; i++){
		for(j=0; j<vel3; j++){
			if(c[j]==k[i]){
				p[i]++;
				break;
			}
		}
	}
	
	int v=0;
	for(i=0; i<s; i++){
		if(p[i]==2)
		v++;
	}
	return v;
}


int main() {
	int niz1[]={1, 2, 3, 5};
	int niz2[]={1, 2, 4, 6, 7};
	int niz3[]={1, 3, 4, 8, 9, 10};
	int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
	printf("%d", rez);
	return 0;
}
