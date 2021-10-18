#include <iostream>
#include <vector>

std::vector<int> OdrediCifre(int n){
	std::vector<int> v1(3),cifre;
	while(true){
		cifre.push_back(std::abs(n%3));
		n /= 3;
		if(n == 0) break;
	}
	for(auto x : cifre) v1.at(x)++;
	return v1;
}


bool DaLiJeOpaki (int n){
	bool rezultat(true);
	std::vector<int> v1(OdrediCifre(n));
	for(auto x : v1){
		if(x>0 && x%2!=0) {
			rezultat = false;
			break;
		}
	}
	return rezultat;
}

bool DaLiJeOdvratni (int n){
	bool rezultat(true);
	std::vector<int> v1(OdrediCifre(n));
	for(auto x : v1){
		if(x>0 && x%2==0) {
			rezultat = false;
			break;
		}
	}
	return rezultat;
}

std::vector<int> IzdvojiGadne(std::vector<int> v , bool f){
	std::vector<int> rez;
	bool uslov;
	if(f){
		for(int i = 0; i < v.size(); i++){
			if(DaLiJeOpaki(v.at(i))) {
				uslov = false;
				for(auto x : rez) if(x == v.at(i)) {
					uslov = true;
					break;
				}
				if(!uslov) rez.push_back(v.at(i));
			}
		}
	}
	else{
		for(int i = 0; i < v.size(); i++){
			if(DaLiJeOdvratni(v.at(i))) {
				uslov = false;
				for(auto x : rez) if(x == v.at(i)) {
					uslov = true;
					break;
				}
				if(!uslov) rez.push_back(v.at(i));
			}
		}
	}
	return rez;
}

int main ()
{
	std::vector<int> v;
	int x;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	while(true){
		std::cin >> x;
		if(x == 0) break;
		v.push_back(x);
	}
	std::vector<int> v1;
	v1 = IzdvojiGadne(v,true);
	std::cout << "Opaki: ";
	for(auto x : v1) std::cout << x << " ";
	std::vector<int> v2;
	v2 = IzdvojiGadne(v,false);
	std::cout << std::endl << "Odvratni: ";
	for(auto x : v2) std::cout << x << " ";
	return 0;
}