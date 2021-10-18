#include <stdio.h>
#include <math.h>
#include <string.h>
void unesi(char niz[], int velicina){
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
    struct Datum stariji, mladji;
    int razlika=0, direktor_prez1=0, direktor_prez2=0, di=0, br=0, brojac=0, ki=0, i=0, br_puta=0,vel1;
    /*Direktor prezime*/
        	while(direktor.ime_prezime[di]!='\0') di++;
        	di--;
        	/*Na pocetak prezimena*/
            while(direktor.ime_prezime[di]!=' '){
        		brojac++;
        		di--;
        		/*Broj slova u drugom prezimenu*/
        		if(direktor.ime_prezime[i]=='-'){
        			direktor_prez2=brojac;
        			brojac=0;
        			di--;
        		}
        	}
        	direktor_prez1=brojac;
        	di++;
    struct Uposlenik* kraj = (kandidati + vel);
    vel1=vel;
    while(br_puta<vel1){
    	i=0;
    	br_puta++;
    	/*Trazenje starijeg po godisitma*/
    	if((*kandidati).datum_rodjenja.godina > direktor.datum_rodjenja.godina){
    		stariji = direktor.datum_rodjenja;
    		mladji = (*kandidati).datum_rodjenja;
    	}
    	else if((*kandidati).datum_rodjenja.godina < direktor.datum_rodjenja.godina){
    	    stariji = (*kandidati).datum_rodjenja;
    		mladji = direktor.datum_rodjenja;
    	}
    	
    	else {
    		/*Stariji po mjesecima*/
    		if((*kandidati).datum_rodjenja.mjesec > direktor.datum_rodjenja.mjesec){
    			stariji = direktor.datum_rodjenja;
    		    mladji = (*kandidati).datum_rodjenja;
    		}
		    else if((*kandidati).datum_rodjenja.mjesec < direktor.datum_rodjenja.mjesec){
		        stariji = (*kandidati).datum_rodjenja;
    		    mladji = direktor.datum_rodjenja;
		}
		else {
			/*Stariji po danima*/
			if((*kandidati).datum_rodjenja.dan > direktor.datum_rodjenja.dan){
    			stariji = direktor.datum_rodjenja;
    		    mladji = (*kandidati).datum_rodjenja;
    		}
		   else {
		    stariji = (*kandidati).datum_rodjenja;
    		mladji = direktor.datum_rodjenja;
		}
		}
    	}
    	
        /*Razlika u danima*/ 
        if(stariji.godina!=mladji.godina){
        	while (stariji.mjesec!=13) {
        		switch(stariji.mjesec){
        			case 1:
        			case 3:
        			case 5:
        			case 7:
        			case 8:
        			case 10:
        			case 12:
        			if(i==0) razlika+=31-stariji.dan;
        			else razlika+=31;
        			break;
        			
        			case 2:
        			if((stariji.godina%4==0 && stariji.godina%100!=0) || stariji.godina%400==0){
        				if(i==0) razlika+=29-stariji.dan;
        				else razlika+=29;
        			}
        			else{
        				if(i==0) razlika+=28-stariji.dan;
        				else razlika+=28;
        			}
        			break;
        			
        			case 4:
        			case 6:
        			case 9:
        			case 11:
        			if(i==0) razlika+=30-stariji.dan;
        			else razlika+=30;
        			break;
        		}
        		
        		stariji.mjesec++;
        		i++;
        	}
        	stariji.godina++;
        	
        	razlika+=mladji.dan;
        	mladji.mjesec--;
        	while (mladji.mjesec!=0){
        		switch(mladji.mjesec){
        	        case 1:
        			case 3:
        			case 5:
        			case 7:
        			case 8:
        			case 10:
        			case 12:
        	        razlika+=31;
        			break;
        			
        			case 2:
        			if((mladji.godina%4==0 && mladji.godina%100!=0) || mladji.godina%400==0) razlika+=29;
        			else razlika+=28;
        			break;
        			
        			case 4:
        			case 6:
        			case 9:
        			case 11:
        			razlika+=30;
        			break;
        		}
        		mladji.mjesec--;
        	}
        	
        	while(stariji.godina<mladji.godina){
        		if((stariji.godina%4==0 && stariji.godina%100!=0) || stariji.godina%400==0) razlika+=366;
        		else razlika+=365;
        		stariji.godina++;
        	}
        	}
        
        else {
        	if(stariji.mjesec!=mladji.mjesec){
        	razlika+=mladji.dan;
        	while(stariji.mjesec < mladji.mjesec){
        		switch(stariji.mjesec){
        			case 1:
        			case 3:
        			case 5:
        			case 7:
        			case 8:
        			case 10:
        			case 12:
        			if(i==0) razlika+=31-stariji.dan;
        			else razlika+=31;
        			break;
        			
        			case 2:
        			if((stariji.godina%4==0 && stariji.godina%100!=0) || stariji.godina%400==0){
        				if(i==0) razlika+=29-stariji.dan;
        				else razlika+=29;
        			}
        			else{
        				if(i==0) razlika+=28-stariji.dan;
        				else razlika+=28;
        			}
        			break;
        			
        			case 4:
        			case 6:
        			case 9:
        			case 11:
        			if(i==0) razlika+=30-stariji.dan;
        			else razlika+=30;
        			break;
        		}
        		
        		stariji.mjesec++;
        		i++;
        	}
        	}
        	else razlika+=mladji.dan-stariji.mjesec;
        }
        
        if(razlika>fabs(broj_dana)){
        	int kandidati_prez1=0, kandidati_prez2=0;
        	
        /*Kandidat prezime*/
           brojac=0;
        	while((*kandidati).ime_prezime[ki]!='\0') ki++;
        	ki--;
        	
            while((*kandidati).ime_prezime[ki]!=' '){
        		brojac++;
        		ki--;
        		/*Broj slova u drugom prezimenu*/
        		if((*kandidati).ime_prezime[ki]=='-'){
        			kandidati_prez2=brojac;
        			brojac=0;
        			ki--;
        		}
        	}
        	kandidati_prez1=brojac;
        	ki++;
            
            
        /*Provjera da li imaju isto prezime*/
           if(direktor_prez1==kandidati_prez1){
           	 while(di<di+direktor_prez1){
           	 	if(direktor.ime_prezime[di]!=(*kandidati).ime_prezime[ki]){
           	 		di-=br;
           	 		ki-=br;
           	 		br=0;
           	 		break;
           	 	}
           	 	br++;
           	 	di++;
           	 	ki++;
           	 }
           }
           
           if(br==0){
           if(direktor_prez1==kandidati_prez2){
           	ki+=(kandidati_prez1+1);
           	while(di<di+direktor_prez2){
           	 	if(direktor.ime_prezime[di]!=(*kandidati).ime_prezime[ki]){
           	 		di-=br;
           	 		ki-=(br+kandidati_prez1+1);
           	 		br=0;
           	 		break;
           	 	}
           	 	br++;
           	 	di++;
           	 	ki++;
           	 }
           }
           }
           
           
           if(br==0 && direktor_prez2!=0){
           if(direktor_prez2==kandidati_prez1){
            di+=(direktor_prez1+1);
           	while(di<(di+direktor_prez2)){
           	 	if(direktor.ime_prezime[di]!=(*kandidati).ime_prezime[ki]){
           	 		di-=(br+direktor_prez1+1);
           	 		ki-=br;
           	 		br=0;
           	 		break;
           	 	}
           	 	br++;
           	 	di++;
           	 	ki++;
           	 }
           }
           }
           
            if(br==0 && direktor_prez2!=0){
           if(direktor_prez2==kandidati_prez1){
            di+=(direktor_prez1+1);
            ki+=(kandidati_prez1+1);
           	while(di<di+direktor_prez2){
           	 	if(direktor.ime_prezime[di]!=(*kandidati).ime_prezime[ki]){
           	 		di-=(br+direktor_prez1+1);
           	 		ki-=(br+kandidati_prez1+1);
           	 		br=0;
           	 		break;
           	 	}
           	 	br++;
           	 	di++;
           	 	ki++;
           	 }
           }
           }
           
        /*Izbacivanje s liste*/
           if(br==0){
              i=0;
               while(kandidati<kraj){
                   *kandidati=*(kandidati+1);
                   kandidati++;
                   i++;
               }
               kraj--;
               vel--;
               kandidati-=i;
           }
        }
        razlika=0;
        kandidati++;
    }
    
    return vel;
}
int main() {
	struct Uposlenik direktor = {"Mujo Mujic", {3, 1, 1982} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 12, 1981 } },
    { "Pero Peric", { 1, 2, 1980 } },
    { "Sara Sarac", { 2, 2, 1980 } },
    { "Fata Mujicic", { 1, 2, 1976 } },
    { "Jozo Jozic", { 1, 1, 1982 } },
    { "Mijo Mijic", { 4, 3, 1979 } },
    { "Suljo Suljic", { 30, 12, 1981 } },
};

/* Meho Mehic je za 3 dana stariji, a Suljo Suljic za 4 dana */

int novi_br = suzi_listu(kandidati,7 , direktor, 3);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
