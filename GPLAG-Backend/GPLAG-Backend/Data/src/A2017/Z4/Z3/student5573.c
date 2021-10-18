#include <stdio.h>
#include <string.h>

void najduzi_bp(char *s1,char *s2)
{
	char prvi[100]={""},drugi[100]={""},temp[100]={""},nula[100]={""};
	char *pocetak=s1;
	int l=0,i=0,j,br=0,k=0;
	strcpy(s2,nula);
	while((*pocetak<'A' || (*pocetak>'Z' && *pocetak<'a') || *pocetak>'z') && *pocetak!='\0')	pocetak++;
	while(((*pocetak>='a' && *pocetak<='z') || (*pocetak>='A' && *pocetak<='Z')) && *pocetak!='\0')
	{
		temp[l]=*pocetak;
		l++;
		pocetak++;
	}
	for(i=0;i<l;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(temp[i]==temp[j]+32 || temp[i]==temp[j]-32 || temp[i]==temp[j])	br++;
		}
		if(br==0)
		{
			prvi[k]=temp[i];
			k++;
		}
		else	break;
		br=0;
	}
	l=0;
	br=0;
	k=0;
	while(*pocetak!='\0')
	{
		while((*pocetak<'A' || (*pocetak>'Z' && *pocetak<'a') || *pocetak>'z') && *pocetak!='\0')	pocetak++;
		while(((*pocetak>='A' && *pocetak<='Z') || (*pocetak>='a' && *pocetak<='z')) && *pocetak!='\0')
		{
			temp[l]=*pocetak;
			l++;
			pocetak++;
		}
		for(i=0;i<l;i++)
		{
			for(j=i-1;j>=0;j--)
			{
				if(temp[i]==temp[j]+32 || temp[i]==temp[j]-32 || temp[i]==temp[j])	br=1;
			}
			if(br==0)
			{
				drugi[k]=temp[i];
				k++;
			}
			else	break;
			br=0;
		}
		if(strlen(drugi)>strlen(prvi))	
		{strcpy(prvi,drugi);}
		strcpy(drugi,nula);
		l=0;br=0;k=0;
		pocetak++;
	}
	strcpy(s2,prvi);
}
int main() {
	char niz[10];
        najduzi_bp ("Ovo je neki primjer teksta", niz);
        printf ("Niz: '%s'", niz);
	/*printf("Zadaća 4, Zadatak 3");*/
	return 0;
}
