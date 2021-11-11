#include <stdio.h>

int main() {
	char x;
	int c=0,p=0,b=0,s=0,v=0,  suma=0;
	printf("Unesite vozila: ");
	while(1)
	{
	    scanf("%c",&x);
	    if(x=='c'||x=='C')
	    {
	        c++;
	        suma++;
	        
	    }
	    else if(x=='B'||x=='b')
	    {
	        b++;
	        suma++;
	        
	    }
	    else if(x=='s'||x=='S')
	    {
	        s++;
	        suma++;
	        
	    }
	    else if(x=='v'||x=='V')
	    {
	        v++;
	        suma++;
	        
	    }
	    else if(x=='p'||x=='P')
	    {
	        p++;
	        suma++;
	       
	    }
	    else if(x=='k'||x=='K')
	    {
	        break;
	    }
	    else{
	        printf("Neispravan unos\n");
	    }
	   
	}
	printf("Ukupno evidentirano %d vozila.\n",suma);
	int maxi,o=1;
	maxi=c;
	
	if(maxi<b){
	    maxi=b;
	    
	    o=2;
	}
	 if(maxi<s)
	{ 
	    maxi=s;
	    
	    o=3;
	}
	if(maxi<v)
	{    maxi=v;
			
		o=4;
	}
	if(maxi<p)
	{    maxi=p;
		
		o=5;
	}
	double f,g;
	f=maxi;
	g=suma;
	if(suma==0)
		g=1;
	printf("Najpopularnija boja je ");
	switch (o){
		case 1:
			printf("crna (%.2f%).",f/g*100);
			break;
		case 2:
			printf("bijela (%.2f%).",f/g*100);
			break;
		case 3:
			printf("siva (%.2f%).",f/g*100);
			break;
		case 4:
			printf("crvena (%.2f%).",f/g*100);
			break;
		case 5:
			printf("plava (%.2f%).", f/g*100);
			break;
	
	}
	
	return 0;
}