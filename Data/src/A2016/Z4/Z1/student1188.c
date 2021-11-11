#include <stdio.h>
#include <ctype.h>
void bounce(char* s, int duzina){
    while(*(s+duzina)){
        *s=*(s+duzina);
        s++;
    }
    *s=*(s+duzina);
}

char* izbaci_najcescu(char* s){
	char* reset=s;
	char *kraj_pon=s, *pocetak, *kraj, *p=s, *t, *pocetak1, *kraj1, *pocetak0, *q1, *q2;
	int max_brojac=0, max_duzina=0, brojac=0, ista, broj_slova, duzina1, duzina2, mozel_rijec;
	char ch1, ch2;
	
	if(*p=='\0') return s;

	while(*p!='\0'){
	    while((*p<'A' || (*p>'Z' && *p<'a') || *p>'z') && *(p+1)!='\0') p++;
		if(*p!='\0'){
			pocetak=p;
			kraj=p;
			duzina1=1;
			while((toupper(*(kraj+1))>='A' && toupper(*(kraj+1))<='Z') && *(kraj+1)!='\0'){
				duzina1++;
				kraj++;
			}
			brojac=1;
			t=kraj+1;
			while(*t!='\0'){
				pocetak1=t;
				while((*pocetak1<'A' || (*pocetak1>'Z' && *pocetak1<'a') || *pocetak1>'z') && *(pocetak1+1)!='\0') pocetak1++;
				kraj1=pocetak1;
				duzina2=1;
				while((toupper(*(kraj1+1))>='A' && toupper(*(kraj1+1))<='Z') && *(kraj1+1)!='\0'){
					duzina2++;
					kraj1++;
				}
				ista=1;
				broj_slova=0;
				pocetak0=pocetak;
				if(duzina1!=duzina2) ista=0;
				else
				while(broj_slova<duzina2){
					if(*pocetak0>='A' && *pocetak0<='Z') 
						ch1=(*pocetak0)+('a'-'A'); 
						else 
							ch1=*pocetak0;
					if(*pocetak1>='A' && *pocetak1<='Z') 
						ch2=(*pocetak1)+('a'-'A'); 
						else 
							ch2=*pocetak1;
					if(ch1!=ch2) ista=0;
					pocetak0++;
					pocetak1++;
					broj_slova++;
				}

				if(ista) brojac++;
				t=kraj1+1;
			}
			if (brojac>max_brojac){
				max_brojac=brojac;
                kraj_pon=kraj;
				max_duzina=duzina1;
			}
		}
		p=kraj+1;;
	}
	p=t-1;

	while(p>=s){
		mozel_rijec=0;
            if((*(p+1)<'A' || (*(p+1)>'Z' && *(p+1)<'a') || *(p+1)>'z') || *(p+1)=='\0') mozel_rijec=1;
        if(*p>='A' && *p<='Z') 
        	ch1=(*p)+('a'-'A'); 
        	else 
        		ch1=*p;
            if(*kraj_pon>='A' && *kraj_pon<='Z') 
            	ch2=(*kraj_pon)+('a'-'A'); 
            		else 
            			ch2=*kraj_pon;
        if(ch1==ch2 && mozel_rijec){
			q2=p;
			q1=kraj_pon;
			duzina2=0;
			ista=1;
			while(q2>=s && ((toupper(*q2)>='A' && toupper(*q2)<='Z') )){
				if(q1>=s){
					if(*q1>='A' && *q1<='Z') 
						ch1=(*q1)+('a'-'A'); 
							else 
								ch1=*q1;
					if(*q1>='A' && *q1<='Z') 
						ch2=(*q1)+('a'-'A'); 
							else 
								ch2=*q1;
					if(ch1!=ch2) ista=0;
				}
				duzina2++;
				q2--;
				q1--;
			}
			q2++;
			if(max_duzina!=duzina2) ista=0;
			if(ista){
				bounce(q2, duzina2);
			}
		}
		p--;
	}
	return reset;
}
int main() {
	char a[]="jedan dva tri jedan";
	printf("%s",izbaci_najcescu(a));
	return 0;
}
