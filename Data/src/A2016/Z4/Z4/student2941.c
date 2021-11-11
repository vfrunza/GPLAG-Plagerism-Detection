#include <stdio.h>
#include <string.h>
#define epsilon 0.0001


int provjera_ispravnosti(char* pocetak) {
	char* p, *s1; 
	int imalzareza=0;
	p=pocetak;
	if(p[0] != '(') return 1;
	p++;
	s1=p;
	while(*s1 != ')' && *s1 != '\0'){ 
		if(*s1 == ',') imalzareza++; 
		if(imalzareza>0)  break;
		s1++;
	}
	if(imalzareza==0) return 1;
	if(imalzareza!=0) imalzareza=0;
	while(*p != '\0') {
		
		if(*p == '(') { 
			s1=p; 
			while(*s1 != ')' && *s1 != '\0'){
				if(*s1 == ',') imalzareza++; 
				if(imalzareza>0) break; 
				s1++;
				} 
		if(imalzareza==0) return 1;
		if(imalzareza!=0) imalzareza=0;
		}
		if(!(*p=='(' || *p==')' || *p=='.' || *p==',' || *p=='-' || (*p>='0' && *p<='9'))) return 1;
		if(*p == '.'){ if(!((*(p-1)>='0' && *(p-1)<='9') && ((*(p+1)>='0' && *(p+1)<='9') || *(p+1)==',' || *(p+1)==')' ))) return 1; }
		if(*p == '-') { if(!((*(p-1)=='(' || *(p-1)==',') && (*(p+1)>='0' && *(p+1)<='9'))) return 1; }
		if(*p == ',' && *(p+1)!= '(' && *(p-1) != ')') { if(!(((*(p-1)>= '0' && *(p-1)<= '9') || *(p-1)=='.') && ((*(p+1)>= '0' && *(p+1)<= '9') || *(p+1)=='-'))) return 1; }
		if(*p == ',' && *(p+1)!= '(' && *(p-1) != ')') { s1=p; s1++; while( *s1 != ')' && *s1!= '\0') { if(*s1 == ',') return 1; s1++; } }
		if(*p == ',' && (*(p+1)== '(' || *(p-1) == ')')) { if(!(*(p-1)==')' && *(p+1)=='(')) return 1; }
		if(*p == '(') { if(!((*(p-1)== ',') && ((*(p+1)>='0' && *(p+1)<='9') || *(p+1)== '-')))  return 1; }
		if(*p == ')') { if(!((*(p+1)== ',' || *(p+1)== '\0') && ((*(p-1)>='0' && *(p-1)<='9') || *(p-1)== '.')))  return 1; }
		p++;
		if(*p == '\0') if(*(p-1) != ')') return 1;
	
	}
	return 0;
}
char* obuhvat(char* koordinate,float x1, float y1, float x2, float y2){
	float a=0,b=0,d=1;
	char* p1, *p2;
	char* p;
	int negativan=0,br=0;
	p=koordinate;
	if(provjera_ispravnosti(p)) return NULL;
	p=koordinate;
	while(*p != '\0') {
		if(*p == '(' ) {
			p1=p;
			p++;
			a=0;
			if(*p == '-')  { p++; negativan=1; }
			while((*p>='0' && *p<='9') || *p != ',') {
				if(*p == '.'){
					d=10;
					p++;
					if(*p== ',') break;
					while(*p != ','){
						a+=(*p-48)/d;
						d*=10;
						p++;
					}
				}
				if(*p== ',') break;
				a=a*d+(*p-48);
				
				d=10;
				p++;
			}
			
			
		}
		if(negativan==1) { a=a*(-1); negativan=0; }
			
		d=1;
		b=0;
		if(*p == ',' && *(p+1) != '(' ) {
			p++;
			if(*p == '-') { p++; negativan=1; }
			while((*p>='0' && *p<='9') || *p != ')') {
				if(*p == '.'){
					
					d=10;
					p++;
					if(*p== ')') break;
					else {while(*p != ')'){
						b+=(*p-48)/d;
						d*=10;
						p++;
						
					}
				}
				}
				if(*p== ')') break;
				b=b*d+(*p-48);
				
				d=10;
				p++;
			}
		}
		if(negativan==1) { b=b*(-1); negativan=0; }
		while( *p != '(') {p++; if( *p == '\0') break; }
		p2=p;
		br++;
		if(!(( a>=x1 && a<=x2)  && (b>=y1 && b<=y2))) {
			br--;
			if(*p == '\0') { 
				p-=2; 
				if(br>0) {
					while(*p != ')') { 
					*p--='\0'; 
					
				
			} 
				}
				while(*p != ')' && p!=p1) { 
					*(--p)='\0'; 
					
				
			} 
			if(br!=0) 
			
			return koordinate;
			}
			while ( p != p1) {
				
				p2=p;
				while(*p2 != '\0') {
					 
					*(p2-1)=*p2;
					p2++;
					if (*p2 == '\0') *(p2-1)='\0';
				}
				
				
				p--;
			}
			a=0; b=0;
		}
		
	}
	
	
	return koordinate;
}

int main() {
	char s[] = "(1.1,5.5),(1.2,5.5),(1.3,5.5),(1.4,5.5),(1.5,5.5)";
char* rez = obuhvat(s, 1.2, 5.499, 1.4, 5.501);
printf("%s", rez);
	return 0;
}
