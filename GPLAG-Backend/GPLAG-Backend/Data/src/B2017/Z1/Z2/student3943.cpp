#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
double Najvecielemenat(std:: vector<std::vector<double>> m)
{
	double max=m[0][0];
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.at(0).size(); j++) {
			if(max<m.at(i).at(j)) max=m.at(i).at(j);

		}



	}



	return max;
}
int NajvecaSirina(int i,int j,std::vector<std::vector<double>> m)
{
	int brojac;
	if(j<m.at(0).size()/2 && i<m.size()/2) {
		if(i<=j) brojac=i;
		else brojac=j;
	} else if(j<m.at(0).size()/2 && i>=m.size()/2 ) {

		if(m.size()-i-1<=j) brojac=m.size()-i-1;
		else brojac=j;
	}

	else if(j>=m.at(0).size()/2 && i<m.size()/2) {
		if(i<=m.at(0).size()-j-1) brojac=i;
		else brojac=m.at(0).size()-j-1;

	} else if(j>=m.at(0).size()/2 && i>=m.size()/2) {
		if(m.size()-i-1<=m.at(0).size()-j-1)
			brojac=m.size()-i-1;
		else brojac=m.at(0).size()-j-1;
	}

	return brojac;
}
std:: vector<std::vector<double>>NajvecaPlaninaMatrice(std::vector<std::vector<double>> m)
{
	if(m.size()==0 || m.at(0).size()==0) return std:: vector<std::vector<double>>(0);
	for(int i=0; i<m.size()-1; i++) {
		if(m.at(i).size()!=m.at(i+1).size()) throw std::domain_error("Matrica nije korektna");

	}









	std:: vector<std::vector<double>> mat;
	std:: vector<std::vector<double>> matmax;
	for(int i=1; i<m.size()-1; i++) {
		for(int j=1; j<m.at(0).size()-1; j++) {

			double sumamin(m.at(i).at(j));

			double suma2(m.at(i).at(j));
			for(int p=1; p<=NajvecaSirina(i,j,m); p++) {

				double suma=0;
				for(int k=i-p; k<=i+p; k++) {
					for(int m1=j-p; m1<=j+p; m1++) {

						suma=suma+m.at(k).at(m1);


					}
				}
				double suma1=suma-suma2;
				suma2=suma;
				if(suma1<sumamin) {
					sumamin=suma1;
					mat.resize(2*p+1);
					int brojac(0);
					for(int v=i-p; v<=i+p; v++) {
						for(int d=j-p; d<=j+p; d++) {

							mat.at(brojac).push_back(m.at(v).at(d));
						}
						brojac++;
					}

					if(matmax.size()<mat.size()) {
						matmax=std::move(mat);
						mat=std::vector<std::vector<double>>(0);
					} else if(matmax.size()==mat.size() && matmax.at((2*p+1)/2).at((2*p+1)/2)<mat.at((2*p+1)/2).at((2*p+1)/2)) {
						matmax=std::move(mat);
						mat=std::vector<std::vector<double>>(0);
					} else continue;

				}


				else break;



			}


		}

	}
	if(matmax.size()==0)
		return {{Najvecielemenat(m)}};






	return matmax;
}

int main()
{
	try {

		std::cout<<"Unesite dimenzije matrice (m i n): ";
		int m,n;
		std::cin>>m>>n;
		if(m<0 || n<0) {
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout<<"Unesite elemente matrice:"<<std::endl;
		std:: vector<std::vector<double>> mat(m,std::vector<double>(n));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {

				std::cin>>mat.at(i).at(j);
			}


		}
		std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
		std::vector<std::vector<double>> podmat(NajvecaPlaninaMatrice(mat));
		for(int i=0; i<podmat.size(); i++) {
			for(int j=0; j<podmat.at(0).size(); j++) {

				std::cout<<std::setw(6)<<std::right<<podmat.at(i).at(j);
			}
			std::cout<<std::endl;




		}
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}




	return 0;
}


