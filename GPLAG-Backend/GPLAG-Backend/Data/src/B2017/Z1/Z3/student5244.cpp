#include <iostream>
#include <vector>
#include <deque>
typedef std::vector<int> Vektor;
typedef std::deque<std::vector<int>> Dek;

enum Smjer {Rastuci=1,Opadajuci};

bool StepenDvojke(int n)
{
	if(n==0) return false;
	while(n!=1) {
		if(n%2!=0) return false;
		n=n/2;
	}
	return true;
}
Dek IzbaciIste(Dek d)
{
	for(int i=0; i<d.size(); i++) {
		for(int j=i+1; j<d.size(); j++) {
			if(d.at(i)==d.at(j)) {
				for(int k=j; k<d.size()-1; k++) {
					d.at(k)=d.at(k+1);
				}
				j--;
				d.resize(d.size()-1);
			}
		}
	}
	return d;
}
Dek MaksimalniPodnizoviStepenaDvojke(Vektor v,Smjer s)
{
	Dek d;
	if(s==1) {
		for(int i=0; i<v.size(); i++) {
			Vektor vek;
			if(i < v.size()-1 && v.at(i) <= v.at(i+1)) {
				while(i < v.size()-1 && v.at(i) <= v.at(i+1)) {
					vek.push_back(v.at(i));
					i++;
				}
				vek.push_back(v.at(i));
			}
			for(int j=0; j<vek.size(); j++) {
				if(!StepenDvojke(vek.at(j)) && j!=0) {
					vek.resize(j);
					break;
				} else if(!StepenDvojke(vek.at(j)) && j==0) {
					vek.erase(vek.begin());
					j--;
				}
				
			}
			
			if(vek.size()>1) {
				d.push_back(vek);
			}
		}
	} else {
		for(int i=0; i<v.size(); i++) {
			Vektor vek;
			if(i<v.size()-1 && v.at(i)>=v.at(i+1)) {
				while(i<v.size()-1 && v.at(i)>=v.at(i+1)) {
					vek.push_back(v.at(i));
					i++;
				}
				vek.push_back(v.at(i));
			}
			for(int j=0; j<vek.size(); j++) {
				if(!(StepenDvojke(vek.at(j))) && j != 0) {
					vek.resize(j);
					break;
				} else if(!(StepenDvojke(vek.at(j))) && j == 0) {
					vek.erase(vek.begin());
					j--;
				}
			}
			
			if(vek.size()>1) d.push_back(vek);
		}
	}
	d = IzbaciIste(d);
	return d;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	Vektor v;
	for(int i=0; i<n; i++) {
		int a;
		std::cin>>a;
		v.push_back(a);
	}
	Smjer s;
	int smjer;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>smjer; // recimo da će korisnik fakat unijeti ili 1 ili 2, sta ako ne unese
	s = static_cast<Smjer>(smjer);

	Dek d;
	d=MaksimalniPodnizoviStepenaDvojke(v,s);

	if(s == 1)
		std::cout << "Maksimalni rastuci podnizovi: "<<std::endl;
	else if(s == 2)
		std::cout << "Maksimalni opadajuci podnizovi: "<<std::endl;

	for(int i=0; i<d.size(); i++) {
		for(int j=0; j<d.at(i).size(); j++) {
			std::cout<<d.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}