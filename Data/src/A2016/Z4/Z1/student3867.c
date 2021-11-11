#include <stdio.h>

/*standard kopirana funkcija*/
void unesi(char niz[], int velicina)
{
    int i=0;
    char znak=getchar();
    if (znak=='\n')
        znak=getchar();
    while(i<velicina-1 && znak!='\n')
    {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

char* izbaci_najcescu(char* s)
{
    int i=0,j=0,k=0,n=0,m=0,h=0,d=0,max=0,point=0,razmak=0;
    int hist[250000]={0};
    char pom[250000]={0},pom_1[250000],najces[250000];
    
/*iz unesenog stringa pravimo novi string u kojem ce se nalaziti samo rijeci odvojene sa jednim razmakom*/
/*rjesavamo se svega sto nisu slova, tj. sve sto odvaja neka slova smatramo jednim razmakom*/
    for(i=0;*(s+i)!='\0';i++)
    {
        if((*(s+i)>64 && *(s+i)<91) || (*(s+i)>96 && *(s+i)<123))
        {
            pom[j]=*(s+i);
            j++;
        }
        if(i>0)
        {
            if((*(s+i)<65 || (*(s+i)>90 && *(s+i)<97) || *(s+i)>122) && ((*(s+i-1)>64 && *(s+i-1)<91) || (*(s+i-1)>96 && *(s+i-1)<123)))
            {
                if(j>0)
                {
                    if(pom[j-1]==32)
                        continue;
                }
                pom[j]=' ';
                j++;
            }
            else continue;
        }
    }
    if(j>0)
    {
        if(pom[j-1]==32)
            pom[j-1]='\0';
    }
    else pom[j]='\0';
/**/

/*iz novog stringa(string sa samo rijecima) izdvajamo rijec po rijec i provjeravamo koliko se puta ponavlja*/
/*koristeci histogram biljezimo koja je rijec po redu*/
/*poziciju u histogramu povecavamo kada se u stringu dodje do razmaka*/
    j=0;
    for(i=0;;i++)
    {
        if(pom[i]!=32)
        {
            pom_1[j]=pom[i];
            j++;
        }
        else if(pom[i]==32)
        {
            pom_1[j]='\0';
            n=0;
            m=0;
            for(k=0;;k++)
            {
                if(n<j)
                {
                    if(pom_1[n]==pom[k] || pom_1[n]==pom[k]-32 || pom_1[n]==pom[k]+32)
                    {
                        n++;
                        m++;
                        if(k>=j)
                        {
                            if((pom[k+1]==32 || pom[k+1]=='\0') && j==m && pom[k-m]==32)
                            {
                                    hist[h]++;
                                    m=0;
                                    n=0;
                            }
                        }
                        if(((pom[k+1]>64 && pom[k+1]<91)||(pom[k+1]>96 && pom[k+1]<123)) && j==m)
                        {
                            m=0;
                            n=0;
                        }
                        if(k>0)
                        {
                            if((m==1) && ((pom[k-1]>64 && pom[k-1]<91) || (pom[k-1]>96 && pom[k-1]<123)))
                            {
                                m=0;
                                n=0;
                            }
                        }
                        else
                        {
                            hist[h]++;
                            m=0;
                            n=0;
                        }
                    }
                }
                if(pom[k]=='\0')
                {
                    if((pom[k-1]==32 || pom[k-1]=='\0') && j==m)
                    {
                        hist[h]++;
                        m=0;
                        n=0;
                    }
                    break;
                }
            }
            j=0;
            h++;
        }
        if(pom[i]=='\0')
            break;
    }
/**/

/*iz histograma pronalazimo koja po redu rijec se najvise puta ponavlja*/
/*najveca vrijednost sa lijeva*/
    max=hist[0];
    for(i=0;i<h+1;i++)
    {
        if(hist[i]>max)
        {
            max=hist[i];
            point=i;
        }
    }
/**/

/*pravimo string koju cini samo rijec koja se najvise ponavlja*/
/*tu rijec pronalazimo tako sto uz pomoc pozicije iz histograma trazimo mjesto kada su razmak i pozicija jednaki*/
/*string cine svi karakteri od mjesta kada je razmak jednak poziciji do mjesta gdje je sljedeci razmak*/
    d=0;
    for(i=0;;i++)
    {
        if(razmak==point)
        {
            najces[d]=pom[i];
            d++;
        }
        if(point<razmak)
        {
            najces[d-1]='\0';
            break;
        }
        if(pom[i]=='\0')
        {
            najces[d-1]='\0';
            break;
        }
        if(pom[i]==32)
            razmak++;
    }
    d--;
    m=0;
    n=0;
/**/

/*uz pomoc stringa najcesce ponavljane rijeci, prolazimo kroz prvobitni string*/
/*te na svakom mjestu gdje se pojavi takva rijec koja odgovara najcescoj(po postavci zadatka) brisemo iz prvobitnog stringa*/
    razmak=0;
    for(i=0;;i++)
    {
        if(m==1 && razmak>0)
        {
            if((*(s+i-2)>64 && *(s+i-2)<91) || (*(s+i-2)>96 && *(s+i-2)<123))
                m=0;
        }
        if(*(s+i)>64 && *(s+i)<91)
        {
            if(najces[m]==*(s+i) || najces[m]==*(s+i)+32)
                m++;
            else m=0;
        }
        if(*(s+i)>96 && *(s+i)<123)
        {
            if(najces[m]==*(s+i) || najces[m]==*(s+i)-32)
                m++;
            else m=0;
        }
        if(m==d && (*(s+i)<65 || (*(s+i)>90 && *(s+i)<97) || *(s+i)>122))
        {
            for(j=i-d;;j++)
            {
                *(s+j)=*(s+j+d);
                if(*(s+j+d)=='\0')
                    break;
            }
            i-=d;
            m=0;
        }
        if(*(s+i)<65 || (*(s+i)>90 && *(s+i)<97) || *(s+i)>122)
            razmak++;
        if(*(s+i)=='\0')
            break;
    }
/**/
    return s;
}

int main()
{
	char str[250000];
	unesi(str,250000);
	printf("%s",izbaci_najcescu(str));
	return 0;
}