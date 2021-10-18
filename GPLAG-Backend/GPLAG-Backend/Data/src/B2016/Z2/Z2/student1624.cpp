#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <iomanip>
#include <stdexcept>
using namespace::std;

enum class SmjerKretanja {
 NaprijedNazad=0, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename kont>
auto IzdvojiDijagonale3D(kont a,SmjerKretanja s) 
    -> typename remove_reference<decltype(a.at(0))>::type
{
    auto x = a;
    if(a.size() == 0 || a.at(0).size() == 0 || a.at(0).at(0).size() == 0)
        return a.at(0);
    auto y = a.at(0);
    auto z = a.at(0).at(0);
    decltype(y) dijag;
    if(s == SmjerKretanja(0) || s == SmjerKretanja(1))
    {
        for(int i = 0;i < x.size();i++)
            dijag.push_back(decltype(z)());
    }
    else if(s == SmjerKretanja(2) || s == SmjerKretanja(3))
    {
        for(int i = 0;i < y.size();i++)
            dijag.push_back(decltype(z)());
    }
    else
    {
        for(int i = 0;i < z.size();i++)
            dijag.push_back(decltype(z)());
    }
    for(auto b:a)
    {
        for(auto c:b)
        {
            if(b.at(0).size() != c.size())
                throw domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    for(auto b : a)
    {
        if(a.at(0).size() != b.size())
            throw domain_error("Plohe nemaju isti broj redova");
    }
        
    int i(0),j(0),k(0);

    for(auto b:a)
    {
        for(auto c:b)
        {
            for(auto d:c)
            {
                if(s == SmjerKretanja(0) && j == k)
                    dijag.at(i).push_back(d);
                else if(s == SmjerKretanja(1) && j == z.size()-k-1)
                    dijag.at(a.size()-i-1).push_back(d);
                if(s == SmjerKretanja(2) && x.size()-1-i == k)
                    dijag.at(j).push_back(d);
                if(s == SmjerKretanja(3) && z.size()-1-k == x.size()-1-i)
                    dijag.at(j).push_back(d);
                if(s == SmjerKretanja(4) && x.size()-1-i == j)
                    dijag.at(k).push_back(d);
                if(s == SmjerKretanja(5) && i == j)
                    dijag.at(k).push_back(d);
                k++;
            }
            k = 0;
            j++;
        }
        j = 0;
        i++;
    }
    if(s == SmjerKretanja(2) || s == SmjerKretanja(3) || s == SmjerKretanja(4))
    {
        for(auto &a : dijag)
        {
            for(int i = 0; i < a.size()/2;i++)
            {
                auto temp = a.at(i);
                a.at(i) = a.at(a.size()-1-i);
                a.at(a.size()-1-i) = temp;
            }
        }
    }
    if(s == SmjerKretanja(3) || s == SmjerKretanja(5))
    {
        for(int i = 0; i < dijag.size()/2;i++)
        {
            auto temp = dijag.at(i);
            dijag.at(i) = dijag.at(dijag.size()-1-i);
            dijag.at(dijag.size()-1-i) = temp;
        }
    }
    return dijag;
}

int main()
{
    vector<deque<deque<double>>> a;
    int x,y,z;
    cout << "Unesite dimenzije (x y z): ";
    cin >> x >> y >> z;
    if(x < 0 || y < 0 || z < 0)
    {
        cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    cout << "Unesite elemente kontejnera: " << endl;
    for(int i = 0; i < x; i++)
    {
        a.push_back(deque<deque<double>>(0));
        for(int j = 0; j < y; j++)
        {
            a[i].push_back(deque<double>(0));
            for(int k = 0; k < z; k++)
            {
                double temp;
                cin >> temp;
                a[i][j].push_back(temp);
            }
        }
    }
    cout << "Unesite smjer kretanja [0 - 5]: ";
    int temp;
    cin >> temp;
    if(temp > 5 || temp < 0)
    {
        cout << "Smjer kretanja nije ispravan!" << endl;
        return 0;
    }
    deque<deque<double>> t;
    try 
    {
            t = IzdvojiDijagonale3D(a,SmjerKretanja(temp));
    }
    catch (const exception e) 
    {
        std::cout << e.what() << std::endl;
        return 0;
    }
    if(temp == 0)
        cout << "NaprijedNazad: " << endl;
    else if(temp == 1)
        cout << "NazadNaprijed: " << endl;
    else if(temp == 2)
        cout << "GoreDolje: " << endl;
    else if(temp == 3)
        cout << "DoljeGore: " << endl;
    else if(temp == 4)
        cout << "LijevoDesno:" << endl;
    else
        cout << "DesnoLijevo: " << endl;
    for(auto x : t)
    {
        for(auto y:x)
            cout << setw(4) << y;
        cout << endl;
    }
    return 0;
}