#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
typedef vector<vector<double>> Matrica;

Matrica izvrni_vertikalno(Matrica iz_glovne)
{
	Matrica odavd;												//testirano za 3x3
	for(int i(0);i<iz_glovne.size();i++)						//testirano za 4X4
	{															//testirano za 4x9
		odavd.push_back(iz_glovne.at(iz_glovne.size()-1-i));	//testirano za 1x9
	}															//testirano za 5x2
	return odavd;
}

Matrica izvrni_horizontalno(Matrica iz_glovne)			//testirano za 3x3
{														//testirano za 3x2
	Matrica odavd(iz_glovne.size());					//testirano za 2x3
	for(int i(0);i<iz_glovne.size();i++)				//testirano za 5x2
	{
		for(int j(0);j<iz_glovne.at(i).size();j++)
			odavd.at(i).push_back(iz_glovne.at(i).at(iz_glovne.at(i).size()-1-j));
	}
	return odavd;
}

Matrica kombinacija(Matrica iz_glovne)
{
	return izvrni_horizontalno(izvrni_vertikalno(iz_glovne));
}
vector<double> spoji_vektore(vector<double> jedan,vector<double> dva, vector<double> tri )
{
	for(int i(0);i<dva.size();i++)
	{
		jedan.push_back(dva.at(i));
	}
	for(int i(0);i<tri.size();i++)
	{
		jedan.push_back(tri.at(i));
	}
	return jedan;
}
Matrica OgledaloMatrica(Matrica iz_glovne)
//reba vratiti matricu 3 puta vecu tj 3m X 3n
//zato je mozemo popunjaati po trecinama
{
	Matrica vertikalna(izvrni_vertikalno(iz_glovne));
	Matrica horizontalna(izvrni_horizontalno(iz_glovne));
	Matrica kobinovana(kombinacija(iz_glovne));
	Matrica povratna;
	for(int i(0);i<iz_glovne.size();i++)// prva trecina hv | v | hv
	{
		povratna.push_back(spoji_vektore(kobinovana.at(i),vertikalna.at(i),kobinovana.at(i)));
	}
	for(int i(0);i<iz_glovne.size();i++)//druga trecina h | 0 | h
	{
		povratna.push_back(spoji_vektore(horizontalna.at(i),iz_glovne.at(i),horizontalna.at(i)));
	}
	for(int i(0);i<iz_glovne.size();i++)// prva trecina = treca trecina
	{
		povratna.push_back(spoji_vektore(kobinovana.at(i),vertikalna.at(i),kobinovana.at(i)));
	}
	return povratna;
}
int main ()
{
	cout << "Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m;
	cin>>n;
	if(m<0 || n<0)
	{
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica glavna(m);
	cout << "Unesite elemente matrice: "<<endl;
	for(int i(0);i<m;i++)
	{
		for(int j(0);j<n;j++)
		{
			double broj;
			cin>>broj;
			glavna.at(i).push_back(broj);
		}
	}
	for(int i(0);i<glavna.size();i++)
	{
		if(glavna.at(0).size()!=glavna.at(i).size())throw std::domain_error("Matrica nije korektna");
	}
	try{
		Matrica modif(OgledaloMatrica(glavna));
		cout<<"Rezultantna matrica: "<<endl;
		for(auto x:modif)
		{
			for(auto y:x)
				cout<<std::setw(4)<<y;
			cout<<endl;	
		}
	}
	catch(std::domain_error izuzetak){cout<<izuzetak.what();}
	return 0;
}