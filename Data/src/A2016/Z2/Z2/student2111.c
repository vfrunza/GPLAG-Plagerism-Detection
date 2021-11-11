#include <stdio.h>
#define pi 3.1415926
#include <math.h>
int main() {
	int minute,sekunde,stepeni;
	float minute_racun;
	float sekunde_racun;
	float niz[500];
	int broj_uglova;
	int i,j;
	float uglovi_u_radijanima;
	float ukupno_stepeni;
	float sekunde_zaokruzivanje;
	int ostatak_sekunde;
	int ostatak;
	int cijeli_dio;
	printf("Unesite broj uglova: ");
	scanf("%d",&broj_uglova);
	
	printf("Uglovi su:\n");
	for(i=0;i<broj_uglova;i++){
		scanf("%f",&niz[i]);
	
	}
	

	
		for(i=0;i<broj_uglova;i++){
		uglovi_u_radijanima=niz[i];
		ukupno_stepeni=uglovi_u_radijanima*180/pi;
		stepeni=(int)ukupno_stepeni;
		minute_racun=(ukupno_stepeni-stepeni)*60;
		minute=(int)minute_racun;
		sekunde_racun=(minute_racun-minute)*60;
		sekunde=(int)sekunde_racun;
		
		sekunde_zaokruzivanje=sekunde_racun-sekunde;
		sekunde_zaokruzivanje=sekunde_zaokruzivanje*100;
		ostatak_sekunde=sekunde_zaokruzivanje;
		cijeli_dio=ostatak_sekunde/10;
		ostatak=ostatak_sekunde%10;
		if(fabs(sekunde_racun-sekunde)>=0.5){
			if(sekunde>=0){
				sekunde=sekunde+1;
			}
			else if(sekunde<0){
				sekunde=sekunde-1;
			}
			}
			
			else if(cijeli_dio==4 && ostatak>=5){
			if(sekunde>=0){
			sekunde=sekunde+1;
			}
			else if(sekunde<0){
			sekunde=sekunde-1;
			}
			}
			
			if(sekunde<=-60){
			sekunde=sekunde+60;
			minute=minute-1;
			}
			
			if(minute<=-60){
			minute=minute+60;
			stepeni=stepeni-1;
			}
			
		
			if(sekunde>=60){
			sekunde=sekunde-60;
			minute=minute+1;
			}
			
			if(minute>=60){
			minute=minute-60;
			stepeni=stepeni+1;
			}
	
			if((sekunde>30 || sekunde<-30)){
			for(j=i;j<broj_uglova-1;j++){
			niz[j]=niz[j+1];
			}
			broj_uglova--;
			i--;
			}

			}
		
		
		for(i=0;i<broj_uglova;i++){
		uglovi_u_radijanima=niz[i];
		ukupno_stepeni=uglovi_u_radijanima*180/pi;
		stepeni=(int)ukupno_stepeni;
		minute_racun=(ukupno_stepeni-stepeni)*60;
		minute=(int)minute_racun;
		sekunde_racun=(minute_racun-minute)*60;
		sekunde=(int)sekunde_racun;
		
		sekunde_zaokruzivanje=sekunde_racun-sekunde;
		sekunde_zaokruzivanje=sekunde_zaokruzivanje*100;
		ostatak_sekunde=sekunde_zaokruzivanje;
		cijeli_dio=ostatak_sekunde/10;
		ostatak=ostatak_sekunde%10;
		
		if(fabs(sekunde_racun-sekunde)>=0.5){
		if(sekunde>=0){
		sekunde=sekunde+1;
		}
		else if(sekunde<0){
		sekunde=sekunde-1;
		}
		}
			
		else if(cijeli_dio==4 && ostatak>=5){
		if(sekunde>=0){
		sekunde=sekunde+1;
		}
		else if(sekunde<0){
		sekunde=sekunde-1;
		}
		}
			
		if(sekunde<=-60){
		sekunde=sekunde+60;
		minute=minute-1;
		}
			
		if(minute<=-60){
		minute=minute+60;
		stepeni=stepeni-1;
		}
			
		
		if(sekunde>=60){
		sekunde=sekunde-60;
		minute=minute+1;
		}
			
		if(minute>=60){
		minute=minute-60;
		stepeni=stepeni+1;
		}	 	
		
		if(sekunde<0){sekunde=0-sekunde;}
		if(minute<0){minute=0-minute;}	
		
		printf("%d stepeni %d minuta %d sekundi \n",stepeni,minute,sekunde);
	}
	return 0;
}
