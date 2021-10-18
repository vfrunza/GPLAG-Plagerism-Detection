/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;


typedef pair<double, double> Tacka;

class Trougao
{
    Tacka tacka1, tacka2, tacka3;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) 
    { 
        Postavi(t1, t2, t3); 
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Orijentacija(t1, t2, t3) == 0)
        throw domain_error("Nekorektne pozicije tjemena");
    
        tacka1 = t1;
        tacka2 = t2;
        tacka3 = t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks != 1 && indeks != 2 && indeks != 3)
            throw range_error("Nekorektan indeks");
        
        if(indeks == 1)
        {
            if(Orijentacija(t, tacka2, tacka3) == 0)
                throw domain_error("Nekorektne pozicije tjemena");
            tacka1 = t;
        }
        else if(indeks == 2) 
        {
            if(Orijentacija(tacka1, t, tacka3) == 0)
                throw domain_error("Nekorektne pozicije tjemena");
            tacka2 = t;
        }
        else 
        {
            if(Orijentacija(t, tacka2, t) == 0)
                throw domain_error("Nekorektne pozicije tjemena");
            tacka3 = t;
        }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) 
    {
        int temp = t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second); 
        int vrati = 0;
        if(temp > 0) vrati = 1;
        else if(temp < 0) vrati = -1;
        return vrati;
    }
    Tacka DajTjeme(int indeks) const 
    {
        if(indeks < 1 || indeks > 3)
            throw range_error("Nekorektan indeks");
        
        if(indeks == 1) return tacka1;
        else if(indeks == 2) return tacka2;
        else return tacka3;
    }
    double DajStranicu(int indeks) const
    {
        if(indeks < 1 || indeks > 3)
            throw range_error("Nekorektan indeks");
            
        if(indeks == 1)
            return sqrt((tacka3.first - tacka2.first) * (tacka3.first - tacka2.first) + (tacka3.second - tacka2.second) * (tacka3.second - tacka2.second));
        else if(indeks == 2)
            return sqrt((tacka3.first - tacka1.first) * (tacka3.first - tacka1.first) + (tacka3.second - tacka1.second) * (tacka3.second - tacka1.second));
        else
            return sqrt((tacka2.first - tacka1.first) * (tacka2.first - tacka1.first) + (tacka2.second - tacka1.second) * (tacka2.second - tacka1.second));
    }
    double DajUgao(int indeks) const
    {
        if(indeks < 1 || indeks > 3)
            throw range_error("Nekorektan indeks");
            
        double a, b, c;
        a = DajStranicu(1);
        b = DajStranicu(2);
        c = DajStranicu(3);
        if(indeks == 1)
            return acos((a * a - b * b - c * c) / (2 * b *c));
        else if(indeks == 2)
            return acos((b * b - a * a - c * c) / (2 * a * c));
        else
            return acos((c * c - a * a - b * b) / (2 * b * c));
    }
    Tacka DajCentar() const
    {
        Tacka teziste;
        teziste.first = (tacka1.first + tacka2.first + tacka3.first) / 3;
        teziste.second = (tacka1.second + tacka2.second + tacka3.second) / 3;
        
        return teziste;
    }
    double DajObim() const
    {
        return (DajStranicu(1) + DajStranicu(2) + DajStranicu(3));
    }
    double DajPovrsinu() const
    {
        return abs(tacka1.first * (tacka2.second - tacka3.second) - tacka2.first * (tacka1.second - tacka3.second) + tacka3.first * (tacka1.second - tacka2.second)) / 2;
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
        if(Orijentacija(tacka1, tacka2, tacka3) == 1) return true;
        else return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const
    {
        if(Orijentacija(tacka1, tacka2, t) == 0 || Orijentacija(tacka2, tacka3, t) == 0 || Orijentacija(tacka1, tacka3, t) == 0) 
            return false;
        if(Orijentacija(tacka1, tacka2, tacka3) == Orijentacija(tacka1, tacka2, t) == Orijentacija(tacka2, tacka3, t) == Orijentacija(tacka3, tacka3, t))
            return true;
        else return false;
    }
    void Ispisi() const
    {
        cout << "((" << tacka1.first << "," << tacka1.second << "),(" << tacka2.first << "," << tacka2.second << "),(" << tacka3.first << "," << tacka3.second << "))"; 
    }
    void Transliraj(double delta_x, double delta_y)
    {
        tacka1.first = tacka1.first + delta_x;
        tacka2.first = tacka2.first + delta_x;
        tacka3.first = tacka3.first + delta_x;
        tacka1.second = tacka1.second + delta_y;
        tacka2.second = tacka2.second + delta_y;
        tacka3.second = tacka3.second + delta_y;
    }
    void Centriraj(const Tacka &t)
    {
        Transliraj(t.first - DajCentar().first, t.second - DajCentar().second);
    }
    void Rotiraj(const Tacka &t, double ugao) 
    {
        // tacka1.first = t.first + (tacka1.first - t.first) * cos(ugao) - (tacka1.second - t.second) * sin(ugao);
        // tacka1.second = t.second + (tacka1.first - t.first) * sin(ugao) + (tacka1.second - t.second) * cos(ugao);
        // tacka2.first = t.first + (tacka2.first - t.first) * cos(ugao) - (tacka2.second - t.second) * sin(ugao);
        // tacka2.second = t.second + (tacka2.first - t.first) * sin(ugao) + (tacka2.second - t.second) * cos(ugao);
        // tacka3.first = t.first + (tacka3.first - t.first) * cos(ugao) - (tacka3.second - t.second) * sin(ugao);
        // tacka3.second = t.second + (tacka3.first - t.first) * sin(ugao) + (tacka3.second - t.second) * cos(ugao);
        
        tacka1.first -= t.first;
        tacka1.second -= t.second;
        double noviX = tacka1.first * cos(ugao) - tacka1.second * sin(ugao);
        double noviY = tacka1.first * sin(ugao) + tacka1.second * cos(ugao);
        tacka1.first = noviX + t.first;
        tacka1.second = noviY + t.second;
        
        tacka2.first -= t.first;
        tacka2.second -= t.second;
        noviX = tacka2.first * cos(ugao) - tacka2.second * sin(ugao);
        noviY = tacka2.first * sin(ugao) + tacka2.second * cos(ugao);
        tacka2.first = noviX + t.first;
        tacka2.second = noviY + t.second;
        
        tacka3.first -= t.first;
        tacka3.second -= t.second;
        noviX = tacka3.first * cos(ugao) - tacka3.second * sin(ugao);
        noviY = tacka3.first * sin(ugao) + tacka3.second * cos(ugao);
        tacka3.first = noviX + t.first;
        tacka3.second = noviY + t.second;
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        const double eps = 1e-10;
        if(abs(faktor) < eps)
            throw domain_error("Nekorektan faktor skaliranja");
        
        tacka1.first = t.first + faktor * (tacka1.first - t.first);
        tacka1.second = t.second + faktor * (tacka1.second - t.second);
        tacka2.first = t.first + faktor * (tacka2.first - t.first);
        tacka2.second = t.second + faktor * (tacka2.second - t.second);
        tacka3.first = t.first + faktor * (tacka3.first - t.first);
        tacka3.second = t.second + faktor * (tacka3.second - t.second);
    }
    void Rotiraj(double ugao)
    {
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj(double faktor)
    {
        Skaliraj(DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    const double eps = 1E-10;
    vector<double> x1{t1.tacka1.first, t1.tacka2.first, t1.tacka3.first}, 
        x2{t2.tacka1.first, t2.tacka2.first, t2.tacka3.first}, 
        y1{t1.tacka1.second, t1.tacka2.second, t1.tacka3.second}, 
        y2{t2.tacka1.second, t2.tacka2.second, t2.tacka3.second};
    
    sort(x1.begin(), x1.end());
    sort(x2.begin(), x2.end());
    sort(y1.begin(), y1.end());
    sort(y2.begin(), y2.end());
    
    if(abs(x1[0] - x2[0]) < eps && abs(x1[1] - x2[1]) < eps && abs(x1[2] - x2[2]) < eps &&
        abs(y1[0] - y2[0]) < eps && abs(y1[1] - y2[1]) < eps && abs(y1[2] - y2[2]) < eps)
        return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    const double eps = 1E-10;
    vector<double> t1stranice{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)}, t2stranice{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
            
    sort(t1stranice.begin(), t1stranice.end());
    sort(t2stranice.begin(), t2stranice.end());
        
    for(int i = 0; i < 3; i++)
        if(abs(t1stranice[i] - t2stranice[i]) > eps)
            return false;
            
    return true;
    
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    vector<double> t1stranice{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)}, t2stranice{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
            
    sort(t1stranice.begin(), t1stranice.end());
    sort(t2stranice.begin(), t2stranice.end());
        
    const double eps = 1E-10;
    double faktor = t1stranice[0] / t2stranice[0];
        
    for(int i = 1; i < 3; i++)
    {
        double faktor1 = t1stranice[i] / t2stranice[i];
        if(fabs(faktor1 - faktor) <= eps)
            faktor1 = faktor;
        if(abs(faktor1 - faktor) > eps)
            return false;
    }
        
    return true; 
}

int main ()
{
    int n;
    Tacka t1, t2, t3;
    
    cout << "Koliko zelite kreirati trouglova: ";
    cin >> n;
    
    vector<shared_ptr<Trougao>> trouglovi; 
    
    for(int i = 0; i < n; i++)
    {
        double x1, x2, x3, y1, y2, y3;
        cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        try
        {
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            
            t1.first = x1;
            t1.second = y1;
            t2.first = x2;
            t2.second = y2;
            t3.first = x3;
            t3.second = y3;
            
            Trougao t(t1, t2, t3);
            trouglovi.push_back(make_shared<Trougao>(t1, t2, t3));
        }
        catch(domain_error e)
        {
            cout << e.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    
    double dx, dy;
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> dx >> dy;
    
    double ugao;
    cout << "Unesite ugao rotacije: ";
    cin >> ugao;
    
    double fs;
    cout << "Unesite faktor skaliranja: ";
    cin >> fs;
    
    transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [&](shared_ptr<Trougao> t)->shared_ptr<Trougao> { t->Transliraj(dx, dy); t->Rotiraj(ugao); t->Skaliraj(t->DajTjeme(1), fs); return t; });
    
    sort(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao> t2)->bool { return t1->DajPovrsinu() < t2->DajPovrsinu(); });
    
    cout << "Trouglovi nakon obavljenih transformacija:" << endl;
    
    for_each(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> t)->void { t->Ispisi(); cout << endl; });
    
    auto najManjiObim = min_element(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao> t2)->bool { return t1->DajObim() < t2->DajObim(); });
    cout << "Trougao sa najmanjim obimom: ";
    (*najManjiObim)->Ispisi();
    cout << endl;
    
    bool imaLiIdenticnih = false;
    bool imaLiPodudarnih = false;
    bool imaLiSlicnih = false;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(DaLiSuIdenticni(*trouglovi[i], *trouglovi[j]) && (i != j))
                imaLiIdenticnih = true;
                
            if(DaLiSuPodudarni(*trouglovi[i], *trouglovi[j]) && (i != j))
                imaLiPodudarnih = true;
                
            if(DaLiSuSlicni(*trouglovi[i], *trouglovi[j]) && (i != j))
                imaLiSlicnih = true;
        }
    }
    
    if(imaLiIdenticnih) cout << "Parovi identicnih trouglova:" << endl;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(DaLiSuIdenticni(*trouglovi[i], *trouglovi[j]) && (i != j))
            {
                trouglovi[i]->Ispisi();
                cout << " i ";
                trouglovi[j]->Ispisi();
                cout << endl;
            }
        }
    }
    
    if(!imaLiIdenticnih) cout << "Nema identicnih trouglova!" << endl;
    
    if(imaLiPodudarnih) cout << "Parovi podudarnih trouglova:" << endl;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(DaLiSuPodudarni(*trouglovi[i], *trouglovi[j]) && (i != j))
            {
                trouglovi[i]->Ispisi();
                cout << " i ";
                trouglovi[j]->Ispisi();
                cout << endl;
            }
        }
    }
    
    if(!imaLiPodudarnih) cout << "Nema podudarnih trouglova!" << endl;
    
    
    
    if(imaLiSlicnih) cout << "Parovi slicnih trouglova:" << endl;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(DaLiSuSlicni(*trouglovi[i], *trouglovi[j]) && (i != j))
            {
                trouglovi[i]->Ispisi();
                cout << " i ";
                trouglovi[j]->Ispisi();
                cout << endl;
            }
        }
    }
    
    if(!imaLiSlicnih) cout << "Nema slicnih trouglova!" << endl;
    
	return 0;
}