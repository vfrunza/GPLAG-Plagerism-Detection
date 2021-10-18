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
using std:: vector;
long long int  BazaTri(int a){
	long long int b(0);
	int i(1);
	while(a!=0){
		b+=(a%3)*i;
		i*=10;
		a/=3;
	}
	return b;
}
vector<int> provjera (vector<int> v1){
	for(int i=0; i<v1.size(); i++){
		for(int j=i+1; j<v1.size(); j++){
			if(v1.at(i)==v1.at(j)) {
				
				v1.erase(v1.begin()+j);
				j--;
			}
		}
	}
	return v1;
}
bool Opak(int a){
	std::vector<int> v1(0);
	long long int b(BazaTri(abs(a)));
	while(b!=0){
		v1.push_back(b%10);
		b/=10;
	}
	for(int i=0; i<v1.size(); i++){
		int br(0);
		for(int j=0; j<v1.size(); j++){
			if(v1.at(i)==v1.at(j)) br++;
		}
		if(br%2!=0) return false;
	}
	
	return true;
}
bool Odvratan(int a){
	vector<int> v1(0);
	long long int b(BazaTri(abs(a)));
	while(b!=0){
		v1.push_back(b%10);
		b/=10;
	}
	for(int i=0; i<v1.size(); i++){
			int br(0);
		for(int j=0; j<v1.size(); j++){
			if(v1.at(i)==v1.at(j)) br++;
		}
		if(br%2==0 && br!=0) return false;
	}
	return true;
}
vector<int> IzdvojiGadne(vector <int>v1, bool da){
	vector<int> v2(0);
	if(da){
		for(int i=0; i<v1.size(); i++){
			if(Opak(v1.at(i))==true) v2.push_back(v1[i]);
		}
	}
	else if(!da){
		for(int i=0; i<v1.size(); i++){
			if(Odvratan(v1.at(i))==true) v2.push_back(v1[i]);
		}
	}
	v2=provjera(v2);
	return v2;
}
int main ()
{	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	vector<int> v1;
	int n;
	do{
		std::cin>>n;
		if(n==0) break;
		v1.push_back(n);
	}while(n!=0);
	vector<int> opaki(IzdvojiGadne(v1, true));
	std::cout<<"Opaki: ";
	for(int i=0; i<opaki.size(); i++){
		std::cout<<opaki[i]<<" ";
	}
	std::cout <<"\n";
	vector<int> odvratni(IzdvojiGadne(v1, false));
	std::cout<<"Odvratni: ";
	for(int i=0; i<odvratni.size(); i++){
		std::cout<<odvratni[i]<<" ";
	}
	return 0;
}