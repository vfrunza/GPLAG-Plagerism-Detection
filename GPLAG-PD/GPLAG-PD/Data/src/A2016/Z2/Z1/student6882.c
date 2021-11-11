#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main() {
 int n,cifra1,cifra2;

 int novi_broj=0;
 printf ("Unesite broj: " );
 scanf ("%d",&n);
 n=abs(n);
 if (n>0 && n<9)
{ 
	printf ("0");
	return 0;
	
}
 /* if (n>0)
{
	 scanf ("%d",&n);
}
 
else if (n<0)
{
n=abs(n);
scanf ("%d",&n);
}
printf ("\n");
if (n>0 && n<9)
{ 
	printf ("0");
	
}*/ 
int i=0;
while (n>10)
{ 
int m=0;
cifra1=n%10;
	n/=10;
 cifra2=n%10;

 m=abs(cifra1-cifra2);
 m*=pow(10,i);
 novi_broj+=m;
i++;

}

printf ("%d",novi_broj);


	return 0;
}
