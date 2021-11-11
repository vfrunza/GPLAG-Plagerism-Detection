#include <stdio.h>
#include <math.h>
	struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
int genijalci(struct Student s[], int vel_niza, float prosjek){
	int i=0,j=0,k=0, brojac[3], n=0;
	char *p, *q;
	float niz_prosjeka[50], suma=0, max[3];
	for(i=0; i<vel_niza; i++){
		suma=0;
		for(j=0; j<s[i].br_ocjena; j++){
			if(s[i].ocjene[j]==5){
				k=1;
			}
			suma+=s[i].ocjene[j];
		}
		if(k==1){
			niz_prosjeka[i]=5.0;
			k=0;
		} else if(suma==0){
				niz_prosjeka[i]=5.0;
		}
	else {
		niz_prosjeka[i]=(suma/s[i].br_ocjena);
	}
		
	}
	
	
	
	
	for(i=0; i<vel_niza; i++){
		if(niz_prosjeka[i]<prosjek){
			for(j=i; j<vel_niza-1; j++){
					  s[j]=  s[j+1];
					niz_prosjeka[j]=niz_prosjeka[j+1];
			}
				vel_niza--;
				i--;
			}
	
		}
		for(j=0; j<3; j++){
			max[j]=5.0;
		for(i=0; i<vel_niza; i++){
			haha:
			if(niz_prosjeka[i]>max[j]){
			max[j]=niz_prosjeka[i];
			brojac[j]=i;
			} else if(niz_prosjeka[i]==max[j]){ 
			if(s[i].prezime[0]<s[brojac[j]].prezime[0]){
			max[j]=niz_prosjeka[i];
			brojac[j]=i;
			} else if(s[i].prezime[0]==s[brojac[j]].prezime[0]){
				p=s[i].ime;
				q=s[brojac[j]].ime;
					while(*p!='\0'){
                if(*p==*q){
                    q++;
                    if(*q=='\0'){
                        i++;
                        goto haha;
                    }
                } else if(*q>*p){
                 max[j]=niz_prosjeka[i];
                 brojac[j]=i;
        i++;
                 goto haha;
                } else{
                i++;
                goto haha;
                }
                p++;
			}
			}
			}
		}
		if(max[j]<prosjek) break;
		n++;
	niz_prosjeka[brojac[j]]=0;
}
for(i=0;i<n;i++){
    printf("%s %s\n",s[brojac[i]].prezime, s[brojac[i]].ime);
}

	return vel_niza;
			
			
}
int main() {

	return 0;
}
