#include <stdio.h>
#include <string.h>
int main() 
	{
		float CR,SI,BI,CV,PL,i,CP,SP,BP,CVP,PP,K,L;
		
		char a,j;
		CV=0;
		SI=0;
		BI=0;
		CV=0;
		PL=0;
		printf("Unesite vozila: ");
		i=0;
	  
	  
	  do {
	  	scanf("%c",&a);
	  	if((a!='0' && a!='1') && (a!=' ') && (a!=',')&&(a=='C'||a=='c'||a=='S'||a=='s'||a=='B'||a=='b'||a=='V'||a=='v'||a=='P'||a=='p'||a=='K'||a=='k')) {i++; }
	  	if(a!='C'&&a!='c'&&a!='S'&&a!='s'&&a!='B'&&a!='b'&&a!='V'&&a!='v'&&a!='P'&&a!='p'&&a!='K'&&a!='k')
	  	printf("Neispravan unos:\n");{
	  		if((a=='C' || a=='c')) CR=CR+1;
	  		if((a=='S' || a=='s')) SI=SI+1;
	  		if((a=='B' || a=='b')) BI=BI+1;
	  		if((a=='V' || a=='v')) CV=CV+1;
	  		if((a=='P' || a=='p')) PL=PL+1;
	  		
	  	}
	  }
	  while(a!='k'&&a!='K');
	  if(i-1!=0) {
	  	CP=CR/(i-1)*100;
	  	SP=SI/(i-1)*100;
	  	BP=BI/(i-1)*100;
	  	CVP=CV/(i-1)*100;
	  	PP=PL/(i-1)*100;
	  }
	  if(CP==0&&SP==0&&BP==0&&CVP==0&&PL==0) {
	  	printf("Ukupno evidentirano 0 vozila.\n");
	  }
	  else {
	  	printf("Ukupno evidentirano %1.f vozila.\n",i-1);
	  }
	 if(CR>=SI&&CR>=BI&&CR>=CV&&CR>=PL)
	 printf("Najpopularnija boja je crna (%4.2f%).",CP);
	 if(SI>CR&&SI>=BI&&SI>=CV&&SI>=PL)
	 printf ("Najpopularnija boja je siva (%4.2f%).",SP);
	 if(BI>CR&&BI>CR&&BI>=CV&&BI>=PL)
	 printf("Najpopularnija boja je bijela (%4.2f%).",BP);
	 if(CV>CR&&CV>SI&&CV>BI&&CV>=PL)
	 printf("Najpopularnija boja je crvena (%4.2f%).",CVP);
	 if(PL>CR&&PL>SI&&PL>BI&&PL>CV)
	 printf("Najpopularnija boja je plava (%4.2f%).",PP);
	 
	
	
	return 0;
	}
