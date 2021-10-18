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
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

template <typename tip>
bool f(tip p, int x, int br){
	
	for(int i = 0 ; i < br - 1; i++)
		if(x == p[i]) return true;
	
	return false;
}

template<typename Tip>
int BrojProstihFaktora(Tip x){
	
	int br(0);
	
	for(int i = 1; i <= x ; i++){
		
		if(x % i == 0)
			br++;
	
	}
	
	
	
	return br;
	
}

template <typename tip>
bool FUN(tip a, tip b){
	
	//cout<<a<<": "<<BrojProstihFaktora(a)<<" "<<b<<": "<<BrojProstihFaktora(b)<<endl;
	
	if(BrojProstihFaktora(a) == BrojProstihFaktora(b)) return a > b;
	
	return BrojProstihFaktora(a) > BrojProstihFaktora(b);
	
}

template <typename tip1, typename tip2>
int fun(tip1 a, tip2 b){					//ISPRAVITI TIP FUNKCIJE
	
	return -2*a + b;
	
}

template <typename Tip1, typename Tip2, typename Tip3> 
auto SortirajPodrucjeVrijednosti(Tip1 poc_1, Tip2 kraj_1, Tip2 poc_2, Tip3 poc_3, decltype(*poc_3 + *poc_3) fun (decltype(*poc_1 + *poc_1), decltype(*poc_2 + *poc_2)), bool FUN(decltype(*poc_1 + *poc_1), decltype(*poc_2 + *poc_2)) ) -> decltype(poc_3){
	
	int vel(kraj_1 - poc_1);
	
	sort(poc_1, kraj_1, FUN);
	
	sort(poc_2, poc_2 + vel, FUN);
	
	bool a;
	
	for(int i = 0; i < vel; i++){
		
		a=false;
		
		for(int j = 0; j < vel; j++)
			if(fun(poc_1[i], poc_2[i]) == poc_3[j]) { 
				
				a=true; 
				
				decltype(*poc_3 + *poc_3) temp;
				
				temp = poc_3[i];
				
				poc_3[i] = poc_3[j];
				
				poc_3[j] = temp;
				
				break; 
	
			}
			
		if(a == false) throw logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
	
	return poc_3;
	
		
}


int main ()
{
	
	try{
		
	int n;
	
	cout<<"Unesite broj elemenata: ";

	cin>>n;
	
	vector<int> v1(n), v2(n), v(n);
	
	cout<<"Unesite elemente prvog vektora: ";
	
	int br (0);
	
	for(auto &x : v1) {
		cin>>x; 
		
		br++;
		
		bool a;
		
		do{
			
			a =f(v1.begin(), x, br);
			
			if(a == true) cin>>x;
		
		}while(a == true);
	}	
	cout<<"Unesite elemente drugog vektora: ";
	
	br=0;
	
	for(auto &x : v2)  {
		
		cin>>x; 
		
		br++;
		
		bool a;
		
		do{
			
			a =f(v2.begin(), x, br);
			
			if(a == true) cin>>x;
		
		}while(a == true);
	}	
	
	cout<<"Unesite elemente treceg vektora: ";
	
	br=0;
	
	for(auto &x : v)  {
		cin>>x; 
		
		br++;
		
		bool a;
		
		do{ 
			
			a =f(v.begin(), x, br);
			
			if(a == true) cin>>x;
		
		}while(a == true);
	}	
	
	cout<<endl;
	
	SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v.begin(),fun,FUN);
	
	cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<endl;
	
	for(int i = 0; i < n; i++)
		cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v[i]<<endl;
	}
	catch(logic_error e){
		cout<<"Izuzetak: "<<e.what()<<endl;
	}
	
	return 0;
}










