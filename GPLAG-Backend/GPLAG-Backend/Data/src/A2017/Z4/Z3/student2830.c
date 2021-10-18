#include <stdio.h>
void najduzi_bp(char* s1, char* s2)
{
	char* max;
	int maxbrslova=0;
	int trenutnibrslova=1;
	int i=0,brslovaurijeci=0,j=0,m=0;


	int n=0;
	int p=0;
	int t=0;
	int g=0;
	while(*(s1+i)!='\0')
	{
		p=0;
		//ako naidje na rijec
		if((*(s1+i)>='A' && *(s1+i)<='Z') || (*(s1+i)>='a' && *(s1+i)<='z')){
			p=1;
			brslovaurijeci=0;
	        j=0;
	        m=0;
	       

	        trenutnibrslova=1;
	       
			//broji slova u rijeci
			while((*(s1+i+brslovaurijeci)>='A' && *(s1+i+brslovaurijeci)<='Z') || (*(s1+i+brslovaurijeci)>='a' && *(s1+i+brslovaurijeci)<='z'))
			{   brslovaurijeci++;
					}
		//trazi podstring..tako sto svako slovo stavlja kao pocetak i gleda koliko slova nakon njega idu bez ponavljanja
		 while(j<brslovaurijeci)
		 {
		  
		 	for(m=j+1;m<brslovaurijeci;m++)
		 	{
		 	 for(g=m-1;g>=j;g--){
		 		if((*(s1+i+m)==*(s1+i+g) || *(s1+i+m)-32==*(s1+i+g) || *(s1+i+m)+32==*(s1+i+g))){ t=1; break;}
		 	 }
		 	 if(t==1) break;
		 	 trenutnibrslova++;
	 		 	}
	 	if(trenutnibrslova>maxbrslova){ maxbrslova=trenutnibrslova; max=s1+i+j;}
	 	t=0;
	 	trenutnibrslova=1;
		 	if(maxbrslova==brslovaurijeci) break;
	 		 	
		 	j++;
		 }
		 
			
		}
		if(p==1) i=i+brslovaurijeci;
		if(p==0) i++;
	}
	while(n<maxbrslova)
	{
		*(s2+n)=*(max+n);
		n++;
	}
	*(s2+n)='\0';
	
	
}
int main() {
	char niz[10];
        najduzi_bp ("abcde etankera cdefg", niz);
        printf ("Niz: '%s'", niz);
	return 0;
}
