#include <stdio.h>
#define rp 6.80
#define rh 3.30
#define rc 5.00
#define fp 8.00
#define fh 3.00
#define fc 3.90
#define bp 5.30
#define bh 5.00
#define bc 6.00

int main() {
	
	double ruk=0,fuk=0,buk=0;
	double p=0,h=0,c=0;
	char tarik,mirza,bojan;
	char novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	
	switch(tarik) {
		case 'P':
		ruk=ruk+rp;
		fuk=fuk+fp;
		buk=buk+bp;
		p++;
		break;
		
		case 'H':
		ruk=ruk+rh;
		fuk=fuk+fh;
		buk=buk+bh;
		h++;
		break;
		
		case 'C':
		ruk=ruk+rc;
		fuk=fuk+fc;
		buk=buk+bc;
		c++;
		break;
	}
	
	switch(bojan) {
		case 'P':
		ruk=ruk+rp;
		fuk=fuk+fp;
		buk=buk+bp;
		p++;
		break;
		
		case 'H':
		ruk=ruk+rh;
		fuk=fuk+fh;
		buk=buk+bh;
		h++;
		break;
		
		case 'C':
		ruk=ruk+rc;
		fuk=fuk+fc;
		buk=buk+bc;
		c++;
		break;
	}
	
	switch(mirza) {
		case 'P':
		ruk=ruk+rp;
		fuk=fuk+fp;
		buk=buk+bp;
		p++;
		break;
		
		case 'H':
		ruk=ruk+rh;
		fuk=fuk+fh;
		buk=buk+bh;
		h++;
		break;
		case 'C':
		ruk=ruk+rc;
		fuk=fuk+fc;
		buk=buk+bc;
		c++;
		break;
	}
	
	if(ruk<fuk && ruk<buk){
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",ruk);
	return 0; }
	else if(fuk<ruk && fuk<buk)
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",fuk);
	
	else if(buk<ruk && buk<fuk)
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",buk);
	
	
	
	if(p*rp>h*rh && p*rp>c*rc)
	ruk=ruk-0.1*p*rp;
	
	else if(h*rh>p*rp && h*rh>c*rc)
	ruk=ruk-0.1*h*rh;
	
	else if(c*rc>p*rp && c*rc>h*rh)
	ruk=ruk-0.1*c*rc;
	
	if(ruk<fuk && ruk<buk)
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",ruk);
	
	return 0;
}
