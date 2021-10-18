#include <stdio.h>
int dva_od_tri(int niz1[], int velicina1, int niz2[], int velicina2, int niz3[], int velicina3)
{
	int i, j, k=0, m, novi_niz[100], nizA[1000], nizB[1000], nizC[1000], a=0, b=0, c=0, t, u, v;
	
	for(i=0; i<velicina3; i++){
		for(j=0; j<velicina1; j++){
			if(niz3[i]==niz1[j]){
				nizA[a]=niz3[i];
				a++;
			}
		}
	}
	
	for(i=0; i<velicina2; i++){
		for(j=0; j<velicina3; j++){
			if(niz2[i]==niz3[j]){
				nizB[b]=niz2[i];
				b++;
			}
		}
	}
	
	for(i=0; i<velicina1; i++){
		for(j=0; j<velicina2; j++){
			if(niz1[i]==niz2[j]){
				nizC[c]=niz1[i];
				c++;
			}
		}
	}
	
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){
			if(nizA[i]<nizA[j]){
				t=nizA[i];
				nizA[i]=nizA[j];
				nizA[j]=t;
			}
		}
	}
	
	for(i=0; i<b; i++){
		for(j=0; j<b; j++){
			if(nizB[i]<nizB[j]){
				u=nizB[i];
				nizB[i]=nizB[j];
				nizB[j]=u;
			}
		}
	}
	
	for(i=0; i<c; i++){
		for(j=0; j<c; j++){
			if(nizC[i]<nizC[j]){
				v=nizC[i];
				nizC[i]=nizC[j];
				nizC[j]=v;
			}
		}
	}
	
	for(i=0; i<a;i++){
		for(j=i+1; j<a; j++){
			if(nizA[i]==nizA[j]){
				nizA[j]=nizA[a-1];
				a--;
				j--;
			}
		}
	}
	
	for(i=0; i<b; i++){
		for(j=i+1; j<b; j++){
			if(nizB[i]==nizB[j]){
				nizB[j]=nizB[b-1];
				b--;
				j--;
			}
			
		}
	}
	
	for(i=0; i<c; i++){
		for(j=i+1; j<c; j++){
			if(nizC[i]==nizC[j]){
				nizC[j]=nizC[j-1];
				c--;
				j--;
			}
		}
	}
	
	for(i=0; i<a; i++){
		for(j=0; j<b; j++){
			if(nizA[i]==nizB[j]){
				novi_niz[k]=nizA[i];
				k++;
			}
		}
	}
	
	for(i=0; i<k; i++){
		for(j=0; j<a; j++){
		if(novi_niz[i]==nizA[j]){
			nizA[j]=nizA[a-1];
		
			a--;
		j--;
		}
		}
	}
	
	for(i=0; i<k; i++){
		for(j=0; j<b; j++){
		if(novi_niz[i]==nizB[j]){
			nizB[j]=nizB[b-1];
		
				b--;
		j--;
		}
		}
	}
	
	for(i=0; i<k; i++){
		for(j=0; j<c; j++){
		if(novi_niz[i]==nizC[j]){
			nizC[j]=nizC[c-1];
		
					c--;
		j--;
		}
		}

	}
	
	m=a+b+c;
	return m;
}


int main() {
	int niz1[100], niz2[100], niz3[100];
	int n1, n2, n3, i;
	
	printf("Unesite velicinu niza 1: ");
	scanf("%d", &n1);
	printf("Unesite elemente niza 1: ");
	for(i=0; i<n1; i++){
		scanf("%d", &niz1[i]);
	}
	
	printf("Unesite velicinu niza 2: ");
	scanf("%d", &n2);
	printf("Unesite elemente niza 2: ");
	for(i=0; i<n2; i++){
		scanf("%d", &niz2[i]);
	}
	
	printf("Unesite velicinu niza 3: ");
	scanf("%d", &n3);
	printf("Unesite elemente niza 3: ");
	for(i=0; i<n3; i++){
		scanf("%d", &niz3[i]);
	}
	
	printf("%d", dva_od_tri(niz1,n1,niz2,n2,niz3,n3));
	
	return 0;
}
