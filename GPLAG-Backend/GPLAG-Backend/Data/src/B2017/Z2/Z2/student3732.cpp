/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <type_traits>
#include <vector>
#include <deque>

enum class SmjerKretanja { 
	NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo
};
template<typename TIP>
auto Gore_Dolje(TIP kont,int i)->typename std::remove_reference<decltype(kont[0])>::type{
	typename std::remove_reference<decltype(kont[0])>::type matrica;
	int z(0);
	int r(0);
	for(int j=0;j<=(kont[i].size())/2;j++){
		for(int k=r;k<kont[i][j].size()-r;k++){
		   matrica[z].push_back(kont[j][k]);
		}
		z++;
		r++;
	}
	int j=kont[i].size()/2;
	r=kont[i][j].size()/2;
	for(j=(kont[i].size())/2;j<kont[i][j].size();j++){
		for(int k=r;k<kont[i][j].size()-r;k++){
			matrica[z].push_back(kont[j][k]);
		}
		z++;
		r--;
	}
	return matrica;
}
template<typename tip>
auto PjescaniSat(tip Kont,SmjerKretanja a)->typename std::remove_reference<decltype(Kont[0])>::type{
	typename std::remove_reference<decltype(Kont[0])>::type mat;
	int duzina1(Kont[0].size());
	int duzina2(Kont[0][0].size());
	int br(0);
	for(int i=0;i<Kont.size();i++){
		for(int j=0;j<Kont[i].size();j++){
			if(duzina2!=Kont[i][j].size()) throw domain_error("3D matrica nema oblik kocke");
			else if(duzina2!=Kont[j][k].size()) throw domain_error("3D matrica nema oblik kocke"),
		}
		br++;
	}
	if(br!=Kont.size()) throw domain_error("3D matrica nema oblik kocke");
	for(int i=0;i<Kont.size();i++){
		for(int j=0;j<Kont[i].size();j++){
			for(int k=0;k<Kont[i][j].size();k++){
				mat[i]=GoreDolje(Kont,i);
			}
		}
	}
	return mat;
}
int main ()
{
	return 0;
}