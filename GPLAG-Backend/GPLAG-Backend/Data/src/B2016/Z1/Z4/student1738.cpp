//jos potpuno poklapanje i ponavljanje



#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::string> vektorstringova;
using std::string;

bool DaLiJeRijec (string s)
{
    for (int i=0;i<s.size();i++)
    {
        if ((s.at(i)>'Z' || s.at(i)<'A')&&(s.at(i)<'a'||s.at(i)>'z'))
        return false;
    }
    return true;
}

string ObrniString (string s)
{
    string s1;
    for (int i=int(s.length())-1;i>=0;i--)
    {
        s1.push_back(s.at(i)); 
    }
    return s1;
}
std::vector<int> PocetakKraj (string s1, string s2)
{
    std::vector<int> v (2,-1);
    if ((s1.size()<s2.size())||(s1.size()<2 || s2.size()<2))
    {
        return v;
    }
    string str1(s1),str2(s2);
    int i, j(0);
    for (i=0;i<int(str1.size()) && j<int(str2.size());i++)
    {
        if (str1[i]==str2[j])
        {
            j++;
        }
        else j=0;
    }
    if (j==int(s2.size()))
    {
        v[0]=i-j;
        v[1]=v[0]+str2.size();
    }
    return v;
}

string Zamjena (string s, string s1)
{
    std::vector<int> v(PocetakKraj(s,s1));
    s1=ObrniString(s1);
    string rs(s);
    int j(0);
    for (int i=v[0];i<v[1];i++)
    {
        rs[i]=s1[j]; 
        j++;
    }
    return rs;
}

string ObrniFraze (string s, vektorstringova vs)
{
    string rs(s);
    if (vs.size()==0) return rs;
    for (int i=0;i<int(vs.size());i++)
    {
        rs=Zamjena(rs,vs[i]);
    }
    return rs;
}


string RijecUPigLatin (string s)
{
    string rs(s.length()+2,'0');
    int j(1);
    for (int i=0;i<int(s.size()-1);i++)
    {
        rs[i]=s[j];
        j++;
    }
    rs[s.size()-1]=s[0];
    rs[s.size()]='a';
    rs[s.size()+1]='y';
    return rs;
}

string ZamjeniUPigLatin (string s, string s1)
{
    std::vector<int>v(PocetakKraj(s,s1));
    string s2(RijecUPigLatin(s1));
    string rs(s);
    int j(0);
    for (int i=v[0];i<int(v[0]+s2.size());i++)
    {
        rs.insert(rs.begin()+i,s2[j]);
        j++;
    }
    int p(v[0]+s2.size()),k(p+s1.size());
    
    for (int i=k-1;i>=p;i--)
    {
        rs.erase(rs.begin()+i);
    }
    return rs;
}

string IzmjeniSve (string s)
{
    string pomocni;
    for (int i=0;i<s.size();)
    {
        if (s.at(i)==' ')
        {
            s.erase(s.begin()+0);
        }
        else break;
    }
    
    string rs1(s);
    
    int i(0);
    
    while (i<s.size())
    {
        pomocni.resize(0);
        while (s.at(i)!=' ')
        {
            pomocni.push_back(s[i]);
            if (i<s.size()-1) i++;
            else break;
        }
        if (i<s.size()-1) i++;
        else 
        {
            rs1=ZamjeniUPigLatin(rs1,pomocni);
            break;
        }
        rs1=ZamjeniUPigLatin(rs1,pomocni);
    }
    return rs1;
}


string IzmijeniUPigLatin (string s,vektorstringova vs)
{
    string rs(s);
    if (vs.size()==1)
    {
        rs=IzmjeniSve(rs);
        return rs;
    }
    for (int i=0;i<int(vs.size());i++)
    {
        rs.push_back(' ');
    }
    for (int i=0;i<int(vs.size());i++)
    {
        if (!DaLiJeRijec(vs[i])) throw std::domain_error ("Nekorkatan izbor rijeci");
        rs=ZamjeniUPigLatin(rs,vs[i]);
    }
    return rs;
}



int main ()
{
    /*std::cout << "Unesite recenicu: ";
    string s;
    std::getline(std::cin,s);
    std::cin.ignore(10000,'\n');
    vektorstringova vs;
    std::cout << "Unesite fraze: ";
    do
    {
        string f;
        std::getline(std::cin,f);
        vs.push_back(f);
    }while (char (std::cin.peek())!='\n');
    string s1(s);
    try 
    {
    std::cout << "Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,vs);
    }
    catch (std::domain_error izuzetak)
    {
        std::cout << "Izuzetak "<<izuzetak.what();
    }
    std::cout << std::endl <<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s1,vs);*/
   
    return 0;
}