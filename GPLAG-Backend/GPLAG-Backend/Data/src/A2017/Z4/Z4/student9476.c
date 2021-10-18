#include <stdio.h>

int i=0;

int uporedi(char c1,char c2)
{
	if(c1<='Z' && c1>='A') c1+=32;
	if(c2<='Z' && c2>='A') c2+=32;
	if (c1==c2) return 1;
	return 0;
	
}

int slovo(char c)
{
	if((c<='Z' && c>='A')|| (c<='z' && c>='a')) return 1;
	return 0;
}

int provjera_1(char*s,int p)
{
	int j;
	for(j=0;s[j+p]!='\0';j++)
	if(s[j+p]=='>') return 1;
	
	return 0;
}

int provjera_2(char*s,int p)
{
	int j;
	for(j=p;s[j]!='\0';j++)
	if(s[j]=='<' && s[j+1]=='/') return 1;
	
	return 0;
}

int rekur(const char* s,int p1)
{
	
	int j=0;
	for(i;s[i]!='\0';i++)
	{
		
		if(s[i]=='<' && slovo(s[i+1]))
		{
			if(provjera_1(s,i)==0 || provjera_2(s,i)==0)return 0;
			i++;
			if(rekur(s,i)==0)return 0;
			
		}
		
		
		if(s[i]=='<' && (!slovo(s[i+1]) && s[i+1]!='/'))
		return 0;
		
		
		if(s[i]=='<' && s[i+1]=='/')//Ako je zatvoreni
		{
			i+=2;//Stavlja na prvo slovo
			if(s[i]==' ')
				{
				return 0;}//Vraca ako je prvi space
			
			for(j=0;s[i+j-1]!=' ' && s[i+j]!='>';j++)	//Ide dok nije kraj desnog
				if(uporedi(s[i+j],s[p1+j])==0)
					return 0;
				//Ako nisu isti gasi
				
				if(s[p1+j]!=' ' && s[p1+j]!='>')
				return 0; 
				
				i+=j;
				return 1;
				
				
		}
		if(s[i]=='\0') return 0;
	}
	
	return 1;
}

int provjeri(const char* s)
{	
 	i=0;
	return(rekur(s,0));
	
}

int main() {
	
	return 0;
}

