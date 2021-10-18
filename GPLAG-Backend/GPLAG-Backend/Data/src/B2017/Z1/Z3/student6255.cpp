#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

enum Smjer {Rastuci=1, Opadajuci=2};

bool DaLiJeStepenDvojke (int x)
{
    bool vrati=false;

    if(x==0)
        return false;

    if((x &(x-1))==0)
        vrati=true;
    return vrati;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer s)
{
    std::deque<std::vector<int>> r;
    std::vector <int> privr;

    int p, q, c;
    bool Podniz=false;

    if(s==Rastuci) {
        for(int i=1; i<v.size(); i++) {
            c=v.at(i);
            if(c>=v.at(i-1) && DaLiJeStepenDvojke(c) && DaLiJeStepenDvojke(v.at(i-1))) {
                Podniz=true;
                p=i-1;
                q=i;
                for(int j=i+1; j<v.size(); j++) {
                    c=v.at(j);
                    if(!(c>=v.at(j-2) && DaLiJeStepenDvojke(c) && DaLiJeStepenDvojke(v.at(j-1)))) {
                        break;
                    }
                    q=j;
                }
            }
            if(Podniz==true) {
                for(int k=p; k<=q; k++) {
                    privr.push_back(v.at(k));
                }
                r.push_back(privr);
                privr.clear();
                i=q+1;
                Podniz=false;
            }
        }
    }

    if(s==Opadajuci) {
        for(int i=1; i<v.size(); i++) {
            c=v.at(i);

            if(c<=v.at(i-1) && DaLiJeStepenDvojke(c) && DaLiJeStepenDvojke(v.at(i-1))) {
                Podniz=true;
                p=i-1;
                q=i;

                for(int j=i+1; j<v.size(); j++) {
                    c=v.at(j);

                    if(!(c<=v.at(j-1) && DaLiJeStepenDvojke(c) && DaLiJeStepenDvojke(v.at(j-1)))) {
                        break;
                    }
                    q=j;
                }
            }
            if(Podniz==true) {
                for(int k=p; k<=q; k++) {
                    privr.push_back(v.at(k));
                }
                r.push_back(privr);
                privr.clear();
                i=q+1;
                Podniz=false;
            }
        }
    }
    return r;
}

int main()
{
    std::deque<std::vector<int>> r;
    std::vector<int> v;

    int n;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    int x;
    for(int i=0; i<n; i++) {
        std::cin>>x;
        v.push_back(x);
    }
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";

    std::cin>>x;
    Smjer s = (Smjer)x;

    r=MaksimalniPodnizoviStepenaDvojke(v, s);

    if(x==1) std::cout<<"Maksimalni rastuci podnizovi: \n";
    else std::cout<<"Maksimalni opadajuci podnizovi: \n";

    for(int i=0; i<r.size(); i++) {
        for(int j=0; j<r.at(i).size(); j++) {
            std::cout<<r.at(i).at(j)<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}