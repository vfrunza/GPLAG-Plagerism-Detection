#include <stdio.h>

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

int uporedi(char *rijec1, char *rijec2,int vel1,int vel2){
	int i;
	char*p1=rijec1, *p2=rijec2;
	if(vel1!=vel2)
		return 0;
	else{
		for(i=0;i<vel1-1;i++){
			if(*(p2+i)>='A'&&*(p2+i)<='Z'&&*(p1+i)>='A'&&*(p1+i)<='Z'){
				if(*(p1+i)+32!=*(p2+i)+32)
					return 0;
				continue;
			}
			if(*(p1+i)>='A'&&*(p1+i)<='Z'){
				if(*(p1+i)+32!=*(p2+i))
					return 0;
				continue;
			}
			
			
			if(*(p2+i)>='A'&&*(p2+i)<='Z'){
				if(*(p1+i)!=*(p2+i)+32)
					return 0;
				continue;
			}
			
			
			
			if(*(p1+i)!=*(p2+i))
					return 0;
			
			
			
			
		}
	}
	return 1;
}




char* izbaci_najcescu(char *s){
	char *p, *pok[500];
	int i=0, j=0,brojac_slova[500]={0}, brojac_rijeci=1, brojac_najcesce[500]={0};
	p=s;
	pok[j]=p;
	if(*p=='\0')
		return NULL;
	while(*p!='\0'){
		if((*p>31&&*p<'A')||(*p>'Z'&&*p<'a')||(*p>'z'&&*p<127)){
			brojac_rijeci++;
			do{
				p++;
			}while((*p>31&&*p<'A')||(*p>'Z'&&*p<'a')||(*p>'z'&&*p<127));
			j++;
			i++;
			pok[j]=p;
			continue;
		}
		brojac_slova[i]++;
		p++;
	}
	// daje nam broj slova za svaku rijec i stavlja pokazivac na svaku rijec
	
	for(i=0;i<brojac_rijeci-1;i++){
		for(j=i+1;j<brojac_rijeci;j++){
			if(uporedi(pok[i], pok[j],brojac_slova[i], brojac_slova[j]))
				brojac_najcesce[i]++;
		}
	}
	//do sad je u niz brojac_najcece[i] ubacilo vrijednosti koliko puta se ponavlja rijec na mijestu u stringu s
	
	int max;
	max=0;
	for(i=0;i<brojac_rijeci;i++){
		if(brojac_najcesce[i]>brojac_najcesce[max]) 	
			max=i;
	}
	// pronasli smo za sad clan najcesce rijeci

	for(i=0;i<brojac_rijeci;i++){
		if(max==i) i++;
		if(uporedi(pok[max], pok[i], brojac_slova[max], brojac_slova[i])){
			p=pok[i];
			if(i==brojac_rijeci-1){
				*p='\0';
				break;
			}
			while(*p!='\0'){
				*p=*(p+brojac_slova[i]);	
				if(*p=='\0') break;
				p++;
			}
			do{
				pok[i]++;
			}while((*p>31&&*p<'A')||(*p>'Z'&&*p<'a')||(*p>'z'&&*p<127));
			for(j=i+1;j<brojac_rijeci;j++){
				pok[j]-=brojac_slova[i];
				
			}
			
		}
		
	}
	//izbacene su sve rijeci koje se ponavljaju osim prve
	p=pok[max];
	while(*p!='\0'){
		*p=*(p+brojac_slova[max]);	
		if(*p=='\0') break;
		p++;
	}
	
	return s;
}	
	
int main() {
	char tekst[]="1PsT1 psT2 3Pst pstpst pst";
	printf("%s",izbaci_najcescu(tekst));
	return 0;
}
