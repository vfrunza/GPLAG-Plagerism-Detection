#include <iostream>
#include <vector>
typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(std::vector<double> niz){
    matrica mat;
    if(niz.size()==0)
        return mat;
    int i=0,p=0,q=0,j=0;
    do{
        if((i<niz.size()-1) and (niz[i]<=niz[i+1])){
        p=i;
        while((i<niz.size()-1) and (niz[i]<=niz[i+1])){
            i++;
        }
        q=i;
        }
        if((p!=q)){   
            mat.push_back(std::vector<double>());
            for(;p<=q;p++){
                mat[j].push_back(niz[p]);
            }
            j++;
            q=0;
            p=0;
        }
        i++;
    }while(i<niz.size()-1);
    return mat;
}

matrica OpadajuciPodnizovi(std::vector<double> niz){
    matrica mat;
    if(niz.size()==0)
        return mat;
    int i=0,p=0,q=0,j=0;
    do{
        if((i<niz.size()-1) and (niz[i]>=niz[i+1])){
        p=i;
        while((i<niz.size()-1) and (niz[i]>=niz[i+1])){
            i++;
        }
         q=i;
        }
        if((p!=q)){ 
            mat.push_back(std::vector<double>());
            for(;p<=q;p++){
                mat[j].push_back(niz[p]);
            }
            j++;
            q=0;
            p=0;
        }
        i++;
    }while(i<niz.size()-1);
    return mat;
}
        
        
int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    std::vector<double> a(n);
    std::cout<<"Unesite elemente vektora: ";
    for(auto &x : a) std::cin>>x;
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    matrica b(RastuciPodnizovi(a));
    for(int i=0; i<b.size(); i++){
        for(auto y : b[i]) {
            std::cout<<y<<" ";
        }
        
            std::cout<<std::endl;
    }
  //  std::cout<<std::endl;
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(auto x : OpadajuciPodnizovi(a)){
        for(auto y : x) 
            std::cout<<y<<" ";
        std::cout<<std::endl;
    }
	return 0;
}