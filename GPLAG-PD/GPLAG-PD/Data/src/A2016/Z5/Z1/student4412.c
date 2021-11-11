#include <stdio.h>

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int strcp(const char *s1, const char *s2, int velikamala){
	char tmp1, tmp2;
	while(*s1 != '\0' && *s2 != '\0'){
		tmp1 = *s1;
		tmp2 = *s2;
		if(tmp1 >= 'A' && tmp1 <= 'Z' && velikamala==0)
			tmp1 += 32;
		if(tmp2 >= 'A' && tmp2 <= 'Z' && velikamala==0)
			tmp2 += 32;
		if(tmp1 < tmp2) return -1;
		if(tmp1 > tmp2) return 1;
		s1++;
		s2++;
	}
	if(*s1 != '\0') return 1;
	if(*s2 != '\0') return -1;
	return 0;
}

double Prosjek(int niz_ocjena[], int vel_niza){
	int suma = 0, i;
	if(vel_niza == 0) return 5.0;
	for(i = 0; i < vel_niza; i++){
		if(niz_ocjena[i] == 5) return 5.0;
		suma += niz_ocjena[i];
	}
	return (double)suma / vel_niza;
}

void Zamjena_int_niza(int niz_ocjena_1[], int vel_niza_1, int niz_ocjena_2[], int vel_niza_2) {
	int i;
	for( i = 0; i < vel_niza_2; i++){
		niz_ocjena_1[i] = niz_ocjena_2[i];
	}
	return;
}

int Prije_po_leksifografskom(char *prva, char *druga){
	char *pom_prva, *pom_druga;
	pom_prva=prva;
	pom_druga=druga;
	
	while(*pom_prva!='\0' || *pom_druga!='\0'){
		if(*pom_prva<*pom_druga) return 1;
		else if(*pom_druga<*pom_prva) return 2;
		pom_prva++;
		pom_druga++;
	}
	return 0;
}

void Ispis_Studenata_Niza_Po_Prosjeku(struct Student niz_studenata[], int vel_niza, double trazeni_prosjek){
	if(vel_niza == 0) return;
	else if(vel_niza == 1){
		if(Prosjek(niz_studenata[0].ocjene, niz_studenata[0].br_ocjena) >= trazeni_prosjek)
			printf("%s %s\n", niz_studenata[0].prezime, niz_studenata[0].ime);
	}
	else if(vel_niza == 2){
		if(Prosjek(niz_studenata[0].ocjene, niz_studenata[0].br_ocjena) > Prosjek(niz_studenata[1].ocjene, niz_studenata[1].br_ocjena) && Prosjek(niz_studenata[0].ocjene,niz_studenata[0].br_ocjena) >= trazeni_prosjek ) {
            printf("%s %s\n%s %s\n", niz_studenata[0].prezime, niz_studenata[0].ime,niz_studenata[1].prezime, niz_studenata[1].ime);
        }
        else if(Prosjek(niz_studenata[1].ocjene, niz_studenata[1].br_ocjena) > Prosjek(niz_studenata[0].ocjene, niz_studenata[0].br_ocjena) && Prosjek(niz_studenata[1].ocjene,niz_studenata[1].br_ocjena) >= trazeni_prosjek) {
            printf("%s %s\n%s %s\n", niz_studenata[1].prezime, niz_studenata[1].ime,niz_studenata[0].prezime, niz_studenata[0].ime);
        }
        else if(Prosjek(niz_studenata[1].ocjene, niz_studenata[1].br_ocjena) == Prosjek(niz_studenata[0].ocjene, niz_studenata[0].br_ocjena) && Prosjek(niz_studenata[0].ocjene,niz_studenata[0].br_ocjena) >= trazeni_prosjek) {
                if(Prije_po_leksifografskom(niz_studenata[0].ime, niz_studenata[1].ime)==1){
                    printf("%s %s\n%s %s\n", niz_studenata[0].prezime, niz_studenata[0].ime, niz_studenata[1].prezime, niz_studenata[1].ime);
                }
                else if(Prije_po_leksifografskom(niz_studenata[0].ime, niz_studenata[1].ime)==2){
                    printf("%s %s\n%s %s\n", niz_studenata[1].prezime, niz_studenata[1].ime, niz_studenata[0].prezime, niz_studenata[0].ime);
                }
                else if(Prije_po_leksifografskom(niz_studenata[0].ime, niz_studenata[1].ime)==0){
                    if(Prije_po_leksifografskom(niz_studenata[0].prezime, niz_studenata[1].prezime)==1){
                        printf("%s %s\n%s %s\n", niz_studenata[0].prezime, niz_studenata[0].ime, niz_studenata[1].prezime, niz_studenata[1].ime);
                    }
                    else if(Prije_po_leksifografskom(niz_studenata[0].prezime, niz_studenata[1].prezime)==2){
                        printf("%s %s\n%s %s\n", niz_studenata[1].prezime, niz_studenata[1].ime, niz_studenata[0].prezime, niz_studenata[0].ime);
                    }
                    else if(Prije_po_leksifografskom(niz_studenata[0].ime, niz_studenata[1].ime)==0){
                        printf("%s %s\n%s %s\n", niz_studenata[1].prezime, niz_studenata[1].ime, niz_studenata[0].prezime, niz_studenata[0].ime);
                    }
                }
        }
	}
	else if(vel_niza >= 3){
		int i=0;
		int index_drugog_najboljeg=-1;
		int index_treceg_najboljeg=-1;
		double pomocni_prosjek=5.0, prosjek_prvog, prosjek_drugog, prosjek_treceg;
		int index_najboljeg=-1;
		for(i=0; i<vel_niza; i++){
			if(Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena) - pomocni_prosjek>0.0001 && Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)>=trazeni_prosjek  ){
				index_najboljeg=i;
				pomocni_prosjek=Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena);
				prosjek_prvog=pomocni_prosjek;
			}
		}
		pomocni_prosjek=5.0;
		for(i=0; i<vel_niza; i++){
			if(Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)-pomocni_prosjek>0.0001 && Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)>=trazeni_prosjek && i!=index_najboljeg){
				if((Prije_po_leksifografskom(niz_studenata[i].prezime,niz_studenata[index_drugog_najboljeg].prezime)==1 && Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)==pomocni_prosjek) || (Prije_po_leksifografskom(niz_studenata[i].prezime,niz_studenata[index_drugog_najboljeg].prezime)==0 && Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)==pomocni_prosjek && Prije_po_leksifografskom(niz_studenata[i].ime,niz_studenata[index_drugog_najboljeg].ime)==1 )){
    				index_drugog_najboljeg=i;
    				pomocni_prosjek=Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena);
    				prosjek_drugog=pomocni_prosjek;
				}
				else if(Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)!=pomocni_prosjek){
				    index_drugog_najboljeg=i;
    				pomocni_prosjek=Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena);
    				prosjek_drugog=pomocni_prosjek;
				}
			}
		}
		
		pomocni_prosjek=5.0;
		for(i=0;i<vel_niza;i++){
            if(Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)-pomocni_prosjek>0.0001 && Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)>=trazeni_prosjek && i!=index_najboljeg && i!=index_drugog_najboljeg ){
                if((Prije_po_leksifografskom(niz_studenata[i].prezime,niz_studenata[index_treceg_najboljeg].prezime)==1 && Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)==pomocni_prosjek) || (Prije_po_leksifografskom(niz_studenata[i].prezime,niz_studenata[index_treceg_najboljeg].prezime)==0 && Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)==pomocni_prosjek && Prije_po_leksifografskom(niz_studenata[i].ime,niz_studenata[index_treceg_najboljeg].ime)==1 )){
    				index_treceg_najboljeg=i;
    				pomocni_prosjek=Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena);
    				prosjek_treceg=pomocni_prosjek;
				}
				else if(Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena)!=pomocni_prosjek){
				    index_treceg_najboljeg=i;
    				pomocni_prosjek=Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena);
    				prosjek_treceg=pomocni_prosjek;
				}
            }
        }
        if(index_najboljeg!=-1 && index_treceg_najboljeg!=-1 && index_drugog_najboljeg!=-1 ){

            int prije_po_l12=Prije_po_leksifografskom(niz_studenata[index_najboljeg].prezime,niz_studenata[index_drugog_najboljeg].prezime);
            int prije_po_l13=Prije_po_leksifografskom(niz_studenata[index_najboljeg].prezime,niz_studenata[index_treceg_najboljeg].prezime);
            int prije_po_l23=Prije_po_leksifografskom(niz_studenata[index_drugog_najboljeg].prezime,niz_studenata[index_treceg_najboljeg].prezime);
            if(prosjek_prvog!=prosjek_drugog && prosjek_prvog!=prosjek_treceg && prosjek_drugog!=prosjek_treceg)
            {
                printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
            }
            else if(prosjek_prvog!=prosjek_drugog && prosjek_drugog==prosjek_treceg){
                if(prije_po_l23==1){
                    printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                    printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                    printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                }
                else if(prije_po_l23==2){
                    printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                    printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                    printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                }
                else {
                    int prije_po_li23=Prije_po_leksifografskom(niz_studenata[index_drugog_najboljeg].ime,niz_studenata[index_treceg_najboljeg].ime);
                    if(prije_po_li23==1){
                        printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                    }
                    else {
                         printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                         printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                         printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                    }
                }

            }
            else if(prosjek_prvog==prosjek_drugog && prosjek_drugog==prosjek_treceg){

                    if(prije_po_l12==1 && prije_po_l13==1){
                        if(prije_po_l23==1){
                            printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                        }
                        else {
                            printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                        }
                    }
                    else if(prije_po_l12==1 && prije_po_l13==2){
                            printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                    }
                    else if(prije_po_l12==2 && prije_po_l13==1){
                            printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);

                    }
                    else if(prije_po_l12==2 && prije_po_l13==2){
                        if(prije_po_l23==1){
                            printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);

                        }
                        else{
                            printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                            printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);

                        }
                    }
                    else if(prije_po_l12==0 && prije_po_l23==1){
                        printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                    }
                    else if(prije_po_l12==0 && prije_po_l23==2){

                        printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                    }
                    else if(prije_po_l23==0 && prije_po_l12==1){
                        printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                    }
                    else if(prije_po_l23==0 && prije_po_l12==2){
                        printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                    }
                    else if(prije_po_l13==0 && prije_po_l12==1){
                        printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                        printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);

                    }
                    else if(prije_po_l13==0 && prije_po_l12==2){
                         printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                         printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                         printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                    }
                    else if(prije_po_l12==0 && prije_po_l23==0){
                         printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                         printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                         printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                    }

            }
            else if(prosjek_prvog==prosjek_drugog && prosjek_drugog!=prosjek_treceg){
                if(prije_po_l12==1){
                    printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                    printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                    printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                }
                else{
                    printf("%s %s \n", niz_studenata[index_drugog_najboljeg].prezime, niz_studenata[index_drugog_najboljeg].ime);
                    printf("%s %s \n", niz_studenata[index_najboljeg].prezime, niz_studenata[index_najboljeg].ime);
                    printf("%s %s \n", niz_studenata[index_treceg_najboljeg].prezime, niz_studenata[index_treceg_najboljeg].ime);
                }

            }
        }
	}
}

int genijalci (struct Student niz_studenata[], int vel_niza, double prosjek){
	int i;
	for(i=0; i<vel_niza; i++){
		if(Prosjek(niz_studenata[i].ocjene, niz_studenata[i].br_ocjena) < prosjek){
			int j;
			for(j=i; j<vel_niza-1; j++){
				niz_studenata[j]=niz_studenata[j+1];
			}
			vel_niza--;
			i--;
		}
	}
	Ispis_Studenata_Niza_Po_Prosjeku(niz_studenata, vel_niza, prosjek);
	return vel_niza;
}

int main(){
   struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 6, 6.5);

	return 0;
}
































