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

enum Smjer{Rastuci = 1, Opadajuci};
bool DaLiJeStepenDvojke(int n){
	if(n<=0) return false;
	int ostatak(0);
	while(n!=0){
		ostatak=ostatak+n%2;
		n=n/2;
	} // Ukupan ostatak pri djeljenju sa 2, nekog broja, koji je stepen dvojke ce uvijek biti = 1
	if(ostatak==1) return true;
	else return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> a, Smjer birani_smjer){
	std::deque<std::vector<int>> krajnji;
	std::vector<int> pomocni;
	if(birani_smjer==Smjer::Rastuci){
		for(int i(0); i<a.size(); i++){ // Specifican mehanizam za odredjivanje rastuceg podniza datog niza, pri cemu vodimo racuna o prvom i posljednjem clanu niza
			if((i==0) && (DaLiJeStepenDvojke(a.at(i))) && (DaLiJeStepenDvojke(a.at(i+1))) && (a.at(i)<=a.at(i+1))) pomocni.push_back(a.at(i));
			else if((i==a.size()-1) && (DaLiJeStepenDvojke(a.at(i))) && (DaLiJeStepenDvojke(a.at(i-1))) && (a.at(i)>=a.at(i-1))){
				pomocni.push_back(a.at(i));
				krajnji.push_back(pomocni);
			}
			else if((DaLiJeStepenDvojke(a.at(i))) && (DaLiJeStepenDvojke(a.at(i-1))) && (a.at(i)>=a.at(i-1)) && (i!=0)) pomocni.push_back(a.at(i));
			else{
				if(pomocni.size()>1){
					krajnji.push_back(pomocni);
					pomocni.resize(0);
				}
				if((i!=a.size()-1) && (DaLiJeStepenDvojke(a.at(i))) && (DaLiJeStepenDvojke(a.at(i+1))) && (a.at(i+1)>=a.at(i))) pomocni.push_back(a.at(i));
			}
		}
	}
	else if(birani_smjer==Smjer::Opadajuci){
		for(int i(0); i<a.size(); i++){ // Specifican mehanizam za odredjivanje opadajuceg podniza datog niza, pri cemu vodimo racuna o prvom i posljednjem clanu niza
			if((i==0) && (DaLiJeStepenDvojke(a.at(i))) && (DaLiJeStepenDvojke(a.at(i+1))) && (a.at(i)>=a.at(i+1))) pomocni.push_back(a.at(i));
			else if((i==a.size()-1) && (DaLiJeStepenDvojke(a.at(i))) && (DaLiJeStepenDvojke(a.at(i-1))) && (a.at(i)<=a.at(i-1))){
				pomocni.push_back(a.at(i));
				krajnji.push_back(pomocni);
			}
			else if((i!=a.size()-1) && (DaLiJeStepenDvojke(a.at(i))) && (DaLiJeStepenDvojke(a.at(i+1))) && (a.at(i)>=a.at(i+1))) pomocni.push_back(a.at(i));
			else{
				if((i!=0) && (DaLiJeStepenDvojke(a.at(i))) && (DaLiJeStepenDvojke(a.at(i-1))) && (a.at(i-1)>=a.at(i))) pomocni.push_back(a.at(i));
				if(pomocni.size()>1){
					krajnji.push_back(pomocni);
					pomocni.resize(0);
				}
			}
		}
	}
	return krajnji;
}
int main ()
{
	int n,l;
	Smjer birani_smjer;
	std::vector<int> a;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>> n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i<n; i++){
		int k;
		std::cin>>k;
		a.push_back(k);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>> l;
	birani_smjer=Smjer(l);
	std::deque<std::vector<int>> Konacni_dek_vektora;
	if(birani_smjer==Rastuci){
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		Konacni_dek_vektora=MaksimalniPodnizoviStepenaDvojke(a,birani_smjer);
		for(int i(0); i<Konacni_dek_vektora.size(); i++){
			for(int j(0); j<Konacni_dek_vektora.at(i).size(); j++)
				std::cout<<Konacni_dek_vektora.at(i).at(j)<<" ";
				std::cout<<"\n";
		}
	}
	else if(birani_smjer==Opadajuci){
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		Konacni_dek_vektora=MaksimalniPodnizoviStepenaDvojke(a,birani_smjer);
		for(int i(0); i<Konacni_dek_vektora.size(); i++){
			for(int j(0); j<Konacni_dek_vektora.at(i).size(); j++)
				std::cout<<Konacni_dek_vektora.at(i).at(j)<<" ";
				std::cout<<"\n";
		}
	}
	return 0;
}