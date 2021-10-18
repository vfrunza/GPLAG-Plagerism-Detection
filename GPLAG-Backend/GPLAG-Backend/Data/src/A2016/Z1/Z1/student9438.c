#include <stdio.h>
#define MAXP 20.0
#define MINP 0.0
#define MAXZAV 40.0
#define MINZAV 0.0
#define MAXPRI 10.0
#define MINPRI 0.0
#define MAXZAD 10.0
#define MINZAD 0.0
#define GRANICA 55.0

int main() {
	float TP1, TP2, TZAV, TPRI, TZAD, Tbod, BP1, BP2, BZAV, BPRI, BZAD, Bbod, MP1, MP2, MZAV, MZAD, MPRI, Mbod;
	int ocjenaT, ocjenaM, ocjenaB;
	printf("Unesite bodove za Tarika:\n" );
	printf("I parcijalni ispit: \n");
	scanf("%f", &TP1);
	printf("II parcijalni ispit: \n");
	scanf("%f", &TP2);
	printf("Prisustvo: \n");
	scanf("%f", &TPRI);
	printf("Zadace: \n");
	scanf("%f", &TZAD);
	printf("Zavrsni: \n");
	scanf("%f", &TZAV);
	 
		if(TP1<MINP || TP1>MAXP || TP2<MINP || TP2>MAXP || TZAV<MINZAV || TZAV>MAXZAV || TZAD<MINZAD || TZAD>MAXZAD || TPRI<MINPRI || TPRI>MAXPRI){
		printf("Pogrešan broj bodova.\n");
		return 0;
		}
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: \n");
	scanf("%f", &BP1);
	printf("II parcijalni ispit: \n");
	scanf("%f", &BP2);
	printf("Prisustvo: \n");
	scanf("%f", &BPRI);
	printf("Zadace: \n");
	scanf("%f", &BZAD);
	printf("Zavrsni: \n");
	scanf("%f", &BZAV);
	
	if(BP1<MINP || BP1>MAXP || BP2<MINP || BP2>MAXP || BZAV<MINZAV || BZAV>MAXZAV || BZAD<MINZAD || BZAD>MAXZAD || BPRI<MINPRI || BPRI>MAXPRI){
		printf("Pogrešan broj bodova.\n");
		return 0;
		}
	
	printf("Unesit bodove za Mirzu: \n");
	printf("I parcijalni ispit: \n");
	scanf("%f", &MP1);
	printf("II parcijalni ispit: \n");
	scanf("%f", &MP2);
	printf("Prisustvo: \n");
	scanf("%f", &MPRI);
	printf("Zadace: \n");
	scanf("%f", &MZAD);
	printf("Zavrsni: \n");
	scanf("%f", &MZAV);
	
	if(MP1<MINP || MP1>MAXP || MP2<MINP || MP2>MAXP || MZAV<MINZAV || MZAV>MAXZAV || MZAD<MINZAD || MZAD>MAXZAD || MPRI<MINPRI || MPRI>MAXPRI){
		printf("Pogrešan broj bodova.\n");
		return 0;
		}
	
	Tbod= BP1+ BP2+ BZAV+ BZAD+ BPRI;
	Mbod= MP1+ MP2+ MZAV+ MZAD+ MPRI;
	Bbod= BP1+ BP2+ BZAV+ BZAD+ BPRI;
	

if((Tbod>=GRANICA) && (Bbod>=GRANICA) && (Mbod>=GRANICA))
	{
		printf("Sva tri studenta su polozila ispit.\n");
	}
		else if((Tbod>=GRANICA && Bbod>=GRANICA && Mbod<=GRANICA) || (Tbod>=GRANICA && Bbod<=GRANICA && Mbod>=GRANICA) || (Tbod<=GRANICA && Bbod>=GRANICA && Mbod>=GRANICA)){
			printf ("Dva su studenta položila ispit.\n");
			
		}
		
		else if((Tbod>=GRANICA && Bbod<=GRANICA && Mbod<=GRANICA) || (Tbod<=GRANICA && Bbod<=GRANICA && Mbod>=GRANICA) || (Tbod<=GRANICA && Bbod>=GRANICA && Mbod<=GRANICA)) {
			printf("Jedan student je položio ispit.\n");
		}
				else{
					printf("Nijedan student nije polozio ispit.\n");
				}
	
	

/**	
			
	if(Tbod>=55 && Tbod<65){
			printf("Tarik je dobio ocjenu 6\n");
		}
			
			else if(Tbod>=65 && Tbod<75){
				printf("Tarik je dobio ocjenu 7\n");
			}
			
			else if(Tbod>=75 && Tbod<85){
				printf("Tarik je dobio ocjenu 8\n");
				
			}
			
			else if(Tbod>=85 && Tbod<95){
				
				printf("Tarik je dobio ocjenu 9\n");
			}
			
			else if(Tbod>=95 && Tbod<=100){
			printf("Tarik je dobio ocjenu 10\n");
			}
			
			else{
				printf("Tarik je pao ispit\n");
			}
	if(Bbod>=55 && Bbod<65){
			printf("Bojan je dobio ocjenu 6\n");
		}
			
			else if(Bbod>=65 && Bbod<75){
				printf("Bojan je dobio ocjenu 7\n");
			}
			
			else if(Bbod>=75 && Bbod<85){
				printf("Bojan je dobio ocjenu 8\n");
				
			}
			
			else if(Bbod>=85 && Bbod<95){
				
				printf("Bojan je dobio ocjenu 9\n");
			}
			
			else if(Bbod>=95 && Bbod<=100){
			printf("Bojan je dobio ocjenu 10\n");
			}
			
			else{
				printf("Bojan je pao ispit\n");
			}		
	if(Mbod>=55 && Mbod<65){
			printf("Mirza je dobio ocjenu 6\n");
		}
			
			else if(Mbod>=65 && Mbod<75){
				printf("Mirza je dobio ocjenu 7\n");
			}
			
			else if(Mbod>=75 && Mbod<85){
				printf("Mirza je dobio ocjenu 8\n");
				
			}
			
			else if(Mbod>=85 && Mbod<95){
				
				printf("Mirza je dobio ocjenu 9\n");
			}
			
			else if(Mbod>=95 && Mbod<=100){
			printf("Mirza je dobio ocjenu 10\n");
			}
			
			else{
				printf("Mirza je pao ispit\n");
			}		
			
			**/
    ocjenaT=Tbod/10;
	ocjenaB=Bbod/10;
	ocjenaM=Mbod/10;
if(ocjenaB==ocjenaT && ocjenaT==ocjenaM){
	
	printf("Sva tri studenta imaju istu ocjenu\n");
}

else if((ocjenaM==ocjenaT && ocjenaM!=ocjenaB ) || (ocjenaM==ocjenaB && ocjenaM!=ocjenaB ) || (ocjenaM!=ocjenaT && ocjenaM==ocjenaB ))
	{
		printf("Dva od tri studenta imaju istu ocjenu\n");
	}
else{ 
	
	printf("Svi studenti imaju različitu ocjenu\n");}
	
	return 0;
}
