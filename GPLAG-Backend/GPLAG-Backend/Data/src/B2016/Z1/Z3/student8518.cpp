/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include<iostream>
#include<vector>
typedef std::vector<std::vector<double>> Matrica ;

Matrica RastuciPodnizovi ( std::vector<double>v )
{
	Matrica M;
	bool x(true);
	int l(0);
	int vel(v.size());
	for(int i=0; i<vel-1; i++) {

		if( v[i]<= v[i+1] ) {
			if (x==true) {
				M.push_back( std::vector<double>(0) );
				x=false;
			}

			M[l].push_back(v[i]);



			if(i==vel-2 && ( v[i]<=v[i+1] ) ) {
				M[l].push_back(v[i+1]);
				break;
			}
		}

		else if(x==false) {
			x=true;
			M[l].push_back(v[i]);
			l++;
		}
	}
	return M;
}

Matrica OpadajuciPodnizovi ( std::vector<double>v )
{
	Matrica M;
	bool x(true);
	int l(0);
	int vel(v.size());
	for(int i=0; i<vel-1; i++) {

		if( v[i] >= v[i+1] ) {
			if (x==true) {
				M.push_back( std::vector<double>(0) );
				x=false;
			}

			M[l].push_back(v[i]);



			if(i==vel-2 && ( v[i]>=v[i+1] ) ) {
				M[l].push_back(v[i+1]);
				break;
			}
		}

		else if(x==false) {
			x=true;
			M[l].push_back(v[i]);
			l++;
		}
	}
	return M;
}

int main ()
{
	int n(0);
	double e(0);
	std::vector<double>v ;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin >> e;
		v.push_back(e);
	}

	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(std::vector<double> x : RastuciPodnizovi(v) ) {
		for(double y : x) {
			std::cout << y <<" ";
		}
		std::cout << std::endl;
	}

	std::cout << "Maksimalni opadajuci podnizovi:" << std::endl;
	for(std::vector<double> x : OpadajuciPodnizovi(v) ) {
		for(double y : x) {
			std::cout << y <<" ";
		}
		std::cout << std::endl;
	}
	return 0;
}
