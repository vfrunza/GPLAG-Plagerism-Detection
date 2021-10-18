#include <stdio.h>

int jeLiSlovo(char c){
	if((c>='A' && c<='Z')||(c>='a' && c<='z'))return 1;
	return 0;
}

int caseSensitive(char c1,char c2){
	if(c1-32==c2 || c1+32==c2 || c1==c2)return 1;
	return 0;
}

void najduzi_bp(char *s1,char *s2){
	char mat[100][100];
	char kontejner[20];
	int stanica=0,i=0,j,t,max,indeks,niz[100],counter,z=0;
	char *tmp,*pk,*str=s1,*q;

	while(*str!='\0'){
		if(jeLiSlovo(*str)){
			tmp=str;
			pk=kontejner;
			*pk=*tmp;
			tmp++;
			pk++;
			*pk='\0';
			while(jeLiSlovo(*tmp)){
				pk=kontejner;
				stanica=0;
				while(*pk!='\0'){
					if(caseSensitive(*tmp,*pk)){
						stanica=1;
						break;
					}
					pk++;
				}
				if(stanica){
					j=0;
					q=str;
					while(q!=tmp){
						mat[i][j]=*q;
						q++;
						j++;
					}
					mat[i][j]='\0';
					i++;
					break;
				}else {
					*pk=*tmp;
					pk++;
					*pk='\0';
				}
				tmp++;
			}
			if(!stanica){
				j=0;
				q=str;
				while(q!=tmp){
				mat[i][j]=*q;
					q++;
					j++;
				}
				mat[i][j]='\0';
				i++;
				str=tmp;
				if(*str=='\0')break;
			}
		}
		str++;
	}
	t=0;
	while(t<i){
		counter=0;
		z=0;
		while(mat[t][z]!='\0'){counter++;z++;}
		niz[t]=counter;
		t++;
	}
	max=niz[0];
	indeks=0;
	t=0;
	while(t<i){
		if(max<niz[t]){
			max=niz[t];
			indeks=t;
		}
		t++;
	}
	for(j=0;;j++){
		if(mat[indeks][j]=='\0')break;
		*s2=mat[indeks][j];
		s2++;
	}
	*s2='\0';
}

int main() {
{//AT10.4, najduzi podstring je zapravio omedjen _ sa jedne, @ sa druge strane!
        char niz[10];
        najduzi_bp ("_abc@", niz);
        printf ("Niz: '%s'", niz);
    }//Niz: 'abCdeFgh'
	return 0;
}
