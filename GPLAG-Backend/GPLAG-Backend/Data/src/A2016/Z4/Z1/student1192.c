#include <stdio.h>
#include <stdio.h>

    /*Funkcija za unos stringa*/
    
void unesi(char niz[], int velicina){
	char znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\0'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

    /*Funkcija trazi iste rijeci u stringu*/
    
int uporedi(char *rijec1, char *rijec2,int velicina1,int velicina2){
	int i;
	char *pokazivac1,*pokazivac2;
	pokazivac1=rijec1;
	pokazivac2=rijec2;
	if(velicina1!=velicina2)
		return 0;
	else{
		for(i=0;i<velicina1-1;i++){
			if(*(pokazivac1+i)>='A'&&*(pokazivac1+i)<='Z'){
				if(*(pokazivac1+i)+32!=*(pokazivac2+i))
					return 0;
				continue;
			}
			
			if(*(pokazivac2+i)>='A'&&*(pokazivac2+i)<='Z'){
				if(*(pokazivac1+i)!=*(pokazivac2+i)+32)
					return 0;
				continue;
			}
			
			if(*(pokazivac2+i)>='A'&&*(pokazivac2+i)<='Z'&&*(pokazivac1+i)>='A'&&*(pokazivac1+i)<='Z'){
				if(*(pokazivac1+i)+32!=*(pokazivac2+i)+32)
					return 0;
				continue;
			}
			
			if(*(pokazivac1+i)!=*(pokazivac2+i))
					return 0;
		}
	}
	return 1;
}

    /*Funkcija izbacuje najcescu rijec koju pronadje*/
char* izbaci_najcescu(char *string){
	char *reset, *pok[100];
	int i=0, j=0,max=0,brojac_slova[100]={0}, brojac_rijeci=1, brojac_najcesce[100]={0};
	reset=string;
	pok[j]=string;
	if(*string=='\0')
		return 0;
		
    /*Stavljamo pokazivac na svaku rijec i brojimo slova svake rijeci*/		
	while(*string!='\0'){
		if((*string>31&&*string<'A')||(*string>'Z'&&*string<'a')||(*string>'z'&&*string<127)){
			brojac_rijeci++;
			do{
				string++;
			}while((*string>31&&*string<'A')||(*string>'Z'&&*string<'a')||(*string>'z'&&*string<127));
			j++;
			i++;
			pok[j]=string;
			continue;
		}
		brojac_slova[i]++;
		string++;
	}
	
	/*Brojimo rijeci koje se ponavljaju*/
	for(i=0;i<brojac_rijeci-1;i++){
		for(j=i+1;j<brojac_rijeci;j++){
			if(uporedi(pok[i], pok[j],brojac_slova[i], brojac_slova[j]))
				brojac_najcesce[i]++;
		}
	}
	
	/*Trazimo koja je rijec najvise puta ponovljena*/
	for(i=0;i<brojac_rijeci;i++){
		if(brojac_najcesce[i]>brojac_najcesce[max]) 	//fali uslov kada se neka rijec ponavlja isti broj puta
			max=i;
	}
	
	/*Izbacujemo sva ponavljanja najcesce rijeci u stringu*/
	for(i=0;i<brojac_rijeci;i++){
		if(max==i) i++;
		if(uporedi(pok[max], pok[i], brojac_slova[max], brojac_slova[i])){
			string=pok[i];
			if(i==brojac_rijeci-1){
				*string='\0';
				break;
			}
			while(*string!='\0'){
				*string=*(string+brojac_slova[i]);	
				if(*string=='\0') break;
				string++;
			}
			do{
				pok[i]++;
			}while((*string>31&&*string<'A')||(*string>'Z'&&*string<'a')||(*string>'z'&&*string<127));
			for(j=i+1;j<brojac_rijeci;j++){
				pok[j]-=brojac_slova[i];
				
			}
		}
	}
	
	/*Izbacujemo jos samo prvo pojavljivanje najcesce rijeci*/
	string=pok[max];
	while(*string!='\0'){
		*string=*(string+brojac_slova[max]);	
		if(*string=='\0') break;
		string++;
	}
	
	return reset;
}
int main() {
	char string[]="You ____will---never,never,!!.never walk alone,....alone";
	printf("%s",izbaci_najcescu(string));
	return 0;
}
