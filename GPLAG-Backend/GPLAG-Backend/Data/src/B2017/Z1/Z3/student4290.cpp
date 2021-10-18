#include <iostream>
#include <vector>
#include <deque>
enum Smjer{Rastuci,Opadajuci};
bool StepenDvojke(int broj)
{
    if(broj==0) return false;
    if(broj==1) return true;
    while (broj!=1) {
        if(broj%2!=0) return false;
        broj/=2;
    }
    return true;
}
std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int>v,Smjer s)
{
    std::deque<std::vector<int>> prazan(0);
    std::deque<std::vector<int>>d_rastuci;
    if(s==Rastuci&&v.size()!=0) {
        bool t(false);
        int j(0);
        v.push_back(0);
        std::vector<int>rastuci;
        for(int i(0); i<v.size(); i++) {
            if(j==v.size()-1) break;
            j=i+1;
            if(v.at(j)>=v.at(i)&&StepenDvojke(v.at(i))&&StepenDvojke(v.at(j))) {
                rastuci.push_back(v.at(i));
                t=true;
            } else {
                if(t) rastuci.push_back(v.at(j-1));
                if(rastuci.size()!=0) d_rastuci.push_back(rastuci);
                rastuci.resize(0);
                t=false;
            }
        }
        v.resize(v.size()-1);
        return d_rastuci;
    }
    std::deque<std::vector<int>>d_opadajuci ;
    if(s==Opadajuci&&v.size()!=0) {
        bool t(false);
        int j(0);
        std::vector<int>opadajuci;
        v.push_back(0);
        for(int i(0); i<v.size(); i++) {
            if(j==v.size()-1) break;
            j=i+1;
            if(v.at(j)<=v.at(i)&&StepenDvojke(v.at(i))&&StepenDvojke(v.at(j))) {
                opadajuci.push_back(v.at(i));
                t=true;
            } else {
                if(t) opadajuci.push_back(v.at(j-1));
                if(opadajuci.size()!=0) d_opadajuci.push_back(opadajuci);
                opadajuci.resize(0);
                t=false;
            }
        }
        v.resize(v.size()-1);
        return d_opadajuci;
    }
    return prazan;
}
int main ()
{
    std::vector<int>v ;
    std::deque<std::vector<int>>d ;
    Smjer s;
    std::cout << "Unesite broj elemenata vektora: ";
    int br_elemenata;
    std::cin >> br_elemenata;
    std::cout << "Unesite elemente vektora: ";
    int broj;
    for(int i(0); i<br_elemenata; i++) {
        std::cin >> broj;
        v.push_back(broj);
    }
    std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    int izbor;
    std::cin >> izbor;
    if(izbor==2) {
        d=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
        std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
        for(int i=0; i<d.size(); i++) {
            for(int j=0; j<d.at(i).size(); j++)
                std::cout << d.at(i).at(j) <<" ";
            std::cout  << std::endl;
        }
    }
    if(izbor==1) {
        d=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
        std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
        for(int i(0); i<d.size(); i++) {
            for(int j(0); j<d.at(i).size(); j++)
                std::cout << d.at(i).at(j) <<" ";
            std::cout  << std::endl;
        }
    }
    return 0;
}