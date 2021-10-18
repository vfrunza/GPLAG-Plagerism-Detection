#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;

typedef deque<vector<int>> Matrica;



bool DalJeStepen( int a)
{
    if(a<1) return false;
    while(a!=1) {
        if(a%2!=0) return false;
        a/=2;
    }
    return true;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int>a,bool neki)
{


    Matrica m;
    if (neki==1) {



        unsigned	int broj_red=0;

        int i(0);

        while(i<a.size()-1) {


            if(DalJeStepen(a.at(i))==1 && a.at(i)<=a.at(i+1) && DalJeStepen(a.at(i+1))==1) {
                broj_red++;
                while(a.at(i)<=a.at(i+1) && DalJeStepen(a.at(i))==1) {
                    i++;
                    if(i==a.size()-1) break;
                }
            }
            i++;
        }
        m.resize(broj_red);

        i=0;

        broj_red=0;

        while(i<a.size()) {

            if(i==a.size()-1 && DalJeStepen(a.at(i)==0) )break;

            if(i<a.size()-1 && DalJeStepen(a.at(i))==1  && a.at(i)<=a.at(i+1) && DalJeStepen(a.at(i+1))==1) {
                int broj_el(1);
                broj_red++;
                int j(0);
                while(DalJeStepen(a.at(i))==1  && a.at(i)<=a.at(i+1) ) {
                    broj_el++;

                    m[broj_red-1].resize(broj_el-1);
                    m.at(broj_red-1).at(j)=a.at(i);
                    j++;
                    i++;

                    if(i==a.size()-1 && DalJeStepen(a.at(i))!=1)  break;
                    if((i==a.size()-1 && a.at(i)>a.at(i-1) ) || (a.at(i)>a.at(i-1) && a.at(i)>a.at(i+1)) ) {
                        broj_el++;

                        m[broj_red-1].resize(broj_el-1);
                        m.at(broj_red-1).at(j)=a.at(i);


                        break;
                    }
                }



            }

            i++;
        }
    }

    else if(neki==0) {

        unsigned	int broj_red=0;

        int i(0);

        while(i<a.size()-1) {


            if(DalJeStepen(a.at(i))==1 && a.at(i)>=a.at(i+1) && DalJeStepen(a.at(i+1))==1) {
                broj_red++;
                while(a.at(i)>=a.at(i+1) && DalJeStepen(a.at(i))==1) {
                    i++;
                    if(i==a.size()-1) break;
                }
            }
            i++;
        }
        m.resize(broj_red);

        i=0;

        broj_red=0;

        while(i<a.size()) {

            if(i==a.size()-1 && DalJeStepen(a.at(i)==0) )break;

            if(i<a.size()-1 && DalJeStepen(a.at(i))==1  && a.at(i)>=a.at(i+1) && DalJeStepen(a.at(i+1))==1) {
                int broj_el(1);
                broj_red++;
                int j(0);
                while(DalJeStepen(a.at(i))==1 && a.at(i)>=a.at(i+1) ) {
                    broj_el++;

                    m[broj_red-1].resize(broj_el-1);
                    m.at(broj_red-1).at(j)=a.at(i);
                    j++;
                    i++;

                    if(i==a.size()-1 && DalJeStepen(a.at(i))!=1)  break;
                    if(i==a.size()-1 && a.at(i)<a.at(i-1)  || (a.at(i)<a.at(i-1) && a.at(i)<a.at(i+1)) ) {
                        broj_el++;

                        m[broj_red-1].resize(broj_el-1);
                        m.at(broj_red-1).at(j)=a.at(i);


                        break;
                    }
                }



            }

            i++;
        }
    }

    return m;
}


void Ispisi(Matrica m)
{
    for(vector<int> red: m) {
        for(int x: red) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main ()
{

    int a;
    vector<int> v;
    int n;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>a;

    cout<<"Unesite elemente vektora: ";

    for(int i=0; i<a; i++) {
        cin>>n;
        v.push_back(n);
    }

    int b;
    cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";

    cin>>b;
    if(b==1) {
        Matrica m=MaksimalniPodnizoviStepenaDvojke(v, b);
        cout<<"Maksimalni rastuci podnizovi: "<<endl;
        Ispisi(m);
    } else if(b==2) {
        Matrica m=MaksimalniPodnizoviStepenaDvojke(v, 0);
        cout<<"Maksimalni opadajuci podnizovi: "<<endl;

        Ispisi(m);
    }
    return 0;
}