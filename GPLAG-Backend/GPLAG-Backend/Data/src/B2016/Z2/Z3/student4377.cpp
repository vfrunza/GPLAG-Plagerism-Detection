/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>

int SumaDjelilaca(int n)
{
	int suma(0);
	if(n<0) n*=-1;
	for(int i = n; i>0; i--) if(n%i==0) suma+=i;
	return suma;
}

int BrojSavrsenihDjelilaca(int n)
{
	int brojac(0);
	if(n<0) n*=-1;
	for(int i=2; i<=n; i++)
	{
		if(n % i == 0)
		{
			if(i == (SumaDjelilaca(i)-i))
			{
				brojac++;
			}
		}
	}
	return brojac;
}

int SumaCifara(int n)
{
	int suma(0);
	while(n!=0)
	{
		suma += n%10;
		n/=10;
	}
	return suma;
}

int BrojProstihFaktora(int n)
{
	int brojac(0);
	while (n%2==0)
	{
		brojac++;
		n/=2;
	}
	
	for(int i=3; i<n; i+=2)
	while(n%i == 0)
	{
		brojac++;
		n/=i;
	}
	
	if(n>2) brojac++;
	
	return brojac;
}

int Parno(int n)
{
	if(n%2 == 0) return 1;
	return 0;
}

template <typename Tip, typename Tip2, typename FTip, typename ArgTip>
auto UvrnutiPresjek(Tip a1, Tip a2, Tip2 b1, Tip2 b2, FTip f(ArgTip)) -> std::vector<std::vector<ArgTip>>
{
	Tip ca1(a1);  // Kopije pokazivaca
	Tip2 cb1(b1);
	
	std::vector<std::vector<ArgTip>> matrica;
	int i(0);
	while(a1 != a2)
	{
		while(b1 != b2)
		{
			if(f(*a1) == f(*b1)) 
			{
				matrica.resize(matrica.size()+1);
				matrica[i].resize(3);
				matrica[i][0] = *a1;
				matrica[i][1] = *b1;
				matrica[i][2] = f(*a1);
				i++;
			}
			b1++;
		}
		b1 = cb1;
		a1++;
	}
	a1 = ca1;
	
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<ArgTip> x, std::vector<ArgTip> y) { if(x[2] == y[2]) if(x[0] == y[0]) return x[1] < y[1]; else return x[0] < y[0]; return x[2] < y[2];});
	return matrica;
}

template <typename Tip, typename Tip2>
auto UvrnutiPresjek(Tip a1, Tip a2, Tip2 b1, Tip2 b2) -> std::vector<std::vector<typename std::remove_reference<decltype(*a1)>::type>>
{
	Tip ca1(a1);  // Kopije pokazivaca
	Tip2 cb1(b1);
	
	std::vector<std::vector<typename std::remove_reference<decltype(*a1)>::type>> matrica;
	int i(0);
	while(a1 != a2)
	{
		while(b1 != b2)
		{
			if(*a1 == *b1) 
			{
				matrica.resize(matrica.size()+1);
				matrica[i].resize(3);
				matrica[i][0] = *a1;
				matrica[i][1] = 0;
				matrica[i][2] = 0;
				i++;
			}
			b1++;
		}
		b1 = cb1;
		a1++;
	}
	a1 = ca1;
	
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<typename std::remove_reference<decltype(*a1)>::type> x, std::vector<typename std::remove_reference<decltype(*a1)>::type> y) { if(x[2] == y[2]) if(x[0] == y[0]) return x[1] < y[1]; else return x[0] < y[0]; return x[2] < y[2];});
	return matrica;
}

template <typename Tip, typename Tip2, typename FTip, typename ArgTip>
auto UvrnutaRazlika(Tip a1, Tip a2, Tip2 b1, Tip2 b2, FTip f(ArgTip)) -> std::vector<std::vector<ArgTip>>
{
	Tip ca1(a1);  // Kopije pokazivaca
	Tip2 cb1(b1);
	
	bool ima_par (false);
	int i(0);
	std::vector<std::vector<ArgTip>> matrica;
	while(a1 != a2)
	{
		ima_par = false;
		while(b1 != b2)
		{
			if(f(*a1) == f(*b1)) 
			{
				ima_par = true;
				break;
			}
			b1++;
		}
		
		if(!ima_par)
		{
			matrica.resize(matrica.size()+1);
			matrica[i].resize(2);
			matrica[i][0] = *a1;
			matrica[i][1] = f(*a1);
			i++;
		}
		
		b1 = cb1;
		a1++;
	}
	a1 = ca1;
	
	
	
	//-------------------------------------------------------------------
	ima_par = false;
	while(b1 != b2)
	{
		ima_par = false;
		while(a1 != a2)
		{
			if(f(*a1) == f(*b1)) 
			{
				ima_par = true;
				break;
			}
			a1++;
		}
		
		if(!ima_par)
		{
			matrica.resize(matrica.size()+1);
			matrica[i].resize(2);
			matrica[i][0] = *b1;
			matrica[i][1] = f(*b1);
			i++;
		}
		
		a1 = ca1;
		b1++;
	}
	b1 = cb1;
	
	
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<ArgTip> x, std::vector<ArgTip> y) { if(x[0] == y[0]) return x[1] > y[1]; return x[0] > y[0];});
	return matrica;
}

template <typename Tip, typename Tip2> // Kad je podrazumjevana - preklapanje
auto UvrnutaRazlika(Tip a1, Tip a2, Tip2 b1, Tip2 b2) -> std::vector<std::vector<typename std::remove_reference<decltype(*a1)>::type>>
{
	Tip ca1(a1);  // Kopije pokazivaca
	Tip2 cb1(b1);
	
	bool ima_par (false);
	int i(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*a1)>::type>> matrica;
	while(a1 != a2)
	{
		ima_par = false;
		while(b1 != b2)
		{
			if(*a1 == *b1) 
			{
				ima_par = true;
				break;
			}
			b1++;
		}
		
		if(!ima_par)
		{
			matrica.resize(matrica.size()+1);
			matrica[i].resize(2);
			matrica[i][0] = *a1;
			matrica[i][1] = 0;
			i++;
		}
		
		b1 = cb1;
		a1++;
	}
	a1 = ca1;
	
	
	
	//-------------------------------------------------------------------
	ima_par = false;
	while(b1 != b2)
	{
		ima_par = false;
		while(a1 != a2)
		{
			if(*a1 == *b1) 
			{
				ima_par = true;
				break;
			}
			a1++;
		}
		
		if(!ima_par)
		{
			matrica.resize(matrica.size()+1);
			matrica[i].resize(2);
			matrica[i][0] = *b1;
			matrica[i][1] = 0;
			i++;
		}
		
		a1 = ca1;
		b1++;
	}
	b1 = cb1;
	
	
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<typename std::remove_reference<decltype(*a1)>::type> x, std::vector<typename std::remove_reference<decltype(*a1)>::type> y) { if(x[0] == y[0]) return x[1] > y[1]; return x[0] > y[0];});
	return matrica;
}


int main2 ()
{
	std::cout << BrojProstihFaktora(123456) << " " << BrojProstihFaktora(56789) << " " << BrojProstihFaktora(12121281) << " ";
std::cout << BrojProstihFaktora(4512698) << " " << BrojProstihFaktora(202248) << " " << BrojProstihFaktora(181287) << " ";
std::cout << BrojProstihFaktora(45698) << " " << BrojProstihFaktora(2048) << " " << BrojProstihFaktora(8128);
	
	return 0;
}

int main()
{
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int br1;
	std::cin >> br1;
	std::deque<int> kont1(br1);
	int broj;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i=0; i<br1; i++)
	{
		bool logika (false);
		std::cin >> broj;
		for(auto j:kont1)
		{
			if(j == broj)
			{
				i--;
				logika = true;
				break;
			}
		}
		if(!logika) kont1[i] = broj;
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> br1;
	std::deque<int> kont2(br1);
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i=0; i<br1; i++)
	{
		bool logika (false);
		std::cin >> broj;
		for(auto j:kont2)
		{
			if(j == broj)
			{
				i--;
				logika = true;
				break;
			}
		}
		if(!logika) kont2[i] = broj;
		
	}
	
	
	
	std::cout << "Uvrnuti presjek kontejnera: \n";
	std::vector<std::vector<int>> m{UvrnutiPresjek(kont1.begin(), kont1.end(), kont2.begin(), kont2.end(), SumaCifara)};
	
	
	for(auto red : m) 
 	{
 		for(auto x : red) std::cout << std::right << std::setw(6) << x << " ";
 		std::cout << std::endl;
 	}
 	
 	std::cout << "Uvrnuta razlika kontejnera: \n";
	std::vector<std::vector<int>> m2{UvrnutaRazlika(kont1.begin(), kont1.end(), kont2.begin(), kont2.end(), BrojProstihFaktora)};
	
	
	for(auto red : m2) 
 	{
 		for(auto x : red) std::cout << std::right << std::setw(6) << x << " ";
 		std::cout << std::endl;
 	}
 	
 	std::cout << std::endl << "Dovidjenja!";
 	
	return 0;
}