#include <stdio.h>
#include <string.h>

char *vrati_podstring(char *s){
	int i=1;
	char *poredi=s, *vrati=s, *obnovi=s, max[100]="a", osiguraj[100], *sjeti_se=s;
	strcpy(osiguraj, s);
	while(*obnovi!='\0'){
		while(*s!='\0'){
			while(*poredi!='\0'){
				poredi++;
				
				
				if(*s>='A' && *s<='Z' && *poredi>='a' && *poredi<='z'){
					if((*s)+32 == *poredi){
						*poredi='\0';
						break;
					}
				}else if(*s>='a' && *s<='z' && *poredi>='A' && *poredi<='Z'){
					if(*s==*(poredi)+32){
						*poredi='\0';
						break;
					}
				}else{
					if(*s==*poredi){
						*poredi='\0';
						break;
					}
				}
				
				
			}
			s++;
			poredi=s;
		}
		if(strlen(vrati)>strlen(max)){
			strcpy(max, vrati);
		}
		vrati++;
		obnovi++;
		s=obnovi;
		poredi=obnovi;
		strcpy(obnovi, osiguraj+(i));
		i++;
	}
	strcpy(sjeti_se, max);
	return sjeti_se;
}

void najduzi_bp(char* s1, char* s2){
	int i=0;
	char provjera[1000], max[100]="a";
	while(*s1!='\0'){
		while(*s1<'A' || *s1>'z' || (*s1>'Z' && *s1<'a')){
			if(*s1=='\0') return;
			s1++;
		}
		while((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')){
			provjera[i++]=*s1++;
			if(*s1=='\0') break;
		}
		provjera[i]='\0';
		
		if(strlen(vrati_podstring(provjera))>strlen(max)){
		strcpy(max, vrati_podstring(provjera));
		}
		
		if(*s1=='\0') continue;
		else s1++;
		i=0;
	}
	
	strcpy(s2, max);
}

int main() {
	char prva[]="Ovo je primjer";
	char druga[100];
	najduzi_bp(prva, druga);
	printf("%s", druga);
	return 0;
	
}
