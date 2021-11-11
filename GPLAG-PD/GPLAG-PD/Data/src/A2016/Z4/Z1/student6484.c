#include <stdio.h>


void unesi (char niz[], int velicina){
       int i=0; 
      char znak=getchar();
      if(znak=='\n') znak=getchar();
       i=0; 
      while(i<velicina - 1 && znak != '\n'){
          niz[i]=znak;
          i++;
          znak=getchar();
      }
    niz[i]='\0';
    
    
}


void kopiraj(char *s1, char *s2) {
  
    while(*s1 != '\0') {
        if(*s1>= 'a' && *s1 <='z')
        *s2=*s1-32; 
       else  *s2=*s1; 
        s1++; 
        s2++;
         
    }
        *s2= '\0';
    
    
}


int prebroji_istu_rijec(char *s1, char *s2) {

  int brojac=0;
   char* poc = s1;
  while (*s1 != '\0') {
   char* p = s1;
   char* q = s2;
   while (*p++ == *q++)
   if (*q == '\0' &&  (s1 == poc || *(s1-1) != ((*s1<='z'&& *s1 >= 'a') || (*s1<='Z' && *s1>='A')))   &&
       (*p != ((*p<='z'&& *p >= 'a') || (*p<='Z' && *p>='A')) || *p == '\0') ) brojac++;
      s1++;
} 
return brojac; 

} 


int trazenje_najcesce(char *m) {
    char *w=m;
    int neslovo=1, broj_rijeci=0, c=0,d,najcesca,t;
    char *a;
	     	while(*m != '\0') {
			if(  !((*m >= 'A'  && *m<='Z' ) || (*m>= 'a'  && *m<='z')) ) {
			neslovo = 1;
		} else if ( neslovo==1) {
			broj_rijeci++;
			a=m; 
			d=prebroji_istu_rijec(w,a); 
			if(d>c) {
			    najcesca=d;
			    c=d;
			    t=broj_rijeci;
			    	}
			neslovo=0;
		}
		m++;
	}
	return t;
    
}




int main() {
  char string1[100], string2[100];
  int y;
  printf("Unesi string1:");
  unesi(string1,100); 
  kopiraj(string1,string2);
  y=trazenje_najcesce(string2);
  
 return 0;    
}