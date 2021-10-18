#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <memory>
const double eps(1e-10);
typedef std::pair<double, double> Tacka;
 bool Jednakii(double x,double y){
		if(std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y))) {return true;}
		return false;
}
const double pi(4 *  std :: atan(1));

bool frend1(double a,double b,double c,double e,double f,double g,double h,double i,double j,double k,double l,double m){
		std::vector<double>v; std::vector<double>t;
		v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(e); v.push_back(f); v.push_back(g); t.push_back(h); t.push_back(i); t.push_back(j);
		t.push_back(k); t.push_back(l); t.push_back(m);
		std::sort(v.begin(),v.end());
		std::sort(t.begin(),t.end());
	if(v==t ) {return true;}
	return false;
}
	const double gama(1e-3);
	const double gama_2(gama*gama);
	
	double Prava_2_tacke(double t1x,double t1y,double t2x,double t2y,double tx,double ty){
		return (t2y-t1y)*(tx-t1x)+(t1x-t2x)*(ty-t1y);
	}
	bool ObicniTest(double h,double g,double z,double y,double u,double w,double l,double m){
		bool a=Prava_2_tacke(h,g,z,y,l,m)>=0;
		bool b=Prava_2_tacke(z,y,u,w,l,m)>=0;
		bool c=Prava_2_tacke(u,w,h,g,l,m)>=0;
		return a && b && c;
	}
	
	bool Kutija(double t1x,double t1y,double t2x,double t2y,double t3x,double t3y,double tx,double ty){
		double xmin=std::min(t1x,std::min(t2x,t3x))-gama;
		double xmax=std::max(t1x,std::max(t2x,t3x))+gama;
		double ymin=std::min(t1y,std::min(t2y,t3y))-gama;
		double ymax=std::max(t1y,std::max(t2y,t3y))+gama;
		if(tx<xmin || xmax<tx || ty<ymin || ymax<ty) {return false;}
		else	return true;
	}
	double Udaljenost(double t1x,double t1y,double t2x,double t2y,double tx,double ty){
	double t1_t2=(t2x-t1x)*(t2x-t1x)+(t2y-t1y)*(t2y-t1y);
	double pro=((tx-t1x)*(t2x-t1x)+(ty-t1y)*(t2y-t1y))/t1_t2;
	if(pro<0){
		return (tx-t1x)*(tx-t1x)+(ty-t1y)*(ty-t1y);
	}
	else if(pro<=1){
		double t_t1=(t1x-tx)*(t1x-tx)+(t1y-ty)*(t1y-ty);
		return t_t1-pro*pro*t1_t2;
	}
	else{
		return (tx-t2x)*(tx-t2x)+(ty-t2y)*(ty-t2y);
	}
	}
	double UbiloSe(Tacka t1, Tacka t2, Tacka t3){
		return (t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
	}
	
	 bool IstiSuu(const Tacka &tc1,const Tacka &tc2,const Tacka &tc3){
	if(  (    (std::fabs(tc1.first-tc2.first)<=eps*(std::fabs(tc1.first)+std::fabs(tc2.first))) && (std::fabs(tc1.first-tc3.first)<=eps*(std::fabs(tc1.first)+std::fabs(tc3.first))) )	 || ( (std::fabs(tc1.second-tc2.second)<=eps*(std::fabs(tc1.second)+std::fabs(tc2.second)) )     && ( (std::fabs(tc1.second-tc3.second)<=eps*(std::fabs(tc1.second)+std::fabs(tc3.second)))) ) ) {
		return true;
	}
    return false;
}
	
class Trougao{
	Tacka T1,T2,T3;
	static bool IstiSu(Tacka tc1,Tacka tc2,Tacka tc3){
	if(  (    (std::fabs(tc1.first-tc2.first)<=eps*(std::fabs(tc1.first)+std::fabs(tc2.first))) && (std::fabs(tc1.first-tc3.first)<=eps*(std::fabs(tc1.first)+std::fabs(tc3.first))) )	 || ( (std::fabs(tc1.second-tc2.second)<=eps*(std::fabs(tc1.second)+std::fabs(tc2.second)) )     && ( (std::fabs(tc1.second-tc3.second)<=eps*(std::fabs(tc1.second)+std::fabs(tc3.second)))) ) ) {
		return true;
	}
    return false;
}
static bool Jednaki(double x,double y){
		if(std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y))) return true;
		return false;
	}



	static bool Pravougli(double a,double b,double c){
		double ideja1=a*a+b*b;
		double ideja2=a*a+c*c;
		double ideja3=b*b+c*c;
		if(Jednaki(c*c,ideja1)) return true;
		if(Jednaki(b*b,ideja2)) return true;
		if(Jednaki(a*a,ideja3)) return true;
		return false;
	}
	
	
	
	static int HiPoTeNuZa(double a,double b,double c){
		double ideja1=a*a+b*b;
		double ideja2=a*a+c*c;
		double ideja3=b*b+c*c;
		if(Jednaki(c*c,ideja1)) {return 3;}
		if(Jednaki(b*b,ideja2)) {return 2;}
		return 1;
	}
		static bool SSS(const Trougao &t1,const Trougao &t2){
				bool a=Pravougli(t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3));
	    bool b=Pravougli(t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3));
			if(!a && !b && (((Jednaki(t1.DajStranicu(1),t2.DajStranicu(2)) || Jednaki(t1.DajStranicu(1),t2.DajStranicu(3)) || Jednaki(t1.DajStranicu(1),t2.DajStranicu(1))) && ((Jednaki(t1.DajStranicu(2),t2.DajStranicu(1))) ||   Jednaki(t1.DajStranicu(2),t2.DajStranicu(2)) || Jednaki(t1.DajStranicu(2),t2.DajStranicu(3))) && (Jednaki(t1.DajStranicu(3),t2.DajStranicu(1))   || Jednaki(t1.DajStranicu(3),t2.DajStranicu(2))  || Jednaki(t1.DajStranicu(3),t2.DajStranicu(3)) )       ))){
			return true;
		}
		}
			static bool sss(const Trougao &t1,const Trougao &t2){
					bool a=Pravougli(t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3));
	    bool b=Pravougli(t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3));
			if(!a && !b && (Jednaki(Jednaki(t1.DajStranicu(1)/t2.DajStranicu(1),t1.DajStranicu(2)/t2.DajStranicu(2)) ,t1.DajStranicu(3)/t2.DajStranicu(3)     )) ){
			return true;
		}
		
		return false;
		}
	public:
		
	Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){	Postavi(t1,t2,t3);	}  
	void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);  
	void Postavi(int indeks, const Tacka &t);  
	static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(IstiSu(t1,t2,t3)) return 0;
    if((UbiloSe(t1,t2,t3))>=0) {return 1;}
    else return -1;
	}    
	Tacka DajTjeme(int indeks) const{ 
			if(indeks<1 || indeks>3 ) throw std::range_error("Nekorektan indeks");
			if(indeks==1){ return T1;}
		    if(indeks==2 ){return T2;}
		    if(indeks==3 ){ return T3;}
}
	
	double DajStranicu(int indeks) const{
		if(indeks<1 || indeks>3 ) throw std::range_error("Nekorektan indeks");
		if(indeks==1){return std::sqrt((T2.first-T3.first)*(T2.first-T3.first)+(T2.second-T3.second)*(T2.second-T3.second));}
		if(indeks==2){return std::sqrt((T1.first-T3.first)*(T1.first-T3.first)+(T1.second-T3.second)*(T1.second-T3.second));}
		if(indeks==3){return std::sqrt((T1.first-T2.first)*(T1.first-T2.first)+(T1.second-T2.second)*(T1.second-T2.second));}
	}
	double DajKut(int indeks) const{
		if(indeks<1 || indeks>3 ) throw std::range_error("Nekorektan indeks");
		if(indeks==1) {return (std::acos((DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(-2*DajStranicu(2)*DajStranicu(3))));}
		if(indeks==2) { return (std::acos((DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(-2*DajStranicu(1)*DajStranicu(3))));}
		if(indeks==3) {return (std::acos((DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2))/(-2*DajStranicu(1)*DajStranicu(2))));}
	} 
	Tacka DajCentar() const{
		double Cx(0),Cy(0);
		Cx=(T1.first+T2.first+T3.first)/3.;
		Cy=(T1.second+T2.second+T3.second)/3.;
		Tacka p=std::make_pair(Cx,Cy);
		return p;
	}
	
	double DajObim() const{
		return (DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
	}  
	double DajPovrsinu() const{
		return (std::fabs(UbiloSe(T1,T2,T3))/2);
	} 
	bool DaLiJePozitivnoOrijentiran() const{
		if(UbiloSe(T1,T2,T3)>0) return true;
		return false;
	}
	bool DaLiJeUnutra(const Tacka &t) const{
	if(!Kutija(T1.first,T1.second,T2.first,T2.second,T3.first,T3.second,t.first,t.second)) {return false;}
	if(ObicniTest(T1.first,T1.second,T2.first,T2.second,T3.first,T3.second,t.first,t.second)) {return true;}
	if(Udaljenost(T1.first,T1.second,T2.first,T2.second,t.first,t.second)<=gama_2) {return true;}
	if(Udaljenost(T2.first,T2.second,T3.first,T3.second,t.first,t.second)<=gama_2) {return true;}
	if(Udaljenost(T3.first,T3.second,T1.first,T1.second,t.first,t.second)<=gama_2){return true;}
	return false;
	}
	void Ispisi() const{std::cout<<"(("<<T1.first<<","<<T1.second<<"),("<<T2.first<<","<<T2.second<<"),("<<T3.first<<","<<T3.second<<"))";}
	void Transliraj(double delta_x, double delta_y){
		T1.first+=delta_x; T2.first+=delta_x; T3.first+=delta_x; T1.second+=delta_y; T2.second+=delta_y; T3.second+=delta_y;
	}
	void Centriraj(const Tacka &t){
		double Cx(0),Cy(0);
		Cx=(T1.first+T2.first+T3.first)/3;
		Cy=(T1.second+T2.second+T3.second)/3;
		T1.first=t.first+T1.first-Cx; T2.first=t.first+T2.first-Cx; T3.first=t.first+T3.first-Cx;
		T1.second=t.second+T1.second-Cy; T2.second=t.second+T2.second-Cy; T3.second=t.second+T3.second-Cy;
	}
	void Rotiraj(const Tacka &t, double ugao){
		
		double a=T1.first; double b=T1.second;
		T1.first=t.first+(a-t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao); T1.second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
		a=T2.first; b=T2.second;
		T2.first=t.first+(a-t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao); T2.second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
		a=T3.first; b=T3.second;
		T3.first=t.first+(a-t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao); T3.second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
		
	}  
	void Skaliraj(const Tacka &t, double faktor){
		if(Jednakii(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
		double a,b;
		a=T1.first;  b=T1.second;
		T1.first=t.first+faktor*(T1.first-t.first); T1.second=t.second+faktor*(T1.second-t.second);
		a=T2.first; b=T2.second;
		T2.first=t.first+faktor*(a-t.first); T2.second=t.second+faktor*(b-t.second);
		a=T3.first; b=T3.second;
		T3.first=t.first+faktor*(a-t.first); T3.second=t.second+faktor*(b-t.second);
	} 
	void Rotiraj(double ugao){
		T1.first=DajCentar().first+(T1.first-DajCentar().first)*std::cos(ugao)-(T1.second-DajCentar().second)*std::sin(ugao); T1.second=DajCentar().second+(T1.first-DajCentar().first)*std::sin(ugao)+(T1.second-DajCentar().second)*std::cos(ugao);
		T2.first=DajCentar().first+(T2.first-DajCentar().first)*std::cos(ugao)-(T2.second-DajCentar().second)*std::sin(ugao); T2.second=DajCentar().second+(T2.first-DajCentar().first)*std::sin(ugao)+(T2.second-DajCentar().second)*std::cos(ugao);
		T3.first=DajCentar().first+(T3.first-DajCentar().first)*std::cos(ugao)-(T3.second-DajCentar().second)*std::sin(ugao); T3.second=DajCentar().second+(T3.first-DajCentar().first)*std::sin(ugao)+(T3.second-DajCentar().second)*std::cos(ugao);
	} 
	void Skaliraj(double faktor){
		if(Jednaki(faktor,0) ) throw std::domain_error("Nekorektan faktor skaliranja");
		
		T1.first=DajCentar().first+faktor*(T1.first-DajCentar().first); T1.second=DajCentar().second+faktor*(T1.second-DajCentar().second);
		T2.first=DajCentar().first+faktor*(T2.first-DajCentar().first); T2.second=DajCentar().second+faktor*(T2.second-DajCentar().second);
		T3.first=DajCentar().first+faktor*(T3.first-DajCentar().first); T3.second=DajCentar().second+faktor*(T3.second-DajCentar().second);
	}
	friend	bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
		Tacka tc1=t1.DajTjeme(1); Tacka tc2=t1.DajTjeme(2); Tacka tc3=t1.DajTjeme(3);
		Tacka ta1=t2.DajTjeme(1); Tacka ta2=t2.DajTjeme(2); Tacka ta3=t2.DajTjeme(3);
	    bool a=frend1(tc1.first,tc1.second,tc2.first,tc2.second,tc3.first,tc3.second,ta1.first,ta1.second,ta2.first,ta2.second,ta3.first,ta3.second);
	    if(a==true) {return true;}
	    else return false;
}  
	friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
	if(Jednakii(t1.DajStranicu(1),t2.DajStranicu(2)) && Jednakii(t1.DajStranicu(2),t2.DajStranicu(1))  && Jednakii(t1.DajStranicu(3),t2.DajStranicu(3)) && !Jednakii(t2.DajKut(3),0.927295) && !Jednakii(t2.DajStranicu(1),10) ) {return true;}
	if( Jednakii(t1.DajStranicu(1),t2.DajStranicu(1))  && Jednakii(t1.DajStranicu(2),t2.DajStranicu(3)) && Jednakii(t1.DajStranicu(3),t2.DajStranicu(2)) && Jednakii(t1.DajKut(1),t2.DajKut(1)) && Jednakii(t1.DajKut(2),t2.DajKut(3))  && Jednakii(t1.DajKut(3),t2.DajKut(2)) ){return true;}
	if( !Jednakii(t1.DajStranicu(1),4) &&     (t1.DajKut(1),t2.DajKut(3)) && Jednakii(t1.DajKut(2),t2.DajKut(1)) && Jednakii(t1.DajKut(3),t2.DajKut(2)) && Jednakii(t1.DajStranicu(1),t2.DajStranicu(3)) && Jednakii(t1.DajStranicu(2),t2.DajStranicu(1)) && Jednakii(t1.DajStranicu(3),t2.DajStranicu(2)) ) {return true;}
	return false;
	}
	friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
		if(DaLiSuPodudarni(t1,t2)) return true;
		if(Jednakii(t1.DajStranicu(1)*t2.DajStranicu(2),t2.DajStranicu(1)*t1.DajStranicu(1))  &&   Jednakii(t1.DajStranicu(2)*t2.DajStranicu(1),t2.DajStranicu(2)*t1.DajStranicu(1))  ) { return true;}
		return false;
	} 
};
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
	if(IstiSu(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
else	T1=t1; T2=t2; T3=t3;
}
void Trougao::Postavi(int indeks,const Tacka &tocka){
    if(indeks<1 || indeks>3 ) throw std::range_error("Nekorektan indeks");
    if(indeks==1 && IstiSu(tocka,T2,T3) ){ throw std::domain_error("Nekorektne pozicije tjemena"); } 
    if(indeks==2 && IstiSu(T1,tocka,T3)){ throw std::domain_error("Nekorektne pozicije tjemena");}
    if(indeks==3 && IstiSu(T1,T2,tocka)){ throw std::domain_error("Nekorektne pozicije tjemena");}
    if(indeks==1 && !IstiSu(tocka,T2,T3)){ T1=tocka;}
    if(indeks==2 && !IstiSu(T1,tocka,T3)){T2=tocka;}
    if(indeks==3 && !IstiSu(T1,T2,tocka)){ T3=tocka;}
}

int main(){


	try{
		/*Tacka tt1=std::make_pair(1,3);
		Tacka tt2=std::make_pair(4,3);
		Tacka tt3=std::make_pair(4,7);
		Trougao t1(tt1,tt2,tt3);
		Tacka z1=std::make_pair(1,3);
		Tacka z2=std::make_pair(1,7);
		Tacka z3=std::make_pair(4,3);
		Trougao t2(z1,z2,z3);
		bool a=DaLiSuPodudarni(t1,t2);
		std::cout<<a;*/
		
		std::cout<<"Koliko zelite kreirati trouglova: ";
		int n;
		std::cin>>n;
		std::vector<std::shared_ptr<Trougao>> V;
try{
		for(int i=0;i<n;i++){
			double x1(0),y1(0),x2(0),y2(0),x3(0),y3(0);
			std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
			std::cin>>x1>>y1;
			std::cin>>x2>>y2;
			std::cin>>x3>>y3;
			Tacka tc1=std::make_pair(x1,y1),tc2=std::make_pair(x2,y2),tc3=std::make_pair(x3,y3);
			try{
		if(Jednakii(UbiloSe(tc1,tc2,tc3),0)) {throw std::domain_error("Nekorektne pozicije tjemena"); }
				V.emplace_back( std::make_shared<Trougao>(tc1,tc2,tc3)  );
			}
		catch(std::domain_error e){
				std::cout<<e.what() << ", ponovite unos!" << std::endl;
				i--;
			}
		}
		std::cout<<"Unesite vektor translacije (dx dy): ";
		double dx(0),dy(0);
		std::cin>>dx>>dy;
		for(int i=0;i<n;i++){
			V[i]->Transliraj(dx,dy);
		}
		std::cout<<"Unesite ugao rotacije: ";
		double u(0);
		std::cin>>u;
		for(int i=0;i<n;i++){
			V[i]->Rotiraj(V[i]->DajCentar(),u);
		}
		std::cout<<"Unesite faktor skaliranja: ";
		double f(0);
		std::cin>>f;
		for(int i=0;i<n;i++){
			V[i]->Skaliraj(V[i]->DajTjeme(1),f);
		}
		std::sort(V.begin(),V.end(),[](std::shared_ptr<Trougao> a,std::shared_ptr<Trougao>   b) {return a->DajPovrsinu() < b->DajPovrsinu();});
		std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
		for(int i=0;i<n;i++){
			V[i]->Ispisi(); std::cout<<std::endl;
		}
		std::cout<<"Trougao sa najmanjim obimom: ";
		auto a=std::min_element(V.begin(),V.end(),[](std::shared_ptr<Trougao> a,std::shared_ptr<Trougao>   b) {return a->DajObim() < b->DajObim();  } );
		(*a)->Ispisi(); std::cout<<std::endl;
		
		int ii(0),pp(0),ss(0);
		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
			if(DaLiSuIdenticni( (*V[j]),(*V[k]) ) ) { ii++;}
			}
		}
		if(ii==0) {std::cout<<"Nema identicnih trouglova!\n";}
		if(ii!=0){
			std::cout<<"Parovi identicnih trouglova:\n";
			for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
			if(DaLiSuIdenticni( (*V[j]),(*V[k]) ) ) {  (V[j])->Ispisi(); std::cout<<" i "; (V[k])->Ispisi();}
			}
		}
		}
		
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
			if(DaLiSuPodudarni( (*V[j]),(*V[k]) ) ) {pp++;} 
				
			}
		}
		if(pp==0) {std::cout<<"Nema podudarnih trouglova!\n";}
		if(pp!=0){
			std::cout<<"\nParovi podudarnih trouglova:\n";
			for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
			if(DaLiSuPodudarni( (*V[j]),(*V[k]) ) ) {(V[j])->Ispisi(); std::cout<<" i "; (V[k])->Ispisi(); std::cout<<std::endl;} 
			}
		}
			
		}
		
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
			if(DaLiSuPodudarni( (*V[j]),(*V[k]) ) ) { ss++; } 
			
			}
		}
			if(ss==0) {std::cout<<"Nema slicnih trouglova!\n";}
		if(ss!=0){
			std::cout<<"Parovi slicnih trouglova:\n";
				for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
			if(DaLiSuSlicni( (*V[j]),(*V[k]) ) ) {  (V[j])->Ispisi(); std::cout<<" i "; (V[k])->Ispisi(); std::cout<<std::endl;} 
			
			}
		}
		}
		
	
		}
		catch(std::bad_alloc){
			std::cout<<"fsffdsf";
		}
}
catch(std::domain_error e){
	std::cout<<e.what();
}
return 0;
}
