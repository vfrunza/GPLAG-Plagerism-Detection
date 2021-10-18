/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <cmath>
#include <vector>
#include <iostream>
std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> a){
	std::vector<std::vector<double>> c;
	std::vector<double> c2;
	int t(0),g(0),a2(2);
	double sum,temp(0),sum2,max2(0);
	bool vec(true);
	int counter,max(0);
	for (std::vector<double> red : a ){
		for (double k : red){
			if (t!= 0 && g != 0 && t != a.size() && g!= red.size()){
				sum = a.at(t).at(g+1) + a.at(t+1).at(g+1) + a.at(t+1).at(g) + a.at(t+1).at(g-1) + a.at(t).at(g-1) + a.at(t - 1).at(g-1) + a.at(t - 1).at(g) + a.at(t -1).at(g+1);
				temp = sum;
				if ( sum < a.at(t).at(g)){
					vec = true;
				}
				if (vec == true){
					while(vec == true){
						temp = temp + sum + sum2;
						for(int s = 0; s< a2;s++){
							for(int s2 = 0;s2 < 2*(a2) + 1;s2++){
								sum2 = sum2 + a.at(s + (t-a2)).at(s2 +(g-a2));
							}
						}
						sum2 = sum2 - k - temp;
						if (sum2 > sum){
							vec = false;
						} else{
							sum = sum2;
							a2++;
						}
						}
					if ( a2 > max){
						max = a.at(t).at(g);
						for(int s = 0; s< a2;s++){
							for(int s2 = 0;s2 < 2*(a2) + 1;s2++){
								c.at(counter).push_back(a.at(s + (t-a2)).at(s2 +(g-a2)));
							}
							counter++;
						}
					} else if (a2 == max && a.at(t).at(g) > max2){
						max2 =a.at(t).at(g);
						for(int s = 0; s< a2;s++){
						for(int s2 = 0;s2 < 2*(a2) + 1;s2++){;
							c.at(counter).push_back(a.at(s + (t-a2)).at(s2 +(g-a2)));
						}
						counter++;
						}
					} 
				}
			}
			t++;
			g++;
		}
			
	}
return c;
}
	

int main ()
{

	double b;
	int m,n;
	std::vector<std::vector<double>> rez;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m;
	std::cin >> n;
	std::vector<std::vector<double>> a(m,std::vector<double> (n));
	std::cout << "Unesite elemente matrice: ";
	for(int k =0;k <m;k++){
		for(int g = 0;g<n;g++){
			std::cin >> b;
			a.at(k).at(g) == b;
		}
	}
	rez = NajvecaPlaninaMatrice(a);
	for(std::vector<double> row: rez){
		for(double t : row){
		std::cout << t;
	}
	}
	return 0;
}