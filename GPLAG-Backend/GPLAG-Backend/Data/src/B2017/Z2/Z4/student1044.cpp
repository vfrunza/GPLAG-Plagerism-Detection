/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;
template<typename Tip>
int brojProstihFaktora (Tip broj){
	int i;
	int brojac=0;
	i=1;
	while(i<=broj){
		if(broj%i==0){
			int j=1, k=0;
			while(j<=i){
				if(i%j==0)
					k++;
					j++;
					
				}
				if(k==2)brojac++;
			}
			i++;
		}
		return brojac;
	}
template<typename tip1>
bool zaUporedjivanje (tip1 x, tip1 y){
	if(brojProstihFaktora(x)>brojProstihFaktora(y)) return true;
	else return false;
}

template<typename tip2>
int f (tip2 x, tip2 y){
	tip2 n((-2)**x+*y);
	return n;
}
template<typename T1, typename T2, typename T3, typename F1, typename F2>
void SortirajPodrucjeVrijednosti(T1 poc1, T1 kraj, T2 poc2, T3 poc3, F1 f,F2 fun2){

int brojac=0;
int vrijednost;
sort(poc1,kraj,fun2);
auto kraj2 (poc2),pom1(poc1),pom2(kraj);
while(pom1!=pom2){kraj2++; pom1++; brojac++;}
sort(poc2,kraj2,fun2);
auto kraj3(poc3), pomoc1(poc1), pomoc2(kraj);
while (pomoc1!=pomoc2){kraj++; pomoc1++;}
auto x(poc1),y(poc2),z(poc3);
for(int i(0);i<brojac;i++){
	try{
		vrijednost=f(*x,*y);
		auto it=find(poc3,kraj3,vrijednost);
		x++;
		y++;
		if(it==kraj3)throw logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		*z=vrijednost;
		z++;
	}
	catch(const logic_error &e){
		cout<<"Vrijednost koja odgovara nekom od parova nije nadjena";
	}
}
}
bool postojiLi (vector<int>v,int unos){
	if(find(v.begin(),v.end(),unos)!=v.end())return true;
	return false;
}
int main ()
{
	vector<int>v1,v2,v3;
	int brojEl;
	int unos=-1000;
	cout<<"Unesi broj elemenata: ";
	cin>>brojEl;
	cout<<"Unesi elemente prvog vektora: ";
	for(int i(0);i<brojEl;i++){
		cin>>unos;
		while(postojiLi(v1,unos)){
			cin.clear();
			cin>>unos;
		}
		v1.push_back(unos);
	}
	cout<<endl;
		cout<<"Unesi elemente drugog vektora: ";
	for(int i(0);i<brojEl;i++){
		cin>>unos;
		while(postojiLi(v2,unos)){
			cin.clear();
			cin>>unos;
		}
		v2.push_back(unos);
	}
	cout<<endl;
		cout<<"Unesi elemente treceg vektora: ";
	for(int i(0);i<brojEl;i++){
		cin>>unos;
		while(postojiLi(v3,unos)){
			cin.clear();
			cin>>unos;
		}
		v3.push_back(unos);
	}
	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),f,zaUporedjivanje);
	
	return 0;
}