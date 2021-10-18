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
#include <iomanip>
enum Smjer {Rastuci, Opadajuci};
Smjer Tok;

bool DaLiJeStepenDvojke (int n)
{
	int nije(0);
	if(n<=0) return false;
	for (int i=1; i<=n; i*=2) {
		if(n%i!=0) nije++;
		else nije=0;
	}
	if(nije>0) {
		return false; 
		
	}
	else if(nije==0) return true;
}

std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke( std::vector<int>v, Smjer Tok )
{
	int j(0),brojac_r(0),brojac_o(0);
	std::vector<int>opadajuci,rastuci,brojaci_r,brojaci_o;
	std::deque<std::vector<int>> rastuci_n,opadajuci_n;
	for(int i=0; i<v.size(); i++) {
		j=i+1;
		while(j<v.size()) {
			if (DaLiJeStepenDvojke(v.at(i))==1) {
				if (DaLiJeStepenDvojke(v.at(j))==1 && v.at(i)>v.at(j)){
					if(brojac_o<2) {

					opadajuci.push_back(v.at(i));
					opadajuci.push_back(v.at(j));
					brojac_o+=2;
					i=j;
					j++; 
						
					}
					else if(brojac_o>=2)  {
						opadajuci.push_back(v.at(j));
						brojac_o++;
						i=j;
						j++;
						
					}
						if(j==v.size()){
							brojaci_o.push_back(brojac_o);
							brojac_o=0;
						}
						
					if(rastuci.size()>=2  && brojac_r>0 ) {
						brojaci_r.push_back(brojac_r);
						brojac_r=0;
						
					}

				} else if( DaLiJeStepenDvojke(v.at(j))==1 && v.at(i)<v.at(j)) {
					if(brojac_r<2) {
					rastuci.push_back(v.at(i));
					rastuci.push_back(v.at(j));
					brojac_r+=2;
					i=j;
					j++;
						
					}
					else if (brojac_r>=2) {
						rastuci.push_back(v.at(j));
						brojac_r++;
						i=j;
						j++;
						
					}
					if(j==v.size()){
						brojaci_r.push_back(brojac_r);
						brojac_r=0;
						}
					
				
			
					
					if(opadajuci.size()>=2 && brojac_o>0) {
						brojaci_o.push_back(brojac_o);
						brojac_o=0;

					}

				} else if ((DaLiJeStepenDvojke(v.at(j))==0 || j==v.size()-1) && (rastuci.size()>=2 && brojac_r>0)) {
					brojaci_r.push_back(brojac_r);
					i++;
					j=i+1;
					brojac_r=0;

				} else if((DaLiJeStepenDvojke(v.at(j))==0 || j==v.size()-1) && (opadajuci.size()>=2 && brojac_o>0)){
					brojaci_o.push_back(brojac_o);
					i++;
					j=i+1;
					brojac_o=0;
				}
				else {
					i++;
					j=i+1;
				}

				}
			 else {
			 	i++;
			 	j=i+1;
			 }

			}
		
	}


	if(Tok==Opadajuci)
	{
		int visina_o=brojaci_o.size();
		if(visina_o==0) return opadajuci_n;
	opadajuci_n.resize(visina_o);
	int o=0;
	while(o<visina_o) {
		int vel_o2=opadajuci.size();
		for(int i=0; i<vel_o2; i++) {
			for(int b=0; b<brojaci_o.size(); b++) {
				int vel_o1=brojaci_o.at(b);
				for(int j=0; j<vel_o1; j++) {
					opadajuci_n.at(o).push_back(opadajuci.at(i));
					i++;
				}
					
				
				o++;

			}

		}
}
	
	return opadajuci_n;
		
	}
	else if(Tok==Rastuci){
		
		int visina_r=brojaci_r.size();
		if(visina_r==0) return rastuci_n;
		rastuci_n.resize(visina_r);
	
	int r=0;
	while(r<visina_r) {
		int vel_r2=rastuci.size();
		for(int i=0; i<vel_r2; i++) {
			for(int b=0; b<brojaci_r.size(); b++) {
				int vel_r1=brojaci_r.at(b);
				for(int j=0; j<vel_r1; j++) {
						rastuci_n.at(r).push_back(rastuci.at(i));
					i++;
				}
				
			
				r++;
			}
		}
	}
	return rastuci_n;	
	
}
	
}
int main ()
{
	int Tok(0);
	int broj_el(0),element(0);
	std::deque<std::vector<int>>opadajuci,rastuci;
	std::vector<int> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_el;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<broj_el; i++) {
		std::cin>>element;
		v.push_back(element);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>Tok;
	rastuci=MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
	opadajuci=MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
	if(Tok==2) {
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i=0; i<opadajuci.size(); i++) {
			for(int j=0; j<opadajuci.at(i).size(); j++) {
				std::cout<<opadajuci.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}


	} else if(Tok==1) {
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(int m=0; m<rastuci.size(); m++) {
			for(int n=0; n<rastuci.at(m).size(); n++) {
				std::cout<<rastuci.at(m).at(n)<<" ";
			}
			std::cout<<std::endl;
		}
	}



	return 0;
}