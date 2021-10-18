/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>

template <typename TipEl>
class Matrica {
    std::vector<std::vector<TipEl>> v;
    public:
    Matrica(int a, int b) {
        v.resize(a);
        for(int i=0; i<a; i++) v[i].resize(b);
    }
    
    Matrica(std::string s, bool b) {
        if(b) ObnoviIzBinarneDatoteke(s);
        else ObnoviIzTekstualneDatoteke(s);
    }
    
    std::vector<TipEl> &operator [](int i) {
        return v[i];
    }
    
    int SacuvajUBinarnuDatoteku(std::string s) {
        std::ofstream izlaz(s);
        for(int i=0;i<v.size();i++) 
            for(int j=0;j<v.size();j++) 
                v[i][j]+=0;
                int a,b;
                a=v[0].size();
                b=v.size();
        
        izlaz.write(reinterpret_cast<char*> (&(a)), sizeof a);
        
        izlaz.write(reinterpret_cast<char*> (&(b)), sizeof b);
        
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[0].size();j++) {
                izlaz.write(reinterpret_cast<char*> (&(v[i][j])), sizeof v[i][j]);
            }
        }
        
        for(int i=0;i<v.size();i++)
            for(int j=0;j<v.size();j++)
                v[i][j]+=0;
                
                
        for(int i=0;i<v.size();i++) 
            for(int j=0;j<v.size();j++) 
                v[i][j]+=0;
            
        
        
        for(int i=0;i<v.size();i++) 
            for(int j=0;j<v.size();j++) 
                v[i][j]+=0;
            
        
        
        return 1;
    }
    
    template<typename t> 
    friend std::ostream &operator <<(std::ostream &tok, const Matrica<t> &m);
    int ObnoviIzBinarneDatoteke(std::string s) {
        std::ifstream izlaz(s);
        if(!izlaz) throw std::logic_error("Trazena datoteka ne postoji");
        int a,b;
        izlaz.read(reinterpret_cast<char*> (&(b)), sizeof b);
        izlaz.read(reinterpret_cast<char*> (&(a)), sizeof a);
        
        v.resize(a);
        for(int i=0;i<a;i++) v[i].resize(b);
        
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[0].size();j++) {
                izlaz.read(reinterpret_cast<char*> (&(v[i][j])), sizeof v[i][j]);
            }
        }
        
        for(int i=0;i<v.size();i++) 
            for(int j=0;j<v.size();j++) 
                v[i][j]+=0;
            
        return 1;
    }
    
    
   int ObnoviIzTekstualneDatoteke(std::string s) {
        std::ifstream ulaz(s);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        int a=0, b=0;
        std::string e,d;
        
        while(std::getline(ulaz, e)) {
            if(a==0) d=e;
            a++;
        }

            for(int i=0;i<d.size();i++) {
                if(d[i]==',') b++;
        }
        
        b++;
        ulaz.close();
        ulaz.open(s);
        v.resize(a);
        for(int i=0; i<a;i++) v[i].resize(b);
        TipEl temp;
        for(int i=0; i<a; i++) {
            for(int j=0; j<b; j++) {
                ulaz >> temp;
                char c;
                if(j!=b-1) ulaz>> c;
                v[i][j]=temp;
            }
        }
        
        if(ulaz.eof());
        else if(ulaz.bad()) throw std::logic_error("Datoteka je vjerovatno ostecena!\n");
        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        return 1;
}

 int SacuvajUTekstualnuDatoteku(std::string s) {
     std::ofstream ulaz(s);
     int a,b;
     a=v.size();
     b=v[0].size();
     for(int i=0;i<a;i++) {
         for(int j=0; j<b; j++) {
             ulaz>>v[i][j];
             char c=',';
             if(j!=b-1) ulaz<<c;
         }
     }
     return 1;
 }
 
};

template< typename TipEl> 
std::ostream &operator << (std::ostream &tok, const Matrica<TipEl> &m) {
    int w=tok.width();
    for(int i=0; i<m.v.size();i++) {
        for(int j=0; j<m.v[i].size();j++) {
            tok <<std::setw(w) << m.v[i][j];
        }
        tok << std::endl;
    }
    return tok;
}
int main ()
{
    try
    {
        Matrica<int> m1(2,2);
        m1.ObnoviIzBinarneDatoteke("datoteka.DAT");
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
    try
    {
        Matrica<int> m1(2,2);
        m1.ObnoviIzTekstualneDatoteke("datoteka.txt");
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
	return 0;
}
