#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

typedef std::vector<int> vector;
enum Smjer {Opadajuci = 2, Rastuci = 1};

bool StepenDva(int num){
	if(num <= 0) return false;
	
	int i = 1;
	while(true){
		if(i > num) return false;
		if(i == num) break;
		i *= 2;
	}
	
	return true;
}

std::deque<vector> MaksimalniPodnizoviStepenaDvojke(vector v, Smjer s){
	std::deque<vector> toRet;
	unsigned int vSize = v.size();
	
	if(vSize <= 1) return toRet;
	
	vector temp;
	if(StepenDva(v.at(0)))
		temp.push_back(v.at(0));
	
	if(s == Smjer::Opadajuci){
		for(int i = 1; i < vSize; i++){
			//Dok je niz rastuci/opadajuci, dodaji elemente u temp ako je element stepen dvojke
			if(StepenDva(v.at(i)) && (v.at(i) <= v.at(i-1))){
					temp.push_back(v.at(i));
			}else{
				//Kada niz vise nije rastuci, dodaj rastuci u deque, pod uslovom da je duzi od jedan
				if(temp.size() >= 2)
					toRet.push_back(temp);
				//Ocisti temp
				temp.clear();
				//I dodaj trenutni clan
				if(StepenDva(v.at(i)))
					temp.push_back(v.at(i));
			}
		}
	}else{
		for(int i = 1; i < vSize; i++){
			//Dok je niz rastuci/opadajuci, dodaji elemente u temp ako je element stepen dvojke
			if(StepenDva(v.at(i)) && (v.at(i) >= v.at(i-1))){
					temp.push_back(v.at(i));
			}else{
				//Kada niz vise nije rastuci, dodaj rastuci u deque, pod uslovom da je duzi od jedan
				if(temp.size() >= 2)
					toRet.push_back(temp);
				//Ocisti temp
				temp.clear();
				//I dodaj trenutni clan
				if(StepenDva(v.at(i)))
					temp.push_back(v.at(i));
			}
		}
	}
	
	//Posljednji podniz
	if(temp.size() >= 2)
		toRet.push_back(temp);
	
	return toRet;
}

int main ()
{
	
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	vector v(n);
	std::deque<vector> deq;
	
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < n; i++){
		std::cin >> v.at(i);
	}
	
	int monot;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> monot;
	
	std::cout << "Maksimalni " << ((monot == 1)? "rastuci" : "opadajuci") << " podnizovi: \n";
	deq = MaksimalniPodnizoviStepenaDvojke(v, static_cast<Smjer>(monot));
	
	for(vector vec : deq){
		for(int i : vec)
			std::cout << i << " ";
		std::cout << std::endl;
	}
	
	return 0;
}