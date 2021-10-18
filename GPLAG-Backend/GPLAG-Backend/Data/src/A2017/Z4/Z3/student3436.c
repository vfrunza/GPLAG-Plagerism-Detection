#include <stdio.h>

int touppoer(char c1,char c2)
{
	if(c1<='z' && c1>='a') c1-=32;
	if(c2<='z' && c2>='a') c2-=32;
	if (c1==c2) return 1;
	return 0;
}

int najduzi_podstring(char* prvi,int* zadnji)
{
	char* s=prvi;
	int max=0,tempmax;
	char* kraj;
	char* temp;
	
	while(*s!='\0'){
		if(*s<'A' ||*s>'z' ||(*s<'a' && *s>'Z')) break;
		s++;
		}
		
	kraj=s;//Na kraju rijeci
	s=prvi;
	
	while(s<kraj){
		
		temp=s+1;
		while(temp<kraj){
			if(touppoer(*s,*temp)==1) break;
			temp++;
		}
		
		if(temp<kraj)
		kraj=temp;
	
		s++;	
	}
	
	tempmax=kraj-prvi;
	
	if(tempmax>max){
		max=tempmax;
		*zadnji=max;
		
	}
	
	return max;
}



void najduzi_bp(char* s1, char* s2)
{
	char* s = s1;
	char* prvi=s1;
	char* prvi1=s,*kraj1=s;
	int tempzadnji;
	int max=0,tempmax=0;
	
	while(*s!='\0')
	{
		if((*s<='Z' && *s>='A')||(*s<='z' && *s>='a') )
		{
			
		tempmax=najduzi_podstring(s,&tempzadnji);
		
		if(tempmax>max)
		{
			max=tempmax;
			kraj1=s+tempzadnji;
			prvi1=s;
		}
		}
		s++;
	}
	
	s=prvi1;
	
	while(s<kraj1)
	{
	*s2=*s;
	s2++;
	s++;
	}
	*s2='\0';
	
	
}

int main() {
	
	char niz[10];
        najduzi_bp ("abcdef predsjed bcdefg", niz);
        printf ("Niz: '%s'", niz);
        
	return 0;
}
