#include <stdio.h>

int main() {
	char slovo;
	int br=0,br_c=0,br_b=0,br_s=0,br_v=0,br_p=0;
	double procenat=0;
	printf("Unesite vozila: ");
	for(;;)
	{
		scanf("%c",&slovo);
		
		if(slovo=='K' || slovo=='k') break;
		else if(slovo=='C' || slovo=='c') 
		{
			br_c++; 
			br++;
		}
		else if(slovo=='B' || slovo=='b')
		{
			br_b++;
			br++;
		}
		else if(slovo=='S' || slovo=='s')
		{
			br_s++;
			br++;
		}
		else if(slovo=='V' || slovo=='v')
		{
			br_v++;
			br++;
		}
		else if(slovo=='P' || slovo=='p')
		{
			br_p++;
			br++;
		}
		else printf("Neispravan unos\n");
	
	}
	
	printf("Ukupno evidentirano %d vozila.\n",br);
    

	if(br_c>=br_b && br_c>=br_s && br_c>=br_v && br_c>=br_p)
	{
		procenat=((double)br_c/br)*100.0;
		if(br==0) procenat=0;
		printf("Najpopularnija boja je crna (%.2f%%).",procenat);
	}
	else if(br_b>=br_c && br_b>=br_s && br_b>=br_v && br_b>=br_p)
	{
		procenat=((double)br_b/br)*100.0;
		if(br==0) procenat=0;
		printf("Najpopularnija boja je bijela (%.2f%%).",procenat);
	}
	else if(br_s>=br_c && br_s>=br_b && br_s>=br_v && br_s>=br_p)
	{
		procenat=((double)br_s/br)*100.0;
		if(br==0) procenat=0;
		printf("Najpopularnija boja je siva (%.2f%%).",procenat);
	}
	else if(br_v>=br_c && br_v>=br_b && br_v>=br_s && br_v>=br_p)
	{
		procenat=((double)br_v/br)*100.0;
		if(br==0) procenat=0;
		printf("Najpopularnija boja je crvena (%.2f%%).",procenat);
	}
	else if(br_p>=br_c && br_p>=br_b && br_p>=br_s && br_p>=br_v)
	{
		procenat=((double)br_p/br)*100.0;
		if(br==0) procenat=0;
		printf("Najpopularnija boja je plava (%.2f%%).",procenat);
	}
	return 0;
}
