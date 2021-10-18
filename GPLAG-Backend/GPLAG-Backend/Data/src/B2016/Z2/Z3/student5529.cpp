/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
using std::deque;
int SumaDjelilaca(int n){
	int suma=0;
	for(int i=1; i<n; i++){
		if(n%i==0) suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(int n){
	int br=0;
	for(int i=2; i<n; i++){
		if(n%i==0) br++;
	}
	return br++;
}


//template <typename Tip1, typename Tip2> 
int main ()
{
	int n1,n2,x1,x2;
	deque<int> v1;
	deque<int> v2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	v1.resize(n1);
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0; i<v1.size(); i++)
		std::cin>>x1;
		v1.push_back(x1);
		
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	v2.resize(n2);
	std::cout<<"Unesite elemente drugog kontejnera ";
	for(int i=0; i<v2.size(); i++)
		std::cin>>x2;
		v2.push_back(x2);

	return 0;
}