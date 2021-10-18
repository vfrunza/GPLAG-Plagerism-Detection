#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> IzdvojiGadne(std::vector<int>v, bool r){
        std::vector<int>a;
        std::vector<int>b;
        std::vector<int>h;
        int c,n,x,d,p,brojac(0),brojac1(0),brojac2(0),brojac0(0);
        for(int i=0; i<v.size()-1; i++){
            for(int j=1+i; j<v.size(); j++){
                if((v[i])==(v[j])){
                    v.erase(v.begin()+j);
                    j--;
                }
            }
        }
        for(int i=0; i<v.size(); i++){
                x = v[i];
                n = v[i];
                p = v[i];
            while(n!=0){
                n = n/3;
                if(n==0) break;
                brojac++;
            }
            while(brojac>=0){
                c= x/(pow(3,brojac));
                if(c==0){
                    brojac0++;
                    a.push_back(c);
                }else if(c==1 || c==-1){
                    brojac1++;
                    a.push_back(c);
                }else if(c==2 || c==-2){
                    brojac2++;
                    a.push_back(c);
                }
                d=c*(pow(3,brojac));
                x = x-d;
                brojac--;
            }
            
        
                if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0){b.push_back(p);}
                if((brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0)) {h.push_back(p);}
                    brojac = 0;
                    a = std::vector<int>(0);
                    brojac0 = 0;
                    brojac1 = 0;
                    brojac2 = 0;
                }
        
        if(r)  return b;
        else return h;
}

int main(){
    int broj;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    std::vector<int>v;
    do{
        std::cin>>broj; 
        if(broj==0) break;
        v.push_back(broj);
    }while(broj!=0);
    std::vector<int> p;
    std::vector<int>r;
    bool a(true);
    bool b(false);
    p = IzdvojiGadne(v,a); 
    std::cout<<"Opaki: ";
        for(int i=0; i<p.size(); i++){
            std::cout<<p[i]<<" ";
        }
    std::cout<<std::endl;
    std::cout<<"Odvratni: ";
    r = IzdvojiGadne(v,b);
        for(int i=0; i<r.size(); i++){
            std::cout<<r[i]<<" ";
        }
    return 0;
}