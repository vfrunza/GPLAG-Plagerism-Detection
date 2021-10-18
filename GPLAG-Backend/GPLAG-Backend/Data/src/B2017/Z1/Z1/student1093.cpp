#include <iostream>
#include <vector>
#include <string>
#include <cmath>

bool Prostbroj(long int n)
{
	if(n<=1) return false;
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0) return false;
	}
	return true;
}
std::vector<int> Vektori(std::vector<int>v, bool a)
{
	std::vector<int> vektorprostih;
	std::vector<int> vektorslozenih;
	for(int i=0; i<int(v.size()); i++) {
		if(v.at(i)==1) i++;
		if(v.at(i)<0) {
			long long int pomocni(v.at(i));
			pomocni=abs(pomocni);
			if(Prostbroj(pomocni)) vektorprostih.push_back(-pomocni);
			else vektorslozenih.push_back(-pomocni);
		}
		if(v.at(i)>0) {
			if (Prostbroj(v.at(i))) vektorprostih.push_back(v.at(i));
			else vektorslozenih.push_back(v.at(i));
		}
	}
	if(a) return vektorprostih;
	else return vektorslozenih;
}
std::string Pretvoribroj(int a)
{
	std::string broj;
	int ostatak=0;
	long long int n;
	n=abs(a);
	while(n!=0) {
		ostatak=n%3;
		broj.push_back(ostatak + '0');
		n=n/3;
	}
	return broj;
}
std::vector<std::string> PretvorbaUTernaranBroj(std::vector<int>v,bool a)
{
	std::vector<int>vektor;
	vektor=Vektori(v,a);
	std::vector<std::string>novivektor;
	for(int i=0; i<vektor.size(); i++) {
		novivektor.push_back(Pretvoribroj(vektor.at(i)));
	}
	return novivektor;
}
bool DaLiJeSimetrican(std::string n)
{
	std::string pomocni;
	for(int i=n.length()-1; i>=0; i--) {
		pomocni.push_back(n.at(i));
	}
	if(pomocni==n)return true;
	return false;
}
std::vector<int>IzdvojiSimetricneTernare(std::vector<int>v,bool a)
{
	std::vector<std::string> vektorternarnih;
	vektorternarnih=PretvorbaUTernaranBroj(v,a);
	std::vector<int> vektorintova;
	vektorintova = Vektori(v,a);
	std::vector<int>almostfinal;
	for(int i=0; i<vektorternarnih.size(); i++) {
		if(DaLiJeSimetrican(vektorternarnih.at(i))) almostfinal.push_back(vektorintova.at(i));
	}
	for(int i=0; i<almostfinal.size(); i++){
		for (int j=i+1; j<almostfinal.size(); j++){
			if(almostfinal.at(i)==almostfinal.at(j)){
				for(int k=j; k<almostfinal.size()-1; k++){
					almostfinal.at(k)=almostfinal.at(k+1);
				}
				j--;
				almostfinal.resize(almostfinal.size()-1);
			}
		}
	}
	return almostfinal;
}
void IspisElemenata(std::vector<int>v)
{
	for(int i=0; i<v.size(); i++) {
		if(i==v.size()-1) std::cout<<v.at(i)<<".";
		else std::cout<<v.at(i)<<", ";
	}
}
int main ()
{
	std::vector<int>v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int n;
	do {
		std::cin>>n;
		if(n!=-1) v.push_back(n);
	} while(n!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int a;
	do {
		std::cin>>a;
		if(a==1 || a==0) break;
		else
			std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while(a!=0 || a!=1);
	std::vector<int>vector;
	vector=IzdvojiSimetricneTernare(v,a);
	if(vector.size()==0) {
		if(a==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else if(a==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	} else {
		if(a==1) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else if(a==0) std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		IspisElemenata(vector);
	}
	return 0;
}