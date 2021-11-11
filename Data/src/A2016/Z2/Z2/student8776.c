#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int bruglova=0,brstepeni=0, brminuta=0, brsekundi=0, i, j;
	float ugao,a,b,c,d,e, niz1[500];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &bruglova);

	
	for(i=0; i<bruglova; i++){
		scanf("%f", &ugao);
		
		niz1[i]=ugao;
	}
	printf("Uglovi su:\n");
	if(bruglova>0)
	{
	
		for(j=0; j<bruglova; j++){
			
			
		a=niz1[j]*(180/PI);
	a=fabs(a);
		brstepeni=(int)a;
		if(niz1[j]<0)
		brstepeni=(int)a*(-1);
		b=a-(int)a;
		c=b*60;
		brminuta=(int)c;
		d=c-(int)c;
		e=d*60;
	 brsekundi=round(e);
	 
	 if(brsekundi>=59.5)
	 {
	 	brminuta=brminuta+1;
	 brsekundi=0;
	 }
	 if(brminuta>=59.5 && brstepeni>0){
	 	brstepeni=brstepeni+1;
	 	brminuta=0;
	 }
	 else if(brminuta>=59.5 && brstepeni<0){
	 	brstepeni=brstepeni-1;
	 	brminuta=0;
	 }
	 
	 
	  if(brsekundi<=30)
	printf("%d stepeni %d minuta %d sekundi\n", brstepeni, brminuta, brsekundi);
	
	}
	}
	
	return 0;
}
