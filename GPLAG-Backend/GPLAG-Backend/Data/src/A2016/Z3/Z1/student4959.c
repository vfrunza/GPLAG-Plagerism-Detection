#include <stdio.h>
#include <math.h>
 int daj_prost1(int prost)
{

 int b=0,i;

	for(i=2;i<prost;i++){
		if(prost%i==0) b++;
	}
	if(b==0)  return 1;
	else return 0;
	
   }
int daj_prost()
{ static int s=1;
int i=s+1;
	while(!daj_prost1(i)){
		i++;
	}
	s=i;
	return i;
}
int main() {
	int a,b,suma=0,i;
	t:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a<=0) {printf("A nije prirodan broj.\n");
	goto t;}
	else if(a>b || a==b ) { printf("A nije manje od B.\n");
	goto t;
	}
	for(i=a+1;i<b;i++){
		if(daj_prost1(i)==1) suma+=i;
		else continue;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
