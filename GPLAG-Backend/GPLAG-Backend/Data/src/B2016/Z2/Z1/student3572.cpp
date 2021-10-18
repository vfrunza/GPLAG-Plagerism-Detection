/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
int main ()
{
	std::vector<int> a;
	std::vector<std::vector<int>> mine;
	std::cout<<"Unesite pozicije mina: ";
	int x;
	do{
	for(int i=0;i<2;i++){
		std::cin>>x;
		a.push_back(x);
		}
	mine.push_back(a);
	} while(x!=0);
	
	for(int i=0;i<mine.size();i++){
		for(int j=0;j<mine[i].size();j++){
		std::cout<<mine[i][j]<<" ";
	}
	}
	return 0;
}