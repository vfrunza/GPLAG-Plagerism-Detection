#include <stdio.h>

int jeLiSlovo(char c){
	if((c>='A' && c<='Z')||(c>='a' && c<='z')||(c>='0' && c<='9'))return 1;
	return 0;
}

int caseSensitive(char c1,char c2){
	if(c1-32==c2 || c1+32==c2 || c1==c2)return 1;
	return 0;
}

int provjeri(char *s){
	char *str=s,mat[50][50];
	int prekidac=0,c,m,niz[30];
	int i=0,j,k,l,t,ogranicenje,fula;
	//
	if(*s=='\0')return 1;
	while(*str!='\0'){
		if(*str!=' ')prekidac=1;
		str++;
	}
	if(!prekidac)return 1;
	//prva provjera
	str=s;
	while(*str!='\0'){
		if(*str=='<'){
			str++;
			if(*str=='/' || jeLiSlovo(*str));
			else return 0;
			if(*str=='/' && !jeLiSlovo(*(str+1)))return 0;
			while(*str!='>'){
				if(*str=='<')return 0;
				str++;
			}
		}
		str++;
	}
	//druga provjera
	str=s;
	while(*str!='\0'){
		if(*str=='<'){
			str++;
			if(jeLiSlovo(*str)){
				j=0;
				while(jeLiSlovo(*str)){
					mat[i][j]=*str;
					j++;
					str++;
				}
				mat[i][j]='\0';
				niz[i]=0;
				i++;
			}else if(i==0)return 0;
			else if(*str=='/'){
				str++;
				j=0;
				while(jeLiSlovo(*str)){
					mat[i][j]=*str;
					j++;
					str++;
				}
				mat[i][j]='\0';
				niz[i]=1;
				i++;
			}
			while(*str!='>')str++;
			if(*str=='\0')break;
		}
		str++;
	}
	ogranicenje=i;
	for(i=0;i<ogranicenje;i++){
		fula=0;
		for(j=0;;j++){
			k=i+1;
			if(k==ogranicenje || ogranicenje==1)return 0;
			if(mat[k][j]=='\0' && mat[i][j]!='\0'){fula=1;break;}
			if(mat[i][j]=='\0')break;
			else if(!caseSensitive(mat[i][j],mat[k][j])){
				fula=1;
				break;
			}
		}
		if(niz[i]==0 && niz[k]==0)fula=1;
		if(!fula){
		//	if(niz[i]==0 && niz[k]==0)return 0;
			for(t=k+1;t<ogranicenje;t++,i++){
				for(l=0;;l++){
					if(mat[t][l]=='\0')break;
					mat[i][l]=mat[t][l];
				}
				niz[i]=niz[t];
				mat[i][l]='\0';
			}
			i=-1;
			ogranicenje-=2;
		}
	}
	if(ogranicenje==0)return 1;
	return 0;
}

int main() {
printf ("Provjera 6: %d\n", provjeri ("      <i>      <b></b>        <i>      "));
	return 0;
}
