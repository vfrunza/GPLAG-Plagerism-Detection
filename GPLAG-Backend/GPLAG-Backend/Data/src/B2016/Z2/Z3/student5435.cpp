#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>

int SumaDjelilaca(long long int broj) {
	int suma(broj+1);
	for(int i=2; i<broj; i++) 
		if(broj%i==0) suma+=i;
	return suma;
}

bool DaLiJeProst(long long int broj) {
	for(int i=2; i<broj; i++) {
		if(broj%i==0) return false;
	}
	return true;
}

int BrojProstihFaktora(long long int broj) { //(y)
	int x(0);
	for(int i=2; i<broj+1; i++) {
		if(broj%i==0 && DaLiJeProst(i)) {
			x++;
			broj/=i;
			i=1;
		}
	}
	return x;
}

bool DaLiJeSavrsen(int broj) {
	int suma(0);
	for(int i=1; i<broj; i++) 
		if(broj%i==0) suma+=i;
	return suma==broj;
}

int BrojSavrsenihDjelilaca(long long int broj) {
	if(broj<6) return 0;
	int x(0);
	for(int i=2; i<=broj; i++) {
		if(DaLiJeSavrsen(i) && broj%i==0) x++;
	}
	return x;
}

int BrojCifara (int broj) {
	return int(std::log10(std::abs(broj))) +1;
}

template <typename Tip1, typename Tip2, typename funkcija>
std::vector<std::vector<int>> UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, funkcija f) {
	std::vector<std::vector<int>> v(0, std::vector<int> (3));
	Tip1 s1(p1);
	Tip2 s2(p3);
	while(s1!=p2) {
		s2=p3;
		while(s2!=p4) {
			int a(f(*s1));
			int b(f(*s2));
			if(a==b) {
				std::vector<int> pomocni { *s1, *s2, a } ;
				v.push_back(pomocni);
			}
			s2++;
		}
		s1++;
	}
	auto it1(v.begin());
	auto it2(v.end());
	std::sort(it1, it2, [] (std::vector<int> v1, std::vector<int> v2) { if(v1[2]==v2[2] && v1[1]==v2[2]) return v1[0]<v2[0];
																		if(v1[2]==v2[2]) return v1[1]<v2[1];
																		return v1[3]<v2[3]; });
	return v;
}

template <typename Tip1, typename Tip2>
std::vector<std::vector<int>> UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) {
	std::vector<std::vector<int>> v(0, std::vector<int> (3));
	Tip1 s1(p1);
	Tip2 s2(p3);
	while(s1!=p2) {
		s2=p3;
		while(s2!=p4) {
			if(*s1==*s2) {
				std::vector<int> pomocni { *s1, 0, 0 } ;
				v.push_back(pomocni);
			}
			s2++;
		}
		s1++;
	}
	auto it1(v.begin());
	auto it2(v.end());
	std::sort(it1, it2, [] (std::vector<int> v1, std::vector<int> v2) { return v1[0]<v2[0];});
	return v;
}

template <typename Tip1, typename Tip2, typename funkcija>
std::vector<std::vector<int>> UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, funkcija f) {
	std::vector<std::vector<int>> v(0, std::vector<int> (2));
	Tip1 s1(p1);
	Tip2 s2(p3);
	while(s1!=p2) {
		s2=p3;
		while(s2!=p4) {
			if(f(*s1)==f(*s2)) continue;
			std::vector<int> pomocni { *s1, f(*s1) } ;
			v.push_back(pomocni);
			s2++;
		}
		s1++;
	}
	auto it1(v.begin());
	auto it2(v.end());
	std::sort(it1, it2, [] (std::vector<int> v1, std::vector<int> v2) { if(v1[0]==v2[0]) return v1[1]<v2[1];
																		return v1[0]<v2[0]; });
	return v;
}

template <typename Tip1, typename Tip2>
std::vector<std::vector<int>> UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) {
	std::vector<std::vector<int>> v(0, std::vector<int> (2));
	Tip1 s1(p1);
	Tip2 s2(p3);
	while(s1!=p2) {
		s2=p3;
		while(s2!=p4) {
			if(BrojCifara(*s1)==BrojCifara(*s2)) continue;
			std::vector<int> pomocni { *s1, BrojCifara(*s1) } ;
			v.push_back(pomocni);
			s2++;
		}
		s1++;
	}
	auto it1(v.begin());
	auto it2(v.end());
	std::sort(it1, it2, [] (std::vector<int> v1, std::vector<int> v2) { if(v1[0]==v2[0]) return v1[1]<v2[1];
																		return v1[0]<v2[0]; });
	return v;
}


int main ()
{
/*	int n1, n2;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n1;
	std::deque<int> d1(n1);
	std::cout << "Unesite broj elemenata drugog kontejnera: "
*/
	std::deque<int> d1{6, 168, 28, 12}, d2{1, 28, 51, 6};
    std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojSavrsenihDjelilaca)};
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojSavrsenihDjelilaca)};
	
	for (std::vector<int>& red : v1)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	for (std::vector<int>& red : v2)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}

	return 0;
}