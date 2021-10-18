/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

int GadnostBrojaDecimaly (int n){
	
	std::vector<int> ponavljanja{0, 0, 0};
	while(n){
		ponavljanja.at(abs(n%3))++;
		n/=3;
	}
	if((ponavljanja.at(0)%2==0 || ponavljanja.at(0)==0) && (ponavljanja.at(1)%2==0 || ponavljanja.at(1)==0) && (ponavljanja.at(2)%2==0 || ponavljanja.at(2)==0)) return 1;
	else if((ponavljanja.at(0)%2!=0 || ponavljanja.at(0)==0) && (ponavljanja.at(1)%2!=0 || ponavljanja.at(1)==0) && (ponavljanja.at(2)%2!=0 || ponavljanja.at(2)==0)) return 0;
	else return -1;	
}

std::vector<int> IzdvojiGadne (std::vector<int> vektor_brojeva, bool logic){							//Funkcija uz ostale pomocne funkcije vraca vektor sa opakim, ili odvratnim brojevima,
	std::vector<int> povratni_vektor;
	bool ponavlja_se(false);
	for(int i=0; i<vektor_brojeva.size(); i++){
		ponavlja_se = false;																			//Prvo se provjerava da li se broj vec nalazi u vektoru, nakon cega poziva ostale dvije funkcije
		for(int j=0; j<i; j++)																			//uz pomoc kojih puni vektor odgovarajucim elementima
			if(vektor_brojeva.at(j) == vektor_brojeva.at(i)) ponavlja_se = true;
		if(ponavlja_se) continue;
		if(logic){
			if(GadnostBrojaDecimaly(vektor_brojeva.at(i))==1) povratni_vektor.push_back(vektor_brojeva.at(i));
		}else{
			if(GadnostBrojaDecimaly(vektor_brojeva.at(i))==0) povratni_vektor.push_back(vektor_brojeva.at(i));
		}
	}
	return povratni_vektor;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> brojevi;
	int temp(1);
	bool first(1);
	while(temp!=0) {
		std::cin >> temp;
		if(temp!=0) {brojevi.push_back(temp); if(first) first=0;}
		else if(first) {brojevi.push_back(temp); first=0; temp=1;}
		else break;
	}
	std::cout << "Opaki: ";
	std::vector<int> opaki(IzdvojiGadne(brojevi, true));
	for(int x: opaki) std::cout << x<< " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	std::vector<int> gadni(IzdvojiGadne(brojevi, false));
	for(int x: gadni) std::cout << x<< " ";
	std::cout << std::endl;
	return 0;
}