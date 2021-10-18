/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>

bool SimetricniTernarni(int b){
	int c;
	std::vector<int>m, p;
	while(b!=0){
		c=abs(b%3);
		m.push_back(c);
		b/=3;
	}
	for(int i=m.size()-1; i>=0; i--)
	p.push_back(m.at(i));
	int d(1);
	for(int i=0; i<m.size(); i++){
		if(m.at(i)!=p.at(i)){
			d=0;
			break;
		}
	}
	if(d==0) return false;
	return true;
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v, bool a){
	std::vector<int>v4;
	for(int i=0; i<v.size()-1; i++){ //Brisanje duplih
		for(int j=i+1; j<v.size(); j++)
		{
			if(v.at(j)==v.at(i)){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	for(int i=0; i<v.size(); i++) 
	{
	
		if(v.at(i)==1){
		v.erase(v.begin()+i);
		i--;}
	}
	for(int j=0; j<v.size(); j++){
		int s(0);
		if(v.at(j)%2==0&&v.at(j)!=2)
		s=1;
		else{
		for(int k=3; k<=sqrt(v.at(j)); k++){
			if(v.at(j)%k==0)
			{
				s++;
				break;
			}
		}}
		if(s==0&&a==true&&SimetricniTernarni(v.at(j)))
		v4.push_back(v.at(j));
		if(s!=0&&a==false&&SimetricniTernarni(v.at(j)))
		v4.push_back(v.at(j));
		}
	return v4;
}


int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	int broj;
	do{
		std::cin>>broj;
		if(broj!=-1)
		v.push_back(broj);
	}while(broj!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int d;
	bool a;
	while(1){
		std::cin>>d;
		if(d==0||d==1){
			a=d;
			break;
		}
		else
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	auto v1(IzdvojiSimetricneTernarne(v, a));
	int i;
	if(a==1&&v1.size()>0){
	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(i=0; i<v1.size()-1; i++)
	std::cout<<v1.at(i)<<", ";
	std::cout<<v1.at(i)<<".";}
	else if(a==0&&v1.size()>0){
	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(i=0; i<v1.size()-1; i++)
	std::cout<<v1.at(i)<<", ";
	std::cout<<v1.at(i)<<".";}
	else if(a==1&&v1.size()==0)
	std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else
	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	return 0;
}