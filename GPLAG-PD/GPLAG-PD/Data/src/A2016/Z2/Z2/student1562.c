#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int brojuglova,i,j;
	float uglovi[500],stepeni,minute,sekunde,b,a;
	printf("Unesite broj uglova: ");
	scanf("%d",&brojuglova);
	for(i=0;i<brojuglova;i++){
	scanf("%f",&uglovi[i]);
	}
	float n=3;
	n=pow(10,n);
	for(i=0;i<brojuglova;i++){
        stepeni=uglovi[i]*(180/PI);
		minute=(stepeni-(int)stepeni);
		minute=minute*60;
		minute=(int)(minute*n+0.5)/n;
		sekunde=(minute-(int)minute);
		sekunde=sekunde*60;
		sekunde=(int)(sekunde*n+0.5)/n;
		sekunde=sekunde+0.05;
	    if(sekunde>=60){sekunde-=60;minute++;}
        if(minute>=60){minute-=60;stepeni++;}
        
        
	  if(sekunde>30){
	   	for(j=i;j<brojuglova-1;j++){
	   		uglovi[j]=uglovi[j+1];
	   	}
	   	brojuglova--;
	   	i--;
	   }
	}
	
	printf("Uglovi su: \n");
	for(i=0;i<brojuglova;i++){
     	stepeni=uglovi[i]*(180/PI);
		
		minute=(stepeni-(int)stepeni);
	
		minute=minute*60;
		//minute=(int)(minute*n+0.5)/n;
		
		sekunde=(minute-(int)minute);
	
		
		sekunde=sekunde*60;
		sekunde=(int)(sekunde*n+0.5)/n;
		
		sekunde=sekunde+0.55;
		
		
        
	    if(sekunde>=60){sekunde-=60;minute++;}
        if(minute>=60){minute-=60;stepeni++;}
		printf("%d stepeni %d minuta %d sekundi\n",(int)stepeni,(int)minute,(int)sekunde);
	}
	
	
	return 0;
}
