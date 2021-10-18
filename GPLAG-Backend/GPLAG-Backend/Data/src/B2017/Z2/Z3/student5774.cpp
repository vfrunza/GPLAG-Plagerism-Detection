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
	T **mat = new T*[n]{};
	int max(0);
	try
	{
		for (int i(0); i < n; i++) mat[i] = new T[v.at(i % p)];
	}
	catch (...)
	{
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
	T **mat = new T*[n];
	try
	{
		mat[0] = new T[m];
		for (int i(1); i < n; i++)
			mat[i] = mat[i-1] + v.at((i-1) % p);
	}
	catch (...) { delete[] mat; throw; }
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