/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/





//PROVJERIT ZA ENUM KAO PARAMETAR U FJI 
//ZA ATOVE STO MI PADAJU NA ZAMGERU PREPRAVIT linija 48 i 87
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
//Salje li se kao smjer ista osim 1 i 2 npr true i false kao u primjeru u postavci???
//JE LI POTREBNA SAD OVA DODJELA rastuci=1, opadajuci=2

enum Smjer {Rastuci, Opadajuci};
std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer niz){
	std::deque<std::vector<int>> dek;
	std::vector<int> red;
	//RASTUCI
	if(niz==Rastuci){
		int k;
		for(int i=1;i<v.size();i++){
			if(v.at(i-1)<=v.at(i) && i<v.size()){
			  while(i<v.size() && v.at(i-1)<=v.at(i)){
			  	if(v.at(i-1)>0 && v.at(i-1)%2==0 || v.at(i-1)==1){
			  		for(int s=0;s<=int(std::sqrt(v.at(i-1))+0.5);s++){
			  			if(pow(2,s)==v.at(i-1)){
			  				 red.push_back(v.at(i-1));
			  				 k=i-1;
			  				 break;
			  			}
			  			
			  		}
			    }
			  	
			  	i++;
			  }
			  
			    if(i-k-1==1 && v.at(i-1)>0 && v.at(i-1)%2==0 || v.at(i-1)==1){
			  		for(int s=0;s<=int(std::sqrt(v.at(i-1))+0.5);s++){
			  			if(pow(2,s)==v.at(i-1)){
			  				 red.push_back(v.at(i-1));
			  				 break;
			  			}
			  		}
			    }
			  
			  if(red.size()>1) dek.push_back(red);
			  i--;
			  
			}
			
			red.resize(0);
		}
	}


    //OPADAJUCI
	else if(niz==Opadajuci){
		int k;
		for(int i=1;i<v.size();i++){
			if(v.at(i-1)>=v.at(i) && i<v.size()){
			  while(i<v.size() && v.at(i-1)>=v.at(i)){
			  	if(v.at(i-1)>0 && v.at(i-1)%2==0 || v.at(i-1)==1){
			  		for(int s=0;s<=int(std::sqrt(v.at(i-1))+0.5);s++){
			  			if(pow(2,s)==v.at(i-1)){
			  				 red.push_back(v.at(i-1));
			  				 k=i-1;
			  				 break;
			  			}
			  			
			  		}
			    }
			  	
			  	i++;
			  }
			  
			    if(i-k-1==1 && v.at(i-1)>0 && v.at(i-1)%2==0 || v.at(i-1)==1){
			  		for(int s=0;s<=int(std::sqrt(v.at(i-1))+0.5);s++){
			  			if(pow(2,s)==v.at(i-1)){
			  				 red.push_back(v.at(i-1));
			  				 break;
			  			}
			  		}
			    }
			  
			  if(red.size()>1) dek.push_back(red);
			  i--;
			  
			}
			
			red.resize(0);
		}
	}
	return dek;
}


int main ()
{
	int n,a;
	std::vector<int> v;
	std::deque<std::vector<int>> d;
	int b;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>a;
		v.push_back(a);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>b;
	if(b==1){
	 d=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
	 std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else if(b==2) {
		d=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}

	for(int i=0;i<d.size();i++){
		for(int j=0;j<d.at(i).size();j++){
			std::cout<<d.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}