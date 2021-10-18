#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

enum Smjer {Rastuci, Opadajuci};

bool StepenDvojke(int n)
{
    for(int i=0; i<n; i++)
        if((int)(round)(pow(2, i))==n)
            return true;
    return false;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer s)
{
    deque<vector<int>> d;
    int brojac_vektora(0), j(0);
    if(s==Rastuci) {
        for(int i=0; i<(int)v.size()-1; i++) {
            if(v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
                j=0;
                brojac_vektora++;
                do {
                    j++;
                    d.resize(brojac_vektora);
                    d.at(brojac_vektora-1).resize(j);
                    d.at(brojac_vektora-1).at(j-1)=v.at(i);
                    i++;
                } while(i<(int)v.size()-1 && v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)));
                if(StepenDvojke(v.at(i)) && v.at(i)>=v.at(i-1)) {
                    d.at(brojac_vektora-1).resize(j+1);
                    d.at(brojac_vektora-1).at(j)=v.at(i);
                }
            }
        }
    } else if(s==Opadajuci) {
        for(int i=0; i<(int)v.size()-1; i++) {
            if(v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
                j=0;
                brojac_vektora++;
                do {
                    j++;
                    d.resize(brojac_vektora);
                    d.at(brojac_vektora-1).resize(j);
                    d.at(brojac_vektora-1).at(j-1)=v.at(i);
                    i++;
                } while(i<(int)v.size()-1 && v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)));
                if(StepenDvojke(v.at(i)) && v.at(i)<=v.at(i-1)) {
                    d.at(brojac_vektora-1).resize(j+1);
                    d.at(brojac_vektora-1).at(j)=v.at(i);
                }
            }
        }
    }
    return d;
}

int main ()
{
    deque<vector<int>> d;
    vector<int> v;
    int n, a;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>n;
    v.resize(n);
    cout<<"Unesite elemente vektora: ";
    for(int i=0; i<n; i++) {
        cin>>a;
        v.at(i)=a;
    }
    cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    cin>>a;
    if(a==1) {
        d=MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
        cout<<"Maksimalni rastuci podnizovi: ";
    } else if(a==2) {
        d=MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
        cout<<"Maksimalni opadajuci podnizovi: ";
    }
    cout<<endl;
    for(int i=0; i<d.size(); i++) {
        for(int j=0; j<d.at(i).size(); j++)
            cout<<d.at(i).at(j)<<" ";
        cout<<endl;
    }
    return 0;
}