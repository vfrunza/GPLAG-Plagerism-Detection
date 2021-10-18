#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string IzmijeniUPigLatin(string s1, vector<string> s2)
{
    int broj = s2.size();
    broj = broj * 2;
    int broj1 = s1.size();
    string formirani(s1);
   
    string rijec;
    int pom = 0;
    string pomocna;
    char piva;
    for(int z=0; z < s2.size(); z++)
    {
        rijec=s2[z];
        pom =0;
        for(int i=0; i<s1.size(); i++)
        {
            int br=0;
            int k=i;
            for(int j=0; j<rijec.size(); j++)
            {
                if(rijec[j]==s1[k])
                {
                    br++;
                }

                k++;
            }
            if(br==rijec.size())
            {
            	 formirani.resize(formirani.size());
                reverse(formirani.begin()+i, formirani.begin()+i+rijec.size());
                reverse(formirani.begin()+i, formirani.begin()+i+rijec.size() - 1);
                formirani.insert(i+rijec.size(), "ay");

            }
        }
        s1=formirani;
        rijec.clear();
    }



    return formirani;
}
string ObrniFraze(string s1, vector<string> s2)
{
    string formirani(s1);
    string rijec;
    int pom = 0;
    string pomocna;
    char piva;
    for(int z=0; z < s2.size(); z++)
    {
        rijec=s2[z];
        pom =0;
        for(int i=0; i<s1.size(); i++)
        {
            int br=0;
            int k=i;
            for(int j=0; j<rijec.size(); j++)
            {
                if(rijec[j]==s1[k])
                {br++;}

                k++;
            }
            if(br==rijec.size())
            {

                reverse(formirani.begin()+i, formirani.begin()+i+rijec.size());

            }
        }
        s1=formirani;
         rijec.clear();
    }



    return formirani;
}
int main()
{
    string recenica, rijec, ispravljenaRecenica;
    string pig;
    vector<string> vektor;
    cout<<"Unesite recenicu: ";
    getline(cin, recenica);

   cout<<"Unesite fraze: ";
   while(getline(cin, rijec) && rijec.size()>0)
   {
       vektor.push_back(rijec);
   }
   
   ispravljenaRecenica=ObrniFraze(recenica,vektor);
   pig = IzmijeniUPigLatin(recenica,vektor);
   	cout << "Recenica nakon PigLatin transformacije: " << pig;
   	cout << endl;
   cout <<"Recenica nakon obrtanja fraza: "<< ispravljenaRecenica;

    return 0;
}
