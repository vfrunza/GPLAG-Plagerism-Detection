/*B 2017/2018, Zadaća 1, Zadatak 3
	
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
#include <deque>
#include <cmath>

	enum Smjer {Rastuci, Opadajuci};

bool Stependvojke(int broj) {

if(broj<1) return false;

while(broj!=1) {

if(broj%2!=0)return false;   //ako pri dijeljenju broja sa dva dodjemo do neparnog rezultata, osim =1, broj nije stepen dvojke
broj/=2;

}
return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> vektor, bool direction) {
int j=0;
std::deque<std::vector<int>> pomocni;
bool nasao=false;
if (direction==Rastuci) {
	
	for(int i=0;i<vektor.size();i++) {
	
	if(i<vektor.size()-1 && vektor[i]<=vektor.at(i+1) &&Stependvojke(vektor.at(i)) &&Stependvojke(vektor.at(i+1))  )  {
		
		pomocni.resize(pomocni.size()+1);
		if(j==0 && nasao==true)j++;          //j je inicijalno 0, pomocni vektor pise u 0-ti red. ako j=0 a desilo se prebacivanje u pomocni, j++  
		
	else if(j!=0)j++;   //ako je j bilo koji broj veci od 0, odmah j++
	nasao=true;  //sluzi samo za to da se upisuje u 0-ti red pomocnog, jer uradimo j++ na j=1 samo ako se vec desilo upisivanje u pomocni
	}
	while(i<vektor.size()-1 && vektor.at(i)<=vektor.at(i+1) &&Stependvojke(vektor.at(i)) &&Stependvojke(vektor.at(i+1))  ) {
	pomocni.at(j).push_back(vektor.at(i));
	i++;
	}          //petlja se zavrsava kada sljedeci clan ne zadovoljava uslove za prebacivanje, stoga moramo rucno prebaciti trenutni clan
	if(i>0 && vektor.at(i)>=vektor.at(i-1) && Stependvojke(vektor.at(i)) && Stependvojke(vektor.at(i-1))) pomocni.at(j).push_back(vektor.at(i));


	}
	
}


if (direction==Opadajuci) {    //potpuno analogno slucaju direction==Rastuci, samo obrnuti uslovi za poredjenje
	
	for(int i=0;i<vektor.size();i++) {
	
	if(i<vektor.size()-1 && vektor.at(i)>=vektor.at(i+1) &&Stependvojke(vektor.at(i)) &&Stependvojke(vektor.at(i+1)) ) {
		pomocni.resize(pomocni.size()+1);
		if(j==0 && nasao==true)j++;
		else if(j!=0)j++;
		nasao=true;
	}
	while(i<vektor.size()-1 && vektor.at(i)>=vektor.at(i+1) &&Stependvojke(vektor.at(i)) &&Stependvojke(vektor.at(i+1)) ) {
	
		
	pomocni.at(j).push_back(vektor.at(i));
	i++;
	}
	if(i>0 && vektor.at(i)<=vektor.at(i-1) && Stependvojke(vektor.at(i)) && Stependvojke(vektor.at(i-1))) pomocni.at(j).push_back(vektor.at(i));
 
	}
	
}


return pomocni;

}


int main ()
{
	
	
		std::vector<int >vektor;
		int n;
		std::cout<<"Unesite broj elemenata vektora: ";
		std::cin>>n;
		std::cout<<"Unesite elemente vektora: ";
		int broj;
for(int i=0;i<n;i++) {
	std::cin>>broj;
	vektor.push_back(broj);
}
std::deque<std::vector<int>> dekvektora;

std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>n;
	if(n==1) {
		dekvektora=MaksimalniPodnizoviStepenaDvojke(vektor,Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	if(n==2) {
	dekvektora=MaksimalniPodnizoviStepenaDvojke(vektor,Opadajuci);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	

for(auto a:dekvektora) {

	for(auto b:a) {
		std::cout<<b<<" ";
	}
std::cout<<std::endl;
}
	
	return 0;
}