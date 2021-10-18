// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>




int main ()
{
    int x, y, z;
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    int unos(0);
    std::vector<std::vector<int>> v(y, std::vector<int>(z));
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    do
    {
        for (int i(0); i<y; i++)
        {
            for (int j(0); j<z; j++)
            {
                std::cin >> v[i][j];
            }
        }
        unos++;
    }while (unos > x);
    
	return 0;
}