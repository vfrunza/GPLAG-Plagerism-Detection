#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

enum Smjer {Opadajuci, Rastuci};

bool StepenDvojke(int n)
{
    if(n<1) return false;
    for(int i=0; i<30; i++)
        if(std::fabs(std::pow(2,i)-n)<0.000001) return true;
    return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s)
{
    std::deque<std::vector<int>> dek;
    int br(0);
    std::vector<int> tmp;
    for(int i=0; i<v.size(); i++) {
        if(StepenDvojke(v.at(i))) {
            while(i<v.size() && StepenDvojke(v.at(i))) {
                if(s==Rastuci) {
                    if(br==0 || (br>0 && tmp.at(br-1)<=v.at(i))) {
                        tmp.push_back(v.at(i));
                        br++;
                        i++;
                    } else {
                        if(tmp.size()>1) dek.push_back(tmp);
                        tmp.resize(0);
                        br=0;
                    }
                } else if(s==Opadajuci) {
                    if(br==0 || (br>0 && tmp.at(br-1)>=v.at(i))) {
                        tmp.push_back(v.at(i));
                        br++;
                        i++;
                    } else {
                        if(tmp.size()>1) dek.push_back(tmp);
                        tmp.resize(0);
                        br=0;
                    }
                }
            }
            br=0;
            if(tmp.size()!=1) dek.push_back(tmp);
            tmp.resize(0);
        }
    }
    return dek;
}

int main ()
{
    int n, smjer;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    std::vector<int> v(n);
    for(int i=0; i<n; i++) std::cin>>v.at(i);
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin>>smjer;
    if(smjer==1) {
        std::deque<std::vector<int>> rastuci=MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
        std::cout<<"Maksimalni rastuci podnizovi:"<<std::endl;
        for(int i=0; i<rastuci.size(); i++) {
            for(int x : rastuci.at(i)) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
    }
    else if(smjer==2) {
        std::deque<std::vector<int>> opadajuci=MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
        std::cout<<"Maksimalni opadajuci podnizovi:"<<std::endl;
        for(int i=0; i<opadajuci.size(); i++) {
            for(int x : opadajuci.at(i)) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
    }
    return 0;
}