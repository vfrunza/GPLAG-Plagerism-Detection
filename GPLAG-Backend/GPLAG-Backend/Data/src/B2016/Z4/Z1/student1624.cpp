#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

using namespace::std;


typedef pair<double,double> Tacka;

bool JesuLiJednaki(double x, double y, double Eps = 1E-10) 
{
    return abs(x-y) <= Eps*(abs(x)+abs(y));
}
double HeronovaFormula(Tacka t1, Tacka t2, Tacka t3)
{
    double temp;
    temp = get<0>(t1)*(get<1>(t2)-get<1>(t3))
          -get<0>(t2)*(get<1>(t1)-get<1>(t3))
          +get<0>(t3)*(get<1>(t1)-get<1>(t2));
    return temp;
}

class Trougao
{
    Tacka t1,t2,t3;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Orijentacija(t1,t2,t3) == 0)
            throw domain_error("Nekorektne pozicije tjemena");
        Trougao::t1 = t1;
        Trougao::t2 = t2;
        Trougao::t3 = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        Trougao::t1 = t1;
        Trougao::t2 = t2;
        Trougao::t3 = t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks == 1)
            t1 = t;
        if(indeks == 2)
            t2 = t;
        if(indeks == 3)
            t3 = t;
        throw range_error("Nekorektan indeks");
        
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double temp;
        temp = get<0>(t1)*(get<1>(t2)-get<1>(t3))
              -get<0>(t2)*(get<1>(t1)-get<1>(t3))
              +get<0>(t3)*(get<1>(t1)-get<1>(t2));
        if(JesuLiJednaki(temp,0))
            return 0;
        if(temp > 0)
            return 1;
        return -1;
    }
    Tacka DajTjeme(int indeks) const
    {
        if(indeks == 1)
            return t1;
        if(indeks == 2)
            return t2;
        if(indeks == 3)
            return t3;
        throw range_error("Nekorektan indeks");
        
    }
    double DajStranicu(int indeks) const
    {
        if(indeks == 1)
            return sqrt((get<0>(t2)-get<0>(t3)) * (get<0>(t2)-get<0>(t3)) 
                      + (get<1>(t2)-get<1>(t3)) * (get<1>(t2)-get<1>(t3)));
        if(indeks == 2)
            return sqrt((get<0>(t1)-get<0>(t3)) * (get<0>(t1)-get<0>(t3)) 
                      + (get<1>(t1)-get<1>(t3)) * (get<1>(t1)-get<1>(t3)));
        if(indeks == 3)
            return sqrt((get<0>(t2)-get<0>(t1)) * (get<0>(t2)-get<0>(t1)) 
                      + (get<1>(t2)-get<1>(t1)) * (get<1>(t2)-get<1>(t1)));
        throw range_error("Nekorektan indeks");
    }
    double DajUgao(int indeks) const
    {
        if(indeks > 3 || indeks < 1)
            throw range_error("Nekorektan indeks");
        double kos;
        if(indeks == 1)
            kos = (DajStranicu(2)*DajStranicu(2) + DajStranicu(3)*DajStranicu(3) - DajStranicu(1)*DajStranicu(1))/
                    (2*DajStranicu(2)*DajStranicu(3));
        if(indeks == 2)
            kos = (DajStranicu(1)*DajStranicu(1) + DajStranicu(3)*DajStranicu(3) - DajStranicu(2)*DajStranicu(2))/
                    (2*DajStranicu(1)*DajStranicu(3));
        if(indeks == 3)
            kos = (DajStranicu(2)*DajStranicu(2) + DajStranicu(1)*DajStranicu(1) - DajStranicu(3)*DajStranicu(3))/
                    (2*DajStranicu(1)*DajStranicu(2));
        return acos(kos);
    }
    Tacka DajCentar() const
    {
        Tacka t = make_pair((get<0>(t1) + get<0>(t2) + get<0>(t3))/3,
        (get<1>(t1) + get<1>(t2) + get<1>(t3))/3);
        return t;
        
    }
    double DajObim() const
    {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const
    {
        double temp;
        temp = get<0>(t1)*(get<1>(t2)-get<1>(t3))
              -get<0>(t2)*(get<1>(t1)-get<1>(t3))
              +get<0>(t3)*(get<1>(t1)-get<1>(t2));
        return 0.5*abs(temp);
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
        return (Orijentacija(t1,t2,t3) >= 0);
    }
    bool DaLiJeUnutra(const Tacka &t) const
    {
        double a1 = 0.5*abs(HeronovaFormula(t1,t2,t));
        double a2 = 0.5*abs(HeronovaFormula(t1,t3,t));
        double a3 = 0.5*abs(HeronovaFormula(t2,t3,t));
        if(JesuLiJednaki(a1+a2+a3,Trougao::DajPovrsinu()))
            return true;
        return false;
    }
    void Ispisi() const
    {
            cout << "((" << get<0>(t1) << "," << get<1>(t1) << "),("
                 << get<0>(t2) << "," << get<1>(t2) << "),("
                 << get<0>(t3) << "," << get<1>(t3) << "))";
    }
    void Transliraj(double delta_x, double delta_y)
    {
        Tacka x = make_pair(get<0>(t1) + delta_x,get<1>(t1) + delta_y);
        Tacka y = make_pair(get<0>(t2) + delta_x,get<1>(t2) + delta_y);
        Tacka z = make_pair(get<0>(t3) + delta_x,get<1>(t3) + delta_y);
        Postavi(x,y,z);
    }
    void Centriraj(const Tacka &t)
    {
        double dx = get<0>(t) - get<0>(Trougao::DajCentar());
        double dy = get<1>(t) - get<1>(Trougao::DajCentar());
        Transliraj(dx,dy);
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        Tacka x = make_pair(get<0>(t) + (get<0>(t1)-get<0>(t))*cos(ugao)-(get<1>(t1)-get<1>(t))*sin(ugao),
                            get<1>(t) + (get<0>(t1)-get<0>(t))*sin(ugao)+(get<1>(t1)-get<1>(t))*cos(ugao));
        Tacka y = make_pair(get<0>(t) + (get<0>(t2)-get<0>(t))*cos(ugao)-(get<1>(t2)-get<1>(t))*sin(ugao),
                            get<1>(t) + (get<0>(t2)-get<0>(t))*sin(ugao)+(get<1>(t2)-get<1>(t))*cos(ugao));
        Tacka z = make_pair(get<0>(t) + (get<0>(t3)-get<0>(t))*cos(ugao)-(get<1>(t3)-get<1>(t))*sin(ugao),
                            get<1>(t) + (get<0>(t3)-get<0>(t))*sin(ugao)+(get<1>(t3)-get<1>(t))*cos(ugao));
        Postavi(x,y,z);
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(JesuLiJednaki(faktor,0))
            throw domain_error("Nekorektan faktor skaliranja");
        Tacka x = make_pair(get<0>(t) + faktor*(get<0>(t1) - get<0>(t)),get<1>(t) + faktor*(get<1>(t1) - get<1>(t)));
        Tacka y = make_pair(get<0>(t) + faktor*(get<0>(t2) - get<0>(t)),get<1>(t) + faktor*(get<1>(t2) - get<1>(t)));
        Tacka z = make_pair(get<0>(t) + faktor*(get<0>(t3) - get<0>(t)),get<1>(t) + faktor*(get<1>(t3) - get<1>(t)));
        Postavi(x,y,z);
    }
    void Rotiraj(double ugao)
    {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor)
    {
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
    {
        if(JesuLiJednaki(t1.DajPovrsinu(),t2.DajPovrsinu()) && JesuLiJednaki(t1.DajObim(),t2.DajObim()))
        {
            if((t1.DajTjeme(1) == t2.DajTjeme(1) || t1.DajTjeme(1) == t2.DajTjeme(2) ||t1.DajTjeme(1) == t2.DajTjeme(3)) && t1.DajCentar() == t2.DajCentar())
                return true;
        }
        return false;
        
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
    {
        vector<double> str1{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)},
                       str2{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
        vector<double> a1 = str1;
        vector<double> a2 = str2;
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        if(str1 == str2 && JesuLiJednaki(t1.DajPovrsinu(),t2.DajPovrsinu()))
        {
            if(Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) 
            == Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)))
            {
                auto it = find(a2.begin(),a2.end(),a1[0]);
                int poz = it - a2.begin();
                if(a1[1] == a2[(poz+1)%3])
                    return true;
            }
            else
            {
                auto it = find(a2.begin(),a2.end(),a1[0]);
                int poz = it - a2.begin();
                if(a1[2] == a2[(poz+1)%3])
                    return true;
            }
        }
        return false;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
    {
        vector<double> u1{t1.DajUgao(1),t1.DajUgao(2),t1.DajUgao(3)},
                       u2{t2.DajUgao(1),t2.DajUgao(2),t2.DajUgao(3)};
        vector<double> str1{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)},
                       str2{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        sort(u1.begin(),u1.end());
        sort(u2.begin(),u2.end());
        if(u1 == u2)
        {
            double k = str1[0]/str2[0];
            Trougao a(t2);
            a.Skaliraj(k);
            if(DaLiSuPodudarni(t1,a))
                return true;
        }
        return false;
    }
};
int main()
{
    int n;
    cout << "Koliko zelite kreirati trouglova: ";
    cin >> n;
    if(n == 0)
        return 0;
    vector<shared_ptr<Trougao>> v;
    for(int i = 0;i<n;i++)
    {
        double x1,y1,x2,y2,x3,y3;
        cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Tacka t1 = make_pair(x1,y1);
        Tacka t2 = make_pair(x2,y2);
        Tacka t3 = make_pair(x3,y3);
        try
        {
            Trougao a(t1,t2,t3);
            v.push_back(make_shared<Trougao>(t1,t2,t3));
        }
        catch(exception &e)
        {
            cout << e.what() << ", ponovite unos!" << endl;
            i--;
        }
        
    }
    
    double dx,dy;
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> dx >> dy;
    double alfa;
    cout << "Unesite ugao rotacije: ";
    cin >> alfa;
    double k;
    cout << "Unesite faktor skaliranja: ";
    cin >> k;
    try
    {
    transform(v.begin(),v.end(),v.begin(),[dx,dy,alfa,k](shared_ptr<Trougao> t)
    {
        t->Transliraj(dx,dy);
        t->Rotiraj(alfa);
        t->Skaliraj(t->DajTjeme(1),k);
        return t;
    });
    }
    catch(...)
    {
        return 0;
    }
    sort(v.begin(),v.end(),[](shared_ptr<Trougao> t1,shared_ptr<Trougao> t2)
    {
        if(t1->DajPovrsinu() < t2->DajPovrsinu())
            return true;
        return false;
    });
    cout << "Trouglovi nakon obavljenih transformacija:" << endl;
    for_each(v.begin(),v.end(),[](shared_ptr<Trougao> t)
    {
        t->Ispisi();
        cout << endl;
    });
    auto najmanji =  min_element(v.begin(),v.end(),[](shared_ptr<Trougao> t1,shared_ptr<Trougao> t2)
    {
        return t1->DajObim() < t2->DajObim();
    });
    cout << "Trougao sa najmanjim obimom: ";
    (*najmanji)->Ispisi();
    cout << endl;
    bool ima(false);
    for(int i = 0; i < v.size();i++)
    {
        for(int j = i+1 ; j < v.size();j++)
        {
            auto x = *v[i];
            auto y = *v[j];

            if(DaLiSuIdenticni(x,y))
            {
                if(ima == false)
                {
                    cout << "Parovi identicnih trouglova:" << endl;
                    ima = true;
                }
                x.Ispisi();
                cout << " i ";
                y.Ispisi();
                cout << endl;
            }
        }
    }
    if(ima == false)
        cout << "Nema identicnih trouglova!" << endl;
    ima = false;
    for(int i = 0; i < v.size();i++)
    {
        for(int j = i+1 ; j < v.size();j++)
        {
            auto x = *v[i];
            auto y = *v[j];
            if(DaLiSuPodudarni(x,y))
            {
                if(ima == false)
                {
                    cout << "Parovi podudarnih trouglova:" << endl;
                    ima = true;
                }
                x.Ispisi();
                cout << " i ";
                y.Ispisi();
                cout << endl;
            }
        }
    }
    if(ima == false)
        cout << "Nema podudarnih trouglova!" << endl;
    ima = false;
    for(int i = 0; i < v.size();i++)
    {
        for(int j = i+1 ; j < v.size();j++)
        {
            auto x = *v[i];
            auto y = *v[j];
            if(DaLiSuSlicni(x,y))
            {
                if(ima == false)
                {
                    cout << "Parovi slicnih trouglova:" << endl;
                    ima = true;
                }
                x.Ispisi();
                cout << " i ";
                y.Ispisi();
                cout << endl;
            }
        }
    }
    if(ima == false)
        cout << "Nema slicnih trouglova!" << endl;
    return 0;
}