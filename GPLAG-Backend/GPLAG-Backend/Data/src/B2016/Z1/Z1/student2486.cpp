#include <iostream>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> PrebrojiCifre(int n)//funkcija koja pretvara broj u ternarni brojevni sistem
{
	vector <int> nekivektor;
	int brojac1(0),brojac2(0),brojac3(0);
	int ostatak;
	long long 	pomocni=1;
	long long	suma=0;
	long long	broj=n;
	while(broj!=0) {
		ostatak=broj%3;
		ostatak=abs((long long int)(ostatak));//za slucaj da je ostatak, negativan opet fja treba da radi 
		suma=suma+ostatak*pomocni;
		pomocni=pomocni*10;
		broj=broj/3;
		if(ostatak==1)brojac2++;//brojaci broje broj 0,1,2 odmah cim rastavimo cifru broja
		else if(ostatak==2)brojac3++;
		else if(ostatak==0)brojac1++;
	}

	nekivektor.push_back(brojac1);
	nekivektor.push_back(brojac2);
	nekivektor.push_back(brojac3);//napravili smo vektor od tri elementa koji sadrzi brojace koji predstavljaju broj nula jedinica i dvica te ih vracamo u fju

	return nekivektor;


}

vector <int> IzdvojiGadne(vector <int> niz, bool a)
{
	vector <int> niz2;


	for(int i {}; i<niz.size(); i++) {
		for(int j {i+1}; j<niz.size(); j++) {
			if(niz.at(i)==niz.at(j)) {
				niz.erase(niz.begin()+ j--);//izbacivanje duplih clanova iz niza pomocu begin i erase
			}
		}
	}


	if(a==true) {
		for(int i=0; i<niz.size(); i++) {
			vector <int> brojaci;
			brojaci=PrebrojiCifre(niz[i]);
			if(brojaci[0]%2==0 && brojaci[1]%2==0 && brojaci[2]%2==0) {//uvjet samo ako je broj sve tri cifre u broju paran
				niz2.push_back(niz.at(i));
			}
		}
		return niz2;
	} else {
		for(int i=0; i<niz.size(); i++) {
			if(niz.at(i)==1 || niz.at(i)==2 ) {
				niz2.push_back(niz.at(i));
				continue;
			}
			vector <int> brojaci;
			brojaci=PrebrojiCifre(niz[i]);
			if(brojaci[0]%2!=0 && brojaci[1]%2!=0 && brojaci[2]%2!=0) {
				niz2.push_back(niz.at(i));
			} else if(brojaci[0]%2!=0 && brojaci[1]%2!=0 && brojaci[2]==0) {//imamo vise uvjeta u slucaju neparnih brojeva zbog slucaja da se ukoliko nula cifara ima racuna kao parni
				niz2.push_back(niz.at(i));
			} else if(brojaci[0]%2!=0 && brojaci[1]==0 && brojaci[2]%2!=0) {
				niz2.push_back(niz.at(i));
			} else if(brojaci[0]==0 && brojaci[1]%2!=0 && brojaci[2]%2!=0) {
				niz2.push_back(niz.at(i));
			}
			else if(brojaci[0]==0 && brojaci[1]%2!=0 && brojaci[2]==0){
				niz2.push_back(niz.at(i));
			}
		
		}
		return niz2;
	}
}

int main()
{
	vector <int> n;
	int a;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		cin>>a;
		if(a!=0) {
			n.push_back(a);
		}
		
//unos elemenata
	} while(a!=0);

	vector <int> n2,n1;
	bool isti=false;
	n2=IzdvojiGadne(n,true);
	n1=IzdvojiGadne(n,false);
	cout<<"Opaki: ";
	for(int i=0; i<n2.size(); i++) {
		cout<<n2.at(i)<<" ";
	}
	cout<<endl;
	cout<<"Odvratni: ";
	for(int i=0; i<n1.size(); i++) {
		cout<<n1.at(i)<<" ";
	}
//ispis elemenata


	return 0;
}