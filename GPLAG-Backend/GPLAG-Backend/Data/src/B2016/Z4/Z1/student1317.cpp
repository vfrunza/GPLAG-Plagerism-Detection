/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<double, double> Tacka;

class Trougao
{
    Tacka tjeme_1, tjeme_2, tjeme_3;
    static bool JesuLiJednaki(double x, double y, double Eps = 1e-10) 
    {  }
    static double RacunajIzraz(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    { return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second); }
    
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi(int indeks, const Tacka &t);
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        Tacka DajTjeme(int indeks) const;
        double DajStranicu(int indeks) const;
        double DajUgao(int indeks) const;
        Tacka DajCentar() const { return Tacka(((tjeme_1.first+tjeme_2.first+tjeme_3.first)/3.), ((tjeme_1.second+tjeme_2.second+tjeme_3.second)/3.)); }
        double DajObim() const { return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); }
        double DajPovrsinu() const { return (fabs(RacunajIzraz(tjeme_1, tjeme_2, tjeme_3))/2.); }
        bool DaLiJePozitivnoOrijentiran() const { if(Orijentacija(tjeme_1, tjeme_2, tjeme_3)==1) return true; return false; }
        bool DaLiJeUnutra(const Tacka &t) const;
        void Ispisi() const { cout << "((" << tjeme_1.first << "," << tjeme_1.second << "),(" << tjeme_2.first << "," << tjeme_2.second << "),(" << tjeme_3.first << "," << tjeme_3.second << "))"; }
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

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(Orijentacija(t1, t2, t3)==0) throw domain_error("Nekorektne pozicije tjemena");
    tjeme_1=t1; tjeme_2=t2; tjeme_3=t3;
}

void Trougao::Postavi(int indeks, const Tacka &t)
{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
    if(indeks==1) tjeme_1=t;
    else if(indeks==2) tjeme_2=t;
    else tjeme_3=t;
}

// Funkcija metoda Orijentacija testira kako su orijentirane tri tacke koje
// se zadaju putem parametara i vraca 1 ako su pozitivno orijentirane,
// -1 ako su negativno orijentirane i 0 ako su kolinearne
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(RacunajIzraz(t1, t2, t3)>0) return 1;
    else if(RacunajIzraz(t1, t2, t3)<0) return -1;
    return 0;
}

Tacka Trougao::DajTjeme(int indeks) const
{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
    if(indeks==1) return tjeme_1;
    else if(indeks==2) return tjeme_2;
    return tjeme_3;
}

double Trougao::DajStranicu(int indeks) const
{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
    if(indeks==1) return sqrt((tjeme_2.first-tjeme_3.first)*(tjeme_2.first-tjeme_3.first)+(tjeme_2.second-tjeme_3.second)*(tjeme_2.second-tjeme_3.second));
    else if(indeks==2) return sqrt((tjeme_1.first-tjeme_3.first)*(tjeme_1.first-tjeme_3.first)+(tjeme_1.second-tjeme_3.second)*(tjeme_1.second-tjeme_3.second));
    return sqrt((tjeme_1.first-tjeme_2.first)*(tjeme_1.first-tjeme_2.first)+(tjeme_1.second-tjeme_2.second)*(tjeme_1.second-tjeme_2.second));
}

double Trougao::DajUgao(int indeks) const
{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
    if(indeks==1) return acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(3)*DajStranicu(2)));
    else if(indeks==2) return acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(3)*DajStranicu(1)));
    return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    if(Orijentacija(tjeme_1, tjeme_2, t)==Orijentacija(tjeme_1, tjeme_2, tjeme_3) && Orijentacija(tjeme_2, tjeme_3, t)==Orijentacija(tjeme_1, tjeme_2, tjeme_3) && Orijentacija(tjeme_3, tjeme_1, t)==Orijentacija(tjeme_1, tjeme_2, tjeme_3)) return true;
    return false;
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    tjeme_1.first+=delta_x;
    tjeme_1.second+=delta_y;
    tjeme_2.first+=delta_x;
    tjeme_2.second+=delta_y;
    tjeme_3.first+=delta_x;
    tjeme_3.second+=delta_y;
}

// Funkcija metoda Centriraj translira trougao tako da se nakon nje
// centar trougla nadje u taci koja je zadana kao parametar
void Trougao::Centriraj(const Tacka &t)
{
    Tacka centar(DajCentar());
    double delta_x(t.first-centar.first), delta_y(t.second-centar.second);
    Transliraj(delta_x, delta_y);
}

// Funkcija metoda Rotiraj rotira trougao oko zadane tacke za zadani ugao
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    double x1(tjeme_1.first), x2(tjeme_2.first), x3(tjeme_3.first), y1(tjeme_1.second), y2(tjeme_2.second), y3(tjeme_3.second);
    
    tjeme_1.first=t.first+(x1-t.first)*cos(ugao)-(y1-t.second)*sin(ugao);
    tjeme_1.second=t.second+(x1-t.first)*sin(ugao)+(y1-t.second)*cos(ugao);
    
    tjeme_2.first=t.first+(x2-t.first)*cos(ugao)-(y2-t.second)*sin(ugao);
    tjeme_2.second=t.second+(x2-t.first)*sin(ugao)+(y2-t.second)*cos(ugao);
    
    tjeme_3.first=t.first+(x3-t.first)*cos(ugao)-(y3-t.second)*sin(ugao);
    tjeme_3.second=t.second+(x3-t.first)*sin(ugao)+(y3-t.second)*cos(ugao);
}

// Funkcija metoda Skaliraj skalira trougao tako da mu se sve stranice produze sa zadanim faktorom
void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(JesuLiJednaki(faktor, 0.0)) throw domain_error("Nekorektan faktor skaliranja");
    tjeme_1.first=t.first+(tjeme_1.first-t.first)*faktor;
    tjeme_2.first=t.first+(tjeme_2.first-t.first)*faktor;
    tjeme_3.first=t.first+(tjeme_3.first-t.first)*faktor;
    
    tjeme_1.second=t.second+(tjeme_1.second-t.second)*faktor;
    tjeme_2.second=t.second+(tjeme_2.second-t.second)*faktor;
    tjeme_3.second=t.second+(tjeme_3.second-t.second)*faktor;
}

// Funkcija metoda Rotiraj rotira trougao oko centra trougla za zadani ugao
void Trougao::Rotiraj(double ugao)
{
    Tacka centar(DajCentar());
    Rotiraj(centar, ugao);
}

void Trougao::Skaliraj(double faktor)
{
    Tacka centar(DajCentar());
    Skaliraj(centar, faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if((t1.tjeme_1==t2.tjeme_1 || t1.tjeme_1==t2.tjeme_2 || t1.tjeme_1==t2.tjeme_3) && (t1.tjeme_2==t2.tjeme_1 || t1.tjeme_2==t2.tjeme_2 || t1.tjeme_2==t2.tjeme_3) && (t1.tjeme_3==t2.tjeme_1 || t1.tjeme_3==t2.tjeme_2 || t1.tjeme_3==t2.tjeme_3)) return true;
    
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    double a1(t1.DajStranicu(1)), b1(t1.DajStranicu(3)), c1(t1.DajStranicu(2));
    double a2(t2.DajStranicu(1)), b2(t2.DajStranicu(3)), c2(t2.DajStranicu(2));
    if(DaLiSuIdenticni(t1, t2)) return true;
    if(((Trougao::JesuLiJednaki(a1, a2) && Trougao::JesuLiJednaki(b1, c2) && Trougao::JesuLiJednaki(c1, b2)) || (Trougao::JesuLiJednaki(b1, b2) && Trougao::JesuLiJednaki(a1, c2) && Trougao::JesuLiJednaki(c1, a2)) || (Trougao::JesuLiJednaki(c1, c2) && Trougao::JesuLiJednaki(b1, a2) && Trougao::JesuLiJednaki(a1, b2)))  && Trougao::Orijentacija(t1.tjeme_1, t1.tjeme_2, t1.tjeme_3)!=Trougao::Orijentacija(t2.tjeme_1, t2.tjeme_2, t2.tjeme_3)) return true;
    else if(Trougao::JesuLiJednaki(a1, b2) && Trougao::JesuLiJednaki(b1, c2) && Trougao::JesuLiJednaki(c1, a2)) return true;
    
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    double a1(t1.DajStranicu(1)), b1(t1.DajStranicu(3)), c1(t1.DajStranicu(2));
    double a2(t2.DajStranicu(1)), b2(t2.DajStranicu(3)), c2(t2.DajStranicu(2));
    if(DaLiSuPodudarni(t1, t2)) return true;
    if(((Trougao::JesuLiJednaki(a1/a2, b1/c2) && Trougao::JesuLiJednaki(a1/a2, c1/b2)) || (Trougao::JesuLiJednaki(b1/b2, c1/a2) && Trougao::JesuLiJednaki(b1/b2, a1/c2)) || (Trougao::JesuLiJednaki(c1/c2, b1/a2) && Trougao::JesuLiJednaki(c1/c2, a1/b2))) && Trougao::Orijentacija(t1.tjeme_1, t1.tjeme_2, t1.tjeme_3)!=Trougao::Orijentacija(t2.tjeme_1, t2.tjeme_2, t2.tjeme_3)) return true;
    return false;
}

int main ()
{
	int n;
	
	cout << "Koliko zelite kreirati trouglova: ";
	cin >> n;
	vector<shared_ptr<Trougao>> trouglovi(n);
	
    try
    {
        for(int i=0; i<n; i++)
        {
            cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            double x1, y1, x2, y2, x3, y3;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            try
            {
                trouglovi[i]=make_shared<Trougao>(Trougao(Tacka(x1, y1), Tacka(x2, y2), Tacka(x3, y3)));
            }
            catch(domain_error izuzetak)
            {
                cout << izuzetak.what() << ", ponovite unos!" << endl;
                i--;
            }
        }
        double dx, dy;
        cout << "Unesite vektor translacije (dx dy): ";
        cin >> dx >> dy;
        
        transform(&trouglovi[0], &trouglovi[0]+n, &trouglovi[0], [dx, dy](shared_ptr<Trougao> trougao)
        {
            trougao->Transliraj(dx, dy);
            return trougao;
        });
        
        cout << "Unesite ugao rotacije: ";
        double ugao_rotacije;
        cin >> ugao_rotacije;
        
        transform(&trouglovi[0], &trouglovi[0]+n, &trouglovi[0], [ugao_rotacije](shared_ptr<Trougao> trougao)
        {
            trougao->Rotiraj(ugao_rotacije);
            return trougao;
        });
        
        cout << "Unesite faktor skaliranja: ";
        double faktor;
        cin >> faktor;
        
        transform(&trouglovi[0], &trouglovi[0]+n, &trouglovi[0], [faktor](shared_ptr<Trougao> trougao)
        {
            trougao->Skaliraj(trougao->DajTjeme(1), faktor);
            return trougao;
        });
        
        sort(&trouglovi[0], &trouglovi[0]+n, [](shared_ptr<Trougao> trougao1, shared_ptr<Trougao> trougao2)
        {
            if(trougao1->DajPovrsinu()<trougao2->DajPovrsinu()) return true;
            return false;
        });
        
        cout << "Trouglovi nakon obavljenih transformacija:" << endl;
        for_each(&trouglovi[0], &trouglovi[0]+n, [](shared_ptr<Trougao> trougao){ trougao->Ispisi(); cout << endl; });
        
        cout << "Trougao sa najmanjim obimom: ";
        auto pom(min_element(&trouglovi[0], &trouglovi[0]+n, [](shared_ptr<Trougao> trougao1, shared_ptr<Trougao> trougao2){ if(trougao1->DajObim()<trougao2->DajObim()) return true; return false;}));
        (*pom)->Ispisi();
        
        bool identicni(false);
        
        for(int i=0; i<trouglovi.size(); i++)
        {
            for(int j=i+1; j<trouglovi.size(); j++)
            {
                if(DaLiSuIdenticni(*trouglovi[i], *trouglovi[j]))
                {
                    identicni=true;
                    break;
                }
            }
            if(identicni) break;
        }
        
        if(identicni)
        {
            cout << endl << "Parovi identicnih trouglova:" << endl;
            for(int i=0; i<trouglovi.size(); i++)
            {
                for(int j=i+1; j<trouglovi.size(); j++)
                {
                    if(DaLiSuIdenticni(*trouglovi[i], *trouglovi[j]))
                    {
                        trouglovi[i]->Ispisi();
                        cout << " i ";
                        trouglovi[j]->Ispisi();
                        cout << endl;
                    }
                }
            }
        }
        else cout << endl << "Nema identicnih trouglova!" << endl;
        
        bool podudarni(false);
        for(int i=0; i<trouglovi.size(); i++)
        {
            for(int j=i+1; j<trouglovi.size(); j++)
            {
                if(DaLiSuPodudarni(*trouglovi[i], *trouglovi[j]))
                {
                    podudarni=true;
                    break;
                }
            }
            if(podudarni) break;
        }
        
        if(podudarni)
        {
            cout << "Parovi podudarnih trouglova:" << endl;
            for(int i=0; i<trouglovi.size(); i++)
            {
                for(int j=i+1; j<trouglovi.size(); j++)
                {
                    if(DaLiSuPodudarni(*trouglovi[i], *trouglovi[j]))
                    {
                        trouglovi[i]->Ispisi();
                        cout << " i ";
                        trouglovi[j]->Ispisi();
                        cout << endl;
                    }
                }
            }
        }
        else cout << "Nema podudarnih trouglova!" << endl;
        
        bool slicni(false);
        
        for(int i=0; i<trouglovi.size(); i++)
        {
            for(int j=i+1; j<trouglovi.size(); j++)
            {
                if(DaLiSuSlicni(*trouglovi[i], *trouglovi[j]))
                {
                    slicni=true;
                    break;
                }
            }
            if(slicni) break;
        }
        
        if(slicni)
        {
            cout << "Parovi slicnih trouglova:" << endl;
            for(int i=0; i<trouglovi.size(); i++)
            {
                for(int j=i+1; j<trouglovi.size(); j++)
                {
                    if(DaLiSuSlicni(*trouglovi[i], *trouglovi[j]))
                    {
                        trouglovi[i]->Ispisi();
                        cout << " i ";
                        trouglovi[j]->Ispisi();
                        cout << endl;
                    }
                }
            }
        }
        else cout << "Nema slicnih trouglova!" << endl;
    }
    catch(domain_error izuzetak)
    {
        cout << izuzetak.what() << endl;
    }
    catch(range_error izuzetak)
    {
        cout << izuzetak.what() << endl;
    }
	
	
	return 0;
}