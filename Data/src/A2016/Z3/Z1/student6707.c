#include <stdio.h>

int prost( int x)
	{
		int provjera=0,i;
		if(x==1) return 0;
		else{ for(i=2; i<x; i++)
		{
			if(x%i==0) provjera++;
		}
		if(provjera==0) return 1;
		else return 0;
		    
		}
	}

int daj_prost()
    {
        int y,i;
        static int a=2;
    
        for(i=a;i>0;i++)
        {
        y=prost(i);
        if(y==1){ a=i+1; return i;}
        }
        a=i+1;
    }

int main() {
	
	int a,b,suma=0,y;
	do{
	    printf("Unesite brojeve A i B: ");
	    scanf("%d %d",&a,&b);
	     if(a>=b) printf("A nije manje od B.\n");
	    else if (a<=0) printf("A nije prirodan broj.\n");
	    else if(b<=0) printf("B nije prirodan broj.\n");
	    
	    
	}while(a<=0 || b<=0 || a>=b );
	
	y=daj_prost();
	
	while(y<b)
	{
	    if(y>a) suma+=y;
	    y=daj_prost();
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
