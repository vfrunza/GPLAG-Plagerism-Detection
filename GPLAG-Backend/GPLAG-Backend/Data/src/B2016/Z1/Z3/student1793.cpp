/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
vector<vector<double>> RastuciPodnizovi (vector<double> niz)
{
	vector<vector<double>> raste(niz.size());
	vector<double> pomocniNiz (niz.size());
	int b = 0, i = 0;
	while (i < niz.size() - 1)
	{
		while (niz[i] <= niz[i + 1])
		{
			//raste[j][b] = niz[i];
			pomocniNiz.push_back(niz[i]);
			//b++;
			i++;
			if (niz[i] > niz[i + 1])
				{
					//raste[j][b] = niz[i];
					//j++;
					pomocniNiz.push_back(niz[i]);
				}
		}
		i++;
		if (!pomocniNiz.empty())
		{
			raste.push_back(pomocniNiz); // kriticna linija
			b++;
		}
		pomocniNiz.clear();
	}
	return raste;
}
int main ()
{
	vector<double> a {1, 3, 2, 6, 7, 9, 10, 4, 3, 1, 7};
	vector<vector<double>> k (11, vector<double> (11));
	k = RastuciPodnizovi(a);
	for(int x = 0; x < k.size(); x++)
			{
			for(int y = 0; y < k[x].size(); y++)
			     cout << setw(4) << k[x][y];
			   cout << endl;
			}	
	return 0;
}