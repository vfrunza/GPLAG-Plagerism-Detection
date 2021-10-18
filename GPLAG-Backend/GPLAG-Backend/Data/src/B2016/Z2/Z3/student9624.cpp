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
using std::cout;
using std::cin;

template <typename cb1 = long long int>
bool JelProst (cb1 x) {
	for (int i = 2; i < x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}


template <typename cb1 = long long int, typename cb2 = int>
cb2 SumaDjelilaca(cb1 x){
	if (x<0) x = x*(-1);
	cb2 suma(0);
	for(int i=1; i<=x ; i++){
		if(x%i == 0) suma += i;
	}
	return suma;
}

template <typename cb1 = long long int, typename cb2 = int>
cb2 SumaCifara(cb1 x){
	if (x<0) x = x*(-1);
	cb2 suma(0);
	while(x != 0){
		 suma += x%10;
		 x = x/10;
	}
	return suma;
}

template <typename cijelibroj = long long int>
int BrojSavrsenihDjelilaca(cijelibroj x){
	int br(0);
	for(long long int i=1 ; i<=x ; i++) {
	if(SumaDjelilaca(i)-i == i && x%i == 0) br++;
	}
	return br;
}

int t = 0;
template <typename cb1 = int, typename cb2 = long long int> 
cb1 presjek (cb2 x) {
	t = 1;
	return x;
}



template <typename cb1 = long long int, typename cb2 = int>
cb2 BrojProstihFaktora (cb1 x) {
	cb2 suma(0);
	for (int i = 2; i <= x; i++) {
		int k = x;
		while (k%i == 0 && JelProst(i) == true) { suma++; k=k/i; }
	}
	return suma;
}

template < typename tip = int, typename iter1, typename iter2 ,typename tip1 = long long int>
auto UvrnutiPresjek(iter1 p1, iter1 k1, iter2 p2, iter2 k2, tip (*f)(tip1) = presjek) -> std::vector<std::vector< decltype(*p1+*p2)>> {
	
	iter1 t1(p1);
	iter1 t2(k1);
	iter2 t3(p2);
	iter2 t4(k2);

	int m(0);
	
	while (t1 != t2) {
		t3 = p2;
		while (t3 != t4) {
			if((*f)(*t1) == (*f)(*t3)) m++; 
			t3++;
		}
		t1++;
	}
	std::vector<std::vector< decltype(*p1-*p2)>> mat;
	mat.resize(m);
	t1 = p1;
	t3 = p2;
	m = 0;
	
	while (t1 != t2) {
		t3 = p2;
		while (t3 != t4) {
			if((*f)(*t1) == (*f)(*t3)) {
			mat[m].push_back(*t1);
			if(t == 0) mat[m].push_back(*t3);
			else mat[m].push_back(0);
			if(t == 0) mat[m].push_back((*f)(*t1));
			else mat[m].push_back(0);
			m++;
			}
			t3++;
		}
		t1++;
	}
	
	 std::sort(mat.begin(), mat.end(),  [] (std::vector<decltype(*p1-*p2)> x, std::vector<decltype(*p1-*p2)> y) {
		if ( x[2] != y[2] ) return x[2] < y[2];
		else if ( x[0] != y[0] ) return x[0] < y[0];
		else return x[1] < y[1];
		
	} ); 
	
	t = 0;
	return mat;
	
}




template < typename tip = int, typename iter1, typename iter2 ,typename tip1 = long long int>
auto UvrnutaRazlika(iter1 p1, iter1 k1, iter2 p2, iter2 k2, tip (*f)(tip1) = presjek) -> std::vector<std::vector< decltype(*p1+*p2)>> {
	
	iter1 t1(p1);
	iter1 t2(k1);
	iter2 t3(p2);
	iter2 t4(k2);

	int m(0);
	
	while (t1 != t2) {
		int h(0);
		t3 = p2;
		while (t3 != t4) {
			if((*f)(*t1) == (*f)(*t3)) { h = 1; break; }
			t3++;
		}
		if (h == 0) m++;
		t1++;
	}
	
	t1 = p1;
	t3 = p2;
	
	while (t3 != t4) {
		int h(0);
		t1 = p1;
		while (t1 != t2) {
			if((*f)(*t3) == (*f)(*t1)) { h = 1; break; }
			t1++;
		}
		if (h == 0) m++;
		t3++;
	}
	
	
	std::vector<std::vector< decltype(*p1-*p2)>> mat;
	mat.resize(m);
	t1 = p1;
	t3 = p2;
	m = 0;
	
	while (t1 != t2) {
		t3 = p2;
		int h(0);
		while (t3 != t4) {
			if((*f)(*t1) == (*f)(*t3)) { h = 1; break; }
			t3++;
		}
		if (h == 0) {
			mat[m].push_back(*t1);
			if(t == 0) mat[m].push_back((*f)(*t1));
			else  mat[m].push_back(0);
			m++;
		}
		t1++;
	}
	
	t1 = p1;
	t3 = p2;
	
	while (t3 != t4) {
		t1 = p1;
		int h(0);
		while (t1 != t2) {
			if((*f)(*t3) == (*f)(*t1)) { h = 1; break; }
			t1++;
		}
		if (h == 0) {
			mat[m].push_back(*t3);
			if(t == 0) mat[m].push_back((*f)(*t3));
			else  mat[m].push_back(0);
			m++;
		}
		t3++;
	}
	
	std::sort(mat.begin(), mat.end(),  [] (std::vector<decltype(*p1-*p2)> x, std::vector<decltype(*p1-*p2)> y) {
		if ( x[0] != y[0] ) return x[0] > y[0];
		else return x[1] > y[1];
		
	} );
	t = 0;
	return mat;
	
}





int main () {
	
	int a, b;
	std::deque<long long int> dek1;
	std::deque<long long int> dek2;
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> a;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i = 0; i < a; i++) {
		long long int x;
		std::cin>>x;
		int k = 0;
		for (int i = 0; i < dek1.size(); i++) {
			if(x == dek1[i]) k = 1;
		}
		if(k == 0) dek1.push_back(x);
		else i--;
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> b;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i = 0; i < b; i++) {
		long long int x;
		std::cin>>x;
		int k = 0;
		for (int i = 0; i < dek2.size(); i++) {
			if(x == dek2[i]) k = 1;
		}
		if(k == 0) dek2.push_back(x);
		else i--;
	}
	
	std::vector<std::vector<long long int>> dek3 = UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara);
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl; 
	for(int i = 0; i < dek3.size(); i++) {
		std::cout << std::setw(6) << dek3[i][0] << std::setw(7) << dek3[i][1] << std::setw(7) << dek3[i][2];
		std::cout << std::endl;
	}
	
	std::vector<std::vector<long long int>> dek4 = UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	
	std::cout << "Uvrnuta razlika kontejnera: " <<std::endl;
	for(int i = 0; i < dek4.size(); i++) {
		std::cout << std::setw(6) << dek4[i][0] << std::setw(7) << dek4[i][1];
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}