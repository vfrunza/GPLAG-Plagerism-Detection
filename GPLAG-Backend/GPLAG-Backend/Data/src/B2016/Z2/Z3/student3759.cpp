/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>

using namespace std;

template <typename IterTip1, typename IterTip2, typename TipF1>

auto UvrnutiPresjek(IterTip1 pok1, IterTip1 pok2, IterTip2 pok3, IterTip2 pok4, TipF1 f) -> typename vector<vector<decltype(*pok1)>>{
	/*decltype(pok1) pom1 = pok1;
	decltype(pok3) pom3 = pok3;*/
	auto pom1 = pok1;
	auto pom3 = pok3;
	
	vector<vector<int>>mat(3);
	int i = 0, brojacREDOVA(0);
	while(pom1!=pok2){
		if(f(*pom1)==f(*pom3)){
			mat[i].push_back(*pom1);//WHAT THE FUCK IS YOUR PROBLEM PLEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEB:>
			mat[i].push_back(*pom3);
			mat[i].push_back(f(*pom1));
			brojacREDOVA++;
			i++;
		}
		pom1++;pom3++;
		/*if(brojacREDOVA==2){
			i++;
			brojacREDOVA=0;
		}*/
	}
	/*while (pom1 != pok2){
		while (pom3 != pok4) {
			if (funkcija(*pom1) == funkcija(*pom3)) {
				mat.push_back(*pom3);
				i++;
			}
			pom3++;
		}
		pom1++;
	}*/
	return mat;
}

int main ()
{
	
	vector<int> v1={12,22,34,45,51};
	vector<int> v2={21,31,32,11,60};
	vector<vector<int>> mat;
	mat= UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), [] (int x) {int f(x); int suma(0); while(f!=0){suma=suma+f%10;f=f/10;}return suma;});
	
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<5;i++){
		cout<<v1[i]<<",,,"<<v2[i];
	}
	
	return 0;
}