
#include <iostream>
#include <vector>
#include <deque>

typedef std::vector<int> Vektor;
enum Smjer { Rastuci=1, Opadajuci};

bool SDvojke(int a){
	if(a<1) return false;
	if(a==1) return true;
	else{
		while(a>=2){
			if(a%2!=0) return false;
			if(a==2) return true;
			a=a/2;
			if(a==2) return true;
		}
	}
		return false;
}
std::deque<Vektor> MaksimalniPodnizoviStepenaDvojke (Vektor v, Smjer l){
	std::deque<Vektor> dek;
	Vektor pomocni;
	int brojac=0;
	if(v.size()==0) return dek;
	if(l==Rastuci){
		for(int i=0; i<v.size(); i++){
			if(SDvojke(v.at(i))==true){
				if(i==v.size()-1){
					if(pomocni.size()>1){
						pomocni.push_back(v.at(i));
						brojac++;
						dek.resize(brojac);
						dek.at(brojac-1)=pomocni;
					}
				}
				else{
					pomocni.push_back(v.at(i));
					if(v.at(i)>v.at(i+1)){
						if(pomocni.size()>1){
							brojac++;
							dek.resize(brojac);
							dek.at(brojac-1)=pomocni;
							pomocni.resize(0);
						}
						else pomocni.resize(0);
					}
					
				}
			}
			else{
				if(pomocni.size()>1){
					brojac++;
					dek.resize(brojac);
					dek.at(brojac-1)=pomocni;
					pomocni.resize(0);
				}
				else pomocni.resize(0);
			}
		}
	}
	else{
		for(int i=0; i<v.size(); i++){
			if(SDvojke(v.at(i))==true){
				if(i==v.size()-1){
					if(v.at(i)<v.at(i-1) && pomocni.size()!=0){
						pomocni.push_back(v.at(i));
						brojac++;
						dek.resize(brojac);
						dek.at(brojac-1)=pomocni;
						pomocni.resize(0);
					}
					if(pomocni.size()>1){
						pomocni.push_back(v.at(i));
						brojac++;
						dek.resize(brojac);
						dek.at(brojac-1)==pomocni;
					}
				}
				else{
					pomocni.push_back(v.at(i));
					if(v.at(i)<v.at(i+1)){
						if(pomocni.size()>1){
							brojac++;
							dek.resize(brojac);
							dek.at(brojac-1)=pomocni;
							pomocni.resize(0);
						}
						else pomocni.resize(0);
					}
				}
			}
			else{
				if(pomocni.size()>1){
					brojac++;
					dek.resize(brojac);
					dek.at(brojac-1)=pomocni;
					pomocni.resize(0);
				}
				else pomocni.resize(0);
			}
		}
	}
	return dek;
}

int main ()
{
	std::deque<Vektor> dek;
	Vektor pomocni;
	int n;
	int b;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin>>b;
		pomocni.push_back(b);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int y;
	std::cin>>y;
	if(y==1){ 
		dek=MaksimalniPodnizoviStepenaDvojke(pomocni, Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else{ 
		dek=MaksimalniPodnizoviStepenaDvojke(pomocni, Opadajuci);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	for(auto a: dek){
		for(int x: a) std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	return 0;
}