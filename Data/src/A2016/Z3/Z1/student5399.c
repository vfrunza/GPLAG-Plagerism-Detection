#include <stdio.h>

int daj_prost()
{
	/*static int i=2;*/
	static int i, br=1, prost=1;
	br++;
	for(i=2;i<br;i++)
	{
		if(i==br)
		{
            return br;
		} 
	    else if(br%i==0)
	    {
	    	br++;
	    	i=2;
	    	prost=0;
	    }
	    else prost=1;
	}
	if(prost==1)
	{
		return br;
	}
	return br;
}

int main() {
	int a, b, i, h, suma=0;
	while(1==1){
	    printf("Unesite brojeve A i B: ");
	    scanf("%d %d", &a, &b);
	    if(a<=0)
	    {
	        printf("A nije prirodan broj.\n");
	        continue;
	    }
	    else if(b<=a)
	    {
	        printf("A nije manje od B.\n");
	        continue;	
	    } 
	    else if(b<=0)
	    {
	        printf("B nije prirodan broj.\n");
	        continue;
	    }
		break;
	}
	for(i=a+1;i<b;i++)
	{   
	    h=daj_prost();
	    while(h<=a)
	    {
	    	h=daj_prost();
	    	if(h>a)break;
	    }
	    if(h<b)
	    {
	    	suma+=h;
	    }
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
