#include <stdio.h>

int karakter(char c)
{
	if((c>='A' && c<='Z') || (c>='a' && c<='z'))
	return 1;
	else return 0;
}
void najduzi_bp(char* s1, char* s2)
{
	int da = 1;
	int i = 0, j;
	int poc = 0;
	int kraj = 0;
	int poc_naj = 0;
	int kraj_naj = 0;
	
	while(s1[i]!='\0')
	{
		if(karakter(s1[i]))
		{
			poc=i;
			kraj=i;
			while(karakter(s1[kraj])==1)
			{
				da=1;
				for(j=poc;j<kraj;j++)
				{
					if(s1[j] == s1[kraj] && j!=kraj)
					{
						da=0;
						break;
					}
				}
				if(da==0 || karakter(s1[kraj])==0) break;
				kraj++;
			}
			
			if(kraj-poc > kraj_naj-poc_naj)
			{
				kraj_naj = kraj;
				poc_naj = poc;
			}
		}
	
			
		i++;
	}
	
	for(i=poc_naj;i<kraj_naj;i++)
	{
		s2[i-poc_naj] = s1[i];
	}
	s2[i-poc_naj] = '\0';
}



int main() {


char tekst[] = "Ovo je neki primjer teksta";
char s2[100];
najduzi_bp(tekst, s2);
printf("%s ", s2);

}
