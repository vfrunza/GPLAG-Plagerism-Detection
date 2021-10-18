/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cstdlib>

bool DaLiJeOpaki(int x){
	int jedan(0),dva(0),nula(0);
	if(x==0) return false;
	while(x!=0){
		int c=abs(x%3);
		if(c==1) jedan++;
		else if(c==2) dva++;
		else nula++;
		x/=3;
	}
	if((jedan==0 || jedan%2==0) && (dva==0 || dva%2==0) && (nula==0 || nula%2==0))return true;
	return false;
}

bool DaLiJeOdvratni(int x){
	int jedan(0),dva(0),nula(0);
	if(x==0) return true;
	while(x!=0){
		int c=abs(x%3);
		if(c==1) jedan++;
		else if(c==2) dva++;
		else nula++;
		x/=3;
	}
	if((jedan==0 ||jedan%2!=0) && (dva==0 || dva%2!=0) && (nula==0 || nula%2!=0)) return true;
	return false;
}


std::vector<int> IzdvojiGadne (std::vector<int> v, bool a){
	if(v.size()>1){ 
		for(int i=0;i<v.size()-1;i++){
			for(int j=i+1;j<v.size();j++){
				if(v[i]==v[j]){
					v.erase(v.begin()+j);
					j--;
				}
			}
		}
	}
	std::vector<int>v1;
	if(a){
		//trazimo opake
		for(int i=0;i<v.size();i++){
			if(DaLiJeOpaki(v[i])) v1.push_back(v[i]);
		}
	}
	else{
		// odvratne
		for(int i=0;i<v.size();i++){
			if(DaLiJeOdvratni(v[i])) v1.push_back(v[i]);
		}
	}
	return v1;
}

int main ()
{
	std::vector<int> a;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		int x;
		std::cin >> x;
		if(!std::cin) {
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			return 0;
		}
		if(x==0) break;
		a.push_back(x);
	}
	std::vector<int>b=IzdvojiGadne(a,true);
	std::vector<int> c=IzdvojiGadne(a,false);
	std::cout << "Opaki: ";
	for(int i=0;i<b.size();i++) std::cout << b[i] << " ";
	std::cout<< std::endl << "Odvratni: ";
	for(int i=0;i<c.size();i++) std::cout << c[i] << " ";
	std::cout<<std::endl;
	return 0;
}