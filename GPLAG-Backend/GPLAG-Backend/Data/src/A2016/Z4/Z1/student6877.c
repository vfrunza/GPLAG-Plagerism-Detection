#include <stdio.h>
void unesi (char niz[] , int velicina){
	char znak;
	int i=0;
	znak = getchar();
	if (znak=='\n') znak= getchar();
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
int uporedi (char *string1, char *string2, int velicina1, int velicina2){
	char *p1=string1;
	char *p2=string2;
	int i;
	if (velicina1!=velicina2) return 0;
	else {
		for(i=0;i<velicina1-1;i++)
		{
			if(*(p1+i)>='A' && *(p1+i)<='Z'){
			if(*(p1+i)+32!=*(p2+i)) return 0;
		    continue;
			}
		    if(*(p2+i)>='A' && *(p2+i)<='Z'){
		    if(*(p2+i)!=*(p2+i)+32) return 0;
		    continue;
		    }
		if(*(p1+i)!=*(p2+i)) return 0;
		}
		
	}
	return 1;
}
char* izbaci_najcescu(char *s){
	char*p , *pokazivac[100];
	int i=0,j=0,brojac_slova[100]={0},brojac_rijeci=1,brojac_najcesce[100]={0};
	p=s;
	pokazivac[j]=p;
	if (*p!='\0') return NULL;
	while(*p!='\0'){
		if ((*p>31 && *p<'A') || (*p>'Z' && *p<'a') || (*p>'z' && *p<127)){
			brojac_rijeci++;
			do{
				p++;
			}while((*p>31 && *p<'A') || (*p>'Z' && *p<'a') || (*p>'z' && *p<127));
			i++;
			j++;
			pokazivac[j]=p;
			continue;
		}
		brojac_slova[i]++;
		p++;
	}
	for(i=0;i<brojac_rijeci-1;i++){
		for(j=i+1;j<brojac_rijeci;j++){
			if(uporedi(pokazivac[i],pokazivac[j],brojac_slova[i],brojac_slova[j]))
			brojac_najcesce[i]++;
		}
	}
	int max;
	max=0;
	for(i=0;i<brojac_rijeci;i++){
		if(brojac_najcesce[i]>brojac_najcesce[max]) max=i; 
	}
	for(i=0;i<brojac_rijeci;i++){
		if(max==i) i++;
		if(uporedi(pokazivac[max],pokazivac[i],brojac_slova[max],brojac_slova[i])){
			p=pokazivac[i];
			if(i==brojac_rijeci-1){
				*p='\0';
				break;
			}
			while(*p!='\0'){
				*p=*p(brojac_slova[i]);
				if(*p=='\0') break;
				p++;
			}
			do{
				pokazivac[i]++;
			}while((*p>31 && *p<'A') || (*p>'Z' && *p<'a') || (*p>'z' && *p<127));
			for(j=i+1;j<brojac_rijeci;j++){
				pokazivac[j]-=brojac_slova[i];
			}
			
		}
	}
	p=pokazivac[max];
	while (*p!='\0') {
		*p=*p(brojac_slova[max]);
		if(*p=='\0') break;
		p++;
	}
		
	return s;	
	
	
}
	
	



int main() {
	char tekst[]="asd ddd asd  ddd asd trzhrth";
	printf("%s",izbaci_najcescu(tekst));
	
	return 0;
}
