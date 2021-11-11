#include <stdio.h>
#define PI 3.1415926
int main(){
	int broj,i,a;
	int stepeni[500],minuta[500],sekundi[500];
	double ugao;
	printf("Unesite broj uglova: ");
	scanf("%d",&broj);
	for(i=0;i<broj;i++){
		scanf("%lf",&ugao);
		if(ugao>=0) 
		a=(ugao*180*3600/PI)+0.5;
		if (ugao<0)
		a=(ugao*180*3600/PI)-0.5;
		stepeni[i]=a/3600;
		if(a<0) a*=-1;
		sekundi[i]=a%60;
		a/=60;
		minuta[i]=a%60;
		if(sekundi[i]>30){
			i--;
			broj--;
		}
	}
	printf("Uglovi su: \n");
	for(i=0;i<broj;i++)
	printf("%d stepeni %d minuta %d sekundi \n", stepeni[i],minuta[i],sekundi[i]);
	
	return 0;
	
}

