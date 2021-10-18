#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
enum Smjer {Rastuci=1,Opadajuci};

bool Stepen(int n)
{
    double x=log(n)/log(2);
    if (x==round(x)) return true;
    else if (x<0) return false;
    else return false;
}


std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v,Smjer s)
{
    int i;
    std::deque<std::vector<int>> dek;
    if (s==Rastuci) {
        for (i=0; i<v.size(); i++) {
            std::vector<int> v1;
            if (v.at(i)==1 || Stepen(v.at(i))==true) {
                while (1) {
                    i++;
                    if (v.size()<=i) break;
                    if (v.at(i)==0 || v.at(i-1)==0) continue;
                    if (v.at(i-1)<=v.at(i) && Stepen(v.at(i))==true && v1.size()==0) {
                        v1.push_back(v.at(i-1));
                        v1.push_back(v.at(i));
                    } else if (v.at(i-1)<=v.at(i) && Stepen(v.at(i))==true) v1.push_back(v.at(i));
                    else if (v.at(i-1)<=v.at(i) && Stepen(v.at(i))==true && Stepen(v.at(i-2))==false && Stepen(v.at(i-1))==true) {
                        v1.push_back(v.at(i-1));
                        v1.push_back(v.at(i));
                    } else {
                        i--;
                        break;
                    }
                }
            }
            if (v1.size()!=0) dek.push_back(v1);
        }
        return dek;
    } else if (s==Opadajuci) {
        for (i=0; i<v.size(); i++) {
            std::vector<int> v1;
            if (v.at(i)==1 || Stepen(v.at(i))==true) {
                while (1) {
                    i++;
                    if (v.size()<=i) break;
                    if (v.at(i)==0 || v.at(i-1)==0) continue;
                    if (v.at(i-1)>=v.at(i) && Stepen(v.at(i))==true && v1.size()==0) {
                        v1.push_back(v.at(i-1));
                        v1.push_back(v.at(i));
                    } else if (v.at(i-1)>=v.at(i) && Stepen(v.at(i))==true) v1.push_back(v.at(i));
                    else if (v.at(i-1)>=v.at(i) && Stepen(v.at(i))==true && Stepen(v.at(i-2))==false && Stepen(v.at(i-1))==true) {
                        v1.push_back(v.at(i-1));
                        v1.push_back(v.at(i));
                    } else {
                        i--;
                        break;
                    }
                }
            }
            if (v1.size()!=0) dek.push_back(v1);
        }
        return dek;
    }
}





int main ()
{
    std::deque<std::vector<int>> dek;
    int n,x;
    int y;
    Smjer s;
    std::vector<int> vektor;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    while (vektor.size()!=n) {
        std::cin>>x;
        vektor.push_back(x);
    }
    std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin>>y;
    s=Smjer(y);
    dek=MaksimalniPodnizoviStepenaDvojke(vektor,s);
    if (s==Rastuci) {
        std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
        for (int j=0; j<dek.size(); j++) {
            for (int k=0; k<dek.at(j).size(); k++) {
                std::cout<<dek.at(j).at(k)<<" ";
            }
            std::cout<<std::endl;
        }
    } else if (s==Opadajuci) {
        std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
        for (int j=0; j<dek.size(); j++) {
            for (int k=0; k<dek.at(j).size(); k++) {
                std::cout<<dek.at(j).at(k)<<" ";
            }
            std::cout<<std::endl;
        }
    }

    return 0;
}