#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>

typedef std::pair<double, double> Tacka;

class Trougao{
    private:
        Tacka t1;
        Tacka t2;
        Tacka t3;
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1,t2,t3); }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi(int indeks, const Tacka &t);
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        Tacka DajTjeme(int indeks) const;
        double DajStranicu(int indeks) const;
        double DajUgao(int indeks) const;
        Tacka DajCentar() const;
        double DajObim() const;
        double DajPovrsinu() const;
        bool DaLiJePozitivnoOrijentiran() const;
        bool DaLiJeUnutra(const Tacka &t) const;
        void Ispisi() const;
        void Transliraj(double delta_x, double delta_y);
        void Centriraj(const Tacka &t);
        void Rotiraj(const Tacka &t, double ugao);
        void Skaliraj(const Tacka &t, double faktor);
        void Rotiraj(double ugao);
        void Skaliraj(double faktor);
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double uslov;
    uslov = t1.first * (t2.second - t3.second);
    uslov -= (t2.first * (t1.second - t3.second));
    uslov += (t3.first * (t1.second - t2.second));
    if(uslov > 0) return 1;
    else if(uslov < 0) return -1;
    else return 0;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}

void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    bool uslov;
    if(indeks == 1) uslov = (Orijentacija(t,t2,t3) == 0);
    else if(indeks == 2) uslov = (Orijentacija(t1,t,t3) == 0);
    else uslov = (Orijentacija(t1,t2,t) == 0);
    if(uslov) throw std::domain_error("Nekorektne pozicije tjemena");
    if(indeks == 1) Trougao::t1 = t;
    else if(indeks == 2) Trougao::t2 = t;
    else Trougao::t3 = t;
}

Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) return Trougao::t1;
    else if(indeks == 2) return Trougao::t2;
    else return Trougao::t3;
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    double d;
    if(indeks == 1){
        d = std::pow((t3.first - t2.first),2) + std::pow((t3.second - t2.second),2);
        return std::sqrt(d);
    }
    else if(indeks == 2){
        d = std::pow((t1.first - t3.first),2) + std::pow((t1.second - t3.second),2);
        return std::sqrt(d);
    }
    else{
        d = std::pow((t2.first - t1.first),2) + std::pow((t1.second - t2.second),2);
        return std::sqrt(d);
    }
}

double Trougao::DajUgao(int indeks) const{
    double a(DajStranicu(1)),b(DajStranicu(2)),c(DajStranicu(3));
    double d;
    if(indeks == 1){
        d = std::pow(b,2) + std::pow(c,2) - std::pow(a,2);
        d = d / (2 * b * c);
        return std::acos(d);
    }
    else if(indeks == 2){
        d = std::pow(a,2) + std::pow(c,2) - std::pow(b,2);
        d = d / (2 * a * c);
        return std::acos(d);
    }
    else{
        d = std::pow(b,2) + std::pow(a,2) - std::pow(c,2);
        d = d / (2 * b * a);
        return std::acos(d);
    }
}
Tacka Trougao::DajCentar() const{
    double x((t1.first + t2.first + t3.first)/3);
    double y((t1.second + t2.second + t3.second)/3);
    Tacka t(x,y);
    return t;
}

double Trougao::DajObim() const{
    double a(DajStranicu(1)),b(DajStranicu(2)),c(DajStranicu(3));
    return (a+b+c);
}
double Trougao::DajPovrsinu() const{
    double uslov;
    uslov = t1.first * (t2.second - t3.second);
    uslov -= (t2.first * (t1.second - t3.second));
    uslov += (t3.first * (t1.second - t2.second));
    return (std::abs(uslov)/2);
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    int uslov(Orijentacija(t1,t2,t3));
    return uslov == 1;
}

void Trougao::Ispisi() const {
    std::cout << "((" << t1.first << "," << t1.second << "),";
    std::cout << "(" << t2.first << "," << t2.second << "),";
    std::cout << "(" << t3.first << "," << t3.second << "))";
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    try{
        Trougao tr1(t1,t2,t);
        Trougao tr2(t1,t3,t);
        Trougao tr3(t2,t3,t);
        double p = tr1.DajPovrsinu() + tr2.DajPovrsinu() + tr3.DajPovrsinu();
        if(std::abs(DajPovrsinu() - p) < 0.00001) return true;
        else return false;
    }
    catch(...){
        return false;
    }
}

void Trougao::Transliraj(double delta_x, double delta_y){
    Trougao::t1.first += delta_x;
    Trougao::t1.second += delta_y;
    Trougao::t2.first += delta_x;
    Trougao::t2.second += delta_y;
    Trougao::t3.first += delta_x;
    Trougao::t3.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    Tacka centar = DajCentar();
    double delta_x = t.first - centar.first;
    double delta_y = t.second - centar.second;
    Transliraj(delta_x,delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    t1.first = t.first + ((t1.first - t.first) * std::cos(ugao)) - ((t1.second - t.second) * std::sin(ugao));
    t1.second = t.second + ((t1.first - t.first) * std::sin(ugao)) + ((t1.second - t.second) * std::cos(ugao));
    t2.first = t.first + ((t2.first - t.first) * std::cos(ugao)) - ((t2.second - t.second) * std::sin(ugao));
    t2.second = t.second + ((t2.first - t.first) * std::sin(ugao)) + ((t2.second - t.second) * std::cos(ugao));
    t3.first = t.first + ((t3.first - t.first) * std::cos(ugao)) - ((t3.second - t.second) * std::sin(ugao));
    t3.second = t.second + ((t3.first - t.first) * std::sin(ugao)) + ((t3.second - t.second) * std::cos(ugao));
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(std::abs(faktor - 0) < 0.000001) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first = t.first + ((t1.first - t.first) * faktor);
    t1.second = t.second + ((t1.second - t.second) * faktor);
    t2.first = t.first + ((t2.first - t.first) * faktor);
    t2.second = t.second + ((t2.second - t.second) * faktor);
    t3.first = t.first + ((t3.first - t.first) * faktor);
    t3.second = t.second + ((t3.second - t.second) * faktor);
}

void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
}

void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(),faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if(t1.DajTjeme(1) == t2.DajTjeme(1)){
        if(t1.DajTjeme(2) == t2.DajTjeme(2)) return (t1.DajTjeme(3) == t2.DajTjeme(3));
        else if(t1.DajTjeme(2) == t2.DajTjeme(3)) return (t1.DajTjeme(3) == t2.DajTjeme(2));
        else return false;
    }
    else if(t1.DajTjeme(1) == t2.DajTjeme(2)){
        if(t1.DajTjeme(2) == t2.DajTjeme(1)) return (t1.DajTjeme(3) == t2.DajTjeme(3));
        else if(t1.DajTjeme(2) == t2.DajTjeme(3)) return (t1.DajTjeme(3) == t2.DajTjeme(1));
        else return false;
    }
    else if(t1.DajTjeme(1) == t2.DajTjeme(3)){
        if(t1.DajTjeme(2) == t2.DajTjeme(2)) return (t1.DajTjeme(3) == t2.DajTjeme(1));
        else if(t1.DajTjeme(2) == t2.DajTjeme(1)) return (t1.DajTjeme(3) == t2.DajTjeme(2));
        else return false;
    }
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    bool slicni = DaLiSuSlicni(t1,t2);
    if(slicni) return (std::abs(t1.DajObim() - t2.DajObim()) < 0.000001);
    else return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    if(std::abs(t1.DajUgao(1) - t2.DajUgao(1)) < 0.000001){
        if(std::abs(t1.DajUgao(2) - t2.DajUgao(2)) < 0.000001) return (std::abs(t1.DajUgao(3) - t2.DajUgao(3)) < 0.000001);
        else if(std::abs(t1.DajUgao(2) - t2.DajUgao(3)) < 0.000001) return (std::abs(t1.DajUgao(3) - t2.DajUgao(2)) < 0.000001);
        else return false;
    }
    else if(std::abs(t1.DajUgao(1) - t2.DajUgao(2)) < 0.000001){
        if(std::abs(t1.DajUgao(2) - t2.DajUgao(1)) < 0.000001) return (std::abs(t1.DajUgao(3) - t2.DajUgao(3)) < 0.000001);
        else if(std::abs(t1.DajUgao(2) - t2.DajUgao(3)) < 0.000001) return (std::abs(t1.DajUgao(3) - t2.DajUgao(1)) < 0.000001);
        else return false;
    }
    else if(std::abs(t1.DajUgao(1) - t2.DajUgao(3)) < 0.000001){
        if(std::abs(t1.DajUgao(2) - t2.DajUgao(2)) < 0.000001) return (std::abs(t1.DajUgao(3) - t2.DajUgao(1)) < 0.000001);
        else if(std::abs(t1.DajUgao(2) - t2.DajUgao(1)) < 0.000001) return (std::abs(t1.DajUgao(3) - t2.DajUgao(2)) < 0.000001);
        else return false;
    }
    else return false;
}

int main ()
{
	int n;
	std::cout << "Koliko zelite kreirati trouglova: ";
	std::cin >> n;
	std::vector<std::shared_ptr<Trougao>> trouglovi;
	for(int i = 0; i < n; i++){
	    int x1,x2,x3,y1,y2,y3;
	    std::cout << "Unesite podatke za " << i + 1 << ". trougao ";
	    std::cout << "(x1 y1 x2 y2 x3 y3): ";
	    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	    try{
	        trouglovi.push_back(std::make_shared<Trougao>(Tacka(x1,y1),Tacka(x2,y2),Tacka(x3,y3)));
	    }
	    catch(std::exception &e){
	        std::cout << e.what() << std::endl;
	        i--;
	    }
	}
	double dx,dy,ugao,faktor;
	std::cout << "Unesite vektor translacije (dx dy): ";
	std::cin >> dx >> dy;
	std::cout << "Unesite ugao rotacije: ";
	std::cin >> ugao;
	std::cout << "Unesite faktor skaliranja: ";
	std::cin >> faktor;
	std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),
	    [dx,dy](std::shared_ptr<Trougao> t){ 
	        t->Transliraj(dx,dy); 
	        return std::make_shared<Trougao>(t->DajTjeme(1),t->DajTjeme(2),t->DajTjeme(3));
	    });
	std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),
	    [ugao](std::shared_ptr<Trougao> t){ 
	        t->Rotiraj(ugao); 
	        return std::make_shared<Trougao>(t->DajTjeme(1),t->DajTjeme(2),t->DajTjeme(3));
	    });
	std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),
	    [faktor](std::shared_ptr<Trougao> t){ 
	        t->Skaliraj(t->DajTjeme(1),faktor); 
	        return std::make_shared<Trougao>(t->DajTjeme(1),t->DajTjeme(2),t->DajTjeme(3));
	    });
	std::sort(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2)
	    { return t1->DajPovrsinu() < t2->DajPovrsinu(); });
	std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
	std::for_each(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t){ t->Ispisi(); std::cout << std::endl; });
	std::cout << "Trougao sa najmanjim obimom: ";
	auto min = std::min_element(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2)
	    { return t1->DajObim() < t2->DajObim(); });
	trouglovi[min - trouglovi.begin()]->Ispisi();
	std::cout << std::endl;
	std::cout << "Parovi identicnih trouglova:" << std::endl;
	for(int i = 0; i < trouglovi.size(); i++){
	    for(int j = i + 1; j < trouglovi.size(); j++){
	        if(DaLiSuIdenticni(*trouglovi[i],*trouglovi[j])){
	            trouglovi[i]->Ispisi();
	            std::cout << " i ";
	            trouglovi[j]->Ispisi();
	            std::cout << std::endl;
	        }
	    }
	}
	std::cout << "Parovi podudarnih trouglova:" << std::endl;
	for(int i = 0; i < trouglovi.size(); i++){
	    for(int j = i + 1; j < trouglovi.size(); j++){
	        if(DaLiSuPodudarni(*trouglovi[i],*trouglovi[j])){
	            trouglovi[i]->Ispisi();
	            std::cout << " i ";
	            trouglovi[j]->Ispisi();
	            std::cout << std::endl;
	        }
	    }
	}
	std::cout << "Parovi slicnih trouglova:" << std::endl;
	for(int i = 0; i < trouglovi.size(); i++){
	    for(int j = i + 1; j < trouglovi.size(); j++){
	        if(DaLiSuSlicni(*trouglovi[i],*trouglovi[j])){
	            trouglovi[i]->Ispisi();
	            std::cout << " i ";
	            trouglovi[j]->Ispisi();
	            std::cout << std::endl;
	        }
	    }
	}
	return 0;
}