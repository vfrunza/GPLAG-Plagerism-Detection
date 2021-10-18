/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <vector>
#include <memory>
#include <algorithm>

const double eps = 1E-10;
typedef std::pair<double,double> Tacka;
class Trougao{
	Tacka a,b,c;
	public:
	static double povrsina(const Tacka t1, const Tacka t2, const Tacka t3){
	    double x=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
	    return x;
	}
	Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
		if(ProvjeriTacke(t1,t2,t3)==false)throw std::domain_error("Nekorektne pozicije tjemena");
		a=t1;b=t2;c=t3;
	}
	void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
		if(ProvjeriTacke(t1,t2,t3)==false)throw std::domain_error("Nekorektne pozicije tjemena");
		a=t1;b=t2;c=t3;
	}
	void Postavi(int indeks, const Tacka &t){
		if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
		if(indeks==1)a=t;else if(indeks==2)b=t;else if(indeks==3)c=t;
	}
	static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
		double x=povrsina(t1,t2,t3);
		if(fabs(x)<eps)return 0;
		else if(x<0)return -1;
		else if(x>0)return 1;
		return 0;
	}
	Tacka DajTjeme(int indeks) const{
		if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
		else if(indeks ==1)return a;else if(indeks==2)return b;return c;
	}
	double DajStranicu(int indeks) const{
		if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
		else if(indeks==3)return sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));
		else if(indeks==2)return sqrt((c.first-a.first)*(c.first-a.first)+(c.second-a.second)*(c.second-a.second));
		return sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second));
	}
	double DajUgao(int indeks) const{
		if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
		else if(indeks==1)return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(3)*DajStranicu(2)));
		else if(indeks==2)return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
		return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
	}
	Tacka DajCentar() const{
	    double x=(a.first+b.first+c.first)/3;double y=(a.second+b.second+c.second)/3;
	    return std::make_pair(x,y);
	}
	double DajObim() const{
	    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
	}
	double DajPovrsinu() const{
	    return fabs((1./2)*povrsina(a,b,c));
	}
	bool DaLiJePozitivnoOrijentiran() const{
		if(Orijentacija(a,b,c)==1)return true;
		if(Orijentacija(a,b,c)==-1)return false;
		return false;
	}
	bool DaLiJeUnutra(const Tacka &t)const{
	if(Orijentacija(a,b,t)==1 && Orijentacija(b,c,t)==1 && Orijentacija(c,a,t)==1)return true;
	return false;
	}
	void Ispisi() const{
		std::cout<<"(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))";
	}
	void Transliraj(double delta_x, double delta_y){
		a.first+=delta_x;b.first+=delta_x;c.first+=delta_x;
		a.second+=delta_y;b.second+=delta_y;c.second+=delta_y;
	}
	void Centriraj(const Tacka &t){
		double x_promjena=t.first-DajCentar().first;double y_promjena=t.second-DajCentar().second;
		a.first+=x_promjena;b.first+=x_promjena;c.first+=x_promjena;
		a.second+=y_promjena;b.second+=y_promjena;c.second+=y_promjena;
	}
	void RotirajTacku(Tacka &rot,const Tacka &cr,double ugao){
		auto rot_x=rot.first;
		rot_x=(cr.first+(rot.first-cr.first)*cos(ugao)-(rot.second-cr.second)*sin(ugao));
		rot.second=(cr.second+(rot.first-cr.first)*sin(ugao)+(rot.second-cr.second)*cos(ugao));
		rot.first=rot_x;
	}
	void Rotiraj(const Tacka &t, double ugao){
		RotirajTacku(a,t,ugao);RotirajTacku(b,t,ugao);RotirajTacku(c,t,ugao);
	}
	void SkalirajTacku(Tacka &skal,const Tacka &cs,double faktor){
		skal.first=cs.first+faktor*(skal.first-cs.first);
		skal.second=cs.second+faktor*(skal.second-cs.second);
	}
	void Skaliraj(const Tacka &t, double faktor){
		if(fabs(faktor)< eps)throw std::domain_error("Nekorektan faktor skaliranja");
		SkalirajTacku(a,t,faktor);SkalirajTacku(b,t,faktor);SkalirajTacku(c,t,faktor);
	}
	void Rotiraj(double ugao){
		auto centar=DajCentar();
		RotirajTacku(a,centar,ugao);RotirajTacku(b,centar,ugao);RotirajTacku(c,centar,ugao);
	}
	void Skaliraj(double faktor){
		if(fabs(faktor)<eps)throw std::domain_error("Nekorektan faktor skaliranja");
		auto centar=(DajCentar());
		SkalirajTacku(a,centar,faktor);SkalirajTacku(b,centar,faktor);SkalirajTacku(c,centar,faktor);
	
	}
	bool ProvjeriTacke(const Tacka &t1,const Tacka &t2,const Tacka &t3);
	friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
	friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
	friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
	friend bool UporediOpet(const Trougao &t1,const Trougao &t2);
	friend bool ProvjeriPodudarnost(const Trougao &t1,const Trougao &t2);
};
bool UporediTacke(const Tacka &a,const Tacka &b,int slucaj=1){
	if(slucaj==1){
		if(fabs(a.first-b.first)<eps  && fabs(a.second-b.second)<eps)return true;
		}
	if(slucaj==0){
			if(fabs(a.first-b.first)<0.0001 && fabs(a.second-b.second)<0.0001)return true;
		}
	return false;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
	if(UporediTacke(t1.a,t2.a) || UporediTacke(t1.a,t2.b) || UporediTacke(t1.a,t2.c)){
		if(UporediTacke(t1.b,t2.a)|| UporediTacke(t1.b,t2.b) || UporediTacke(t1.b,t2.c)){
			if(UporediTacke(t1.c,t2.a) || UporediTacke(t1.c,t2.b) || UporediTacke(t1.c,t2.c)){
				return true;
			}
		}
	}
	return false;
}
bool ProvjeriPodudarnost(const Trougao &t1,const Trougao &t2){
	int slucaj=0;
	if(UporediTacke(t1.a,t2.a,slucaj) || UporediTacke(t1.a,t2.b,slucaj) || UporediTacke(t1.a,t2.c,slucaj)){
		if(UporediTacke(t1.b,t2.a,slucaj)|| UporediTacke(t1.b,t2.b,slucaj) || UporediTacke(t1.b,t2.c,slucaj)){
			if(UporediTacke(t1.c,t2.a,slucaj) || UporediTacke(t1.c,t2.b,slucaj) || UporediTacke(t1.c,t2.c,slucaj)){
				return true;
			}
		}
	}
	return false;
}
bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
	bool slucaj=false;
	if(fabs(t1.DajStranicu(1)-t2.DajStranicu(1))<eps    || fabs(t1.DajStranicu(1)-t2.DajStranicu(2))<eps   || fabs(t1.DajStranicu(1)-t2.DajStranicu(3))<eps   ){
		if(fabs(t1.DajStranicu(2)-t2.DajStranicu(1))<eps    || fabs(t1.DajStranicu(2)-t2.DajStranicu(2))<eps    || fabs(t1.DajStranicu(2)-t2.DajStranicu(3))<eps   ){
			if(fabs(t1.DajStranicu(3)-t2.DajStranicu(1))<eps    || fabs(t1.DajStranicu(3)-t2.DajStranicu(2))<eps    || fabs(t1.DajStranicu(3)-t2.DajStranicu(3))<eps   ){
				slucaj=true;
			}
		}
	}
	if(slucaj==false)return false;
	auto kop_t2=t2;
	auto kop_t1=t1;
	kop_t2.Centriraj(t1.DajCentar());
	double ugao=0;
	while(ugao<10){
		if(ProvjeriPodudarnost(kop_t2,kop_t1)==true)return true;
		kop_t2.Rotiraj(0.01745329252);
		ugao+=0.01745329252;
	}
	return false;
}
bool UporediSlicnost(double a, double b,double c){
	if(fabs(a-b)<eps  && fabs(b-c)<eps )return true;
	return false;
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
	double k(1);
	if(UporediSlicnost(t1.DajStranicu(1)/t2.DajStranicu(1),t1.DajStranicu(2)/t2.DajStranicu(2),t1.DajStranicu(3)/t2.DajStranicu(3)))k=t1.DajStranicu(1)/t2.DajStranicu(1);
	if(UporediSlicnost(t1.DajStranicu(1)/t2.DajStranicu(2),t1.DajStranicu(2)/t2.DajStranicu(3),t1.DajStranicu(3)/t2.DajStranicu(1)))k=t1.DajStranicu(3)/t2.DajStranicu(1);
	if(UporediSlicnost(t1.DajStranicu(1)/t2.DajStranicu(2),t1.DajStranicu(2)/t2.DajStranicu(1),t1.DajStranicu(3)/t2.DajStranicu(3)))k=t1.DajStranicu(3)/t2.DajStranicu(3);	
	if(UporediSlicnost(t1.DajStranicu(1)/t2.DajStranicu(3),t1.DajStranicu(2)/t2.DajStranicu(1),t1.DajStranicu(3)/t2.DajStranicu(2)))k=t1.DajStranicu(3)/t2.DajStranicu(2);
	if(UporediSlicnost(t1.DajStranicu(1)/t2.DajStranicu(3),t1.DajStranicu(2)/t2.DajStranicu(2),t1.DajStranicu(3)/t2.DajStranicu(1)))k=t1.DajStranicu(3)/t2.DajStranicu(2);
	auto t1_kopija=t1;
	auto t2_kopija=t2;
	if(k<1)t1_kopija.Skaliraj(k);
	if(k>1)t2_kopija.Skaliraj(k);
	t2_kopija.Centriraj(t1.DajCentar());
	return DaLiSuPodudarni(t1_kopija,t2_kopija);
}
bool Trougao::ProvjeriTacke(const Tacka &t1,const Tacka &t2,const Tacka &t3){
	double x=0.5*((t1.first*t2.second + t2.first*t3.second + t3.first*t1.second)-
	(t2.first*t1.second + t3.first*t2.second + t1.first*t3.second));
	if(fabs(x+x)<eps)return false;
		return true;
	}
int main(){
	std::cout<<"Koliko zelite kreirati trouglova: ";
	int n;
	Tacka a,b,c;
	std::cin>>n;
	try{
	std::vector<std::shared_ptr<Trougao>> vek_pok(n,nullptr);
	for(int i=0;i<n;i++){
		double ax,ay,bx,by,cx,cy;
		std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
		std::cin>>ax>>ay;
		std::cin>>bx>>by;
		std::cin>>cx>>cy;
		try{
			a=std::make_pair(ax,ay);
			b=std::make_pair(bx,by);
			c=std::make_pair(cx,cy);
			vek_pok[i]=std::shared_ptr<Trougao>(new Trougao(a,b,c));
		}
		catch(std::range_error x){
			std::cout<<"Izuzetak: "<<x.what();
			return 0;
		}
		catch(std::domain_error e){
				std::cout<<e.what() << ", ponovite unos!" << std::endl;
				i--;
				continue;
		}
	  }
	  std::cout<<"Unesite vektor translacije (dx dy): ";//transliranje
	  double koefx,koefy,koefs,ugao;
	  std::cin>>koefx>>koefy;
	  std::cout<<"Unesite ugao rotacije: ";//skaliranje i rotacija
	  std::cin>>ugao;
	  std::cout<<"Unesite faktor skaliranja: ";
	  std::cin>>koefs;
	  std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
	  try{
	  std::transform(vek_pok.begin(),vek_pok.end(),vek_pok.begin(),
	  [koefx,koefy,koefs,ugao](std::shared_ptr<Trougao> a){
	  	a->Transliraj(koefx,koefy);
	  	a->Rotiraj(a->DajCentar(),ugao);
	  	a->Skaliraj(a->DajTjeme(1),koefs);
	  	return a;
	  });
	  }
	  catch(...){//hvatanje izzetka usljed nepravilno zadanog koef!
	  	return 0;
	  }
	 std::sort(vek_pok.begin(),vek_pok.end(),
	  [](std::shared_ptr<Trougao> a,std::shared_ptr<Trougao> b){
	  	return a->DajPovrsinu()<b->DajPovrsinu();
	  });
	 std::for_each(vek_pok.begin(),vek_pok.end(),
	  [](std::shared_ptr<Trougao> a){
	  	a->Ispisi();std::cout<<std::endl;
	  });
	  auto ispis_o=std::max_element(vek_pok.begin(),vek_pok.end(),
	  [](std::shared_ptr<Trougao> a,std::shared_ptr<Trougao> b){
	  	return a->DajObim()>b->DajObim();
	  });
	  std::cout<<"Trougao sa najmanjim obimom: ";(*ispis_o)->Ispisi();
	  std::cout<<std::endl;
	  int brojac=0;
		for(int i=0;i<vek_pok.size()-1;i++){
		for(int j=i;j<vek_pok.size();j++){
			if(i==j)continue;
			if(DaLiSuIdenticni(*vek_pok[i],*vek_pok[j])==true){
				if(brojac==0)std::cout<<"Parovi identicnih trouglova:"<<std::endl;
				vek_pok[i]->Ispisi();std::cout<<" i ";
				vek_pok[j]->Ispisi();std::cout<<std::endl;
				brojac++;
			}
		}
	}if(brojac==0)std::cout<<"Nema identicnih trouglova!"<<std::endl;
	brojac=0;
	for(int i=0;i<vek_pok.size()-1;i++){
		for(int j=i;j<vek_pok.size();j++){
			if(i==j)continue;
			if(DaLiSuPodudarni(*vek_pok[i],*vek_pok[j])==true){
				if(brojac==0)std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
				vek_pok[i]->Ispisi();std::cout<<" i ";
				vek_pok[j]->Ispisi();std::cout<<std::endl;brojac++;
			}
		}
	}if(brojac==0)std::cout<<"Nema podudarnih trouglova!"<<std::endl;
	brojac=0;
	for(int i=0;i<vek_pok.size()-1;i++){
		for(int j=i;j<vek_pok.size();j++){
			if(i==j)continue;
			if(DaLiSuSlicni(*vek_pok[i],*vek_pok[j])==true){
				if(brojac==0)std::cout<<"Parovi slicnih trouglova:"<<std::endl;
				vek_pok[i]->Ispisi();std::cout<<" i ";
				vek_pok[j]->Ispisi();std::cout<<std::endl;
				brojac++;
			}
		}
	}
	if(brojac==0)std::cout<<"Nema slicnih trouglova!"<<std::endl;
	}
	catch(...){
		return 0;
	}
	return 0;
}