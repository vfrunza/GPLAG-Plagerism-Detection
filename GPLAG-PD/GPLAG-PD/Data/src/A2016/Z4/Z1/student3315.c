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
int poredjenje(char *prva_rijec, char *druga_rijec,int vel1,int vel2){
	int k;
	char*p1=prva_rijec, *p2=druga_rijec;
	if(vel1!=vel2)
		return 0;
		
	
		for(k=0;k<vel1-1;k++){
			if(*(p2+k)>='A'&&*(p2+k)<='Z'){
				if(*(p1+k)!=*(p2+k)+32)
					return 0;
				continue;
			}
		
		
		
		
		
			if(*(p2+k)>='A'&&*(p2+k)<='Z'&&*(p1+k)>='A'&&*(p1+k)<='Z'){
				if(*(p1+k)+32!=*(p2+k)+32)
					return 0;
				continue;
			}
			if(*(p1+k)>='A'&&*(p1+k)<='Z'){
				if(*(p1+k)+32!=*(p2+k))
					return 0;
				continue;
			}
			
			
			
			
			
			
			if(*(p1+k)!=*(p2+k))
					return 0;
			
			
			
			
		
	}
	
	return 1;
}
char* izbaci_najcescu(char *s){
	char *p, *pok[500];
	int i=0, j=0,brojac[500]={0}, brojac_rijeci=1, najcesca[500]={0};
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
		brojac[i]++;
		p++;
	}
	
	
	for(i=0;i<brojac_rijeci-1;i++){
		for(j=i+1;j<brojac_rijeci;j++){
			if(poredjenje(pok[i], pok[j],brojac[i], brojac[j]))
				najcesca[i]++;
		}
	}
	//u nizu imamo koliko se ponavlja rijec u nasem strigu//
	
	int max;
	max=0;
   for(i=0;i<brojac_rijeci;i++){
		if(najcesca[i]>najcesca[max]) 	
			max=i;
	}
	//clan najcesce rijeci//
	for(i=0;i<brojac_rijeci;i++){
		if(max==i) i++;
		if(poredjenje(pok[max], pok[i], brojac[max], brojac[i])){
			p=pok[i];
			if(i==brojac_rijeci-1){
				*p='\0';
				break;
			}
			while(*p!='\0'){
				*p=*(p+brojac[i]);	
				if(*p=='\0') break;
				p++;
			}
			do{
				pok[i]++;
			}while((*p>31&&*p<'A')||(*p>'Z'&&*p<'a')||(*p>'z'&&*p<127));
			for(j=i+1;j<brojac_rijeci;j++){
				pok[j]-=brojac[i];
				
			}
			
		}
		
	}
	//izbacene su ponovljene rijeci osim prve//
	p=pok[max];
	while(*p!='\0'){
		*p=*(p+brojac[max]);	
		if(*p=='\0') break;
		p++;
	}
	
	return s;
}	


int main() {
    char tekst[10000];
    printf("Unesite tekst: ");
    unesi(tekst,10000);
    printf("%s", izbaci_najcescu);
    return 0;
}

	
