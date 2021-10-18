/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>
#include <string>

using namespace std;

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename tip>
tip IskopirajUSmjeru(tip k_pocetni, SmjerKretanja smjer){
	
	int vel(k_pocetni.size());
	
	tip k1(k_pocetni);
	
	for(int i = 0; i < vel; i++ ){
		
		for(int j = 0; j < vel; j++){
			
			for(int k = 0; k < vel; k++){															//smjer kretanja slovima
				
				if(smjer == SmjerKretanja(3))
					k1.at(i).at(j).at(k) = k_pocetni.at(i).at(vel - 1 - j).at(k);
				
				else if(smjer == SmjerKretanja(5))
					k1.at(i).at(j).at(k) = k_pocetni.at(i).at(k).at(vel - 1 - j);
					
				else if(smjer == SmjerKretanja(4))
					k1.at(i).at(j).at(k) = k_pocetni.at(i).at(k).at(j);
					
				else if(smjer == SmjerKretanja(0))
					k1.at(i).at(j).at(k) = k_pocetni.at(j).at(i).at(k);
				
				else if(smjer == SmjerKretanja(1))
					k1.at(i).at(j).at(k) = k_pocetni.at(vel - 1 - j).at(i).at(k);
			}
		}
	}
	
	return k1;
}

template <typename kont>
kont PjescaniSat(kont kontejner, SmjerKretanja smjer){
	
	
	for(int i = 0; i < kontejner.size(); i++){
		if(kontejner.size() != kontejner.at(i).size()) throw domain_error ("3D matrica nema oblik kocke");
		
		for(int j = 0; j < kontejner.at(i).size() ; j++)
			if(kontejner.at(i).size() != kontejner.at(j).size()) throw domain_error("3D matrica nema oblik kocke");
	}
	
	if(kontejner.size() % 2 == 0) throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	
		
	int vel(kontejner.size());
	
	kontejner = IskopirajUSmjeru(kontejner,smjer);
	
	for(int i = 0; i < vel; i++ ){
		
		int br(0);
	
		
		for(int j = 0; j < vel; j++){
			
				if(j > vel/2) br = br + 2;
			
			for(int k = 0; k < j - br; k++){
				
				kontejner.at(i).at(j).erase(kontejner.at(i).at(j).begin());
				
				kontejner.at(i).at(j).erase(kontejner.at(i).at(j).end() - 1);

			}
		}
	}	
	return kontejner;
}

int main ()
{
	
	cout<<"Unesite dimenziju (x/y/z): ";
	
	int n;
	cin>>n;
	
	if(n < 0) 
		while(n < 0){
		
			cout<<"Dimenzija nije ispravna, unesite opet: ";
			cin>>n;
		
		}
		
	cout<<"Unesite elemente kontejnera: ";
	
	vector<deque <deque <int> > > kontejner;
	
	try{
	kontejner.resize(n);
	}
	catch(...){
		throw;
	}
	
	for(int i = 0; i < n; i++){
		
		int broj;
		
		for(int j = 0; j < n; j++){
			
			try{
			kontejner.at(i).resize(n);
			}
			catch(...){
				throw;
			}
			for(int k = 0; k < n; k++){
		
				cin>>broj;
				try{
					kontejner.at(i).at(j).push_back(broj);
				}
				catch(...){
					throw;
				}
		
			}
		}
	}
	
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	
	int m;
	cin>>m;
	
	while(m < 0 || m > 5){
		
		cout<<"Smjer nije ispravan, unesite opet: ";
		cin>>m;	
		
	}
	
	cout<<endl;
	
	try{
	kontejner=PjescaniSat(kontejner,SmjerKretanja(m));
	
	cout<<"Pjescani sat unesene matrice je:";
	
	for(int i = 0; i < kontejner.size(); i++){
		cout<<endl<<endl;
		
		int br(0);
		
		for(int j = 0; j < kontejner.at(i).size(); j++){
			
			if(j > n/2) br=br+2;

			for(int k = 0; k < kontejner.at(i).at(j).size(); k++){
				
				if((j != 0 && j != n - 1) && k == 0) cout<<right<<setw(4*(j + 1 - br) )<<kontejner.at(i).at(j).at(k);
				else cout<<right<<setw(4)<<kontejner.at(i).at(j).at(k);
		
			}
			cout<<endl;
		}
	}
	
	}
	catch(domain_error e){
		cout<<"Izuzetak: "<<e.what()<<endl;
	}
	catch(length_error e){
		cout<<"Izuzetak: "<<e.what()<<endl;
	}
	catch(...){
		cout<<"Izuzetak!"<<endl;
	}
			
			
	return 0;
}















