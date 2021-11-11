#include <stdio.h>

int main() {

	char a,maxiC='a';float lj=0;
	int br=0; int flag=0;
	int maxi=0,brC=0,brB=0,brS=0,brV=0,brP=0;
	printf("Unesite vozila: ");
	scanf("%c",&a);
	
	while(a!='k')
	{   
		if(a>='a' && a<='z') a=a-32;
		switch (a)
		{
			case 'C':br++;brC++;if(maxi<brC){maxi=brC;maxiC=a;}break;
			case 'B':br++;brB++;if(maxi<brB){maxi=brB;maxiC=a;}break;
			case 'S':br++;brS++;if(maxi<brS){maxi=brS;maxiC=a;}break;
			case 'V':br++;brV++;if(maxi<brV){maxi=brV;maxiC=a;}break;
			case 'P':br++;brP++;if(maxi<brP){maxi=brP;maxiC=a;}break;
			case 'K':flag=1;break;
			default:printf("Neispravan unos \n");
		}
		if (flag==1) break;
	    scanf("%c",&a);
	}
    
   
    lj=((float)(maxi)/br)*100;
    
    printf("Ukupno evidentirano %d vozila.\n",br);
   
   
	switch (maxiC)
		{
			case 'C':printf("Najpopularnija boja je crna (%.2f%).", lj);break;
			case 'B':printf("Najpopularnija boja je bijela (%.2f%).", lj);break;
			case 'S':printf("Najpopularnija boja je siva (%.2f%).", lj);break;
			case 'V':printf("Najpopularnija boja je crvena (%.2f%).", lj);break;
			case 'P':printf("Najpopularnija boja je plava (%.2f%).", lj);break;
			default:printf("Najpopularnija boja je crna (0.00%).");
		}
   
    
    


return 0;
}
