#include <stdio.h>

int main() {
	int a[100], b1[1000], b[1000], br=0, br3=0, br1[1000], c[1000], d=0, i=0, j=0,k=0,l=0,m=0;
	for(i=0,m=0; i<1000, m<100; i++, m++){
		a[m]=0;
		b1[i]=0;
		b[i]=-1;
		br1[i]=0;
		c[i]=0;
	}
	printf("Unesite velicinu niza: ");
	scanf("%d", &d);
	printf("Unesite clanove niza: ");
	for(i=0; i<d; i++){
		do{
			scanf("%d", &a[i]);
		}while(a[i]<0);
	}
	for(i=0; i<d; i++){
		l=j;
		do{
			b1[j]=a[i]%10;
			j++;
			a[i]=a[i]/10;
		}while(a[i]>0);
		for(k=j-1, m=l; k>=l, m<j; k--,m++){
			b[m]=b1[k];
		}
	}
	br=j;
	for(i=0, m=0; i<br, m<2*br; i++, m++){
		for(j=i; j<br; j++){
			if(b[i]==b[j]){
				br1[i]++;
				if(b[i]!=b[j+1]){
					br3++;
					break;
				}
				
			}
		}
		c[m]=b[i];
		m++;
		c[m]=br1[i];
		i=i+br1[i]-1;
		
	}
	printf("Finalni niz glasi:\n");
	for(i=0; i<2*br3-1; i++){
		printf("%d ", c[i]);
	}
	printf("%d", c[2*br3-1]);
	return 0;
}
