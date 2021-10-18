#include <stdio.h>
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
//funckija koja vrši leksikografsko uporedjivanje karaktera
int strcmp(const char *s1, const char *s2){
	while(*s1!='\0' && *s2!='\0'){
		if(*s1<*s2) return -1;
		else if(*s1>*s2) return 1;
		else if(*(s1+1)=='\0' && *(s2+1)!='\0') return -1;
		else if(*(s2+1)=='\0' && *(s1+1)!='\0') return 1;
		else if(*(s1+1)=='\0' && *(s2+1)=='\0') return 0;
		else{
			s1++;
			s2++;
		}
	}
	if ((*s1)=='\0' && (*s2)=='\0') return 0;
		else if ((*s1)=='\0' && (*s2)!='\0') return -1;
		else return 1;
}
int genijalci(struct Student *p, int velicina, double prosjek){
	struct Student *pocetak=p;
	int n=0,i=0,broj_ocjena, pao,j,izbaceni=0, vel=velicina,n1=0,br=0,tmp;
	double prosjek_ocjena[50]={0}, prosjek_studenta=0,max[3]={0}, max_lokalni=0;
	while(n<velicina){
		prosjek_studenta=0;
		broj_ocjena=p->br_ocjena;
		//studentu ciji je broj ocjena=0, prosjek postaje 5.0 
		if(broj_ocjena<=0) prosjek_ocjena[n]=5.0;
		else {
			i=0;
			//blok naredbi koji ispituje da li student ima ijednu ocjenu 5, te racuna prosjek njegovih ocjena
			while (i<broj_ocjena) {
				pao=0;
				if(p->ocjene[i]==5) {
					prosjek_ocjena[n]=5.0;
					pao=1;
					break;
				}
				prosjek_studenta=prosjek_studenta + p->ocjene[i];
				i++;
			}
			if(pao==0){
				prosjek_studenta=prosjek_studenta/broj_ocjena;
				prosjek_ocjena[n]=prosjek_studenta;
			}
		}
		//if uslov ispituje da li je prosjek ocjena studenta manji od referentog prosjeka
		//ukoliko je uslov ispunjen, vrši se izbacivanje tog studenta iz niza
		if (prosjek_ocjena[n]<prosjek){
			struct Student *q=p;
			n1=n;
			while (n1<velicina-1) {
				*q = *(q+1);
				q++;
				n1++;
			}
			velicina--;
			n--;
			izbaceni++;
			p--;
			
		}
		n++;
		p++;
	}
	p=pocetak;
	//2 ugnijezdene petlje koje prosjek ocjena i-tog studenta spremaju na i-to mjesto niza koji sadrzi prosjecne ocjene svih preostalih studenata 
	for(i=0; i<velicina; i++){
		j=0;
		prosjek_studenta=0;
		while(j<p->br_ocjena){
			prosjek_studenta=prosjek_studenta + p->ocjene[j];
			j++;
		}
		prosjek_studenta=prosjek_studenta/p->br_ocjena;
		prosjek_ocjena[i]=prosjek_studenta;
		p++;
	}
	p=pocetak;
	int velicina1=velicina;
	//blok naredbi sadrzanih u while-petlji koje sluze za selekciju studenata cija imena trebaju biti ispisana
	while(velicina>0 && br<3){
		max_lokalni=0;
		//for-petlja koja prolazi kroz niz prosjek_ocjena svih studenata. 
		//trazi se najveci maksimum u nizu
		for(i=0; i<velicina1; i++){
			if(prosjek_ocjena[i]>max_lokalni) {
				max_lokalni=prosjek_ocjena[i];
				tmp=i;
			}
			//ukoliko je prosjek ocjena kod dva studenta isti, prelazi se na poredjenje prezimena po leksikografskom poretku
			else if(prosjek_ocjena[i]==max_lokalni){
				if(strcmp((p+tmp)->prezime,(p+i)->prezime)==-1) continue;
				else if(strcmp((p+tmp)->prezime,(p+i)->prezime)==1){
					max_lokalni=prosjek_ocjena[i];
					tmp=i;
				}
				//leksikografsko poredjenje imena(u slucaju da su sva dosadasnja poredjenja bila nedovoljna za utvrdjivanje koji se treba ispisati)
				else if(strcmp((p+tmp)->prezime,(p+i)->prezime)==0){
					if(strcmp((p+tmp)->ime,(p+i)->ime)==-1 || strcmp((p+tmp)->ime,(p+i)->ime)==0) continue;
					else if(strcmp((p+tmp)->ime,(p+i)->ime)==1){
						max_lokalni=prosjek_ocjena[i];
						tmp=i;
					}
				}
			}
		}
		//redni broj studenata koji trebaju biti ispisani sprema se u niz int max[3]
		max[br]=tmp;
		//prosjek ocjena studenta koji je vec selektovan za ispis se postavlja na nulu
		///razlog: da bi se omogucio pronalazak narednog studenta sa najboljim prosjekom
		prosjek_ocjena[tmp]=0;
		br++; 
		velicina--;
	}
	j=0;
	p=pocetak;
	//while petlja koja sluzi za ispis odabranih studenata(maksimalno 3)
	while(j<br){
		tmp=max[j];
		printf("%s %s\n", (p+tmp)->prezime, (p+tmp)->ime);
		j++;
	}
	return(vel-izbaceni);		
}
int main() {
	
	return 0;
}
