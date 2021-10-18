#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrix;

Matrix NajvecaPlaninaMatrice(Matrix x)
{
	Matrix mali;
	if(x.size()==0 || x.at(0).size()==0)return mali;
	int duzinaReda(x.at(0).size());
	for(int i=0; i<x.size(); i++)
		if(x.at(i).size()!=duzinaReda)throw std::domain_error("Matrica nije korektna");
	if(x.size()<3) {
		mali.resize(1);
		double max(x.at(0).at(0));
		for(int i=0; i<x.size(); i++)
			for(int j=0; j<x.at(i).size(); j++)
				if(x.at(i).at(j)>max)max=x.at(i).at(j);
		mali.at(0).push_back(max);
		return mali;
	}
	Matrix Final;
	int prekidac(1);
	double vrhStart(0);
	int indexPrvi(0),indexDrugi(0),indexTreci(0),indexCetvrti(0);
	int index1(0),index2(0),index3(0),index4(0);
	int duzina1(0),duzina2(0),IndexVrha(0),JndexVrha(0);
	for(int i=0; i<x.size(); i++) {
		for(int j=0; j<x.at(i).size(); j++) {
			if(i!=0 && j!=0 && i!=x.size()-1 && j!=x.at(i).size()-1) {
				double suma(x.at(i-1).at(j-1)+x.at(i-1).at(j)+x.at(i-1).at(j+1)+x.at(i).at(j-1)+x.at(i).at(j+1)+x.at(i+1).at(j-1)+x.at(i+1).at(j)+x.at(i+1).at(j+1)  );
				if(x.at(i).at(j)>suma) {
					suma=x.at(i).at(j);
					for(int z=1;; z++) {
						if(((i-z)<0) || ((j-z)<0) || ((j+z)>x.at(i).size()-1) || ((i+z)>x.size()-1)) {
							break;
						}
						if(prekidac) {
							vrhStart=x.at(i).at(j);
							indexPrvi=i-z;
							indexDrugi=j-z;
							indexTreci=i-z;
							indexCetvrti=j+z;
							duzina1=indexCetvrti-indexDrugi;
							IndexVrha=i;
							JndexVrha=j;
							prekidac=0;
						}
						double novaSuma	(x.at(i-z).at(j-z)+x.at(i-z).at(j)+x.at(i-z).at(j+z)
						                 +x.at(i).at(j-z)+x.at(i).at(j+z)
						                 +x.at(i+z).at(j-z)+x.at(i+z).at(j)+x.at(i+z).at(j+z));
						if(suma>novaSuma) {
							index1=i-z;
							index2=j-z;
							index3=i+z;
							index4=j+z;
							duzina2=index3-index1;
							suma=novaSuma;
						} else break;
					}
					if(duzina1<duzina2) {
						vrhStart=x.at(i).at(j);
						indexPrvi=index1;
						indexDrugi=index2;
						indexTreci=index3;
						indexCetvrti=index4;
						duzina1=duzina2;
					} else if(duzina1==duzina2) {
						if(vrhStart>x.at(i).at(j)) {
							continue;
						} else if(vrhStart<x.at(i).at(j)) {
							vrhStart=x.at(i).at(j);
							indexPrvi=index1;
							indexDrugi=index2;
							indexTreci=index3;
							indexCetvrti=index4;
							duzina1=duzina2;
						} else {
							if(indexPrvi==index1) {
								if(i!=IndexVrha) {
									if(i<IndexVrha) {
										IndexVrha=i;
										vrhStart=x.at(i).at(j);
										indexPrvi=index1;
										indexDrugi=index2;
										indexTreci=index3;
										indexCetvrti=index4;
										duzina1=duzina2;
									}
								} else if(j<JndexVrha) {
									JndexVrha=j;
									vrhStart=x.at(i).at(j);
									indexPrvi=index1;
									indexDrugi=index2;
									indexTreci=index3;
									indexCetvrti=index4;
									duzina1=duzina2;
								}
							}
						}
					}
				}
			}
		}
	}
	if(duzina1==0)return Final;
	Final.resize(duzina1+1);
	for(int i=0;i<duzina1+1;i++)
	Final.at(i).resize(duzina1+1);
	for(int i=0; i<=duzina1; i++) {
		for(int j=0; j<=duzina1; j++) {
			Final.at(i).at(j)=std::move(x.at(indexPrvi+i).at(indexDrugi+j));
		}
	}
	return Final;
}

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int red,kolona;
	std::cin>>red>>kolona;
	if(red<0 || kolona<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout<<"Unesite elemente matrice:";
	Matrix PocetniMatrix(red,std::vector<double> (kolona));
	for(int i=0; i<red; i++)
		for(int j=0; j<kolona; j++)
			std::cin>>PocetniMatrix.at(i).at(j);
	Matrix NeoMatrix;
	try{
		NeoMatrix=(NajvecaPlaninaMatrice(PocetniMatrix));
		std::cout<<"\nNajveca planina unesene matrice je:"<<std::endl;
		for(int i=0; i<NeoMatrix.size(); i++){
			for(int j=0; j<NeoMatrix.at(i).size(); j++)
				std::cout<<std::setw(6)<<NeoMatrix.at(i).at(j);
			std::cout<<std::endl;
		}
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
	return 0;
}