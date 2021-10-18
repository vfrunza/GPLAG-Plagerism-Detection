#include <vector> 
#include <iostream>
#include <cmath>
#include <deque>

typedef std::deque<std::vector<int>> dek;

enum Smjer {Rastuci, Opadajuci};

bool DaLiJeStepen(int number){														//provjera da li je broj stepen dvojke
	int n(number);
	if(n<=0) return false;
	int counter(0);
	while(n!=1){
		n/=2;
		counter++;
	}
	if(number==std::pow(2, counter)) return true;
	else return false;
}
dek MaksimalniPodnizoviStepenaDvojke(std::vector<int> brojevi, Smjer smjer){    //kreiranje vektora samo od stepena dvojke
	dek povratni(0);
	int pocetak(0);					//dek u koji se smjestaju adekvatni vektori 
	std::vector<int> probni;
	probni=brojevi;
	if(smjer==Rastuci){
		std::vector<int> temporary(0);           			//privremeni vektor koji se smjesta u dek
		for(int i(0); i<probni.size(); i++){
			temporary.resize(0);                            //opet nam je potreban taj "premosni" vektor
			for(int j(pocetak); j<probni.size(); j++){
				if(DaLiJeStepen(probni.at(j))==false){
					pocetak++;
					break;
				}
				if((probni.size()-j)==1 && probni.at(j)>=probni.at(j-1)){                 //zadnji u vektoru
					temporary.push_back(probni.at(j));
					pocetak++;
					break;
				}
				if(DaLiJeStepen(probni.at(j))==true && probni.at(j)<=probni.at(j+1) && (probni.size()-j)!=1){
					temporary.push_back(probni.at(j));
					pocetak++;
					continue;
				}
				if(DaLiJeStepen(probni.at(j))==true && probni.at(j)>probni.at(j+1) && (probni.size()-j)!=1){   //slucajevi kad je trenutni veci od next u rastucem nizu
					temporary.push_back(probni.at(j));
					pocetak++;
					break;
				}
				else{
					pocetak++;
					continue;
				}
			}
			if(temporary.size()>=2) povratni.push_back(temporary);
		}
	}
	if(smjer==Opadajuci){
		std::vector<int> temporary(0);
		for(int i(0); i<probni.size(); i++){
			temporary.resize(0);
			for(int j(pocetak); j<probni.size(); j++){
				if(DaLiJeStepen(probni.at(j))==false){
					pocetak++;
					break;
				}
				if((probni.size()-j)==1 && probni.at(j)<=probni.at(j-1)){
					temporary.push_back(probni.at(j));
					pocetak++;
					break;
				}
				if(DaLiJeStepen(probni.at(j))==true && probni.at(j)>=probni.at(j+1) && (probni.size()-j)!=1){
					temporary.push_back(probni.at(j));
					pocetak++;
					continue;
				}
				if(DaLiJeStepen(probni.at(j))==true && probni.at(j)<probni.at(j+1) && (probni.size()-j)!=1){ //slucaj da nije po zakonu opadanja
					temporary.push_back(probni.at(j));
					pocetak++;
					break;
				}
				else pocetak++;
				continue;
			}
			if(temporary.size()>=2) povratni.push_back(temporary);
		}
	}
return povratni;
}		
int main (){
	int size;
	std::vector<int> input_vector(0);
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>size;
	std::cout<<"Unesite elemente vektora:";
	int x;
	for(int i(0); i<size; i++){
		std::cin>>x;
		input_vector.push_back(x);
	}
	int logic;
	std::cout<<" Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>logic;
	dek finalni;
	if(logic==1) finalni=MaksimalniPodnizoviStepenaDvojke(input_vector, Rastuci);
	else if(logic==2) finalni=MaksimalniPodnizoviStepenaDvojke(input_vector, Opadajuci);
	if(logic==1) std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	else if(logic==2) std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i(0); i<finalni.size(); i++){
			for(int j(0); j<(finalni.at(i)).size(); j++){
				std::cout<<finalni.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
		return 0;
	}
	
	
	