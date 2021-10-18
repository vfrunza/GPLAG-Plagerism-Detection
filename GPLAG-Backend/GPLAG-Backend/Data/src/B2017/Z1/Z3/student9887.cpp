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
#include <deque>
#include <vector>
enum Smjer{Rastuci=1 , Opadajuci=2};

typedef std::deque<std::vector<int>> matrica;
typedef std::vector<int> VEKTOR;
bool StepenDvojke(int broj){
	int i;
	for( i=1;i<broj;i*=2);
	if(i==broj)
	return true;
	return false;
}


matrica MaksimalniPodnizoviStepenaDvojke(VEKTOR v , Smjer s){
matrica M;


 
 if(s==1){
 	for(int i=0;i<v.size()-1;i++){
 		VEKTOR pomocni;
 		if(StepenDvojke(v.at(i))){
 			while(StepenDvojke(v.at(i)) && i!=v.size()-1){
 				if((v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i+1))) || (i!=0 && v.at(i)>=v.at(i-1) && StepenDvojke(v.at(i-1))))
 				pomocni.push_back(v.at(i));
 				if((i!=0 && v.at(i)>=v.at(i-1) && StepenDvojke(v.at(i-1))) && StepenDvojke(v.at(i+1)) && !(v.at(i)<=v.at(i+1))){
 					if(pomocni.size()>1)
 				M.push_back(pomocni);
 					pomocni.resize(0);
 				}
 				i++;
 			}
 		}
 		if(i==(v.size()-1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i-1)) && v.at(i)>=v.at(i-1))
 		pomocni.push_back(v.at(i));
 		if(pomocni.size()>1)
 		M.push_back(pomocni);
 	}
 	
 }
 if(s==2){
 	for(int i=0;i<v.size()-1;i++){
 		VEKTOR pomocni;
 		if(StepenDvojke(v.at(i))==true && i!=v.size()-1){
 			while(StepenDvojke(v.at(i))==true && i!=v.size()-1){
 				if((v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i+1))) || (i!=0 && v.at(i)<=v.at(i-1) && StepenDvojke(v.at(i))))
 				pomocni.push_back(v.at(i));
 				if((i!=0 && v.at(i)<=v.at(i-1) && StepenDvojke(v.at(i))) && StepenDvojke(v.at(i+1)) && !(v.at(i)>=v.at(i+1)) ){
 					if(pomocni.size()>1)
 					M.push_back(pomocni);
 					pomocni.resize(0);
 				}
 				i++;
 			}
 		}
 		if(i==(v.size()-1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i-1)) && v.at(i)<=v.at(i-1))
 		pomocni.push_back(v.at(i));
 		if(pomocni.size()>1)
 		M.push_back(pomocni);
 	}
 	
 }
 	
 return M;
 
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;

	std::cout<<"Unesite elemente vektora: ";
		std::vector<int> v(n);
	for(int i=0;i<n;i++){
		std::cin>>v.at(i);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int s;
	std::cin>>s;
	
	matrica M=MaksimalniPodnizoviStepenaDvojke(v, Smjer(s));
	if(s==1 && M.size()!=0){
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		for(int i=0;i<M.size();i++){
			for(int j=0;j<M.at(i).size();j++){
			std::cout<<M.at(i).at(j)<<" ";}
			std::cout<<std::endl;
		}
		
	}
	if(s==1 && M.size()==0)
	std::cout<<"Nema maksimalno rastucih nizova! ";
	if(s==2 && M.size()!=0){
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		for(int i=0;i<M.size();i++){
			for(int j=0;j<M.at(i).size();j++){
			std::cout<<M.at(i).at(j)<<" ";
			
		}
		std::cout<<std::endl;
	}}
	if(s==2 && M.size()==0){
	std::cout<<"Nema maksimalno opadajucih nizova! ";}
	return 0;
}