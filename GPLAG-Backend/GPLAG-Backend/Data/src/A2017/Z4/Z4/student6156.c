#include <stdio.h>
#include <stdlib.h>

int dva_slova(char a, char b);
int ime(char c);
int sigurica(char* kod);
int sigurica2(char* kod,int *broj);
int sigurica3(char* kod);
int tag(char* stek, char* pocetak, char* kraj);
int provjeri(char* kod);


int main()
{
	printf("%d\n",provjeri("<div> <H2> </h2> <p> <b> </b> <i> </i> <a> </a> </p> </div>"));
	return 0;
}


int provjeri(char* kod)
{
	int duzina=0;

	char* pocetak=kod;
	char* kraj=kod;
	if(!sigurica(kod))return 0;
	if(!sigurica2(kod,&duzina))return 0;
	if(!sigurica3(kod))return 0;
	char* stek=(char*)malloc(sizeof(char)*(duzina+1));
	int i;
	for(i=0; i<duzina+1; i++)stek[i]='\0';

	while(*kraj!='\0'&&*pocetak!='\0')
	{


		while(*kraj!='\0')
		{
			if(*kraj=='>')break;
			kraj++;
		}
		if(*kraj=='\0')
		{
			free(stek);
			return 1;
		}
		while(*pocetak!='\0' && pocetak<kraj)
		{
			if(*pocetak=='<')break;
			pocetak++;
		}
		
		if(!tag(stek,pocetak,kraj))
		{
			free(stek);
			return 0;
		}
		if(kraj!='\0')kraj++;
		if(pocetak<kraj)pocetak++;
	}
	free(stek);
	return 1;
}

int sigurica(char* kod)
{
	char *p=kod;
	while(p!='\0')
	{
		if(*p=='<'||*p=='>')return 1;
		p++;
	}
	return 0;
}

int sigurica2(char* kod,int *broj)
{
	int a=0,b=0,c=0;
	char* s=kod;
	while(*s!='\0')
	{
		(*broj)++;
		if(*s=='<')a++;
		if(*s=='>')b++;
		if(*s=='<' && (*(s+1)=='/'&& ime( *(s+2) )   ) )c++;
		if(*s=='<' && 	!(	(*(s+1)=='/'&& ime( *(s+2) )   )	||  ( ime(*(s+1) ) )	) 	)return 0;
		s++;
	}
	if(a==b &&a==c*2)return 1;
	return 0;
}

int sigurica3(char* kod)
{
	int a=-1;
	char* s=kod;
	while(*s!='\0')
	{
		if(*s=='<'||*s=='>')
		{
			if(a==1 && *s=='<' )return 0;
			if(a==-1 && *s=='>')return 0;
			a*=-1;

		}
		s++;
	}
	return 1;
}

int ime(char c)
{
	if( (c>='A' && c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'))return 1;
	return 0;
}

int tag(char* stek, char* pocetak, char* kraj)
{

	char* s1=pocetak;/* "<" */
	char* s2=kraj;/* ">" */
	char* klizni=stek;
	char* zadnji=stek;
	char* predzadnji=stek;
	char* pomocni=0;
	int t=1,pronasao=0;
//	printf("\n |%s|%s| ",pocetak,kraj);
//	printf("\n |%s|| ",stek);
	if( ime(*(s1+1)) )
	{
		/*dodaj na stek*/
		while(*klizni!='\0')klizni++;
		s1++;
		while(ime(*s1)&&s1<s2)
		{
			*klizni=*s1;
			klizni++;
			s1++;
		}
		*klizni++='.';
		*klizni='\0';

	}
	else if(*(s1+1)=='/'&&ime(*(s1+2)))
	{
		/*skini sa steka ako moze i ako nije prazan*/
		klizni=stek;
		if(*stek=='\0')return 0;
		
		while(*klizni!='\0')
		{
			if(*klizni=='.'){zadnji=klizni;}
			klizni++;
		}
		klizni = stek;
		while(*klizni!='\0')
		{
		
			if(*klizni=='.'&&klizni<zadnji)
			{
				pronasao=1;
				predzadnji=klizni;
			}
			klizni++;
		}
	
		if(pronasao){predzadnji++;}/*sad ovaj pokazuje na prvo slovo zadnjeg otvorenog taga */
		else {predzadnji=stek;}

		pomocni=predzadnji;
		s1+=2;
		//	printf("\n |%s|%s| ",predzadnji,s1);
		//	printf("\n %d",*predzadnji-*s1);
		while(predzadnji<zadnji && s1<s2)
		{
			if(		!(*predzadnji==*s1||dva_slova(*predzadnji,*s1)) 	 )
			{
			
				t=0;
				break;
			}
			predzadnji++;
			s1++;
		}
		
		if(t)*pomocni='\0';
		else return 0;

	}

	
	return 1;
}

int dva_slova(char a, char b)
{
	
	if( ((a>='a'&&a<='z')||(a>='A'&&a<='Z'))&&((b>='a'&&b<='z')||(b>='A'&&b<='Z')) )
	{
	
		if(a-b=='a'-'A')return 1;
		if(b-a=='a'-'A')return 1;
	}
	
return 0;
}