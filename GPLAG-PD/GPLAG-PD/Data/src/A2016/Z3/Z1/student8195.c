#include <stdio.h>
#include <math.h>

int daj_prost(){
	static int n=1;
	int i,j,prost;
	j=0;
	while (j==0)
	{
		prost=-1;
		n++;
			if(n==2)
			{
				return 2;
			}
			for(i=0;i<n;i++){
				if((i!=n)&&(i!=1)&&(i!=0))
				{
					if(n%i==0)
					{
						prost=0;
						break;
					}
					else
					{
						prost=1;
					}
				}
			}
			if (prost==1){
		return n;
	}
	}
}



int main() {
	int b1,b2,t=0,suma=0,i,q;
	double bn1,bn2;
	
	while (t==0)
	{
		printf("Unesite brojeve A i B: ");
		
	scanf("%lf %lf",&bn1,&bn2);
	if (bn1<=0){
		printf("A nije prirodan broj:\n");
		
	}
	else if (bn1==round(bn1)&&(bn2==round(bn2))){
		b1=(int)bn1;
		b2=(int)bn2;
		
		if(b1<b2){
			t=-1;
		}
		else{
			printf("A nije manje od B.\n");
		}
		
	}
	for(i=0;i<b2;i++)
	{
		q=daj_prost();
		if (q>b1&&q<b2){
			suma=suma+q;
		}
	}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",b1,b2,suma);
	
	
	return 0;
}
