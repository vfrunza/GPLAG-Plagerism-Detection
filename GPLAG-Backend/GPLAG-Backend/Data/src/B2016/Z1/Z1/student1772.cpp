#include <iostream> 
#include <vector>
#include <cmath>

int BrojOstataka(int n){
    int br=0;
    while(n!=0){
        n=n/3;
        br++;
    }
    return br;
}
std::vector<int>IzdvojiGadne(std::vector<int>g,bool Gadni){
    std::vector<int>odvratni;
    std::vector<int>opaki;
    for(int i=0;i<g.size();i++){
     int a=abs(g[i]);
    int b;
    std::vector<int>ostaci;
    while(a!=0){
        for(int j=0;j<BrojOstataka(a);j++){
            b=a%3;
            ostaci.push_back(b);
        a=a/3;
    }
    }
    std::vector<int>n,p,q;
    for(int k=0;k<ostaci.size();k++){
        if(ostaci[k]==0){
        n.push_back(ostaci[k]);    
        }
        if(ostaci[k]==1){
            p.push_back(ostaci[k]);
        }
        if(ostaci[k]==2){
        q.push_back(ostaci[k]);
        }
    }
    if((n.size()%2==0 || n.size()==0) && (p.size()%2==0 || p.size()==0) && (q.size()%2==0 || q.size()==0)){
        opaki.push_back(g[i]);
    }
    if((n.size()%2!=0 || n.size()==0) && (p.size()%2!=0 || p.size()==0) && (q.size()%2!=0 || q.size()==0)){
    odvratni.push_back(g[i]);
    }
    }
    bool Pp(true);
    if(opaki.size()==0)
    Pp=false;
    if(Pp==true){
    for(int i=0;i<opaki.size()-1;i++){
        for(int j=i+1;j<opaki.size();j++){
            if(opaki[i]==opaki[j]){
                opaki.erase(opaki.begin()+j);
                j--;
            }
        }
    }
    }
    bool Dp(true);
    if(odvratni.size()==0)
    Dp=false;
    if(Dp==true){
    for(int i=0;i<odvratni.size()-1;i++){
        for(int j=i+1;j<odvratni.size();j++){
            if(odvratni[i]==odvratni[j]){
                odvratni.erase(odvratni.begin()+j);
                j--;
            }
        }
    }
    }
    if(Gadni){
    return opaki;
    }
    else
    return odvratni;
}
int main ()
{
    std::vector<int>v;
    std::vector<int>op;
    std::vector<int>od;
    int n;
    std::cout <<"Unesite brojeve (0 za prekid unosa): ";
    do{
        std::cin>>n;
        if(n!=0)
        v.push_back(n);
    }while(n!=0);
    od=IzdvojiGadne(v,false);
    op=IzdvojiGadne(v,true);
    std::cout<<"Opaki: ";
    for(int i=0;i<op.size();i++){
        std::cout<<op[i];
        std::cout<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Odvratni: ";
    for(int i=0;i<od.size();i++){
        std::cout<<od[i];
        std::cout<<" ";
    }
	return 0;
}