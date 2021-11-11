#include <stdio.h>
#include <math.h>
#define BROJ_EL 100
#define BROJ_EL2 1000
int main() {
	int niz[BROJ_EL],niz2[BROJ_EL2],niz3[BROJ_EL2],i=0,j=0,k=0,br=0,m=0,s=0,n;
	float a,b;
	
do{
	printf("Unesite velicinu niza: ");
	scanf("%f",&b);
} while(b<=0 || b>100 || (ceil)(b)!=b);
n=b;

	printf("Unesite clanove niza: ");
for(i=0;i<n;i++){

	scanf("%f",&a);
	     if(a<0 || (ceil)(a)!=a)
	     {
	     	i--;
	     }
	     else niz[i]=a;
}
for(i=0;i<n;i++)
{
	br=0;
	do{
		niz2[s]=niz[i]%10;
		niz[i]=niz[i]/10;
		br++;
		s++;
	} while(niz[i]);
	
	j=s-1;
	
	for(k=s-br;k<s;k++)
	{
		niz3[j]=niz2[k];
		j--;
		
	}
	
}

for(i=0;i<s;i++){
	br=0;
	j=i;
	while(niz3[i]==niz3[j]){
		j++;
		br++;
		if(j==s) break;
	}
	i=i+br-1;
	niz2[m]=niz3[i];
	niz2[m+1]=br;
	m=m+2;
	
}
printf("Finalni niz glasi:\n");

for(i=0;i<m;i++){
	printf("%-2d",niz2[i]);
}
	
	
return 0;
}
