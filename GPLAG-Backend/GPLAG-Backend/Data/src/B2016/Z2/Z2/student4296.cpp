#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <deque>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::deque;
enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Tip>
auto IzdvojiDijagonale3D(Tip c,SmjerKretanja smjer) -> typename std::remove_reference<decltype(c.at(0))>::type {
    typename std::remove_reference<decltype(c.at(0))>::type V;
    if(c.size()==0 ) return V;
    else if(c.at(0).size()==0) return V;
    else if(c.at(0).at(0).size()==0) return V;
    bool izuzetak=false;
    for(int i=0; i<int(c.size()); i++) {
        for(int j=0; j<c[i].size(); j++)
            if(c.at(0).at(0).size()!=c[i][j].size())
                izuzetak=true;
    }
    if(izuzetak) throw std::domain_error ("Redovi nemaju isti broj elementa");
    izuzetak=false;
    for(int i=0; i<int(c.size()); i++) {
        if(c.at(0).size()!=c[i].size())
            izuzetak=true;
    }
    if(izuzetak) throw std::domain_error ("Plohe nemaju isti broj redova");
    if(smjer==SmjerKretanja::NaprijedNazad) {
        int x(c.size()),y(c.at(0).size()), z(c.at(0).at(0).size());
        V.resize(x);
        for(int i=0; i<x; i++)
            for(int j=0; j<y; j++)
                for(int k=0; k<z; k++)
                    if(j==k)
                        V.at(i).push_back(c.at(i).at(j).at(k));
    } else if(smjer==SmjerKretanja::NazadNaprijed) {
        int x(c.size()),y(c.at(0).size()), z(c.at(0).at(0).size());
        V.resize(x);
        int l {};

        for(int i=x-1; i>=0; i--) {
            for(int j=0; j<y; j++)
                for(int k=z-1; k>=0; k--)
                    if(j+k==z-1)
                        V.at(l).push_back(c.at(i).at(j).at(k));
            l++;
        }
    } else if(smjer==SmjerKretanja::DesnoLijevo) {
        int x(c.size()),y(c.at(0).size()), z(c.at(0).at(0).size());
        V.resize(z);
        int l {};
        for(int k=z-1; k>=0; k--) {
            int j=0;
            while(j<x && j<y) {
                V.at(l).push_back(c.at(j).at(j).at(k));
                j++;
            }
            l++;
        }
    }

    else if(smjer==SmjerKretanja::LijevoDesno) {
        int x(c.size()),y(c.at(0).size()), z(c.at(0).at(0).size());
        V.resize(z);
        int l {};
        for(int k=0; k<z; k++) {
            int i=x-1;
            int j=0;
            while(i>=0 && j<y) {
                V.at(l).push_back(c.at(i).at(j).at(k));
                i--;
                j++;
            }
            l++;
        }
    } else if(smjer==SmjerKretanja::DoljeGore) {
        int x(c.size()),y(c.at(0).size()), z(c.at(0).at(0).size());
        V.resize(y);
        int l {};
        for(int j=y-1; j>=0; j--) {
            int i=x-1;
            int k=z-1;
            while(i>=0 && k>=0) {
                V.at(l).push_back(c.at(i).at(j).at(k));
                k--;
                i--;
            }
            l++;
        }
    } else if(smjer==SmjerKretanja::GoreDolje) {
        int x(c.size()),y(c.at(0).size()), z(c.at(0).at(0).size());
        V.resize(y);
        int l {};
        for(int j=0; j<y; j++) {
            int i=x-1;
            int k=0;
            while(i>=0 && k<z) {
                V.at(l).push_back(c.at(i).at(j).at(k));
                k++;
                i--;
            }
            l++;
        }
    }


    return V;
}

int main ()
{

    int x,y,z;
    int s;
    int kraj {};
    vector<deque<deque<int>>> V;
    std::deque<deque<int>> K;


    cout<<"Unesite dimenzije (x y z): ";
    cin>>x>>y>>z;
    if(x<=0 || y<=0 || z<=0) {
        cout<<"Neispravne dimenzije kontejnera!";
        return 1;
    }

    V.resize(x);
    for(int i=0; i<x; i++)
        V[i].resize(y);
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            V[i][j].resize(z);
    cout<<"Unesite elemente kontejnera: ";
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            for(int k=0; k<z; k++)
                cin>>V[i][j][k];
    try {
        cout<<endl<<"Unesite smjer kretanja [0 - 5]: ";

        cin>>s;
        if(s<0 || s>5) {
            kraj++;
            cout<<"Smjer kretanja nije ispravan!"<<endl;

            return 1;

        }

        SmjerKretanja val = static_cast<SmjerKretanja>(s);

        vector<string> p {"NaprijedNazad","NazadNaprijed","GoreDolje","DoljeGore","LijevoDesno", "DesnoLijevo"};
        cout<<p[s]<<": "<<endl;
        K=IzdvojiDijagonale3D(V,val);


        for(int j=0; j<K.size(); j++) {
            for(int k=0; k<K[j].size(); k++)
                cout<<std::setw(4)<<K[j][k];
            cout<<endl;
        }
    } catch(std::domain_error izuzetak) {
        cout<<izuzetak.what();
    }

    return 0;
}