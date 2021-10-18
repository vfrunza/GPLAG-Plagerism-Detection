/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: string;
using std:: set;
using std:: vector;
using std:: map;

vector<string> RazdvojiNaRijeci(string recenica)
{
    vector<string>razdvojeni;
    string rijec="";
    
   for(int i=0; i<recenica.length(); i++)
   {
       if((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='0' && recenica[i]<='9')) rijec+=recenica[i];
       else {if(rijec.size()) razdvojeni.push_back(rijec); rijec=""; }
   }
   razdvojeni.push_back(rijec);
   
   for(int i=0; i<razdvojeni.size()-1; i++)
   {
       for(int j=i+1; j<razdvojeni.size(); j++)
       {
           if(razdvojeni[i]==razdvojeni[j])
           {
               razdvojeni.erase(razdvojeni.begin()+j);
               j--;
           }
       }
   }
   return razdvojeni;
}

map<string, set<int>> KreirajIndeksPojmova(string recenica)
{
    for(int i=0; i<recenica.length(); i++)
    {
        if(recenica[i]>='A' && recenica[i]<='Z') recenica[i]+=32;
    }
   
   vector<string>razdvojeni(RazdvojiNaRijeci(recenica));
   map<string, set<int>> rez;
   
   
   for(int i=0; i<razdvojeni.size(); i++)
   {
       for(int j=0; j<recenica.length(); j++)
       {
           int temp=j;
           string pomocna_rijec="";
           while((recenica[j]>='a' && recenica[j]<='z') || (recenica[j]>'A' && recenica[j]<='Z') || (recenica[j]>='0' && recenica[j]<='9')) 
           {
              pomocna_rijec+=recenica[j];
              j++;
           }
            if(pomocna_rijec==razdvojeni[i]) rez[razdvojeni[i]].insert(temp);
          
       }
       
  
   } 
   
    return rez;
}

void IspisiIndeksPojmova (map<string, set<int>>rezultat)
{
    for(auto it=rezultat.begin(); it!=rezultat.end(); it++)
    {
        vector<int>vektor;
        
       
       
        for(auto it2=it->second.begin(); it2!=it->second.end(); it2++)
        {
            vektor.push_back(*it2);
        } 
        cout << it->first << ": ";
        for(int i=0; i<vektor.size(); i++)
        {
            if(i==vektor.size()-1) cout<<vektor[i]<<endl;
            else  cout<<vektor[i]<<",";
        }
    }
}

set<int> PretraziIndeksPojmova(string rijec, map<string, set<int>> rezultat)
{
    for(int i=0; i<rijec.length(); i++)
    {
            if(rijec[i]>='A' && rijec[i]<='Z') rijec[i]+=32;
    }
    if(rezultat.find(rijec)!=rezultat.end())
    return rezultat[rijec];
    throw std:: logic_error("Unesena rijec nije nadjena!");
}


int main ()
{
    string recenica;
    cout<<"Unesite tekst: ";
    std:: getline(cin, recenica);
    map<string, set<int>>rezultat(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(rezultat);
    while(1)
    {
        cout<<"Unesite rijec: ";
        string rijec;
        std:: getline(cin, rijec);
        if(rijec==".") break;
       
        try
        {
            set<int>zarijec(PretraziIndeksPojmova(rijec, rezultat));
            for(auto it=zarijec.begin(); it!=zarijec.end(); it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
        catch(std:: logic_error izuzetak)
        {
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
    }
    
    
   
    
    
    return 0;
  
}