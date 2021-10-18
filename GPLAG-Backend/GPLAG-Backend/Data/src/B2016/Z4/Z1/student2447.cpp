#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <new>
#include <memory>


typedef std::pair<double,double> Tacka;
const double Eps=1e-10;

class Trougao{
  Tacka tjemena[3];
  static bool JesuLiJednaki(double x,double y,double Eps=1e-10){
    return (std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y)));
  }

  public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    void Postavi(int indeks,const Tacka &t);
    
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
      double vrijednost;
      int pozitivna(1);
      int negativna(-1);
      
      vrijednost=(t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))+(t3.first*(t1.second-t2.second));
      
      if(vrijednost>0){
        return pozitivna;
      }
      else return negativna;
    };
    
    Tacka DajTjeme(int indeks) const ;
    double DajStranicu(int indeks) const ;
    double DajUgao(int indeks) const ;
    Tacka DajCentar() const ;
    double DajObim() const;
    double DajPovrsinu()const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t1) const ;
    void Ispisi() const;
    void Transliraj(double delta_x,double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t,double ugao);
    void Skaliraj(const Tacka &t,double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
      int brojac1(0);
      int brojac2(0);
      
      for(int i=0;i<3;i++){
        if(t1.tjemena[i].first==t2.tjemena[0].first || t1.tjemena[i].first==t2.tjemena[1].first || t1.tjemena[i].first==t2.tjemena[2].first){
          brojac1++;
        }
        if(t1.tjemena[i].second==t2.tjemena[0].second || t1.tjemena[i].second==t2.tjemena[1].second || t1.tjemena[i].second==t2.tjemena[2].second){
          brojac2++;
        }
      }
      if(brojac1==3 && brojac2==3) return true;
        return false;
    };
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};

Trougao::Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
  if(t1==t2 || t1==t3 || t2==t3) throw std::domain_error("Nekorektne pozicije tjemena");
  else Postavi(t1,t2,t3);}

void Trougao::Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    tjemena[0]=t1;
    tjemena[1]=t2;
    tjemena[2]=t3;
}

void Trougao::Postavi(int indeks,const Tacka &t){
  if(indeks==1 || indeks==2 || indeks==3){
    tjemena[indeks]=t;
  }else{
    throw std::range_error("Nekorektan indeks");
  }
}

Tacka Trougao::DajTjeme(int indeks)const{
  if(indeks==1 || indeks==2 || indeks==3){
  return tjemena[indeks];
  }else{
    throw std::range_error("Nekorektan indeks");
  }
  
}

double DajDuzinuDuzi(const Tacka &t1,const Tacka &t2){
  double prva=t1.first-t2.first;
  double druga=t1.second-t2.second;
  double kvadrat_prvog=std::pow(prva,2);
  double kvadrat_drugog=std::pow(druga,2);
  double d;
  return d=sqrt(kvadrat_prvog+kvadrat_drugog);
  }

double Trougao::DajStranicu(int indeks)const{
  int duzina(0);
  if(indeks==1 || indeks==2 || indeks==3){
    if(indeks==1){
      duzina=DajDuzinuDuzi(tjemena[1],tjemena[2]);
      
    }else if(indeks==2){
      duzina=DajDuzinuDuzi(tjemena[0],tjemena[2]);
      
    }else if(indeks==3){
      duzina=DajDuzinuDuzi(tjemena[0],tjemena[1]);
      
    }
    
  }else{
    throw std::range_error("Nekorektan indeks");
  }
  return duzina;
}

double Trougao::DajUgao(int indeks)const{
  double duzinaC(0);
  double duzinaB(0);
  double duzinaA(0);
  double ugao(0);
  
  if(indeks==1 || indeks==2 || indeks==3){
   
      duzinaC=DajDuzinuDuzi(tjemena[0],tjemena[1]);
      duzinaB=DajDuzinuDuzi(tjemena[0],tjemena[2]);
      duzinaA=DajDuzinuDuzi(tjemena[1],tjemena[2]);
      
      if(indeks==1){
      ugao=std::cos((std::pow(duzinaC,2)+std::pow(duzinaB,2)-std::pow(duzinaA,2))/2*duzinaC*duzinaB);
      
    }else if(indeks==2){
      ugao=std::cos((std::pow(duzinaA,2)+std::pow(duzinaC,2)-std::pow(duzinaB,2))/2*duzinaA*duzinaC);
      
    }else if(indeks==3){
      ugao=std::cos((std::pow(duzinaA,2)+std::pow(duzinaB,2)-std::pow(duzinaC,2))/2*duzinaA*duzinaB);
      
    }
    
  }else {
    throw std::range_error("Nekorektan indeks");
  }
  return ugao;
}

Tacka Trougao::DajCentar()const{
  double xc(0);
  double yc(0);
  
  xc=(tjemena[0].first+tjemena[1].first+tjemena[2].first)/3;
  yc=(tjemena[0].second+tjemena[1].second+tjemena[2].second)/3;
  
  Tacka Centar(xc,yc);
  return Centar;
  
}

double Trougao::DajObim()const{
  double duzinaA=DajDuzinuDuzi(tjemena[1],tjemena[2]);
  double duzinaB=DajDuzinuDuzi(tjemena[0],tjemena[2]);
  double duzinaC=DajDuzinuDuzi(tjemena[0],tjemena[1]);
  double obim=duzinaA+duzinaB+duzinaC;
  return obim;
}

double Trougao::DajPovrsinu()const{
  double povrsina(0);
  povrsina=1/2*std::abs((tjemena[0].first*(tjemena[1].second-tjemena[2].second)-tjemena[1].first*(tjemena[0].second-tjemena[2].second)+tjemena[2].first*(tjemena[0].second-tjemena[1].second)));
  return povrsina;
}


bool Trougao::DaLiJePozitivnoOrijentiran()const{
  if(Orijentacija(tjemena[0],tjemena[1],tjemena[2])>0) return true;
  return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t)const{
  int broj(Orijentacija(tjemena[0],tjemena[1],tjemena[2]));
  if(Orijentacija(tjemena[0],tjemena[1],t)!=broj || Orijentacija(tjemena[1],tjemena[2],t)!=broj || Orijentacija(tjemena[2],tjemena[0],t)!=broj)return false;
  return true;
}

void Trougao::Ispisi()const {
  std::cout<<"(("<<DajTjeme(1).first<<","<<DajTjeme(1).second<<"),("<<DajTjeme(2).first<<","<<DajTjeme(2).second<<"),("<<DajTjeme(3).first<<","<<DajTjeme(3).second<<"))";
}

void Trougao::Transliraj(double delta_x,double delta_y){
  tjemena[0].first+=delta_x;
  tjemena[0].second+=delta_y;
  tjemena[1].first+=delta_x;
  tjemena[1].second+=delta_y;
  tjemena[2].first+=delta_x;
  tjemena[2].second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t){
  double prvi_x(t.first-DajCentar().first),drugi_y(t.second-DajCentar().second);
  Transliraj(prvi_x,drugi_y);
}

void Trougao::Rotiraj(const Tacka &t,double ugao){
  double tacka1_x(0);
  double tacka2_x(0);
  double tacka3_x(0);
  double tacka1_y(0);
  double tacka2_y(0);
  double tacka3_y(0);
  
  tacka1_x=(t.first+(tjemena[0].first-t.first)*std::cos(ugao)-(tjemena[0].second-t.second)*std::sin(ugao));
  tacka2_x=(t.first+(tjemena[1].first-t.first)*std::cos(ugao)-(tjemena[1].second-t.second)*std::sin(ugao));
  tacka3_x=(t.first+(tjemena[2].first-t.first)*std::cos(ugao)-(tjemena[2].second-t.second)*std::sin(ugao));
  
  tacka1_y=(t.second+(tjemena[0].first-t.first)*std::sin(ugao)+(tjemena[0].second-t.second)*std::cos(ugao));
  tacka2_y=(t.second+(tjemena[1].first-t.first)*std::sin(ugao)+(tjemena[1].second-t.second)*std::cos(ugao));
  tacka3_y=(t.second+(tjemena[2].first-t.first)*std::sin(ugao)+(tjemena[2].second-t.second)*std::cos(ugao));
}

void Trougao::Skaliraj(const Tacka &t,double faktor){
  if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
  double tacka1_x,tacka2_x,tacka3_x;
  double tacka1_y,tacka2_y,tacka3_y;
  
  tacka1_x=(t.first+faktor*(tjemena[0].first-t.first));
  tacka2_x=(t.first+faktor*(tjemena[1].first-t.first));
  tacka3_x=(t.first+faktor*(tjemena[2].first-t.first));
  
  tacka1_y=(t.second+faktor*(tjemena[0].second-t.second));
  tacka2_y=(t.second+faktor*(tjemena[1].second-t.second));
  tacka3_y=(t.second+faktor*(tjemena[2].second-t.second));
  
}

void Trougao::Rotiraj(double ugao){
  double tacka1_x,tacka2_x,tacka3_x;
  double tacka1_y,tacka2_y,tacka3_y;
  
  Tacka NekaTacka;
  NekaTacka=DajCentar();
  
  tacka1_x=(NekaTacka.first+(tjemena[0].first-NekaTacka.first)*std::cos(ugao)-(tjemena[0].second-NekaTacka.second)*std::sin(ugao));
  tacka2_x=(NekaTacka.first+(tjemena[1].first-NekaTacka.first)*std::cos(ugao)-(tjemena[1].second-NekaTacka.second)*std::sin(ugao));
  tacka3_x=(NekaTacka.first+(tjemena[2].first-NekaTacka.first)*std::cos(ugao)-(tjemena[2].second-NekaTacka.second)*std::sin(ugao));
  
  tacka1_y=(NekaTacka.second+(tjemena[0].first-NekaTacka.first)*std::sin(ugao)+(tjemena[0].second-NekaTacka.second)*std::cos(ugao));
  tacka2_y=(NekaTacka.second+(tjemena[1].first-NekaTacka.first)*std::sin(ugao)+(tjemena[1].second-NekaTacka.second)*std::cos(ugao));
  tacka3_y=(NekaTacka.second+(tjemena[2].first-NekaTacka.first)*std::sin(ugao)+(tjemena[2].second-NekaTacka.second)*std::cos(ugao));
  
 
  
}

void Trougao::Skaliraj(double faktor){
  if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
  
  double tacka1_x,tacka2_x,tacka3_x;
  double tacka1_y,tacka2_y,tacka3_y;
  
  Tacka NekaTacka;
  NekaTacka=DajCentar();
  
  tacka1_x=(NekaTacka.first+faktor*(tjemena[0].first-NekaTacka.first));
  tacka2_x=(NekaTacka.first+faktor*(tjemena[1].first-NekaTacka.first));
  tacka3_x=(NekaTacka.first+faktor*(tjemena[2].first-NekaTacka.first));
  
  tacka1_y=(NekaTacka.second+faktor*(tjemena[0].second-NekaTacka.second));
  tacka2_y=(NekaTacka.second+faktor*(tjemena[1].second-NekaTacka.second));
  tacka3_y=(NekaTacka.second+faktor*(tjemena[2].second-NekaTacka.second));
}



int main ()
{
  Trougao trougao({0, 0}, {3,1}, {2,5});
std::cout << "Obim trougla iznosi: " << trougao.DajObim()
          << "\nPovrsina trougla iznosi: " << trougao.DajPovrsinu();
  
  
	return 0;
}