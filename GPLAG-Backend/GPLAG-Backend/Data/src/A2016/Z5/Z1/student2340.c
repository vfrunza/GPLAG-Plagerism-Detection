/*Data je struktura koja opisuje uspjeh studenta na fakultetu:

struct Student {
char ime[20], prezime[20];
int ocjene[50];
	int br_ocjena;
};
Niz ocjene sadrži sve ocjene koje je student stekao tokom studija, a br_ocjena je broj članova tog niza. Ocjene su cijeli brojevi na 
intervalu [5,10] (nije potrebno provjeravati).

*/

#include <stdio.h>
#include <math.h>
#include <string.h>

void unesi(char *niz, int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}


struct Student {
		char ime[20],prezime[20];
		int ocjene[50];
		int br_ocjena;
		};
		
struct Student unos_studenta(){
    struct Student s;
    int i;
        printf("Unesite ime: ");
        unesi(s.ime,20);
        printf("Unesite prezime: ");
        unesi(s.prezime,20);
        printf("Unesite broj ocjena: ");
        scanf("%d",&s.br_ocjena);
        printf("Unesite ocjene: ");
        for(i=0; i<s.br_ocjena; i++)
        scanf("%d",&s.ocjene[i]);
    return s;
}

/*Napisati funkciju genijalci koja prima niz studenata, veličinu niza i realan broj prosjek, te iz niza izbacuje sve studente čiji je 
prosjek ocjena manji od unesenog prosjeka. Redoslijed studenata u nizu nakon izbacivanja treba ostati nepromijenjen! Ako student ima 
evidentiranu barem jednu ocjenu 5 smatra se da mu je prosjek 5.0 bez obzira na ostale ocjene. Također ako student nema nijednu
registriranu ocjenu uzima se prosjek 5.0. Funkcija treba vratiti broj studenata koji su preostali u nizu nakon izbacivanja.

*/

float prosjek_ocjene(struct Student s){
    int k,suma=0;
    float y;
    
    if(s.br_ocjena<1) return 0;
    
    for (k=0; k<s.br_ocjena;k++){
        if (s.ocjene[k] == 5.0 )
            return 5.0;
        suma+=s.ocjene[k];
    }
    y=(float)suma/s.br_ocjena;

    if(suma==0) 
        y=5.0;
    return y;
}

int veci(struct Student s1, struct Student s2){
    if(strcmp(s1.prezime,s2.prezime)>0)
        return 1;
    else if(strcmp(s1.prezime,s2.prezime)==0)
        return strcmp(s1.ime,s2.ime)>0;
    
    return -1;
}

int genijalci(struct Student *niz_studenata, int velicina_niza, float prosjek){
    int i,j,index=-1,index2=-1,index3=-1;
    float prvimax=-1,drugimax=-1,trecimax=-1;
    //struct Student tmp;
    	for(i=0;i<velicina_niza;i++){
		    if(prosjek_ocjene(niz_studenata[i])<prosjek){
		        
		            for(j=i;j<velicina_niza-1;j++){
		            	niz_studenata[j]=niz_studenata[j+1];
		            	}
	            	velicina_niza--;
	            	i--;
	        	}
            }
        //printf("%.2f\n", prosjek);
        //for (i = 0; i < velicina_niza; ++i)
        //    printf ("%s %s %.2f\n", niz_studenata[i].prezime, niz_studenata[i].ime, prosjek_ocjene(niz_studenata[i]));
        
        for(i=0; i<velicina_niza;i++){
            if(prosjek_ocjene(niz_studenata[i])>prvimax){
                trecimax=drugimax; drugimax=prvimax; prvimax=prosjek_ocjene(niz_studenata[i]);
                index3=index2; index2=index; index=i;
            }
        
        //printf("index prvog: %d\n", index);
        
           
            else if(prosjek_ocjene(niz_studenata[i])>drugimax){
                trecimax=drugimax;drugimax=prosjek_ocjene(niz_studenata[i]);
                index3=index2; index2=i;
            }
            
            
            else if (prosjek_ocjene(niz_studenata[i])>trecimax){
                trecimax=prosjek_ocjene(niz_studenata[i]);
                index3=i;
            }
           
        }
        
        
        for(i=0;i<velicina_niza;i++){
                if(prosjek_ocjene(niz_studenata[i])== prvimax && veci(niz_studenata[i],niz_studenata[index])){
                index=i;
            }
        }
        for(i=0;i<velicina_niza;i++){
            if(prosjek_ocjene(niz_studenata[i])==drugimax && veci(niz_studenata[index2],niz_studenata[i]) && index != i){
                    index2=i;
            }
        }
        for(i=0;i<velicina_niza;i++){
            if(prosjek_ocjene(niz_studenata[i])==trecimax && veci(niz_studenata[index3],niz_studenata[i]) && index2 != i && index !=i){
                    index3=i;
             } 
            }
            
        if(index!=-1)
            printf("%s %s \n",niz_studenata[index].prezime,niz_studenata[index].ime);
        if(index2!=-1)    
            printf("%s %s \n",niz_studenata[index2].prezime,niz_studenata[index2].ime);
         if(index3!=-1)
            printf("%s %s \n",niz_studenata[index3].prezime,niz_studenata[index3].ime);
       
        
    return velicina_niza;
}


/*
Osim toga funkcija treba na ekranu ispisati prezime i ime studenta sa najvećim prosjekom, zatim drugog i trećeg po prosjeku, svakog u 
zasebnom redu kao u sljedećem primjeru:
	Saric Sara
	Mujic Mujo
	Hanic Hana
Pri tome ne smiju se ispisivati studenti čiji je prosjek manji od primljenog parametra. Ako ne postoje tri studenta koji ispunjavaju 
ove uslove treba ispisati samo najbolja dva ili samo najboljeg ili ne ispisati ništa. U slučaju da više studenata ima istu prosječnu 
ocjenu, najprije treba biti ispisan onaj čije je prezime ispred po leksikografskom redoslijedu, a ako imaju isto prezime onda onaj 
čije je ime ispred po leksikografskom redoslijedu. Ako studenti imaju isto prezime i ime i isti prosjek ocjena, svejedno je kojim 
redoslijedom ćete ih ispisati :)

Nije dozvoljeno sortirati niz studenata! Redoslijed mora ostati nepromijenjen.*/



int main() {
    int i;
    float a;
    struct Student s [100];
	printf("Unesite podatke o studentu:\n");
	while (i<100){
	s[i]=unos_studenta();
	    i++;
	};
	printf("Unesite prosjek: ");
	scanf("%f",&a);
	
	printf("Broj studenata:%d",genijalci(s,i,a));
	

    
	return 0;
}
