/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> Izbaci(std::vector<int> v){
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if(v[i]==v[j]){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}

std::vector<int> Opaki(std::vector<int> v){
	std::vector<int> opaki;
	for(int x: v){
		std::vector<int> histogram(3);
		int a=x;
		do{
			histogram[abs(a%3)]++;
			a/=3;
		}while(a!=0);
		bool paran(true);
		for(int c: histogram){
			if(c==0) continue;
			if(c%2!=0){
				paran=false;
				break;
			}
		}
		if(paran) opaki.push_back(1);
		else opaki.push_back(0);
	}
	return opaki;
}

std::vector<int> Odvratni(std::vector<int> v){
	std::vector<int> odvratni;
	for(int x: v){
		std::vector<int> histogram(3);
		int a=x;
		do{
			histogram[abs(a%3)]++;
			a/=3;
		}while(a!=0);
		bool neparan(true);
		for(int c: histogram){
			if(c==0) continue;
			if(c%2==0){
				neparan=false;
				break;
			}
		}
		if(neparan) odvratni.push_back(1);
		else odvratni.push_back(0);
	}
	return odvratni;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool t){
	v=Izbaci(v);
	std::vector<int> izdvojeni;
	std::vector<int> opaki=Opaki(v);
	std::vector<int> odvratni=Odvratni(v);
	if(t){
		for(int i=0; i<v.size(); i++){
			if(opaki[i]) izdvojeni.push_back(v[i]);
		}
		return izdvojeni;
	}
	else{
		for(int i=0; i<v.size(); i++){
			if(odvratni[i]) izdvojeni.push_back(v[i]);
		}
		return izdvojeni;
	}
	return izdvojeni;
}

int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int a=1;
	while(a!=0){
		std::cin>>a;
		if(a==0) break;
		v.push_back(a);
	}
	std::vector<int> opaki=IzdvojiGadne(v, true);
	std::vector<int> odvratni=IzdvojiGadne(v, false);
	std::cout <<"Opaki: ";
	for(int x: opaki) std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int x: odvratni) std::cout<<x<<" ";
	std::cout<<std::endl;
	return 0;
}