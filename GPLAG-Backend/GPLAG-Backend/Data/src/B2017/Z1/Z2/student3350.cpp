#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
double BrojRedova(std::vector<std::vector<double>>m)
{
    if(m.size()==0) return 0;
    double n(m.size());
    return n;
}
double BrojKolona(std::vector<std::vector<double>>m)
{
    if(m.size()==0) return 0;
    double n(m[0].size());
    return n;
}
std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>>Matrica)
{
    int suma(0),izraz(1),duzina,max(0),maxi(0),brojac(0);
    int nova_suma(0),indexi(-1),indexj(-1),vrh(0);
    std::vector<double>pomocni ;
    std::vector<double>m ;

    std::vector<std::vector<double>>ma(BrojRedova(Matrica),std::vector<double>(BrojKolona(Matrica)));
    std::vector<std::vector<double>>Matrica0(0,std::vector<double>(0)) ;
        if(BrojKolona(Matrica)==0||BrojRedova(Matrica)==0)
        return Matrica0;
    int sirina(Matrica.at(0).size());
    for(int i(1); i<Matrica.size(); i++) {
        if(sirina!=Matrica.at(i).size())
            throw std::domain_error ("Matrica nije korektna");
    }


    if(BrojKolona(Matrica)<3||BrojRedova(Matrica)<3) {
        std::vector<std::vector<double>>M(1,std::vector<double>(0)) ;
        int max(Matrica.at(0).at(0));
        for(int i(0); i<BrojRedova(Matrica); i++)
            for(int j(0); j<BrojKolona(Matrica); j++) {
                if(Matrica.at(i).at(j)>max) max=Matrica.at(i).at(j);
            }
        M.at(0).push_back(max);
        return M;
    }
    for(int i(0); i<Matrica.size(); i++) {
        for(int j(0); j<Matrica.at(i).size(); j++) {
            if(i!=0&&j!=0&&i!=BrojRedova(Matrica)-1&&j!=BrojKolona(Matrica)-1) {
                izraz=1;
                brojac=0;
                while(i-izraz>=0&&i+izraz<=BrojRedova(Matrica)-1&&j-izraz>=0&&j+izraz<=BrojKolona(Matrica)-1) {
                    brojac++;
                    for(int k(i-izraz); k<=i+izraz; k++) {
                        for(int l(j-izraz); l<=j+izraz; l++) {
                            if(k==i-izraz||k==i+izraz)  suma+=Matrica.at(k).at(l);
                            else  {
                                if(l==j-izraz) {
                                    suma+=Matrica.at(k).at(j-izraz);
                                    suma+=Matrica.at(k).at(j+izraz);

                                }

                            }

                        }
                    }
                    nova_suma=suma;
                    if(suma<Matrica.at(i).at(j)||suma<nova_suma) {
                        m.resize(0);
                        for(int p(i-izraz); p<=i+izraz; p++) {
                            for(int q(j-izraz); q<=j+izraz; q++) {
                                if(suma<=nova_suma||i-izraz==0) m.push_back(Matrica.at(p).at(q));
                            }
                            duzina=m.size();
                            if(duzina>max) {
                                pomocni=m;
                                max=duzina;
                                vrh=Matrica.at(i).at(j);
                                indexi=i;
                                indexj=j;
                                duzina=0;
                                
                            }
                            if(duzina==max) {
                                if(Matrica.at(i).at(j)>vrh) {
                                    pomocni=m;
                                    vrh=Matrica.at(i).at(j);
                                }
                            
                                if(i<indexi&&vrh>Matrica.at(i).at(j)) {
                                    pomocni=m;
                                    indexi =i;
                                }
                                if(j<indexj&&indexi>i&&Matrica.at(i).at(j)<vrh) {
                                    pomocni=m;
                                    indexj = j;
                                }

                            }
                            duzina=0;
                        }

                    }
                    izraz++;
                    suma=0;
                    if(brojac>maxi) 
                        maxi=brojac;

                }
                nova_suma=0;
            }
        }

    }
    int s(0);
    for(int i(0);i<pomocni.size();i++)
        {
            s+=pomocni.at(i);
        }
        if(s==0) {
            ma.resize(0);
            return ma;
        }
    int k1(0);
    ma.resize(maxi*2+1);
    for(int i(0); i<maxi*2+1; i++)
        ma.at(i).resize(maxi*2+1);
    for(int i(0); i<pomocni.size()/((maxi*2+1)); i++) {
        for(int j(0); j<(pomocni.size()/(maxi*2+1)); j++) {
            ma.at(i).at(j)=pomocni.at(k1);
            k1++;
        }
    }

    return ma;
}
int main()
{
    std::vector<std::vector<double>>Matrica;
    std::vector<std::vector<double>>M ;
    try {
       std::cout << "Unesite dimenzije matrice (m i n): ";
        int m,n;
        std::cin >> m ;
        std::cin >> n;
        if(m<0||n<0) {
            std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
            return 0;
        }
        Matrica.resize(m);
        for(int i(0); i<m; i++)
            Matrica.at(i).resize(n);
        std::cout << "Unesite elemente matrice: "<<std::endl;
        int e;
        for(int i(0); i<m; i++)
            for(int j(0); j<n; j++) {
                std::cin >>Matrica.at(i).at(j);

            } 

        M = NajvecaPlaninaMatrice(Matrica);
        std::cout << "Najveca planina unesene matrice je: " << std::endl;
        for(int i(0); i<M.size(); i++) {
            for(int j(0); j<M.at(i).size(); j++) {
                std::cout <<std::right<<std::setw(6)<<M.at(i).at(j);
            }
            std::cout  << std::endl;
        }
    } catch (const std::domain_error &izuzetak) {
        std::cout <<"Izuzetak: "<< izuzetak.what() << std::endl;
    }
    return 0;
}