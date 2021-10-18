/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

// Kreira matricu sa zadanim brojem redova i kolona
Matrica KreirajMatricu(int br_redova, int br_kolona) 
{

	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica KreirajMatricu_mat(int br_redova, int br_kolona) 
{
	return Matrica(3*br_redova, std::vector<double>(3*br_kolona));
}


// Vraća broj redova zadane matrice
int BrojRedova(Matrica m) 
{
	return m.size();
}

// Vraća broj kolona zadane matrice
int BrojKolona(Matrica m) 
{
    
	return m[0].size();
}

// Unosi sa tastature matricu sa zadanim brojem redova i kolona i
// vraća je kao rezultat
Matrica UnesiMatricu(int br_redova, int br_kolona) 
{
	auto m(KreirajMatricu(br_redova, br_kolona));

 	for(int i = 0; i < br_redova; i++)
 	{
 		for(int j = 0; j < br_kolona; j++) 
 		{
 			std::cin >> m[i][j];
 		}
 	}	
 	return m;
}

// Ispisuje zadanu matricu
void IspisiMatricu(Matrica m) 
{
	std::cout<<"Rezultantna matrica: "<<std::endl;
	
 	for(int i = 0; i < BrojRedova(m); i++) 
 	{
 		for(int j = 0; j < BrojKolona(m); j++)
 			std::cout <<std::setw(4)<< m[i][j];
 		std::cout << std::endl;
 	}
}

Matrica OgledaloMatrica(Matrica m)
{
    
    if(BrojRedova(m)==0 || BrojKolona(m)==0)
        return m;
    
        
    for(int i=0;i<BrojRedova(m);i++)
    {
        if(m[i].size()!=m[0].size())
            throw std::domain_error("Matrica nije korektna");
    }
	auto mat(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	
	if( BrojKolona(m)==0)
	  {
	      mat.resize(3*BrojRedova(m));
	      return mat;
	  }
	mat.resize(3*BrojRedova(m)); // 10 redova
    for(int i = 0; i < 3*BrojRedova(m); i++) mat[i].resize(3*BrojKolona(m));

	for(int i=0;i<3*BrojRedova(m);i+=BrojRedova(m))
	{
	    if(i==0)
        {
		for(int j=0;j<BrojRedova(m);j++)
			{
			    for(int k=0;k<BrojKolona(m);k++)
                    mat[j][k]=m[BrojRedova(m)-j-1][BrojKolona(m)-k-1];

                for(int k=BrojKolona(m);k<2*BrojKolona(m);k++)
                    mat[j][k]=m[BrojRedova(m)-j-1][k-BrojKolona(m)];

                for(int k=2*BrojKolona(m);k<3*BrojKolona(m);k++)
                    mat[j][k]=m[BrojRedova(m)-j-1][3*BrojKolona(m)-k-1];
			}
        }
        else if(i==BrojRedova(m))
        {
            for(int j=BrojRedova(m);j<2*BrojRedova(m);j++)
			{
                for(int k=0;k<BrojKolona(m);k++)
                    mat[j][k]=m[j-BrojRedova(m)][BrojKolona(m)-k-1];

                for(int k=BrojKolona(m);k<2*BrojKolona(m);k++)
                    mat[j][k]=m[j-BrojRedova(m)][k-BrojKolona(m)];

                for(int k=2*BrojKolona(m);k<3*BrojKolona(m);k++)
                    mat[j][k]=m[j-BrojRedova(m)][3*BrojKolona(m)-k-1];
			}
        }
        else if(i==2*BrojRedova(m))
        {
            for(int j=2*BrojRedova(m);j<3*BrojRedova(m);j++)
			{
			    for(int k=0;k<BrojKolona(m);k++)
                    mat[j][k]=m[3*BrojRedova(m)-j-1][BrojKolona(m)-k-1];

                for(int k=BrojKolona(m);k<2*BrojKolona(m);k++)
                    mat[j][k]=m[3*BrojRedova(m)-j-1][k-BrojKolona(m)];

                for(int k=2*BrojKolona(m);k<3*BrojKolona(m);k++)
                    mat[j][k]=m[3*BrojRedova(m)-j-1][3*BrojKolona(m)-k-1];
			}
        }
    }
	return mat;
}

// Glavni program
int main() 
{
    try
    {
 	int m1, n1;
 	std::cout << "Unesite dimenzije matrice (m n): ";
 	std::cin >> m1 >> n1;
 	if(m1<0 || n1<0)
 	{
 		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
 		return 0;
 	}
 	
 	std::cout << "Unesite elemente matrice: "<<std::endl;
	auto A(UnesiMatricu(m1,n1));

	auto v(OgledaloMatrica(A));
 	
 	IspisiMatricu(v);
    }
    catch(std::domain_error izuzetak)
    {
        std::cout << izuzetak.what() << std::endl;
    }    
 	
 	return 0;
}