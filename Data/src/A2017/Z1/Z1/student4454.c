#include <stdio.h>


int main()
{
	char tarik,bojan,mirza,n;
	float brojacp=0,brojach=0,brojacc=0,RP=6.8,RH=3.3,RC=5.0,BP=5.3,BH=5.0,BC=6.0,FP=8.0,FH=3.0,FC=3.9,R=0,B=0,F=0;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c",&n);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
		scanf("%c",&n);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	
	if(tarik=='P') brojacp++;
	else if(tarik=='H') brojach++;
	else if(tarik=='C') brojacc++;
	
	if(bojan=='P') brojacp++;
	else if(bojan=='H') brojach++;
	else if(bojan=='C') brojacc++;
	
	if(mirza=='P') brojacp++;
	else if(mirza=='H') brojach++;
	else if(mirza=='C') brojacc++;
	
	R=brojacp*RP+brojach*RH+brojacc*RC;
	B=brojacp*BP+brojach*BH+brojacc*BC;
	F=brojacp*FP+brojach*FH+brojacc*FC;
	int k=0;
	if((R<B) && (R<F)) 
	{printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",R);
	k=1;
	}
	 else if((B<R) && (B<F)) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",B);
	  else if((F<B) && (F<R)) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",F);
	 if((brojach>brojacp) && (brojach>brojacc)) RH*=0.9;
	 else if((brojacc>brojacp) && (brojacc>brojach)) RC*=0.9;
	 else RP*=0.9;
	 R=brojacp*RP+brojach*RH+brojacc*RC;
	 if(R<F && R<B && k!=1) 



	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",R);

	return 0;
}
