/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iterator>
#include <type_traits>
#include <iomanip>
#include <deque>

int SumaCifara(int x) {
	int suma(0);
		while(x!=0) {
			suma+=abs(x%10);
			x/=10;
	}
	return suma;
}

template <typename Tip1, typename Tip2, typename Ftip1, typename Ftip2>
	auto UvrnutiPresjek(Tip1 p1, Tip1 k1, Tip2 p2, Tip2 k2, Ftip1 fun(Ftip2 x)) -> std::vector<std::vector<Ftip1>>{
	std::vector<std::vector<Ftip1>> mat;
	int i(0);
	while(p1 != k1) {
		Tip2 pok(p2);
		while(pok != k2) {
			if(fun(*p1) == fun(*pok)) {
				std::vector<Ftip1> tmp;
				mat.push_back(tmp);
				mat[i].push_back(*p1);
				mat[i].push_back(*pok);
				mat[i].push_back(fun(*p1));
				i++;
			}
			pok++;
		}
		p1++;
	}
	std::sort(mat.begin(), mat.end(), [](std::vector<Ftip1> x, std::vector<Ftip1> y) {
		if (x[2] < y[2])
			return true;
		if(x[2] == y[2] && x[0] < y[0])
			return true;
		if(x[2] == y[2] && x[0] == y[0] && x[1] < y[1])
			return true;
		return false;
	});
	return mat;
}

template <typename Tip1, typename Tip2>
	auto UvrnutiPresjek(Tip1 p1, Tip1 k1, Tip2 p2, Tip2 k2) -> typename std::vector<std::vector<decltype(*p1+*p1)>> {
		std::vector<std::vector<decltype(*p1+*p1)>> mat;
		int i(0);
		while(p1 != k1) {
		Tip2 pok(p2);
		while(pok != k2) {
			if(*p1 == *pok) {
				std::vector<decltype(*p1+*p1)> tmp;
				tmp.push_back(*p1);
				tmp.push_back(0);
				tmp.push_back(0);
				mat.push_back(tmp);
			}
			pok++;
		}
		p1++;
	}
	std::sort(mat.begin(), mat.end(), [](std::vector<decltype(*p1+*p1)> x,std::vector<decltype(*p1+*p1)> y) {return x[0] < y[0];});
	return mat;
}

template <typename Tip1, typename Tip2, typename Ftip1, typename Ftip2>
	auto UvrnutaRazlika(Tip1 p1, Tip1 k1, Tip2 p2, Tip2 k2, Ftip1 fun(Ftip2 x)) -> std::vector<std::vector<Ftip1>> {
		std::vector<std::vector<Ftip1>> mat;
		Tip1 p1_tmp(p1);
		while(p1 != k1) {
			Tip2 pok(p2);
			bool ubaci(true);
			while(pok != k2) {
				if(fun(*p1) == fun(*pok)) {
					ubaci = false;
					break;
				}
			pok++;
			}
			if(ubaci) {
				std::vector<decltype(*p1+*p1)> tmp;
				tmp.push_back(*p1);
				tmp.push_back(fun(*p1));
				mat.push_back(tmp);
			}
		p1++;
	}
	p1 = p1_tmp;
	while(p2 != k2) {
		Tip2 pok(p1);
		bool ubaci(true);
		while(pok != k1) {
			if(fun(*p2) == fun(*pok)) {
				ubaci = false;
				break;
			}
		pok++;
		}
		if(ubaci) {
			std::vector<decltype(*p1+*p1)> tmp;
			tmp.push_back(*p2);
			tmp.push_back(fun(*p2));
			mat.push_back(tmp);
		}
	p2++;
	}
	std::sort(mat.begin(), mat.end(), [](std::vector<Ftip1> x, std::vector<Ftip1> y) {
		if(x[0]>y[0])
			return true;
		if(x[0] == y[0] && x[1] > y[1])
			return true;
		return false;
	});
	return mat;
}

template <typename Tip1, typename Tip2>
	auto UvrnutaRazlika(Tip1 p1, Tip1 k1, Tip2 p2, Tip2 k2) -> typename std::vector<std::vector<decltype(*p1+*p1)>> {
		Tip1 p1_tmp(p1);
		std::vector<std::vector<decltype(*p1+*p1)>> mat;
		while(p1 != k1) {
			Tip2 pok(p2);
			bool ubaci(true);
			while(pok != k2) {
				if(*p1 == *pok) {
					ubaci = false;
					break;
				}
			pok++;
			}
			if(ubaci) {
				std::vector<decltype(*p1+*p1)> tmp;
				tmp.push_back(*p1);
				tmp.push_back(0);
				mat.push_back(tmp);
			}
		p1++;
	}
	p1 = p1_tmp;
	while(p2 != k2) {
		Tip2 pok(p1);
		bool ubaci(true);
		while(pok != k1) {
			if(*p2 == *pok) {
				ubaci = false;
				break;
			}
		pok++;
		}
		if(ubaci) {
			std::vector<decltype(*p1+*p1)> tmp;
			tmp.push_back(*p2);
			tmp.push_back(0);
			mat.push_back(tmp);
		}
	p2++;
	}
	std::sort(mat.begin(), mat.end(), [](std::vector<decltype(*p1+*p1)> x, std::vector<decltype(*p1+*p1)> y) {return x[0] > y[0];});
	return mat;
}

bool JeLiProst(long long int x) {
	double korijen(std::sqrt(std::abs(x)));
	for(int i=2; i<=korijen; i++)
		if(x%i == 0)
			return false;
	return true;
} 

int SumaDjelilaca(long long int x) {
	int suma(0);
	if(x>0)
		for(int i=1; i<=x; i++)
			if(x%i == 0)
				suma+=i;
	if(x<0)
		for(int i=x; i<=-1; i++)
			if(x%i == 0) 
				suma+=-i;
	return suma;
}

int BrojProstihFaktora(long long int x) {
	int brojac(0);
	if(x>0)
		for(int i=2; i<=x; i++) {
			if(x%i == 0) {
				if(JeLiProst(i)) {
					brojac++;
					x/=i;
					i--;
				}
			}
		}
	if(x<0)
		for(int i=x; i<=-2; i++) {
			if(x%i == 0) {
				if(JeLiProst(-i)) {
					brojac++;
					x/=i;
					i++;
				}
			}
		}
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int x) {
	if (x<0) 
		x = -x;
	int brojac(0);
	for(int i=2; i<=x; i++) 
		if(x%i == 0 && i == SumaDjelilaca(i)-i)
			brojac++;
	return brojac;
}

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int a;
	std::cin>>a;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::vector<int> v1(a);
	for(int i=0; i<a; i++) {
		int tmp;
		std::cin>>tmp;
		bool ubaci(true);
		for(int j=0; j<v1.size(); j++) {
			if (tmp==v1[j]) {
				ubaci = false;
				break;
			}
		}
		if(ubaci)
			v1[i] = tmp;
		else i--;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>a;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::vector<int> v2(a);
	for(int i=0; i<a; i++) {
		int tmp;
		std::cin>>tmp;
		bool ubaci(true);
		for(int j=0; j<v2.size(); j++) {
			if (tmp==v2[j]) {
				ubaci = false;
				break;
			}
		}
		if(ubaci)
			v2[i] = tmp;
		else i--;
	}
	auto mat(UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), SumaCifara));
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[i].size(); j++)
			std::cout<<std::setw(6)<<mat[i][j]<<" ";
		std::cout<<std::endl;
	}
	auto mat2(UvrnutaRazlika(v1.begin(), v1.end(), v2.begin(), v2.end(), BrojProstihFaktora));
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i=0; i<mat2.size(); i++) {
		for(int j=0; j<mat2[i].size(); j++)
			std::cout<<std::setw(6)<<mat2[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}