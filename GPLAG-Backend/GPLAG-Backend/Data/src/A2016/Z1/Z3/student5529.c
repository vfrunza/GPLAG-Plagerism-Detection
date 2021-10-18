#include <stdio.h>

int main() {
	char r,k='a',l='e',m='d',n='f',o='g';
	
	int	brojac1=0, brojac2=0, brojac3=0, brojac4=0, brojac5=0,p1,p2,p3,p4,p5,brojac;
	float f1,f2,f3,f4,f5;

	printf("Unesite vozila: ");
	do{
	scanf("%c", &r);
	if((r=='C'||r=='c')&&r!='k'&&r!='K'){
		brojac1++;
		k=r;
	}  if((r=='B'||r=='b')&&r!='k'&&r!='K'){
		brojac2++;
		l=r;
	}  if((r=='S'||r=='s')&&r!='k'&&r!='K'){
		brojac3++;
		m=r;
	}  if((r=='V'||r=='v')&&r!='k'&&r!='K'){
		brojac4++;
		n=r;
	}  if((r=='P'||r=='p')&&r!='k'&&r!='K'){
		brojac5++;
		o=r;
	} 


	   if(r!='c'&&r!='k'&&r!='K'&&r!='C'&&r!='b'&&r!='B'&&r!='s'&&r!='S'&&r!='v'&&r!='V'&&r!='p'&&r!='P'&&r!='k'&&r!='K'){
 printf("Neispravan unos\n");
	}}
	
	while(r!='K'&&r!='k');
	
		brojac=brojac1+brojac2+brojac3+brojac4+brojac5;
	
	printf("Ukupno evidentirano %d vozila.",brojac);
	
	
	p1=brojac1*100;
	
	p2=brojac2*100;
		
	p3=brojac3*100;
		
	p4=brojac4*100;
		
	p5=brojac5*100;
	f1=(float)p1/brojac;
	f2=(float)p2/brojac;
	f3=(float)p3/brojac;
	f4=(float)p4/brojac;
	f5=(float)p5/brojac;
 if(brojac==0 && r!='c'&&r!='C'&&r!='b'&&r!='s'&&r!='v'&&r!='p'&&r!='B'&&r!='S'&&r!='V'&&r!='P'){
		printf("\nNajpopularnija boja je crna (0.00%%).");
	}
	else if(brojac1>brojac2&&brojac1>brojac3&&brojac1>brojac4&&brojac1>brojac5){
		printf("\nNajpopularnija boja je crna (%.2f%%).",f1);
	} else if(brojac2>brojac1&&brojac2>brojac3&&brojac2>brojac4&&brojac2>brojac5){
		printf("\nNajpopularnija boja je bijela (%.2f%%).",f2);
	} else if(brojac3>brojac1&&brojac3>brojac2&&brojac3>brojac4&&brojac3>brojac5){
		printf("\nNajpopularnija boja je siva (%.2f%%).",f3);
	} else if(brojac4>brojac1&&brojac4>brojac2&&brojac4>brojac3&&brojac4>brojac5){
		printf("\nNajpopularnija boja je crvena (%.2f%%).",f4);
	} else if(brojac5>brojac1&&brojac5>brojac2&&brojac5>brojac3&&brojac5>brojac4){
		printf("\nNajpopularnija boja je plava (%.2f%%).",f5);
	} 
	
	else if((brojac1==brojac2 || brojac1==brojac3 || brojac1==brojac4|| brojac1==brojac5)&&(k=='C'||k=='c')){
		printf("\nNajpopularnija boja je crna (%.2f%%).",f1);
	} else if((brojac2==brojac1 || brojac2==brojac3 || brojac2==brojac4|| brojac2==brojac5)&&(l=='B'||l=='b')){
		printf("\nNajpopularnija boja je bijela (%.2f%%).",f2);
	}  else if((brojac3==brojac1 || brojac3==brojac2 || brojac3==brojac4|| brojac3==brojac5)&&(m=='S'||m=='s')){
		printf("\nNajpopularnija boja je siva (%.2f%%).",f3);
	}  else if((brojac4==brojac1 || brojac4==brojac2 || brojac4==brojac3|| brojac4==brojac5)&&(n=='V'||n=='v')){
		printf("\nNajpopularnija boja je crvena (%.2f%%).",f4);
	} else if((brojac5==brojac1 || brojac5==brojac2 || brojac5==brojac3|| brojac5==brojac4)&&(o=='P'||o=='p')){
		printf("\nNajpopularnija boja je plava (%.2f%%).",f5);
	} 
	return 0;
}
