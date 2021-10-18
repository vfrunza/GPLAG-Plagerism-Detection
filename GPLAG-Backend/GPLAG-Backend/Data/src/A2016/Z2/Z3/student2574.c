#include <stdio.h>

int main() {
int a[20];
int b[20];
int brojtacaka=0;
int i=0,j=0,k=0;
do
{
printf ("Unesite broj tacaka: ");
scanf ("%d",&brojtacaka);
if (brojtacaka>10 || brojtacaka<=0)
printf ("Pogresan unos\n");
}
while (brojtacaka<=0 || brojtacaka>10);
for (i=0;i<brojtacaka;i++)
{
	printf ("Unesite %d. tacku: ",i+1);
	scanf ("%d %d",&a[i],&b[i]);
	if ((a[i]<0 || a[i]>19) || (b[i]<0 || b[i]>19))
	{
		i=i-1;
	printf ("Pogresan unos\n");
	}
}
for (i=0;i<20;i++)
{
for (j=0;j<20;j++)
	{
		for (k=0;k<brojtacaka;k++)
		{ 
		if (j==a[k] && i==b[k])
		{
	printf ("*");
	break;}
		}
			if (brojtacaka==k)
	printf (" ");
        }
printf ("\n");}
		return 0;}
	