/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <vector>
#include <memory>
constexpr double eps=0.00000000001;
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka x[3];
    double orijent(const Tacka &t1, const Tacka &t2, const Tacka &t3)const{
        return t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
    }
    static bool Jesu(double s1, double s2){
        return (abs(s1-s2)<eps);
    }
    void Test(const Tacka &t1, const Tacka &t2, const Tacka &t3)const{
        if(orijent(t1,t2,t3)==0)   throw std::domain_error("Nekorektne pozicije tjemena");
    }
    double dis(const Tacka &t1, const Tacka &t2)const{
        return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    int Unutra(const Tacka &p,const Tacka &t1, const Tacka &t2, const Tacka &t3)const{
        if(orijent(p,t1,t2)>0&&orijent(p,t1,t3)>0&&orijent(p,t2,t3)>0)  
            return 1;
        if(orijent(p,t1,t2)<0&&orijent(p,t1,t3)<0&&orijent(p,t2,t3)<0)  
            return -1;
        return 0;
    }
    void Sortiraj(){
        /*for(int i=0;i<2;i++){
            for(int j=i;j<3;j++){
                if(x[i].first-x[j].first<eps)
            }
        }*/
    }
    void TestI(int indeks)const{
            if(indeks<1||indeks>3)  throw std::range_error("Nekorektan indeks"); 
        }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Test(t1,t2,t3); 
        x[0]=t1;
        x[1]=t2;
        x[2]=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Test(t1,t2,t3); 
        x[0]=t1;
        x[1]=t2;
        x[2]=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        TestI(indeks); 
        x[indeks]=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Trougao p(t1,t2,t3);
        auto d(p.orijent(t1,t2,t3)); 
        if(d<0) return -1; 
        else if(d>0)return 1; 
        return 0;
    }
    Tacka DajTjeme(int indeks) const{ 
        TestI(indeks); 
        return x[indeks];
    }
    double DajStranicu(int indeks) const{ 
        TestI(indeks); 
        return dis(x[(indeks)%3],x[(indeks+1)%3]);
    }
    double DajUgao(int indeks) const{
        TestI(indeks);
        double a(DajStranicu(indeks)), b(DajStranicu((indeks+1)%4)),c(DajStranicu((indeks+2)%4));
        return acos((a*a-b*b-c*c)/(-2*b*c));
    }
    Tacka DajCentar() const{  
        return std::pair<double, double>((x[0].first+x[1].first+x[2].first)/3,(x[0].second+x[1].second+x[2].second)/3);
    }
    double DajObim() const{
        return dis(x[0],x[1])+dis(x[1],x[2])+dis(x[2],x[0]);
    }
    double DajPovrsinu() const{ 
        return fabs(orijent(x[0],x[1],x[2])/2);
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(orijent(x[0],x[1],x[2])>0) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{ 
        if((orijent(x[0],x[1],x[2])>0&&Unutra(t,x[0],x[1],x[2])==1)||(orijent(x[0],x[1],x[2])<0&&Unutra(t,x[0],x[1],x[2])==-1)) return 1; 
        return 0;
    } 
    void Ispisi() const{ 
        std::cout<<"("; 
        for(int i=0;i<3;i++)
        {
            std::cout<<"("<<x[i].first<<","<<x[i].second<<")";
            if(i!=2)std::cout<<",";
        }
        std::cout<<")";
    }
    void Transliraj(double delta_x, double delta_y){ 
        for(int i=0;i<3;i++){
            x[i].first+=delta_x; 
            x[i].second+=delta_y;
        }
    }
    void Centriraj(const Tacka &t){ 
        double dx(t.first-DajCentar().first), dy(t.second-DajCentar().second);
        Transliraj(dx,dy);
    }
    void Rotiraj(const Tacka &t, double ugao){
        for(int i=0;i<3;i++){
            x[i].first=t.first+(x[i].first-t.first)*cos(ugao)-(x[i].second-t.second)*sin(ugao);
            x[i].second=t.second+(x[i].first-t.first)*sin(ugao)+(x[i].second-t.second)*cos(ugao);
        }
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(faktor==0)   throw std::domain_error ("Nekorektan faktor skaliranja");
        for(int i=0;i<3;i++){
            x[i].first=t.first+faktor*(x[i].first-t.first);
            x[i].second=t.second+faktor*(x[i].second-t.second);
        }    
    }
    void Rotiraj(double ugao){
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor){
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        int s(0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                if(t1.x[i]==t2.x[j])    
                    s++;
        }
        if(s==3)    return true;
        return false;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        std::vector<int> v;
        int p(0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
            {
                if(find(v.begin(),v.end(),j)!=v.end())
                    continue;
                if(Jesu(t1.DajStranicu(i+1),t2.DajStranicu(j+1)))
                {   
                    p++;
                    v.push_back(j);
                    break;
                }
            }
        }
        if(p<3)
            return false;
        for(int i=0;i<3;i++){
            if(Jesu(t1.DajUgao(1),t2.DajUgao(i+1)))
            {
                if(Orijentacija(t1.x[0],t1.x[1],t1.x[2])==Orijentacija(t2.x[0],t2.x[1],t2.x[2])){
                    Tacka x1(t1.x[0].first-t1.x[1].first,t1.x[0].second-t1.x[1].second),y1(t1.x[0].first-t1.x[2].first,t1.x[0].second-t1.x[2].second);
                    Tacka x2(t2.x[i].first-t2.x[(i+1)%3].first,t2.x[i].second-t2.x[(i+1)%3].second),y2(t2.x[i].first-t2.x[(i+2)%3].first,t2.x[i].second-t2.x[(i+2)%3].second);
                    if((x1.first*y1.second-y1.first*x1.second>0&&x2.first*y2.second-y2.first*x2.second>0)||(x1.first*y1.second-y1.first*x1.second<0&&x2.first*y2.second-y2.first*x2.second<0))
                        return true;
                    else
                        return false;
                }          
                
            }
        }
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        double k;
        Trougao a(t1),b(t2);
        int p(0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(Jesu(a.DajUgao(i+1),b.DajUgao(j+1))){
                    p++;
                    k=a.DajStranicu(i+1)/b.DajStranicu(j+1);
                }
            }
        }
        if(p<3)
            return false;
        a.Skaliraj(a.x[0],k);
        DaLiSuPodudarni(a,b);
    }
};
int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i=0;i<n;i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka p[3];
        double n1,n2;
        for(int k=0;k<3;k++){
            std::cin>>n1>>n2;
            p[k]=Tacka(n1,n2);
        }
        try{
            v[i]=std::make_shared<Trougao>(p[0],p[1],p[2]);
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao,k;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>k;
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,ugao,k](std::shared_ptr<Trougao>p){p->Transliraj(dx,dy); p->Rotiraj(ugao);p->Skaliraj(p->DajTjeme(1),k); return p;});
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao>p, std::shared_ptr<Trougao> k){ if(p->DajPovrsinu()<k->DajPovrsinu()) return true; return false;});
	std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> p){ p->Ispisi(); std::cout<<std::endl;});
	std::cout<<"Trougao sa najmanjim obimom: ";
	auto it(*std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> p,std::shared_ptr<Trougao>k){ if(p->DajObim()<k->DajObim())return true; return false; }));
	it->Ispisi();
	std::cout<<std::endl;
	/*Trougao a(Tacka(0,0),Tacka(0,3),Tacka(3,0));
	std::cout<<a.DajUgao(1)<<" "<<a.DajStranicu(3);*/
	
	return 0;
}