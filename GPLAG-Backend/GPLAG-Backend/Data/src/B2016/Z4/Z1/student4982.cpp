/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
typedef std::pair<double,double> Tacka;

class Trougao
{
   Tacka tjeme1, tjeme2, tjeme3;
   static double Formula(const Tacka &t1, const Tacka &t2, const Tacka &t3)  { return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second); }
   static double Duzina(const Tacka &t1, const Tacka &t2)  { return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second)); }
   static bool Jednake (double a, double b, double eps=1e-10)
   {
       return std::fabs(a-b)<=eps*(std::fabs(a)+std::fabs(b));
   }
   static bool IsteTacke(const Tacka &t1, const Tacka &t2) { if(Jednake(t1.first,t2.first) && Jednake(t1.second,t2.second)) return true; else return false; }
   public:
   Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
   if(Jednake(Formula(t1,t2,t3),0)) throw std::domain_error("Nekorektne pozicije tjemena");
   tjeme1.first=t1.first; tjeme1.second=t1.second; 
   tjeme2.first=t2.first; tjeme2.second=t2.second; 
   tjeme3.first=t3.first; tjeme3.second=t3.second;
   }
   void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
       if(Jednake(Formula(t1,t2,t3),0)) throw std::domain_error("Nekorektne pozicije tjemena");
       tjeme1.first=t1.first; tjeme1.second=t1.second;
       tjeme2.first=t2.first; tjeme2.second=t2.second;
       tjeme3.first=t3.first; tjeme3.second=t3.second;
   }
   void Postavi(int indeks, const Tacka &t) 
   {
       if(indeks==1)
       {
           tjeme1.first=t.first; tjeme1.second=t.second;
       }
       else if(indeks==2)
       {
           tjeme2.first=t.first; tjeme2.second=t.second;
       }
       else if(indeks==3)
       {
           tjeme3.first=t.first; tjeme3.second=t.second;
       }
       else throw std::range_error("Nekorektan indeks");
   }
   static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
   Tacka DajTjeme(int indeks) const { if(indeks==1) return tjeme1; else if(indeks==2) return tjeme2; else if(indeks==3) return tjeme3; else throw std::range_error("Nekorektan indeks"); }
   double DajStranicu(int indeks) const
   {
       if(indeks==1) return Duzina(tjeme2,tjeme3);
       else if(indeks ==2) return Duzina(tjeme1,tjeme3);
       else if(indeks==3) return Duzina(tjeme1,tjeme2);
       else throw std::range_error("Nekorektan indeks");
   }
   double DajUgao(int indeks) const;
   Tacka DajCentar() const { return std::make_pair((tjeme1.first+tjeme2.first+tjeme3.first)/3, (tjeme1.second+tjeme2.second+tjeme3.second)/3); }
   double DajObim() const { return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); }
   double DajPovrsinu() const { return std::abs(Formula(tjeme1,tjeme2,tjeme3))/2; }
   bool DaLiJePozitivnoOrijentiran() const { if(Formula(tjeme1,tjeme2,tjeme3)>0 && !Jednake(Formula(tjeme1,tjeme2,tjeme3),0)) return true; if(Formula(tjeme1,tjeme2,tjeme3)<0 && !Jednake(Formula(tjeme1,tjeme2,tjeme3),0)) return false; }
   bool DaLiJeUnutra(const Tacka &t) const;
   void Ispisi() const { std::cout<<"(("<<tjeme1.first<<","<<tjeme1.second<<"),("<<tjeme2.first<<","<<tjeme2.second<<"),("<<tjeme3.first<<","<<tjeme3.second<<"))"; }
   void Transliraj(double delta_x, double delta_y) ;
   void Centriraj(const Tacka &t) ; 
   void Rotiraj(const Tacka &t, double ugao) ; 
   void Skaliraj(const Tacka &t, double faktor);
   void Rotiraj(double ugao) ;
   void Skaliraj(double faktor);
   friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
   friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
   friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if((Trougao::IsteTacke(t1.tjeme1,t2.tjeme1) && Trougao::IsteTacke(t1.tjeme2,t2.tjeme2) && Trougao::IsteTacke(t1.tjeme3, t2.tjeme3))
    || (Trougao::IsteTacke(t1.tjeme1,t2.tjeme1) && Trougao::IsteTacke(t1.tjeme2,t2.tjeme3) && Trougao::IsteTacke(t1.tjeme3,t2.tjeme2))
    || (Trougao::IsteTacke(t1.tjeme1,t2.tjeme2) && Trougao::IsteTacke(t1.tjeme2,t2.tjeme1) && Trougao::IsteTacke(t1.tjeme3,t2.tjeme3))
    || (Trougao::IsteTacke(t1.tjeme1,t2.tjeme2) && Trougao::IsteTacke(t1.tjeme2,t2.tjeme3) && Trougao::IsteTacke(t1.tjeme3,t2.tjeme1))
    || (Trougao::IsteTacke(t1.tjeme1,t2.tjeme3) && Trougao::IsteTacke(t1.tjeme2,t2.tjeme2) && Trougao::IsteTacke(t1.tjeme3,t2.tjeme1))
    || (Trougao::IsteTacke(t1.tjeme1,t2.tjeme3) && Trougao::IsteTacke(t1.tjeme2,t2.tjeme1) && Trougao::IsteTacke(t1.tjeme3,t2.tjeme2)))
    return true; else return false; 
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if((Trougao::Jednake(t1.DajStranicu(1),t2.DajStranicu(1)) && Trougao::Jednake(t1.DajStranicu(2),t2.DajStranicu(2)) && Trougao::Jednake(t1.DajUgao(3),t2.DajUgao(3)))
    || (Trougao::Jednake(t1.DajStranicu(1),t2.DajStranicu(1)) && Trougao::Jednake(t1.DajStranicu(2),t2.DajStranicu(3)) && Trougao::Jednake(t1.DajUgao(3),t2.DajUgao(2)))
    || (Trougao::Jednake(t1.DajStranicu(1),t2.DajStranicu(2)) && Trougao::Jednake(t1.DajStranicu(2),t2.DajStranicu(1)) && Trougao::Jednake(t1.DajUgao(3),t2.DajUgao(3)))
    || (Trougao::Jednake(t1.DajStranicu(1),t2.DajStranicu(2)) && Trougao::Jednake(t1.DajStranicu(2),t2.DajStranicu(3)) && Trougao::Jednake(t1.DajUgao(3),t2.DajUgao(1)))
    || (Trougao::Jednake(t1.DajStranicu(1),t2.DajStranicu(3)) && Trougao::Jednake(t1.DajStranicu(2),t2.DajStranicu(1)) && Trougao::Jednake(t1.DajUgao(3),t2.DajUgao(2)))
    || (Trougao::Jednake(t1.DajStranicu(1),t2.DajStranicu(3)) && Trougao::Jednake(t1.DajStranicu(2),t2.DajStranicu(2)) && Trougao::Jednake(t1.DajUgao(3),t2.DajUgao(1)))) return true;
    else return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    if((Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(1),t1.DajStranicu(2),t2.DajStranicu(2)) && Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(1),t1.DajStranicu(3)/t2.DajStranicu(3)))
    || (Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(1),t1.DajStranicu(2)/t2.DajStranicu(3)) && Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(1),t1.DajStranicu(3)/t2.DajStranicu(2)))
    || (Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(2),t1.DajStranicu(2)/t2.DajStranicu(1)) && Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(2),t1.DajStranicu(3)/t2.DajStranicu(3)))
    || (Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(2),t1.DajStranicu(2)/t2.DajStranicu(3)) && Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(2),t1.DajStranicu(3)/t2.DajStranicu(1)))
    || (Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(3),t1.DajStranicu(2)/t2.DajStranicu(1)) && Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(3),t1.DajStranicu(3)/t2.DajStranicu(2)))
    || (Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(3),t1.DajStranicu(2)/t2.DajStranicu(2)) && Trougao::Jednake(t1.DajStranicu(1)/t2.DajStranicu(3),t1.DajStranicu(3)/t2.DajStranicu(1))))
    return true;
    else return false;
}
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    Tacka temp1(tjeme1), temp2(tjeme2), temp3(tjeme3);
    tjeme1.first=t.first+((temp1.first-t.first)*cos(ugao))-(sin(ugao)*(temp1.second-t.second));
    tjeme1.second=t.second+(sin(ugao)*(temp1.first-t.first))+(cos(ugao)*(temp1.second-t.second));
    tjeme2.first=t.first+((temp2.first-t.first)*cos(ugao))-(sin(ugao)*(temp2.second-t.second));
    tjeme2.second=t.second+(sin(ugao)*(temp2.first-t.first))+(cos(ugao)*(temp2.second-t.second));
    tjeme3.first=t.first+((temp3.first-t.first)*cos(ugao))-(sin(ugao)*(temp3.second-t.second));
    tjeme3.second=t.second+(sin(ugao)*(temp3.first-t.first))+(cos(ugao)*(temp3.second-t.second));
}
void Trougao::Rotiraj(double ugao)
{
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Transliraj(double delta_x, double delta_y)
{
    Tacka temp1(tjeme1), temp2(tjeme2), temp3(tjeme3);
    tjeme1.first=temp1.first+delta_x; tjeme1.second=temp1.second+delta_y;
    tjeme2.first=temp2.first+delta_x; tjeme2.second=temp2.second+delta_y;
    tjeme3.first=temp3.first+delta_x; tjeme3.second=temp3.second+delta_y;
}
void Trougao::Centriraj(const Tacka &t)
{
    double deltax=(t.first-DajCentar().first), deltay=(t.second-DajCentar().second);
    Transliraj(deltax,deltay);
}
void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(Trougao::Jednake(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka temp1(tjeme1), temp2(tjeme2), temp3(tjeme3);
    tjeme1.first=t.first+faktor*(temp1.first-t.first); tjeme1.second=t.second+faktor*(temp1.second-t.second);
    tjeme2.first=t.first+faktor*(temp2.first-t.first); tjeme2.second=t.second+faktor*(temp2.second-t.second);
    tjeme3.first=t.first+faktor*(temp3.first-t.first); tjeme3.second=t.second+faktor*(temp3.second-t.second);
}
void Trougao::Skaliraj(double faktor)
{
    Skaliraj(DajCentar(),faktor);
}
double Trougao::DajUgao(int indeks) const 
{
    if(indeks==1) return acos(-(DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(2)*DajStranicu(3)));
    if(indeks==2) return acos(-(DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(3)));
    if(indeks==3) return acos(-(DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(2)));
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(Formula(t1,t2,t3)<0) return -1;
    if(Formula(t1,t2,t3)>0) return 1;
    if(Formula(t1,t2,t3)==0) return 0;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const 
{
    if(Orijentacija(tjeme1,tjeme2,tjeme3)==1)
    {
        if(Orijentacija(tjeme1,tjeme2,t)<=0 || Orijentacija(tjeme2,tjeme3,t)<=0 || Orijentacija(tjeme3,tjeme1,t)<=0) return false;
        else return true;
    }
    if (Orijentacija(tjeme1,tjeme2,tjeme3)==-1)
    {
        if(Orijentacija(tjeme1,tjeme2,t)>=0 || Orijentacija(tjeme2,tjeme3,t)>=0 || Orijentacija(tjeme3,tjeme1,t)>=0) return false;
        else return true;
    }
}
int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    try
    {
        std::vector<std::shared_ptr<Trougao>> trougletovi(n);
        int br=0;
        while(1) {
        if(br==n) break;
        std::cout<<"Unesite podatke za "<<br+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        double a,b,c,d,e,f;
        std::cin>>a>>b>>c>>d>>e>>f;
        try {
        trougletovi[br]=std::make_shared<Trougao> (std::make_pair(a,b),std::make_pair(c,d),std::make_pair(e,f));
        }
        catch(std::domain_error e)
        {
            br--;
            std::cout<<e.what()<<", ponovite unos!"<<std::endl;
        }
        br++;
        }
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double deltax, deltay;
        std::cin>>deltax>>deltay;
        double ugaorot;
        std::cout<<"Unesite ugao rotacije: ";
        std::cin>>ugaorot;
        std::cout<<"Unesite faktor skaliranja: ";
        double fak;
        std::cin>>fak;
        std::transform(trougletovi.begin(),trougletovi.end(), trougletovi.begin(),
        [deltax,deltay,ugaorot,fak] (std::shared_ptr<Trougao> pok)
        { pok->Transliraj(deltax, deltay); 
        pok->Rotiraj(ugaorot); 
        pok->Skaliraj(pok->DajTjeme(1),fak); 
        return pok;    
        } );
        std::sort(trougletovi.begin(),trougletovi.end(), [] (std::shared_ptr<Trougao> pok1, std::shared_ptr<Trougao> pok2) { return pok1->DajPovrsinu()<pok2->DajPovrsinu(); } );
        std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
        std::for_each(trougletovi.begin(),trougletovi.end(), [] (std::shared_ptr<Trougao> pok) {pok->Ispisi();std::cout<<std::endl;});
        std::cout<<"Trougao sa najmanjim obimom: ";
        auto min=std::min_element(trougletovi.begin(), trougletovi.end(),[] (std::shared_ptr<Trougao> pok1, std::shared_ptr<Trougao> pok2)
        {
            return pok1->DajObim()<pok2->DajObim();
        } );
        (*min)->Ispisi(); std::cout<<std::endl;
        std::vector<std::pair<Trougao,Trougao>> id, pod, sl;
        for(int i=0;i<trougletovi.size()-1;i++)
        {
            for(int j=i+1;j<trougletovi.size();j++)
            {
                if(DaLiSuPodudarni(*trougletovi[i],*trougletovi[j])) pod.emplace_back(std::make_pair(*trougletovi[i],*trougletovi[j]));
                if(DaLiSuIdenticni(*trougletovi[i],*trougletovi[j])) id.emplace_back(std::make_pair(*trougletovi[i],*trougletovi[j]));
                if(DaLiSuSlicni(*trougletovi[i],*trougletovi[j])) sl.emplace_back(std::make_pair(*trougletovi[i],*trougletovi[j]));
            }
        }
        if(id.size()==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
        else
        {
            std::cout<<"Parovi identicnih trouglova: "<<std::endl;
            for(int i=0;i<id.size();i++)
            {
                id[i].first.Ispisi();
                std::cout<<" i ";
                id[i].second.Ispisi();
                std::cout<<std::endl;
            }
        }
        if(pod.size()==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
        else
        {
            std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
            for(int i=0;i<pod.size();i++)
            {
                pod[i].first.Ispisi(); std::cout<<" i "; pod[i].second.Ispisi();
                std::cout<<std::endl;
            }
        }
        if(sl.size()==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
        else
        {
            std::cout<<"Parovi slicnih trouglova: "<<std::endl;
            for(int i=0;i<sl.size();i++)
            {
                sl[i].first.Ispisi(); std::cout<<" i "; sl[i].second.Ispisi();
                std::cout<<std::endl;
            }
        }
        
        
    }
    catch(...)
    {
        std::cout<<"Belaj"<<std::endl;
    }
	return 0;
}