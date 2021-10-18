#include <iostream>
#include <vector>
#include <deque>

std::deque<int> KonverzijaUGadne(int n){
    std::deque<int> d;
    while(n > 0){
        d.push_front(n%3);
        n/=3;
    }
    return d;
}

std::vector<int> IzbaciVisak(std::vector<int> v){
    for(unsigned int i(0); i< v.size(); i++){
         for(unsigned int j(0); j < v.size(); j++){
             if(j!=i && v[i]==v[j]){
              v.erase(v.begin() + j);
              j--;
             }
         }
    }
    return v;
}

int DaLiJeGadan(std::deque<int> d ){
    bool par(false), nepar(false);
    for(unsigned int i(0); i< d.size(); i++){
        int broj(0);
        for(unsigned j(0); j<d.size(); j++){
            if(d[j]==d[i]) broj++;
        }
        if(broj%2!=0) nepar = true;
        if(broj%2 == 0) par = true;
    }
    if (par&&nepar) return 1;
    if(par) return 2;
    return 3;
    
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool flag){
	std::vector<int> odvratan, zao;
	for(unsigned int i(0); i < v.size(); i++){
	    unsigned int temp;
	    if(v[i]<0)  temp = v[i]*(-1);
	    else temp = v[i];
	    if(temp == 0) 
	        odvratan.push_back(v[i]);
	        continue;
	    }
	    else{
	        std::deque<int> d = KonverzijaUGadne(temp);
	        int lol = DaLiJeGadan(d);
	        if(lol == 2) zao.push_back(v[i]);
	        else if (lol == 3) odvratan.push_back(v[i]);
	        else continue;
	    }
	    
	}
	
	if(flag) return IzbaciVisak(zao);
	return IzbaciVisak(odvratan);
}

int main ()
{
    std::vector<int> v;
    std:: cout<<"Unesite brojeve (0 za prekid unosa): ";
    while(1){
        int broj;
        std::cin >> broj;
        if(broj==0)break;
        v.push_back(broj);
    }
    std::vector<int> opaki = IzdvojiGadne(v, true), odvratni = IzdvojiGadne(v, false);
    std::cout << "Opaki: ";
    for(int i : opaki) std::cout<<i<< " ";
    std::cout  << std::endl;
    std::cout<<"Odvratni: ";
    for(int i : odvratni) std::cout << i << " ";
	return 0;
}