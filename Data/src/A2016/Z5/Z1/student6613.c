#include <stdio.h>
struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
void unesi(char niz[], int vel){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<=vel-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
struct Student unesi_osobu(){
	struct Student s;
	int i=0;
	unesi(s.ime,20);
	unesi(s.prezime,20);
	scanf("%d",&s.br_ocjena);
	for(i=0; i<s.br_ocjena; i++){
		scanf("%d", &s.ocjene[i]);
	}
	return s;
}
double fprosjek(struct Student s){
	double suma=0, brocjena,prosjek2;
	int j,r;
		
		brocjena=s.br_ocjena;
		if(brocjena==0) r=-1;
		else r=0;
		for(j=r; j<brocjena; j++){
			
			if(s.ocjene[j]==5 || j==-1){
				suma=5;
				brocjena=1;
				j=brocjena-1;
			} else{
				suma=suma+s.ocjene[j];
			}
			if(j==brocjena-1){
				prosjek2=(double)suma/brocjena;
			}
		}
		return prosjek2;
}
int poredjenje(struct Student o1, struct Student o2){
	int i=0,t=2;
	do{
		if(o1.prezime[i]<o2.prezime[i]) return -1;
		if(o2.prezime[i]<o1.prezime[i]) return 1;
		i++;
		if(o1.prezime[i]=='\0' && o2.prezime[i]!='\0') return -1;
		if(o1.prezime[i]!='\0' && o2.prezime[i]=='\0') return 1;
		if(o1.prezime[i]=='\0' && o2.prezime[i]=='\0') t=0;
	}while(o1.prezime[i]!='\0' && o2.prezime[i]!='\0');
	if(t==0){
		i=0;
		do{
			if(o1.ime[i]<o2.ime[i]) return -1;
			if(o2.ime[i]<o1.ime[i]) return 1;
			i++;
			if(o1.ime[i]=='\0' && o2.ime[i]!='\0') return -1;
			if(o1.ime[i]!='\0' && o2.ime[i]=='\0') return 1;
			if(o1.ime[i]=='\0' && o2.ime[i]=='\0') t=0;
		}while(o1.ime[i]!='\0' && o2.ime[i]!='\0');
	}
	if(t==0) return 0;
	
	return 0;
}
int genijalci(struct Student niz[], int n, double prosjek){
	int i, j, k, s, brocjena,r,t=0,br=0,brojac=0,m,z=-1,h,u=0,rporedjenja, istimaxi=0,isti=0, kolikoistih=0;;
	int maxi=-1,drugi,treci,maxi2;
	double prosjek2=0;
	double max1=prosjek,max2=prosjek,max3=prosjek, prosjeci;
	for(i=0; i<n; i++){
		s=0;
		brocjena=niz[i].br_ocjena;
		if(brocjena==0) r=-1;
		else r=0;
		for(j=r; j<brocjena; j++){
			
			if(niz[i].ocjene[j]==5 || j==-1){
				s=5;
				brocjena=1;
				j=brocjena-1;
			} else{
				s=s+niz[i].ocjene[j];
			}
			if(j==brocjena-1){
				prosjek2=(double)s/brocjena;
				if(prosjek2<prosjek){
					for(k=i; k<n-1; k++){
						niz[k]=niz[k+1];
					}
					n--;
					i--;
					continue;
				}
				else if(prosjek2>max1) max1=prosjek2;
				else if(prosjek2==prosjek) u=1;
				
			}
		}
	}
	if(u==0 && max1==prosjek) return n;
/*prvi maximum!!!*/
	for(i=0; i<n; i++){
		
		prosjek2=fprosjek(niz[i]);
		if(prosjek2==max1) br++;
		}
	if(br==2 || br==1){
	for(i=0; i<n; i++){
		prosjek2=fprosjek(niz[i]);
		if(prosjek2==max1){
		brojac++;
		if(brojac==1){
			if(br==1){
				printf("%s %s\n", niz[i].prezime, niz[i].ime);
			}
			else{
				maxi=i;
				i++;
				continue;
			}
		}
		else if(brojac==2){
			if(br==2){
				h=poredjenje(niz[maxi], niz[i]);
				if(h==-1){
					printf("%s %s\n", niz[maxi].prezime, niz[maxi].ime );
					printf("%s %s\n", niz[i].prezime, niz[i].ime);
					break;
				}
				else if(h==1){
					printf("%s %s\n", niz[i].prezime, niz[i].ime);
					printf("%s %s\n", niz[maxi].prezime, niz[maxi].ime );
					break;
				}
				else if(h==0){
					printf("%s %s\n", niz[i].prezime, niz[i].ime);
					printf("%s %s\n", niz[maxi].prezime, niz[maxi].ime );
					break;
				}
			}
		}
	}
	}
	}	
	else if(br>=3){
		for(i=0; i<n; i++){
			prosjek2=fprosjek(niz[i]);
			if(prosjek2==max1){
				for(j=i+1; j<n; j++){
					prosjeci=fprosjek(niz[j]);
					if(prosjeci==max1){
						rporedjenja=poredjenje(niz[i], niz[j]);
						if(rporedjenja==-1)
							maxi=i;
						else if(rporedjenja==1) 
							maxi=j;
						else if(rporedjenja==0){
							maxi=i;
							istimaxi=i;
						}
					}
				}
			}
		}
		for(i=0; i<n; i++){
			prosjek2=fprosjek(niz[i]);
			if(prosjek2==max1){
				isti=poredjenje(niz[i], niz[maxi]);
				if(isti==0) kolikoistih++;
				else continue;
			}
		}
		if(istimaxi==maxi && kolikoistih>=3){
			printf("%s %s\n", niz[maxi].prezime, niz[maxi].ime);
			printf("%s %s\n", niz[maxi].prezime, niz[maxi].ime);
			printf("%s %s\n", niz[maxi].prezime, niz[maxi].ime);
		}
		else if(istimaxi==maxi && kolikoistih==2){
			printf("%s %s\n", niz[maxi].prezime, niz[maxi].ime);
			printf("%s %s\n", niz[maxi].prezime, niz[maxi].ime);
		}
		else printf("%s %s\n", niz[maxi].prezime, niz[maxi].ime);
	}
	
	return n;
}
int main() {
	struct Student niz[100];
	int i,n,j;
	double prosjek;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		niz[i]=unesi_osobu();
		
	}
	scanf("%lf", &prosjek);
	n=genijalci(niz,n,prosjek);
	for(j=0;j<n; j++){
		printf("\n%s %s", niz[j].ime, niz[j].prezime);
	}
	return 0;
}
