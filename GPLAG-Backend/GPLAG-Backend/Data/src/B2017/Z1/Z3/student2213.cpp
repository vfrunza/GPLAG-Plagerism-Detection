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

typedef std::vector<std::vector<int>> Matrica;
typedef std::deque<std::vector<int>> DekVektora;
enum Smjer{Rastuci = 1,Opadajuci = 2};

int BrojRedova(DekVektora m){
	return m.size();
}

int BrojKolona(DekVektora m){
	return m.at(0).size();
}

void IspisMatricu(DekVektora m){
	for(int i=0;i<BrojRedova(m);i++){
	
	if(m.at(i).size()!=0){		
		for(int j=0;j<m.at(i).size();j++){
			std::cout << m.at(i).at(j)<<" " ;
			}
		
		std::cout  << std::endl;
	
	}
	}
}

DekVektora RastuciPodnizovi(std::vector<int> poslani){
	DekVektora rezultantni;
	std::vector<int> pomocni;
	
	for (int i=0; i<poslani.size();i++) {
		if((i+1)<poslani.size() && (poslani.at(i)<poslani.at(i+1))){
			if(pomocni.size()==0){
				pomocni.push_back(poslani.at(i));
				pomocni.push_back(poslani.at(i+1));
			}
			
			else if(pomocni.size()!=0){
				pomocni.push_back(poslani.at(i+1));
			}
		}	
		else{
			rezultantni.push_back(pomocni);
			pomocni.clear();
		}
	}
	return rezultantni;
}

DekVektora OpadajuciPodnizovi(std::vector<int> poslani){
	DekVektora finalna;
	std::vector<int>temp;
	
	for(int i=0;i<poslani.size();i++){
		if((i+1)<poslani.size() && (poslani.at(i)>poslani.at(i+1))){
			if(temp.size()==0){
				temp.push_back(poslani.at(i));
				temp.push_back(poslani.at(i+1));
			}
			else if(temp.size()!=0){
				temp.push_back(poslani.at(i+1));
			}
		}
		else{
			finalna.push_back(temp);
			temp.clear();
		}
	}
	return finalna;
}

bool DaLiJeStepenDvojke(int broj){
	bool stepen=true;
	while (broj!=1 && stepen) {
		if(broj!=0 && broj%2==0){
		broj/=2;
		}
		else stepen=false;
	}
	return stepen;
}

DekVektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> uneseni, Smjer opcija){
	
	
	DekVektora povratni;
	DekVektora novi;
	std::vector<int>pomocni;
	bool da_li_je_prekinut = false;
	switch(opcija){
		case Rastuci:
		{
				povratni=RastuciPodnizovi(uneseni);
				
				for(int i=0;i<BrojRedova(povratni);i++){
					for(int j=0;j<povratni.at(i).size();j++){
						if(DaLiJeStepenDvojke(povratni.at(i).at(j)) && !da_li_je_prekinut){
							pomocni.push_back(povratni.at(i).at(j));
						}
						else {
							da_li_je_prekinut = true;
							continue;
						}
					}
					if(pomocni.size() > 1)
						novi.push_back(pomocni);
					pomocni.clear();
					da_li_je_prekinut = false;
				}
			
			break;
		}
	case Opadajuci:
	{
		povratni=OpadajuciPodnizovi(uneseni);
		for(int i=0;i<BrojRedova(povratni);i++){
			for(int j=0;j<povratni.at(i).size();j++){
				if(DaLiJeStepenDvojke(povratni.at(i).at(j)) && !da_li_je_prekinut){
					pomocni.push_back(povratni.at(i).at(j));
				}
				else {
					da_li_je_prekinut = true;
					continue;
				}
			}
			if(pomocni.size() > 1)
				novi.push_back(pomocni);
			pomocni.clear();
			da_li_je_prekinut = false;
		}
	break;
	}
	}
return novi;

}


int main ()
{	
	std::vector<int>uneseni;
	int broj_elemenata(0),broj;
	int opcija;
	Smjer enum_opcija;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < broj_elemenata; i++) {
		std::cin >> broj;
		uneseni.push_back(broj);
	}
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> opcija;
	if(opcija==1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else if(opcija == 2) std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	
	if(opcija==1) enum_opcija = Rastuci;
	else if(opcija==2) enum_opcija = Opadajuci;
	else std::cout<<"Nepravilna opcija";
	
	IspisMatricu(MaksimalniPodnizoviStepenaDvojke(uneseni,enum_opcija));
	
	
	
	return 0;
}