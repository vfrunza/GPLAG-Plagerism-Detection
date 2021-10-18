#include <vector>
#include <iostream>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
// Vraća broj redova zadane matrice
int BrojRedova(Matrica m) {
 return m.size();
}
// Vraća broj kolona zadane matrice
int BrojKolona(Matrica m) {
 return m[0].size();
}
bool DalJeGrbava(Matrica m)
{
	int sirina(BrojKolona(m));
	for(auto red: m)
	{
		int b(0);
		for(auto x:red)
		{
			b++;
		}
		if(b!=sirina) return true;
	}
	return false;
}
//Kreira Matricu
Matrica KreirajMatricu(int broj_redova, int broj_kolona) {
 return Matrica(broj_redova, std::vector<double>(broj_kolona));
}

Matrica NajvecaPlaninaMatrice(Matrica m)
{
	
	if(DalJeGrbava(m)) throw std::domain_error("Matrica nije korektna");
	Matrica M;
	double max=m.at(0).at(0);
	for(auto red:m)
	{
		for(auto x: red)
		if(x>max) max=x;
	}
	std::vector<double>V;
	V.push_back(max);
	M.push_back(V);
	
	return M;

}
int main ()
{
	try{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	std::cout<<"Unesite elemente matrice:"<<std::endl;
	Matrica A(KreirajMatricu(m,n));
	for(int i(0);i<m;i++){
		for(int j(0);j<n;j++){
			std::cin>>A.at(i).at(j);
		}
	}
	Matrica M(NajvecaPlaninaMatrice(A));
	std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
	int sirina(5);
	for(auto red: M)
	{
		for(auto x:red)
		std::cout<<" "<<std::setw(sirina)<<std::right<<x;
		std::cout<<std::endl;
	}
	
	}
	catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    
	return 0;
}