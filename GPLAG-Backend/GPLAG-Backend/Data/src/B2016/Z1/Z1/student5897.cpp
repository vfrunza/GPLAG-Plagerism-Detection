#include <iostream>
#include <vector>


bool ProvjeriOpaki(int n) {
	bool gadni(false);
	int broj_jedinice(0), broj_dvice(0), broj_nule(0);
	
	while(n) {
		if(n%3==0) broj_nule++;
		else if(n%3==1) broj_jedinice++;
		else broj_dvice++;
		n/=3;
	}
	if((broj_nule%2==0 ||broj_nule==0) && (broj_jedinice%2==0 || broj_jedinice==0) && (broj_dvice%2==0 || broj_dvice==0)) gadni=true;
	return gadni;
}

bool ProvjeriOdvratni(int n) {
	bool gadni(false);
	int broj_jedinice(0), broj_dvice(0), broj_nule(0);
	
	while(n) {
		if(n%3==0) broj_nule++;
		else if(n%3==1) broj_jedinice++;
		else broj_dvice++;
		n/=3;
	}
	
	if((broj_nule%2!=0 || broj_nule==0) && (broj_jedinice%2!=0 || broj_jedinice==0) && (broj_dvice%2!=0 || broj_dvice==0)) gadni=true;
	return gadni;
}


std::vector<int> IzdvojiGadne(std::vector<int> vekt, bool gadni) {
	//gadni=true opaki
	//gadni = false odvratni
	
	
	//za gadne brojeve
	if(gadni==true) {
		
		std::vector<int> opaki;
		
		for(int i=0; i<vekt.size(); i++) {
			bool a(ProvjeriOpaki(abs(vekt[i]))); 
			
			if(a==true && vekt[i]!=0)
			 {
				opaki.push_back(vekt[i]);
				
				//provjera duplikata
				if(opaki.size()>0) {
					for(int j=0; j<opaki.size()-1; j++) {
						if(opaki[opaki.size()-1]==opaki[j]) opaki.resize(opaki.size()-1);
					}
				}
				
				
			}
		}
		return opaki;
	}
	
	//za odvratne brojeve
	if(gadni==false) {
		
		std::vector<int> odvratni;
		
		for(int i=0; i<vekt.size(); i++) {
			bool a(ProvjeriOdvratni(abs(vekt[i]))); 
			
			if(a==true) {
				odvratni.push_back(vekt[i]);
				
				//provjera duplikata
				if(odvratni.size()>0) {
					for(int j=0; j<odvratni.size()-1; j++) {
						if(odvratni[odvratni.size()-1]==odvratni[j]) odvratni.resize(odvratni.size()-1);
					}
				}
				
				
			}
		}
		
		return odvratni;
	}
	
	return vekt;
}

int main ()
{
	std::vector<int> n;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	
	int x;
	do {
		std::cin >> x;
		n.push_back(x);
	} while(x!=0);

	if(n.size()>1) n.resize(n.size()-1);
	std::vector<int> opaki = IzdvojiGadne(n, true);
	std::vector<int> odvratni = IzdvojiGadne(n, false);
	

		std::cout << "Opaki: ";
		for(int i: opaki) std::cout << i << " ";
		std::cout << std::endl;
	//else std::cout << "Opaki: " << 0 << std::endl;
	

		std::cout << "Odvratni: ";
		for(int j: odvratni) std::cout << j << " "; 

	//else std::cout << "Odvratni: " << 0;
	

	return 0;
}