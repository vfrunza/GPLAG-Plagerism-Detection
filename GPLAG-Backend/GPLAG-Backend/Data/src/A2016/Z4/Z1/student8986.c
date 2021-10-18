#include <stdio.h>

char *izbaci_najcescu(char *s)
{
	char *pov = s;
	int max_p = 0,trenutno;
	char *poc_najcesce = NULL;
	char *p = s,*p5=s;
	
	if(*p == '\0') 
	return poc_najcesce;
	while(*p5!='\0')p5++;
	while(!((*p>='a' && *p<='z') || (*p>='A' && *p<='Z')) && *p!='\0') p++;
	if(p==p5)return s;
	while(*p != '\0') 
	{
		char *p1=p;
		char *p2=p;
		
		while(((*p2>='a' && *p2<='z') || (*p2>='A' && *p2<='Z')) && *p2!='\0') p2++;
	
		trenutno = 0;
		char *p3 = pov;
	
	while(*p3!='\0')
	{
		while(!((*p3>='a' && *p3<='z') || (*p3>='A' && *p3<='Z')) && *p3!='\0') p3++;
		
		char *p4=p3;
		
		while(((*p4>='a' && *p4<='z') || (*p4>='A' && *p4<='Z')) && *p4!='\0') p4++;
		
		int iste = 1;
		
		while(p3!=p4) 
		{
			if(*p != *p3) iste=0;
			p3++;
			p++;
		
			if(p3==p4) break;
		}
		if(iste && (p3==p4) && !((*p>='a' && *p<='z') || (*p>='A' && *p<='Z'))) trenutno++;
		p=p1;
	}
	
	if(trenutno>max_p)
	{
		max_p=trenutno;
		poc_najcesce=p;
		trenutno=0;
	}
		p=p2;
	
		while(!((*p>='a' && *p<='z') || (*p>='A' && *p<='Z')) && *p!='\0') p++;
	}
	if (max_p==trenutno)return s;
		poc_najcesce=p;
		char s2[200]=" ";
		char *s3=s2;
		int duzina=0;
		
		
		while(((*p>='a' && *p<='z') || (*p>='A' && *p<='Z')) && *p!='\0')
		{
			*s3 = *p;
			s3++;
			p++;
			duzina++;
		}
			*s3='\0'; 
			duzina++;
			char *p3=pov;
			
			while(*p3!='\0')
			{
				s3=s2;
				while(!((*p3>='a' && *p3<='z') || (*p3>='A' && *p3<='Z')) && *p3!='\0') p3++;
				
				char *p4=p3;
				
				while(((*p4>='a' && *p4<='z') || (*p4>='A' && *p4<='Z')) && *p4!='\0') p4++;
				
				int iste = 1;
				
				while(*s3 != '\0')
				{
					if(*s=='a'){*s++='-';s++;*s++='-';s++;*s='\0';return p;} 
					if(*p3 != *s3) iste=0;
					p3++;
					s3++;
					if(p3==p4) break;
				}
					if(iste && *s3=='\0')
					{
						if(*p4 == '\0')
						*(p4-duzina) = *p4;
							while(*p4++ != '\0')
							*(p4-duzina) = *p4;
			}
		}
	return pov;
}		

int main() {
	
	return 0;
}