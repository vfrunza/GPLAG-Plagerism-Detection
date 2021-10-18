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

using std::cout;
using std::cin;
using std::endl;

enum Smjer{Rastuci=1,Opadajuci};

typedef std::deque<std::vector<int>> Dek_vektora;

bool StepenDvojke(int n){
	
	if(n<=0) return false;
	
	while(n!=1){
		if(n%2!=0) return false;
		n/=2;
	}
	
	return true; 
	
}

Dek_vektora MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer smjer){
	
	Dek_vektora d;
	int cnt{0};
	int k{-1};
	std::vector<int> a;
	bool novi_red{false};
	
	for(int i=0;i<v.size();i++){
		cnt=0;
		novi_red=false;
		
		if (i!=v.size()-1 && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))){ 
		
		if (smjer==1 && v.at(i)<=v.at(i+1)){
			d.push_back(a); 
			k++;
			novi_red=true;
		}
		
		else if(smjer!=1 && v.at(i)>=v.at(i+1)){
			d.push_back(a);
			k++;
			novi_red=true;
		}
		
		if(novi_red){
		
		int j{0};
		
		for(j=i;j<v.size()-1;j++){
			
			if(smjer==1){
				
			if(v.at(j)<=v.at(j+1) && StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1))){
	
				d.at(k).push_back(v.at(j));
				cnt++;
		}
		
		
		
		else {
			
			if (j>=1 && StepenDvojke(v.at(j)) && v.at(j-1)<=v.at(j)) d.at(k).push_back(v.at(j)); 
			else if (j==v.size()-2 && v.at(j)<=v.at(j+1) && StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1)) ) d.at(k).push_back(v.at(j+1));
			
			break;
		}
		
			}
			
		else {
			
			if(v.at(j)>=v.at(j+1) && StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1))){
	
				d.at(k).push_back(v.at(j));
				cnt++;
		}
		
		
		
		else {
			
			if (j>=1 && StepenDvojke(v.at(j)) && v.at(j-1)>=v.at(j)) d.at(k).push_back(v.at(j)); 
			else if (j==v.size()-2 && v.at(j)>=v.at(j+1) && StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1)) ) d.at(k).push_back(v.at(j+1));
			break;
		}
			
			
		}
		

		
}
		
		if (j==v.size()-1 && smjer==1 && v.at(j-1)<=v.at(j) && StepenDvojke(v.at(j-1)) && StepenDvojke(v.at(j)) ) d.at(k).push_back(v.at(j));
		else if(j==v.size()-1 && v.at(j-1)>=v.at(j) && StepenDvojke(v.at(j-1)) && StepenDvojke(v.at(j)) ) d.at(k).push_back(v.at(j));
		
		}
		}
		i+=cnt;
		
	}
	
	
	
	return d;
	
	
}



int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	
	std::vector<int> v;
	int clan;
	
	cout<<"Unesite elemente vektora: ";
	
	for(int i=0;i<n;i++){
		cin>>clan;
		v.push_back(clan);
	}
	
	int a;
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>a;
	
	cout<<"Maksimalni ";
	
	if(a==1){
		auto d(MaksimalniPodnizoviStepenaDvojke(v,Smjer(a)));
		cout<<"rastuci podnizovi: ";
		cout<<endl;
		for(int i=0;i<d.size();i++){
			for(int j=0;j<d.at(i).size();j++){
				cout<<d.at(i).at(j)<<" ";
			}
			cout<<endl;
		}
	}
	
	if(a==2){
		auto d(MaksimalniPodnizoviStepenaDvojke(v,Smjer(a)));
		cout<<"opadajuci podnizovi: ";
		cout<<endl;
		for(int i=0;i<d.size();i++){
			for(int j=0;j<d.at(i).size();j++){
				cout<<d.at(i).at(j)<<" ";
			}
			cout<<endl;
		}
	}
	
	


	
	return 0;
}