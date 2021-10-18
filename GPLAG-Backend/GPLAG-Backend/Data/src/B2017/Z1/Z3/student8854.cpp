/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/

#include <iostream>
#include <deque>
#include <vector> 

enum Smjer {Rastuci, Opadajuci} ;

bool DaLiJeStepenDvojke (int n){
    if (n<=0) return false;
    if (n==1) return true;
    long long int stepeni_dvojke {2};
    while (stepeni_dvojke<n){
        stepeni_dvojke*=2;
    }
    if (n==stepeni_dvojke) 
        return true;
    return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer smjer){
    std::deque<std::vector<int>> mati;
    int red{0};
    mati.resize(1);
    if (smjer==Smjer::Rastuci){
        for (int i {0}; i<int(v.size())-1; i++){
            while (i<v.size()-1 && v.at(i)<v.at(i+1) && DaLiJeStepenDvojke(v.at(i))){
                mati.at(red).push_back(v.at(i));
                i++;
            }
            
            if (mati.at(red).size() > 0){
                if (DaLiJeStepenDvojke(v.at(i))) mati.at(red).push_back(v.at(i));
                if (mati.at(red).size()>1){
                    mati.resize(mati.size()+1);
                    red++;
                }
                else 
                    mati.at(red).resize(0);
            }
        }
    }
    
    else if (smjer == Smjer::Opadajuci) {
        red=0;
        for (int i {0};i<int(v.size())-1;i++){
            while (i<v.size()-1 && v.at(i)>v.at(i+1) && DaLiJeStepenDvojke(v.at(i))){
                mati.at(red).push_back(v.at(i));
                i++;
            }
            if (mati.at(red).size()>0){
                if (DaLiJeStepenDvojke(v.at(i))) mati.at(red).push_back(v.at(i));
                if (mati.at(red).size()>1){
                    mati.resize(mati.size()+1);
                    red++;
                }
                else {
                    mati.at(red).resize(0);
                }
            }
        }
    }
    return mati;
}

int main (){
    std::vector<int> v;
    int broj;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>broj;
    v.resize(broj);
    std::cout<<"Unesite elemente vektora: ";
    for (int i {0}; i<broj; i++)
        std::cin>>v.at(i);
    
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int jedan_ili_dva;
    std::cin>>jedan_ili_dva;
    std::deque<std::vector<int>> m;
    if (jedan_ili_dva==1)
        m=MaksimalniPodnizoviStepenaDvojke(v,Smjer::Rastuci);
    else if (jedan_ili_dva==2)
        m=MaksimalniPodnizoviStepenaDvojke(v,Smjer::Opadajuci);
    if (jedan_ili_dva==1){
        std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
        for (int i {0}; i < m.size();i++){
            for (int j {0}; j<m.at(i).size();j++){
                std::cout<<m.at(i).at(j)<<" ";
            }
            std::cout<<std::endl;
        }
    }
    else {
        std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
        for (int i {0};i<m.size();i++){
            for (int j {0};j<m.at(i).size();j++){
                std::cout<<m.at(i).at(j)<<" ";
            }
            std::cout<<std::endl;
        }
    }


	return 0;
}