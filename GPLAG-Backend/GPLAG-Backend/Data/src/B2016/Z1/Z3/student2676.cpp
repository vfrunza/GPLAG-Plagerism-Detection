#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::vector;

typedef vector<vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> v)
{
    Matrica podn;
    if(v.size()==0) return podn;
    int brr=-1;
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]<=v[i+1])
        {
            brr++;
            podn.push_back(vector<double>{});
            podn[brr].push_back(v[i]);
            i++;
            while(i<v.size() && v[i]>=podn[brr][podn[brr].size()-1])
            {
                podn[brr].push_back(v[i]);
                i++;
            }
            i--;
        }
    }
    return podn;
}
Matrica OpadajuciPodnizovi(vector<double> v)
{
    Matrica podn;
    if(v.size()==0) return podn;
    int brr=-1;
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]>=v[i+1])
        {
            brr++;
            podn.push_back(vector<double>{});
            podn[brr].push_back(v[i]);
            i++;
            while(i<v.size() && v[i]<=podn[brr][podn[brr].size()-1])
            {
                podn[brr].push_back(v[i]);
                i++;
            }
            i--;
        }
    }
    return podn;
}

int main ()
{
    int n;
    cout << "Unesite broj elemenata vektora: ";
    cin >> n;
    vector<double> a(n);
    cout << "Unesite elemente vektora: ";
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    Matrica c=RastuciPodnizovi(a);
    cout << "Maksimalni rastuci podnizovi:\n";
    for(int i=0;i<c.size();i++)
    {
        for(int j=0;j<c[i].size();j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    Matrica d=OpadajuciPodnizovi(a);
    cout << "Maksimalni opadajuci podnizovi:\n";
    for(int i=0;i<d.size();i++)
    {
        for(int j=0;j<d[i].size();j++)
        {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
	return 0;
}