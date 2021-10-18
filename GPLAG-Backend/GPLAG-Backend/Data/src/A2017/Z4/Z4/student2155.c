#include <stdio.h>
#include <string.h>

int dodajTag(char tagovi[100][100], int brojTagova, char tag[100]){
	int j=0;
	if(*(tag+1) != '/'){ /*dodajemo tag*/
		while(*tag!='\0'){
			tagovi[brojTagova][j++]=*tag;
			tag++;
		}
		tagovi[brojTagova][j]=0;
		
		return brojTagova + 1;
	}else { /*skidamo tag*/
		if(strcmp(tagovi[brojTagova-1]+1, tag+2)==0){
			return brojTagova - 1;
		}
		return brojTagova;
	}
}

int provjeri(char* string){
	int brojTagova=0,i=0;
	char tagovi[100][100], tag[100]="";
	
	for(i=0;i<100;i++){
		tagovi[i][0]=0;
	}
	
	while(*string!='\0'){
		i=0;
		if(*string == '<'){
			while(*string != ' ' && *string != '>' && *string != '\0'){
				tag[i++] = *string++;
				tag[i]=0;
			}
			while(*string != '>' && *string != '\0'){
				string++;
			}
			if(*string == '>'){
				brojTagova = dodajTag(tagovi,brojTagova,tag);
			} else {
				return 0;
			}
		}
		if(*string != '\0'){
			string++;
		}
	}
	
	if(brojTagova == 0){
		return 1;
	} else {
		return 0;
	}
}

int main() {
	printf("%d",provjeri("<p> nesto</p>"));
	return 0;
}
