/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool tacno) {
	std::vector<int> gadni;
	if(tacno) {
		for(int i(0);i<v.size();i++) {
			int hist[3]{0},temp=v[i];
			if(v[i]<0) temp=-temp;
			//pretvaram broj u ternarni i brojim ponavljanja svake cifre
			
			do {
				hist[temp%3]++;
				temp/=3;
			} while(temp!=0);
			
			//provjeravam da li je broj opak
			
			bool opak=true;
			for(int j(0);j<3;j++) {
				if(hist[j]%2!=0) {
					opak=false;
					break;
				}
			}
			
			//provjeravam da li je broj vec stavljen u gadne
			
			bool postoji=false;
			for(int j(0);j<gadni.size();j++) {
				if(gadni[j]==v[i]) postoji=true;
			}
			if(opak && !postoji) gadni.push_back(v[i]);
		}
	}
	else {
		for(int i(0);i<v.size();i++) {
			int hist[3]{0},temp=v[i];
			if(v[i]<0) temp=-temp;
			do {
				hist[temp%3]++;
				temp/=3;
			} while(temp!=0);
			
			//provjeravam da li je broj odvratan
			
			bool odvratan=true;
			for(int j(0);j<3;j++) {
				if(hist[j]!=0 && hist[j]%2==0) {
					odvratan=false;
					break;
				}
			}
			bool postoji=false;
			for(int j(0);j<gadni.size();j++) {
				if(gadni[j]==v[i]) postoji=true;
			}
			if(odvratan && !postoji) gadni.push_back(v[i]);
		}
	}
	return gadni;
}

int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int broj;
	do {
		std::cin>>broj;
		if(broj!=0) v.push_back(broj);
	} while(broj!=0);
	std::vector<int> opaki=IzdvojiGadne(v,true);
	std::cout<<"Opaki:";
	for(auto x : opaki) {
		std::cout<<" "<<x;
	}
	std::vector<int> odvratni=IzdvojiGadne(v,false);
	std::cout<<"\nOdvratni:";
	for(auto x : odvratni) {
		std::cout<<" "<<x;
	}
	return 0;
}
