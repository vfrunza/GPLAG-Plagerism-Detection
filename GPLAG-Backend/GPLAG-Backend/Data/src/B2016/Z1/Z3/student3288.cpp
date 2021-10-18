/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <iomanip>


std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v) {

	std::vector<std::vector<double> > m(v.size());
	int vel(0);
	std::vector<double> pom(vel);
	int j(0);

	for(int i=0; i<v.size(); i++) {

		if(i==0) {
					if(v[i]<=v[i+1])	{
						pom.push_back(v[i]);
						vel++;
					}
		}

		if(i==v.size()-1) {
							if(v[i]>=v[i-1]) {
								pom.push_back(v[i]);
								vel++;

								for(int k=0; k<vel; k++) {
									m[j].resize(k+1);
								}

								for(int k=0; k<vel; k++) {
									m[j][k] = pom[k];
								}

								vel=0;
								pom.resize(vel);
								j++;
							}
		}

		if(i!=v.size()-2 && i!=v.size()-1) {

					if(v[i+1]>=v[i] && v[i+1]<=v[i+2]) {
						pom.push_back(v[i+1]);
						vel++;
					}

					else if(v[i+1]>=v[i] && v[i+1]>=v[i+2]) {
						pom.push_back(v[i+1]);
						vel++;

					for(int k=0; k<vel; k++) {
						m[j].resize(k+1);
					}

					for(int k=0; k<vel; k++) {
						m[j][k] = pom[k];
					}

					vel = 0;
					pom.resize(vel);
					j++;
				}

				else if(v[i+1]<=v[i] && v[i+1]<=v[i+2]) {
					pom.push_back(v[i+1]);
					vel++;
				}
		}

	}

	return m;
}



std::vector<std::vector<double>>  OpadajuciPodnizovi (std::vector<double> v) {

	std::vector<std::vector<double>> m(v.size());
	int vel(0);
	std::vector<double> pom(vel);
	int j(0);

	for(int i=0; i<v.size(); i++) {

		if(i==0) {
				if(v[i]>=v[i+1]) {
					pom.push_back(v[i]);
					vel++;
				}
		}

		if(i==v.size()-1) {
			if(v[i]<=v[i-1]) {
				pom.push_back(v[i]);
				vel++;

				for(int k=0; k<vel; k++) {
					m[j].resize(k+1);
				}

				for(int k=0; k<vel; k++) {
					m[j][k] = pom[k];
				}

				vel=0;
				pom.resize(vel);
				j++;
			}
		}

		if(i!=v.size()-1 && i!=v.size()-2) {

			if(v[i+1]<=v[i] && v[i+1]>=v[i+2]) {
						pom.push_back(v[i+1]);
						vel++;
			}

			else if(v[i+1]<=v[i] && v[i+1]<=v[i+2]) {
				pom.push_back(v[i+1]);
				vel++;

				for(int k=0; k<vel; k++) {
					m[j].resize(k+1);
				}

				for(int k=0; k<vel; k++) {
					m[j][k] = pom[k];
				}

				vel = 0;
				pom.resize(vel);
				j++;
			}

			else if(v[i+1]>=v[i] && v[i+1]>=v[i+2]) {
				pom.push_back(v[i+1]);
				vel++;
			}
		}
	}

	return m;
}


int main ()
{
	int vel;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> vel;
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> brojevi;

	//Testovi:
//	std::vector<double> brojevi = {1, 3, 2, 6, 7, 9, 10, 4, 3, 1, 7, 0, 0, 0, 1, -1, 2};
//	std::vector<double> brojevi {0.1111111111, 0.1111111119, 0.11, 0.1, -0.11, -0.111};
//	std::vector<double> brojevi {0.1, 0.1, 0.9, 0.9, -0.1, 0.1, -0.9, 0.9, -0.1, 0.1, 0.9, 0.9, 0.1, -0.1, 0.9, -0.9};
//	std::vector<double> brojevi {10, 1, 2, 3, 4, 3, 2, 1, 2, 3, 4};
//	std::vector<double> brojevi {19, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//	std::vector<double> brojevi {0.1, 0.1, 0.1};

	// unos elementa u vektor
	int broj;
	for(int i=0; i<vel; i++) {
		std::cin >> broj;
		brojevi.push_back(broj);
	}


	std::vector<std::vector<double>> a, b;

	// Rastuci podnzovi:
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	a = RastuciPodnizovi(brojevi);
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a[i].size(); j++) {
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	// Opadajuci podnizovi:
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	b = OpadajuciPodnizovi(brojevi);
	for(int i=0; i<b.size(); i++) {
		for(int j=0; j<b[i].size(); j++) {
			std::cout << b[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}