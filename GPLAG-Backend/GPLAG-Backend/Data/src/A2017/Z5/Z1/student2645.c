#include <stdio.h>
	
	struct Datum { int dan, mjesec, godina; };
	struct Uposlenik {
		char ime_prezime[50];
		struct Datum datum_rodjenja;
	};
	int prestupna(int god){
		if((god%100!=0) && (god%4==0 ) || god%400==0) return 1;
		return 0;
	}
	
	
	
	int razlika (struct Datum d1, struct Datum d2){
		int bdum[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		int god1=d1.godina;
		int god2=d2.godina;
		int mj1=d1.mjesec;
		int mj2=d2.mjesec;
		int dan1=d1.dan;
		int dan2=d2.dan;
		int dan=dan1-dan2;
		int mj=mj1-mj2;
		int god=god1-god2;
		int brdana=0;
		int prestup=0;
		
		if(god>0){
			while(god2!=god1){
				if(prestupna(god2)) {brdana+=366; prestup=1;}
				else brdana+=365;
				god2++;
			}
		}
		
		if(god<0){
			while(god1!=god2){
				if(prestupna(god1)) {brdana-=366; prestup=1;}
				else brdana-=365;
				god1++;
			}
		}
		if(god==0) {
			prestup=prestupna(god1);
		
		}
		if(mj>0){
			while(mj2!=mj1){
				if(prestup==1 && mj2==2) brdana+=bdum[mj2]+1;
				else brdana+=bdum[mj2];
			
			mj2++;
			}
		}
		
		if(mj<0){
			while(mj1!=mj2){
				if(mj1==2 && prestup==1) brdana-=bdum[mj1]+1;
				else brdana-=bdum[mj1];
				mj1++;
			}
		}
		
		brdana+=dan;
		
	
		
		return brdana;
		
	}
	
	int prezime(struct Uposlenik dir, struct Uposlenik rad){
		char *p=dir.ime_prezime;
		char *q=rad.ime_prezime;
		int crticap=0,crticaq=0;
		char *pom, *pomp, *pomq;
		char *pocp1, *pocp2;
		char *pocq1, *pocq2;
		char *pompocp1, *pompocp2, *pompocq1, *pompocq2;
		
		int isti1=1, isti2=1, kraj1=0, kraj2=0;
		
		/*direktor*/
		
		pom=p;
		while(*pom!='\0'){
			if(*pom=='-') crticap=1;
			pom++;
		}
		
		/*radnik*/
		
		pom=q;
		while(*pom!='\0'){
			if(*pom=='-') crticaq=1;
			pom++;
		}
		
		/* za direktora*/
		
		if(crticap==1) {
			pomp=p;
			while(*pomp!='\0'){
				if(*pomp==' ') pocp1=pomp;
				if(*pomp=='-') pocp2=pomp;
				pomp++;
			}
			pocp1++; /* pokazuje na poc prvog prezimena direktora*/
			pocp2++; /* pokazuje na poc drugog prezimena direktora*/
		}
		else {
			pomp=p;
			while(*pomp!='\0') pomp++; /* pomp pokazuje na kraj \0*/
			while(*pomp!=' ') pomp--; /* vracamo pomp do prvog razmaka*/
			pomp++;
			pocp1=pomp; /*pokazuje na prvo slovo prezimena*/
		}
		
		/*za radnika*/
		
		if(crticaq==1) {
			pomq=q;
			while(*pomq!='\0'){
				if(*pomq==' ') pocq1=pomq;
				if(*pomq=='-') pocq2=pomq;
				pomq++;
			}
			pocq1++; /* pokazuje na poc prvog prezimena radnika*/
			pocq2++; /* pokazuje na poc drugog prezimena radnika*/
		}
		else {
			pomq=q;
			while(*pomq!='\0') pomq++; /* pomp pokazuje na kraj \0*/
			while(*pomq!=' ') pomq--; /* vracamo pomp do prvog razmaka*/
			pomq++;
			pocq1=pomq; /*pokazuje na prvo slovo prezimena*/
		}
		
		if (crticap==1){
			if(crticaq==1){
				
				/*poredimo prvo prezime direktora sa prvim i drugim prezimenom radnika*/
				
				pompocp1=pocp1;
				pompocp2=pocp2;
				pompocq1=pocq1;
				pompocq2=pocq2;
				
				while(*pocp1!='-'){
					if(*pocp1!=*pocq1) isti1=0;
					if(*pocp1!=*pocq2) isti2=0;
					if(*pocq1=='-') kraj1=1;
					if(*pocq2=='\0') kraj2=1;
					if(isti1==0 && isti2==0) break;
					if(kraj1==0) pocq1++;
					if(kraj2==0) pocq2++;
					pocp1++;
				}
				
				if((isti1==1 || isti2==1) && (*pocq1=='-' || *pocq2=='\0')) return 1;
				
				/*poredimo drugo prezime direktora sa prvim i drugim prezimenom radnika*/
				pocp1=pompocp1;
				pocp2=pompocp2;
				pocq1=pompocq1;
				pocq2=pompocq2;
				
				while(*pocp2!='\0'){
					if(*pocp2!=*pocq1) isti1=0;
					if(*pocp2!=*pocq2) isti2=0;
					if(*pocq1=='-') kraj1=1;
					if(*pocq2=='\0') kraj2=1;
					if(isti1==0 && isti2==0) break;
					if(kraj1==0) pocq1++;
					if(kraj2==0) pocq2++;
					pocp2++;
				}
				
				if((isti1==1 || isti2==1) && (*pocq1=='-' || *pocq2=='\0')) return 1;
				
				
				
			}
			else{
			
				
				/* poredimo prezime radnika sa prvim i drugim prezimenom direktora*/
				
				while(*pocq1!='\0'){
					if(*pocq1!=*pocp1) isti1=0;
					if(*pocq1!=*pocp2) isti2=0;
					if(*pocp1=='-') kraj1=1;
					if(*pocp2=='\0') kraj2=1;
					if(isti1==0 && isti2==0) break;
					if(kraj1==0) pocp1++;
					if(kraj2==0) pocp2++;
					pocq1++;
				}
				
				if((isti1==1 || isti2==1) && (*pocp1=='-' || *pocp2=='\0')) return 1;
				
				
			}
		}
		else{
			if(crticaq==1){
				
				/*poredimo prezime direktora sa prvim i drugim prezimenom radnika*/
				
				while(*pocp1!='\0'){
					if(*pocp1!=*pocq1) isti1=0;
					if(*pocp1!=*pocq2) isti2=0;
					if(*pocq1=='-') kraj1=1;
					if(*pocq2=='\0') kraj2=1;
					if(isti1==0 && isti2==0) break;
					if(kraj1==0) pocq1++;
					if(kraj2==0) pocq2++;
					pocp1++;
				}
				
				if((isti1==1 || isti2==1) && (*pocq1=='-' || *pocq2=='\0')) return 1;
				
					
			}
			else{
				
				/* poredimo prezime direktora i prezime radnika*/
				
				while(*pocp1!='\0' && *pocq1!='\0'){
					if(*pocp1!=*pocq1) {isti1=0; break;}
					pocq1++;
					pocp1++;
				}
				
				if(isti1==1 && *pocq1=='\0') return 1;
				
			}
		}
		
		return 0;
		
	}
	
	int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
		int raz=0;
		int pre=0;
		int i=0,j;
		for(i=0;i<vel;i++){
			raz=razlika(direktor.datum_rodjenja,kandidati[i].datum_rodjenja);
			pre=prezime(direktor,kandidati[i]);
			if(pre==0 && raz>broj_dana) {
				
				/*izbacivanje*/
				
				for(j=i;j<vel-1;j++){
					kandidati[j]=kandidati[j+1];
				}
				i--;
				vel--;
				
			}
			
		}
		return vel;
	}
	

	
	

int main() {
struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1900} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1900 } },
    { "Pero Peric", { 1, 2, 1900 } },
    { "Sara Sarac", { 2, 2, 1900 } },
    { "Fata Mujic", { 1, 2, 1896 } },
    { "Jozo Jozic", { 1, 10, 1900 } },
    { "Mijo Mijic", { 4, 3, 1899 } },
    { "Suljo Suljic", { 15, 1, 1902 } },
};

int novi_br = suzi_listu(kandidati, 7, direktor, 28);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
