#include <stdio.h>
int daj_prost(){
	int k=0, i;
do{
	k=0;
static int n=2;
	for (i=2; i<n; i++)
	{
		if(n%i==0){
			k++;}
	}
	if (k==0)
	{
		n++;
		return n-1;}
	n++;}
while (k!=0);
}

int main() {
	int A,B,p=2,s,br;
	do{
	printf ("Unesite brojeve A i B: ");
	scanf ("%d%d", &A, &B);
	if (A>=B) printf ("A nije manje od B.\n");
	else if (A<1) printf ("A nije prirodan broj.\n");
	else if (B<1) printf ("B nije prirodan broj.\n");
	else break;}
	while (p<3);
	
	s=0;
	
br=daj_prost();

	while (br<B)
	{
		if (A<br&&br<B)
		s=s+br;
		br=daj_prost();
	}
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A, B, s);
	
	
	
	
	
	
	return 0;
}