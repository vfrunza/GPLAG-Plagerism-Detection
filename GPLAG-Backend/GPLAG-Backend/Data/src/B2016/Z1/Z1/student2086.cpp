#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> Konvertuj(long long int a){
    std::vector<int> broj;
    for(int i=0; i<sqrt(a); i++){
        if(pow(3,i)==a){
            for(int k=0; k<=i; k++){
                if(k==0){
                    broj.push_back(1);
                    continue;
                }
                broj.push_back(0);
            }
            return broj;
        }
        if(i==sqrt(a)) break;
    }
    int cifra;
    
    int j=0;
    bool k(false);
    for(int i=0;;i++){
        if(pow(3,i)>a){
            i--;
            if(k)
            while(i!=j-1){
                broj.push_back(0);
                j--;
            }
            cifra=(a/int(pow(3,i)));
            broj.push_back(cifra);
            a-=cifra*pow(3,i);
            j=i;
            k=true;
            i=0;
        }
        if(a<=0) break;
    }
     while(j>0){
            broj.push_back(0);
            j--;
        }
    return broj;
}
std::vector<int> IzdvojiGadne(std::vector<int> a, bool logicka){
    std::vector<int> novi;
    if(logicka)
    for(auto x : a){
        std::vector<int> s(Konvertuj(std::abs((long long int)x)));
        //std::cout<<s<<s.size();
        std::vector<bool> b(3,true);
        for(int i=0; i<s.size(); i++){
            if(s[i]==0){
                b[0]=(!b[0]);
          //      std::cout<<b[0];
                continue;
            }
            if(s[i]==1){
                b[1]=(!b[1]);
            //    std::cout<<b[1];
                continue;
            }
            if(s[i]==2){
                b[2]=(!b[2]);
              //  std::cout<<b[2];
            }
            if(i==s.size()) break;
        }
        //for(auto x : b) std::cout<<x<<", ";
        if((b[0]) and (b[1]) and (b[2])){
            novi.push_back(x);
        }
    }
    else
     for(auto x : a){
        std::vector<int> s(Konvertuj(std::abs((long long int)x)));
    //    std::cout<<s<<s.size();
        std::vector<bool> b(3,false);
        std::vector<int> pomoc(3,0);
        for(int i=0; i<s.size(); i++){
            if(s[i]==0){
                b[0]=(!b[0]);
                pomoc[0]++;
              //  std::cout<<b[0];
                continue;
            }
            if(s[i]==1){
                b[1]=(!b[1]);
                pomoc[1]++;
            //    std::cout<<b[1];
                continue;
            }
            if(s[i]==2){
                b[2]=(!b[2]);
                pomoc[2]++;
          //      std::cout<<b[2];
            }
            if(i==s.size()) break;
        }
        //for(auto x : b) std::cout<<x<<", ";
        if(pomoc[0]==0) b[0]=true;
        if(pomoc[1]==0) b[1]=true;
        if(pomoc[2]==0) b[2]=true;
        if(((b[0]) and (b[1]) and (b[2]))){
            novi.push_back(x);
        }
    }
    //std::cout<<novi.size();
    for(int i=0; i<int(novi.size())-1; i++){
        for(int j=i+1; j<novi.size(); j++){
            if(novi[i]==novi[j]){
                novi.erase(novi.begin()+j);
                j--;
            }
            if(j==novi.size()) break;
        }
        if(i==int(novi.size())-1) break;
    }
    return novi;
}

int main ()
{
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    std::vector<int> a;
    for(;;){
        int x;
        std::cin>>x;
        if(!x) break;
        else a.push_back(x);
    }
    std::cout<<"Opaki: ";
    for(auto x : IzdvojiGadne(a,true)) std::cout<<x<<" ";
    std::cout<<std::endl<<"Odvratni: ";
    for(auto x : IzdvojiGadne(a,false)) std::cout<<x<<" ";
  /*   int y;
    std::cin>>y;
    for(auto x : Konvertuj(y)) std::cout<<x<<" "; */
	return 0;
}