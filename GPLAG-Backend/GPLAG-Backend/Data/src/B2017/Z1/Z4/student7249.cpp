#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string ObrniRijec(string rijec){
	string obrnuta;
	for(int i=rijec.size()-1; i>=0; i--){
		obrnuta.push_back(rijec.at(i));
	}
	return obrnuta;
}
string NapraviPalindrom(string recenica, vector<string> rijeci){
	for(int i=0; i<rijeci.size(); i++){
		int k=0, j=0;
		while(recenica.at(k)!=rijeci.at(i).at(j)){
			if(k==recenica.size()-1)break;
			k++;
			while(recenica.at(k)==rijeci.at(i).at(j)){
				if(j==rijeci.at(i).size()-1)break;
				k++;
				j++;
			}
			if(j==rijeci.at(i).size()-1){
					auto obrnuta=ObrniRijec(rijeci.at(i));
					for(int m=0; m<obrnuta.size(); m++){
						recenica.insert(recenica.begin()+k+1+m, obrnuta[m]);
						
					}
					j=0;
					k=k+obrnuta.size()+1;
					if(k>recenica.size()-1)break;
				}
				else{
					j=0; 
					continue;
				}
		}
			}
		return recenica;
	}

string ObrniPoluRijec(string rijec){
	string obrnuta;
	int l=rijec.size()/2;
	for(int i=0; i<rijec.size()-1; i++){
		if((rijec.at(i)=='n' || rijec.at(i)=='l') && rijec.at(i+1)=='j' && rijec.size()%2!=0){
			 l=rijec.size()/2;
			 break;
		}
		else l=rijec.size()/2 + 1;
	}
	if(rijec.size()%2==0)l=rijec.size()/2;
	for(int i=0; i<l; i++){
		obrnuta.push_back(rijec.at(i));
	}
	string poluobrnuta;
	for(int i=obrnuta.size()-1; i>=0; i--){
		poluobrnuta.push_back(obrnuta.at(i));
	}
	return poluobrnuta;
}

string NapraviPoluPalindrom(string recenica, vector<string> rijeci){
	
	for(int i=2; i<rijeci.size(); i++){
			int k=0, j=0;
			while(recenica.at(k)!=rijeci.at(i).at(j)){
				
				if(k==recenica.size()-1)break;
				k++;
				while(recenica.at(k)==rijeci.at(i).at(j)){
					if(j==rijeci.at(i).size() - 1){
						
						break;
					}
				
					k++;
					j++;
				}
				
				
				if(j==rijeci.at(i).size()-1){
						auto obrnuta=ObrniPoluRijec(rijeci.at(i));
						int l=obrnuta.size();
						if(rijeci.at(i).size()%2==0){
						for(int m=0; m<l; m++){
							recenica.at(k-l+m+1)=obrnuta.at(m);
						}
						k--;
						continue;
						}
						else{
							for(int m=0; m<l; m++){
							recenica.at(k-l+m)=obrnuta.at(m);
								}
						  }
						  
						/*
						if(rijeci.at(i).size()%2==0) {
							int l=rijeci.at(i).size();
							for(int m=0; m<l; m++){
								recenica.at(k-m)=recenica.at(k-l+m);
							}
							
						}
						else {
							int l=rijeci.at(i).size();
							for(int m=0; m<l; m++){
								recenica.at(k-m)=recenica.at(k-l+m);
		
							}
							
						}*/
						j=0;
						
						if(k>recenica.size()-1)break;
					}
					else{
						j=0; 
						continue;
					}
			}
				}
			return recenica;
	}
	
int main (){
	string recenica{"Izasla je prva zaddaz iz predmeta Tehnike prrp ekinheT, a ovih dana ocekujemo jos zaddaz iz drugih predmeta"};
	vector<string> rijec{"zadaca","Tehnike programiranja", "drugih predmeta", "meso od sira"};
	recenica=NapraviPoluPalindrom(recenica, rijec);
	for(auto x: recenica) cout << x;
	return 0;
}