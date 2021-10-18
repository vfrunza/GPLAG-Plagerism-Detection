#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::cin;
using std::vector;

bool DaLiJeProst(int n)
{ if(n<0)
		n*=-1;
		if(n==0)
		return false;
	for(int i=2; i<=int(std::sqrt(n)); i++) {

		if(n%i==0 )
			return false;

	}
	return true;

}
vector<int> IzdvojiSimetricneTernarne(vector<int> vektor,bool a)
{
		
	for(int i=0;i<vektor.size();i++){
		for(int j=i+1;j<int(vektor.size());j++){
			int kontrola (1);
		if(vektor.at(i)==vektor.at(j)){
			kontrola=0;
				vektor.erase(vektor.begin() +j);
		}
		if(kontrola==0)
		j--;
	
}
		}
	
	
		vector<int>privremeni;
		vector<int>privremeni2;

	for(int i=0; i<int(vektor.size()); i++) {
		int brojac(0);
		if(DaLiJeProst(vektor.at(i))==a && vektor.at(i)!=1 ) {
			privremeni2.push_back(vektor.at(i));
			for(int j=3; j<=vektor.at(i); j*=3)
				brojac++;
				
			int novibroj(0);
            int something;
            something=vektor.at(i);
			for(int k=brojac; k>=0; k--) {
				if((2* pow(3,k))<= something) {
					novibroj=novibroj*10+2;
					something=something-(2* pow(3,k));

					continue;

				}
				if((1* pow(3,k))<= something) {
					novibroj=novibroj*10+1;
					something=something-(1* pow(3,k));

					continue;

				}
				if((0* pow(3,k))<= something) {
					novibroj=novibroj*10+0;
				something=something-(0* pow(3,k));

					continue;

				}

			}

	
			privremeni.push_back(novibroj);

}
		
	}
			vector<int> rezultat;

		for(int i=0; i<privremeni.size(); i++) {
			vector<int> v(0);
			while(privremeni.at(i)!=0) {
				int cifra;
				cifra=privremeni.at(i)%10;

				v.push_back(cifra);
				privremeni.at(i)/=10;

			}
		
			int nesto;
			nesto=int(v.size())-1;
			int istina(1);
			for(int j=0; j<int(v.size()); j++) {
				if(v.at(j)!=v.at(nesto)) {
					istina=0;
					break;
				}
				if(j==nesto)
				break;
				nesto--;
			}
		
			if(istina) {
				rezultat.push_back(privremeni2.at(i));

			}


		}

	return rezultat;
}
int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	vector<int> brojevi;
	int broj;
		int l(-1);
		
	while(1) {
		cin>>broj;
		
		if(broj==l)
			break;
			brojevi.push_back(broj);
	}
int a;
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(true) {
		
		cin>>a;
		if(a==0 || a==1)
			break;
		else
			cout<<"Neispravan unos! Unesite ponovo: ";
	}
	bool varijabla(true);
	if(a==0)
varijabla=false;

	

		
	 
	//izbrisat one koji se ponavljaju


vector<int>	d=IzdvojiSimetricneTernarne(brojevi,varijabla);
	
	if(d.size()>0){
		if(a==1)
		cout<<"Prosti simetricni brojevi iz vektora su: ";
		else
		cout<<"Slozeni simetricni brojevi iz vektora su: ";
	
		for(int i=0; i<d.size(); i++) {
			if(i==d.size()-1)
				cout<<d.at(i)<<"."<<std::endl;
			else
				cout<<d.at(i)<<", ";
		}
}	else {
		if(a==0)
			cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else
			cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	return 0;
}