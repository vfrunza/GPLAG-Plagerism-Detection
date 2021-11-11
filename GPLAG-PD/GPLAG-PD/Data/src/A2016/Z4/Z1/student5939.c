#include <stdio.h>
void unesi (char niz[], int velicina) {
	char znak=getchar();
	if (znak=='\n') {
		znak=getchar();
	}
	int i=0;
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int duzina(char *ptr) {
	
	char *str = ptr;
	while (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))) {
		str = str + 1;
	}
	
	return str - ptr;
	
}
int prebroji (char *ptr) {
	
	int status = 1;
	int ukupno = 0;
	int mala_slova = 0;
	int velika_slova = 0;

    
	while(*ptr!='\0') {
		mala_slova = *ptr >= 'a' && *ptr <= 'z';
		velika_slova = *ptr >= 'A' && *ptr <= 'Z';
		
		if (!(mala_slova || velika_slova)) {
			status = 1;
		}
		else if (status) {
			status = 0;
			ukupno = ukupno + 1;
		}
		ptr = ptr + 2;
	}
	
	return ukupno;
}


void izbaci(char *str, char *slovo) {
	
	int velika_slova = 0;
	int mala_slova = 0;
	char *pokazivac = str;
	int jednako = 0;
	char *leksem = slovo;
	char *x = slovo;
	
	if(*pokazivac) {
	    return str;
	}
	
	while (*pokazivac) {
		        while(!((*pokazivac>='A' && *pokazivac<='Z') || (*pokazivac>='a' && *pokazivac<='z'))) 
		        pokazivac++;
        if(*pokazivac==*leksem || (*pokazivac>='A' && *pokazivac<='Z' && *leksem>='a' && *leksem<='z' && *leksem - *pokazivac == 'a' - 'A') || (*pokazivac>='a' && *pokazivac<='z' && *leksem>='A' && *leksem<='Z' && *pokazivac - *leksem == 'a' - 'A') )
        {
            int razmak=0; char*pokazivac2=pokazivac, *z=pokazivac;
            
            
            while(*pokazivac2==*leksem || (*pokazivac2>='A' && *pokazivac2<='Z' && *leksem>='a' && *leksem<='z' && *leksem - *pokazivac2 == 'a' - 'A') || (*pokazivac2>='a' && *pokazivac2<='z' && *leksem>='A' && *leksem<='Z' && *pokazivac2 - *leksem == 'a' - 'A') )
            {
                pokazivac2++; leksem++; razmak++;
                if(!((*pokazivac2>='A' && *pokazivac2<='Z') || (*pokazivac2>='a' && *pokazivac2<='z')) && *leksem=='\0')
                {
                    if(*pokazivac2) {
                        *pokazivac='\0'; 
                        break;
                    }
                    
                    while(*pokazivac2)
                    {
                        *z=*pokazivac2;
                        z++; pokazivac2++;
                    }
                    
                    *z='\0'; 
                    leksem=slovo;
                }
            }
        }
       
        pokazivac++;
    }
   
   
}



char* izbaci_najcescu(char *s) {
    char *start=s;
    char string2[150]={'\0'};
    char najcesca_rijec[150]={'\0'};
    char *str2=string2;
    char *pocetak2=string2, *str1=0;
    int broj_ponavljanja=0; 
    int najveci=0;
   // int ukupno_rijeci=0;
   // ukupno_rijeci=prebroji(s);

    if(duzina(s)==0 ) return s;
    while(*start!='\0')
    {   if(!( (*start>='A' && *start<='Z') || (*start>='a' && *start<='z') )) break;
        broj_ponavljanja=0;
        while ( (*start>='A' && *start<='Z') || (*start>='a' && *start<='z') )
        {
        *str2=*start;
        start++; str2++;
        }
   
    str2=pocetak2;
    *str2='\0'; 
    str1=start;


    while(*str1)
    {
        char *prvi=str1, *drugi=str2;

        while(*prvi == *drugi || (*prvi>='A' && *prvi<='Z' && *drugi>='a' && *drugi<='z' && *drugi - *prvi == 'a' - 'A') || (*prvi>='a' && *prvi<='z' && *drugi>='A' && *drugi<='Z' && *prvi - *drugi == 'a' - 'A') )
        {
            prvi++; drugi++;

            if(*drugi=='\0' && (str1==s || !( (*(str1-1)>='A' && *(str1-1)<='Z') || (*(str1-1)>='a' && *(str1-1)<='z') ) ) && ( ( !( (*prvi>='A' && *prvi<='Z') || (*prvi>='a' && *prvi<='z') ) ) || *prvi=='\0' ) ) {broj_ponavljanja++; str2=pocetak2; break;}
           
        }
        str1++;
    }


    if (broj_ponavljanja>najveci)
    {
      najveci=broj_ponavljanja;
      char *str3;
      *str3=najcesca_rijec;
       char *c=pocetak2;
       while(*c!='\0')
       {
        *str3=*c;
        c++; str3++;
       } *str3='\0';
    }
       
    start ++;
       
    }
   
   izbaci(s,najcesca_rijec);
   
    return s; 
}

int main() {
	
	return 0;
}
