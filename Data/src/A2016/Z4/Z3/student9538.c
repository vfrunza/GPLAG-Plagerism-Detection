#include <stdio.h>

 int daliimarijeci(char*s1,char*s2) {
 	char*poc=s1,*p,*q;
 	while(*s1!='\0') {
 		p=s1;q=s2;
 		while(*p++==*q++) {
 			if((s1==poc || *(s1-1)==' ') && (*q=='\0') && (*p==' ' || *p=='\0')) return 1;
 		}
 		s1++;
 	}
 	return 0; }
 	char*trazi_rijec(char*s1,char*s2) {
 		char*poc=s1;
 		char*p=s1;
 		char*q=s2;
 		while(*s1!='\0') {
 		 p=s1; q=s2;
 		 while(*p++ == *q++)
 		if(*q=='\0' && (s1==poc|| *(s1-1)==' ') && (*p==' ' || *p=='\0')) return s1;
 	s1++; }
 	return NULL; }
 	void izbaci(char*p, int vel) {
 		if (vel>0) {
 			char *r=p+vel;
 			while(*r!='\0')
 			*p++=*r++;
 			*p='\0';
 		}
 	}
 void ubaci(char*p, char*r) {
 	char*kraj=p;
 while(*kraj!='\0') kraj++;
 char*pom=r;
 int duz=0;
 while(*pom!='\0') {
 	duz++;
 	pom++;
 }
 while (kraj>=p) {
 	*(kraj+duz)=*kraj;
 	kraj--;
 }
 while(*r!='\0') {
 	*p++=*r++;
 } 
  
 }
 char* zamjena_rijeci(char*tekst,char**rijeci,char**zamjene,int broj_rijeci) {
 	char*pocetak=tekst;
 	char*s=tekst,*p,*n,*r;
 	int i;
 	int vel;
 	char*rr=rijeci[0];
 	char*zz=zamjene[0];
 	if(*rr==*zz &&*(rr+1)==*(zz+1)&&*(rr+2)==*(zz+2)) return pocetak;
 	for(i=0;i<broj_rijeci;i++) {
 	 int izbacivanje=0;
 	 char*pom=rijeci[i];
 	 int duzina=0;
 	 while(*pom!='\0') {
 	  duzina++; pom++;
 	 }
 		int vr=daliimarijeci(tekst,rijeci[i]);
 		if (vr==1)  { p=trazi_rijec(tekst,rijeci[i]);
 		izbacivanje=1;}
 		if(vr==1) {
 			izbaci(p,duzina);
 			if(izbacivanje==1) {
 				ubaci(p,zamjene[i]);
 				i--; }
 		}
 		else if(vr==0) continue;
 	}
 	return pocetak;
 }
 int main () {
 	char*rijeci[2]={"beli","sneg"};
 	char*zamjene[2]={"bijeli","snijeg"};
 	char tekst[100]="beli sneg je pokrio beli breg";
 	printf("%s",zamjena_rijeci(tekst,rijeci,zamjene,2));
 	return 0;
 }
 