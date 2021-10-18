#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

char* kodiraj(char* tekst, char* s){
	char* temp;
	char* temp1;
	char* temp2;
	char* temp3;
	int br[200]={0},i,j,max=-1,a=-2;
	temp=tekst;
	temp1=tekst;
	temp3=tekst;
	while(*tekst!='\0'){
		for(i=32;i<=126;i++){
			if(i==*tekst){
				br[i]++;
			}
		}
		tekst++;
	}
	while(*temp!='\0'){
		for(i=32;i<=126;i++){
			for(j=32;j<=126;j++){
				if(br[j]>max){
					max=br[j];
				}
			}
			for(j=32;j<=126;j++){
				if(br[j]==max && max!=0){
					*s=j;
					s++;
					br[j]=a;
					a--;
					goto unos;
				}
			}
			unos:;
		}
		max=-1;
		temp++;
	}
	temp2=s;
	for(i=32;i<=126;i++){
		if(br[i]==0){
			*temp2=i;
			temp2++;
		}
	}
	*temp2='\0';
	while(*temp3!='\0'){
		for(i=32;i<=126;i++){
			if(*temp3==i){
				*temp3='~'+br[i]+2;
				goto kraj;
			}
		}
		kraj:
		temp3++;
	}
	return temp1;
}

char* dekodiraj(char *tekst,char* s){
	char* temp;
	char* temp1;
	char* temp3;
	int br[200]={0},i,j,max=-1,a=-2,pozicije[200]={0},temporary;
	temp=tekst;
	temp1=tekst;
	temp3=tekst;
	while(*tekst!='\0'){
		for(i=32;i<=126;i++){
			if(i==*tekst){
				br[i]++;
			}
		}
		tekst++;
	}
	for(i=32;i<=126;i++){
		pozicije[i]=br[i];
	}
	while(*temp!='\0'){
		for(i=32;i<=126;i++){
			for(j=32;j<=126;j++){
				if(br[j]>max){
					max=br[j];
				}
			}
			for(j=32;j<=126;j++){
				if(br[j]==max && max!=0){
					br[j]=a;
					a--;
					goto unosa;
				}
			}
			unosa:;
		}
		max=-1;
		temp++;
	}
	for(i=32;i<=126;i++){
		for(j=i+1;j<=126;j++){
			if(pozicije[i]==pozicije[j]){
				temporary=br[i];
				br[i]=br[j];
				br[j]=temporary;
			}
		}
	}
	while(*temp3!='\0'){
		for(i=32;i<=126;i++){
			if(i==*temp3){
				*temp3=*(s-br[i]-2);
				continue;
			}
		}
		temp3++;
	}
	return temp1;
}

int main() {
	char tekst[100],sifrarnik[100]="";
	unesi(tekst,100);
	printf("\n%s",kodiraj(tekst,sifrarnik));
	printf("\n%s",dekodiraj(tekst,sifrarnik));
	return 0;
}
