#include <stdio.h>

/*funkcija koja broji koliko ima karaktera u stringu*/
int kolko(char*s){
	char*p=s;
	int brojac=0;
	while(*p!='\0'){
		p++;brojac++;
	}
	return brojac;
}
/*funkcija koja izbacuje poslanu rijec iz poslanog stringu*/
void f(char*s, char*r){
	int duzina=kolko(r);
	char*s1=s;
	char*pomp=s;
	
	while(*s1!='\0'){
    	char*r2=r;
    	char*p2=s1;
    	while(((*p2==*r2)||(*p2==*r2-32)||(*p2==*r2+32))&&*r2!='\0'){
				p2++;r2++;
				if(s1==s){
					if(*r2=='\0' && !(*p2 >= 'A' && *p2 <= 'Z') && !(*p2 >= 'a' && *p2 <= 'z'))
					pomp=s1;
					while(*(pomp+duzina)!='\0'){
						*pomp=*(pomp+duzina);
						pomp++;
					}
					*pomp=*(pomp+duzina);

				}			
				else if(*r2=='\0' && (!(*p2 >= 'A' && *p2 <= 'Z') && !(*p2 >= 'a' && *p2 <= 'z')) && !(*(s1-1)>='a' && *(s1-1)<='z') && !(*(s1-1)>='A' && *(s1-1)<='Z')){
				    pomp=s1;
					while(*(pomp+duzina)!='\0'){
						*pomp=*(pomp+duzina);
						pomp++;
					}
					*pomp=*(pomp+duzina);
				}
		   }
    	s1++;	
   }
}
char* izbaci_najcescu(char*s){
    char*p=s;
    char*k=s;
    char*a=s;
    char*b=s;
    char*p1=s;
    int duzina=0,i=0,brojac=0;
    char rijec[10000];
    char max_rijec[10000];
    int max=0;
    int provjerim=kolko(s);
    if(provjerim==0){
    	return p;
    }
    

    while(*s!='\0'){
    	k=s;
    	while(!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))){
			if(*s=='\0') 
				break;
			s++;}
			
		if(*s=='\0'){ 
			if(k==p)  
				return p;
		    break;}
		a=s;
		b=s;
		duzina=0;
		brojac=0;
		
		while((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))	{
			 if(*s=='\0') 
		  		break;
		  	s++;	
		}
		if(b==p && *s=='\0'){
			f(p,p);
			return p;
		}
	    if(*s=='\0') 
			break;
		i=0;
		while(i<s-a){
			*(rijec+i)=*b;
			b++;
			duzina++;
			i++;
		}
		rijec[i]='\0';
		p1=p;
		
		/*provjerim koliko se puta ponavlja*/
		while(*p1!='\0'){
			char*p2=p1;
			char*r2=rijec;
			while(((*p2==*r2)||(*p2==*r2-32)||(*p2==*r2+32))&&*r2!='\0'){
				p2++;r2++;
				if(p1==p){if(*r2=='\0' && !(*p2 >= 'A' && *p2 <= 'Z') && !(*p2 >= 'a' && *p2 <= 'z'))
							brojac++;}
				else if(*r2=='\0' && (!(*p2 >= 'A' && *p2 <= 'Z') && !(*p2 >= 'a' && *p2 <= 'z')) && !(*(p1-1)>='a' && *(p1-1)<='z') && !(*(p1-1)>='A' && *(p1-1)<='Z'))
				            brojac++;
				}
				p1++;	
			}
			
		if(brojac>max){
			max=brojac;
			for(i=0;i<duzina;i++){
				max_rijec[i]=rijec[i];
			}
			max_rijec[i]='\0';
		}
    if(*s=='\0') 
		  break;
    s++;	    
    }
    f(p,max_rijec);

   return p;
}
int main() {
	
	char s[100000]={"szzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttteeeerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrreeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwsqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqssssssssssssssssssssssssssssssssssssssssssssssssaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"};
	printf("\nModificiran niz glasi: |%s|", izbaci_najcescu(s));
	
   return 0;
}
