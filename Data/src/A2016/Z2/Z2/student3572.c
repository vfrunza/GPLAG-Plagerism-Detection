#include <stdio.h>
#define PI 3.1415926

int main() {
	int n,i,j,sekunde,minute,stepen;
	double ugao,niz[500];

	

	
printf("Unesite broj uglova: ");
scanf("%d", &n);
	
	
	for(i=0; i<n; i++) {
	scanf("%lf", &niz[i]); }
	
	printf("Uglovi su:\n");
	for(i=0; i<n; i++) {
		
		ugao=niz[i]*180/PI;
		if(ugao<0) 
		ugao=-ugao;
		stepen=(int)ugao;
		ugao-=(int)ugao;
		ugao=ugao*60;
		
		minute=(int)ugao;
		ugao-=(int)ugao;
		ugao=ugao*60;
		
		sekunde=(int)(ugao+0.5);
	
		if(sekunde>=60) 
		{sekunde-=60; minute++;}
		if(minute>=60)
		{minute-=60; stepen++;}
		
	
	
	if(sekunde>30){
		for(j=i; j<n-1; j++) {
			
				
				niz[j]=niz[j+1]; }
				
				n--;
				i--;
			}
	}
for(i=0; i<n; i++) {
	int negativni=0;
	ugao=niz[i]*180/PI;
	if(ugao<0) {
		ugao=-ugao;
		negativni=-1;
		
	}
	
		
		ugao=niz[i]*180/PI;
		if(ugao<0) 
		ugao=-ugao;
		stepen=(int)ugao;
		ugao-=(int)ugao;
		ugao=ugao*60;
		
		minute=(int)ugao;
		ugao-=(int)ugao;
		ugao=ugao*60;
		
		sekunde=(int)(ugao+0.5);
	
		if(sekunde>=60) 
		{sekunde-=60; minute++;}
		if(minute>=60)
		{minute-=60; stepen++;}
		
	
	
	
	 
	

	 if(negativni) printf("-");
    printf("%d stepeni %d minuta %d sekundi\n", stepen,minute,sekunde);		
	}

	

    


	
	return 0;
}
