
// zad sa parcijalnog posaljes mu broj on vraca z 
// PRAVI ZADATAK 1 IZ ZADACE 1 OD SARAH god 2017/2018

prvi zadatak sa mog i sarinog usmenog ide S TIM DA OVAJ NE RADI SKROZ IMAŠ U FOLDERU 
PROBA 1  ZADATAK 1 POGLEDAJ TU prvi ispod pa onda ovi odozgo

#include <stdio.h>
#include <math.h>

int main() {
	
	int mat[100][100], i, j, n=0, broj[100],maxr, maxic,k;
	double suma=0, max_suma=0, max_sr_vr=0, sr_vr=0;
	printf("Unesite matricu: \n");
	for(i=0; i<100; i++){
		j=0;
		while(j<100){
			scanf("%d", &mat[i][j]);
			if(mat[i][j] == -1) break;
			j++;
		}
		broj[i] = j;
		
		if(mat[i][0] == -1) break;
		
	}
	n=i;
	
	for(j=0; j< broj[0]; j++)
		max_suma += mat[0][j];
		
		max_sr_vr = max_suma / broj[0];
	
	maxic = broj[0];
	for (i=0; i<n; i++){
		if(broj[i] > maxic) maxic = broj[i];
	}
	
	
	for(i=0; i<n; i++){
		suma=0;
		for(j=0; j<broj[i]; j++){
			suma += mat[i][j];
		}
		sr_vr = suma / broj[i];
		if(sr_vr >= max_sr_vr){
			max_sr_vr = sr_vr;
			maxr = i;
			
		}
	}
	
	

/* prof način sarah na ispitu isto kao ispod radi
	for(i=0; i<n; i++)
		for(j=0; j< maxic; j++)
			mat[maxr][j]= mat[n-1][j];
	
	
	n--;
	*/
	
	//sefer nacinn
	/*for (i=maxr; i<n-1; i++) {
		for (j=0; j<maxic; j++)
		mat[i][j]=mat[i+1][j];
	}
	n--;
*/

	for (i=0; i<n; i++) {
		if (i==maxr) {
			for (k=i; k<n-1; k++) {
				for (j=0; j<maxic; j++) {
					mat[k][j]=mat[k+1][j];
				}
			}
			n--;
		}
	}
	
	printf("Nakon izbacivanja matrica glasi: \n");
	for(i=0; i<n; i++){
		for(j=0; j<broj[i]; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
#include <stdio.h>

void VracaZ (int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i==0 || i==n-1 || i==n-j-1) printf("*");
			else printf(" ");
			}
		printf("\n");
	}
	
}

int main(){
	int n; 
	printf("Unesi broj: ");
	scanf("%d", &n);
	VracaZ(n);
	
	return 0;
}*/




Z1Z1

#include <stdio.h>

int main() {
	float pr=6.80,pf=8.00,pb=5.30,hr=3.30,hf=3.00,hb=5.00,cr=5.00,cf=3.90,cb=6.00,sumaR=0,sumaR2=0,sumaF=0,sumaB=0,nova_cijena=0;
	char tarik,bojan,mirza,novi_red,novo_jelo='\0';
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	
	
	if ((tarik=='P' && bojan=='P') || (tarik=='P' && mirza=='P') || (bojan=='P' && mirza=='P') || (tarik!=bojan && tarik!=mirza && bojan!=mirza))
		{
		nova_cijena=pr-pr*0.1;
		novo_jelo='P';
		}
	else if ((tarik=='H' && bojan=='H') || (tarik=='H' && mirza=='H') || (bojan=='H' && mirza=='H'))
			
	{
		nova_cijena=hr-hr*0.1;
		novo_jelo='H';
	}	
	else if ((tarik=='C' && bojan=='C') || (tarik=='C' && mirza=='C') || (bojan=='C' && mirza=='C'))
	{
		nova_cijena=cr-cr*0.1;
		novo_jelo='C';
	}
	if (tarik=='P')
	{
		sumaR+=pr;
		sumaF+=pf;
		sumaB+=pb;
		if (novo_jelo=='P')
			sumaR2+=nova_cijena;
		else 
			sumaR2+=pr;
	}
	else if (tarik=='H')
	{
		sumaR+=hr;
		sumaF+=hf;
		sumaB+=hb;
		if (novo_jelo=='H')
			sumaR2+=nova_cijena;
		else 
			sumaR2+=hr;	
	}
	else if (tarik=='C')
	{
		sumaR+=cr;
		sumaF+=cf;
		sumaB+=cb;
		if (novo_jelo=='C')
			sumaR2+=nova_cijena;
		else 
			sumaR2+=cr;	
	}
	
	if (bojan=='P')
	{
		sumaR+=pr;
		sumaF+=pf;
		sumaB+=pb;
		if (novo_jelo=='P')
			sumaR2+=nova_cijena;
		else 
			sumaR2+=pr;
	}
	else if (bojan=='H')
	{
		sumaR+=hr;
		sumaF+=hf;
		sumaB+=hb;
		if (novo_jelo=='H')
			sumaR2+=nova_cijena;
		else 
			sumaR2+=hr;
	}
	else if (bojan=='C')
	{
		sumaR+=cr;
		sumaF+=cf;
		sumaB+=cb;
		if (novo_jelo=='C')
			sumaR2+=nova_cijena;
		else 
			sumaR2+=cr;
	}

	if (mirza=='P')
	{
		sumaR+=pr;
		sumaF+=pf;
		sumaB+=pb;
		if (novo_jelo=='P')
			sumaR2+=nova_cijena;
		else 
			sumaR2+=pr;
	}
	else if (mirza=='H')
	{
		sumaR+=hr;
		sumaF+=hf;
		sumaB+=hb;
		if (novo_jelo=='H')
			sumaR2+=nova_cijena;
		else 
			sumaR2+=hr;
	}
	else if (mirza=='C')
	{
		sumaR+=cr;
		sumaF+=cf;
		sumaB+=cb;
		if (novo_jelo=='C')
			sumaR2+=nova_cijena;
		else 
			sumaR2+=cr;
	}
	if (sumaR<sumaF && sumaR<sumaB)
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",sumaR);
	else if (sumaF<sumaR && sumaF<sumaB)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",sumaF);
	else if (sumaB<sumaR && sumaB<sumaF)
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",sumaB);
		
	if (sumaR>sumaF || sumaR>sumaB)
	{
		if (sumaR2<sumaF && sumaR2<sumaB)
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",sumaR2);
	}
	return 0;
}