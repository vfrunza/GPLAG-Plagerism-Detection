#include <iostream>
#include <vector>
#include <cmath>
using namespace::std;
vector<int> IzdvojiGadne(vector<int> b,bool opak)
{
    vector<int> pozitivni,brojac(3),opaki,odvratni;
    vector<vector<int>> baza3(b.size());
    for(int i = 0;i < b.size();i++)
    {
        if(b[i] < 0)
            pozitivni.push_back(-b[i]);
        else
            pozitivni.push_back(b[i]);
    }
    for(int i = 0; i < pozitivni.size();i++)
    {
        int temp = pozitivni[i];
        while( temp > 0)
        {
            baza3[i].push_back(temp%3);
            temp = temp/3;
        }
    }
    for(int i = 0; i < baza3.size();i++)
    {
        brojac[0] = 0;
        brojac[1] = 0;
        brojac[2] = 0;
        for(int j = 0; j < baza3[i].size();j++)
        {
            for(int k = 0; k < 3;k++)
            {
                if(baza3[i][j] == k)
                    brojac[k]++;
            }
        }
        int parni(0),neparni(0),cifre(0);
        for(int j = 0;j < 3;j++)
        {
            if(brojac[j] > 0)
            {
                cifre++;
                if(brojac[j] %2 == 0)
                    parni++;
                else
                    neparni++;
            }
        }
        if(parni == cifre)
        {
            bool vec_ima(false);
            for(int j = 0; j < opaki.size();j++)
            {
                if(b[i] == opaki[j])
                    vec_ima = true;
            }
            if(vec_ima == false)
            opaki.push_back(b[i]);
        }
        if(neparni == cifre)
        {
            bool vec_ima(false);
            for(int j = 0; j < odvratni.size();j++)
            {
                if(b[i] == odvratni[j])
                    vec_ima = true;
            }
            if(vec_ima == false)
            odvratni.push_back(b[i]);
        }
    }
    if(opak == true)
        return opaki;
    return odvratni;
}
int main()
{
    int broj;
    vector<int> a;
    cout << "Unesite brojeve (0 za prekid unosa): ";
    do
    {
        cin >> broj;
        if(broj != 0)
        a.push_back(broj);
    }while(broj != 0);
    vector<int> opaki = IzdvojiGadne(a,1);
    vector<int> odvratni = IzdvojiGadne(a,0);
    cout << "Opaki: ";
    for(int i =0 ; i < opaki.size();i++)
    {
        cout << opaki[i] << " ";
    }
    cout << endl << "Odvratni: ";
    for(int i = 0;i < odvratni.size(); i++)
    {
        cout << odvratni[i] << " ";
    }
    return 0;
}
