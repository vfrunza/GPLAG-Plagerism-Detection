/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica UnosMatrice(int BrRedova, int BrKolona) {
	Matrica mat(BrRedova, std::vector<double>(BrKolona));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<BrRedova; i++) {
		for(int j=0; j<BrKolona; j++) {
			double broj;
			std::cin >> broj;
			mat.at(i).at(j)=broj;
		}
	}
	return mat;
}
/*
void IspisiMatricu(Matrica mat) {
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.at(0).size(); j++) {
			std::cout << std::setw(6) << mat.at(i).at(j);
		}
		std::cout << std::endl;
	}
}*/

Matrica NajvecaPlaninaMatrice(Matrica mat) {
	
	if(mat.size()==0 || mat.at(0).size()==0) {
		Matrica Planina;
		return Planina;
	}
	
	for(int i=0; i<(mat.size())-1; i++) {
		if(mat.at(i).size()!=mat.at(i+1).size()) throw std::domain_error("Matrica nije korektna");
	}
	
	
	double vrh=mat.at(0).at(0);
	if(mat.size()<=2 || mat.at(0).size()<=2) {
NemaPlanine:		
		Matrica Planina(1, std::vector<double>(1));
		for(int i=0; i<mat.size(); i++) {
			for(int j=0; j<mat.at(i).size(); j++) {
				if(vrh<mat.at(i).at(j)) vrh=mat.at(i).at(j);
				else continue;
			} 
		}
		Planina.at(0).at(0)=vrh;
		return Planina;
	} 
	
	std::vector<int>i1;
	std::vector<int>j1;
	std::vector<int>format;
	bool provjera;
	int gorei, gorej, doljei, doljej, format1, minformat, maxformat;
	double sumaokoline;
	double sumaprethodna;
	for(int i=1; i<mat.size()-1; i++) {
		for(int j=1; j<mat.at(i).size()-1; j++) {
			provjera=false;
			vrh=mat.at(i).at(j);
			gorei=i;
			gorej=j;
			doljei=i;
			doljej=j;
			maxformat=0;
			minformat=1;
			do{
				gorei--;
				gorej--;
				doljei++;
				doljej++;
				maxformat++;
			}while(gorei!=0 && gorej!=0 && doljei!=mat.size() && doljej!=mat.at(i).size());
			
			sumaprethodna=vrh;
			while(minformat<=maxformat) {
				sumaokoline=0.;
				for(int x=i-minformat; x<i+minformat; x++) {
					for(int y=j-minformat; y<j+minformat; y++) {
						if(x==(i-minformat) || x==(i+minformat) || y==(j-minformat) || y==(j+minformat)) sumaokoline+=mat.at(x).at(y);
						else if(x==i && y==j) continue;
					}
				}
				if(sumaokoline<vrh) {
					if(sumaokoline<sumaprethodna) {
						format1=minformat;
						provjera=true;
					} else {
						break;
					}
				} else {
					break;
				}
					sumaprethodna=sumaokoline;
				minformat++;
			}
			
			if(provjera) {
				i1.push_back(i);
				j1.push_back(j);
				format.push_back(format1);
			}
		}
	}
	int tempf, tempi, tempj;
	
/*	for(int i=0; i<format.size(); i++) {
		std::cout << std::endl << format.at(i) << " " << i1.at(i) << " " << j1.at(i) << std::endl;
	}*/
	
	if(format.size()==0) {
		goto NemaPlanine;
	} else {
		tempf=format.at(0);
		tempi=i1.at(0);
		tempj=j1.at(0);
	//	std::cout << tempi << " " << tempj << " " << tempf << std::endl;
		for(int i=1; i<format.size(); i++) {
			if(tempf>format.at(i)) continue;
			else {
				if(tempf<format.at(i)) {
					tempf=format.at(i);
					tempi=i1.at(i);
					tempj=j1.at(i);
				} else {
					if(tempf==format.at(i)) {
						if(tempi>i1.at(i)) {
							continue;
						} else {
							if(tempi<i1.at(i)) {
								tempi=i1.at(i);
								tempj=j1.at(i);
							} else {
								if(tempi==i1.at(i)) {
									if(tempj>j1.at(i)) {
										continue;
									} else {
										if(tempj<j1.at(i)) {
											tempi=i1.at(i);
											tempj=j1.at(i);
										} else {
											continue;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
//	std::cout << std::endl << tempi << " " << tempj << " " << tempf << std::endl;

	int a, b;
	Matrica Planina(2*tempf+1, std::vector<double>(2*tempf+1));
	a=0;
	for(int i=tempi-tempf; i<=tempi+tempf; i++) {
		b=0;
		for(int j=tempj-tempf; j<=tempj+tempf; j++) {
			Planina.at(a).at(b)=mat.at(i).at(j);
			b++;
		}
		a++;
	}
	
	return Planina;
}



int main () {
	std::cout << "Unesite dimenzije matrice (m i n): ";
	try {
		int m, n;
		std::cin >> m >> n;
		if(m<0 or n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
		Matrica mat=UnosMatrice(m, n);
		
		Matrica Planina=NajvecaPlaninaMatrice(mat);
		std::cout << std::endl << "Najveca planina unesene matrice je: " << std::endl;
		for(int i=0; i<Planina.size(); i++) {
			for(int j=0; j<Planina.at(0).size(); j++) {
				std::cout << std::setw(6) << Planina.at(i).at(j);
			}
			std::cout << std::endl;
		}
	}catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}




/*for(int i=1; i<mat.size()-1; i++) {
			for(int j=1; j<mat.at(0).size()-1; j++) {
				provjera=false;
				sumaVrh=mat.at(i).at(j);
				tempGorei=i; 
				tempGorej=j;
				tempDolje=i;
				brojac=0;
				while(tempGorei!=0 && (tempDolje!=(mat.at(0).size())-1 || tempDolje!=(mat.size())-1) && tempGorej!=0) {
					tempGorei--;
					tempGorej--;
					tempDolje++;
					brojac++;
				}
				brojac1=1;
			//	suma2=1;
				do{
					suma1=0;
			//		if(suma2>suma1);
					for(int k=i-brojac1; k<=i+brojac1; k++) {
						for(int l=j-brojac1; l<=j+brojac1; l++) {
							if(k==i && l==j) continue;
							else suma1+=mat.at(k).at(l);
						}
					}
					if(suma1<sumaVrh) {
						if(brojac1==1) {
							cuvajbr=brojac1;
							provjera=true;
							provjera1=true;
						} else {
							if(brojac1!=1) {
								if(suma1<suma2) {
									cuvajbr=brojac1;
								}
							}
						}
					} else {
						break;
					}
					suma2=suma1;
					brojac1++;
				}while(brojac1<=brojac);
				if(provjera) {
					if(br==brojac1) {
						if(sumaVrh>suma2) {
							cuvajvrh=sumaVrh;
							i1=i;
							j1=j;
							br=cuvajbr;
						}
					} else {
						if(brojac1>br) {
							if(sumaVrh>suma2) {
								cuvajvrh=sumaVrh;
								i1=i;
								j1=j;
								br=cuvajbr;
							}
						}
					}
				}
			}
		}
		if(!provjera1) {
			Matrica Planina(1, std::vector<double>(1));
			for(int i=0; i<mat.size(); i++) {
				for(int j=0; j<mat.at(i).size(); j++) {
					if(vrh<mat.at(i).at(j)) vrh=mat.at(i).at(j);
					else continue;
				}
			}
			Planina.at(0).at(0)=vrh;
			return Planina;
		} else {
			if(provjera1) {
				Matrica Planina(br+2, std::vector<double>(br+2));
				int a, b;
				a=0;
				for(int i=i1-br; i<=i1+br; i++) {
					b=0;
					for(int j=j1-br; j<=j1+br; j++) {
						Planina.at(a).at(b)=mat.at(i).at(j);
						b++;
					}
					a++;
				}
			}
			return Planina;
		}
*/