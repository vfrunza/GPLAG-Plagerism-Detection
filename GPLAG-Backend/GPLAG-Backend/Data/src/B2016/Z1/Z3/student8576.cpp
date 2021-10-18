#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
	std::vector<double> a;
	std::vector<std::vector<double>> mat;
	
	
	return mat;
}
int main ()
{
	
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::vector<double> a(n);

	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >> a[i];
		
	}
	
	std::vector<std::vector<double>> c;
	c=RastuciPodnizovi(a);
	
	for(int i=0; i<c.size(); i++) {
		for(int j=0; j<c[0].size(); j++) {
			std::cout << c[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	
	return 0;
	
}