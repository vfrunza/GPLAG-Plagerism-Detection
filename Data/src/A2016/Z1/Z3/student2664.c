#include <stdio.h>


int main() {
	
	int x=0, brojac_c=0, brojac_b=0, brojac_s=0,brojac_v=0,brojac_p=0;
	char autic;
	float p1,p2,p3,p4,p5;
	
	printf("Unesite vozila: ");
	
	do {
	scanf ("%c", &autic);
		
	if (autic=='C' || autic=='c') {
		brojac_c++;
	}
	else if (autic=='B' || autic=='b') { 
		brojac_b++;
	}
	else if (autic=='S' || autic=='s') {
		brojac_s++;
	}
	else if (autic=='V' || autic=='v') {
	brojac_v++; 
	}
	else if (autic=='P' || autic=='p') {
		brojac_p++;
	} 
	else if (autic=='K' || autic=='k') {
		break;
	}
	else
	{
		printf("Neispravan unos\n");
}
	} while (autic != 'K' && autic !='k');
	
	
	
	x=brojac_c+brojac_b+brojac_s+brojac_v+brojac_p;
	
	printf("Ukupno evidentirano %d vozila.\n",x);
	

 
	p1 = ((float)brojac_c/x)*100;
	p2 = ((float)brojac_b/x)*100;
	p3 = ((float)brojac_s/x)*100;
	p4 = ((float)brojac_v/x)*100;
	p5 = ((float)brojac_p/x)*100;
	
	
	if (x==0){
		p1=0;
		p2=0;
		p3=0;
		p4=0;
		p5=0;
	} 
else {
	
	if(p1>=p2 && p1>=p3 && p1>=p4 && p1>=p5) 
	{
	printf ("Najpopularnija boja je crna (%.2f%%).",p1);
	}
	else if ( p2>=p1 && p2>=p3 && p2>=p4 && p2>=p5)
	{
	printf ("Najpopularnija boja je bijela (%.2f%%).",p2);
	}
	else if (p3>=p2 && p3>=p1 && p3>=p4 && p3>=p5 ) 
	{
	printf("Najpopularnija boja je siva (%.2f%%).",p3);
	}
	else if ( p4>=p1 && p4>=p2 && p4>=p3 &&p4>=p5) 
	{
	printf("Najpopularnija boja je crvena (%.2f%%).",p4);
	}
	else if( p5>=p1 && p5>=p2 && p5>=p3 && p5>=p4) 
	{
	printf("Najpopularnija boja je plava (%.2f%%).",p5);
	}
}
	
	
	
	
	
	
	return 0;
}

	
