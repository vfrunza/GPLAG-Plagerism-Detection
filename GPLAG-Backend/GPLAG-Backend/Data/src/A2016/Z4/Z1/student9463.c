#include <stdio.h>
#include <ctype.h>
#define D 100
#define V 100

int izbaci (char *s1, char *s2, int vel){
	int isti=1;
	char *temp_a, *temp_b, *start=s1, *start2=s2;
	while(*s1){
		s2=start2;
		if(toupper(*s1)==toupper(*s2) && ((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z'))){
			isti=1; temp_a=s1;
			while(((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) && *s2!='\0'){
				if(toupper(*s1)!=toupper(*s2)) isti=0;
				s1++; s2++;
			}
			if(*s2!='\0' && *s1=='\0')
				isti=0;
			if((*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z')) isti=0;
			if((*s2>='A' && *s2<='Z') || (*s2>='a' && *s2<='z')) isti=0;
			if(isti==1){
				temp_b=temp_a+vel;
				while(*temp_a++ = *temp_b++);
				s1=start;
			}
			else if(*s1!='\0')
				s1++;
		}
		else
			s1++;
	}
	return 1;
}

int compare (char *s1, char *s2){
	char *p1=s1, *p2=s2;
	if(toupper(*p1)==toupper(*p2)) return 1;
	while(*p1){
		if(toupper(*p1)!=toupper(*p2)) return 0;
		p1++;
		p2++;
	}
	if(*p2!=0) return 0;
	return 1;
}

char* izbaci_najcescu(char* s) {
	char *start=s, *niz_pok[200], ponavlja[200];
	int i, br_slova[50]={0}, br_ponavljanja[50]={0}, max_rijec=0, brr=0, neslovo=1, provjera_ponavljanja;
	while(*s){
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
			neslovo=1;
		}else if(neslovo==1){
			neslovo=0; provjera_ponavljanja=0;
			for(i=0; i<brr; i++){
				if(compare(s, niz_pok[i])){
					br_ponavljanja[i]++;
					provjera_ponavljanja=1;
					break;
				}
			}
			if(provjera_ponavljanja) continue;
			niz_pok[brr]=s;
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
				br_slova[brr]++;
				s++;
			}
			brr++;
			s--;
		}
		s++;
	}
	
	for(i=0; i<brr; i++){
		if(br_ponavljanja[i]>max_rijec) max_rijec=i;
	}
	
	for(i=0; i<br_slova[max_rijec]; i++){
		ponavlja[i]= toupper(*(niz_pok[max_rijec]+i));
	}ponavlja[i]=0;
	izbaci(start, ponavlja, br_slova[max_rijec]);
	return start;
}

int main() {
	char t[]=" Koristio sam auto stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
	printf("'%s'", izbaci_najcescu(t));
	return 0;
}
