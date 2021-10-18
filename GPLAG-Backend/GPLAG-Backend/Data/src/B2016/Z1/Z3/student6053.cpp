/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova,int broj_kolona){
	return Matrica(broj_redova,vector<int>(broj_kolona));
}
Matrica RastuciPodnizovi(vector<int> v){
	

}
Matrica OpadajuciNizovi(vector<int> v){
	
}

int main ()
{
	vector<int>  v;
	int n;
	cout << "Koliko zelite unijeti elementa: ";
	cin>>n;
	int broj;
	for(int i=0;i<n;i++){
	cin >> broj; 
	v.push_back(broj);
	}
	Matrica a;
	Matrica b;
	a=RastuciPodnizovi(v);
	b=OpadajuciNizovi(v);
	

	}
	return 0;
}