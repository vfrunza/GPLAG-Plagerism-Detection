#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
	double P1=6.8,H1=3.3,C1=5;
	double P2=8,H2=3,C2=3.9;
	double P3=5.3,H3=5.0,C3=6.0;
	int brojacP=0,brojacH=0,brojacC=0;
	double cijena1=0,cijena2=0,cijena3=0,min=0;
	char t,b,m,novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&t);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&b);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&m);
	scanf("%c",&novi_red);
	switch (t){
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
	switch (b){
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
	switch(m){
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
	cijena1=brojacP*P1+brojacH*H1+brojacC*C1;
	cijena2=brojacP*P2+brojacH*H2+brojacC*C2;
	cijena3=brojacP*P3+brojacH*H3+brojacC*C3;
	
	min=cijena1;
	if (cijena2<min) {min=cijena2;} 
	else if (cijena3<min){min=cijena3;}
	
	
	if ((cijena1<min) || (fabs(cijena1-min)<epsilon)) {printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena1);}
	else if ((cijena2<min) || fabs(cijena2-min)<epsilon) {printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena2);}
	else if ((cijena3<min) || fabs(cijena3-min)<epsilon){printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena3);}
	
	if (cijena1>min){      
		if ((brojacP*P1>brojacH*H1) && (brojacP*P1>brojacC*C1)) {cijena1=((brojacP*P1-(brojacP*P1)/10)+brojacH*H1+brojacC*C1);}
		else if ((brojacH*H1>brojacP*P1) && (brojacH*H1>brojacC*C1)) {
			cijena1=brojacP*P1+(brojacH*H1-((brojacH*H1)/10))+brojacC*C1;
		}
			else if ((brojacC*C1>brojacP*P1) && (brojacC*C1>brojacH*H1)){
				cijena1=brojacP*P1+brojacH*H1+((brojacC*C1)-(brojacC*C1)/10);
			}
		}
	if (cijena1<min) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena1);   
	return 0;
}