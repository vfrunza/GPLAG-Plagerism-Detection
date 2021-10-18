/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
#include <vector>
#include <type_traits>

int SumaCifara (long long int x) {
	int suma (0);
	while (x!=0) {
		suma+=x%10;
		x/=10;
	}
	return suma;
}

int SumaDjelilaca (long long int x) {
	int suma (0);
	for (int i=1; i<=abs(x); i++) {
		if (x%i==0) suma+=i;
	}
	//std::cout << suma;
	return suma;
}

int BrojProstihFaktora (long long int  x) {
	int brfakt (0);
	for (int i=2; i<=abs(x); i++) {
		if (x%i==0) {
			brfakt++;
			x/=i;
			//std::cout << i << " ";
			i--;
		}
	}
	return brfakt;
}

int BrojSavrsenihDjelilaca (long long int x) {
	int brdjel (0);
	for (int i=2; i<abs(x); i++) {
		if (x%i==0) {
			if (i==SumaDjelilaca(i)-i) {
				brdjel++;
				//std::cout << i << " ";
			}
		}
	}
	return brdjel;
}


template <typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
	std::vector<std::vector<Tip2>> UvrnutiPresjek (IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2, Tip1 fun(Tip2))  {
		std::vector<std::vector<Tip2>> v;
		
				for (int i=0; i<kraj1-poc1; i++) {
					for (int j=0; j<kraj2-poc2; j++) {
						if (fun(*(poc1+i))==fun(*(poc2+j))) {
							v.push_back(std::vector<Tip2> {*(poc1+i), *(poc2+j), fun(*(poc1+i))});
						}
					}
				}
			
		sort(v.begin(), v.end(), [](std::vector<Tip2> v1, std::vector<Tip2> v2) { if (v1[2]!=v2[2]) return v1[2]<v2[2]; else if (v1[0]!=v2[0]) return v1[0]<v2[0]; else return v1[1]<v2[1]; });
		return v;
	}
	
/*template <typename IterTip1, typename IterTip2>
	std::vector<std::vector<long long int>> UvrnutiPresjek (IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2)  {
		std::vector<std::vector<long long int>> v;
		for (int i=0; i<kraj1-poc1; i++) {
			for (int j=0; j<kraj2-poc2; j++) {
				if (*(poc1+i)==*(poc2+j)) 
					v.push_back(std::vector<long long int> {*(poc1+i), 0, 0});
			}
		}
		sort(v.begin(), v.end());
		return v;
	}*/
	
template <typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
	std::vector<std::vector<Tip2>> UvrnutaRazlika (IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2, Tip1 fun(Tip2))  {
		std::vector<std::vector<Tip2>> v;
		for (int i=0; i<kraj1-poc1; i++) {
			int j;
			for (j=0; j<kraj2-poc2; j++) {
				if (fun(*(poc1+i))==fun(*(poc2+j))) break;
			}			
			if (j==kraj2-poc2) v.push_back(std::vector<Tip2> {*(poc1+i), fun(*(poc1+i))});
		}
		for (int i=0; i<kraj2-poc2; i++) {
			int j;
			for (j=0; j<kraj1-poc1; j++) {
				if (fun(*(poc1+j))==fun(*(poc2+i))) break;
			}			
			if (j==kraj1-poc1) v.push_back(std::vector<Tip2> {*(poc2+i), fun(*(poc2+i))});
		}		
			
		sort(v.begin(), v.end(), [](std::vector<Tip2> v1, std::vector<Tip2> v2) { if (v1[0]!=v2[0]) return v1[0]>v2[0];  else return v1[1]>v2[1]; });
		return v;
	}
	

int main ()
{
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n1, n2;
	std::cin >> n1;
	std::deque <long long int> d1, d2;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for (int i=0; i<n1; i++) {
		int x;
		std::cin >> x;
		int j;
		for (j=0; j<i; j++) {
			if (x==d1[j]) break;
		}
		if (i==j) d1.push_back(x);
			else i--;
	}
	//std::cin.ignore(10000, '\n');
	/*for (int i=0; i<n1; i++) {   		//ispis
		std::cout << d1[i] << " ";
	}*/
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i=0; i<n2; i++) {
		int x;
		std::cin >> x;
		int j;
		for (j=0; j<i; j++) {
			if (x==d2[j]) break;
		}
		if (i==j)	d2.push_back(x);
			else i--;
	}
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	std::vector<std::vector<long long int>> v1 (UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara));
	//std::vector<std::vector<long long int>> v (UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end()));
	for (int i=0; i<v1.size(); i++) {
		std::cout << " ";
		for (int j=0; j<3; j++) {
			std::cout << v1[i][j] << "     ";
		}
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	std::vector<std::vector<long long int>> v2 (UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora));
	for (int i=0; i<v2.size(); i++) {
		std::cout << " ";
		for (int j=0; j<2; j++) {
			std::cout  << "   " << v2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}

/*int main_ () {
	std::deque<int> d1{15, 16, 17, 12, 13, 14}, d2{1, 5, 21, 51, 23};
 std::vector<std::vector<int>> v1(UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaDjelilaca));
	std::vector<std::vector<int>> v2(UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaDjelilaca));
	
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
}*/