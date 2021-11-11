#include <stdio.h>
int ifchange(char* t, char* r ){
	char* b=t;
	char* br=r;
	int m=1;
	
	while(*t!='\0' && *r!='\0'){
		if(*t!=*r)m=0;
		t++;
		r++;
	}
	if((*t!=' ' && *t!='\0') || *r!='\0')m=0;
	t=b;
	r=br;
	return m;
}
void change(char* txt, char* w, char*nw){
	char* tmp=txt;
	char* wtmp=w, *ntmp=nw, *c=txt;
	int m=0, i, cnt=1;
	while(*txt!='\0'){
		cnt=0;
		while(*txt!='\0' && *txt!=*w){
			txt++;
		}
		if(*txt!='\0' && (txt==tmp || *(txt-1)==' ') && ifchange(txt, w)){
			
			while(*nw!='\0'){
				if(*txt==' ' ||*txt=='\0' ){
					c=txt;
					while(*txt!='\0'){txt++;}
					txt++;
					while(txt>c){
						*txt=*(txt-1);
						txt--;
					}
			}
			*txt=*nw;
			txt++;
			nw++;
		}
		cnt=1;
	}
	if(*txt!=' ' && *txt!='\0' && cnt==1){
		c=txt;
		while(*txt!=' ' && *txt!='\0'){
			m++;
			txt++;
		}
		txt=c;
		for(i=0;i<m;i++){
			txt=c;
			while(*txt!='\0'){
				*txt=*(txt+1);
				txt++;
			}
		}
		txt=c;
	}
	if(*txt!=' ' && *txt!='\0')txt++;
	w=wtmp;
	nw=ntmp;
}
txt=tmp;
w=wtmp;
nw=ntmp;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char* tmptxt=tekst;
	int i;
	for(i=0;i<broj_rijeci;i++){
		tekst=tmptxt;
		while(*tekst!='\0'){
			while(*tekst!='\0' && *tekst==' '){tekst++;	}
			if(ifchange(tekst, rijeci[i])){
				
				change(tekst, rijeci[i], zamjene[i]);
			}
			while(*tekst!=' ' && *tekst!='\0')tekst++;
		}
	}return tmptxt;
}
int main() {
	char* rijeci[2]={"", ""};
	char* zamjene[2]={"", ""};
	char tekst[100]="";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	
	return 0;
	
}

