#include <stdio.h>
#include <stdlib.h>
int strcmpi(const char *s1, const char *s2) {
	while (*s1 && *s2) {
		if (*s1>='A' && *s1<='Z' && *s2>='a' && *s2<='z') {
			if (*s1+32>*s2)
				return 1;
			else if (*s1+32<*s2)
				return -1;
			s1++; s2++;
		}
		if (*s2>='A' && *s2<='Z' && *s1>='a' && *s1<='z') {
			if (*s1>*s2+32)
				return 1;
			else if (*s1<*s2+32)
				return -1;
			s1++; s2++;
		}
		if (*s1>*s2)
			return 1;
		else if (*s1<*s2)
			return -1;
		s1++; s2++;
	}
	if (*s1) 
		return 1;
	if (*s2)
		return -1;
	return 0;
}
int duzinataga(char* htmlkod) {
	int duzina= 0;
	while (*htmlkod!='>' && *htmlkod!=' ') {
		htmlkod++;
		duzina++;
	}
	return duzina;
}
int izbrojiotvorene(char* htmlkod) {
	int brojac = 0;
	while (*htmlkod) {
		if (*htmlkod=='<' && *(htmlkod+1)!='/') {
			while (*htmlkod!='>')
				htmlkod++;
			brojac++;
		}
		htmlkod++;
	}
	return brojac;
}
int izbrojizatvorene(char* htmlkod) {
	int brojac = 0;
	while (*htmlkod) {
		if (*htmlkod=='<' && *(htmlkod+1)=='/') {
			while (*htmlkod!='>')
				htmlkod++;
			brojac++;
		}
		htmlkod++;
	}
	return brojac;
	
}
int provjeri(char* htmlkod) {
	int brojotvorenih, brojzatvorenih, i, duzinaTaga;
	brojotvorenih=izbrojiotvorene(htmlkod);
	brojzatvorenih=izbrojizatvorene(htmlkod);
	if (brojzatvorenih!=brojotvorenih) 
		return 0;
	
	char** otvorenitagovi=malloc(brojotvorenih*sizeof(char *));
	char** zatvorenitagovi=malloc(brojzatvorenih*sizeof(char *));
	
	char* temp = htmlkod;
	char* temp2;
	i=0;
	while (*temp) {
		if (*temp=='<' && *(temp+1)!='/') {
			temp++;
			duzinaTaga=duzinataga(temp);
			otvorenitagovi[i]=(char *)malloc(duzinaTaga+1);
			temp2=otvorenitagovi[i];
			while (*temp!=' ' && *temp!='>') 
				*temp2++=*temp++;
			*temp2='\0';
			i++;
		}
		temp++;
	}
	
	i=0;
	temp=htmlkod;
	
	while (*temp) {
		if (*temp=='<' && *(temp+1)=='/') {
			temp+=2;
			duzinaTaga=duzinataga(temp);
			zatvorenitagovi[i]=(char *)malloc(duzinaTaga+1);
			temp2=zatvorenitagovi[i];
			while (*temp!='>')
				*temp2++=*temp++;
			*temp2='\0';
			i++;
		}
		temp++;
	}
	
	for (i=0;i<brojotvorenih;i++) {
		if (strcmpi(otvorenitagovi[i], zatvorenitagovi[brojzatvorenih-1-i])) {
			for (i=0;i<brojotvorenih;i++) {
				free(otvorenitagovi[i]);
				free(zatvorenitagovi[i]);
			}
			free(otvorenitagovi);
			free(zatvorenitagovi);
			return 0;
		}
			
	}
	
	for (i=0;i<brojotvorenih;i++) {
		free(otvorenitagovi[i]);
		free(zatvorenitagovi[i]);
	}
	free(otvorenitagovi);
	free(zatvorenitagovi);
	return 1;
}
int main() {
	char htmlkod[]={"<div id=""tekst""><h2>Naslov</h2><p>Ovo je <b>četvrti</b> i <i>posljednji</i> zadatak iz <a href=""zadaca4"">zadaće 4</a></p></div>"};
	int brojotvorenih=izbrojiotvorene(htmlkod);
	int brojzatvorenih=izbrojizatvorene(htmlkod);
	int provjera=provjeri(htmlkod);
	printf ("%d %d, %d", brojotvorenih, brojzatvorenih, provjera);
	return 0;
}
