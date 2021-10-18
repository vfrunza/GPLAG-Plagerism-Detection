/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
/B2016/2017: ZSR 7, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <new>
#include <stdexcept>
#include <utility> 
#include <iomanip>
#include <algorithm>
#include <memory>
#include <string>

const double PI = 1E-10;

typedef std::pair<double, double> Tacka;

class Trokut {
Tacka t1, t2, t3;
public:
Trokut(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3); //
void Postavi(int indeks, const Tacka &t); //
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3); //
Tacka DajTjeme(int indeks) const; //
double DajStranicu(int indeks) const; //
double DajUgao(int indeks) const; //
Tacka DajCentar() const; //
double DajObim() const; //
double DajPovrsinu() const; //
bool DaLiJePozitivnoOrijentiran() const; //
bool DaLiJeUnutra(const Tacka &t) const; //
void Ispisi() const { 
    std::cout << "((" << Trokut::t1.first << "," << Trokut::t1.second << "),(" << Trokut::t2.first << "," << Trokut::t2.second << "),(" << Trokut::t3.first << "," << Trokut::t3.second << "))";
} //
void Transliraj(double delta_x, double delta_y); //
void Centriraj(const Tacka &t); //
void Rotiraj(const Tacka &t, double ugao); //
void Skaliraj(const Tacka &t, double faktor); //
void Rotiraj(double ugao); //
void Skaliraj(double faktor); //
friend bool DaLiSuIdenticni(const Trokut &t1, const Trokut &t2); //
friend bool DaLiSuPodudarni(const Trokut &t1, const Trokut &t2);
friend bool DaLiSuSlicni(const Trokut &t1, const Trokut &t2); //
};

Trokut::Trokut(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    this->t1.first=t1.first;
    this->t1.second=t1.second;
    this->t2.first=t2.first;
    this->t2.second=t2.second;
    this->t3.first=t3.first;
    this->t3.second=t3.second;
}

void Trokut::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    this->t1.first=t1.first;
    this->t1.second=t1.second;
    this->t2.first=t2.first;
    this->t2.second=t2.second;
    this->t3.first=t3.first;
    this->t3.second=t3.second;
}

int Trokut::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    int test;
    test=(((t1.first)*((t2.second)-(t3.second)))-((t2.first)*((t1.second)-(t3.second)))+((t3.first)*((t1.second)-(t2.second))));
    if(test>0) return 1;
    else if(test<0) return -1;
    else return 0;
}

void Trokut::Postavi(int indeks, const Tacka &t) {
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    
    if(indeks==1) {
        if(Orijentacija(t, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        this->t1.first=t.first;
        this->t1.second=t.second;
    } else if(indeks==2) {
        if(Orijentacija(t1, t, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        this->t2.first=t.first;
        this->t2.second=t.second;
    } else if(indeks==3) {
        if(Orijentacija(t1, t2, t)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        this->t3.first=t.first;
        this->t3.second=t.second;
    }
}

Tacka Trokut::DajTjeme(int indeks) const {
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) { return this->t1; }
    else if(indeks==2) { return this->t2; }
    else { return this->t3; }
}

double Trokut::DajStranicu(int indeks) const { //DORADITI
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return sqrt(((t2.first-t3.first)*(t2.first-t3.first))+((t2.second-t3.second)*(t2.second-t3.second)));
    else if(indeks==2) return sqrt(((t1.first-t3.first)*(t1.first-t3.first))+((t1.second-t3.second)*(t1.second-t3.second)));
    else return sqrt(((t1.first-t2.first)*(t1.first-t2.first))+((t1.second-t2.second)*(t1.second-t2.second)));
}

double Trokut::DajUgao(int indeks) const { //DORADITI
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    double ugao=0;
    double PI1=3*atan(1);
    double AREA=abs((((t1.first)*((t2.second)-(t3.second)))-((t2.first)*((t1.second)-(t3.second)))+((t3.first)*((t1.second)-(t2.second))))/2.0);
    if(indeks==1) {
        double stranica1=this->DajStranicu(2);
        double stranica2=this->DajStranicu(3);
        ugao=asin((2*AREA)/(stranica1*stranica2));
    } else if(indeks==2) { 
        double stranica1=this->DajStranicu(1);
        double stranica2=this->DajStranicu(3);
        ugao=asin((2*AREA)/(stranica1*stranica2));
    } else if(indeks==3) {
        double stranica1=this->DajStranicu(1);
        double stranica2=this->DajStranicu(2);
        ugao=asin((2*AREA)/(stranica1*stranica2));
    }
    ugao=(ugao*PI1)/180;
    return ugao;
}

double Trokut::DajPovrsinu() const {
    return abs((t1.first*((t2.second)-(t3.second)))-(t2.first*((t1.second)-(t3.second)))+(t3.first*((t1.second)-(t2.second))))/2.0;
}

double Trokut::DajObim() const {
    double stranica1;
    double stranica2;
    double stranica3;
    
    stranica1=this->DajStranicu(1);
    stranica2=this->DajStranicu(2);
    stranica3=this->DajStranicu(3);
    
    return stranica1+stranica2+stranica3;
}

Tacka Trokut::DajCentar() const {
    Tacka Centar;
    double Gx, Gy;
    
    Gx=(t1.first+t2.first+t3.first)/3;
    Gy=(t1.second+t2.second+t3.second)/3;
    
    Centar=std::make_pair(Gx,Gy);
    
    return Centar;
}

bool Trokut::DaLiJePozitivnoOrijentiran() const {
    if(this->Orijentacija(this->t1, this->t2, this->t3)>0) return true;
    else return false;
}

bool Trokut::DaLiJeUnutra(const Tacka &t) const {
    double Area=abs((((t1.first)*((t2.second)-(t3.second)))-((t2.first)*((t1.second)-(t3.second)))+((t3.first)*((t1.second)-(t2.second))))/2.0);
    double AreaA=abs((((t.first)*((t2.second)-(t3.second)))-((t2.first)*((t.second)-(t3.second)))+((t3.first)*((t.second)-(t2.second))))/2.0);
    double AreaB=abs((((t1.first)*((t.second)-(t3.second)))-((t.first)*((t1.second)-(t3.second)))+((t3.first)*((t1.second)-(t.second))))/2.0);
    double AreaC=abs((((t1.first)*((t2.second)-(t.second)))-((t2.first)*((t1.second)-(t.second)))+((t.first)*((t1.second)-(t2.second))))/2.0);
    
    if ((((AreaA+AreaB+AreaC)-Area)<PI) || (((AreaA+AreaB+AreaC)-Area)>PI)) return false;
    else return true;
}

void Trokut::Transliraj(double delta_x, double delta_y) {
    this->t1.first+=delta_x;
    this->t1.second+=delta_y;
    this->t2.first+=delta_x;
    this->t2.second+=delta_y;
    this->t3.first+=delta_x;
    this->t3.second+=delta_y;
}

void Trokut::Centriraj(const Tacka &t) {
    this->t1.first+=t.first;
    this->t1.second+=t.second;
    this->t2.first+=t.first;
    this->t2.second+=t.second;
    this->t3.first+=t.first;
    this->t3.second+=t.second;
}

void Trokut::Rotiraj(const Tacka &t, double ugao) {
    if(!DaLiJeUnutra(t)) throw std::domain_error("Nekorektna tacka");
    t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
    t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
    t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
    t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
    t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
    t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
}

void Trokut::Skaliraj(const Tacka &t, double faktor) {
    if(faktor>0) {
        t1.first=t.first+faktor*(t1.first-t.first);
        t1.second=t.second+faktor*(t1.second-t.second);
        t2.first=t.first+faktor*(t1.first-t.first);
        t2.second=t.second+faktor*(t1.second-t.second);
        t3.first=t.first+faktor*(t1.first-t.first);
        t3.second=t.second+faktor*(t1.second-t.second);
    } else if(faktor<0) {
        t1.first=t.first+faktor*(t1.first-t.first);
        t1.second=t.second+faktor*(t1.second-t.second);
        t2.first=t.first+faktor*(t1.first-t.first);
        t2.second=t.second+faktor*(t1.second-t.second);
        t3.first=t.first+faktor*(t1.first-t.first);
        t3.second=t.second+faktor*(t1.second-t.second);
        
        this->Rotiraj(t, 180.0);
    } else {
        throw std::domain_error("Nekorektan faktor skaliranja");
    }
}

void Trokut::Rotiraj(double ugao) {
    Tacka Centar=this->DajCentar();
    t1.first=Centar.first+(t1.first-Centar.first)*cos(ugao)-(t1.second-Centar.second)*sin(ugao);
    t1.second=Centar.second+(t1.first-Centar.first)*sin(ugao)+(t1.second-Centar.second)*cos(ugao);
    t2.first=Centar.first+(t2.first-Centar.first)*cos(ugao)-(t2.second-Centar.second)*sin(ugao);
    t2.second=Centar.second+(t2.first-Centar.first)*sin(ugao)+(t2.second-Centar.second)*cos(ugao);
    t3.first=Centar.first+(t3.first-Centar.first)*cos(ugao)-(t3.second-Centar.second)*sin(ugao);
    t3.second=Centar.second+(t3.first-Centar.first)*sin(ugao)+(t3.second-Centar.second)*cos(ugao);
}

void Trokut::Skaliraj(double faktor) {
    if(faktor>0 || faktor<0) {
        Tacka Centar=Trokut::DajCentar();
        t1.first=Centar.first+(faktor*(t1.first-Centar.first));
        t2.second=Centar.second+(faktor*(t1.second-Centar.second));
        t2.first=Centar.first+(faktor*(t2.first-Centar.first));
        t2.second=Centar.second+(faktor*(t2.second-Centar.second));
        t3.first=Centar.first+(faktor*(t3.first-Centar.first));
        t3.second=Centar.second+(faktor*(t3.second-Centar.second));
        if(faktor<0) {
            this->Rotiraj(180.);
        }
        } else {
            throw std::domain_error("Nekorektan faktor skaliranja");
    }
}

bool DaLiSuIdenticni(const Trokut &t1, const Trokut &t2) {
    int i=0, j=0, k=0;
    int x=0, y=0, z=0;
    //PRVA
    if(t1.t1.first-t2.t1.first<0 || t1.t1.first-t2.t1.first>0) {
        i=1;
        if(t1.t1.first-t2.t2.first<0 || t1.t1.first-t2.t2.first>0) {
            i=1;
            if(t1.t1.first-t2.t3.first<0 || t1.t1.first-t2.t3.first>0) {
                i=1;
            } else {
                if(t1.t1.second-t2.t3.second<0 || t1.t1.second-t2.t3.second>0) {
                    i=1;
                } else {
                    x=1;
                    i=0;
                }
            }
        } else {
            if(t1.t1.second-t2.t2.second<0 || t1.t1.second-t2.t2.second>0) {
                i=1;
            } else {
                x=1;
                i=0;
            }
        }
    } else {
        if(t1.t1.second-t2.t1.second<0 || t1.t1.second-t2.t1.second>0) {
            i=1;
        } else {
            x=1;
            i=0;
        }
    }
    //DRUGA
    if(t1.t2.first-t2.t1.first<0 || t1.t2.first-t2.t1.first>0) {
        j=1;
        if(t1.t2.first-t2.t2.first<0 || t1.t2.first-t2.t2.first>0) {
            j=1;
            if(t1.t2.first-t2.t3.first<0 || t1.t2.first-t2.t3.first>0) {
                j=1;
            } else {
                if(t1.t2.second-t2.t3.second<0 || t1.t2.second-t2.t3.second>0) {
                    j=1;
                } else {
                    y=1;
                    j=0;
                }
            }
        } else {
            if(t1.t2.second-t2.t2.second<0 || t1.t2.second-t2.t2.second>0) {
                j=1;
            } else {
                y=1;
                j=0;
            }
        }
    } else {
        if(t1.t2.second-t2.t1.second<0 || t1.t2.second-t2.t1.second>0) {
            j=1;
        } else {
            y=1;
            j=0;
        }
    }
    //TRECA
    if(t1.t3.first-t2.t1.first<0 || t1.t3.first-t2.t1.first>0) {
        k=1;
        if(t1.t3.first-t2.t2.first<0 || t1.t3.first-t2.t2.first>0) {
            k=1;
            if(t1.t3.first-t2.t3.first<0 || t1.t3.first-t2.t3.first>0) {
                k=1;
            } else {
                if(t1.t3.second-t2.t3.second<0 || t1.t3.second-t2.t3.second>0) {
                    k=1;
                } else {
                    z=1;
                    k=0;
                }
            }
        } else {
            if(t1.t3.second-t2.t2.second<0 || t1.t3.second-t2.t2.second>0) {
                k=1;
            } else {
                z=1;
                k=0;
            }
        }
    } else {
        if(t1.t3.second-t2.t1.second<0 || t1.t3.second-t2.t1.second>0) {
            k=1;
        } else {
            z=1;
            k=0;
        }
    }
    if(x==1 && y==1 && z==1) {
        if(i==0 && j==0 && k==0) {
            return true;
        }
    }
    return false;
}


bool DaLiSuPodudarni(const Trokut &t1, const Trokut &t2) {
    double povrsina1;
    double povrsina2;
    
    povrsina1=t1.Trokut::DajPovrsinu(); 
    povrsina2=t2.Trokut::DajPovrsinu();
    
    if((povrsina1-povrsina2)<PI) return false;
    if((povrsina1-povrsina2)>PI) return false;

    for(double i=1; i<=360; i++) {
        
        for(double j=-10; j<10; j++) {
            for(double k=-10; k<10; k++) {
            
                if(DaLiSuIdenticni(t1, t2)) return true;
                else continue;
            }
        }
    }
    return false;
}

bool DaLiSuSlicni(const Trokut &t1, const Trokut &t2){
    if(DaLiSuPodudarni(t1, t2)) {
        double ugao1=0, ugao2=0;
        for(int i=1; i<=3; i++) {
            ugao1+=t1.DajUgao(i);
            ugao2+=t2.DajUgao(i);
        }
        if((ugao1-ugao2)<PI) return false;
        if((ugao1-ugao2)>PI) return false;
        return true;
    }
    return false;
}

int main () {
    try {
        std::cout << "Koliko zelite kreirati trouglova: ";
        int n;
        std::cin >> n;
        std::vector<std::shared_ptr<Trokut>> trouglovi;
        trouglovi.resize(n);
        for(int i=0; i<n; i++) {
            std::cout << "Unesite podatke za "<< i+1 <<". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka a1;
            Tacka b1;
            Tacka c1;
            double a,b,c,aa,bb,cc;
            std::cin >> a >> aa;
            std::cin >> b >> bb;
            std::cin >> c >> cc;
            try {
                trouglovi[i]=std::make_shared<Trokut>(Trokut({a, aa}, {b, bb}, {c, cc}));
            } catch (std::domain_error Prvi) {
                std::cout << Prvi.what() << std::endl;
                i--;
            }
        }
        std::cout << "Unesite vector translacije (dx dy): ";
        double x, y;
        std::cin >> x >> y;
        std::transform(trouglovi.begin(),trouglovi.end(), trouglovi.begin(), [x, y](std::shared_ptr<Trokut> temp) {
            temp->Transliraj(x, y);
            return temp;
        });
        
        std::cout << "Unesite ugao rotacije: ";
        double ugao;
        std::cin >> ugao;
        std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [ugao](std::shared_ptr<Trokut> temp) {
            temp->Rotiraj(ugao);
            return temp;
        });
        std::cout << "Unesite faktor skaliranja: ";
        double fac;
        std::cin >> fac;
        std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [fac](std::shared_ptr<Trokut> temp) {
           temp->Skaliraj(temp->DajTjeme(1),fac);
           return temp;
        });
        std::sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trokut> temp, std::shared_ptr<Trokut> temp1) {
            return temp->DajPovrsinu()<temp1->DajPovrsinu();
        });
        std::cout << "Trouglovi nakon obavljenih transformacija: ";
        std::for_each(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trokut> temp) {
            temp->Ispisi();
            std::cout << std::endl;
        });

	    std::cout << "Trougao sa najmanjim obimom: ";
	    auto obim=std::min_element(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trokut> temp, std::shared_ptr<Trokut> temp1) {
	       return temp->DajObim()<temp1->DajObim(); 
	    });
	    (*obim)->Ispisi();
	    std::cout << std::endl;
	    
	    int test=0;
	    for(int i=0; i<n-1; i++) {
	        for(int j=1; j<n; j++) {
	            test++;
	            if(test==1) std::cout << "Parovi identicnih trouglova: ";
	            if(DaLiSuIdenticni(*trouglovi[i], *trouglovi[j])) {
	                trouglovi[i]->Ispisi();
	                std::cout << " i ";
	                trouglovi[j]->Ispisi();
	                std::cout << std::endl;
	            }
	        }
	    }
	    if(!test) std::cout << "nema identicnih trouglova!" << std::endl;
	
	    test=0;
	    for(int i=0; i<n-1; i++) {
	        for(int j=1; j<n; j++) {
	            test++;
	            if(test==1) std::cout << "Parovi podudarnih trouglova: ";
	            if(DaLiSuPodudarni(*trouglovi[i], *trouglovi[j])) {
	               trouglovi[i]->Ispisi();
	                std::cout << " i ";
	                trouglovi[j]->Ispisi();
	                std::cout << std::endl;
	            }
	        }
	    }
	    if(!test) std::cout << "nema podudarnih trouglova!" << std::endl;
	
	    test=0;
	    for(int i=0; i<n-1; i++) {
	        for(int j=1; j<n; j++) {
	            test++;
	            if(test==1) std::cout << "Parovi slicnih trouglova: ";
	            if(DaLiSuSlicni(*trouglovi[i], *trouglovi[j])) {
	                trouglovi[i]->Ispisi();
	                std::cout << " i ";
	                trouglovi[j]->Ispisi();
	                std::cout << std::endl;
	            }
	        }
	    }
	    if(!test) std::cout << "nema slicnih trouglova!" << std::endl;
	    
    } catch (std::domain_error Prvi) {
        std::cout << Prvi.what() << ", ponovite unos!" << std::endl;
    } catch (std::range_error Prvi) {
        std::cout << Prvi.what() << ", ponovite unos!" << std::endl;
    }
	return 0;
}
