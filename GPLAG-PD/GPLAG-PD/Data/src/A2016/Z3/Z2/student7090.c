#include <stdio.h>
#include <math.h>
void ubaci(int *a, int velicina){
	int k,S,pom,l;
	for(k=0;k<2*velicina;k++){
		S=0;
		pom=a[k];
		if (pom<0)
		pom=pom*(-1);
		while(pom!=0){
			S=S+pom%10;
			pom=pom/10;
		}
		for (l=(2*velicina)-1;l>k;l--){
			a[l]=a[l-1];
		}
		k++;
		a[k]=S;
	}
}
int JelFibonacijev(int y){
	int pr=1;
	int dr=1;
	int zbir=pr+dr;
	if (y==1)
	return 1;
	if (y<1)
	return 0;
	while (zbir<=y){
		if(zbir==y)
		return 1;
		pr=dr;
		dr=zbir;
		zbir=pr+dr;
	}
	return 0;
}
int izbaci(int *a, int velicina){
	int k,l,y,pr,dr,zbir;
	for(k=0;k<velicina;k++){
		y=0;
		pr=1;
		dr=1;
		zbir=pr+dr;
		if (a[k]==1)
		y=1;
		else if (a[k]<1)
		y=0;
		else while (zbir<=a[k]){
			if(zbir==a[k])
			y=1;
			pr=dr;
			dr=zbir;
			zbir=pr+dr;
		}
		if(y){
			for(l=k;l<velicina-1;l++)
			a[l]=a[l+1];
			velicina--;
			k--;
		}
	}
	return velicina;
}
int main() {
	int velicina,k;
	int a[20];
	printf("Unesite niz od 10 brojeva: ");
	for(k=0;k<10;k++){
		scanf("%d",&a[k]);
	}
	ubaci(a,10);
	velicina=izbaci(a,10*2);
	printf("Modificirani niz glasi: ");
	for(k=0;k<velicina;k++)
		if(k==velicina-1)
		printf("%d. ",a[k]);
		else printf("%d, ",a[k]);
	return 0;
}
