/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: vector;
using std:: deque;

int SumaDjelilaca (long long int broj)
{
	int suma(0);
	for(int i=1; i<=broj; i++)
	{
		if(broj%i==0) suma+=i;
	}
	return suma;
}

bool DaLiJeProst(long long int broj) {
	if(broj==2) return true;
	int granica = sqrt(broj);
	for(int i=2;i<granica;i++)
		if(broj%i == 0)
			return false;
	return true;
}

int BrojProstihFaktora (long long int broj)
{
	int brojac=0;
	if(broj == 1 ) return 1;
	else {
		while(broj%2==0) {
			brojac++;
			broj/=2;
		}
		for(int i=3;i<=broj;i++) {
			while(broj%i==0) {
				brojac++;
				broj/=i;
			}
		}
	}
	return brojac;
}

bool DaLiJeSavrsen(long long int x) {
	int suma = 0;
	for(int i(1);i<x;i++)
		if(x%i==0)
			suma+=i;
	if(suma==x) return true;
	return false;
}

int BrojSavrsenihDjelilaca (long long int broj)
{
	std::vector<long long int> djelioci;
	for(int i(1);i<=broj;i++)
		if(broj%i==0)
			djelioci.push_back(i);
	int rezultat =0;
	for(auto broj1 : djelioci) {
		if(DaLiJeSavrsen(broj1))
			rezultat++;
	}
	return rezultat;
}

template<typename Tip1, typename Tip2>
Tip1 ObicniPresjek(Tip2 x) {
	return x;
}

int SumaCifara(long long int x) {
	int i = 0;
	while(x!=0) {
		i+=x%10;
		x/=10;
	}
	return i;
}


template<typename Tip1, typename Tip2, typename T1, typename T2>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, T1 funkcija(T2) = nullptr) ->
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> povratna;
	Tip1 tmp = p1;
	Tip2 tmp2 = p3;
	std::vector<typename std::remove_reference<decltype(*p1)>::type> pomocni_vektor;
	if(!funkcija) {
		while(tmp!=p2) {
			tmp2 = p3;
			while(tmp2!=p4) {
				if(*tmp == *tmp2) {
					pomocni_vektor.resize(0);
					pomocni_vektor.push_back(*tmp);
					pomocni_vektor.push_back(0);
					pomocni_vektor.push_back(0);
					povratna.push_back(pomocni_vektor);
				}
				tmp2++;
			}
			tmp++;
		}	
	}
	else {
		tmp = p1;
		tmp2 = p3;
		while(tmp!=p2) {
			tmp2 = p3;
			while(tmp2!=p4) {
				if(funkcija(*tmp) == funkcija(*tmp2)) {
					pomocni_vektor.resize(0);
					pomocni_vektor.push_back(*tmp);
					pomocni_vektor.push_back(*tmp2);
					pomocni_vektor.push_back(funkcija(*tmp));
					povratna.push_back(pomocni_vektor);
				}
				++tmp2;
			}
			++tmp;
		}
	}
	std::sort(povratna.begin(), povratna.end(),
	[funkcija] (std::vector<typename std::remove_reference<decltype(*p1)>::type> a, std::vector<typename std::remove_reference<decltype(*p1)>::type> b) {
		if(a[2]<b[2])
			return true;
		else if(a[2]>b[2])
			return false;
		else if(a[0]<b[0])
			return true;
		else if(a[0]>b[0])
			return false;
		else if(a[1]<b[1])
			return true;
		else return false;
	});
	return povratna;	
}

template<typename Tip1, typename Tip2, typename T1, typename T2>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, T1 funkcija(T2) = nullptr) ->
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> {
	
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> povratna;
	Tip1 tmp = p1;
	Tip2 tmp2 = p3;
	std::vector<typename std::remove_reference<decltype(*p1)>::type> pomocni_vektor;
	if(!funkcija) {
		while(tmp!=p2) {
			bool ima = false;
			tmp2 = p3;
			while(tmp2!=p4) {
				if(*tmp==*tmp2)
					ima=true;
				tmp2++;
			}
			if(!ima) {
				pomocni_vektor.resize(0);
				pomocni_vektor.push_back(*tmp);
				pomocni_vektor.push_back(0);
				povratna.push_back(pomocni_vektor);
			}
			tmp++;
		}
		tmp=p1;
		tmp2=p3;
		while(tmp2!=p4) {
			bool ima = false;
			tmp = p1;
			while(tmp!=p2) {
				if(*tmp==*tmp2)
					ima = true;
				tmp++;
			}
			if(!ima) {
				pomocni_vektor.resize(0);
				pomocni_vektor.push_back(*tmp2);
				pomocni_vektor.push_back(0);
				povratna.push_back(pomocni_vektor);
			}
			tmp2++;
		}
	}
	else {
		while(tmp!=p2) {
			bool ima = false;
			tmp2 = p3;
			while(tmp2!=p4) {
				if(funkcija(*tmp) == funkcija(*tmp2))
					ima = true;
				tmp2++;
			}
			if(!ima) {
				pomocni_vektor.resize(0);
				pomocni_vektor.push_back(*tmp);
				pomocni_vektor.push_back(funkcija(*tmp));
				povratna.push_back(pomocni_vektor);
			}
			tmp++;
		}
		tmp=p1;
		tmp2=p3;
		while(tmp2!=p4) {
			bool ima = false;
			tmp = p1;
			while(tmp!=p2) {
				if(funkcija(*tmp)==funkcija(*tmp2))
					ima = true;
				tmp++;
			}
			if(!ima) {
				pomocni_vektor.resize(0);
				pomocni_vektor.push_back(*tmp2);
				pomocni_vektor.push_back(funkcija(*tmp2));
				povratna.push_back(pomocni_vektor);
			}
			tmp2++;
		}
	}
	std::sort(povratna.begin(), povratna.end(),
	 [] (std::vector<typename std::remove_reference<decltype(*p1)>::type> a, std::vector<typename std::remove_reference<decltype(*p1)>::type> b) {
	 	if(a[0]>b[0]) return true;
	 	else if(a[0]<b[0]) return false;
	 	else if(a[1]>b[1]) return true;
	 	else return false;
	 	
	 });
	 return povratna;
}


int main ()
{
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int brel1;
	cin>>brel1;
	deque<int>dek1;
	int element1;
	int i=0;
	cout<<"Unesite elemente prvog kontejnera: ";
	for(;;)
	{
		cin>>element1;
		bool ima = false;
		for(int j=0; j<dek1.size(); j++)
		{
			if(element1==dek1[j]) ima=true;
		}
		if(ima==false) {
			dek1.push_back(element1);
			i++;
			if(i==brel1) break;
		}
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int brel2;
	cin>>brel2;
	deque<int>dek2;
	int element2;
	i=0;
	cout<<"Unesite elemente drugog kontejnera: ";
	for(;;)
	{
		cin>>element2;
		bool ima=false;
		for(int j=0; j<dek2.size(); j++)
		{
			if(element2==dek2[j]) ima=true;
		}
		if(ima==false) {
			dek2.push_back(element2);
			i++;
			if(i==brel2) break;
		}
	}
	auto presjek = UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara);
	auto razlika = UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	for(auto x : presjek) {
		for(auto y : x) {
			cout<<std::setw(6)<<y<<" ";
		}
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	for(auto x : razlika) {
		for(auto y : x) {
			cout<<std::setw(6)<<y<<" ";
		}
		cout<<endl;
	}
	cout<<"Dovidjenja!"<<endl;
	return 0;
}