/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <type_traits>
#include <deque>
#include <cmath>


template<typename T, typename U, typename Ret, typename Arg>
auto UvrnutiPresjek(T first1, T last1, U first2, U last2, Ret (f)(Arg)) ->
	std::vector<std::vector<typename std::remove_reference<decltype(*first1)>::type >> 
{
	std::vector<std::vector<typename std::remove_reference<decltype(*first1)>::type >>  mat;
	typedef std::vector<typename std::remove_reference<decltype(*first1)>::type > vec;
	
	while (first1 != last1) {
		for(auto i = first2; i < last2 ; i++)
			if( f(*i) == f(*first1))
				mat.push_back(vec{*first1, *i, f(*i)});
		++first1;
	}
	
	std::sort(mat.begin(), mat.end(), [](const vec& f, const vec& l)
	{
		const auto& t_1 = f[2];
		const auto& t_2 = l[2];
		if(t_1 == t_2)
		{
			auto s_1 = f[0];
			auto s_2 = l[0];
			if(s_1 == s_2)
				return f[1] < l[1];
			
			return s_1 < s_2;
		}
		return t_1 < t_2;
	});
	
	return mat;
}



template<typename T, typename U>
auto UvrnutiPresjek(T first1, T last1, U first2, U last2) ->
	std::vector<std::vector<typename std::remove_reference<decltype(*first1)>::type >> 
{
	std::vector<std::vector<typename std::remove_reference<decltype(*first1)>::type >>  mat;
	typedef std::vector<typename std::remove_reference<decltype(*first1)>::type > vec;
	
	while (first1 != last1) {
		for(auto i = first2; i < last2 ; i++)
			if( *i == *first1)
				mat.push_back(vec{*first1, 0, 0});
		++first1;
	}
	
	std::sort(mat.begin(), mat.end(), [](const vec& f, const vec& l)
	{
		return f[2] < l[2];
	});
	
	return mat;
}


template<typename T, typename U, typename Ret, typename Arg>
auto UvrnutaRazlika(T first1, T last1, U first2, U last2, Ret (*f)(Arg)) ->
	std::vector<std::vector<typename std::remove_reference<decltype(*first1)>::type >> 
{
	std::vector<std::vector<typename std::remove_reference<decltype(*first1)>::type >> mat;
	typedef std::vector<typename std::remove_reference<decltype(*first1)>::type > vec;
	auto pom = first1;
	
	while (first1 != last1) 
	{
		bool ima = false;
		for(auto i = first2; i < last2 ; i++)
			if( f(*i) == f(*first1))
				ima = true;
		if(!ima)
			mat.push_back(vec{*first1, f(*first1)});
		++first1;
	}
	
	while (first2 != last2) {
		bool ima = false;
		for( auto i = pom; i < last1; i++)
			if( f(*i) == f(*first2))
				ima = true;
		if(!ima)
			mat.push_back(vec{*first2, f(*first2)});
		++first2;
	}
	
	std::sort(mat.begin(), mat.end(), [](const vec& f, const vec& l)
	{
		const auto& t_1 = f[0];
		const auto& t_2 = l[0];
		if(t_1 == t_2)
			return f[1] > l[1];
		
		return t_1 > t_2;
	});
	return mat;
}


template<typename T, typename U>
auto UvrnutaRazlika(T first1, T last1, U first2, U last2) ->
	std::vector<std::vector<typename std::remove_reference<decltype(*first1)>::type >> 
{
	std::vector<std::vector<typename std::remove_reference<decltype(*first1)>::type >> mat;
	typedef std::vector<typename std::remove_reference<decltype(*first1)>::type > vec;
	auto pom = first1;
	
	while (first1 != last1) 
	{
		bool ima = false;
		for(auto i = first2; i < last2 ; i++)
			if( *i == *first1)
				ima = true;
		if(!ima)
			mat.push_back(vec{*first1, 0});
		++first1;
	}
	
	while (first2 != last2) {
		bool ima = false;
		for( auto i = pom; i < last1; i++)
			if( *i == *first2)
				ima = true;
		if(!ima)
			mat.push_back(vec{*first2, 0});
		++first2;
	}
	
	std::sort(mat.begin(), mat.end(), [](const vec& f, const vec& l)
	{
		return f[0] > l[0];
	});
	return mat;
}



int SumaDjelilaca(long long int br)
{
	int suma = 0;
	for( int i = 1; i <= br; i++)
		if( br % i == 0)
			suma += i;
	return suma;
}


int BrojProstihFaktora(long long int n)
{
	int brojac = 0;
	while(n % 2 == 0)
	{
		brojac++;
		n /=2;
	}
	for( int i = 3; i < std::sqrt(n); i+= 2)
		while( n % i == 0)
		{
			brojac++;
			n /= i;
		}
	if( n > 2)
		brojac++;
	return brojac;
}

bool JelPerfektan(long long int n)
{
	long long int suma = 0;
	for( int i = 1; i < n; i++)
		if( n % i == 0)
			suma += i;
	return suma == n;
}


int BrojSavrsenihDjelilaca(long long int n)
{
	int brojac = 0;
	for( int i = 1; i <= n ; i++)
		if(  n % i == 0 && JelPerfektan(i))
			brojac++;
	return brojac;
}

int SumaCifara(long long int x)
{
		int suma_1 = 0;
		while (x != 0) {
			suma_1 += x % 10;
			x /= 10;
		}
		return suma_1;
}

int main ()
{
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin >> n;
	std::deque<long long int> d1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i = 0; i < n; i++)
	{
		long long int p;
		std::cin >> p;
		if( std::find(d1.begin(), d1.end(), p) == d1.end() )
			d1.push_back(p);
		else
		 i--;
		
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	
	std::cin >> n;
	std::deque<long long int> d2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i = 0; i < n; i++)
	{
		long long int p;
		std::cin >> p;
		if( std::find(d2.begin(), d2.end(), p) == d2.end() )
			d2.push_back(p);
			else
		 i--;
	
	}
	std::cout << "Uvrnuti presjek kontejnera:\n";
	auto presjek = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara );
	
	for(const auto& i : presjek)
	{
		for(const auto& j : i)
			std::cout << std::setw(6) << std::right << j << " ";
		std::cout << "\n";
	}
	std::cout << "Uvrnuta razlika kontejnera:\n";	
	auto razlika = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	for(const auto& i : razlika)
	{
		for(const auto& j : i)
			std::cout << std::setw(6) << std::right << j << " ";
		std::cout << "\n";
	}	
	std::cout << "Dovidjenja!";
		
	return 0;
}