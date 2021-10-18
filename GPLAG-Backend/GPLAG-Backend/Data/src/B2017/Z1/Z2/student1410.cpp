#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using std::cout;
using std::cin;
using std::vector;
typedef vector<vector<double>> mat;
mat Kreiraj(int a,int b)
{
    return mat(a,vector<double>(b));
}
int BrojKolona(mat matrica)
{
    return matrica.at(0).size();
}
bool GrbavaMatrica(mat matrica)
{
    int prvi(matrica.at(0).size());
    for(int i=1; i<matrica.size(); i++) {
        if(matrica.at(i).size()!=prvi)
            return false;
    }
    return true;
}
mat NajvecaPlaninaMatrice(mat matrica)
{
    if(matrica.size()==0) {
        mat rezultat;
        return  rezultat;
    }
    if(int(matrica.at(0).size())==0) {
        mat rezultat;
        return  rezultat;
    }


    if(!GrbavaMatrica(matrica)) throw std::domain_error ("Matrica nije korektna");

    int kolone(BrojKolona(matrica));
    int redovi(matrica.size());


    vector<double> vektor_suma;
    vector<int> format;
    vector<int> vrh;
    vector<int> indeks_reda;
    vector<int> indeks_kolone;
    //za male matrice
  
    if(matrica.size()<=2) {
        double maxi(matrica.at(0).at(0));
        for(int i=0; i<matrica.size(); i++)
            for(int j=0; j<kolone; j++)
                if(matrica.at(i).at(j)>maxi) {
                    maxi=matrica.at(i).at(j);
                }
        mat rez(1,vector<double>(1,maxi));

        return rez;
    }

    for(int i=0; i<matrica.size(); i++) {
        for(int j=0; j<kolone; j++) {
            vector<double> vektor_suma(0);
            double suma_nova(0);
            int brojac(0);
            int pomicanje(1);
            if( i<int(matrica.size())-1 && j<kolone-1 && i>0 && j>0) {
                while((i-pomicanje)>=0 && (j-pomicanje)>=0 && (i+pomicanje)<redovi &&(j+pomicanje)<kolone) {
                    double suma_prethodna(0);
                    int kontrola(1);
                    for(int k=(i-pomicanje); k<=(i+pomicanje); k++)
                        for(int l=(j-pomicanje); l<=(j+pomicanje); l++) {

                            suma_prethodna+=matrica.at(k).at(l);

                        }

                    if(brojac==0) {
                        suma_prethodna-=matrica.at(i).at(j);
                        if(suma_prethodna>=matrica.at(i).at(j)){
                            kontrola=0;
                            break;
                        }
                        vektor_suma.push_back(suma_prethodna);
                    } else {
                        suma_nova=0;
                        for(int p=0; p<vektor_suma.size(); p++)
                            suma_nova+=vektor_suma.at(p);
                        //drugi koncentricni kvadrat
                        suma_prethodna-=(suma_nova+matrica.at(i).at(j));
                        if(suma_prethodna>=vektor_suma.at(brojac-1) || suma_prethodna>=matrica.at(i).at(j)) {
                            kontrola=0;
                            break;
                        }
                        vektor_suma.push_back(suma_prethodna);

                    }
                    if(kontrola==0)
                        break;

                    brojac++;
                    pomicanje++;
                }
                //broj koncentricnih kvadrata odredit ce najveci moguci format
                if(brojac>=1) {

                    format.push_back(brojac);
                    vrh.push_back(matrica.at(i).at(j));
                    indeks_reda.push_back(i);
                    indeks_kolone.push_back(j);


                }
            }
        }


    }
    int maxi;
    int indeks;
    if(int(format.size())==0) {
        mat rezultat;
        return rezultat;
    }
    maxi=format.at(0);
    indeks=0;
    int b;
//provjeriti uslove!!
    int provjera(1);
    if(format.size()>1)
        for(int q=1; q<format.size(); q++) {
            if(format.at(q)>maxi) {
                maxi=format.at(q);
                indeks=q;
            } else if(format.at(q)==maxi) {
                provjera=0;
                if(vrh.at(q)>vrh.at(indeks)) {
                    b=q;

                    break;
                } else if(vrh.at(indeks)>vrh.at(q)) {
                    b=indeks;
                    break;
                } else if(vrh.at(q)==vrh.at(indeks)) {
                    if(indeks_reda.at(q)<indeks_reda.at(indeks)) {
                        b=q;
                        break;
                    } else if(indeks_reda.at(indeks)<indeks_reda.at(q)) {
                        b=indeks;
                        break;
                    } else if(indeks_reda.at(indeks)==indeks_reda.at(q)) {
                        if(indeks_kolone.at(q)<indeks_kolone.at(indeks)) {

                            b=q;
                            break;
                        } else if(indeks_kolone.at(indeks)<indeks_kolone.at(q)) {
                            b=indeks;
                            break;
                        }
                    }

                }

            }
        }
//formiranje rezultujuce matrice
    mat rezultujuca_matrica;
    if(provjera) {
        int indeksR(indeks_reda.at(indeks));
        int indeksK(indeks_kolone.at(indeks));

        if(maxi==1) {
            rezultujuca_matrica.resize(3);
            for(int j=0; j<rezultujuca_matrica.size(); j++)
                rezultujuca_matrica.at(j).resize(3);
        } else {
            //broj koncentricnih kvadrata odredjuje format rez matrice
            rezultujuca_matrica.resize(2*maxi+1);
            for(int j=0; j<rezultujuca_matrica.size(); j++)
                rezultujuca_matrica.at(j).resize(2*maxi+1);
        }
        int x(0);
        int y(0);
        int kontrola1(0);
        int kontrola2(0);
        for(int p=indeksR-maxi; p<=indeksR+maxi; p++) {
            if(kontrola1) {

                kontrola2=1;
                x++;
            }
            for(int q=indeksK-maxi; q<=indeksK+maxi; q++) {
                if(kontrola2) y=0;
                rezultujuca_matrica.at(x).at(y)=matrica.at(p).at(q);
                y++;
                kontrola1=1;
                kontrola2=0;
            }
        }
    } else {
        int indeksR(indeks_reda.at(b));
        int indeksK(indeks_kolone.at(b));

        if(maxi==1) {
            rezultujuca_matrica.resize(3);
            for(int j=0; j<rezultujuca_matrica.size(); j++)
                rezultujuca_matrica.at(j).resize(3);
        } else {
            //broj koncentricnih kvadrata odredjuje format rez matrice
            rezultujuca_matrica.resize(2*maxi+1);
            for(int j=0; j<rezultujuca_matrica.size(); j++)
                rezultujuca_matrica.at(j).resize(2*maxi+1);
        }
        int x(0);
        int y(0);
        int kontrola1(0);
        int kontrola2(0);
        for(int p=indeksR-maxi; p<=indeksR+maxi; p++) {
            if(kontrola1) {

                kontrola2=1;
                x++;
            }
            for(int q=indeksK-maxi; q<=indeksK+maxi; q++) {
                if(kontrola2) y=0;
                rezultujuca_matrica.at(x).at(y)=matrica.at(p).at(q);
                y++;
                kontrola1=1;
                kontrola2=0;
            }
        }

    }

    return rezultujuca_matrica;

}
int main ()
{
    try {
        //m broj redova n br kolona
        cout<<"Unesite dimenzije matrice (m i n): ";
        int m,n;
        cin>>m;
        cin>>n;
        if(m<0 || n<0) {
            cout<<"Dimenzije matrice moraju biti nenegativne!";
            return 1;
        }
        mat matrica;
        matrica=(Kreiraj(m,n));
        cout<<"Unesite elemente matrice:";

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>matrica.at(i).at(j);
        mat rezultat;
        rezultat=NajvecaPlaninaMatrice(matrica);
        cout<<std::endl;
        cout<<"Najveca planina unesene matrice je:";
        cout<<std::endl;
        for(int i =0; i<rezultat.size(); i++) {
            for(int j=0; j<rezultat.at(0).size(); j++)
                cout<<std::right<<std::setw(6)<<rezultat.at(i).at(j);
            cout<<std::endl;
        }
    } catch(std::domain_error izuzetak) {
        cout<< izuzetak.what()<<std::endl;
    }
    return 0;
}