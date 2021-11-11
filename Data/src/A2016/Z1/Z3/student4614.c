#include <stdio.h>

int main() {
	char a;
	int c=0,s=0,p=0,v=0,b=0,u=0;
	float pr=0;
	printf("Unesite vozila: ");
	do
	{
	scanf("%c",&a);
	if(a=='k' || a=='K') break;
	
	if(a=='c' || a=='C')
	c++;
	
	else if(a=='s' || a=='S')
	s++;
	
	else if(a=='p' || a=='P')
    p++;
    
	else if(a=='v' || a=='V')
	v++; 
	
	else if(a=='b' || a=='B')
	b++; 
	
	else 
	printf("Neispravan unos\n");
	}while(a!='k' || a!='K');
	
	
	
	u=c+s+p+v+b;
	printf("Ukupno evidentirano %d vozila.\n",u);
	
	if(u==0)
		{
			pr=0;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		}
		else
		{

	 if(c>=s && c>=p && c>=v && c>=b)
	{

				pr=(c*100.)/(float)u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		
	}
	else if(s>c && s>p && s>v && s>b)
	{
		    pr=(s*100.)/(float)u;
		printf("Najpopularnija boja je siva (%.2f%%).",pr);
	}
	else if(p>c && p>s && p>v && p>b)
	{
			pr=(p*100.)/(float)u;
		printf("Najpopularnija boja je plava (%.2f%%).",pr);
	}
	else if(v>c && v>p && v>b && v>s)
	{
			pr=(v*100.)/(float)u;
		printf("Najpopularnija boja je crvena (%.2f%%).",pr);
	}
	else if(b>c && b>s && b>p && b>v)
	{
			pr=(b*100.)/(float)u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
	}
	
	
	

	 else if((b==s) && (b==v) && (b==p))
	{
		pr=(b*100.)/(float)u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
	}
	 else if((s==v) && (s==p))
	{
		 pr=(s*100.)/(float)u;
		printf("Najpopularnija boja je siva (%.2f%%).",pr);
	}
	 else if(v==p)
	{
		pr=(v*100.)/(float)u;
		printf("Najpopularnija boja je crvena (%.2f%%).",pr);
	}
	else printf("Najpopularnija boja je plava (%.2f%%).",pr);
	

	
		}

	    
	return 0;
}




















