/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iomanip>
template <typename tip1, typename tip2>
std::deque<std::deque <int>> UvrnutiPresjek(tip1 poc, tip1 kraj, tip2 odred, tip2 kraj2, int fun(int) )
{ std::deque<std::deque<int>> mat;
	int i(0);
		while(poc!=kraj){
			int broj(0);
			odred=odred-broj;
			while(odred!=kraj2){
				if(fun(*odred)==fun(*poc))
				{
			     mat[i].push_back(*poc);
			     mat[i].push_back(*odred);
			     mat[i].push_back(fun(*poc));
				i++;
				break;
				}
				odred++;
				broj++;
			}
			poc++;
		}
		std::sort(mat.begin(),mat.end(),[](tip1 ))
		return mat;
}
int main ()
{
	int broj1,broj2;
	std::deque<std::deque<int>> mat;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>broj1;
	std::deque<int> d1(broj1);
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<d1.size();i++)
	{
		std::cin>>d1[i];
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>broj2;
	std::deque<int> d2(broj2);
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<d2.size();i++){
		std::cin>>d2[i];
	}
	mat=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),[](int x){
	int suma(0);
		while(x>0){
			suma=x%10+suma;
			x/=10;
		}
		return suma;
	});
	std::cout<<"Uvrnuti presjek kontejnera: ";
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
			std::cout<<mat[i][j]<<std::setw(6);
		}
		std::cout<<std::endl;
	}
	
	
	std::cout<<"Dovidjenja!";
	return 0;
}