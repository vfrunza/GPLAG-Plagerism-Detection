#include <stdio.h>
#include <math.h>
#define BROJ_EL 200
#define E 0.0001

int main() {
	int i,j,sa,va,sb,vb;
	double a[BROJ_EL][BROJ_EL],b[BROJ_EL][BROJ_EL];
	printf("Unesite sirinu i visinu matrice A: ");
	do{
		scanf("%d %d",&sa,&va);
	}while(sa<0 || va<0 || sa>BROJ_EL ||va>BROJ_EL);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<va;i++)
	 for(j=0;j<sa;j++)
	 	scanf("%lf",&a[i][j]);
	 	
	 printf("Unesite sirinu i visinu matrice B: ");
	 	
	 	do{
	 		scanf("%d %d",&sb,&vb);
	 	}while(vb<0 || sb<0|| sb>BROJ_EL|| vb>BROJ_EL);
	 	printf("Unesite clanove matrice B: ");
	 	for(i=0;i<vb;i++)
	 		for(j=0;j<sb;j++)
	 			scanf("%lf",&b[i][j]);
	 	
	 	if(sa!=vb || va!=sb)
	 	{
	 	printf("NE");
	 	return 0;
	 	}
	 	
	 /*	for(i=0;i<vb;i++)
	 	 for(j=0;j<sb;j++)
	 	 if(fabs(b[i][j]-a[j][sa-1-i])>E)
	 	 {printf("NE");
	 	 return 0;}*/
	 	 for(i=0;i<va;i++)
	 	  for(j=0;j<sa;j++)
	 	  if(fabs(a[i][j]-b[j][sb-1-i])>E)
	 	  {
	 	  	printf("NE");
	 	  	return 0;
	 	  }
	 	 
	printf("DA");
	
	return 0;
}
