#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

int Slovo (char c)
{
    if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return 1;
    return 0;    
}

string NapraviPalindrom(string recenica, vector<string> fraze)
{
   
    for(int i=0; i<fraze.size(); i++)
    {
        int razmak=1;
        for(int j=0; j<recenica.size(); j++)
        {
            if (recenica.at(j)==' ')
                razmak=1;
            else if (razmak==1)
            {
                razmak=0;
                string rijec;
                if (j + fraze.at(i).size()>recenica.size())
                    continue;
                rijec=recenica.substr(j, fraze.at(i).size());
                bool kraj=true;
            
                if (fraze.at(i)!=rijec)
                    kraj=false;
             
                int pom = j + fraze.at(i).size();
                if (pom < recenica.size() && Slovo(recenica.at(pom)))
                    kraj=false;
                    
                if (kraj==true)
                {
                    for(int k=fraze.at(i).size()-1; k>=0; k--)
                    {
                        recenica.insert(recenica.begin()+pom, fraze.at(i).at(k));
                        pom++;
                    }
                }
            }
        }
    }    
    
    return recenica;
}

string NapraviPoluPalindrom(string recenica, vector<string> fraze)
{
    for(int i=0; i<fraze.size(); i++)
    {
        int razmak=1;
        for(int j=0; j<recenica.size(); j++)
        {
            if (recenica.at(j)==' ')
                razmak=1;
            else if (razmak==1)
            {
                razmak=0;
                string rijec;
                if (j + fraze.at(i).size()>recenica.size())
                    continue;
                
                rijec=recenica.substr(j, fraze.at(i).size());  
                
                bool kraj=true;
                if (rijec!=fraze.at(i))
                    kraj=false;
                
                int p=j+fraze.at(i).size();
                if (p < recenica.size() && Slovo(recenica.at(p)))
                    kraj=false;
                
                if (kraj==true)
                {
                    int brojac;
                    brojac=fraze.at(i).size();
                    if (brojac%2==0)
                    {
                        int pom(j);
                        for(int k=0; k<brojac/2; k++)
                            pom++;
                       
                        int m;
                        m=pom-1;
                           
                        for(int k=0; k<brojac/2; k++)
                        {
                            recenica.at(pom)=recenica.at(m);
                            pom++;
                            m--;
                        }
                        
            
                    }
                    else if (brojac%2!=0)
                    {
                        
                       
                        
                            int pom(j);
                            for(int k=0; k<brojac/2; k++)
                                pom++;
                            int m;    
                            m=pom-1;
                            pom++;
                            for(int k=0; k<brojac/2; k++)
                            {
                                
                                recenica.at(pom)=recenica.at(m);
                                pom++;
                                m--;
                            }
                        }
                    }
                
                }
            }
        }
        
return recenica;
      
}

int main1()
{
    string s = "Danas je lijep i suncan dan";
    vector<string> v = {"dan", "lijep", "suncan"};
    auto nova = NapraviPalindrom(s, v);
    auto nova2 = NapraviPoluPalindrom(s, v);
    cout << nova << "\n" << nova2;
    return 0;
}
int main ()
{
    string recenica;
    cout<<"Unesite recenicu: ";
    std::getline(cin, recenica);
    
    cout<<"Unesite fraze: ";
    vector<string> fraze;
    for(;;)
    {
        char a;
        a=cin.peek();
        if (a=='\n')
            break;
        string rijec;
        std::getline(cin, rijec);
        fraze.push_back(rijec);
    }
    
    string vr_pal;
    cout<<"Recenica nakon Palindrom transformacije: ";
    vr_pal=NapraviPalindrom(recenica, fraze);
    cout<<vr_pal<<"\n";
    
    string vr_pol;
    cout<<"Recenica nakon PoluPalindrom transformacije: ";
    vr_pol=NapraviPoluPalindrom(recenica, fraze);
    cout<<vr_pol;
    
    
	return 0;
}