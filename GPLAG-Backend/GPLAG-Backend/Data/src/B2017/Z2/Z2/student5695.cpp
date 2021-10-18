#include <deque>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

enum SmjerKretanja:int { NaprijedNazad=0, NazadNaprijed=1, GoreDolje=2, DoljeGore=3, LijevoDesno=4, DesnoLijevo=5 };

typedef vector<deque<deque<int>>> vddi;

template <typename tip_kont> 
void ImaIzac(tip_kont kont) {
    int n(kont.size());
    for(int i=0;i<n;i++) {
        if(kont.at(i).size()!=n) throw domain_error ("3D matrica nema oblik kocke");
        for(int j=0;j<kont.at(i).size();j++) if(kont.at(i).at(j).size()!=n) throw domain_error ("3D matrica nema oblik kocke");
    }
    if(n%2==0) throw length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
}

void Ispis(vddi kont) {
    cout << endl << "Pjescani sat unesene matrice je:" << endl << endl;
    for(int i=0;i<kont.size();i++) {
	    for(int j=0;j<kont.size();j++) {
	        if(j<=kont.size()/2) cout << setfill(' ') << setw(4*j) << "";
	        else cout << setfill(' ') << setw(4*(kont.size()-j-1)) << "";
	        for(int k=0;k<kont.at(i).at(j).size();k++) {
	            if(k==0 && (j==0 || j==kont.size()-1)) cout << setw(4) << right << kont.at(i).at(j).at(k);
	            else cout <<  setw(4) << right << kont.at(i).at(j).at(k);
	        }
	        cout << endl;
	    }
	    cout << endl;
	}
}

template <typename tip_kont>
tip_kont PjescaniSat(tip_kont kont, SmjerKretanja smjer) {
    ImaIzac(kont);
    if(smjer==4 || smjer==5) {
        for(int i=0;i<kont.size();i++) {
            for(int j=0;j<kont.size();j++) {
                for(int k=j;k<kont.size();k++) {
                    auto pom(kont.at(i).at(j).at(k));
                    kont.at(i).at(j).at(k)=kont.at(i).at(k).at(j);
                    kont.at(i).at(k).at(j)=pom;
                }
            }
        }
    }
    else if(smjer==0 || smjer==1) {
        tip_kont pom_kont(kont);
        for(int i=0;i<kont.size();i++) {
            for(int j=0;j<kont.size();j++) {
                for(int k=0;k<kont.size();k++) {
                    kont.at(i).at(j)=pom_kont.at(j).at(i);
                }
            }
        }
    }
    if(smjer==1 || smjer==3 || smjer==5) {
        for(int i=0;i<kont.size();i++) {
            for(int j=0;j<kont.size()/2;j++) {
                auto pomocni_dek=kont.at(i).at(j);
                kont.at(i).at(j)=kont.at(i).at(kont.size()-j-1);
                kont.at(i).at(kont.size()-j-1)=pomocni_dek;
            }
        } 
    }
    for(int i=0;i<kont.size();i++) {
        for(int j=0;j<kont.size();j++) {
            int n(kont.size()-j-1);
            if(j<=kont.size()/2 && j!=0) {
                for(int k=0;k<kont.size()-j;k++) kont.at(i).at(j).at(k)=kont.at(i).at(j).at(k+j);
            }
            else if(j>(int)kont.size()/2 && j!=kont.size()-1) {
                for(int k=0;k<=j;k++) kont.at(i).at(j).at(k)=kont.at(i).at(j).at(k+n);
                
            }
        }
        for(int l=0;l<kont.size()/2+1;l++) {
            auto pomocni=kont.at(i).at(l);
            pomocni.resize(kont.size()-2*l);
            kont.at(i).at(l)=pomocni;
        }
        for(int l=kont.size()/2+1;l<kont.size();l++) {
            auto pomocni=kont.at(i).at(l);
            pomocni.resize(kont.size()-2*(kont.size()-l-1));
            kont.at(i).at(l)=pomocni;
        }
    }
    return kont;
}

int main() {
	cout << "Unesite dimenziju (x/y/z): ";
	int dim;
	cin >> dim;
	while(!cin || dim<0) {
		cout << "Dimenzija nije ispravna, unesite opet: ";
		cin >> dim;
	}
	vddi kont(dim);
	cout << "Unesite elemente kontejnera: ";
	for(int i=0;i<dim;i++) {
	    kont.at(i).resize(dim);
	    for(int j=0;j<dim;j++) {
	        for(int k=0;k<dim;k++) {
	            int p;
	            cin >> p;
	            kont.at(i).at(j).push_back(p);
	        }
	    }
	}
	cout << "Unesite smjer kretanja [0 - 5]: ";
	int a(-1);
	for(;;) {
	    cin >> a;
	    if(a>5 || a<0 || int(a)!=a) cout << "Smjer nije ispravan, unesite opet: ";
	    else break;
	}
	SmjerKretanja s=SmjerKretanja(a);
	try {
		kont=PjescaniSat(kont,s);
		Ispis(kont);
	}
    catch (domain_error izuzetak) {
    	cout << endl << "Izuzetak: " << izuzetak.what();
    }
    catch (length_error izuzetak) {
    	cout << endl << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}