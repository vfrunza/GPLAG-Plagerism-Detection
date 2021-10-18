/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <set>
#include <new>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;

class Trougao{
    std::vector<Tacka> tacke;
    static int Kolinearne(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double glat(t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second));
        if(glat < 0) return -1;
        else if(glat > 0) return 1;
        return 0;
    }
    double Kolinearne_1(const Tacka &t1, const Tacka &t2, const Tacka &t3) const {
        return (t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second));
    }
    double Duzina(const Tacka &t1, const Tacka &t2) const {
        return std::sqrt((t1.first - t2.first)*(t1.first - t2.first) + (t1.second - t2.second)*(t1.second - t2.second));
    }
    void Nadjiindexe(int &ind1, int &ind2, int &indeks) const {
             if(indeks == 1) {ind1 = 2; ind2 = 3;}
        else if(indeks == 2) {ind1 = 1; ind2 = 3;}
        else if(indeks == 3) {ind1 = 1; ind2 = 2;}
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3):tacke(3){
        if(Kolinearne(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        tacke[0] = t1; tacke[1] = t2; tacke[2] = t3; 
    };
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Kolinearne(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        tacke[0] = t1; tacke[1] = t2; tacke[2] = t3; 
    };
    void Postavi(int indeks, const Tacka &t){
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        std::vector<Tacka> tacke1(tacke); tacke1[indeks] = t;
        if(Kolinearne(tacke1[0], tacke1[1], tacke1[2]) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        tacke[indeks] = t; 
    };
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return Kolinearne(t1, t2, t3);
    };
    Tacka DajTjeme(int indeks) const{
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        return tacke[indeks-1];
    };
    double DajStranicu(int indeks) const{
        if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) return Duzina(tacke[1], tacke[2]);
        else if(indeks == 2)  return Duzina(tacke[0], tacke[2]);
        return Duzina(tacke[0], tacke[1]);
    };
    double DajUgao(int indeks) const{
        int ind1, ind2;
        Nadjiindexe(ind1, ind2, indeks);
        double kosinus_ugla;
        kosinus_ugla = (DajStranicu(ind1)*DajStranicu(ind1) + DajStranicu(ind2)*DajStranicu(ind2) - 
         DajStranicu(indeks)*DajStranicu(indeks)) / (2*DajStranicu(ind1)*DajStranicu(ind2));
        return acos(kosinus_ugla);
    };
    Tacka DajCentar() const{
        Tacka centar;
        centar.first = (tacke[0].first + tacke[1].first + tacke[2].first) / 3;
        centar.second = (tacke[0].second + tacke[1].second + tacke[2].second) / 3;
        return centar;
    };
    double DajObim() const{
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    };
    double DajPovrsinu() const{
        return 0.5*fabs((tacke[0].first*(tacke[1].second - tacke[2].second) - tacke[1].first*(tacke[0].second - tacke[2].second) + tacke[2].first*(tacke[0].second - tacke[1].second)));
      //  return (1/2)*abs(Kolinearne_1(tacke[0], tacke[1], tacke[2]));
    };
    bool DaLiJePozitivnoOrijentiran() const{
        if(Kolinearne(tacke[0], tacke[1], tacke[2]) > 0) return true;
        return false;
    };
    bool DaLiJeUnutra(const Tacka &t) const{
        double duz1(Duzina(tacke[0], t)), duz2(Duzina(tacke[1], t)), duz3(Duzina(tacke[2], t)); 
        double str1(DajStranicu(1)), str2(DajStranicu(2)), str3(DajStranicu(3));
        if(duz1 > str1 || duz1 > str2 || duz1 > str3) return false;
        if(duz2 > str1 || duz2 > str2 || duz2 > str3) return false;
        if(duz3 > str3 || duz3 > str2 || duz3 > str3) return false;
        return true;
    };
    void Ispisi() const{
        std::cout << "(" << "("<<tacke[0].first<<","<<tacke[0].second<<")" << "," << "(" <<tacke[1].first<<",";
        std::cout << tacke[1].second<< ")" << "," << "(" <<tacke[2].first<<","<<tacke[2].second<< ")" <<")";
    };
    void Transliraj(double delta_x, double delta_y){
        tacke[0].first += delta_x; tacke[0].second += delta_y;
        tacke[1].first += delta_x; tacke[1].second += delta_y;
        tacke[2].first += delta_x; tacke[2].second += delta_y;
    };
    void Centriraj(const Tacka &t){
       double delta_x, delta_y;
       delta_x = t.first - this->DajCentar().first;
       delta_y = t.second - this->DajCentar().second;
       this->Transliraj(delta_x, delta_y);
    };
    void Rotiraj(const Tacka &t, double ugao){
        tacke[0].first = t.first + (tacke[0].first - t.first)*cos(ugao) - (tacke[0].second - t.second)*sin(ugao);
        tacke[0].second = t.second + (tacke[0].first - t.first)*sin(ugao) + (tacke[0].second - t.second)*cos(ugao);
        tacke[1].first = t.first + (tacke[1].first - t.first)*cos(ugao) - (tacke[1].second - t.second)*sin(ugao);
        tacke[1].second = t.second + (tacke[1].first - t.first)*sin(ugao) + (tacke[1].second - t.second)*cos(ugao);
        tacke[2].first = t.first + (tacke[2].first - t.first)*cos(ugao) - (tacke[2].second - t.second)*sin(ugao);
        tacke[2].second = t.second + (tacke[2].first - t.first)*sin(ugao) + (tacke[2].second - t.second)*cos(ugao);
    };
    void Skaliraj(const Tacka &t, double faktor){
        if(faktor > 0 && faktor < 0.00000000000000000001) throw std::domain_error("Nekorektan faktor skaliranja");
        tacke[0].first = t.first + faktor*(tacke[0].first - t.first);
        tacke[0].second = t.second + faktor*(tacke[0].second - t.second);
        tacke[1].first = t.first + faktor*(tacke[1].first - t.first);
        tacke[1].second = t.second + faktor*(tacke[1].second - t.second);
        tacke[2].first = t.first + faktor*(tacke[2].first - t.first);
        tacke[2].second = t.second + faktor*(tacke[2].second - t.second);
    };
    void Rotiraj(double ugao){
        Tacka t; t = DajCentar();
        Rotiraj(t, ugao);
    };
    void Skaliraj(double faktor){
        Tacka t; t = DajCentar();
        Skaliraj(t, faktor);
    };
    friend bool Uporedi(const Tacka &t1, const Tacka &t2);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool Uporedi(const Tacka &t1, const Tacka &t2){
      if(fabs(t1.first - t2.first) < 0.000000000001 && fabs(t1.second - t2.second) < 0.000000000001) return true;
      return false;
    }
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    int br(0);
    for(int i = 0; i< 3; i++)
        for(int j= 0 ; j < 3; j++)
            if(Uporedi(t1.tacke[i], t2.tacke[j]))  br++;
    if(br == 3) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::set<double> s1; s1.insert(t1.DajStranicu(1));s1.insert(t1.DajStranicu(2));s1.insert(t1.DajStranicu(3));
    std::set<double> s2; s2.insert(t2.DajStranicu(1));s2.insert(t2.DajStranicu(2));s2.insert(t2.DajStranicu(3));
    std::vector<std::pair<double, Tacka>> v3;
    std::vector<std::pair<double, Tacka>> v4;
    for(int i=0; i<3; i++){
    std::pair<double, Tacka> par;
    par.first = t1.DajStranicu(i+1); par.second = t1.DajTjeme(i+1);
    v3.push_back(par);
    }
    std::sort(v3.begin(), v3.end());
    for(int i=0; i<3; i++){
    std::pair<double, Tacka> par;
    par.first = t2.DajStranicu(i+1); par.second = t2.DajTjeme(i+1);
    v4.push_back(par);
    }
    std::sort(v4.begin(), v4.end());
    return (s1 == s2 && Trougao::Kolinearne(v3[0].second, v3[1].second, v3[2].second) == Trougao::Kolinearne(v4[0].second, v4[1].second, v4[2].second));
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::set<double> s1; s1.insert(t1.DajStranicu(1));s1.insert(t1.DajStranicu(2));s1.insert(t1.DajStranicu(3));
    std::set<double> s2; s2.insert(t2.DajStranicu(1));s2.insert(t2.DajStranicu(2));s2.insert(t2.DajStranicu(3));
    if(s1.size() != s2.size()) return false;
    auto it1=s1.begin(); auto it2=s2.begin(); double omjer(*it1 / *it2); int br(s1.size()); it1++; it2++;
    while(br != 0){
        if(fabs(*it1 / *it2 - omjer) > 0.00000000001) return false;
        it1++; it2++; 
        br--;
    }
    std::vector<std::pair<double, Tacka>> v3;
    std::vector<std::pair<double, Tacka>> v4;
    for(int i=0; i<3; i++){
    std::pair<double, Tacka> par;
    par.first = t1.DajStranicu(i+1); par.second = t1.DajTjeme(i+1);
    v3.push_back(par);
    }
    std::sort(v3.begin(), v3.end());
    for(int i=0; i<3; i++){
    std::pair<double, Tacka> par;
    par.first = t2.DajStranicu(i+1); par.second = t2.DajTjeme(i+1);
    v4.push_back(par);
    }
    std::sort(v4.begin(), v4.end());
    return Trougao::Kolinearne(v3[0].second, v3[1].second, v3[2].second) == Trougao::Kolinearne(v4[0].second, v4[1].second, v4[2].second);
}
bool ImaUVek(std::vector<std::pair<int, int>> vek,std::pair<int, int> index1,std::pair<int, int> index2){
    for(int i=0; i<vek.size(); i++)
        if(vek[i]==index1 || vek[i]==index2) return true;
    return false;
}
int main ()
{
    using std::cout; using std::cin;
    int n;
    cout << "Koliko zelite kreirati trouglova: ";
    cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    double x1, y1, x2, y2, x3, y3;
    Tacka t1, t2, t3;
    for(int i=0; i<n; i++){
    cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
    cin >>x1>>y1>>x2>>y2>>x3>>y3;
    t1.first = x1; t1.second = y1; t2.first = x2; t2.second = y2; t3.first = x3; t3.second = y3;
    try{
        v[i] = std::make_shared<Trougao> (Trougao(t1, t2, t3));
    }
    catch(std::bad_alloc){cout << "Problemi sa memorijom";}
    catch(std::domain_error cigla){cout << "Nekorektne pozicije tjemena, ponovite unos!\n"; i--;}
    }
    double ugao, faktor, a, b;
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> a >> b;
    cout << "Unesite ugao rotacije: ";
    cin >> ugao;
    cout << "Unesite faktor skaliranja: ";
    cin >> faktor;
    std::transform(v.begin(), v.end(), v.begin(), [a, b, ugao, faktor](const std::shared_ptr<Trougao> &t){
        t->Transliraj(a, b);
        t->Rotiraj(ugao);
        t->Skaliraj((*t).DajTjeme(1), faktor);
        return t;
    });
    std::sort(v.begin(), v.end(), [](const std::shared_ptr<Trougao> &t1, const std::shared_ptr<Trougao> &t2){
        if(t1->DajPovrsinu() < t2->DajPovrsinu() && std::fabs(t1->DajPovrsinu() - t2->DajPovrsinu()) > 0.000000000001)
            return true;
        return false;
    });
    cout << "Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(v.begin(), v.end(), [](const std::shared_ptr<Trougao> &t){(*t).Ispisi();cout<<std::endl;});
    cout << "Trougao sa najmanjim obimom: ";
    (*std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        if(t1->DajObim() < t2->DajObim() && std::fabs(t1->DajObim() - t2->DajObim()) > 0.000000000001)
            return true;
        return false;
    }))->Ispisi();
    
    
    std::vector<std::pair<int, int>> vek;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::pair<int,int> index1; index1.first = i; index1.second = j;
            std::pair<int,int> index2; index2.first = j; index2.second = i;
            if(DaLiSuIdenticni(*v[i], *v[j]) && i!=j && !ImaUVek(vek, index1, index2)){
                vek.push_back(index1); vek.push_back(index2);
            }
        }
    }
    if(vek.size() > 0){
         std::vector<std::pair<int, int>> vek;
    cout << "\nParovi identicnih trouglova: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::pair<int,int> index1; index1.first = i; index1.second = j;
            std::pair<int,int> index2; index2.first = j; index2.second = i;
            if(DaLiSuIdenticni(*v[i], *v[j]) && i!=j && !ImaUVek(vek, index1, index2)){
                vek.push_back(index1); vek.push_back(index2);
                v[i]->Ispisi(); cout<<" i "; v[j]->Ispisi(); cout << "\n";
            }
        }
    }
    }
    else cout << "\nNema identicnih trouglova!";
    
    std::vector<std::pair<int, int>> vekp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::pair<int,int> index1; index1.first = i; index1.second = j;
            std::pair<int,int> index2; index2.first = j; index2.second = i;
            if(DaLiSuPodudarni(*v[i], *v[j]) && i!=j && !ImaUVek(vekp, index1, index2)){
                vekp.push_back(index1); vekp.push_back(index2);
            }
        }
    }
    if(vekp.size() > 0){
    std::vector<std::pair<int, int>> vekp;
    cout << "Parovi podudarnih trouglova: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::pair<int,int> index1; index1.first = i; index1.second = j;
            std::pair<int,int> index2; index2.first = j; index2.second = i;
            if(DaLiSuPodudarni(*v[i], *v[j]) && i!=j && !ImaUVek(vekp, index1, index2)){
                vekp.push_back(index1); vekp.push_back(index2);
                v[i]->Ispisi(); cout<<" i "; v[j]->Ispisi(); cout << "\n";
            }
        }
    }
    }
    else cout << "\nNema podudarnih trouglova!";
    
    std::vector<std::pair<int, int>> veks;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::pair<int,int> index1; index1.first = i; index1.second = j;
            std::pair<int,int> index2; index2.first = j; index2.second = i;
            if(DaLiSuSlicni(*v[i], *v[j]) && i!=j && !ImaUVek(veks, index1, index2)){
                veks.push_back(index1); veks.push_back(index2);
            }
        }
    }
    if(veks.size() > 0){
    std::vector<std::pair<int, int>> veks;
    cout << "Parovi slicnih trouglova: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::pair<int,int> index1; index1.first = i; index1.second = j;
            std::pair<int,int> index2; index2.first = j; index2.second = i;
            if(DaLiSuSlicni(*v[i], *v[j]) && i!=j && !ImaUVek(veks, index1, index2)){
                veks.push_back(index1); veks.push_back(index2);
                v[i]->Ispisi(); cout<<" i "; v[j]->Ispisi(); cout << "\n";
            }
        }
    }
    }
    else cout << "\nNema slicnih trouglova!";
    
    
	return 0;
}