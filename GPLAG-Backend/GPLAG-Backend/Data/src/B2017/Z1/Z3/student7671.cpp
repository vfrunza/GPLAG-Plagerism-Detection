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

enum smjer {rastuci=0, opadajuci=1};

bool DaLiJeStepenDvojke (int broj){
	if(broj%2==0)
		return true;
	else
		return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, smjer n){
	std::deque<std::vector<int>> dek;
	std::vector<int> pomocni;
	int red(0), kolona(0);
	 if(n==rastuci){
	 	for(int i=0; i<v.size(); i++){
	 		for(int j=i+1; j<v.size(); j++){
	 			int zapamti(j);
	 			while(DaLiJeStepenDvojke(v.at(j))==true && DaLiJeStepenDvojke(j-1)==true && v.at(j)>v.at(j-1)){
	 				j++;
	 			}
	 			if(zapamti<j){
	 				int k;
	 				kolona=0;
	 				for(k=i; k<j; k++){
	 					pomocni.at(kolona)=v.at(k);
	 					kolona++;
	 				} 
	 				i=k;
	 				for(int z=0; z<kolona; z++)
	 					dek.at(red).at(z)=pomocni.at(k);
	 				red++;
	 			}
	 			break;
	 		}
	 	}
	 }
	 else if (n==opadajuci){
	 	for(int i=0; i<v.size(); i++){
	 		for(int j=i+1; j<v.size(); j++){
	 			int zapamti(j);
	 			while(DaLiJeStepenDvojke(v.at(j))==true && DaLiJeStepenDvojke(j-1)==true && v.at(j)>v.at(j-1)){
	 				j++;
	 			}
	 			if(zapamti<j){
	 				int k;
	 				for(k=i; k<j; k++){
	 					dek.at(red).at(kolona)=v.at(k);
	 					kolona++;
	 				}
	 				i=k;
	 				red++;
	 			}
	 			break;
	 		}
	 	}
	 }
	 return dek;
}

int main (){
	std::vector<int> v {1,4,3,4,3,2,16,10,4,8,4,2,1,2,1,7};
	std::deque<std::vector<int>> dek;
	dek=MaksimalniPodnizoviStepenaDvojke(v,rastuci);
	for(int i=0; i<dek.size(); i++){
		for(int j=0; j<dek.at(i).size(); j++){
			std::cout << dek.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}