/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

int SumaDjelilaca (long long int a) {
	
	int suma(0);
	long long int b; 
	b=a; 
	
	while (b!=0) {
		
		if (a%b==0) 
		suma+=b; 
		b--;
	}
	return suma;
}

int BrojProstihFaktora (long long int a) {
	
	int b(9); 
	int brojac(0); 
	
	while (b!=1) {
		if (a%b==0) 
		brojac++; 
		b--;
	}
	
	return brojac; 
}

int BrojSavrsenihDjelilaca (long long int a) {
	
	long long int b; 
	b=a; 
	int faktor; 
	int brojac(0); 
	
	while (b!=0) {
		if (a%b==0) {
		faktor=b; 
		
		int faktor1; 
		faktor1=(faktor-1); 
		int suma(0); 
		while (faktor1!=0) {
			
			if (faktor%faktor1==0) 
			suma+=faktor1; 
			
			faktor1--; 
		}
		
		if (suma==faktor) brojac++; 
		}
		b--; 
	}
	
	return brojac; 
}

template <typename IterTip1, typename IterTip2, typename Tip, typename Tipp> 
auto UvrnutiPresjek(IterTip1 p1, IterTip1 p2, IterTip2 p3, IterTip2 p4, Tip f(Tipp)) -> std::vector<std::vector<decltype(p1[0])>> {
	
	std::vector<IterTip1> mat; 
	
	mat.resize(3); 
	
	IterTip1 p(p1); 
	IterTip2 pp(p3); 
	
	while (p!=p2) {
		
		while (pp!=p4) {
			
			if (f(*p)==f(*pp)) {
				mat.push_back(*p); 
				mat.push_back(*pp); 
				mat.push_back(f(*p)); 
				
				for (int i=1; i<=1; i++) 
				mat[i].resize(i); 
			}
			
			pp++;
		}
		
		p++;
	}
	
	sort (mat.begin(), mat.end(), [](int x, int y) { return x>y;}); 
	
	return mat; 
}

/*template <typename Tip1, typename Tip2, typename Tip>
std::vector<std::vector<Tip1>> UvrnutaRazlika (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip f(Tip)) {
	
	std::vector<std::vector<Tip1> mat; 
	mat.resize(2); 
	
	Tip1 p(p1); 
	Tip2 pp(p3); 
	
	while (p!=p2) {
		while (pp!=p4) {
			
			if (f(*p)==f(*pp)) break; 
			else {
				mat.push_back(*p);
				mat.push_back(f(*p)); 
			}
			pp++; 
		}
		p++;
	}
	
	while (pp!=p4) {
		while (p!=p2) {
			
			if (f(*pp)==f(*p)) break; 
			else {
				mat.push_back(*pp); 
				mat.push_back(f(*p)); 
			}
			p++;
		}
		pp++;
	}
	
	sort (mat.begin(), mat.end(), [](int x) {return f(x); }); 
	
	return mat; 
}
*/

int main ()
{
	std::cout << "Unesite broj elemenata prvog kontejnera: "; 
	int n; 
	std::deque<long long int> d(n); 
	std::cout << "Unesite elemente prvog kontejnera: "; 
	for (long long int &x:d) {
		std::cin >> x; 
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: "; 
	int m; 
	std::deque<long long int> d1(m); 
	std::cout << "Unesite elemente drugog kontejnera: "; 
	for (long long int &x:d1) {
		std::cin >> x; 
	}
	
	std::cout << "Uvrnuti presjek kontejnera: "; 
	std::deque<std::deque<long long int>>mat(UvrnutiPresjek(d.begin(), d.end(), d1.begin(), d1.end(), SumaDjelilaca)); 
	
	for (int i=0; i<3; i++) {
		for (int j=0; j<mat[i].size(); j++) {
			std::cout << mat[i][j] << " "; 
		}
		std::cout << std::endl; 
	}
	
/*	std::cout << "Uvrnuta razlika kontejnera: "; 
	std::deque<std::deque<int>> mat1; 
	mat1=UvrnutaRazlika(d.begin(), d.end(), d1.begin(), d1.end(), BrojProstihFaktora); 
	
	for (int i=0; i<2; i++) {
		for (int j=0; j<mat[i].size(); j++) {
			std::cout << mat[i][j] << " "; 
		}
		std::cout << std::endl; 
	}*/
	return 0;
}