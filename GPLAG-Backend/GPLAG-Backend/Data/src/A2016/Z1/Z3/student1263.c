#include <stdio.h>

int main() {
	char a;
	float suma1=0,suma2=0,suma3=0,suma4=0,suma5=0,suma;
	float prosjek1,prosjek2,prosjek3,prosjek4,prosjek5;
	
	printf("Unesite vozila: ");
	for(;;)
	{
		scanf("%c",&a);
		if(a=='C'||a=='c')
		{
			suma1++;
		}
		else if(a=='B'||a=='b')
		{
			suma2++;
		}
		else if(a=='S'||a=='s')
		{
			suma3++;
		}
		else if(a=='V'||a=='v')
		{
			suma4++;
		}
		else if(a=='P'||a=='p')
		{
			suma5++;
		}
		else if(a=='K'||a=='k')
		{
			break;
		}
		else 
		{
		printf("Neispravan unos ");
		}
	}
	 suma=suma1+suma2+suma3+suma4+suma5;
    prosjek1=(suma1/suma)*100;
    prosjek2=(suma2/suma)*100;
    prosjek3=(suma3/suma)*100;
    prosjek4=(suma4/suma)*100;
    prosjek5=(suma5/suma)*100;
    printf("Ukupno evidentirano %.f vozila. \n",suma);
    if(suma1>suma2&&suma1>suma3&&suma1>suma4&&suma1>suma5)
    {
        printf("Najpopularnija boja je crna (%.2f%%).",prosjek1);
    }
    else if(suma2>suma1&&suma2>suma3&&suma2>suma4&&suma2>suma5)
    {
        printf("Najpopularnija boja je bijela (%.2f%%).",prosjek2);
    }
    else if(suma3>suma2&&suma3>suma1&&suma3>suma4&&suma3>suma5)
    {
        printf("Najpopularnija boja je siva (%.2f%%).",prosjek3);
    }
    else if(suma4>suma2&&suma4>suma3&&suma4>suma1&&suma4>suma5)
    {
        printf("Najpopularnija boja je crvena (%.2f%%).",prosjek4);
    }
    else if(suma5>suma2&&suma5>suma3&&suma5>suma4&&suma5>suma1)
    {
        printf("Najpopularnija boja je plava (%.2f%%).",prosjek5);
    }
	return 0;
}
