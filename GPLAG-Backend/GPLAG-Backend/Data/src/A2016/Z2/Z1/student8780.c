#include <stdio.h>
#include <math.h>

int main() {
	
	int a,c,d,i,p,e,g,f,b,l,m,n,s,h,j,k,z,o,t,u,v;

	int brojac=0;
	printf ("Unesite broj: ");
	scanf ("%d",&a);
	


p=a;	
do
{
	c=a%10;
	
   brojac = brojac+1;
   
  a=(a/10);
  

 l=0; 

}while (a!=0);

if (brojac==1){printf ("0");return 0;}
		

for (i=0;i<brojac;i++)
{
c=p%10;
b=(p/10)%10;


if (c==0){f=c*pow(10,brojac-1-i);}

else {	f=(c*(pow(10,brojac-1-i)));}
	
	
p=p/10;
h=f+l;

l=h;

}k=0; g=0;
for (j=0;j<brojac-1;j++)
{
	e=h%10;
	m=(h/10)%10;
	
	s=fabs(e-m);

	z=s*((pow(10,brojac-2-j)))
	;
g=z+k;
k=g;


	h=h/10;
	

	
} printf ("%d",k);
 
 
 
	return 0;
}
