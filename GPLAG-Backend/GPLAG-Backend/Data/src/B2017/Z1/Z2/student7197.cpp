#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
typedef std::vector<std::vector<double> > Matrica;


Matrica NajvecaPlaninaMatrice(Matrica m)
{
	double max = m.at(0).at(0);
	for(int i = 0; i < m.size(); i ++) {
		for (int j = 0; m.at(i).size(); j++) {
		
		}
	}
	for (int i = 0; m.size(); i ++){
		for (int j = 0; m.at(i).size(); j++){
			if(m.at(0).at(j)== max || m.at(m.size()).at(j)== max )
		}
	}
	Matrica Planina;
	
	return Planina;
}

int NajvecaSirina ( Matrica m)
{
    int sirina = 0, br = 0,max=0;
    for(int i = 0; i <m.size(); i++) {
        for(int j = 0; j < m.at(i).size(); j ++) {
            int broj = m.at(i).at(j);
            if(broj<0) br++;
            while(broj!=0) {
                broj /= 10;
                br++;
            }
            if (br > max) max = br;
            br=0;
        }
    }
    return max;
}
int main ()
{
	std::cout << "Unesite m i n: ";
	int m,n;
	std::cin >> m >> n; //broj redova i kolona
	Matrica GlavnaMatrica;
	double Elementi;

	//unos elemenata u matricu
	for (int i = 0; i < m; i++) {
		std::vector<double> temp;
		for(int j = 0; j < n; j++) {
			std::cin>> Elementi;
			temp.push_back(Elementi);
		}
		GlavnaMatrica.push_back(temp);
	}
	int z = NajvecaSirina(GlavnaMatrica);
	NajvecaPlaninaMatrice(GlavnaMatrica);

	//Ispis matrice
//	double max= GlavnaMatrica.at(0).at(0);
	for(int i = 0; i < GlavnaMatrica.size(); i++) {
		for (int j = 0; j < GlavnaMatrica.at(i).size(); j++) {
			std::cout << std::setw(z + 1) << GlavnaMatrica.at(i).at(j);
		}
		std::cout << std::endl;
	}
	return 0;
}