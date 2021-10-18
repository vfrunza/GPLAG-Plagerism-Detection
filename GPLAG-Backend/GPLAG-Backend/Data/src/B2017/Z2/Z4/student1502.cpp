
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;
int MOLIM_TE(int x,int y){
		return (-2)*x+y;
}

bool NEMOJ_MI_TO_RADIT(int x,int y){
		int suma1=0;
	 	for(int i=1;i<=x;i++){
			if(x%i==0)suma1++;
	 	}
	 	int suma2=0;
	 	for(int i=1;i<=y;i++){
			if(y%i==0)suma2++;
	 	}
	 	if(suma1==suma2) return y<x;
	 	return suma2<suma1;
}

template <typename it1, typename it2, typename it3>

void SortirajPodrucjeVrijednosti(it1 pocetak, it1 kraj, it2 poc1, it3 poc2,
typename remove_reference<decltype(*poc2)>::type f(typename remove_reference<decltype(*kraj)>::type,typename remove_reference<decltype(*kraj)>::type),
bool g(typename remove_reference<decltype(*kraj)>::type,typename remove_reference<decltype(*kraj)>::type)){
	
sort(pocetak,kraj,g);	
sort(poc1,poc1+(kraj-pocetak),g);

it1 temp1=pocetak;
it2 temp2=poc1;
it3 temp3=poc2;
int brojac=0;
while(temp1!=kraj){
auto x=*temp1;
auto y=*temp2;
auto itrez=find(poc2, poc2+(kraj-pocetak),f(x,y));
	if(itrez!=poc2+(kraj-pocetak)){
		auto hajde_ba=*itrez;
		*itrez=*temp3;
		*temp3=hajde_ba;
	}else{
		throw logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
brojac++;
temp1++;
temp2++;
temp3++;
if(temp1==poc2+(kraj-pocetak))break;
}
}

int main (){
	int n;
	cout<<"Unesite broj elemenata: ";
	cin>>n;
	cin.ignore(10000,'\n');
		vector<int> v;
	cout<<"Unesite elemente prvog vektora: ";
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		bool upisati=true;
		for(int x :v){
			if(x==a){
				upisati=false;
				i--;
				break;
			}
		}
		if(upisati)v.push_back(a);
	}
	cin.ignore(10000,'\n');
		vector<int> v1;
	cout<<"Unesite elemente drugog vektora: ";
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
bool upisati=true;
		for(int x :v1){
			if(x==a){
				upisati=false;
				i--;
				break;
			}
		}		
		if(upisati)v1.push_back(a);
	}
	cin.ignore(10000,'\n');
		vector<int> v2;
	cout<<"Unesite elemente treceg vektora: ";
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		bool upisati=true;
		for(int x :v2){
			if(x==a){
				upisati=false;
				i--;
				break;
			}
		}
		if(upisati)v2.push_back(a);
	}
	cout<<endl;
	try{
	 
	 
	 SortirajPodrucjeVrijednosti(v.begin(),v.end(), v1.begin(),v2.begin(),MOLIM_TE, NEMOJ_MI_TO_RADIT);
	 cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<endl;
	 for(int i=0;i<n;i++){
	 	cout<<"f("<<v.at(i)<<", "<<v1.at(i)<<") = "<<v2.at(i)<<endl;
	 }
	}catch(logic_error hi){
		cout<<"Izuzetak: "<<hi.what();
	}
	
	
	return 0;
}