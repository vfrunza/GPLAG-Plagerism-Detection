/*B 2016/2017, Zadaća 1, Zadatak 2
	
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
vector<vector<int>> OgledaloMatrica (vector<vector<int>> M)
{
	if (M.empty()) return M;
	if (M.size() == 0 && M[0].size() == 0) return M;
	vector<vector<int>> Matrica (3 * M.size(), vector<int> (M[0].size() * 3));
	vector<vector<int>> hv (M.size(), vector<int> (M[0].size()));
	vector<vector<int>> v  (M.size(), vector<int> (M[0].size()));
	vector<vector<int>> h  (M.size(), vector<int> (M[0].size()));
	for (int i = 0; i < M.size(); i++)
		for (int j = 0; j < M[i].size(); j++)
			{
				v[i][j] = M[i][j];				// kopirnaje jer mi javlja
			}									// naku gresku pa se slomih 
	for (int i = 0; i < M.size(); i++)			// pokusavajuci
		for (int j = 0; j < M[i].size(); j++)	// rijesiti
			{
				h[i][j] = M[i][j];
			}
	int pomocna;
	// h kolone naopako
	// v redovi
	// hv kombinacija :D
	// idemo obrtati prvo kolone i pravimo matricu h, let the game begin!
	for (int i = 0; i < h.size(); i++)
		for (int j = 0; j < h[0].size() / 2; j++)
			{
				pomocna = h[i][j];
				h[i][j] = h[i][h[0].size() - 1 - j];
				h[i][h[0].size() - 1 - j] = pomocna;
			}
	// okrenuli smo kolone, idemo dalje za iste pare
	// marka i sedamdeset tri KM po litru dizela poyy
	// obrcemo redove i pravimo matricu v
	int a = v.size();
	for (int i = 0; i < v.size() / 2; i++)
		for (int j = 0; j < v[i].size(); j++)
			{
				pomocna = v[i][j];
				v[i][j] = v[a - 1 - i][j];
				v[a - 1 - i][j] = pomocna;
			}
	// gotovo i ovo
	// idemo sad i redove i kolone obrtati
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++)
			{
				hv[i][j] = v[i][j];				// kopiranje
			}
	int b = hv[0].size();
	for (int i = 0; i < h.size(); i++)
		for (int j = 0; j < h[i].size() / 2; j++)
			{
				pomocna = hv[i][j];
				hv[i][j] = hv[i][b - 1 - j]; // e jadna majko moja 
				hv[i][b - 1 - j] = pomocna;
			}
	// zavrsili smo i ovu vratolomiju nad matricom
	// prvi red
	for (int i = 0; i < hv.size(); i++)
		for (int j = 0; j < hv[0].size(); j++)
			Matrica[i][j] = hv[i][j];
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[0].size(); j++)
			Matrica[i][ hv[0].size() + j] = v[i][j];
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[0].size(); j++)
			Matrica[i][hv[0].size() +v[0].size() + j] = hv[i][j];
	// drugi red
	for (int i = 0; i < h.size(); i++)
		for (int j = 0; j < h[0].size(); j++)
			Matrica[hv.size() + i][j] = h[i][j];
	for (int i = 0; i < M.size(); i++)
		for (int j = 0; j < M[0].size(); j++)
			Matrica[hv.size() + i][h[0].size() + j] = M[i][j];
	for (int i = 0; i < h.size(); i++)
		for (int j = 0; j < h[0].size(); j++)
			Matrica[hv.size() + i][h[0].size() + M[0].size() + j] = h[i][j];
	// treci red
	for (int i = 0; i < hv.size(); i++)
		for (int j = 0; j < hv[0].size(); j++)
			Matrica[hv.size() + h.size() + i][j] = hv[i][j];
			
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[0].size(); j++)
			Matrica[hv.size() + h.size() + i][hv[0].size() + j] = v[i][j];
			
	for (int i = 0; i < hv.size(); i++)
		for (int j = 0; j < hv[0].size(); j++)
			Matrica[hv.size() + h.size() + i][hv[0].size() + v[0].size() + j] = hv[i][j];
			
	return Matrica;
}
int main ()
{
	int o, p;
    cout << "Unesite dimenzije matrice (m n): ";
    cin >> o >> p;
    cin.ignore(10000, '\n');
    if (o < 0 || p < 0) 
    {
    	cout << "Dimenzije matrice moraju biti nenegativne! ";
    	return 0;
    }
    if (p == 0 && o != 0)
    {
    	cout << "Unesite elemente matrice: " << endl << "Rezultantna matrica: ";
    	for (int i = 0; i < o * 3; i++)
    		cout << endl;
    	cout << endl;
    }
    else
    {
    	vector<vector<int>> c(o, vector<int> (p)), k(3 * o, vector<int> (3 * p));
    	cout << "Unesite elemente matrice: ";
		for(int i = 0; i < o; i++)
			for(int j = 0; j < p; j++) 
				cin >> c[i][j];
			cout << endl;
			k = OgledaloMatrica(c);
			cout << "Rezultantna matrica: " << endl;
		for(int x = 0; x < k.size(); x++)
			{
			for(int y = 0; y < k[0].size(); y++)
			     cout << setw(4) << k[x][y];
			   cout << endl;;
			}	
    	
    }	
	return 0;
}



/*for (int i = 0; i < Matrica.size(); i++)\
		for (int j = 0; j < Matrica[i].size(); j++)
			{
				if (i < hv.size() && j < hv[0].size())
					Matrica[i][j] = hv[i][j];
				else if (j > hv.size() && j < Matrica.size() - hv.size() &&
				i < Matrica.size() - M.size() - v.size())
					Matrica[i][j] = v[i][j];
				else if (i < Matrica.size() - h.size() - hv.size() &&
				j > Matrica[0].size() - hv[0].size() - v[0].size())
					Matrica[i][j] = hv[i][j];
				else if (i > hv.size() && j < h[0].size())
					Matrica[i][j] = h[i][j];
				else if (i > v.size() && i < v.size() + M.size() &&
				j > h[0].size() - 1 && j < hv[0].size() + M[0].size())
					Matrica[i][j] = M[i][j];
				else if (i > hv.size() && i < h.size() + hv.size() &&
				j > hv[0].size() + v[0].size() - 1)
					Matrica[i][j] = hv[i][j];
				else if (i > hv.size() + h.size() - 1 && j < hv[0].size())
					Matrica[i][j] = hv[i][j];
				else if (i > v.size() + M.size() - 1 && j > hv[0].size() - 1 &&
				j < Matrica[0].size() - hv[0].size())
					Matrica[i][j] = v[i][j];
				else if (i > hv.size() + h.size() - 1 && j > hv[0].size() + v[0].size() - 1)
					Matrica[i][j] = hv[i][j];
			}*/