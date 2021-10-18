/*B 2017/2018, ===TITLE===
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/

/*
#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <new>

template <typename TIP> int DajPeriod (const std::vector <TIP> &vektor)
{
    int i{0}, T{1};
    while ((i + T) < vektor.size())
        i += vektor.at(i) == vektor.at(i + T) ? 1 : (T++, -i);
    return T;
}
template <typename TIP> void Validiraj (const std::vector<TIP> &v)
{
    if (v.empty())
        throw "Prazan vektor!";
    if (std::count_if (v.begin(), v.end(), [] (TIP x) {return x <= 0;}) > 0)
        throw std::domain_error("Neispravan vektor!");
}
template <typename TIP>
TIP **AlocirajFragmentirano(const std::vector<TIP> &v, int& koliko_puta)
{
    Validiraj(v);
    TIP **matrica{nullptr}, najveci{*max_element(v.begin(), v.end())};
    koliko_puta = int (v.size() / DajPeriod(v));
    
    if ((v.size() % DajPeriod(v)) != 0 || DajPeriod(v) == v.size())
        koliko_puta++;
    
        try 
        {
            matrica = new TIP* [DajPeriod(v) * koliko_puta]{};
            for (int i{0}; i < DajPeriod(v) * koliko_puta; i++)
                matrica[i] = new TIP [v.at(i % DajPeriod(v))]{};
        }
        catch (std::bad_alloc)
        {
            for (int i{0}; i < DajPeriod(v) * koliko_puta; i++)
                delete [] matrica[i];
            delete [] matrica;
            throw;
        }
    
        for (int k{0}; k < koliko_puta; k++)
            for (int i{0}; i < DajPeriod(v); i++)
                for (int j{v.at(i) - 1}, l{0}; j > -1; j--, l++)
                    matrica[i + DajPeriod(v) * k][j] = najveci - l;
    return matrica;
}
template <typename TIP>
TIP **AlocirajKontinualno(const std::vector<TIP> &v, int& koliko_puta)
{
    Validiraj(v); 
    TIP **matrica{nullptr}, broj(accumulate(v.begin(), v.end(), 0.)); 
    koliko_puta = int (v.size() / DajPeriod(v));
    
    if ((v.size() % DajPeriod(v)) != 0 || DajPeriod(v) == v.size())
        koliko_puta++;
    
    try
    {
        matrica = new TIP* [DajPeriod(v) * koliko_puta]{};
        try
        {   
            matrica[0] = new TIP [broj * koliko_puta];
            for (int i{1}; i <  DajPeriod(v) * koliko_puta; i++)
                matrica[i] = matrica[i - 1] + v.at((i - 1) %  DajPeriod(v));
        }
        catch (...)
        {
            delete [] matrica;
            throw;
        }
    }
    catch (...)
    {   
        throw;
    }
            
    for (int k{0}; k < koliko_puta; k++)
        for (int i{0}; i <  DajPeriod(v); i++)
            for (int j{v.at(i) - 1}; j > -1; j--)
                matrica[i +  DajPeriod(v) * k][j] = v.at(i) - j;
    return matrica;
}

int main()
{
    int brojElemenata {0}, brojPuta;
    bool fragmentirana {true};
    std::cout << "Unesite broj elemenata vektora: ";
    std::cin >> brojElemenata;
    std::vector<int> vektor(brojElemenata);
    std::cout << "Unesite elemente vektora: ";
    for (int& v : vektor)
        std::cin >> v;
    std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
    std::cin >> fragmentirana;
    try
    {
        int **matrica{};
        matrica = (fragmentirana ? AlocirajFragmentirano(vektor, brojPuta) : AlocirajKontinualno(vektor, brojPuta));
        
        std::cout << "Dinamicki alocirana matrica:" << std::endl;
        for (int i{0}; i < DajPeriod(vektor) * brojPuta; i++)
            for (int j{0}; j < vektor.at(i % DajPeriod(vektor)); j++)
                 std::cout << std::setw(3) << std::left << matrica[i][j] << ((j + 1 != vektor.at(i % DajPeriod(vektor))) ? "" : "\n");
        
        if (fragmentirana)
           for (int i{0}; i < DajPeriod(vektor) * brojPuta; i++)
                delete [] matrica[i];
        else       
            delete [] matrica[0];            
        delete [] matrica;
    }
    catch (const std::domain_error& e)
    {
        std::cout<< "Izuzetak: " << e.what() << std::endl;
    }
    catch (const char izuzetak[])
    {
        std::cout << "Izuzetak: "<< izuzetak << std::endl;
    }
    
    return 0;
}*/



#include <iostream>
#include <vector>
#include <new>
#include <stdexcept>
#include <iomanip>
using std::vector;
template <typename T> int period(const vector<T> &v)
{
	for (int i(1); i < v.size(); i++)
	{
	    for (int j(i); j < v.size(); j++)
	    	if (v.at(j) != v.at(j-i)) goto preskok;
	    return i;
	    preskok:;
	}
	return 0;
}
template <typename T> int predradnje(const vector<T> &v, int &koliko_puta)
{
	if (v.empty()) throw "Prazan vektor!";
	for (auto x : v)
		if (x <= 0) throw std::domain_error("Neispravan vektor!");
	int p(period(v));
	koliko_puta = p != 0 ? v.size() / p + (v.size() % p != 0) : 2;
	return p != 0 ? p : v.size();
}
template <typename T> T **AlocirajFragmentirano(const vector<T> &v, int &koliko_puta)
{
	int p(predradnje(v, koliko_puta)), n(p * koliko_puta);
	T **mat = new T*[n]{nullptr};
	int max(0);
	try
	{
		for (int i(0); i < n; i++) mat[i] = new T[v.at(i % p)]{};
	}
	catch (...)
	{
	    if (!mat)
		for (int i(0); i < n && mat[i] != nullptr; i++)
			delete[] mat[i];
		delete[] mat;
		throw;
	}
	for (const auto &x : v)
		if (x > max) max = x;
	for (int i(0); i < n; i++)
		for (int j(0); j < v.at(i % p); j++)
			mat[i][v.at(i % p)-1-j] = max-j;
	return mat;
}
template <typename T> T **AlocirajKontinualno(const vector<T> &v, int &koliko_puta)
{
	int p(predradnje(v, koliko_puta)), m(0), n(p * koliko_puta);
	for (int i(0); i < p; i++) m += v.at(i);
	m *= koliko_puta;
	T **mat = new T*[n]{nullptr};
	try
	{
		mat[0] = new T[m];
		for (int i(1); i < n; i++)
			mat[i] = mat[i-1] + v.at((i-1) % p);
	}
	catch (...) { if (!mat) delete[] mat; throw; }
	for (int i(0); i < n; i++)
		for (int j(0); j < v.at(i % p); j++)
			mat[i][v.at(i % p)-1-j] = j+1;
	return mat;
}

int main()
{
	int n, f, p;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	vector<int> v(n);
	for (int &x : v) std::cin >> x;
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> f;
	try
	{
		int **mat = f ? AlocirajFragmentirano(v, n) : AlocirajKontinualno(v, n);
		p = period(v);
		n = (p = p != 0 ? p : v.size()) * n;
		std::cout << "Dinamicki alocirana matrica: ";
		for (int i(0); i < n; i++)
		{
			std::cout << std::endl;
			for (int j(0); j < v.at(i % p); j++)
				std::cout << std::setw(3) << std::left << mat[i][j];
			if (f) delete[] mat[i];
		}
		if (!f) delete[] *mat;
		delete[] mat;
	}
	catch (const char *s) { std::cout << "Izuzetak: " << s; }
	catch (std::domain_error e) { std::cout << "Izuzetak: " << e.what(); }
	catch (...) { }
	return 0;
}
