#include <iostream>
#include <deque>
#include <vector>

enum Smjer {Rastuci,Opadajuci};
bool ProvjeraStepena (int value_2)
{
	//Funkcija za provjeru stepena
	if (value_2<0) return false;
	for (int i(1); i<=value_2; i*=2) {
		if (i==value_2) return true;
	}
	return false;
}
std::vector<int> CreateSubVector (std::vector<int> Vecc, int begin, int end)
{
	//Funkcija stvara subvektor rastucih/opadajucih vektora
  std::vector<int> SubVector;
	for (int i=begin; i<end; i++) {
		SubVector.push_back(Vecc.at(i));
	}
	return SubVector;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> Arr, enum Smjer parametar )
{
	int Bstop(0), Estop(0);
	std::deque<std::vector<int>> StoredV;
    //Na osnovu vrijednosti parametra odredi rastuce ili opadajuce nizove 
	if (parametar==0) {
		for (int i(0); i<Arr.size()-1; i++) {
			for (int j(i+1); j<Arr.size(); j++) {
				if (Arr.at(j-1)>Arr.at(j) || !(ProvjeraStepena(Arr.at(j))) || !(ProvjeraStepena(Arr.at(j-1))) ) {
					std::vector<int> SubVector(CreateSubVector(Arr, i, j));
					if (SubVector.size()>1)	StoredV.push_back(SubVector);
					i=j-1;
					break;

				} else if (j==Arr.size()-1) {
					std::vector<int> SubVector(CreateSubVector(Arr, i, j+1));
					if (SubVector.size()>1)	StoredV.push_back(SubVector);
					i=j-1;
					break;
				}
			}
		}
	} else if (parametar==1)  {
		for (int i(0); i<Arr.size()-1; i++) {
			for (int j(i+1); j<Arr.size(); j++) {
				if (Arr.at(j-1)<Arr.at(j) || !(ProvjeraStepena(Arr.at(j))) || !(ProvjeraStepena(Arr.at(j-1))) ) {
					std::vector<int> SubVector(CreateSubVector(Arr, i, j));
					if (SubVector.size()>1)	StoredV.push_back(SubVector);
					i=j-1;
					break;

				} else if (j==Arr.size()-1) {
					std::vector<int> SubVector(CreateSubVector(Arr, i, j+1));
					if (SubVector.size()>1)	StoredV.push_back(SubVector);
					i=j-1;
					break;
				}
			}
		}
	}
	return StoredV;
}

int main ()
{
	 std::vector<int> Veca;
	std::deque<std::vector<int>> VEC;
	int BrEl(0);
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>BrEl;
	std::cout<<"Unesite elemente vektora: ";
	for (int i(0); i<BrEl ; i++) {
		int broj;
		std::cin>>broj;
		Veca.push_back(broj);
	}
	int parametar;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>parametar;

	if (parametar==1) {
		VEC=MaksimalniPodnizoviStepenaDvojke ( Veca, Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi:  "<<std::endl;
	    
	}
	else if (parametar==2) {
		VEC=MaksimalniPodnizoviStepenaDvojke ( Veca, Opadajuci);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	for (int i(0); i<VEC.size(); i++) {
		for (int j(0); j<VEC.at(i).size(); j++) {
			std::cout<<VEC[i][j]<<" ";
		}
		std::cout<<std::endl;
	} 
   return 0; 
}



