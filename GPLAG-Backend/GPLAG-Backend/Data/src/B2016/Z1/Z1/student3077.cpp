/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;


std::vector<int> IzdvojiGadne(std::vector<int> v, bool a){
	std::vector<int> v1;
	std::vector<int> brojac(3,0);
	for(int i=0; i<v.size(); i++){
		int kopija(v.at(i));
		brojac={0,0,0};
		if(kopija==0)
			brojac[0]++;
		else{
			while(kopija!=0){
			int cifra=abs(kopija%3);
			kopija/=3;
			brojac[cifra]++;
			}
		}
		if(a){
			if(brojac[0]%2==0 && brojac[1]%2==0 && brojac[2]%2==0)
				v1.push_back(v.at(i));
		}
		else{
			if((brojac[0]%2!=0 || brojac[0]==0) && (brojac[1]%2!=0 || brojac[1]==0) && (brojac[2]%2!=0 || brojac[2]==0))
				v1.push_back(v.at(i));
		}
	}
	for(int i=0; i<v1.size(); i++){
		for(int j=i+1; j<v1.size(); j++){
			if(i<v1.size()-1 && v1[i]==v1[j]) {
				v1.erase(v1.begin()+j);
				i--;
			}
		}
	}
	return v1;
}


int main ()
{
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	for(;;){
		int i(0);
		int a;
		cin>>a;
		if(a==0) break;
		v.push_back(a);
		i++;
	}
	
	std::vector<int> v2=IzdvojiGadne(v,true);
	cout<<"Opaki: ";
	for(int i=0; i<v2.size(); i++){
		cout<<v2[i]<<" ";
	}
	cout<<std::endl;
	v2=IzdvojiGadne(v,false);
	cout<<"Odvratni: ";
	for(int i=0; i<v2.size(); i++){
		cout<<v2[i]<<" ";
	}
	return 0;
}