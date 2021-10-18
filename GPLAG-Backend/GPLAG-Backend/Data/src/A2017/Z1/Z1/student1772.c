#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
	double p1=6.8,h1=3.3,c1=5;
	double p2=8,h2=3,c2=3.9;
	double p3=5.3,h3=5.0,c3=6.0;
	int brojacP=0,brojacH=0,brojacC=0;
	double cijena1=0,cijena2=0,cijena3=0,min=0;
	char tarik,bojan,mirza,novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	switch (tarik){
		case 'P':
		brojacP=brojacP+1;
		break;
		case 'H':
		brojacH=brojacH+1;
		break;
		case 'C':
		brojacC=brojacC+1;
		break;
		default:
		printf("Unjeli ste pogresnu vrijednost\n");
	}
	switch (bojan){
		case 'P':
		brojacP=brojacP+1;
		break;
		case 'H':
		brojacH=brojacH+1;
		break;
		case 'C':
		brojacC=brojacC+1;
		break;
		default:
		printf("Unjeli ste pogresnu vrijednost\n");
	}
	switch(mirza){
		case 'P':
		brojacP=brojacP+1;
		break;
		case 'H':
		brojacH=brojacH+1;
		break;
		case 'C':
		brojacC=brojacC+1;
		break;
		default:
		printf("Unjeli ste pogresnu vrijednost\n");
	}
	cijena1=brojacP*p1+brojacH*h1+brojacC*c1;
	cijena2=brojacP*p2+brojacH*h2+brojacC*c2;
	cijena3=brojacP*p3+brojacH*h3+brojacC*c3;
	
	min=cijena1;
	if (cijena2<min) {min=cijena2;} 
	else if (cijena3<min){min=cijena3;}
	
	
	if ((cijena1<min) || (fabs(cijena1-min)<epsilon)) {printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena1);}
	else if ((cijena2<min) || fabs(cijena2-min)<epsilon) {printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
	else if ((cijena3<min) || fabs(cijena3-min)<epsilon){printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);}
	
	if (cijena1>min){      
		if ((brojacP*p1>brojacH*h1) && (brojacP*p1>brojacC*c1)) {cijena1=((brojacP*p1-(brojacP*p1)/10)+brojacH*h1+brojacC*c1);}
		else if ((brojacH*h1>brojacP*p1) && (brojacH*h1>brojacC*c1)) {
			cijena1=brojacP*p1+(brojacH*h1-((brojacH*h1)/10))+brojacC*c1;
		}
			else if ((brojacC*c1>brojacP*p1) && (brojacC*c1>brojacH*h1)){
				cijena1=brojacP*p1+brojacH*h1+((brojacC*c1)-(brojacC*c1)/10);
			}
		}
	if (cijena1<min) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena1);   
	return 0;
}
   