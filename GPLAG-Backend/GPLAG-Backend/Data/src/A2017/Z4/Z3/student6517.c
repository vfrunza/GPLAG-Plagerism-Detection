#include <stdio.h>

void najduzi_bp(char*s,char*s2){
	
	char*p=s,*p1,*p2,*k,temp;
	char niz [100];
	int i,max=0,duzz;
	while(*p!='\0'){
		if(*p>='A'&& *p<='Z'|| *p<='z'&&*p>='a'){
			duzz=0;
			p1=p;
			p2=p;
			while ((*p1>='A'&& *p1<='Z')|| (*p1<='z'&&*p1>='a')) {
				if (*p1>='A'&& *p<='Z')
					temp=*p1;
				else 
					temp=*p1+'A'-'a';
				 if(p1==p){
				 		niz[duzz++]=temp;
				 		p1++;
				 }
				 else{
				 	for (i = 0; i < duzz; i++) {
				 		if(niz[i]==temp)
				 		break;
				 	}
				 if (i==duzz)
				 	niz[duzz++]=temp;
				 else break;
				 	p1++;
				 	}
			}
			if(duzz>max){
				
				max=duzz;
				i=0;
				while (p2<p1) {
					*(s2+i)=*p2++;
					i++;
				}
			*(s2+i)='\0';
			}
			p++;
	}
	else p++;
	}
	
}

int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
