#include <stdio.h>
char veliko(char s){
	if(s>='a' && s<='z') return s-32;
	return s;
}
void izbaci(char*p1, char*s1){
	while(*p1 != '\0'){
		*s1=*p1;
		s1++;
		p1++;
	}
	*s1='\0';
	
}
char* izbaci_najcescu(char*s){
	char* p=s, *pocetak_najcesce=0,*kraj_najcesce, *pocetak_trenutne=0, *kraj_trenutne, *p1;
	int max=0, rel_max=0;
	int neslovo=1;
	
	while(*p != '\0'){
		
		if(!(veliko(*p)>='A' && veliko(*p)<= 'Z')) neslovo = 1;
		else if(neslovo == 1){
			
			rel_max = 0;
			neslovo = 0;
			pocetak_trenutne = p1 = p;
			
			while(veliko(*p1)>='A' && veliko(*p1)<='Z') p1++;
			
			kraj_trenutne=p1;
			if(*kraj_trenutne=='\0') rel_max=1;
			else{
				rel_max=1;
				int neslovo;
				char* ostatak;
				neslovo=1;
				
				ostatak= kraj_trenutne + 1;
				
				while(*ostatak != '\0'){
					if(!(veliko(*ostatak)>='A' && veliko(*ostatak)<='Z')) neslovo = 1;
					
					else if(neslovo==1){
						neslovo=0;
						char* p1 = ostatak;
						
						while((veliko(*p1)>='A' && veliko(*p1)<='Z')) p1++;
						int isti=0;
						
						char* pom1=pocetak_trenutne, *pom2=ostatak;
						while(pom1 != kraj_trenutne && pom2 != p1){
							if(!(veliko(*pom1)==veliko(*pom2))) break;
							pom1++;
							pom2++;
						}
						if(pom1==kraj_trenutne && pom2==p1) isti=1;
						if(isti) rel_max++;
					}
					ostatak++;
				}
			}
			if(rel_max>max){
				pocetak_najcesce = pocetak_trenutne;
				kraj_najcesce = kraj_trenutne;
				max = rel_max;
			}
		}
		p++;
	}
	
	if(max==0) return s;
	
	char rijec[100], *q=rijec;
	while(pocetak_najcesce!=kraj_najcesce){
		*q=*pocetak_najcesce;
		q++; 
		pocetak_najcesce++;
	}
	*q='\0';
	p=s;
	while(*p != '\0'){
		if(!(veliko(*p)>='A' && veliko(*p)<='Z')) p++;
		int isti=0;
		char* pom1=p, *pom2=rijec;
		while(*pom1 != '\0' && pom2 != q){
			if(!(veliko(*pom1)==veliko(*pom2))) break;
			pom1++;
			pom2++;
	}
	if(pom2==q && !(veliko(*pom1)>='A' && veliko(*pom1)<='Z')) isti=1;
	if(isti){
		char* s1=p, *p1=pom1;
		izbaci(p1,s1);
	}
	while (veliko(*p)>='A' && veliko(*p)<='Z') p++;
}
return s;
}
int main() {
	char t[]="Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam zatvorio dekstop kompjutera stop";
	printf("%d", izbaci_najcescu(t));
	
	return 0;
}
