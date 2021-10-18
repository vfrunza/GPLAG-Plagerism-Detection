/*B 16/17, Zadaća 2, Zadatak 3

NAPOMENA: i javni ATo-vi su dio postavke

Autotestovi by Berina Cocalic. Sva pitanja, sugestije
i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <iostream>
#include <vector>
#include <type_traits>
#include <iomanip>

using namespace std;

int SumaDjelilaca(int x)
{
	int sum = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0) sum += i;
	}

	return sum;
}

int BrojProstihFaktora(int x)
{
	int i = 2;
	int br = 0;
	int pom = x;
	for (int i = 2; i < pom; i++)
	{
		if (pom % i == 0)
		{
			br++;
			while (pom % i == 0) pom /= i;
			cout << pom << " ";
		}
	}

	return br;
}

int BrojSavrsenihDjelilaca(int x)
{
	int br = 0;
	int pom = x;
	for (int i = 1; i < pom; i++)
	{
		if (pom % i == 0)
		{
			int k = 1;
			int sum = 0;
			while (k < i)
			{
				if (i % k == 0) sum += k;
				k++;
			}
			if (sum == pom) br++;
		}
	}

	return br;
}

template <typename IterTip1, typename IterTip2, typename TipF1>
auto UvrnutiPresjek(IterTip1 pok1, IterTip1 pok2, IterTip2 pok3, IterTip2 pok4, TipF1 f) -> typename vector<vector<typename remove_reference<decltype(*pok1)>::type>>
{
	auto pom1 = pok1;
	auto pom3 = pok3;

	int j = 0;
	while (pom1 != pok2)
	{
		pom3 = pok3;
		while (pom3 != pok4)
		{
			if (f(*pom1) == f(*pom3))
			{
				j++;
			}
			pom3++;
		}
		pom1++;
	}

	pom1 = pok1;
	pom3 = pok3;

	vector<vector<int>>mat(j);

	int i = 0;
	while (pom1 != pok2)
	{
		pom3 = pok3;
		while (pom3 != pok4)
		{
			if (f(*pom1) == f(*pom3))
			{
				mat[i].push_back(*pom1);
				mat[i].push_back(*pom3);
				mat[i].push_back(f(*pom1));

				i++;
			}
			pom3++;
		}
		pom1++;
	}

	pom1 = pok1;
	pom3 = pok3;

	return mat;
}

int main()
{
	cout << "Unesite broj elemenata prvog kontejnera: ";
	int n1;
	cin >> n1;
	cout << "Unesite elemente prvog kontejnera: ";
	vector<int> v1(n1);
	for (int i = 0; i < n1; i++) cin >> v1[i];
	cin.ignore(10000, '\n');

	cout << "Unesite broj elemenata drugog kontejnera: ";
	int n2;
	cin >> n2;
	cout << "Unesite elemente drugog kontejnera: ";
	vector<int> v2(n2);
	for (int i = 0; i < n2; i++) cin >> v2[i];
	cin.ignore(10000, '\n');

	cout << "Uvrnuti presjek: \n";
	vector<vector<int>> matP;
	matP = UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), [](int x) {
		int pom = x;
		int sum = 0;
		while (pom != 0) { sum = sum + pom % 10; pom = pom / 10; }
		return sum;
	});

	for (int i = 0; i<matP.size(); i++)
	{
		for (int j = 0; j<matP[i].size(); j++)
		{
			cout << setw(6) << matP[i][j];
		}
		cout << endl;
	}

	return 0;
}