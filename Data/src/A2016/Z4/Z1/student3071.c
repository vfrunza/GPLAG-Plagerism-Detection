#include <stdio.h>

void unesi( char *s, int vel){
    char znak=getchar();
    if (znak == '\n') znak = getchar();
    int i=0;
    while(i<vel && znak!='\n'){
        *(s+i)=znak;
        i++;
        znak=getchar();
    }
    *(s+i)='\0';
}


//br_ponavljanja_u_stringu uzima prvo argument
//rijec pa tek onda string u kojem se ona trazi
int br_ponavljanja_u_stringu( char *rijec, char *s){
	int broj=0;
	while(*s!='\0'){
		char *p=s;
		char *q=rijec;
		int i=0;
		while(*p == *q){
			p++; q++;
			if(*q=='\0') {
				broj++;
				q=rijec;
			}
		}
		s++;
	}
	return broj;
}


void izbaci_rijec(char *s, char *stara_rijec){
    int i, j, duzina_stringa=0, duzina_rijeci_za_izbaciti=0;
    int found;
    char *string=s;
	char *rijec=stara_rijec;
	//logicka za nadjeno postaje 1
	int logicka=0;
	while(*string!='\0'){
		duzina_stringa++;
		string++;
	}
	while(*rijec!='\0'){
		duzina_rijeci_za_izbaciti++;
		rijec++;
	}

    for(i=0; i<=duzina_stringa - duzina_rijeci_za_izbaciti; i++){
    found = 1;
    for(j=0; j<duzina_rijeci_za_izbaciti; j++){
    if(s[i + j] != stara_rijec[j]){
        found = 0;
        break;
    }
}
    if(found == 1){
        for(j=i; j<duzina_stringa - duzina_rijeci_za_izbaciti; j++){
    s[j] = s[j + duzina_rijeci_za_izbaciti];
    }
s[j] = '\0';
duzina_stringa = duzina_stringa - duzina_rijeci_za_izbaciti;
}
}
}


char *izbaci_najcescu( char *s){
	int max;
 char rijec[20];
 char *temp_rijec;
 temp_rijec=rijec;

 char rijec_naj_ponavljanja[20];
 char *temp_rijec_naj_ponavljanja;
 temp_rijec_naj_ponavljanja=rijec_naj_ponavljanja;

 char *temp_s;
 temp_s=s;

 char *pom_s;
 pom_s=s;
 char nova_rijec[50];
 char *ptr_nova_rijec=nova_rijec;
 char stara_rijec[50];
 char *ptr_stara_rijec=stara_rijec;

 int neslovo=1, broj_rijeci=0, br_slova=0;
 while (*pom_s != '\0') {

 	if ( !(*pom_s >= 'A' && *pom_s <= 'Z' || *pom_s >= 'a' && *pom_s <= 'z') )
 	neslovo = 1;
 	else if (neslovo == 1) {
 		neslovo = 0;
 		broj_rijeci++;
 		}
 		if ( (*pom_s >= 'A' && *pom_s <= 'Z') || (*pom_s >= 'a' && *pom_s <= 'z') ){
 			br_slova++;
 			stara_rijec[br_slova-1]=*pom_s;
 		} else {
 			stara_rijec[br_slova]='\0';
			max=br_ponavljanja_u_stringu(stara_rijec,s);
 			br_slova=0;
 			if(*stara_rijec!='\0')
 			break;
 		}
 		pom_s++;

 	}
while(*pom_s!='\0'){
 	if ( !(*pom_s >= 'A' && *pom_s <= 'Z' || *pom_s >= 'a' && *pom_s <= 'z') )
 	neslovo = 1;
 	else if (neslovo == 1) {
 		neslovo = 0;
 		broj_rijeci++;
 		}
 		if ( (*pom_s >= 'A' && *pom_s <= 'Z') || (*pom_s >= 'a' && *pom_s <= 'z') ){
 			br_slova++;
 			nova_rijec[br_slova-1]=*pom_s;
 		} else {
 			nova_rijec[br_slova]='\0';
 			int broj=br_ponavljanja_u_stringu(nova_rijec,s);
 			if(broj>max){
 				max=broj;
 				ptr_stara_rijec=ptr_nova_rijec;


 			}
 			br_slova=0;
 				//if(*nova_rijec!='\0')
                  //  break;

 		}
 		pom_s++;
}
 		izbaci_rijec(s,ptr_stara_rijec);
 	return s;
 	}




int main() {
	//printf("Zadaća 4, Zadatak 1");
	char A[200];
	unesi(A,200);
	printf("%s",izbaci_najcescu(A));
	return 0;
}
