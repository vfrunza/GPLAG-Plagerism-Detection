/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<stdexcept>
#include<utility>
#include<cmath>
#include<vector>
#include<memory>
#include <algorithm>

#define EPS 000000000.1
using namespace std ;

typedef pair<double, double> Tacka;
class Trougao{
    Tacka tacka1, tacka2, tacka3;
    static bool DaLiSuJednaki(double x,double y){
        if(fabs(x-y)<=EPS) return true;
        return false;
    }

    public:

Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(DaLiSuJednaki((t2.first-t1.first)/(t3.first-t1.first),(t2.second-t1.second)/(t3.second-t1.second))) throw domain_error("Nekorektne pozicije tjemena");
    Postavi(t1, t2, t3);
}

void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(DaLiSuJednaki((t2.first-t1.first)/(t3.first-t1.first),(t2.second-t1.second)/(t3.second-t1.second))) throw domain_error("Nekorektne pozicije tjemena");
    tacka1=t1; tacka2=t2; tacka3=t3;
}

void Postavi(int indeks, const Tacka &t){
if(indeks<0 || indeks>3) throw range_error ("Nekorektan indeks");
if(indeks==1) tacka1=t; if(indeks==2) tacka2=t; if(indeks==3) tacka3=t;
}

static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if((t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))-(t3.first*(t1.second-t2.second))>0) return 1; 
     if((t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))-(t3.first*(t1.second-t2.second))<0) return -1;
}

Tacka DajTjeme(int indeks) const { 
if(indeks<0 || indeks>3) throw range_error ("Nekorektan indeks");
if(indeks==1) return tacka1; if(indeks==2) return tacka2;  if(indeks==3) return tacka3;
}

double DajStranicu(int indeks) const;
double DajUgao(int indeks) const;
Tacka DajCentar() const{ Tacka pomocna;
pomocna.first=(tacka1.first+tacka2.first+tacka3.first)/3;
pomocna.second=(tacka1.second+tacka2.second+tacka3.second)/3;
return pomocna;
}
double DajObim() const{ return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
double DajPovrsinu() const{ double s(DajObim()/2);
return sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)));
}

bool DaLiJePozitivnoOrijentiran() const{
if((tacka1.first*(tacka2.second-tacka3.second))-(tacka2.first*(tacka1.second-tacka3.second))-(tacka3.first*(tacka1.second-tacka2.second))>0) return true; 
return false;
}

bool DaLiJeUnutra(const Tacka &t) const{
    if((Orijentacija(tacka1,tacka2,tacka3))==1 && Orijentacija(tacka1,tacka2,t)==1 && Orijentacija(tacka2,tacka3,t)==1 && Orijentacija(tacka3,tacka1,t)==1) 
    return true;
}
void Ispisi() const {
    cout<<"(("<<tacka1.first<<","<<tacka1.second<<") , ("<<tacka2.first<<","<<tacka2.second<<") , ("<<tacka3.second<<","<<tacka3.first<<"))";
}
void Transliraj(double delta_x, double delta_y);
void Centriraj(const Tacka &t);
void Rotiraj(const Tacka &t, double ugao);
void Skaliraj(const Tacka &t, double faktor);
void Rotiraj(double ugao){
Rotiraj(DajCentar(),ugao);
}
void Skaliraj(double faktor);
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        if(DaLiSuJednaki(t1.tacka1.first,t2.tacka1.first) && DaLiSuJednaki(t1.tacka1.second,t2.tacka1.second)){
        if(DaLiSuJednaki(t1.tacka2.first,t2.tacka2.first) && DaLiSuJednaki(t1.tacka2.second,t2.tacka2.second) && DaLiSuJednaki(t1.tacka3.first,t2.tacka3.first) && DaLiSuJednaki(t1.tacka3.second,t2.tacka3.second))
        return true;
        if(DaLiSuJednaki(t1.tacka2.first,t2.tacka3.first) && DaLiSuJednaki(t1.tacka2.second,t2.tacka3.second) && DaLiSuJednaki(t1.tacka3.first,t2.tacka2.first) && DaLiSuJednaki(t1.tacka3.second,t2.tacka2.second))
        return true;
        }
        
    if(DaLiSuJednaki(t1.tacka1.first,t2.tacka2.first) && DaLiSuJednaki(t1.tacka1.second,t2.tacka2.second)){
        if(DaLiSuJednaki(t1.tacka2.first,t2.tacka1.first) && DaLiSuJednaki(t1.tacka2.second,t2.tacka1.second) && DaLiSuJednaki(t1.tacka3.first,t2.tacka3.first) && DaLiSuJednaki(t1.tacka3.second,t2.tacka3.second))
        return true;
        if(DaLiSuJednaki(t1.tacka2.first,t2.tacka3.first) && DaLiSuJednaki(t1.tacka2.second,t2.tacka3.second) && DaLiSuJednaki(t1.tacka3.first,t2.tacka1.first) && DaLiSuJednaki(t1.tacka3.second,t2.tacka1.second))
        return true;
        }
    if(DaLiSuJednaki(t1.tacka1.first,t2.tacka3.first) && DaLiSuJednaki(t1.tacka1.second,t2.tacka3.second)){
        if(DaLiSuJednaki(t1.tacka2.first,t2.tacka1.first) && DaLiSuJednaki(t1.tacka2.second,t2.tacka1.second) && DaLiSuJednaki(t1.tacka3.first,t2.tacka2.first) && DaLiSuJednaki(t1.tacka3.second,t2.tacka2.second))
        return true;
        if(DaLiSuJednaki(t1.tacka2.first,t2.tacka2.first) && DaLiSuJednaki(t1.tacka2.second,t2.tacka2.second) && DaLiSuJednaki(t1.tacka3.first,t2.tacka1.first) && DaLiSuJednaki(t1.tacka3.second,t2.tacka1.second))
        return true;
        }
    return false;

}

friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if(DaLiSuJednaki(t1.DajStranicu(1),t2.DajStranicu(1)) && DaLiSuJednaki(t1.DajStranicu(2),t2.DajStranicu(2)) && DaLiSuJednaki(t1.DajStranicu(3),t2.DajStranicu(3))) return true;
    return false;
}
friend bool TrougaoDaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    
        if(DaLiSuJednaki((t1.DajStranicu(1)/t2.DajStranicu(1)),(t1.DajStranicu(2)/t2.DajStranicu(2))) && DaLiSuJednaki((t1.DajStranicu(3)/t2.DajStranicu(3)),(t1.DajStranicu(1)/t2.DajStranicu(1))) && DaLiSuJednaki((t1.DajStranicu(3)/t2.DajStranicu(3)),(t1.DajStranicu(2)/t2.DajStranicu(2))))
        return true;
        return false;
}
};

double Trougao::DajStranicu(int indeks) const{
    if(indeks<0 || indeks>3) throw range_error ("Nekorektan indeks");
    if(indeks==1) return (sqrt((tacka3.first-tacka2.first)*(tacka3.first-tacka2.first))+((tacka3.second-tacka2.second)*(tacka3.second-tacka2.second)));
    if(indeks==2) return (sqrt((tacka3.first-tacka1.first)*(tacka3.first-tacka1.first))+((tacka3.second-tacka1.second)*(tacka3.second-tacka1.second)));
    if(indeks==3) return (sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first))+((tacka2.second-tacka1.second)*(tacka2.second-tacka1.second)));
}
double Trougao::DajUgao(int indeks) const{
     if(indeks<0 || indeks>3) throw range_error ("Nekorektan indeks");
     if(indeks==1) return acos(((DajStranicu(2)*DajStranicu(2))+(DajStranicu(3)*DajStranicu(3))-(DajStranicu(1)*DajStranicu(1)))/(2*DajStranicu(2)*DajStranicu(3)));
     if(indeks==2) return acos(((DajStranicu(3)*DajStranicu(3))+(DajStranicu(1)*DajStranicu(1))-(DajStranicu(2)*DajStranicu(2)))/(2*DajStranicu(1)*DajStranicu(3)));
     if(indeks==3) return acos(((DajStranicu(1)*DajStranicu(1))+(DajStranicu(2)*DajStranicu(2))-(DajStranicu(3)*DajStranicu(3)))/(2*DajStranicu(1)*DajStranicu(2)));
}

void Trougao::Transliraj(double delta_x, double delta_y){
    tacka1.first+=delta_x;
    tacka2.first+=delta_x;
    tacka3.first+=delta_x;
    tacka1.second+=delta_y;
    tacka2.second+=delta_y;
    tacka3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    double Pomjeri_x, Pomjeri_y;
    Pomjeri_x=((3*t.first)/(tacka1.first+tacka2.first+tacka3.first));
    Pomjeri_y=((3*t.second)/(tacka1.second+tacka2.second+tacka3.second));
    Transliraj(Pomjeri_x,Pomjeri_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    tacka1.first=t.first+(tacka1.first-t.first)*cos(ugao)-(tacka1.second-t.second)*sin(ugao);
    tacka1.second=t.second+(tacka1.first-t.first)*sin(ugao)+(tacka1.second-t.second)*cos(ugao);
    
    tacka2.first=t.first+(tacka2.first-t.first)*cos(ugao)-(tacka2.second-t.second)*sin(ugao);
    tacka2.second=t.second+(tacka2.first-t.first)*sin(ugao)+(tacka2.second-t.second)*cos(ugao);
    
    tacka3.first=t.first+(tacka3.first-t.first)*cos(ugao)-(tacka3.second-t.second)*sin(ugao);
    tacka3.second=t.second+(tacka3.first-t.first)*sin(ugao)+(tacka3.second-t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    Tacka temp;
    temp.first=t.first;
    temp.second=t.second;
    if(fabs(faktor)<=EPS) throw domain_error ("Nekorektan faktor skaliranja");
    if(faktor>0){
    tacka1.first=temp.first+faktor*(tacka1.first-temp.first);
    tacka1.second=temp.second+faktor*(tacka1.second-temp.second);
    
    tacka2.first=temp.first+faktor*(tacka2.first-temp.first);
    tacka2.second=temp.second+faktor*(tacka2.second-temp.second);
    
    tacka3.first=temp.first+faktor*(tacka3.first-temp.first);
    tacka3.second=temp.second+faktor*(tacka3.second-temp.second);
    }
    else {
    tacka1.first=temp.first+faktor*(tacka1.first-temp.first);
    tacka1.second=temp.second+faktor*(tacka1.second-temp.second);
    
    tacka2.first=temp.first+faktor*(tacka2.first-temp.first);
    tacka2.second=temp.second+faktor*(tacka2.second-temp.second);
    
    tacka3.first=temp.first+faktor*(tacka3.first-temp.first);
    tacka3.second=temp.second+faktor*(tacka3.second-temp.second);
    Rotiraj(DajCentar(),4.*atan(1.));
    }
        
}

void Trougao::Skaliraj(double faktor){
   
    if(fabs(faktor)<=EPS) throw domain_error ("Nekorektan faktor skaliranja");
    if(faktor>0){
    Skaliraj(DajCentar(),faktor);
    }
    else {
    Skaliraj(DajCentar(),faktor);
    Rotiraj(DajCentar(),4.*atan(1.));
    }
}
bool DaLiSuJednaki(double x,double y){
        if(fabs(x-y)<=EPS) return true;
        return false;
    }
int main(){
  	try{
		cout<<"Koliko zelite kreirati trouglova: ";
		int n;
		cin>>n;
		vector<shared_ptr<Trougao>>v;
try{
		for(int i=0;i<n;i++){
			double x1(0),x2(0),x3(0);
			double y1(0),y2(0),y3(0);
			cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
			cin>>x1>>y1>>x2>>y2>>x3>>y3;
			Tacka t1=make_pair(x1,y1);
			Tacka t2=make_pair(x2,y2);
			Tacka t3=make_pair(x3,y3);
			try{
		if(DaLiSuJednaki((t2.first-t1.first)/(t3.first-t1.first),(t2.second-t1.second)/(t3.second-t1.second))) {throw domain_error("Nekorektne pozicije tjemena"); }
				v.emplace_back( make_shared<Trougao>(t1,t2,t3));
			}
		catch(domain_error e){
				cout<<e.what() << ", ponovite unos!" << endl;
				i--;
			}
		}
        
    }
    catch(domain_error e){
	cout<<e.what();
}
    vector<Tacka>vcentar;
   // int m(n-2);
		for(int i=0;i<n;i++){
			vcentar.emplace_back(v[i]->DajCentar());
		}
		cout<<"Unesite vektor translacije (dx dy): ";
		double delta_x(0);
		double delta_y(0);
		cin>>delta_x>>delta_y;
		for(int i=0;i<n;i++) v[i]->Transliraj(delta_x,delta_y);
		double ugao(0);
		cout<<"Unesite ugao rotacije: ";
		cin>>ugao;
		for(int i=0;i<n;i++) v[i]->Rotiraj(v[i]->DajCentar(),ugao);
		double faktor(0);
		cout<<"Unesite faktor skaliranja: ";
		cin>>faktor;
		for(int i=0;i<n;i++) v[i]->Skaliraj(v[i]->DajTjeme(1),faktor);
		sort(v.begin(),v.end(),[](shared_ptr<Trougao>p,shared_ptr<Trougao>q) {return p->DajPovrsinu() < q->DajPovrsinu();});
		cout<<"Trouglovi nakon obavljenih transformacija:\n";
		for(int i=0;i<n;i++){
			v[i]->Ispisi(); 
			cout<<endl;
		}
		cout<<"Trougao sa najmanjim obimom: ";
		auto min=min_element(v.begin(),v.end(),[](shared_ptr<Trougao>p,shared_ptr<Trougao>q) {return p->DajObim() < q->DajObim();  } );
		(*min)->Ispisi(); 
		cout<<endl;
		int identicni(0),podudarni(0),slicni(0);
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
			if(DaLiSuIdenticni(*v[i],*v[j])) {
			    identicni++;
			    
			}
			}
		}
		if(identicni==0) {
		    cout<<"Nema identicnih trouglova!\n";
		}
		if(identicni!=0){
			cout<<"Parovi identicnih trouglova:\n";
			for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;i++){
			if(DaLiSuIdenticni(*v[i],*v[j])) {  
			    v[i]->Ispisi();
			    cout<<" i ";
			    v[j]->Ispisi();
			}
			}
		}
		}
		
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
			if(DaLiSuPodudarni(*v[i],*v[j])) {
			    podudarni++;
			} 
			}
		}
		if(podudarni==0) {
		    cout<<"Nema podudarnih trouglova!\n";
		}
		if(podudarni!=0){
			cout<<"\nParovi podudarnih trouglova:\n";
			for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
			if(DaLiSuPodudarni(*v[i],*v[j])) {
			    v[i]->Ispisi();
			    cout<<" i "; 
			    v[j]->Ispisi();
			    cout<<endl;
			} 
			}
		}
			
		}
		
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
			if(DaLiSuPodudarni(*v[i],*v[j])) { 
			    slicni++; 
			} 
			}
		}
			if(slicni==0) {
			    cout<<"Nema slicnih trouglova!\n";
			}
		if(slicni!=0){
			cout<<"Parovi slicnih trouglova:\n";
				for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
			if(DaLiSuPodudarni(*v[i],*v[j])) { 
			    v[i]->Ispisi();
			    cout<<" i ";
			    v[j]->Ispisi();
			    cout<<endl;} 
			}
		}
		}
		}
		catch(bad_alloc){
			cout<<"Nazalost";
		}

//catch(domain_error e){
//	cout<<e.what();
//}
    return 0;
}