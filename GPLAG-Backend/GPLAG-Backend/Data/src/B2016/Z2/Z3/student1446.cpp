#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector < std::vector < std::vector < double > > > niz;
typedef std::vector < std::vector <double> > Mat;
 int Faktorijel(int n, int k) {
 if(n < 0) throw std::domain_error ("Neispravni parametri!");
 int p(1);
 for(int i = n; i >n-k ; i--) p *= i;
 return p;
}
 int NewtonovBinomniKoeficijent(int n, int k) {
 try {
 return Faktorijel(n,k) / (Faktorijel(k,k));
 }
 catch(std::domain_error rere) {
 throw std::domain_error ("Neispravni parametri!");
 }
}
int PascalovTrougao (int m, int n ){
    Mat a;
    a.resize(m);
    for(int i=0;i<m;i++){
        a[i].resize(i+1);
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<=i; j++){
            if(j==0){
                a[i][j]=1;
            }    
            else 
                if(j==i){
                    a[i][j]=1;
                }    
            else{
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }    
        }
    }
    return a[m-1][n-1];
}
template<typename tip, typename dnesto>
tip Izmijeni3dKontejner(dnesto &d,tip fun(int,int),int p=0,int q=0){
    tip x=fun(p,q);
    try{
    bool tmp(false);
    for(int i=0; i<d.size(); i++){
        for(int j=0; j<d[0].size();j++){
            for(int k=0;k<d[0][0].size();k++){
                if(d[i][j][k]==x){
                    tmp=true;
                }
            }
        }
    }
    if(tmp==false)throw std::range_error ("Nije pronadjen broj");
    else{
        for(int i=0; i<d.size(); i++){
        for(int j=0; j<d[0].size();j++){
            for(int k=0;k<d[0][0].size();k++){
                if(d[i][j][k]==x)
                    d[i][j][k]=x*x;
            }
        }
    }
    }
    return x;
    }
    catch(std::range_error greska){
        std::cout<<greska.what();
    }
}
int main()
{
    try{
    std::cout<<"Unesite dimenzije 3D kontejnera: ";
    int visina,sirina,duzina;
    std::cin>>visina>>sirina>>duzina;
    niz v;
    for(int i=0; i<visina; i++){
        v.resize(visina);
        for(int j=0; j<sirina; j++){
            v[i].resize(sirina);
            for(int k=0; k<duzina; k++){
                v[i][j].resize(duzina);
            }
        }
    }
    std::cout<<"Unesite elemente: ";
    for(int i=0; i<visina; i++){
            for(int j=0; j<sirina; j++){
                for(int k=0; k<duzina; k++){
                    double x;
                    std::cin>>x;
                    v[i][j][k]=x;
                }
            }
    }
    int p,q;
    std::cout<<"Unesite brojeve p i q: ";
    std::cin>>p>>q;
    int l=Izmijeni3dKontejner(v, PascalovTrougao , p, q);
    std::cout<<"Kontejner nakon zamjene broja "<<l<<" brojem "<<l*l << " glasi: "<<std::endl;
      for(int i=0; i<visina; i++){
            for(int j=0; j<sirina; j++){
                for(int k=0; k<duzina; k++){
                    std::cout<<std::setw(4)<<std::left<<v[i][j][k]<<" ";
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;
    }
}

    catch(std::domain_error poruka) {
 std::cout << poruka.what() << std::endl;
    }
    return 0;
}


