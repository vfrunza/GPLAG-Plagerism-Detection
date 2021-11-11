#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
char ime[20], prezime[20];
int ocjene[50];
	int br_ocjena;
};

void unesi(char niz[], int velicina) {
		char znak=getchar();
		if(znak='\n') znak=getchar();
		int i=0;
		while(i<velicina-1 && znak!='\n') {
			niz[i]=znak;
			i++;
			znak=getchar();
		}
			niz[i]='\0';
	}
struct Student unesi_studenta() {
		struct Student s;
		int i;
		unesi(s.ime,20);
		unesi(s.prezime,20);
		scanf("%d",&s.br_ocjena);
		for(i=0;i<s.br_ocjena;i++){
				scanf("%d",&s.ocjene[i]);
		}
		return s;
}
	double prosjek(struct Student st[],int i){
		int j,br=0;
		double p,s=0;
			for(j=0;j<st[i].br_ocjena;j++){
				s+=st[i].ocjene[j];
				br++;
				if(st[i].ocjene[j]==5) { s=5; br=1; break;}
			}
			p=s/br;
			return p;
	}
		int genijalci(struct Student st[100],int vel,double prosjek1) {
		int i,j,m,v;
		v=vel;
		for(i=0;i<v;i++){
		
			if(prosjek(st,i)<prosjek1) {
					for(j=i;j<v;j++){
						st[j]=st[j+1];
					}
				v--;
				i--;
			}
			
		}
		return v;
	}
	void ispisi_3(struct Student st[],int v,double prosjek1){
		int i,j,max,vel;
		double p;
		p=prosjek1;
		vel=v;
		struct Student tmp;
		for (i=0; i<v; i++) {
        max = i;
        for (j=i+1; j<v; j++)
            if (prosjek(st,j) > prosjek(st,max)) 
                max = j;

        tmp = st[i];
        st[i] = st[max];
        st[max] = tmp;
    }
    v=genijalci(st,vel,p);
    if(v==1)
    printf("%s %s\n",st[0].prezime,st[0].ime);
    else if(v==2){
    	printf("%s %s\n",st[0].prezime,st[0].ime);
    	printf("%s %s\n",st[1].prezime,st[1].ime);
    }
    else if(v>=3) {
    	printf("%s %s\n",st[0].prezime,st[0].ime);
    	printf("%s %s\n",st[1].prezime,st[1].ime);
    	printf("%s %s\n",st[2].prezime,st[2].ime);
    }
	}


	
int main() {
	struct Student st[100];
	int i,j,q,vel;
	double prosjek1;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		st[i]=unesi_studenta();
	}
	scanf("%lf",&prosjek1);
	
	ispisi_3(st,q,prosjek1);

	return 0;
}
