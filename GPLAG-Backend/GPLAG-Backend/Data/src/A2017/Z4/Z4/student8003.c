#include <stdio.h>

int i=0;

int touppoer(char c1,char c2)
{
	if(c1<='z' && c1>='a') c1-=32;
	if(c2<='z' && c2>='a') c2-=32;
	if (c1==c2) return 1;
	return 0;
}

int provjeri_slovo(char c)
{
	if((c<='Z' && c>='A')||(c<='z' && c>='a')) return 1;
	return 0;
}

int zatvoren(int i,char* s)
{
	int j=0;
	for(j=i;s[j]!='\0';j++)
	{
		if(s[j]=='<' && s[j+1]=='/')return 1;
		if(s[j]=='>')return 1;
	}
	return 0;
}

int pomocni_provjeri(int pocetak1,char*s)
{

	int j=0;
	
	for(;s[i]!='\0';i++)
	{
		
		if(s[i]=='<' && provjeri_slovo(s[i+1]))
		{

			if(zatvoren(i,s)==0)return 0;
			i++;
			if(pomocni_provjeri(i,s)==0){return 0;}
		}
		
		if(s[i]=='<'&&(!provjeri_slovo(s[i+1])&& s[i+1]!='/'))
		return 0;
		
		if(s[i+1]=='/' && s[i]=='<')
		{
			i+=2;
			if(s[i]==' ')return 0;
			
			
			for(j=0;s[i+j-1]!=' ' && s[i+j]!='>';j++)
				if(touppoer(s[pocetak1+j],s[i+j])==0){return 0;}
		
			
			if(s[pocetak1+j]!='>')
			if (s[pocetak1+j]!=' ')
			return 0;
			
			
			i=i+j;
			return 1;
			
		}
		if(s[i]=='\0')return 0;
		
	}
	
	return 1;
}

int provjeri(const char* s)
{
i=0;
return(pomocni_provjeri(0,s));

	
}

int main() {
	
char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
char tekst2[] = "<b><a>proba</b></a>";
printf("%d ", provjeri(tekst1));
printf("%d ", provjeri(tekst2));

	return 0;
}
