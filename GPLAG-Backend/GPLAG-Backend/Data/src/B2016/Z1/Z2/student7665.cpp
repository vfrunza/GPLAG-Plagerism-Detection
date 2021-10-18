//B 2016/2017, Zadaća 1, Zadatak 2
#include<iostream>
#include<vector>
#include<stdexcept>
#include<iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int brojredova, int brojkolona)              //funkcija koja na osnovu redova i kolona koje prima kao parametar vraca praznu matricu s tolikim brojem redova i kolona
{
    return Matrica(brojredova, std::vector<double>(brojkolona));
}


Matrica OgledaloMatrica(Matrica MATRICA)
{

    for(int i=0; i<MATRICA.size(); i++) {
        for(int j=0; j<MATRICA.at(i).size(); j++) {
            if(MATRICA.at(0).size()!=MATRICA.at(i).size())
                throw std::domain_error("Matrica nije korektna");
        }
    }

    int n;
    int m(MATRICA.size());
    if(m==0) n=0;
    else
        n=MATRICA[0].size();

    auto Horizontalna(KreirajMatricu(m,n));
    auto Veritkalna(KreirajMatricu(m,n));
    auto Kombinovana(KreirajMatricu(m,n));
    auto Ogledalo(KreirajMatricu(3*m,3*n));

    if(m==1 && n==1) {
        for(int i=0; i<Ogledalo.size(); i++) {
            for(int j=0; j<Ogledalo.at(i).size(); j++) {
                Ogledalo.at(i).at(j)=MATRICA.at(0).at(0);
            }
        }
        return Ogledalo;
    }

    for(int i=0, k=0; i<MATRICA.size(), k<Horizontalna.size(); i++, k++) {                  //dvostruka petlja u ovom dijelu koda, paralelno radi s pocetnom matricom i prethodno kreiranom praznom horizontalnom matricom, tako da na odgovarajuca mjesta horizontalne matrice(sto se moze vidjeli iz uvjeta u petljama) stavlja odgovarajuce elemente polazne matrice
        for(int j=MATRICA.at(i).size()-1, e=0; j>=0, e<Horizontalna.at(k).size(); j--, e++) {
            Horizontalna.at(k).at(e)=MATRICA.at(i).at(j);
        }
    }

    for(int i=MATRICA.size()-1, k=0; i>=0, k<Veritkalna.size(); i--, k++) {                //analogno kao u prethodnoj petlji, s tim da baratamo sad s vertikalnom petljom i shodno tome drugacijim uslovima po kojima se ponasa petlja
        for(int j=0, e=0; j<MATRICA.at(i).size(), e<Veritkalna.at(k).size(); j++, e++ ) {
            Veritkalna.at(k).at(e)=MATRICA.at(i).at(j);
        }
    }

    for(int i=MATRICA.size()-1, k=0; i>=0, k<Kombinovana.size(); i--, k++) {
        for(int j=MATRICA.at(i).size()-1, e=0; j>=0, e<Kombinovana.at(k).size(); j--, e++) {
            Kombinovana.at(k).at(e)=MATRICA.at(i).at(j);
        }
    }

    for(int i=0, k=0; i<int(int(Ogledalo.size())/m), k<Kombinovana.size(); i++, k++) {
        for(int j=0, e=0; j<int(int(Ogledalo.at(i).size())/n), e<Kombinovana.at(k).size(); j++, e++ ) {
            Ogledalo.at(i).at(j)=Kombinovana.at(k).at(e);
        }
        std::cout<<std::endl;
    }

    for(int i=0, k=0; i<int(int(Ogledalo.size())/m), k<Veritkalna.size(); i++, k++) {
        for(int j=n, e=0; j<int(int(Ogledalo.at(i).size())/n)+n, e<Veritkalna.at(k).size(); j++, e++) {
            Ogledalo.at(i).at(j)=Veritkalna.at(k).at(e);
        }
    }

    for(int i=0, k=0; i<int(int(Ogledalo.size())/m), k<Kombinovana.size(); i++, k++) {
        for(int j=n+n, e=0; j<Ogledalo.at(i).size(), e<Kombinovana.at(k).size(); j++, e++) {
            Ogledalo.at(i).at(j)=Kombinovana.at(k).at(e);
        }
    }

    for(int i=m, k=0; i<int(int(Ogledalo.size())/m)+m, k<Horizontalna.size(); i++, k++) {
        for(int j=0, e=0; j<int(int(Ogledalo.at(i).size())/n), e<Horizontalna.at(k).size(); j++, e++) {
            Ogledalo.at(i).at(j)=Horizontalna.at(k).at(e);
        }
    }

    for(int i=m, k=0; i<int(int(Ogledalo.size())/m)+m, k<MATRICA.size(); i++, k++) {
        for(int j=n, e=0; j<int(int(Ogledalo.at(i).size())/n)+n, e<MATRICA.at(k).size(); j++, e++) {
            Ogledalo.at(i).at(j)=MATRICA.at(k).at(e);
        }
    }

    for(int i=m, k=0; i<int(int(Ogledalo.size())/m)+m, k<Horizontalna.size(); i++, k++) {
        for(int j=n+n, e=0; j<Ogledalo.at(i).size(), e<Horizontalna.at(k).size(); j++, e++) {
            Ogledalo.at(i).at(j)=Horizontalna.at(k).at(e);
        }
    }

    for(int i=m+m, k=0; i<Ogledalo.size(), k<Kombinovana.size(); i++, k++ ) {
        for(int j=0, e=0; j<int(int(Ogledalo.at(i).size())/n), e<Kombinovana.at(k).size(); j++, e++) {
            Ogledalo.at(i).at(j)=Kombinovana.at(k).at(e);
        }
    }

    for(int i=m+m, k=0; i<Ogledalo.size(), k<Veritkalna.size(); i++, k++) {
        for(int j=n, e=0; j<int(int(Ogledalo.at(i).size())/n)+n, e<Veritkalna.at(k).size(); j++, e++) {
            Ogledalo.at(i).at(j)=Veritkalna.at(k).at(e);
        }
    }

    for(int i=m+m, k=0; i<Ogledalo.size(), k<Kombinovana.size(); i++, k++) {
        for(int j=n+n, e=0; j<Ogledalo.at(i).size(), e<Kombinovana.at(k).size(); j++, e++) {
            Ogledalo.at(i).at(j)=Kombinovana.at(k).at(e);
        }
    }
    return Ogledalo;

}


int main ()
{
    try {
        int m, n;
        double elementiM;
        do {
            std::cout<<"Unesite dimenzije matrice (m n): ";
            std::cin>>m>>n;
            if(m<0 || n<0) {
                std::cout<<"Dimenzije matrice moraju biti nenegativne!";
                break;
            }


            std::cout<<"Unesite elemente matrice: ";
            auto M(KreirajMatricu(m, n));

            for(int i=0; i<M.size(); i++) {
                for(int j=0; j<M.at(i).size(); j++) {
                    std::cin>>elementiM;
                    M.at(i).at(j)=elementiM;
                }
            }
            std::cout<<std::endl;
            auto KrajnjaMatrica(OgledaloMatrica(M));

            std::cout<<"Rezultantna matrica: "<<std::endl;
            for(int i=0; i<KrajnjaMatrica.size(); i++) {
                for(int j=0; j<KrajnjaMatrica.at(i).size(); j++) {
                    std::cout<<std::setw(4)<<KrajnjaMatrica.at(i).at(j);
                }
                std::cout<<std::endl;
            }

        } while(m<0 || n<0);
    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }

    return 0;
}