#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>
using namespace std;
typedef vector<vector<double>> Matrica;
Matrica NajvecaPlaninaMatrice(Matrica mat)
{
    if(mat.size()>0 && mat.at(0).size()>0) {
        for(int i=0; i<mat.size()-1; i++) {
            if(mat.at(i).size()!=mat.at(i+1).size()) throw domain_error("Matrica nije korektna");
        }
    }
    const double EPSILON=0.0001;
    double vrh_trenutne(0),vrh(0),zbir_trenutne(0),kvadrat(0);
    int dim_trenutne(0),dim(0),x(0),y(0),x1(0),y1(0);
    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat.size(); j++) {
            dim_trenutne=0;
            vrh_trenutne=mat.at(i).at(j);
            zbir_trenutne=mat.at(i).at(j);
            dim_trenutne++;
            x1=i;
            y1=j;
            int brojac(1);
            bool greska=false;
            while(dim_trenutne-brojac>=0) {
                kvadrat=0;
                for(int a=i-brojac; a<=i+brojac; a++) {
                    for(int b=j-brojac; b<=j+brojac; b++) {
                        if(a<0 || b<0 || a>=mat.size() || b>=mat.at(0).size()) greska=true;
                        if(greska) {
                            a=i+brojac+1;
                            break;
                        }
                    }
                }
                if(greska) break;
                for(int a=i-brojac; a<=i+brojac; a++) {
                    for(int b=j-brojac; b<=j+brojac; b++) {
                        if(a==i-brojac || a==i+brojac || b==j-brojac || b==j+brojac)
                            kvadrat+=mat.at(a).at(b);
                    }
                }
                if(kvadrat<zbir_trenutne) {
                    dim_trenutne+=2;
                    zbir_trenutne=kvadrat;
                    kvadrat=0;
                }
                brojac++;
            }
            if(dim_trenutne>dim) {
                vrh=vrh_trenutne;
                dim=dim_trenutne;
                x=x1;
                y=y1;
                vrh_trenutne=0;
                dim_trenutne=0;
                zbir_trenutne=0;
            } else if(dim_trenutne==dim) {
                if(vrh_trenutne>vrh) {
                    vrh=vrh_trenutne;
                    x=x1;
                    y=y1;
                    dim=dim_trenutne;
                    dim_trenutne=0;
                    zbir_trenutne=0;
                } else if(fabs(vrh_trenutne-vrh)<EPSILON) {
                    int a=x1-dim_trenutne/2;
                    int b=y1-dim_trenutne/2;
                    int k=x-dim/2;
                    int l=y-dim/2;
                    for(;;) {
                        if(mat.at(a).at(b)>mat.at(k).at(l)) {
                            vrh=mat.at(x1).at(y1);
                            dim=dim_trenutne;
                            x=x1;
                            y=y1;
                            dim_trenutne=0;
                            break;
                        } else if(mat.at(k).at(l)>mat.at(a).at(b)) {
                            dim_trenutne=0;
                            zbir_trenutne=0;
                            break;
                        }
                        b++;
                        if(b-dim_trenutne==y1) {
                            a++;
                            b=y1-dim_trenutne/2;
                        }
                        k++;
                        if(k-dim==x) {
                            l++;
                            k=x-dim/2;
                        }
                        if(a==x1+dim_trenutne/2+1) break;
                        if(b==y1+dim_trenutne/2+1) break;
                        if(k==x+dim/2+1) break;
                        if(l==y+dim/2+1) break;
                    }
                }
            }
        }
    }
    Matrica a(dim);
    if(dim!=0) {
        int red=0;
        for(int i=x-(dim/2); i<=x+(dim/2); i++) {
            for(int j=y-(dim/2); j<=y+(dim/2); j++) {
                a.at(red).push_back(mat.at(i).at(j));
            }
            red++;
        }
    }
    return a;
}
int main ()
{
    try {
        cout<<"Unesite dimenzije matrice (m i n): ";
        int n,m;
        cin>>m>>n;
        if(m<0 || n<0) {
            cout<<"Dimenzije matrice moraju biti nenegativne!";
            return 0;
        }
        cout<<"Unesite elemente matrice:";
        Matrica mat(m,vector<double>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cin>>mat.at(i).at(j);
            }
        }
        Matrica mat1=NajvecaPlaninaMatrice(mat);
        if(mat1.size()!=0) {
            cout<<"\nNajveca planina unesene matrice je:\n";
            for(int i=0; i<mat1.size(); i++) {
                for(int j=0; j<mat1.at(i).size(); j++) {
                    cout<<setw(6)<<setfill(' ')<<mat1.at(i).at(j);
                }
                cout<<endl;
            }
        }
    } catch(domain_error poruka) {
        cout<<poruka.what();
    }
    return 0;
}