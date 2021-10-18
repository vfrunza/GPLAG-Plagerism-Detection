#include <stdio.h>
int daj_prost(){
	static int prost=2, i=2;
	int br=0,j;
	for(;;){
		for(j=2;j<i;j++)
		if(i%j!=0)br++;
		if(i-2==br){
			prost=i;
			i++;
			br++;
			break;
		}
		i++;
		br=0;
	}
	return prost;
}
int main(){
	int a, b, sum=0, k;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	if(a==0 || a<0)
    printf("A nije prirodan broj.\n");
	else if(a>b)
	printf("A nije manje od B.\n");
	else if(a==b)
	printf("A nije manje od B.\n");
	else if(a>0 && b<=0)
	printf("A nije manje od B.\n");
	while(a>b || a==0 || a<0 || a==b);
	do{
		k=daj_prost();
		if(k>a && k<b)
		sum+=k;
	}
	while(k<b);
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, sum);
	return 0;
}
