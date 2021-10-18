/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>

using namespace std; 

int SumaCifara(long long int broj)
{	if(broj<0)
	broj=-broj;
	int sumaC(0);
	while(broj!=0)
	{
		sumaC+=broj%10;
		broj=broj/10;
	}
	return sumaC;
}
int SumaDjelilaca(long long int broj)
{	if(broj<0)
	broj=-broj;
	int sumaD(0);
	for(int i=0;i<=broj;i++)
	{
		if(broj%i==0)
		sumaD+=i;
	}
	return sumaD;
}

int BrojProstihFaktora(long long int broj)
{	int brojac(0);
	if(broj<0)
	broj=-broj;
	for(int i=2;i<=broj;i++)
	{
		while(broj%i==0)
		{
			broj=broj/i;
			brojac++;
		}
	}
	return brojac;
}
bool DaLiJeSavrsen(int broj)
{
	int suma(0);
	if(broj<0)
	broj=-broj;
	for(int i=1;i<broj;i++)
	{
		if(broj%i==0)
		suma+=i;
	}
	if(suma==broj)
	return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int broj)
{
	int brojac(0);
	if(broj<0)
	broj=-broj;
	for(int i=2;i<=broj;i++)
	{
		if(broj%i==0)
		{
			if(DaLiJeSavrsen(i))
			brojac++;
		}
	}return brojac;
}

vector<vector<int>> UvrnutiPresjek(int *p1, int *k1, int *p2, int *k2, int fun(long long int)){
	
	vector<vector<int>> matrica; 
	vector<int> temp; 
	while(p1!=k1){
		while(p2!=k2){
			if(fun(*p1)==fun(*p2)){
				temp.push_back(*p1); 
				temp.push_back(*p2); 
				temp.push_back(fun(*p2)); 
				matrica.push_back(temp); 
				temp.resize(0); 
			}
			p2++; 
		}
		p1++; 
	}
	
	
	return matrica; 
}

int main ()
{
	int broj; 
	cout << "Unesite broj elemenata prvog kontejnera: "; 
	int v1; 
	cin >> v1; 
	cout << "Unesite elemente prvog kontejnera: "; 
	deque<int> d1; 
	for(int i=0; i<v1; i++)
	{
		cin >> broj; 
		auto b=find(d1.begin(), d1.end(), broj); 
		if(b==d1.end()) d1.push_back(broj); 
		else 
		i--; 
	}
	cout << "Unesite elemente drugog kontejnera: "; 
	int v2;
	cin >> v2; 
	cout << "Unesite elemente drugog kontejnera: "; 
	deque<int> d2; 
	for(int i=0; i<v2; i++)
	{
		cin >> broj; 
		auto c=find(d2.begin(), d2.end(), broj); 
		if(c==d2.end()) d2.push_back(broj); 
		else 
		i--; 
	}
	cout << "Uvrnuti presjek kontejnera:" << endl; 
	auto presjek=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(). d2.end(), SumaCifara); 
	for(auto red:presjek)
	{
		for(auto x:red)
		{
			cout << setw(6) << x << " "; 
		}
		cout << endl; 
	}
	cout << "Uvrnuta razlika kontejnera:"
	return 0;
}