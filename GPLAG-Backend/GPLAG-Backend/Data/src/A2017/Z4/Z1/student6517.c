#include <stdio.h>

void Unesi(char *pok, int vel)
{
    char znak;
    int i=0;
    
    znak=getchar();
    
    if(znak=='\n')
    znak=getchar();
    
    while(znak!='\n' && i<vel-1)
    {
        *pok=znak;
        
        znak=getchar();
        
        pok++;
        i++;
    }
    
    *pok='\0';
}

void Ispisi(char *pok)
{
    while(*pok!='\0')
    {
        printf("%c", *pok);
        pok++;
    }
}

void NapraviMjesto(char *poc, int br_cifara)
{
    char *kraj;
    
    kraj=poc;
    
    while(*kraj!='\0')
    kraj++;
    
    while(kraj!=poc)                   /*pravi se mjesto za broj koji se treba unijeti, */
    {                                   /* uzimajuci u obzir i razmak koji ide poslije i predznak broja*/
        *(kraj+br_cifara)= *kraj;
        *kraj=' ';
        kraj--;
    }
    
}

void UbaciBroj(char *poc, int predznak, char *cifre, int br_cifara)
{
    int i=0;
    
    if(predznak==-1)
    {
        *poc='-';
        poc++;
    }
    
    cifre=cifre+br_cifara-1;
    
    while(i!=br_cifara)
    {
        *poc=*(cifre-i);
        poc++;
        i++;
    }
}

char *ubaci_broj(char *poc, int broj)
{
    int br_cifara=0, tmp, predznak=1, i=0;
    char *pok, *ubaci, niz[10];
    
    if(broj<0)
    {
        predznak=-1;
        br_cifara++;
        broj*=-1;
    }
    
    tmp=broj;
    
    while(tmp!=0)
    {
        tmp/=10;
        br_cifara++;
    }
    
    if(predznak==-1)
    i++;
    
    while(i!=br_cifara)
    {
        niz[i]=broj%10 +'0';
        broj/=10;
        i++;
    }
    
    //printf("Broj naopacke glasi: %d \n", naopacke);
    
    pok=poc;
    
    while(*pok==' ' && *pok!='\0')
    pok++;
    
    while(*pok!='\0')
    {
        while(*pok!=' ' && *pok!='\0')
        pok++;
        
        ubaci=pok;
        
        while(*pok==' ' && *pok!='\0')
        pok++;
        
        if(*pok!=' ' && *pok!='\0')
        {
            NapraviMjesto(ubaci, br_cifara+1);
            
            ubaci++;
            UbaciBroj(ubaci, predznak, niz, br_cifara);
            
            if(predznak==1)
            pok=ubaci+(br_cifara+1); /*broj cifara->n; razmak poslije broja-> 1; predzank broja->1*/
            else
            pok=ubaci+br_cifara+2;
        }
        else if(*pok!='\0')
        {
            NapraviMjesto(ubaci, br_cifara);
            ubaci++;
            UbaciBroj(ubaci, predznak, niz, br_cifara);
            
            if(predznak==1)
            pok=ubaci+(br_cifara+1);
            else
            pok=ubaci+br_cifara+2;
        }
    }
    
    return poc;
}

int main() 
{
	/*char tekst[100];
	int broj;
	
	printf("Unesite neki tekst: \n");
	Unesi(tekst, 100);
	
	printf("Unesite neki broj: \n");
	scanf("%d", &broj);
	
	ubaci_broj(tekst, broj);
	
	Ispisi(tekst);*/
	
	/*char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
    printf("\"%s\"", ubaci_broj(s, 320));*/
    
    char s[65] = "Sada cemo probati sa negativnim brojem";
    printf("\"%s\"", ubaci_broj(s, -528));
	
	return 0;
}




























/*#include <stdio.h>
#include <math.h>

void unesi(char* niz, int velicina) {
    char znak = getchar();
    int i = 0;
    
    if (znak == '\n') 
    znak=getchar();
   
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    
    niz[i]='\0';                  
}

int duzina(int broj)
{
    int duz=0;
    
    if(broj<0){
    duz++;
    broj=-broj;}
    
    
    while(broj)
    {
    	broj=broj/10;
    	duz++;
    }
    
    return duz;
}



char* ubaci_broj(char* string, int broj)
{
    int i=0, temp, predznak, duzz;
    char *p, *kraj;
    
   	p=string;
   	
   	if(broj<0)
   	predznak=-1;
   	else
   	predznak=1;
   	
   	duzz=duzina(broj);
   
    while(*string!='\0')
    {
        
        if(*string==' ')
        {
        	kraj=string;
        	
        	while(*kraj!='\0')
   			kraj++;
			
			while(kraj>string)
			{
				*(kraj+duzz)=*kraj;
				kraj--;
			}
            
            temp=broj;
            
			string+=duzz;
	
			
			temp=fabs(broj);
			
			while(temp!=0)
			{
			    *string=temp%10+'0';
			    temp/=10;
			    string--;
			}
			
			if(predznak==-1){
			    *string='-';
			    string--;}
			
			string+=duzz+1;
			
			if(*string!=' ')
			{
			    kraj=string;
			    
			    while(*kraj!='\0')
			    kraj++;
			
			    while(kraj>=string)
			    {
			        *(kraj+1)=*kraj;
			        kraj--;
			    }
			    
			    *string=' ';
			}
			
        }
            
        string++;
        
        kraj=string;
        while(*kraj!='\0')
            {
                kraj++;
                if(*kraj=='\0')
                string=kraj;
                if(*kraj!=' ')
                break;
            }
        
    }
    return p;
}


int main(){
    char string[100];
    int broj;
    
    printf("Unesite neki string: ");
    unesi(string, 100);
    
    printf("Unesite neki broj: ");
    scanf("%d", &broj);
  
    return 0;
}*/