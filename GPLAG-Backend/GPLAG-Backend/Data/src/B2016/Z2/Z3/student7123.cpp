#include <iostream>
#include <iomanip>
#include <new>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <limits>


int uporedi(char* s1, char* s2) {
	while (*s1 != '\0' && *s2 != '\0') {
	if (*s1 < *s2) return -1;
	if (*s1 > *s2) return 1;
	s1++;
	s2++;
}
	if (*s1 != '\0') return 1;
	if (*s2 != '\0') return -1;
 	return 0;
}

int SumaCifara(int n) {
	int suma(0);
	if(n==0) return 0;
	
	while(n > 0) {
		suma+= n%10;
		n/=10;
	}
	return suma;
}

int BrojSavrsenihDjelilaca(long long int n) {
	int br(0);
	for(int i=1; i<=sqrt(n); i++) {
		if ((n%i==0) &&(SumaCifara(i) == i)) br++;
	}
	return br;
}

int SumaDjelilaca(long long int n) {
	int suma(0);
	for(int i=1; i<=sqrt(n); i++)
	if((n%i)==0) suma+=i;
	
	return suma;
}
template <typename IterTip1, typename IterTip2, typename FunTip>
std::vector<std::vector<int>> UvrnutiPresjek(IterTip1 p1, IterTip1 p2, IterTip2 q1, IterTip2 q2, FunTip f ) {
	std::vector<std::vector<int>> mat;
	std::vector<int> v;
	
	IterTip2 s1 = p1;
	IterTip1 s2 = q1;

	for(s1 = p1; s1 != p2; s1++) {
		for(s2 = q1; s2 != q2; s2++) {
				if(f(*s1) == f(*s2)) {
				v.push_back(*s1);
				v.push_back(*s2);
				v.push_back(f(*s1));
				mat.push_back(v);
				v.resize(0);
				
			}
		
		}
	}
	
	std::sort(std::begin(mat), std::end(mat), [](std::vector<decltype (mat[0][0]+0)> x, std::vector<decltype (mat[0][0]+0)> y) {
		if(x[2] != y[2]) return (x[2] < y[2]);
		else {
			if(x[0] != y[0]) return (x[0] < y[0]);
			else {
				return (x[1]<=y[1]);
			}
		}
	});
	
	return mat;
}

template <typename IterTip1, typename IterTip2, typename FunTip>
std::vector<std::vector<double>> UvrnutaRazlika(IterTip1 p1, IterTip1 p2, IterTip2 q1, IterTip2 q2, FunTip f) {

	std::vector<std::vector<double>> mat;
	std::vector<double> v;
	bool ima (false);
	
	IterTip2 s1 = p1;
	IterTip1 s2 = q1;

	for(s1 = p1; s1 != p2; s1++) {
		for(s2 = q1; s2 != q2; s2++) {
				if(f(*s1) == f(*s2)) {
				ima = true;
			}
		}
		if(!(ima)) {
			v.push_back(*s1);
			v.push_back(f(*s1));
			mat.push_back(v);
			v.resize(0);
		}
	}
	
		for(s1 = p1; s1 != p2; s1++) {
		for(s2 = q1; s2 != q2; s2++) {
				if(f(*s1) == f(*s2)) {
				ima = true;
			}
		}
		if(!(ima)) {
			v.push_back(*s1);
			v.push_back(f(*s1));
			mat.push_back(v);
			v.resize(0);
		}
	}
		for(s2 = q1; s2 != q2; s2++) {
		for(s1 = p1; s1 != p2; s1++) {
				if(f(*s2) == f(*s1)) {
				ima = true;
			}
		}
		if(!(ima)) {
			v.push_back(*s2);
			v.push_back(f(*s1));
			mat.push_back(v);
			v.resize(0);
		}
	}
	
	
	
	return mat;
}
int main () {
	
 	int n, n1;
	std::deque<double> v1, v2;
	std::deque<double>::iterator it1=v1.begin(), it2;
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n;
	std::cout <<"Unesite elemente prvog kontejnera: ";
	int br1(0);
	
		while(br1<n){
		bool ima (false);
		int a;
		std::cin >> a;

		for(it1 = v1.begin(); it1 != v1.end(); it1++) {
			if(*it1 == a) {ima = true;
				n--;
			}
		}
		
		if(!(ima)) {
		v1.push_back(a);
		br1++;
}
	}

	
	std::cout <<"Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n1;
	std::cout <<"Unesite elemente drugog kontejnera: ";
		br1=0;
		while(br1<n){
		bool ima (false);
		int a;
		std::cin >> a;
		for(it2 = v2.begin(); it2 != v2.end(); it2++) {
			if(*it2 == a) { ima = true;
			n1--;
	
			}
		}
		
		if(!(ima)) {
		v2.push_back(a);
		br1++;
}
	}
	
	auto mat = UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), SumaCifara);
	
	std::cout << "Uvrnuti presjek kontejnera: \n";
	
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<3; j++) std::cout << std::setw(6)<< mat[i][j] ;
		std::cout << std::endl;
	}
	
	std::cout << "Uvrnuta razlika kontejnera: \n";
	
	auto mat1 = UvrnutaRazlika(v1.begin(), v1.end(), v2.begin(), v2.end(), SumaCifara);
	for(int i=0; i<mat1.size(); i++) {
		for(int j=0; j<2; j++) std::cout << std::setw(6)<< mat[i][j] ;
		std::cout << std::endl;
	}

	return 0;
}