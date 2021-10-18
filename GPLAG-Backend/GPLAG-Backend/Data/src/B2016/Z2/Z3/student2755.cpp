/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>
int SumaDjelilaca(long long int broj) {
	int suma(0);
	if(broj<0) broj*=(-1);
	for(int i(1); i<=broj; i++) {
		if(broj%i==0) suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int broj) {
	std::vector<int> v;
	int k=2;
	while(broj>1) {
		if(broj%k==0) {
			v.push_back(k);
			broj/=k;
		}
		else k++;
	}
	return v.size();
}
int BrojSavrsenihDjelilaca(long long int broj) {
	std::vector<int> v;
	for(int i(2); i<=broj; i++) {
		if(broj%i==0) v.push_back(i);
	}
	std::vector<int> d;
	for(int i(0); i<v.size(); i++) {
		int n=v[i];
		int suma(0);
		for(int j(1); j<n; j++) {
			if(n%j==0) suma+=j;
		}
		if(suma==n) d.push_back(n);
	}
	return d.size();
}
int SumaCifara(long long int broj) {
	int suma(0);
	while(broj>0) {
		suma+=broj%10;
		broj/=10;
	}
	return suma;
}
template<typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
auto UvrnutiPresjek(IterTip1 p1, IterTip1 k1, IterTip2 p2, IterTip2 k2, Tip2 f(Tip1)) ->std::vector<std::vector<decltype(*p1+*p1)>>{
	std::vector<decltype(*p1+*p1)> pomocni;
	std::vector<std::vector<decltype(*p1+*p1)>> m;
	while(p1!=k1) {
		auto p(p2);
		while(p!=k2) {
			if(f(*p1)==f(*p)) {
				pomocni.push_back(*p1);
				pomocni.push_back(*p);
				pomocni.push_back(f(*p1));
				m.push_back(pomocni);
				pomocni.clear();
			}
			p++;
		}
		p1++;
	}
	std::vector<decltype(*p1+*p1)> *pok1=&m[0];
	std::vector<decltype(*p1+*p1)> *pok2=&m[m.size()];
	std::sort(pok1, pok2, [](std::vector<decltype(*p1+*p1)> x, std::vector<decltype(*p1+*p1)> y) ->bool {
		if(x[2]<y[2]) return true;
		else if(x[2]>y[2]) return false;
		else if(x[2]==y[2]) {
			if(x[0]<y[0]) return true;
			else if(x[0]>y[0]) return false;
			else if(x[0]==y[0]) 
				return x[1]<y[1];
		}
		return false;
	});
	return m;
}
template<typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
auto UvrnutaRazlika(IterTip1 p1, IterTip1 k1, IterTip2 p2, IterTip2 k2, Tip2 f(Tip1)) ->std::vector<std::vector<decltype(*p1+*p1)>>{        // vraca matricu nx2
	std::vector<decltype(*p1+*p1)>pomocni;
	std::vector<std::vector<decltype(*p1+*p1)>> m;
	auto pom1(p1);
	while(p1!=k1) {
		auto p(p2);
		bool nema(true);
		while(p!=k2) {
			if(f(*p1)==f(*p)) {
				nema=false;
			}
			if(nema==true && p==k2-1) {
				pomocni.push_back(*p1);
				pomocni.push_back(f(*p1));
				nema=true;
				break;
			}
			p++;
		}
		if(pomocni.size()) {
			m.push_back(pomocni);
			pomocni.clear();
		}
		p1++;
	}
	while(p2!=k2) {
		auto p(pom1);
		bool nema(true);
		while(p!=k1) {
			if(f(*p2)==f(*p)) {
				nema=false;
			}
			if(nema==true && p==k1-1) {
				pomocni.push_back(*p2);
				pomocni.push_back(f(*p2));
				nema=true;
				break;
			}
			p++;
		}
		if(pomocni.size()) {
			m.push_back(pomocni);
			pomocni.clear();
		}
		p2++;
	}
	std::vector<decltype(*p1+*p1)> *pok1=&m[0];
	std::vector<decltype(*p1+*p1)> *pok2=&m[m.size()];
	std::sort(pok1,pok2, [](std::vector<decltype(*p1+*p1)> x, std::vector<decltype(*p1+*p1)> y) -> bool{
		if(x[0]>y[0]) return true;
		else if(x[0]<y[0]) return false;
		else if(x[0]==y[0]) {
			if(x[1]>y[1]) return true;
			else if(x[1]<y[1]) return false;
		}
		return false;
	});
	return m;
}
int main (){
	std::deque<int> d1;
	std::deque<int> d2;
	int vel1, vel2;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> vel1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i(0); i<vel1; i++) {
		int n;
		bool moze(true);
		std::cin >> n;
		if(i==0) d1.push_back(n);
		for(int j(0); j<i; j++) {
			if(d1[j]==n) moze=false;
		}
		if(moze && i!=0) d1.push_back(n);
		else if(i!=0) i--;
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> vel2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i(0); i<vel2; i++) {
		int n;
		bool moze(true); 
		std::cin >> n;
		if(i==0) d2.push_back(n);
		for(int j(0); j<i; j++) {
			if(d2[j]==n) moze=false;
		}
		if(moze && i!=0) d2.push_back(n);
		else if(i!=0) i--;
	}
	std::cout << "Uvrnuti presjek kontejnera:\n";
	auto mat1(UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara));
	for(int i(0); i<mat1.size(); i++) {
		for(int j(0); j<mat1[i].size(); j++) {
			std::cout << std::setw(6) << mat1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:\n";
	auto mat2(UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora));
	for(int i(0); i<mat2.size(); i++) {
		for(int j(0); j<mat2[i].size(); j++) {
			std::cout << std::setw(6) << mat2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}