/*B 2017/2018, Zadaća 1, Zadatak 1
	
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
#include <cmath>

using namespace std;

bool Simetricni(vector <int> v1){
	
	bool b = true;
	int l( 0 ) ;
				
	for(int k = 0; k < v1.size() / 2 ; k++){
				
		if(v1.at(k) != v1.at( v1.size()-l-1 ) ) { b=false; break; }
		l++;
					
	}
	
	return b;
}



vector <int> IzdvojiSimetricneTernarne(vector <int> v, bool T){
	
	vector <int> vek;
	
	if(T == true){
		
		for(int i = 0; i < v.size() ;i++){    
			bool a=true;
			
			for(int j = 2; j < sqrt( v.at(i) ) + 1; j++){
				
				if(v.at(i) == 0 || v.at(i) == 1) { a=false; break; }
				
				if(v.at(i) % j == 0) { a=false; break; }
					
			}
			
			if(a == true) {
				
				vector <int> v1;
				int x( v.at(i) ) ;
 				
				do{ 
					
					int temp;
					temp = x % 3;
					x = x / 3;
					v1.push_back(temp);
					
				}while(x != 0);
				
			    if( Simetricni(v1) ) vek.push_back( v.at(i) );
			
			}
		}
	}
	
	else if (T == false) {
		for(int i = 0; i < v.size() ;i++){    
			bool a=false;
			
			for(int j = 2; j < sqrt( v.at(i) ) + 1; j++){
				
				if(v.at(i) % j == 0) { a=true; break; }
					
			}
			
			if(a == true){
				
					
				vector <int> v1;
				int x( v.at(i) ) ;
 				
				do{ 
					
					int temp;
					temp = x % 3;
					x = x / 3;
					v1.push_back(temp);
					
				}while(x != 0);
				
			    if( Simetricni(v1) ) vek.push_back( v.at(i) );
			
				
			}
		}
	}
	
	return vek;
}

int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	
	int broj ;
	vector <int> v;
	
	while(1){
		
		cin>>broj;
		
		while(!cin){
			
			cin.clear();
			cin.ignore(10000, '\n');
			cin>>broj;
			
		}
		
		if(broj == -1) break;
		
		v.push_back(broj);
		
	}
	
	int T;
	
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	do{
	
	cin>>T;
	
	if(T == 1|| T == 0) break;
	
	else cout<<"Neispravan unos! Unesite ponovo: ";
	
	}while(1);
	
	vector <int> vek;
	
	vek=IzdvojiSimetricneTernarne(v,T);
	
	if(vek.size() == 0 && T == false)  cout<<"Nema slozenih simetricnih brojeva u vektoru."; 

	else if(vek.size() == 0 && T == true)  cout<<"Nema prostih simetricnih brojeva u vektoru."; 
	
	else if(T == true){
		
	cout<<"Prosti simetricni brojevi iz vektora su: ";
	
	for(int i = 0; i < vek.size() - 1; i++)  cout<<vek.at(i)<<", ";
	
	cout<<vek.at(vek.size()-1)<<".";
	
	}
	
	else if(T == false){
		
		cout<<"Slozeni simetricni brojevi iz vektora su: ";
	
		for(int i = 0; i < vek.size() - 1; i++)  cout<<vek.at(i)<<", ";
	
		cout<<vek.at(vek.size()-1)<<".";
	}
	
	return 0;
}