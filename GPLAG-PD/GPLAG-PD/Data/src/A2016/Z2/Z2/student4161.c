#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	
	float uglovi[500];
	int broj_uglova,i;
	printf("Unesite broj uglova: ");
	scanf("%d",&broj_uglova);
	
	
	for(i=0;i<broj_uglova;i++){
		scanf("%f",&uglovi[i]);	
	}
	
	for(i=0;i<broj_uglova;i++){
		int sati,minute,sekunde;
		float pomocne_minute,pomocni_ugao;
		
		pomocni_ugao=uglovi[i]*180/PI;
		if(pomocni_ugao>=0){	
			sati=(int)pomocni_ugao;
			pomocne_minute=(pomocni_ugao-sati)*60;
			minute=(int)pomocne_minute;
			sekunde=round((pomocne_minute-minute)*60);
			if(sekunde>=60){
				sekunde=sekunde-60;
				minute=minute+1;
				if(minute>=60){
					minute=minute-60;
					sati=sati+1;
				}
		}
		if(sekunde>30){
			int k=i;
			while(k!=broj_uglova){
				uglovi[k]=uglovi[k+1];
				k++;
			}
			broj_uglova=broj_uglova-1;
			i--;
		}
		}
		else{
			sati=(int)pomocni_ugao; 
			pomocni_ugao=(-1)*pomocni_ugao;
			pomocne_minute=(pomocni_ugao+sati)*60;
			
			minute=(int)pomocne_minute;
			sekunde=round((pomocne_minute-minute)*60);
			if(sekunde>=60){
				sekunde=sekunde-60;
				minute=minute+1;
				if(minute>=60){
					minute=minute-60;
					sati=sati-1;
				}
			}	
			if(sekunde>30){
				int k=i;
				while(k!=broj_uglova){
					uglovi[k]=uglovi[k+1];
					k++;
				}
				broj_uglova=broj_uglova-1;
				i--;
			}
		}
	}
	printf("Uglovi su:\n");
	for(i=0;i<broj_uglova;i++){
			int sati=0,minute=0,sekunde=0;
		float pomocne_minute,pomocni_ugao;
		
		pomocni_ugao=uglovi[i]*180/PI;
		if(pomocni_ugao>=0){	
		sati=(int)pomocni_ugao;
		pomocne_minute=(pomocni_ugao-sati)*60;
		minute=(int)pomocne_minute;
		sekunde=round((pomocne_minute-minute)*60);
		if(sekunde>=60){
			sekunde=sekunde-60;
			minute=minute+1;
			if(minute>=60){
				minute=minute-60;
				sati=sati+1;
			}
		}
		
		}
		else{
			sati=(int)pomocni_ugao; 
			pomocni_ugao=(-1)*pomocni_ugao;
			pomocne_minute=(pomocni_ugao+sati)*60;
			
			minute=(int)pomocne_minute;
			sekunde=round((pomocne_minute-minute)*60);
			if(sekunde>=60){
				sekunde=sekunde-60;
				minute=minute+1;
				if(minute>=60){
					minute=minute-60;
					sati=sati-1;
				}
			}	
		
		}
		printf("%d stepeni %d minuta %d sekundi\n",sati,minute,sekunde);
	}
	return 0;
}
