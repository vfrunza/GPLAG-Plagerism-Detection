/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>

int SumaCifara(long long int n)
{
	int suma(0);
	while(n != 0)
	{
		suma += n%10;
		n /= 10;
	}
	return suma;
}

int SumaDjelilaca(long long int n)
{
	if(n < 0) n *= -1; 
	else if(n == 0) return 0;
	int suma(0);
	for(int i(1); i <= n; i++)
	{
		if(n%i == 0)
		  suma += i;
	}
	return suma;
}

int BrojProstihFaktora(long long int n)
{
	int br(0);
	for(int i(2); i <= n; i++)
	{
		if(n%i == 0)
		{
			br++;
			n /= i;
			i = 1;
		}
	}
	return br;
}

bool Savrsen(long long int n)
{
	int suma(0);
	for(int i(1); i < n; i++)
	{
		if(n%i == 0)
		  suma += i;
	}
	if(suma == n) return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int n)
{
	int br(0);
	for(int i(1); i <= n; i++)
	{
	    if(n%i == 0)
	    {
	    	if(Savrsen(i))
	    	  br++;
		}
	}
	return br;
}

template<typename Tip1, typename Tip2, typename TipF, typename TipP>
auto UvrnutiPresjek(Tip1 poc1, Tip1 kra1, Tip2 poc2, Tip2 kra2, TipF f(TipP x)) -> std::vector<std::vector<decltype(*poc1 + 0)>> 
{
	std::vector<std::vector<decltype(*poc1 + 0)>> mat;
	while(poc1 != kra1)
	{
		Tip2 poc3(poc2), kra3(kra2);
		while(poc3 != kra3)
		{
			if(f(*poc1) == f(*poc3))
			{
				std::vector<decltype(*poc1 + 0)> v{*poc1, *poc3, f(*poc1)};
				mat.push_back(v);
			}
			poc3++;
		}
		poc1++;
	}
	
	std::sort(std::begin(mat), std::end(mat), [] (std::vector<decltype(*poc1 + 0)> x, std::vector<decltype(*poc1 + 0)> y)
	{if(x[2] == y[2]){if(x[0] == y[0]){return x[1] < y[1];}return x[0] < y[0];}return x[2] < y[2];});
	return mat;
}

// Verzija sa 4 parametra
template<typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 poc1, Tip1 kra1, Tip2 poc2, Tip2 kra2) -> std::vector<std::vector<decltype(*poc1 + 0)>> 
{
	std::vector<std::vector<decltype(*poc1 + 0)>> mat;
	while(poc1 != kra1)
	{
		Tip2 poc3(poc2), kra3(kra2);
		while(poc3 != kra3)
		{
			if(*poc1 == *poc3)
			{
				std::vector<decltype(*poc1 + 0)> v{*poc1, 0, 0};
				mat.push_back(v);
			}
			poc3++;
		}
		poc1++;
	}
	std::sort(std::begin(mat), std::end(mat), [] (std::vector<decltype(*poc1 + 0)> x, std::vector<decltype(*poc1 + 0)> y){return x[0] < y[0];});
	return mat;
}

template<typename Tip1, typename Tip2, typename TipF, typename TipP>
auto UvrnutaRazlika(Tip1 poc1, Tip1 kra1, Tip2 poc2, Tip2 kra2, TipF f(TipP x)) -> std::vector<std::vector<decltype(*poc1 + 0)>>
{
	std::vector<std::vector<decltype(*poc1 + 0)>> mat;
	Tip1 Trenutni(poc1);
	while(Trenutni != kra1)
	{
		Tip2 pomocni(poc2);
		bool par(false);
		while(pomocni != kra2)
		{
			if(f(*Trenutni) == f(*pomocni))
			{
				par = true;
				break;
			}
			pomocni++;
		}
		if(par == false)
		{
			std::vector<decltype(*poc1 + 0)> v{*Trenutni, f(*Trenutni)};
			mat.push_back(v);
		}
		Trenutni++;
	}
	while(poc2 != kra2)
	{
		Tip2 pomocni(poc1);
		bool par(false);
		while(pomocni != kra1)
		{
			if(f(*poc2) == f(*pomocni))
			{
				par = true;
				break;
			}
			pomocni++;
		}
		if(par == false)
		{
			std::vector<decltype(*poc1 + 0)> v{*poc2, f(*poc2)};
			mat.push_back(v);
		}
		poc2++;
	}
	std::sort(std::begin(mat), std::end(mat), [] (std::vector<decltype(*poc1 + 0)> x, std::vector<decltype(*poc1 + 0)> y) 
												 {if(x[0] == y[0]){return x[1] > y[1];} return x[0] > y[0];});
	return mat;
}

// Verzija sa 4 parametra
template<typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 poc1, Tip1 kra1, Tip2 poc2, Tip2 kra2) -> std::vector<std::vector<decltype(*poc1 + 0)>>
{
	std::vector<std::vector<decltype(*poc1 + 0)>> mat;
	Tip1 Trenutni(poc1);
	while(Trenutni != kra1)
	{
		Tip2 pomocni(poc2);
		bool par(false);
		while(pomocni != kra2)
		{
			if(*Trenutni == *pomocni)
			{
				par = true;
				break;
			}
			pomocni++;
		}
		if(par == false)
		{
			std::vector<decltype(*poc1 + 0)> v{*Trenutni, 0};
			mat.push_back(v);
		}
		Trenutni++;
	}
	while(poc2 != kra2)
	{
		Tip2 pomocni(poc1);
		bool par(false);
		while(pomocni != kra1)
		{
			if(*poc2 == *pomocni)
			{
				par = true;
				break;
			}
			pomocni++;
		}
		if(par == false)
		{
			std::vector<decltype(*poc1 + 0)> v{*poc2, 0};
			mat.push_back(v);
		}
		poc2++;
	}
	std::sort(std::begin(mat), std::end(mat), [] (std::vector<decltype(*poc1 + 0)> x, std::vector<decltype(*poc1 + 0)> y) {return x[0] > y[0];});
	return mat;
}

template<typename Tip>
bool ImaLiGa(const std::deque<Tip> &dek, int n)
{
	for(int i(0); i < dek.size(); i++)
	{
		if(dek[i] == n)
		  return true;
	}
	return false;
}

template<typename Tip>
void Unos(std::deque<Tip> &dek, int vel)
{
	int n;
	for(int i(0); i < vel; i++)
	{
		std::cin >> n;
		if(ImaLiGa(dek, n) == false)
		  dek.push_back(n);
		else
		  i--;
	}
}

template<typename Tip>
void IspisiMatricu(const std::vector<std::vector<Tip>> &mat)
{
	for(int i(0); i < mat.size(); i++)
	{
		for(int j(0); j < mat[i].size(); j++)
		{
			std::cout << std::setw(6) << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main ()
{
	int vel;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> vel;
	std::cout << "Unesite elemente prvog kontejnera: ";
	std::deque<int> cont1;
	Unos(cont1, vel);
	
	int vel2;
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> vel2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	std::deque<int> cont2;
	Unos(cont2, vel2);
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	auto matP(UvrnutiPresjek(std::begin(cont1), std::end(cont1), std::begin(cont2), std::end(cont2), SumaCifara));
	IspisiMatricu(matP);
	
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	auto matR(UvrnutaRazlika(std::begin(cont1), std::end(cont1), std::begin(cont2), std::end(cont2), BrojProstihFaktora));
	IspisiMatricu(matR);
	std::cout << "Dovidjenja!";
	return 0;
}