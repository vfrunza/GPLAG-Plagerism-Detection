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
#include <cmath>
using namespace std;
bool StepenDvojke(int n){
	return (ceil(log2(n)) == floor(log2(n)));
}
enum Smjer{Rastuci=0, Opadajuci};
deque<vector<int>> Smjesti(vector <int> v, int prvi, int zadnji){
	int k(0);
	deque<vector<int>> c(v.size());
	for(prvi; prvi <=zadnji; prvi++){
		c.at(k).push_back(v.at(prvi));
	}
	return c;
}
deque <vector<int>> MaksimalniPodnizoviStepenaDvojke(vector <int> v, Smjer s){
	int prvi, brojac(0), pom, k(0);
	deque<vector<int>> c(v.size());
    
   
	for(int i=0; i<v.size(); i++){
		
		 prvi = i;
		 int b = prvi;
		 brojac = 0;
	    if(i+1<v.size()-1){
		 for(int j=i+1;;j++){
		 
		 if ((v.at(i)>= 1 && v.at(j)>= 1 && s == Rastuci  && v.at(j) >= v.at(i)  && StepenDvojke(v.at(i)) && StepenDvojke(v.at(j))) || (v.at(i) >= 1 && v.at(j) >=1 && s == Opadajuci && v.at(j) <= v.at(i) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(j)))) {
		 		brojac++; 
		 		if(j<v.size()-1 && b+brojac<=v.size()-1) i++; else{ return Smjesti(v,prvi,b+brojac); }
		 	}
		 	
		 	else { if(brojac > 0 && (prvi+brojac) < v.size()-1){
		 		   for(prvi; prvi<=b+brojac;prvi++){
		 		   	  c.at(k).push_back(v.at(prvi));
		 		   }
		 		   k++;
		 		}
		 	
		 		break;
		 }
		 
		 
	}
}}

return c;
}

int main ()

{   
	int n;
    cout << "Unesite broj elemenata vektora: ";
    cin >> n;
    vector <int> v;
    cout << "Unesite elemente vektora: ";
    int k;
    for(int i=0; i<n; i++){
    	cin >> k;
    	v.push_back(k);
    }
    cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int a;
    cin >> a;
    Smjer s = Smjer(a-1);
    deque <vector<int>> c;
    c = MaksimalniPodnizoviStepenaDvojke(v,s);
   
    if(a==1){
    	cout << "Maksimalni rastuci podnizovi: ";
    	cout << endl;
    	for(int i=0; i<c.size(); i++){
    		for(int j=0; j<c.at(i).size();j++){
    			cout << c.at(i).at(j)<<" ";
    		}
    		cout << endl;
    	}
    } else if(a==2){
    	cout << "Maksimalni opadajuci podnizovi: ";
    	cout << endl;
    	for(int i=0; i<c.size(); i++){
    		for(int j=0; j<c.at(i).size();j++){
    			cout << c.at(i).at(j) <<" ";
    		}
    		cout << endl;
    	}
    }
     
	return 0;
}