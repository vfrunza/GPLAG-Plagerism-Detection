#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

const double pi=4*atan(1.);
const double E=1E-10;
typedef std::pair<double,double> Tacka;
#define Ep -0.00001

class Trougao 
{
    double x1,y1,x2,y2,x3,y3;
      static double Pomocna (int x1,int y1,int x2,int y2,int x3,int y3) 
    {
        double izraz;
       
        izraz = (x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2));
        return izraz;
    }
        bool Isti (double t1,double t2,double t3,double t4)
    {
        if (fabs(t1-t2<E) && fabs(t3-t4<E)) return true;
    }
    
   
    
   static std::vector<std::pair<double,double>> DajTjemena (const Trougao &t2)
{
     // staviti tjemena drugog trougla u vektor  i onda for petlju
     
   std::vector<std::pair<double,double>> tjemena(3);
  
  tjemena[0].first=t2.x1;tjemena[0].second=t2.y1;
  tjemena[1].first=t2.x2;tjemena[1].second=t2.y2;
  tjemena[2].first=t2.x3;tjemena[2].second=t2.y3;
  
  return tjemena; 
}
 std::vector<std::pair<double,double>> DajVektor (const Trougao &t1, const Trougao &t2)
 {
  std::vector<std::pair<double,double>> tjeme;
  tjeme[0].first=t1.x1;tjeme[0].second=t1.y1;
  tjeme[1].first=t1.x2;tjeme[1].second=t1.y2;
  tjeme[2].first=t1.x3;tjeme[2].second=t1.y3;
  return tjeme;
}
    
    
    public:
    Trougao (const Tacka &t1,const Tacka &t2,const Tacka &t3) 
    {   if (Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        x1=t1.first;y1=t1.second; x2=t2.first;y2=t2.second; x3=t3.first;y3=t3.second;
        
    }
    
    void Postavi (const Tacka &t1,const Tacka &t2, const Tacka &t3) 
    
    { if (Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        x1=t1.first;y1=t1.second; x2=t2.first; y2=t2.second; x3=t3.first; y3=t3.second; // samo se poziva nad već postojećim objektom ?!
    }
    
    void Postavi (int indeks,const Tacka &t)
    {
        if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
        
        if (indeks==1) {x1=t.first; y1=t.second;}
        if (indeks==2) {x2=t.first;y2=t.second;}
        if (indeks==3) {x3=t.first;y3=t.second;} // msm da je ovo ok xd
        
    }

    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
       
        double izraz;
        izraz= Pomocna (t1.first,t1.second,t2.first,t2.second,t3.first,t3.second);
        
        if (izraz>0) return 1;
        if (izraz<0) return -1;
        if (izraz<E && izraz>Ep) return 0;
        
    }
    
    Tacka DajTjeme (int indeks) const 
    {
        Tacka t1,t2,t3;
        t1.first=x1; t1.second = y1;
        t2.first=x2; t2.second = y2;
        t3.first=x3; t3.second =y3;
        
        if (indeks==1) return t1;
        if (indeks ==2 ) return t2;
        if (indeks==3) return t3;  // hmmmm nisam sigurna
    }
  
    double DajStranicu (int indeks) const
    {
        // vraća dužinu stranice koja se nalazi nasuprot tjemena čiji je redni broj dat kao parametar
        
        if (indeks==1) {return (sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)));}
        if (indeks==2) {return(sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)));}
        if (indeks==3){return (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));}
    }
    
 

    double DajUgao (int indeks) const
    {
       double a,b,c;
        a=DajStranicu(1);
        b=DajStranicu(2);
        c=DajStranicu(3);
        
        double alfa,beta,gama;
        
        alfa= acos ((b*b+c*c-a*a)/(2*b*c));
        beta= acos ((a*a+c*c-b*b)/(2*a*c));
        gama= acos ((a*a+b*b-c*c)/(2*a*b));
        
        if (indeks==1) return alfa;
        if (indeks==2) return beta;
        if (indeks==3) return gama;
        
    }
    Tacka DajCentar () const
    {
        Tacka centar;
        double x,y;
        
        x=(x1+x2+x3)/3;
        y=(y1+y2+y3)/3;
        
        centar.first=x; centar.second=y;
        return centar;
    }
    
   
    double DajPovrsinu () const 
    {
        double Povrsina;
        Povrsina=Pomocna(this -> x1,this->y1,this->x2,this->y2,this->x3,this->y3)/2;
        return Povrsina;
    }
    double DajObim () const
    {
        double a,b,c;
        a=DajStranicu(1);
        b=DajStranicu(2);
        c=DajStranicu(3);
       
        return ((a+b+c)/3);
    }
    bool DaLiJePozitivnoOrijentiran () const
    {
    
       if (Orijentacija({x1,y1},{x2,y2},{x3,y3})==1) return true;
        
    }
    
    bool DaLiJeUnutra (const Tacka &t) const
    {
        
        if (Orijentacija({x1,y1},{x2,y2},{x3,y3})==1 && Orijentacija({x1,y1},{x2,y2},t)==1 && Orijentacija({x2,y2},{x3,y3},t)==1 && Orijentacija({x3,y3},{x1,y1},t)==1) return true;
        
        return false;
    }
    void Ispisi () const
{
    std::cout << "((" << x1 << "," <<y1<< "),(" << x2 << "," << y2 << "),(" << x3<< "," << y3 << "))";
}
    void  Transliraj (double delta_x,double delta_y)
    {
        // vrši translaciju trougla za delta_x jedinica horizontalno i delta_y jedinica vertikalno
        x1+=delta_x; 
        y1+=delta_y;
        x2+=delta_x; y2+=delta_y;
        x3+=delta_x; y3+=delta_y;
    }
    
    void Centriraj (const Tacka &t)
    {
        // da se nakon nje centar trougla nađe u tački koja je zadana kao parametar
        
        double delta_x;
        double delta_y;
        Tacka Centar = DajCentar();
        delta_x= t.first-Centar.first;
        delta_y=t.second- Centar.second;
        
        Transliraj(delta_x,delta_y);
    }
    
    void Rotiraj (const Tacka &t,double ugao) 
    {
        // pretvori ugao u radijane
        ugao*=pi/180;
        
        double x1r,x2r,x3r,y1r,y2r,y3r;
        double xc,yc;
        xc=t.first; yc=t.second;
        x1= (xc+(x1-xc)*cos(ugao)-(y1-yc)*sin(ugao));
        y1= (yc+(x1-xc)*sin(ugao)+(y1-yc)*cos(ugao));
        x2= (xc+(x2-xc)*cos(ugao)-(y2-yc)*sin(ugao));
        x3= (xc+(x3-xc)*cos(ugao)-(y3-yc)*sin(ugao));
        y2= (yc+(x2-xc)*sin(ugao)+(y2-yc)*cos(ugao));
        y3= (yc+(x3-xc)*sin(ugao)+(y3-yc)*cos(ugao));
        
    }
    
    void Skaliraj (const Tacka &t,double faktor)
    {
        if (faktor<E && faktor>Ep) throw std::domain_error ("Nekorektan faktor skaliranja");
       
        double xc,yc;
        xc=t.first;yc=t.second;
        
        x1=(xc+faktor*(x1-xc));
        y1=(yc+faktor*(y1-yc));
        x2=(xc+faktor*(x2-xc));
        x3=(xc+faktor*(x3-xc));
        y2=(yc+faktor*(y2-yc));
        y3=(yc+faktor*(y3-yc));
       
       if (faktor<0)
       {
           Rotiraj(t,180);
       }
    }
    void Rotiraj (double ugao)
    {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj (double faktor)
    {
        Skaliraj(DajCentar(),faktor);
    }
    
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
     friend bool DaLiSuPodudarni (const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1,const Trougao &t2);

};

bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2)
{
 std::vector<std::pair<double,double>> tjemena (Trougao::DajTjemena(t1));
 std::vector <std::pair<double,double>> tjeme(Trougao::DajTjemena(t2));
  bool isti(true);
  for (int i=0;i<3;i++)
  {
      for (int j=0;j<3;j++)
      {isti=true;
      if (tjeme[i].first-tjemena[j].first<E && tjeme[i].second-tjemena[j].second<E) break;
      else isti=false;
          
      }
      if (!isti) break;
  }   // PROVJERITI U DEBUGGERU !!!!!!
 
 if (isti) return true;
else return false;
}

bool DaLiSuPodudarni (const Trougao &t1,const Trougao &t2)
{
    double a,b,c,a1,b1,c1;
    a=t1.DajStranicu(1);
    b=t1.DajStranicu(2);
    c=t1.DajStranicu(3);
    
    a1=t2.DajStranicu(1);
    b1=t2.DajStranicu(2);
    c1=t2.DajStranicu(3);
    
    double alfa,beta,gama,alfa1,beta1,gama1;
    
    alfa=t1.DajUgao(1);
    beta=t1.DajUgao(2);
    gama=t1.DajUgao(3);
    
    alfa1=t2.DajUgao(1);
    beta1=t2.DajUgao(2);
    gama1=t2.DajUgao(3);
    bool SUS (false);
    bool USU (false);
    bool SSS (false);
    bool SSU (false);
   
    //if ((fabs(a-a1)<E && fabs(b-b1)<E && fabs(gama-gama1)<E) || (fabs (b-b1)<E && (c-c1)<E && (alfa-alfa1)<E) || (fabs (c-c1)<E && fabs (a-a1)<E && (beta-beta1)<E)) SUS=true;
   // if ((fabs (alfa-alfa1)<E && fabs (beta-beta1)<E && fabs (c-c1)<E) || (fabs (beta-beta1)<E && fabs (gama-gama1)<E && (a-a1)<E) || (fabs(alfa-alfa1)<E && fabs (gama-gama1)<E && (b-b1)<E)) USU=true;
    if (fabs (a-a1)<E && fabs (b-b1)<E && fabs(c-c1)<E) SSS=true;
    if (SSS==true) return true;
}

bool DaLiSuSlicni (const Trougao &t1,const Trougao &t2)
{
    
    double a,b,c,a1,b1,c1;
    a=t1.DajStranicu(1);b=t1.DajStranicu(2);c=t1.DajStranicu(3);
    a1=t2.DajStranicu(1);b1=t2.DajStranicu(2);c1=t2.DajStranicu(3);
    
    double alfa,beta,gama,alfa1,beta1,gama1;
    alfa=t1.DajUgao(1);alfa1=t2.DajUgao(1);
    beta=t1.DajUgao(2);beta1=t2.DajUgao(2);
    gama=t1.DajUgao(3);gama1=t2.DajUgao(3);
    bool SUS (false); bool USU (false); bool SSS (false); bool SSU (false);
    
//if((fabs((a/a1)-(b/b1))<E && fabs(gama-gama1)<E) || (fabs((b/b1)-(c/c1))<E && fabs(alfa-alfa1)<E) || (fabs((a/a1)-(c/c1))<E && (beta-beta1)<E)) SUS=true;
if (fabs ((a/a1)-(b/b1)) < E && fabs((a/a1)-(c/c1))<E && fabs ((b/b1)-(c/c1))<E) SSS = true;
// UUU 
// SSU
if (SSS==true) return true;
}

int main ()
{
    int n;
    
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    
    std::vector<std::shared_ptr<Trougao>> pokazivaci ;
    std::vector<std::pair<double,double>> vektor(n);
    
    
    
    
    for (int i=0;i<n;i++)
    { std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1,t2,t3;
        double x1,x2,x3,y1,y2,y3;
        
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        t1.first=x1; t1.second=y1;
        t2.first=x2; t2.second=y2;
        t3.first=x3; t3.second=y3;
    
       try
       {
           std::shared_ptr<Trougao> pokazivac;
        pokazivac=std::make_shared<Trougao>(t1,t2,t3);
        pokazivaci.push_back(pokazivac);  // da li je ovo ispravno ?
     
      }
      catch (std::domain_error izuzetak)
      {
      
      std::cout << "Nekorektne pozicije tjemena, ponovite unos!"<< std::endl;
      i--;
      std::cin.ignore(1000,'\n');
      continue;
      }
    }
    
       std::cout << "Unesite vektor translacije (dx dy): ";
       double delta_x,delta_y,ugao;
       std::cin >> delta_x >> delta_y;
       std::cout << "Unesite ugao rotacije: ";
       std::cin >> ugao;
       double faktor;
       std::cout << "Unesite faktor skaliranja: ";
       std::cin>> faktor;
       
       std::cout << "Trouglovi nakon obavljeninh transformacija: " << std::endl;
       
   std::transform (pokazivaci.begin(),pokazivaci.end(),pokazivaci.begin(),[&](std::shared_ptr<Trougao> T){T->Transliraj(delta_x,delta_y); return T;});
   std::transform (pokazivaci.begin(),pokazivaci.end(),pokazivaci.begin(),[&](std::shared_ptr<Trougao> T) {Tacka t; t=T->DajCentar(); T->Rotiraj(t,ugao); return T;});
   std::transform (pokazivaci.begin(),pokazivaci.end(),pokazivaci.begin(),[&](std::shared_ptr<Trougao> T) { Tacka t; t=T->DajTjeme(1); T->Skaliraj(t,faktor);return T;});
   std::for_each (pokazivaci.begin(),pokazivaci.end(),[](std::shared_ptr<Trougao> T){T->Ispisi();std::cout << std::endl;});
   std::sort      (pokazivaci.begin(),pokazivaci.end(),[&](std::shared_ptr<Trougao> T,std::shared_ptr<Trougao> T1) {return T->DajPovrsinu()<T1->DajPovrsinu();});
   Tacka t1,t2,t3;
  
   t1=(*std::min_element (pokazivaci.begin(),pokazivaci.end(),[&](std::shared_ptr<Trougao>T1,std::shared_ptr<Trougao> T2){return T1->DajObim()<T2->DajObim();}))->DajTjeme(1);
   t2=(*std::min_element(pokazivaci.begin(),pokazivaci.end(),[&](std::shared_ptr<Trougao>T1,std::shared_ptr<Trougao>T2){return T1->DajObim()<T2->DajObim();}))->DajTjeme(2);
   t3=(*std::min_element(pokazivaci.begin(),pokazivaci.end(),[&](std::shared_ptr<Trougao>T1,std::shared_ptr<Trougao>T2){return T1->DajObim()<T2->DajObim();}))->DajTjeme(3);
   
 std::cout << "Trougao sa najmanjim obimom: ";
 std::cout << "(("<<t1.first<<","<<t1.second<<"),";
   std::cout << "("<<t2.first<<","<<t2.second << "),";
   std::cout << "("<<t3.first<<","<<t3.second <<"))"<< std::endl;
    
    int brojac_1(0);
    
    
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (DaLiSuIdenticni(*pokazivaci[i],*pokazivaci[j]))
            {
                brojac_1++;
            }
        }
    }
    
    if (brojac_1==0) std::cout << "Nema identicnih trouglova!"<< std::endl;
    else {
        std::cout << "Parovi identicnih trouglova: "<<std::endl;
    for (int i=0;i<n-1;i++)
    { 
        for (int j=i+1;j<n;j++)
        { 
            if (DaLiSuIdenticni(*pokazivaci[i],*pokazivaci[j]))
            {   
                pokazivaci[i]->Ispisi(); 
                std::cout << " i ";
               pokazivaci[j]->Ispisi();
               std::cout << std::endl;
            }
        }
    }
    }
   
  
    
    int brojac_2(0);
for (int i=0;i<n-1;i++)
{
    for (int j=i+1;j<n;j++)
    {
        if (DaLiSuPodudarni(*pokazivaci[j],*pokazivaci[j])==true)
        {
            brojac_2++;
        }
    }
} if (brojac_2==0) std::cout << "Nema podudarnih trouglova!"<<std::endl;
else{

     std::cout << "Parovi podudarnih trouglova: "<<std::endl;
     
     for (int i=0;i<n-1;i++)
     {
         for (int j=i+1;j<n;j++)
         {
             if (DaLiSuPodudarni(*pokazivaci[i],*pokazivaci[j])==true)
             { 
                 pokazivaci[i]->Ispisi(); std::cout << " i " ; pokazivaci[j]->Ispisi();
                 std::cout << std::endl;
             }
         }
     }}
    
     int brojac_3(0);
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (DaLiSuSlicni(*pokazivaci[i],*pokazivaci[j])==true)
            {
                brojac_3++;
            }
        }
    } if (brojac_3==0) std::cout << "Nema slicnih trouglova!"<<std::endl;
    else{
     std::cout << "Parovi slicnih trouglova: "<< std::endl;
     
     for (int i=0;i<n-1;i++)
     {
         for (int j=i+1;j<n;j++)
         {
             if (DaLiSuSlicni(*pokazivaci[i],*pokazivaci[j])==true)
             { brojac_3++;
                 pokazivaci[i]->Ispisi();std::cout << " i "; pokazivaci[j]->Ispisi();
             std::cout << std::endl;}
         }
     }} 
    
    
    
    
   
    
    
	return 0;
}