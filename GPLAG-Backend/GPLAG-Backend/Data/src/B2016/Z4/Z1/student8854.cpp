/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
typedef std::pair<double,double> Tacka;
const double eps (1e-10);

bool Poredi(double x,double y)
{
    return fabs(x-y)<eps;
}
class Trougao{
	
	Tacka x[3];
	
	public:
	
	
	Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
	{
		if(Orijentacija(t1,t2,t3)==0)
		throw std::domain_error("Nekorektne pozicije tjemena");
		
		x[0]=t1;x[1]=t2;x[2]=t3;
		
		
		
	}
	
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
    		if(Orijentacija(t1,t2,t3)==0)
		throw std::domain_error("Nekorektne pozicije tjemena");
		
	x[0]=t1;x[1]=t2;x[2]=t3;
		
		
    	
    	
    	
    }
    
    void Postavi(int indeks, const Tacka &t)
    {
    	if(indeks<1 || indeks>3)
    	throw std::range_error("Nekorektan indeks");
    	x[indeks-1]=t;
    	
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
    	double xx;
    	xx=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    	if(xx<0) return -1;
    	else
    	{
    	   	if (xx>0) return 1;
    	   	else
    	   	return 0;
    	}
    	
    }
    
    Tacka DajTjeme(int indeks) const
    {
    	if(indeks<1 || indeks>3)
    	throw std::range_error("Nekorektan indeks");
    	
    	return x[indeks-1];
    }
    
    double DajStranicu(int indeks) const
    {
    	if(indeks<1 || indeks>3)
    	throw std::range_error("Nekorektan indeks");
    	double a;
    	if(indeks==1){a= (x[1].first-x[2].first)*(x[1].first-x[2].first)+(x[1].second-x[2].second)*(x[1].second-x[2].second) ;    return std::sqrt(a);   }                                         
    	if(indeks==2){a= (x[0].first-x[2].first)*(x[0].first-x[2].first)+(x[0].second-x[2].second)*(x[0].second-x[2].second);   	return std::sqrt(a);  }
    	else
    	{if(indeks==3){a= (x[0].first-x[1].first)*(x[0].first-x[1].first)+(x[0].second-x[1].second)*(x[0].second-x[1].second);   	return std::sqrt(a); }}
    	
    	
    }
    
    double DajUgao(int indeks) const
    {
        if(indeks<1 || indeks>3)
    	throw std::range_error("Nekorektan indeks");
        double a;
        if(indeks==1){a= ((DajStranicu(2))*(DajStranicu(2))+(DajStranicu(3))*(DajStranicu(3))-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)) ;    return std::acos(a);   }                                         
    	if(indeks==2){a= ((DajStranicu(1))*(DajStranicu(1))+(DajStranicu(3))*(DajStranicu(3))-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)) ;    	return std::acos(a);  }
    	else
    	{if(indeks==3){a= ((DajStranicu(2))*(DajStranicu(2))+(DajStranicu(1))*(DajStranicu(1))-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)) ;    	return std::acos(a); }}
        
        
       
        
        
    }
    
    Tacka DajCentar() const
    {
        return {(x[0].first+x[1].first+x[2].first)/3.,(x[0].second+x[1].second+x[2].second)/3.};
    }
    
    double DajObim() const{
        
        double b(0);
        b+= std::sqrt((x[1].first-x[2].first)*(x[1].first-x[2].first)+(x[1].second-x[2].second)*(x[1].second-x[2].second)); 
        b+= std::sqrt((x[0].first-x[2].first)*(x[0].first-x[2].first)+(x[0].second-x[2].second)*(x[0].second-x[2].second)); 
        b+= std::sqrt((x[0].first-x[1].first)*(x[0].first-x[1].first)+(x[0].second-x[1].second)*(x[0].second-x[1].second)); 
        return b;
    }
    
    double DajPovrsinu() const
    {
        return std::fabs((x[0].first*(x[1].second-x[2].second)-x[1].first*(x[0].second-x[2].second)+x[2].first*(x[0].second-x[1].second))/2.);
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
        return Orijentacija(x[0],x[1],x[2]);
    }
    
    bool DaLiJeUnutra(const Tacka &t) const
    {
        Trougao t1(x[0],x[1],t),t2(x[0],x[2],t),t3(x[1],x[2],t);
        return Poredi(t1.DajPovrsinu()+t2.DajPovrsinu()+t3.DajPovrsinu(),this->DajPovrsinu());
        
    }
    
    void Ispisi() const
    {
        std::cout<<"(("<<x[0].first<<","<<x[0].second<<"),("<<x[1].first<<","<<x[1].second<<"),("<<x[2].first<<","<<x[2].second<<"))";
    }
    
    void Transliraj(double delta_x, double delta_y)
    {
        x[0].first+=delta_x;x[1].first+=delta_x;x[2].first+=delta_x;
        x[0].second+=delta_y;x[1].second+=delta_y;x[2].second+=delta_y;
    }
    void Centriraj(const Tacka &t)
    {
        Tacka Teziste=DajCentar();
        double delta_x,delta_y;
        delta_x=t.first-Teziste.first;
        delta_y=t.second-Teziste.second;
        Transliraj(delta_x,delta_y);
    }
    
    
    void Rotiraj(const Tacka &t, double ugao)
    {
        double a,b;
        a=x[0].first;b=x[0].second;
        
        x[0].first=t.first+(a-t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao);
        x[0].second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
        
        a=x[1].first;b=x[1].second;
        
        x[1].first=t.first+(a-t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao);
        x[1].second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
        
        a=x[2].first;b=x[2].second;
        
        x[2].first=t.first+(a-t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao);
        x[2].second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
        
    }
    
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(!faktor)
        throw std::domain_error("Nekorektan faktor skaliranja");
        double a,b;
        
        a=x[0].first;b=x[0].second;
        
        x[0].first=t.first+faktor*(a-t.first);
        x[0].second=t.second+faktor*(b-t.second);
        
        a=x[1].first;b=x[1].second;
        
       x[1].first=t.first+faktor*(a-t.first);
        x[1].second=t.second+faktor*(b-t.second);
        
        
        a=x[2].first;b=x[2].second;
        
        x[2].first=t.first+faktor*(a-t.first);
        x[2].second=t.second+faktor*(b-t.second);
        
        
        
    }
    
    
    void Rotiraj(double ugao){
        Rotiraj(DajCentar(),ugao);
    }
    
    void Skaliraj(double faktor){
        Skaliraj(DajCentar(),faktor);
    }
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
    {
        bool a,b,c,d,e,f;
        
        a=(Poredi(t1.DajTjeme(1).first,t2.DajTjeme(1).first) && Poredi(t1.DajTjeme(1).second,t2.DajTjeme(1).second) && Poredi(t1.DajTjeme(2).first,t2.DajTjeme(2).first) && Poredi(t1.DajTjeme(2).second,t2.DajTjeme(2).second) && Poredi(t1.DajTjeme(3).first,t2.DajTjeme(3).first) && Poredi(t1.DajTjeme(3).second,t2.DajTjeme(3).second));
        b=(Poredi(t1.DajTjeme(1).first,t2.DajTjeme(1).first) && Poredi(t1.DajTjeme(1).second,t2.DajTjeme(1).second) && Poredi(t1.DajTjeme(2).first,t2.DajTjeme(3).first) && Poredi(t1.DajTjeme(2).second,t2.DajTjeme(3).second) && Poredi(t1.DajTjeme(3).first,t2.DajTjeme(2).first) && Poredi(t1.DajTjeme(3).second,t2.DajTjeme(2).second));
        c=(Poredi(t1.DajTjeme(1).first,t2.DajTjeme(2).first) && Poredi(t1.DajTjeme(1).second,t2.DajTjeme(2).second) && Poredi(t1.DajTjeme(2).first,t2.DajTjeme(1).first) && Poredi(t1.DajTjeme(2).second,t2.DajTjeme(1).second) && Poredi(t1.DajTjeme(3).first,t2.DajTjeme(3).first) && Poredi(t1.DajTjeme(3).second,t2.DajTjeme(3).second));
        
        d=(Poredi(t1.DajTjeme(1).first,t2.DajTjeme(2).first) && Poredi(t1.DajTjeme(1).second,t2.DajTjeme(2).second) && Poredi(t1.DajTjeme(2).first,t2.DajTjeme(3).first) && Poredi(t1.DajTjeme(2).second,t2.DajTjeme(3).second) && Poredi(t1.DajTjeme(3).first,t2.DajTjeme(1).first) && Poredi(t1.DajTjeme(3).second,t2.DajTjeme(1).second));
        e=(Poredi(t1.DajTjeme(1).first,t2.DajTjeme(3).first) && Poredi(t1.DajTjeme(1).second,t2.DajTjeme(3).second) && Poredi(t1.DajTjeme(2).first,t2.DajTjeme(1).first) && Poredi(t1.DajTjeme(2).second,t2.DajTjeme(1).second) && Poredi(t1.DajTjeme(3).first,t2.DajTjeme(2).first) && Poredi(t1.DajTjeme(3).second,t2.DajTjeme(2).second));
        f=(Poredi(t1.DajTjeme(1).first,t2.DajTjeme(3).first) && Poredi(t1.DajTjeme(1).second,t2.DajTjeme(3).second) && Poredi(t1.DajTjeme(2).first,t2.DajTjeme(2).first) && Poredi(t1.DajTjeme(2).second,t2.DajTjeme(2).second) && Poredi(t1.DajTjeme(3).first,t2.DajTjeme(1).first) && Poredi(t1.DajTjeme(3).second,t2.DajTjeme(1).second));
        
        return (a || b || c || d || e || f);
    }
    
    
    
    
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
    {
        
      
        
        double a1[3]{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
        double a2[3]{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
        
        
        bool x,y,z,t,u,v;
        x=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3));
        y=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1));
        z=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2));
        t=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2));
        u=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1));
        v=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3));
        bool a,b,c,d,e,f;
        a=Poredi(a1[0],a2[0]) && Poredi(a1[1],a2[1]) && Poredi(a1[2],a2[2]);
        b=Poredi(a1[0],a2[1]) && Poredi(a1[1],a2[2]) && Poredi(a1[2],a2[0]);
        c=Poredi(a1[0],a2[2]) && Poredi(a1[1],a2[0]) && Poredi(a1[2],a2[1]);
        d=Poredi(a1[0],a2[0]) && Poredi(a1[1],a2[2]) && Poredi(a1[2],a2[1]);
        e=Poredi(a1[0],a2[2]) && Poredi(a1[1],a2[1]) && Poredi(a1[2],a2[0]);
        f=Poredi(a1[0],a2[1]) && Poredi(a1[1],a2[0]) && Poredi(a1[2],a2[2]);
      
         return (a && x) || (b && y) || (c && z) || (d && t) || (e && u) || (f && v);
    }
    
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
    {
        
        double a1[3]{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
        double a2[3]{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
        bool x,y,z,t,u,v;
        x=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3));
        y=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1));
        z=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2));
        t=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2));
        u=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1));
        v=Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3));
        
        
        bool a,b,c,d,e,f;
        a=Poredi(a1[0]/a2[0],a1[1]/a2[1]) && Poredi(a1[1]/a2[1],a1[2]/a2[2]) && Poredi(a1[2]/a2[2],a1[0]/a2[0]);
        b=Poredi(a1[0]/a2[1],a1[1]/a2[2]) && Poredi(a1[1]/a2[2],a1[2]/a2[0]) && Poredi(a1[2]/a2[0],a1[0]/a2[1]);
        c=Poredi(a1[0]/a2[2],a1[1]/a2[0]) && Poredi(a1[1]/a2[0],a1[2]/a2[1]) && Poredi(a1[2]/a2[1],a1[0]/a2[2]);
        d=Poredi(a1[0]/a2[0],a1[1]/a2[2]) && Poredi(a1[1]/a2[2],a1[2]/a2[1]) && Poredi(a1[2]/a2[1],a1[0]/a2[0]);
        e=Poredi(a1[0]/a2[2],a1[1]/a2[1]) && Poredi(a1[1]/a2[1],a1[2]/a2[0]) && Poredi(a1[2]/a2[0],a1[0]/a2[2]);
        f=Poredi(a1[0]/a2[1],a1[1]/a2[0]) && Poredi(a1[1]/a2[0],a1[2]/a2[2]) && Poredi(a1[2]/a2[2],a1[0]/a2[1]);
        return (a && x) || (b && y) || (c && z) || (d && t) || (e && u) || (f && v);
    }
	
	
	

	
};
































int main ()
{
	
	
	std::cout<<"Koliko zelite kreirati trouglova: ";
	int n;
	std::cin>>n;
	std::vector<std::shared_ptr<Trougao>> ulaz(n);
	
	double x1,y1,x2,y2,x3,y3;
	
	
	
	
	
	
	for(int i=0;i<n;i++)
	{
	    
	    
	    for(;;)
	    {
	        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
	        
	        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
	        Tacka g,h,j;
	        g.first=x1;
	        g.second=y1;
	        h.first=x2;
	        h.second=y2;
	        j.first=x3;
	        j.second=y3;
	        try{
	        Trougao trouglova(g,h,j);
	        ulaz[i]=(std::shared_ptr<Trougao>)new Trougao(g,h,j);
	         break;
	        }
	       catch(...)
	        {std::cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<std::endl;
	         
	         }
	    
	    
	    }
	    
	   
	}
	std::cout<<"Unesite vektor translacije (dx dy): ";
double dx,dy;
std::cin>>dx>>dy;

	std::cout<<"Unesite ugao rotacije: ";
double ugao;
std::cin>>ugao;


	std::cout<<"Unesite faktor skaliranja: ";
double faktor;
std::cin>>faktor;
	
	
	std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;

	    std::transform(ulaz.begin(),ulaz.end(),ulaz.begin(),ulaz.begin(),[dx,dy,ugao,faktor](std::shared_ptr<Trougao> jedan,std::shared_ptr<Trougao> dva){
	(*jedan).Transliraj(dx,dy);
	(*jedan).Rotiraj(ugao);
	(*jedan).Skaliraj((*dva).DajTjeme(1),faktor);
	return jedan;
	        });
	    
	    std::sort(ulaz.begin(),ulaz.end(),[](std::shared_ptr<Trougao> jedan,std::shared_ptr<Trougao> dva){return jedan->DajPovrsinu()<dva->DajPovrsinu();  });
	    
std::for_each(ulaz.begin(),ulaz.end(),[](std::shared_ptr<Trougao> jedan){
    jedan->Ispisi();
    std::cout<<std::endl;
    
});
std::cout<<"Trougao sa najmanjim obimom: ";
auto u=std::max_element(ulaz.begin(),ulaz.end(),[](std::shared_ptr<Trougao> jedan,std::shared_ptr<Trougao> dva){
    
    return jedan->DajObim()>dva->DajObim();
    
});
(*u)->Ispisi();
std::cout<<std::endl;

/*std::for_each(ulaz.begin(),ulaz.end(),[](std::shared_ptr<Trougao> jedan){
    jedan->Ispisi();
    std::cout<<std::endl;
    
});*/
{int brojac=0;
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        
        if(DaLiSuIdenticni(*ulaz[i],*ulaz[j]))
        {
            if(!brojac)
            {std::cout<<"Parovi identicnih trouglova: "<<std::endl;brojac++;}
            ulaz[i]->Ispisi();std::cout<<" i ";ulaz[j]->Ispisi();std::cout<<std::endl;}
    }
}
if(!brojac)
std::cout<<"Nema identicnih trouglova! "<<std::endl;
}

{int brojac=0;
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        
        if(DaLiSuPodudarni(*ulaz[i],*ulaz[j]))
        {
            if(!brojac)
            {std::cout<<"Parovi podudarnih trouglova: "<<std::endl;brojac++;}
            ulaz[i]->Ispisi();std::cout<<" i ";ulaz[j]->Ispisi();std::cout<<std::endl;}
    }
}
if(!brojac)
std::cout<<"Nema podudarnih trouglova! "<<std::endl;
}

{int brojac=0;
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        
        if(DaLiSuSlicni(*ulaz[i],*ulaz[j]))
        {
            if(!brojac)
            {std::cout<<"Parovi slicnih trouglova: "<<std::endl;brojac++;}
            ulaz[i]->Ispisi();std::cout<<" i ";ulaz[j]->Ispisi();std::cout<<std::endl;}
    }
}
if(!brojac)
std::cout<<"Nema slicnih trouglova! "<<std::endl;
}




	return 0;
}






