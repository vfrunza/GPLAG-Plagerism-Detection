#include <stdio.h>
#include <ctype.h>
int JelSloiliBr(char x)
{

	return (x>= 'a' && x<= 'z')  || (x>= '0' && x<= '9');
}
int provjeri(char* html)
{
	char tagovi[50][50];
	int i=0;
	int j=0, k=0;
	while (html[i]!=0) {
		if( html[i]=='<' && html[i+1]!='/') {
			j=0;
			i++;
			if(JelSloiliBr(tolower(html[i]))==0)return 0;
			while(html[i]!=' ' && html[i]!='>') {

				tagovi[k][j]=tolower(html[i]);
				tagovi[k][j+1]='\0';
				j++;
				i++;
			}
			k++;
		}
		if( html[i]=='<' && html[i+1]=='/') {
			i+=2;
			j=0;
			if(k==0)return 0;
			while(html[i]!='>' && html[i]!=' ') {
				if(tolower(html[i])!=tagovi[k-1][j]) return 0;
				i++;
				j++;

			}
			if(tagovi[k-1][j]!='\0')return 0;
			k--;
		}
		i++;
	}
	return (k==0);
}
int main()
{
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
