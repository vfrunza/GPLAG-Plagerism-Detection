#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <iomanip>

template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutaRazlika(Tip1 a, Tip1 b, Tip2 x, Tip2 y, Tip3 f(Tip4) )
-> std::vector<typename std::vector<typename std::remove_reference<decltype(*a)>::type>>
{
	typedef std::vector<typename std::vector<typename std::remove_reference<decltype(*a)>::type>> matrica;
	typedef typename std::remove_reference<decltype(*a)>::type clan;
	matrica povratna;
	Tip1 apoc(a); 
	Tip1 a2(a);
	Tip2 xpoc(x);
	Tip2 x2(x);
	int duzina(0), duzina2(0), i(0);
	while(x2++ != y) duzina++;
	while(a2++ != b) duzina2++;
	std::vector<int>brojaci1(duzina2, 0);
	std::vector<int> brojaci2(duzina, 0);
	for(; a != b ;)
	{
		auto tmp = x;
		int j(0);
		for(; x != y ;)
		{
			if(f(*a) == f(*x))
			{
				brojaci1[i] = 1;
				brojaci2[j] = 1;
			}
			j++;
			x++;
		} x = tmp;
		a++; i++;
	} a = apoc;
	x = xpoc;
	i = 0; int j(0); int velicina(0);
	while (a != b)
	{
		if(brojaci1[i++] == 0)
		{
			povratna.resize(++velicina);
			povratna[velicina-1].resize(2);
			povratna[velicina-1][0] = *a;
			povratna[velicina-1][1] = f(*a);
		} a++;
	} i = 0; j = 0;
	while(x != y)
	{
		if(brojaci2[i++] == 0)
		{
			povratna.resize(++velicina);
			povratna[velicina-1].resize(2);
			povratna[velicina-1][0] = *x;
			povratna[velicina-1][1] = f(*x);
		} x++;
	}
	std::sort(povratna.begin(), povratna.end(), [](std::vector<clan> x, std::vector<clan> y) { 
		if(x[0] > y[0]) return true;
		else if(x[0] == y[0]) {	if(x[1] > y [1]) return true;} return false;});
	return povratna;
}
template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutiPresjek (Tip1 a, Tip1 b, Tip2 x, Tip2 y, Tip3 f(Tip4))
-> std::vector<typename std::vector<typename std::remove_reference<decltype(*a)>::type>>
{
	typedef std::vector<typename std::vector<typename std::remove_reference<decltype(*a)>::type>> matrica;
	typedef typename std::remove_reference<decltype(*a)>::type clan;
	matrica povratna;
	int brojac(0);
	for(; a != b ;)
	{
		auto tmp = x;
		for(; x != y ;)
		{
			if(f(*a) == f(*x))
			{
				povratna.resize(brojac+1);
				povratna[brojac].resize(3);
				povratna[brojac][0] = clan(*a);
				povratna[brojac][1] = clan(*x);
				povratna[brojac++][2] = clan(f(*x));
			} x++;
		} x = tmp;
		a++;
	} std::sort(povratna.begin(), povratna.end(), [](std::vector<clan> x, std::vector<clan> y) {
		if(x[2] < y[2]) return true; else if (x[2] == y[2]) { if(x[0] < y[0]) return true; else if(x[0] == y[0]) if(x[1] < y[1]) return true; } 
		return false; });
	return povratna;
}

template <typename Tip1, typename Tip2>
auto UvrnutiPresjek (Tip1 a, Tip1 b, Tip2 x, Tip2 y)
-> std::vector<typename std::vector<typename std::remove_reference<decltype(*a)>::type>>
{
	typedef std::vector<typename std::vector<typename std::remove_reference<decltype(*a)>::type>> matrica;
	typedef typename std::remove_reference<decltype(*a)>::type clan;
	matrica povratna;
	int brojac(0);
	for(; a != b ;)
	{
		auto tmp = x;
		for(; x != y ;)
		{
			if(*a == *x)
			{
				povratna.resize(brojac+1);
				povratna[brojac].resize(3);
				povratna[brojac][0] = clan(*a);
				povratna[brojac][1] = 0;
				povratna[brojac++][2] = 0;
			} x++;
		} x = tmp;
		a++;
	} std::sort(povratna.begin(), povratna.end(), [](std::vector<clan> x, std::vector<clan> y) {
		if(x[2] < y[2]) return true; return false; });
	return povratna;
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 a, Tip1 b, Tip2 x, Tip2 y)
-> std::vector<typename std::vector<typename std::remove_reference<decltype(*a)>::type>>
{
	typedef std::vector<typename std::vector<typename std::remove_reference<decltype(*a)>::type>> matrica;
	typedef typename std::remove_reference<decltype(*a)>::type clan;
	matrica povratna;
	Tip1 apoc(a); 
	Tip1 a2(a);
	Tip2 xpoc(x);
	Tip2 x2(x);
	int duzina(0), duzina2(0), i(0);
	while(x2++ != y) duzina++;
	while(a2++ != b) duzina2++;
	std::vector<int>brojaci1(duzina2, 0);
	std::vector<int> brojaci2(duzina, 0);
	for(; a != b ;)
	{
		auto tmp = x;
		int j(0);
		for(; x != y ;)
		{
			if(*a == *x)
			{
				brojaci1[i] = 1;
				brojaci2[j] = 1;
			}
			j++;
			x++;
		} x = tmp;
		a++; i++;
	} a = apoc;
	x = xpoc;
	i = 0; int j(0); int velicina(0);
	while (a != b)
	{
		if(brojaci1[i++] == 0)
		{
			povratna.resize(++velicina);
			povratna[velicina-1].resize(2);
			povratna[velicina-1][0] = *a;
			povratna[velicina-1][1] = 0;
		} a++;
	} i = 0; j = 0;
	while(x != y)
	{
		if(brojaci2[i++] == 0)
		{
			povratna.resize(++velicina);
			povratna[velicina-1].resize(2);
			povratna[velicina-1][0] = *x;
			povratna[velicina-1][1] = 0;
		} x++;
	}
	std::sort(povratna.begin(), povratna.end(), [](std::vector<clan> x, std::vector<clan> y) { 
		if(x[0] > y[0]) return true; return false;});
	return povratna;
}
int SumaDjelilaca(long long int n)
{
	int suma(0);
	if(n < 0)
	{
		for(long long int i = -1; i >= n; i--)
			if(n % i == 0) suma += std::abs(i);
	}
	for(long long int i = 1; i <= n; i++)
		if(n % i  == 0) suma += i;
	return suma;
}
int BrojProstihFaktora (long long int n)
{
	int num(0);
	for(long long int i = 1; i <= n; i++)
		if(n % i == 0 && SumaDjelilaca(i) == i + 1)
		{
			num++;
			n /= i;
			i = 0;
		}
	return num;
}
bool savrsen( long long int n)
{
	if(SumaDjelilaca(n) == 2*n) return true;
	return false;
}
int BrojSavrsenihDjelilaca(long long int n)
{
	int a(0);
	for(long long int i = 1; i <= n ; i++)
		if(n % i == 0 && savrsen(i)) a++;
	return a;
}
int brCifara(long long int n)
{
	int br(1);
	n/=10;
	n = std::abs(n);
	while(n)
	{
		br++;
		n/=10;
	}
	std::cout<<br<<" ";
	return br;
}
int SumaCifara (long long int n)
{
	int suma(0);
	while(n)
	{
		suma += std::abs(n%10);
		n/=10;
	} return suma;
}

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n1;
	std::cin>>n1;
	std::deque<int> d1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	int brojac(0), tmp;
	while(brojac < n1)
	{
		std::cin>>tmp;
		if(find(d1.begin(), d1.end(), tmp) == d1.end())
		{
			d1.push_back(tmp);
			brojac++;
		} 
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n2;
	std::cin>>n2;
	std::deque<int> d2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	brojac = 0;
	while(brojac < n2)
	{
		std::cin>>tmp;
		if(find(d2.begin(), d2.end(), tmp) == d2.end())
		{
			d2.push_back(tmp);
			brojac++;
		}
	}
	auto ispisinesto(UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara));
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	for(int i = 0; i < ispisinesto.size(); i++)
	{	
		for(int j = 0; j < ispisinesto[i].size(); j++)
			std::cout<<std::setw(6)<<ispisinesto[i][j]<<" ";
		std::cout<<std::endl;	
	}		
	auto kraj(UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora));
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	for(int i = 0; i < kraj.size(); i++)
	{
		for(int j = 0; j < kraj[i].size(); j++)
			std::cout<<std::setw(6)<<kraj[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
} 