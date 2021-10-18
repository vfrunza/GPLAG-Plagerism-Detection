/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <iostream>
#include <deque>
#include <iomanip>
#include <algorithm>
#include <type_traits>
#include <vector>

int SumaCifara(int n)
{
	int suma(0);
	while(n!=0) {
		int c(std::abs(n%10));
		suma+=c;
		n/=10;
	}
	return suma;
}

int SumaDjelilaca(long long int n)
{
	n=std::abs(n);
	int suma(0);
	for(long long int i(1); i<=n; i++) {
		if(n%i==0)
			suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int n)
{
	n=std::abs(n);
	long long int temp(n);
	int brojac(0);
	for(long long int i(2); i<=temp; i++) {
		while(temp%i==0) {
			brojac++;
			temp/=i;
			if(temp==1) break;
		}
	}
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int n) {
	int brojac(0);
	n=std::abs(n);
	for(long long int i(1); i<=n; i++) {
		if(n%i==0) {
			int suma(0);
			for(int j(1);j<i;j++) {
				if(i%j==0) {
					suma+=j;
				}
			}
			if(i==suma) brojac++;
		}
	}
	return brojac;
}


template <typename ItiliPok1, typename ItiliPok2>

auto UvrnutiPresjek(ItiliPok1 p1, ItiliPok1 p2, ItiliPok2 p3, ItiliPok2 p4)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	int brojac(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	while(p1!=p2) {
		ItiliPok2 pok(p3);
		while(pok!=p4) {
			if(*p1==*pok) {
				brojac++;
				Matrica.resize(brojac);
				Matrica.at(brojac-1).resize(3);
				Matrica.at(brojac-1).at(0)=*p1;
				Matrica.at(brojac-1).at(1)=0;
				Matrica.at(brojac-1).at(2)=0;

			}
			pok++;
		}
		p1++;
	}
	std::sort(std::begin(Matrica), std::end(Matrica), [] (typename std::remove_reference<decltype(*std::begin(Matrica))>::type x1, typename std::remove_reference<decltype(*std::begin(Matrica))>::type x2) {
		return x1.at(0)<x2.at(0);
	});
	return Matrica;
}



template <typename ItiliPok1, typename ItiliPok2, typename Tip2, typename Tip3>

auto UvrnutiPresjek(ItiliPok1 p1, ItiliPok1 p2, ItiliPok2 p3, ItiliPok2 p4, Tip2 (*fun) (Tip3))->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	int brojac(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	while(p1!=p2) {
		ItiliPok2 pok(p3);
		while(pok!=p4) {
			if(fun(*p1)==fun(*pok)) {

				brojac++;
				Matrica.resize(brojac);
				Matrica.at(brojac-1).resize(3);
				Matrica.at(brojac-1).at(0)=*p1;
				Matrica.at(brojac-1).at(1)=*pok;
				Matrica.at(brojac-1).at(2)=fun(*p1);

			}
			pok++;
		}
		p1++;
	}
	std::sort(std::begin(Matrica), std::end(Matrica), [] (typename std::remove_reference<decltype(*std::begin(Matrica))>::type x1, typename std::remove_reference<decltype(*std::begin(Matrica))>::type x2) {
		return x1.at(2)<x2.at(2);
	});
	for(int i(0); i<Matrica.size()-1; i++) {
		int j(i+1);
		if(Matrica.at(i).at(2)==Matrica.at(j).at(2)) {
			while(Matrica.at(i).at(2)==Matrica.at(j).at(2)) {
				j++;
				if(j==Matrica.size()) break;
			}
			std::sort(std::begin(Matrica)+i, std::begin(Matrica)+j, [] (typename std::remove_reference<decltype(*std::begin(Matrica))>::type x1, typename std::remove_reference<decltype(*std::begin(Matrica))>::type x2) {
				return x1.at(0)<x2.at(0);
			});
		}
		i=j-1;

	}
	for(int i(0); i<Matrica.size()-1; i++) {
		int j(i+1);
		if(Matrica.at(i).at(0)==Matrica.at(j).at(0)) {
			while(Matrica.at(i).at(0)==Matrica.at(j).at(0)) {
				j++;
				if(j==Matrica.size()) break;
			}
			std::sort(std::begin(Matrica)+i, std::begin(Matrica)+j, [] (typename std::remove_reference<decltype(*std::begin(Matrica))>::type x1, typename std::remove_reference<decltype(*std::begin(Matrica))>::type x2) {
				return x1.at(1)<x2.at(1);
			});
		}
		i=j-1;
	}

	return Matrica;
}

template <typename ItiliPok11, typename ItiliPok22>

auto UvrnutaRazlika(ItiliPok11 p1, ItiliPok11 p2, ItiliPok22 p3, ItiliPok22 p4)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	int brojac(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	ItiliPok11 pp(p1);

	while(pp!=p2) {
		ItiliPok22 pok(p3);
		bool x (true);
		while(pok!=p4) {
			if(*pp==*pok) {
				x=false;
				break;
			}
			pok++;
		}
		if(x==true) {
			brojac++;
			Matrica.resize(brojac);
			Matrica.at(brojac-1).resize(2);
			Matrica.at(brojac-1).at(0)=*pp;
			Matrica.at(brojac-1).at(1)=0;
		}
		pp++;
	}

	ItiliPok22 ppp(p3);
	while(ppp!=p4) {
		ItiliPok11 pok(p1);
		bool x (true);
		while(pok!=p2) {
			if(*ppp==*pok) {
				x=false;
				break;
			}
			pok++;
		}
		if(x==true) {
			brojac++;
			Matrica.resize(brojac);
			Matrica.at(brojac-1).resize(2);
			Matrica.at(brojac-1).at(0)=*ppp;
			Matrica.at(brojac-1).at(1)=0;
		}
		ppp++;
	}

	std::sort(std::begin(Matrica), std::end(Matrica), [] (typename std::remove_reference<decltype(*std::begin(Matrica))>::type x1, typename std::remove_reference<decltype(*std::begin(Matrica))>::type x2) {
		return x1.at(0)>x2.at(0);
	});
	
	return Matrica;

}

template <typename ItiliPok11, typename ItiliPok22, typename Tip22, typename Tip33>

auto UvrnutaRazlika(ItiliPok11 p1, ItiliPok11 p2, ItiliPok22 p3, ItiliPok22 p4, Tip22 fun (Tip33))->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	int brojac(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	ItiliPok11 pp(p1);

	while(pp!=p2) {
		ItiliPok22 pok(p3);
		bool x (true);
		while(pok!=p4) {
			if(fun(*pp)==fun(*pok)) {
				x=false;
				break;
			}
			pok++;
		}
		if(x==true) {
			brojac++;
			Matrica.resize(brojac);
			Matrica.at(brojac-1).resize(2);
			Matrica.at(brojac-1).at(0)=*pp;
			Matrica.at(brojac-1).at(1)=fun(*pp);
		}
		pp++;
	}

	ItiliPok22 ppp(p3);
	while(ppp!=p4) {
		ItiliPok11 pok(p1);
		bool x (true);
		while(pok!=p2) {
			if(fun(*ppp)==fun(*pok)) {
				x=false;
				break;
			}
			pok++;
		}
		if(x==true) {
			brojac++;
			Matrica.resize(brojac);
			Matrica.at(brojac-1).resize(2);
			Matrica.at(brojac-1).at(0)=*ppp;
			Matrica.at(brojac-1).at(1)=fun(*ppp);
		}
		ppp++;
	}

	std::sort(std::begin(Matrica), std::end(Matrica), [] (typename std::remove_reference<decltype(*std::begin(Matrica))>::type x1, typename std::remove_reference<decltype(*std::begin(Matrica))>::type x2) {
		return x1.at(0)>x2.at(0);
	});
	for(int i(0); i<Matrica.size()-1; i++) {
		int j(i+1);
		if(Matrica.at(i).at(0)==Matrica.at(j).at(0)) {
			while(Matrica.at(i).at(0)==Matrica.at(j).at(0)) {
				j++;
				if(j==Matrica.size()) break;
			}
			std::sort(std::begin(Matrica)+i, std::begin(Matrica)+j, [] (typename std::remove_reference<decltype(*std::begin(Matrica))>::type x1, typename std::remove_reference<decltype(*std::begin(Matrica))>::type x2) {
				return x1.at(1)>x2.at(1);
			});
		}
		i=j-1;

	}
	return Matrica;

}

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n1;
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> d1;
	for(int i(0); i<n1; i++) {
		int x;
		bool t(true);
		std::cin>>x;
		for(int j(0); j<i; j++) {
			if(x==d1.at(j)) {
				t=false;
				i--;
				break;
			}
		}
		if(t==true) d1.push_back(x);
	}
	

	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n2;
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> d2;
	for(int i(0); i<n2; i++) {
		int x;
		bool t(true);
		std::cin>>x;
		for(int j(0); j<i; j++) {
			if(x==d2.at(j)) {
				t=false;
				i--;
				break;
			}
		}
		if(t==true) d2.push_back(x);
	}
	
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	std::vector<std::vector<int>> mat1(UvrnutiPresjek(std::begin(d1), std::end(d1), std::begin(d2), std::end(d2), SumaCifara));
	for(int i(0); i<mat1.size(); i++) {
		for(int j(0); j<mat1.at(i).size(); j++) {
			std::cout<<std::setw(6)<<mat1.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	std::vector<std::vector<int>> mat2(UvrnutaRazlika(std::begin(d1), std::end(d1), std::begin(d2), std::end(d2), BrojProstihFaktora));
	for(int i(0); i<mat2.size(); i++) {
		for(int j(0); j<mat2.at(i).size(); j++) {
			std::cout<<std::setw(6)<<mat2.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";

	return 0;
}