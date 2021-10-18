/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector> 

typedef std::vector<std::vector<double>> Matrica;


Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

int BrojRedova (Matrica m){
	return m.size();
}

int BrojKolona (Matrica m){
	return m[0].size();
}

Matrica UnesiMatricu (int br_redova, int br_kolona){
	auto m( KreirajMatricu (br_redova, br_kolona));
	for(int i=0; i<br_redova; i++)
	for(int j=0; j<br_kolona; j++){
		std::cout << "Element (" << i+1 << ", "<< j+1<<"): "; 
		std::cin>>m[i][j];
	}
	return m;
}


Matrica OgledaloMatrica(Matrica m)
{
	Matrica NovaMatrica( KreirajMatricu( BrojRedova(m)*3, BrojKolona(m)*3 ) );
	
	
}

int main ()
{
	return 0;
}