/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <string>
#include <list>
#include <vector>
#include <memory>

#define EPS 0.001

using namespace std;

typedef pair<double, double> Tacka;

bool IstiDouble(const double a, const double b){
    return fabs(a - b) < EPS;
}

class Trougao {
private:
    Tacka t1, t2, t3;
    void ProvjeriIndex(int n) const { if(n < 1 || n > 3) throw range_error("Nekorektan indeks"); }
    double DajStranicu(Tacka t1, Tacka t2) const;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
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

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1, t2, t3) == 0) throw domain_error("Nekorektne pozicije tjemena");
    this->t1 = t1; this->t2 = t2; this->t3 = t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1, t2, t3) == 0) throw domain_error("Nekorektne pozicije tjemena");
    this->t1 = t1; this->t2 = t2; this->t3 = t3;
}

void Trougao::Postavi(int index, const Tacka &t){
    ProvjeriIndex(index);
    if(index == 1) Orijentacija(t, t2, t3), t1 = t;
    else if(index == 2) Orijentacija(t1, t, t3), t2 = t;
    else if(index == 3) Orijentacija(t1, t2, t), t3 = t;
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double rez = t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
    return rez < 0 ? -1 : rez > 0 ? 1 : 0;
}

void Trougao::Ispisi() const {
    cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
}

Tacka Trougao::DajTjeme(int indeks) const {
    ProvjeriIndex(indeks);
    return indeks == 1 ? t1 : indeks == 2 ? t2 : t3;
}

double Trougao::DajStranicu(Tacka t1, Tacka t2) const {
    return sqrt((t1.first - t2.first) * (t1.first - t2.first) + (t1.second - t2.second) * (t1.second - t2.second));
}

double Trougao::DajStranicu(int indeks) const {
    ProvjeriIndex(indeks);
    return indeks == 1 ? DajStranicu(t2, t3) : indeks == 2 ? DajStranicu(t1, t3) : DajStranicu(t1, t2);
}

double Trougao::DajUgao(int indeks) const {
    ProvjeriIndex(indeks);
    double a = DajStranicu(1);
    double b = DajStranicu(2);
    double c = DajStranicu(3);
    return indeks == 1 ? acos((b * b + c * c - a * a) / (2 * b * c)) : indeks == 2 ? acos((a * a + c * c - b * b) / (2 * a * c)) : acos((b * b + a * a - c * c) / (2 * b * a));
}

Tacka Trougao::DajCentar() const {
    return Tacka((t1.first + t2.first + t3.first) / 3, (t1.second + t2.second + t3.second) / 3);
}

void Trougao::Transliraj(double delta_x, double delta_y){
    t1 = {t1.first + delta_x, t1.second + delta_y};
    t2 = {t2.first + delta_x, t2.second + delta_y};
    t3 = {t3.first + delta_x, t3.second + delta_y};
}

void Trougao::Centriraj(const Tacka &t){
    Transliraj(t.first - DajCentar().first, t.second - DajCentar().second);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    t1 = { t.first + (t1.first - t.first) * cos(ugao) - (t1.second - t.second) * sin(ugao), t.second + (t1.first - t.first) * sin(ugao) + (t1.second - t.second) * cos(ugao) };
    t2 = { t.first + (t2.first - t.first) * cos(ugao) - (t2.second - t.second) * sin(ugao), t.second + (t2.first - t.first) * sin(ugao) + (t2.second - t.second) * cos(ugao) };
    t3 = { t.first + (t3.first - t.first) * cos(ugao) - (t3.second - t.second) * sin(ugao), t.second + (t3.first - t.first) * sin(ugao) + (t3.second - t.second) * cos(ugao) };
    
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(IstiDouble(faktor, 0)) throw domain_error("Nekorektan faktor skaliranja");
    t1 = { t.first + faktor * (t1.first - t.first), t.second + faktor * (t1.second - t.second) };
    t2 = { t.first + faktor * (t2.first - t.first), t.second + faktor * (t2.second - t.second) };
    t3 = { t.first + faktor * (t3.first - t.first), t.second + faktor * (t3.second - t.second) };
}

void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(), ugao); 
}

void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(), faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    for(int i(1); i <= 3; i++){
        bool isteTacke(false);
        for(int j(1); j <=3; j++)
            if(IstiDouble(t1.DajTjeme(i).first, t2.DajTjeme(j).first) && IstiDouble(t1.DajTjeme(i).second, t2.DajTjeme(j).second))
                isteTacke = true;
        if(!isteTacke) return false;
    }
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    list<string> prviTip { "vvm", "vmv", "mvv" }; //prvi tip trougla; v = veca, m = manja
    list<string> drugiTip { "vmm", "mmv", "mvm" }; //drugi tip trougla
    string prvi, drugi; //u "prvi" smjestamo odnose od prvog trougla, objasnjenje za "drugi" je logicno
    for(int i(1); i <= 3; i++){
        int j = i == 3 ? 1 : i + 1;
        if(t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)) == 1)
            //ako nije pozitivna orijentacija moramo obrnuti logiku (mjenja se znak poredjenja)
            prvi += t1.DajStranicu(i) > t1.DajStranicu(j) || IstiDouble(t1.DajStranicu(i), t1.DajStranicu(j)) ? "v" : "m";
        else prvi += t1.DajStranicu(i) < t1.DajStranicu(j) || IstiDouble(t1.DajStranicu(i), t1.DajStranicu(j)) ? "v" : "m";
        if(t2.Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)) == 1)
            drugi += t2.DajStranicu(i) > t2.DajStranicu(j) || IstiDouble(t2.DajStranicu(i), t2.DajStranicu(j)) ? "v" : "m";
        drugi += t2.DajStranicu(i) < t2.DajStranicu(j) || IstiDouble(t2.DajStranicu(i), t2.DajStranicu(j)) ? "v" : "m";
    }
    auto it1 = find(prviTip.begin(), prviTip.end(), prvi); // gledamo kojeg je tipa trougao
    auto it2 = find(prviTip.begin(), prviTip.end(), drugi);
    if((it1 != prviTip.end() && it2 == prviTip.end()) || (it1 == prviTip.end() && it2 != prviTip.end())) return false;
    //dakle, ako oba trougla nisu istog tipa nisu podudarni
    //ako su istog tipa onda provjeravamo da li imaju iste duzine stranica
    list<double> str1 { t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3) }, str2 { t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3) };
    for(auto it3 = str1.begin(); it3 != str1.end(); it3++){
        auto it4 = find_if(str2.begin(), str2.end(), [it3](double n){
            return IstiDouble(*it3, n);
        });
        if(it4 == str2.end()) return false;
        str2.erase(it4); //ukoliko smo nasli istu stranicu u oba trougla, izbrisacemo jednu(od drugog trougla) iz liste jer jbg
    }
    return true;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    list<string> prviTip { "vvm", "vmv", "mvv" }; //prvi tip trougla; v = veca, m = manja
    list<string> drugiTip { "vmm", "mmv", "mvm" }; //drugi tip trougla
    string prvi, drugi; //u "prvi" smjestamo odnose od prvog trougla, objasnjenje za "drugi" je logicno
    for(int i(1); i <= 3; i++){
        int j = i == 3 ? 1 : i + 1;
        if(t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)) == 1)
            //ako nije pozitivna orijentacija moramo obrnuti logiku (mjenja se znak poredjenja)
            prvi += t1.DajStranicu(i) > t1.DajStranicu(j) || IstiDouble(t1.DajStranicu(i), t1.DajStranicu(j)) ? "v" : "m";
        else prvi += t1.DajStranicu(i) < t1.DajStranicu(j) || IstiDouble(t1.DajStranicu(i), t1.DajStranicu(j)) ? "v" : "m";
        if(t2.Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)) == 1)
            drugi += t2.DajStranicu(i) > t2.DajStranicu(j) || IstiDouble(t2.DajStranicu(i), t2.DajStranicu(j)) ? "v" : "m";
        drugi += t2.DajStranicu(i) < t2.DajStranicu(j) || IstiDouble(t2.DajStranicu(i), t2.DajStranicu(j)) ? "v" : "m";
    }
    auto it1 = find(prviTip.begin(), prviTip.end(), prvi); // gledamo kojeg je tipa trougao
    auto it2 = find(prviTip.begin(), prviTip.end(), drugi);
    if((it1 != prviTip.end() && it2 == prviTip.end()) || (it1 == prviTip.end() && it2 != prviTip.end())) return false;
    //dakle, ako oba trougla nisu istog tipa nisu podudarni
    //ako su istog tipa onda provjeravamo da li imaju iste uglove
    list<double> uglovi1 { t1.DajUgao(1), t1.DajUgao(2), t1.DajUgao(3) }, uglovi2 { t2.DajUgao(1), t2.DajUgao(2), t2.DajUgao(3) };
    for(auto it3 = uglovi1.begin(); it3 != uglovi1.end(); it3++){
        auto it4 = find_if(uglovi2.begin(), uglovi2.end(), [it3](double n){
           return IstiDouble(*it3, n); 
        });
        if(it4 == uglovi2.end()) return false;
        uglovi2.erase(it4);
    }
    return true;
}

double Trougao::DajObim() const {
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}

double Trougao::DajPovrsinu() const {
    return 0.5 * fabs(t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    return Orijentacija(t1, t2, t3) == 1 ? true : false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    int temp(Orijentacija(t1, t2, t3));
    return temp == Orijentacija(t1, t2, t) && temp == Orijentacija(t2, t3, t3) && temp == Orijentacija(t3, t2, t);
}

int main(){
    try{
        int n;
        cout << "Koliko zelite kreirati trouglova: ";
        cin >> n;
        vector<shared_ptr<Trougao>> v(n);
        for(int i(1); i <= n;){
            cout << "Unesite podatke za " << i << ". trougao (x1 y1 x2 y2 x3 y3): ";
            vector<Tacka> tacke;
            for(int j(1); j <= 3; j++){
                double x, y;
                cin >> x >> y;
                tacke.push_back({x, y});
            }
            Trougao* t;
            try{
                t = new Trougao(tacke[0], tacke[1], tacke[2]);
                v[i - 1] = make_shared<Trougao> (*t);
                i++;
                t = nullptr;
            }catch(exception &e){
                cout << e.what() << ", ponovite unos!" << endl;
                delete t;
            }
        }
        double delta_x, delta_y;
        cout << "Unesite vektor translacije(dx i dy): ";
        cin >> delta_x >> delta_y;
        double ugaoRotacije, faktorSkaliranja;
        cout << "Unesite ugao rotacije: ";
        cin >> ugaoRotacije;
        cout << "Unesite faktor skaliranja: ";
        cin >> faktorSkaliranja;
        
        transform(v.begin(), v.end(), v.begin(), [=](shared_ptr<Trougao> t){
           t->Transliraj(delta_x, delta_y);
           t->Rotiraj(ugaoRotacije);
           t->Skaliraj(t->DajTjeme(1), faktorSkaliranja);
           return t;
        });
        
        sort(v.begin(), v.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao> t2){
            return t1->DajPovrsinu() < t2->DajPovrsinu();
        });
        cout << "Trouglovi nakon obavljenih transformacija: " << endl;
        for_each(v.begin(), v.end(), [](shared_ptr<Trougao> t) {
           t->Ispisi(); cout << endl;
        });
        cout << "Trougao sa najmanjim obimom: ";
        (**max_element(v.begin(), v.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao> t2){
            return t1->DajObim() > t2->DajObim();
        })).Ispisi();
        cout << endl;
        bool postoji(false);
        for(int i(0); i < (int)v.size(); i++){
            for(int j(i + 1); j < (int)v.size(); j++){
                if(DaLiSuIdenticni(*v[i], *v[j])){
                    postoji = true; 
                    break;
                }
            }
        }
        if(!postoji) cout << "Nema identicnih trouglova!" << endl;
        else{
            cout << "Parovi identicnih trouglova:" << endl;
            for(int i(0); i < (int)v.size(); i++){
                for(int j(i + 1); j < (int)v.size(); j++){
                    if(DaLiSuIdenticni(*v[i], *v[j])){
                        v[i]->Ispisi(); cout << " i "; v[j]->Ispisi(); cout << endl;
                    }
                }
            }
        }
        postoji = false;
        
        for(int i(0); i < (int)v.size(); i++){
            for(int j(i + 1); j < (int)v.size(); j++){
                if(DaLiSuPodudarni(*v[i], *v[j])){
                    postoji = true; 
                    break;
                }
            }
        }
        if(!postoji) cout << "Nema podudarnih trouglova!" << endl;
        else{
            cout << "Parovi podudarnih trouglova:" << endl;
            for(int i(0); i < (int)v.size(); i++){
                for(int j(i + 1); j < (int)v.size(); j++){
                    if(DaLiSuPodudarni(*v[i], *v[j])){
                        v[i]->Ispisi(); cout << " i "; v[j]->Ispisi(); cout << endl;
                    }
                }
            }
        }
        postoji = false;
        for(int i(0); i < (int)v.size(); i++){
            for(int j(i + 1); j < (int)v.size(); j++){
                if(DaLiSuSlicni(*v[i], *v[j])){
                    postoji = true; 
                    break;
                }
            }
        }
        if(!postoji) cout << "Nema slicnih trouglova!" << endl;
        else{
            cout << "Parovi slicnih trouglova:" << endl;
            for(int i(0); i < (int)v.size(); i++){
                for(int j(i + 1); j < (int)v.size(); j++){
                    if(DaLiSuSlicni(*v[i], *v[j])){
                        v[i]->Ispisi(); cout << " i "; v[j]->Ispisi(); cout << endl;
                    }
                }
            }
        }
        
    }catch(exception &e){
        cout << "Izuzetak: " << e.what() << endl;
    }
    return 0;
}