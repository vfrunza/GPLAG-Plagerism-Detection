#include <stdio.h>

void najduzi_bp(char *s1, char *s2){
	
	char *p1=s1, *p2=s1, *p3=s1, *q1=s2, *q2=s2;
	char temp;

	int brojac=0, brojac1=0, hist[150]={0},i=0;
	*q1='\0';
	*q2='\0';
	while(*p1){
		
		if((*p1>=65 && *p1<=90) || (*p1>=97 && *p1<=122)){
			p2=p1;
			p3=p1;
			while((*p2>=65 && *p2<=90) || (*p2>=97 && *p2<=122)){
				temp=*p2;
				if(temp>=65 && temp<=90)temp+=32;
				
				
				hist[temp]++;
				for(i=0;i<150;i++){
					if(hist[i]>1)break;
				}
				if(i!=150)break;
				brojac++;
				p2++;
			}
			
		
			
		}
			if(brojac>brojac1){
				while(p3!=p2){
					*q1=*p3;
					q1++;
					p3++;
				}
				*q1='\0';
				brojac1=brojac;
			}
		q1=q2;
		for(i=0;i<150;i++)hist[i]=0;
		brojac=0;
		
		 p1++;
		
	}	
	
}

int main() {
	char a[]="Ajdin je najbolji demonstrator. Ziv bio 100 godina :)";
	char b[100]="";
	najduzi_bp(a,b);
	printf("%s",b);
	return 0;
}

