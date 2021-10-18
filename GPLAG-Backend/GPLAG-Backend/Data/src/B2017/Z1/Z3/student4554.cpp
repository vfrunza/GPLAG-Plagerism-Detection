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

enum Smjer {Rastuci = 1, Opadajuci = 2};

bool DaLiJeBrojStepenDvojke (int n)
{
	if(!(n==0) && !(n & (n - 1))) return true;
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer z)
{

//	std::vector<int> a; //vektor rastucih
	std::vector<int> b; //vektor opadajucih
//	std::deque<std::vector<int>> dek_c; //dek rastucih
	std::deque<std::vector<int>> dek_d; //dek opadajucih
	
	if(z == Rastuci) {
	for(int i=0; i<v.size()-1; i++) {
		if(DaLiJeBrojStepenDvojke(v.at(i)) ) {
			while (i!=v.size()-1 && DaLiJeBrojStepenDvojke(v.at(i+1)) && v.at(i) <= v.at(i+1)) {
				b.push_back(v.at(i));
				i++;
			}
			if(!DaLiJeBrojStepenDvojke(v.at(i))) {
				if(b.size() >= 2)
					dek_d.push_back(b);
				b.resize(0);
				continue;
			}
			if (DaLiJeBrojStepenDvojke(v.at(i)) && b.size() !=0 && v.at(i) > v.at(i-1)){
				b.push_back(v.at(i));
				dek_d.push_back(b);
				b.resize(0);
			}
			else{
				if(b.size() >= 2)
					dek_d.push_back(b);
				b.resize(0);
			}
			    
		}
		if(!DaLiJeBrojStepenDvojke(v.at(i))) {
			    if(b.size() >= 2)
				  dek_d.push_back(b);
				b.resize(0);
		}
	}
	if(b.size()>=2)
	dek_d.push_back(b);
				
}
else if(z == Opadajuci) {
	for(int i=0; i<v.size()-1; i++) {
		if(DaLiJeBrojStepenDvojke(v.at(i)) ) {
			while (i!=v.size()-1 && DaLiJeBrojStepenDvojke(v.at(i+1)) && v.at(i) >= v.at(i+1)) {
				b.push_back(v.at(i));
				i++;
			}
			if(!DaLiJeBrojStepenDvojke(v.at(i))) {
				if(b.size() >= 2)
					dek_d.push_back(b);
				b.resize(0);
				continue;
			}
			if (DaLiJeBrojStepenDvojke(v.at(i)) && b.size() !=0 && v.at(i) < v.at(i-1)){
				b.push_back(v.at(i));
				dek_d.push_back(b);
				b.resize(0);
			}
			else{
				if(b.size() >= 2)
					dek_d.push_back(b);
				b.resize(0);
			}
			    
		}
		if(!DaLiJeBrojStepenDvojke(v.at(i))) {
			    if(b.size() >= 2)
				  dek_d.push_back(b);
				b.resize(0);
		}
	}
	if(b.size()>=2)
	dek_d.push_back(b);
				
}
 return dek_d;
}
	/*
	if(z == 1) {
	  for(int i=0; i<v.size()-1; i++) {
		if(DaLiJeBrojStepenDvojke(v.at(i))) {
			if(DaLiJeBrojStepenDvojke(v.at(i+1))) {
				a.push_back(v.at(i));
				a.push_back(v.at(i+1));
				i++;
				while(v.at(i)<=v.at(i+1) && DaLiJeBrojStepenDvojke(v.at(i+1)) && (i < v.size())){
				a.push_back(v.at(i+1));
				i++;
			}
			dek_c.push_back(a);

			}
			if(DaLiJeBrojStepenDvojke(v.at(i)) && v.at(i) <= v.at(i+1)) {
		        a.push_back(v.at(i));
		        }}}

		        a.resize(0);
	}
	12 128*/
	//else     1 4 2 4 32 
/*	if(z == 2) {
		for(int i=0; i<v.size(); i++) {
			bool odgovarajuci(true);
			if(!DaLiJeBrojStepenDvojke(v.at(i))) {
				if(b.size()>=2){ 
					dek_d.push_back(b);
					
					std::cout << "vektor " << std::endl;
						
					for(int i=0; i<b.size(); i++)
						std::cout << b.at(i) << " ";
						std::cout << std::endl;
					
					b.resize(0);
				}
				odgovarajuci=false;
			}
			if(b.size()>0){
				if(
					v.at(i)>v.at(i-1)){
					odgovarajuci=false;
					}
			}
			if(b.size()==0  && odgovarajuci)
				b.push_back(v.at(i));
			else if(odgovarajuci)
				b.push_back(v.at(i));
			else if(!odgovarajuci){
				if(b.size()>=2){ 
					dek_d.push_back(b);
					
						std::cout << "vektor " << std::endl;
						
					for(int i=0; i<b.size(); i++)
						std::cout << b.at(i) << " ";
						std::cout << std::endl;
						
					b.resize(0);
					continue;
				} 
				b.resize(0);
				if(DaLiJeBrojStepenDvojke(v.at(i-1)) && v.at(i)>v.at(i-1)){
					i--;
				

				}
			}
			
		}
		if (b.size()>=2){
		   dek_d.push_back(b);
		   
		  std::cout << "vektor " << std::endl;
						
					for(int i=0; i<b.size(); i++)
						std::cout << b.at(i) << " ";
						std::cout << std::endl;
		//  std::cout <<std::endl<< "dek:" << dek_d.size();
		}
    }
    return dek_d;
}
			
			
			
			
			/*
			if(!DaLiJeBrojStepenDvojke(v.at(i)) || (i!=v.size()-1 && v.at(i) < v.at(i+1))) {
				if(b.size() >= 2) {
					dek_d.push_back(b);
					b.resize(0);
				}
			 } 
			else b.push_back(v.at(i));
			//if(DaLiJeBrojStepenDvojke(v.at(i)) && (i!=v.size()-1 && v.at(i) >= v.at(i+1)))
		//				b.push_back(v.at(i));
	//			else if(DaLiJeBrojStepenDvojke(v.at(i)) && (i==v.size()-1 )
//						b.push_back(v.at(i));
*/



/*
if(z == 2) {
	for(int i=0; i<v.size()-1; i++) {
		if(DaLiJeBrojStepenDvojke(v.at(i))) {
			if(v.at(i) >= v.at(i+1)) {
				b.push_back(v.at(i));
				dek_d.push_back(b);
				b.resize(0);
			}
		}
	}
}

 */

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;

	std::cout<<"Unesite elemente vektora: ";

	int x;
	std::vector<int> v;

	for(int i=0; i<n; i++) {
		std::cin>>x;
		v.push_back(x);
	}

	int s;
	Smjer a;

	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>s;

	while(s!=1 && s!=2) {
		std::cout<<"Neispravan unos";
		std::cin>>s;
	}

	a = Smjer(s);

	std::deque<std::vector<int>> kraj;

	kraj = MaksimalniPodnizoviStepenaDvojke(v, a);

	if(s == 1) {
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		for(int i=0; i<kraj.size(); i++) {
			for(int j=0; j<kraj.at(i).size(); j++) {
				std::cout<<kraj.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}

	else if(s == 2) {
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		for(int i=0; i<kraj.size(); i++) {
			for(int j=0; j<kraj.at(i).size(); j++) {								
				std::cout<<kraj.at(i).at(j) << " ";
			}
			std::cout<<std::endl;
		}
	}

	return 0;
}