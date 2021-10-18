#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

void IspisiMatricu(Matrica m)
{
	for(int i{0}; i < m.size(); i++)
	{
		for(int j{0}; j < m[i].size(); j++)
			std::cout << m[i][j] << " ";
		std::cout << std::endl;
	}
}


Matrica RastuciPodnizovi(std::vector<double> vektor)
{
	Matrica m;
	
	int br_elemenata{0};
	for(int i{0}; i < vektor.size(); i++)
	{
		std::vector<double> novi;
		while(i < vektor.size() - 1 && vektor[i] <= vektor[i+1])
		{
			novi.push_back(vektor[i]);
			i++;
			br_elemenata++;
		}
		if(i != vektor.size())
			novi.push_back(vektor[i]);
		if(br_elemenata > 0)
			m.push_back(novi);
		br_elemenata = 0;
	}
	
	return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> vektor)
{
	Matrica m;
	
	int br_elemenata{0};
	for(int i{0}; i < vektor.size(); i++)
	{
		std::vector<double> novi;
		while(i < vektor.size() - 1 && vektor[i] >= vektor[i+1])
		{
			novi.push_back(vektor[i]);
			i++;
			br_elemenata++;
		}
		if(i != vektor.size())
			novi.push_back(vektor[i]);
		if(br_elemenata > 0)
			m.push_back(novi);
		br_elemenata = 0;
	}
	
	
	return m;
}


std::vector<double> UnesiVektor(std::vector<double> vektor)
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cin.clear();
	std::cout << "Unesite elemente vektora: ";
	double element;
	for(int i{0}; i < n; i++)
	{
		std::cin >> element;
		vektor.push_back(element);
	}
	
	return vektor;
}

int main ()
{
	std::vector<double> vektor;
	vektor = UnesiVektor(vektor);

	
	Matrica rastuci;
	Matrica opadajuci;
	
	rastuci = RastuciPodnizovi(vektor);
	opadajuci = OpadajuciPodnizovi(vektor);
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	IspisiMatricu(rastuci);
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	IspisiMatricu(opadajuci);
	return 0;
}