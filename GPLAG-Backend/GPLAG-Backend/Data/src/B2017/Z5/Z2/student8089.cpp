/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>

class Mjere {
    int jardi,stope,inchi;
    
    public:
    
    Mjere(int jardi, int stope, int inchi) : jardi(jardi), stope(stope), inchi(inchi) {}
    Mjere(int metri) {
        int centimetri(metri*100);
        inchi = centimetri/2.54;
    }
    void Postavi(int j, int s, int i) {
        if(inchi<0 || inchi>11 || stope<0 || stope>2) throw std::domain_error("Parametri nisu u dozvoljenom opsegu!");
        j=jardi; s=stope; i=inchi;
    }
    int DajDuzinuUMetrima() {
        double temp(0);
        temp=jardi*3;
        temp=temp*12;
        temp*=2.54;
        return temp/100;
    }
    
    int DajJarde() const {return jardi;}
    int DajStope() const {return stope;}
    int DajInche() const {return inchi;}
    
    friend Mjere operator +(const Mjere &m1, const Mjere &m2) {
         if(m1.stope<0 || m2.stope<0 || m1.inchi<0 || m2.inchi<0 || m1.stope>2 || m2.stope>2 || m1.inchi>11 || m2.inchi>11) throw std::domain_error("Neispravne duzine");
        return {m1.jardi+m2.jardi,m1.stope+m2.stope,m1.inchi+m2.inchi};
    }
    friend Mjere &operator +=(Mjere &m1, const Mjere &m2) {
        m1.jardi=m1.jardi+m2.jardi;
        m1.stope=m1.stope+m2.stope;
        m1.inchi=m1.inchi+m2.inchi;
        if(m1.stope > 2 || m1.inchi > 11) throw std::domain_error("Van opsega!"); 
        return m1;
    }
    friend Mjere &operator ++(Mjere &m,int){
        m.inchi=m.inchi+1;
        return m;
    }
    friend Mjere operator ++(Mjere &m){
        Mjere postfiks(m);
        m.inchi++;
        return postfiks;
    }
    friend Mjere operator *(Mjere &m, double d) {
        double duzina;
        duzina=m.jardi*3*12+m.stope*3+m.inchi;
        duzina=duzina*d;
        return duzina;
        
    }
    friend Mjere operator *(double d, Mjere &m){
        long int duzina;
        duzina=m.jardi*3*12+m.stope*3+m.inchi;
        duzina=duzina*d;
        return duzina;
    }
    friend Mjere operator /(const Mjere &m1, const Mjere &m2) {
        double duzina1(m1.jardi*3*12+m1.stope*3+m1.inchi),duzina2(m2.jardi*3*12+m2.stope*3+m2.inchi);
        return duzina1/duzina2;
    }
    friend std::ostream &operator <<(std::ostream &tok, const Mjere &m){
       return tok<<m.DajJarde()<<" yd "<<m.DajStope()<<" ft "<<m.DajInche()<<" in"<<std::endl;
    }
};

int main ()
{
    try{
    Mjere m1(1,2,7);
    Mjere m2(12);
    std::cout<<m1<<std::endl;
    Mjere m3(0,1,4);
    m2++;
    std::cout<<m3<<std::endl;
    m1+=m2;
    std::cout<<m1<<std::endl;
    }catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}
