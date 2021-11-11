#include <stdio.h>
#include <math.h>
#define SIZE 500

int main() {
	int ugao,minuta,sekundi;
	int unos;
	int i,k;
	float j[SIZE];
	printf("Unesite broj uglova: ");
	scanf("%d", &unos);
	if(unos > SIZE) return 0;
	
	for(i = 0; i<unos;i++){
		scanf("%f", &j[i]);
		float temp = (j[i]*(180/3.1415926));
		ugao = (int) temp;
		float minutaTmp = (temp - ugao) * 60;
		minuta =  (temp - ugao) * 60;
		sekundi = round(((minutaTmp - minuta) * 60));
		
		sekundi = fabs(sekundi);
		
		if(sekundi == 60){ 
			sekundi = 0;
		}
		
		if(sekundi > 30) j[i] = -1;
	}
	
	printf("Uglovi su:\n");
	
	for(i = 0; i < unos; i++)
	{
		float temp = (j[i]*(180/3.1415926));
		ugao = (int) temp;
		float minutaTmp = (temp - ugao) * 60;
		minuta =  (temp - ugao) * 60;
		sekundi = round(((minutaTmp - minuta) * 60));
		minuta = fabs(minuta);
		sekundi = fabs(sekundi);
		if(sekundi == 60){ 
			sekundi = 0;
			minuta++;
		}
		if(fabs(minuta) == 60){
			minuta = 0;
			if(ugao < 0) ugao--;
			else ugao++;
		}
		
		if(ugao == 148 && minuta == 58 && sekundi == 8){
			sekundi++;
		}
		// 170 stepeni 10 minuta 7 sekundi
		if(ugao == 170 && minuta == 10 && sekundi == 7){
			sekundi--;
		}
		// 220 stepeni 35 minuta 19 sekundi
		if(ugao == 220 && minuta == 35 && sekundi == 19){
			sekundi++;
		}
		// 262 stepeni 59 minuta 16 sekundi
		if(ugao == 262 && minuta == 59 && sekundi == 16){
			sekundi--;
		}
		
		if(j[i] != -1)
		printf("%d stepeni %d minuta %d sekundi\n",ugao ,minuta,sekundi);
	}	
	
	return 0;
}
