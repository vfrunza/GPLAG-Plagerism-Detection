#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <vector>
double eps=pow(10,-8);
const double pi=4*atan(1);
typedef std::pair<double,double> Tacka;

bool uporedi(double x,double y){
  if(abs(x-y)<eps) return true;
  return false;
}

class Trougao{
  Tacka tacka1,tacka2,tacka3;
  public:
  Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
      if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
          tacka1=t1; tacka2=t2; tacka3=t3;
  }
  void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
      if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
          tacka1=t1; tacka2=t2; tacka3=t3;
  }
  void Postavi(int indeks,const Tacka &t);
  static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3);
  Tacka DajTjeme(int indeks) const;
  double DajStranicu(int indeks) const;
  double DajUgao(int indeks) const;
  Tacka DajCentar() const;
  double DajObim() const;
  double DajPovrsinu() const;
  bool DaLiJePozitivnoOrijentiran() const;
  bool DaLiJeUnutra(const Tacka &t) const;
  void Ispisi() const;
  void Transliraj(double delta_x,double delta_y);
  void Centriraj(const Tacka &t);
  void Rotiraj(const Tacka &t,double ugao);
  void Skaliraj(const Tacka &t,double faktor);
  void Rotiraj(double ugao);
  void Skaliraj(double faktor);
  friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};

int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)>eps) return 1;
    else if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)<0) return -1;
    return 0;
}

void Trougao::Postavi(int indeks,const Tacka &t1){
  if(indeks!=1 && indeks!=2 && indeks !=3) throw std::range_error("Nekorektan indeks");
  if (indeks==1){
    try{
      Postavi(t1,tacka2,tacka3);
    }
    catch(...){
      throw;
    }
  }
  if (indeks==2){
    try{
      Postavi(tacka1,t1,tacka3);
    }
    catch(...){
      throw;
    }
  }
  if (indeks==3){
    try{
      Postavi(tacka1,tacka2,t1);
    }
    catch(...){
      throw;
    }
  }
}

Tacka Trougao::DajTjeme(int indeks) const {
  if(indeks!=1 && indeks!=2 && indeks !=3) throw std::range_error("Nekorektan indeks");
  if(indeks==1) return Trougao::tacka1;
  if(indeks==2) return Trougao::tacka2;
  return Trougao::tacka3;
}

double Trougao::DajStranicu(int indeks) const {
   if(indeks!=1 && indeks!=2 && indeks !=3) throw std::range_error("Nekorektan indeks");
   if(indeks==1) return sqrt((tacka3.first-tacka2.first)*(tacka3.first-tacka2.first)+(tacka3.second-tacka2.second)*(tacka3.second-tacka2.second));
   else if(indeks==2) return sqrt((tacka3.first-tacka1.first)*(tacka3.first-tacka1.first)+(tacka3.second-tacka1.second)*(tacka3.second-tacka1.second));
   else return sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));
}

double Trougao::DajUgao(int indeks) const {
   if(indeks!=1 && indeks!=2 && indeks !=3) throw std::range_error("Nekorektan indeks");
   if(indeks==1) return acos((tacka2.first*tacka3.first+tacka2.second*tacka3.second)/this->DajStranicu(2)*this->DajStranicu(3));
   else if(indeks==2) return acos((tacka1.first*tacka3.first+tacka1.second*tacka3.second)/this->DajStranicu(1)*this->DajStranicu(3));
   else return acos((tacka1.first*tacka2.first+tacka1.second*tacka2.second)/this->DajStranicu(1)*this->DajStranicu(2));
}

Tacka Trougao::DajCentar() const {
  double t1,t2;
  t1=(tacka1.first+tacka2.first+tacka3.first)/3;
  t2=(tacka1.second+tacka2.second+tacka3.second)/3;
  Tacka t=std::make_pair(t1,t2);
  return t;
}

double Trougao::DajObim() const{
  return (this->DajStranicu(1)+this->DajStranicu(2)+this->DajStranicu(3));
}

double Trougao::DajPovrsinu() const{
  double p=abs(tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-tacka2.second));
  return p/2;
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
  if(Orijentacija(tacka1,tacka2,tacka3)==1) return true;
  return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
  if(Orijentacija(this->tacka1,this->tacka2,this->tacka3)==Orijentacija(this->tacka1,this->tacka2,t)==Orijentacija(this->tacka2,this->tacka3,t)==Orijentacija(this->tacka3,this->tacka1,t)) return true;
  return false;
}

void Trougao::Ispisi() const{
  std::cout<<"(("<<tacka1.first<<","<<tacka1.second<<"),("<<tacka2.first<<","<<tacka2.second<<"),("<<tacka3.first<<","<<tacka3.second<<"))";
}

void Trougao::Transliraj(double delta_x,double delta_y){
  tacka1.first+=delta_x;
  tacka2.first+=delta_x;
  tacka3.first+=delta_x;
  tacka1.second+=delta_y;
  tacka2.second+=delta_y;
  tacka3.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t){
  Tacka nova=this->DajCentar();
  double x,y;
  if(t.first<nova.first) x=t.first-nova.first;
  if(t.first>nova.first) x=nova.first-t.first;
  if(t.second<nova.second) y=t.second-nova.second;
  if(t.second>nova.second) y=nova.second-t.second;
  this->Transliraj(x,y);
}

void Trougao::Rotiraj(const Tacka &t,double ugao){
  tacka1.first=t.first+(tacka1.first-t.first)*cos(ugao)-(tacka1.second-t.second)*sin(ugao);
  tacka2.first=t.first+(tacka2.first-t.first)*cos(ugao)-(tacka2.second-t.second)*sin(ugao);
  tacka3.first=t.first+(tacka3.first-t.first)*cos(ugao)-(tacka3.second-t.second)*sin(ugao);
  tacka1.second=t.second+(tacka1.first-t.first)*cos(ugao)-(tacka1.second-t.second)*sin(ugao);
  tacka2.second=t.second+(tacka2.first-t.first)*cos(ugao)-(tacka2.second-t.second)*sin(ugao);
  tacka3.second=t.second+(tacka3.first-t.first)*cos(ugao)-(tacka3.second-t.second)*sin(ugao);
}

void Trougao::Skaliraj(const Tacka &t,double faktor){
  if(abs(faktor)<eps) throw std::domain_error("Nekorektan faktor skaliranja");
  double k=abs(faktor);
  tacka1.first=t.first+k*(tacka1.first-t.first);
  tacka2.first=t.first+k*(tacka2.first-t.first);
  tacka3.first=t.first+k*(tacka3.first-t.first);
  tacka1.second=t.second+k*(tacka1.second-t.second);
  tacka2.second=t.second+k*(tacka2.second-t.second);
  tacka3.second=t.second+k*(tacka3.second-t.second);
  if(faktor<0) this->Rotiraj(t,pi);
}

void Trougao::Rotiraj(double ugao){
  Tacka t=this->DajCentar();
  tacka1.first=t.first+(tacka1.first-t.first)*cos(ugao)-(tacka1.second-t.second)*sin(ugao);
  tacka2.first=t.first+(tacka2.first-t.first)*cos(ugao)-(tacka2.second-t.second)*sin(ugao);
  tacka3.first=t.first+(tacka3.first-t.first)*cos(ugao)-(tacka3.second-t.second)*sin(ugao);
  tacka1.second=t.second+(tacka1.first-t.first)*cos(ugao)-(tacka1.second-t.second)*sin(ugao);
  tacka2.second=t.second+(tacka2.first-t.first)*cos(ugao)-(tacka2.second-t.second)*sin(ugao);
  tacka3.second=t.second+(tacka3.first-t.first)*cos(ugao)-(tacka3.second-t.second)*sin(ugao);
}

void Trougao::Skaliraj(double faktor){
  if(abs(faktor)<eps) throw std::domain_error("Nekorektan faktor skaliranja");
  Tacka t=this->DajCentar();
  double k=abs(faktor);
  tacka1.first=t.first+k*(tacka1.first-t.first);
  tacka2.first=t.first+k*(tacka2.first-t.first);
  tacka3.first=t.first+k*(tacka3.first-t.first);
  tacka1.second=t.second+k*(tacka1.second-t.second);
  tacka2.second=t.second+k*(tacka2.second-t.second);
  tacka3.second=t.second+k*(tacka3.second-t.second);
  if(faktor<0) this->Rotiraj(t,pi);
}

bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
  if((t1.tacka1==t2.tacka1 || t1.tacka1==t2.tacka2 || t1.tacka1==t2.tacka3) && (t1.tacka2==t2.tacka1 || t1.tacka2==t2.tacka2 || t1.tacka2==t2.tacka3) && (t1.tacka3==t2.tacka1 || t1.tacka3==t2.tacka2 || t1.tacka3==t2.tacka3)) return true;
  return false;
}

bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
  if((uporedi(t1.DajStranicu(1),t2.DajStranicu(1)) || uporedi(t1.DajStranicu(1),t2.DajStranicu(2)) || uporedi(t1.DajStranicu(1),t2.DajStranicu(3))) && (uporedi(t1.DajStranicu(2),t2.DajStranicu(1)) || uporedi(t1.DajStranicu(2),t2.DajStranicu(2)) || uporedi(t1.DajStranicu(2),t2.DajStranicu(3))) && (uporedi(t1.DajStranicu(3),t2.DajStranicu(1)) || uporedi(t1.DajStranicu(3),t2.DajStranicu(2)) || uporedi(t1.DajStranicu(3),t2.DajStranicu(3))) &&
  (uporedi(t1.DajUgao(1),t2.DajUgao(1)) || uporedi(t1.DajUgao(1),t2.DajUgao(2)) || uporedi(t1.DajUgao(1),t2.DajUgao(3))) && (uporedi(t1.DajUgao(2),t2.DajUgao(1)) || uporedi(t1.DajUgao(2),t2.DajUgao(2)) || uporedi(t1.DajUgao(2),t2.DajUgao(3))) && (uporedi(t1.DajUgao(3),t2.DajUgao(1)) || uporedi(t1.DajUgao(3),t2.DajUgao(2)) || uporedi(t1.DajUgao(3),t2.DajUgao(3)))) return true;
  return false;
}

bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
  if((uporedi(t1.DajUgao(1),t2.DajUgao(1)) || uporedi(t1.DajUgao(1),t2.DajUgao(2)) || uporedi(t1.DajUgao(1),t2.DajUgao(3))) && (uporedi(t1.DajUgao(2),t2.DajUgao(1)) || uporedi(t1.DajUgao(2),t2.DajUgao(2)) || uporedi(t1.DajUgao(2),t2.DajUgao(3))) && (uporedi(t1.DajUgao(3),t2.DajUgao(1)) || uporedi(t1.DajUgao(3),t2.DajUgao(2)) || uporedi(t1.DajUgao(3),t2.DajUgao(3)))) return true;
  return false;
}



int main ()
{
	try{
	  int n;
	Tacka t[3];
	std::cin>>n;
	std::vector<std::shared_ptr<Trougao>> trokuti(n,nullptr);
	for(int i=0;i<n;i++){
	  for(int j=0;j<3;j++){
	    double prva,druga;
	    std::cin>>prva>>druga;
	    t[j]=std::make_pair(prva,druga);
	  }
	  try{
	    trokuti[i]=std::make_shared<Trougao>(t[0],t[1],t[2]);
	  }
	  catch(std::domain_error e){
	    std::cout<<e.what();
	    i--;
	  }
	}
	std::transform(trokuti.begin(),trokuti.end(),trokuti.begin(),[](std::shared_ptr<Trougao> trokut) {
	  double dx,dy;
	  std::cin>>dx>>dy;
	  trokut->Transliraj(dx,dy);
	  double ugao;
	  std::cin>>ugao;
	  trokut->Rotiraj(ugao);
	  double faktor;
	  std::cin>>faktor;
	  trokut->Skaliraj(trokut->DajTjeme(1),faktor);
	  return trokut;
	  
	});
	std::sort(trokuti.begin(),trokuti.end(),[](std::shared_ptr<Trougao> trokut1,std::shared_ptr<Trougao> trokut2) {
	  return trokut1->DajPovrsinu()<trokut2->DajPovrsinu();
	});
	
	std::for_each(trokuti.begin(),trokuti.end(),[](std::shared_ptr<Trougao> trokut){
	  trokut->Ispisi();
	  std::cout<<std::endl;
	});
	
	
	auto pok=*std::min_element(trokuti.begin(),trokuti.end(),[] (std::shared_ptr<Trougao> trokut1,std::shared_ptr<Trougao> trokut2) {
	  return trokut1->DajObim()<trokut2->DajObim();
	});
	pok->Ispisi();
	std::vector<std::pair<Trougao,Trougao>> slicni;
	std::vector<std::pair<Trougao,Trougao>> identicni;
	std::vector<std::pair<Trougao,Trougao>> podudarni;
	for(int i=0;i<n;i++){
	  for(int j=i+1;j<n;j++){
	    if(DaLiSuIdenticni(*trokuti[i],*trokuti[j])) identicni.push_back(std::make_pair(*trokuti[i],*trokuti[j]));
	    if(DaLiSuSlicni(*trokuti[i],*trokuti[j])) slicni.push_back(std::make_pair(*trokuti[i],*trokuti[j]));
	    if(DaLiSuPodudarni(*trokuti[i],*trokuti[j])) podudarni.push_back(std::make_pair(*trokuti[i],*trokuti[j]));
	  }
	}
	}
	catch(...){
	  
	}
	
	
	
	
	
	
	
	return 0;
}