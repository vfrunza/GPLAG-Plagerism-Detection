#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::vector;
using std::string;

bool Slovo(char a)
{
    return ( (a>='A' and a<='Z') or (a>='a' and a<='z')); 
}

string ObrniFraze(string recenica, vector<string> popis)
{
    for(int j=0;j<popis.size();j++)
    {
        for(int i=0;i<recenica.length();i++)
        {
                string fraza=recenica.substr(i,popis[j].length());
                    if(fraza==popis[j])
                    {
                        int f=i;
                        for(int k=popis[j].length()-1;k>=int(popis[j].length()/2);k--)
                            {
                                char temp(recenica[f]);
                                recenica[f]=recenica[k+i];
                                recenica[k+i]=temp;
                                f++;
                            }
                    }
        }
    }
    return recenica;
}
string IzmijeniUPigLatin(string recenica, vector<string> popis)
{
    if(popis.size()==0)
    {   
        for(int i=0;i<recenica.size();i++)
        {
            if(!Slovo(recenica[i]))
                continue;
            int f=i;
            int j=0;
            while(Slovo(recenica[f]))
            {
                j++;
                f++;
            }
            string a=recenica.substr(i,j);
            a.push_back(a[0]);
            a.erase(a.begin()+0);
            a.push_back('a');
            a.push_back('y');
            for(int k=0;k<a.length()-2;k++)
                recenica.erase(recenica.begin()+i);
            for(int k=a.length()-1;k>=0;k--)
                recenica.insert(recenica.begin()+i,a[k]);
            i=i+a.length()-1;
        }
        return recenica;
    }
    for(int i=0;i<popis.size();i++)
    {
        for(int j=0;j<popis[i].length();j++)
        {
            if(!Slovo(popis[i][j]))
                throw std::domain_error("Nekorektan izbor rijeci");
        }
    }
    for(int i=0;i<recenica.length();i++)
    {
        for(int j=0;j<popis.size();j++)
        {
            if(popis[j][0]==recenica[i])
            {
                string fraza=recenica.substr(i,popis[j].length());
                    if(fraza==popis[j] and ((i+popis[j].length()==recenica.length() or !Slovo(recenica[i+popis[j].length()]))) and (i==0 or !Slovo(recenica[i-1])))
                    {
                        fraza.push_back(fraza[0]);
                        fraza.erase(fraza.begin()+0);
                        fraza.push_back('a');
                        fraza.push_back('y');
                        for(int k=0;k<fraza.length()-2;k++)
                            recenica.erase(recenica.begin()+i);
                        for(int k=fraza.length()-1;k>=0;k--)
                            recenica.insert(recenica.begin()+i,fraza[k]);
                    }
            }
        }
    }
    return recenica;
}
int main()
{
    cout<<"Unesite recenicu: ";
    string recenica,pig;
    std::getline(cin,recenica);
    vector<string> fraze;
    cout<<"Unesite fraze: ";
    for(;;)
    {
        string pomoc;
        std::getline(cin,pomoc);
        if(pomoc=="")
            break;
        else
            fraze.push_back(pomoc);
    }
    try{
        pig=IzmijeniUPigLatin(recenica,fraze);
        cout<<"Recenica nakon PigLatin transformacije: "<<pig<<"\n";
    }
    catch(std::domain_error greska)
    {
        cout<<"Izuzetak: "<<greska.what()<<"\n";
    }
    recenica=ObrniFraze(recenica,fraze);
    cout<<"Recenica nakon obrtanja fraza: "<<recenica<<"\n";
	return 0;
}