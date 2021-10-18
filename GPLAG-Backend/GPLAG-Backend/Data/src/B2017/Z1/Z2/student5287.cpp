#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>

typedef std::vector<double> vector;
typedef std::vector<std::vector<double>> matrix;

double sumaPrstena(matrix m, int x, int y, int prsten){
	double suma = 0;
	
	//Po gornjoj granici
	for(int i = x - prsten; i <= x + prsten; i++){
		suma += m.at(y-prsten).at(i);
	}
	//Po donjoj granici
	for(int i = x - prsten; i <= x + prsten; i++){
		suma += m.at(y+prsten).at(i);
	}
	//Po lijevoj granici
	for(int i = y - (prsten-1); i <= y + (prsten-1); i++){
		suma += m.at(y).at(x-prsten);
	}
	//Po desnoj granici
	for(int i = y - (prsten-1); i <= y + (prsten-1); i++){
		suma += m.at(y).at(x+prsten);
	}
	
	return suma;
}

bool jestePlanina(matrix m, int x, int y, int maxRadius){
	double unutrasnjaSuma;
	double suma;
	
	//Postavimo da je vrh unutrasnja suma
	unutrasnjaSuma = m.at(y).at(x);
	
	for(int i = 1; i <= maxRadius; i++){
		//Racunamo sumu trenutnog prstena
		suma = sumaPrstena(m, x, y, i);
		//Te ako je veca od unutrasnjeg, onda za maxRadius ova matrica nije planina
		if(suma >= unutrasnjaSuma){
			return false;
		}
		unutrasnjaSuma = suma;
	}
	
	return true;
}

matrix Planina(matrix m, int x, int y, int radius){
	//Vraca planinu iz velike matrice iz tacke (x,y) i radiusa radius
	matrix toret(2 * radius + 1, vector(2 * radius + 1, 0.) );
	
	for(int i = -radius; i <= radius; i++){
		for(int j = -radius; j <= radius; j++){
			toret.at(i+radius).at(j+radius) = m.at(i + y).at(j + x);
		}
	}
	
	return toret;
}

void PrintMatrix(matrix m){
	for(vector v : m){
		for(double d : v) std::cout << std::setw(6) << d;
		std::cout << std::endl;
	}
}

void Grbava(matrix m){
	//Ako je velicina matrice manja ili jednaka jedan
	//nema smisla govoriti o "grbavosti" matrice
	if(m.size() <= 1) return;
	
	int size = m.at(0).size();
	for(int i = 1; i < m.size(); i++){
		//U slucaju da je velicina reda razlicita od prethodnog bacamo izuzetak
		if(m.at(i).size() != size) 
			throw std::domain_error("Matrica nije korektna");
		
		size = m.at(i).size();
	}
}

matrix NajvecaPlaninaMatrice(matrix m){
	//Provjerava jel' matrica grbava
	Grbava(m);
	
	//Ako je matrica 0 matrica
	if(m.size() == 0) return m;
	
	//Max radius prstena
	int maxRadius = (m.size() <= m.at(0).size())? m.size() : m.at(0).size();
	maxRadius = std::ceil(maxRadius/2.) - 1;
	
	//Treba sve planine istog formata smjestiti u vektor
	//a posto nema smisla traziti one manjeg formata
	//found se koristi kao flag za prekidanje funkcije
	bool found;
	std::vector<matrix> planine;
	
	while(maxRadius >= 0){
		found = false;
		
		//Dvije petlje pretrazuju unutrasnji dio matrice, trazeci planine
		//najveceg moguceg formata
		for(int dy = m.size() - maxRadius - 1; dy >= maxRadius; dy--){
			for(int dx = m.at(0).size() - maxRadius - 1; dx >= maxRadius; dx--){
				if(jestePlanina(m, dx, dy, maxRadius)){
					matrix p = Planina(m, dx, dy, maxRadius);
					
					//Planine jednakih formata koje se dodaju u vektor, dodaju se na nacin
					//da one koje su viseg vrha i manjih kordinata dolaze na kraj vektora
					if(planine.size() == 0 || p.at(maxRadius).at(maxRadius) >= planine.at(planine.size()-1).at(maxRadius).at(maxRadius)){
						planine.push_back(p);
					}
					
					found = true;
				}
			}
		}
		
		if(found){
			//Posto smo nasli matricu maxRadius formata, nema razloga traziti one manjeg formata
			return planine.at(planine.size()-1);
		}
		
		//Nije nadjena planina radiusa maxRadius, smanji maxRadius
		maxRadius--;
	}
	
	return matrix(0);
}

int main ()
{
	int m, n;
	
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	if(n < 0 || m < 0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	matrix mat(m, vector(n));
	
	std::cout << "Unesite elemente matrice:";
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			std::cin >> mat.at(i).at(j);
		}
	}
	
	std::cout << "\nNajveca planina unesene matrice je:\n";
	PrintMatrix(NajvecaPlaninaMatrice(mat));
	
	return 0;
}