#include <iostream>
#include <string>
#include <vector>
int Nadji(std::string s, std::string f, int poz)
{
    for(int i=poz;i<=s.length()-f.length();i++)
    {
        std::string tmp(s.substr(i,f.length()));
        if(tmp==f) return i;
    }
    return -1;
    
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze)
{
    std::vector<std::string> polu;
    for(std::string s : fraze)
    {
        std::string a;
        for(int i=0;i<=(s.length()-1)/2;i++)
        {
            a+=s.at(i);
        }
        for(int i=(s.length()-2)/2;i>=0;i--)
        {
            a+=s.at(i);
        }
        polu.push_back(a);
    }
    int i=0;
    for(std::string s : fraze)
    {
        if(recenica.length()<s.length()) continue;
        int nPos(Nadji(recenica,s,0));
        while(nPos != -1)
        {
            bool zamijeni=false;
            if(nPos==0)
            {
                if(recenica.length()==s.length()) zamijeni=true;
                else if(!((recenica.at(nPos+s.length())>='a' && recenica.at(nPos+s.length())<='z') || (recenica.at(nPos+s.length())>='A' && recenica.at(nPos+s.length())<='Z'))) zamijeni=true;
            }
            else if(nPos+s.length()==recenica.length() && !((recenica.at(nPos-1)>='a' && recenica.at(nPos-1)<='z') || (recenica.at(nPos-1)>='A' && recenica.at(nPos-1)<='Z')))
            {
                zamijeni=true;
            }
            else if(!((recenica.at(nPos-1)>='a' && recenica.at(nPos-1)<='z') || (recenica.at(nPos-1)>='A' && recenica.at(nPos-1)<='Z')) && !((recenica.at(nPos+s.length())>='a' && recenica.at(nPos+s.length())<='z') || (recenica.at(nPos+s.length())>='A' && recenica.at(nPos+s.length())<='Z')))
            {
                zamijeni=true;
            }
            if(zamijeni)
            {
                for(int j=nPos;j<=nPos+s.length()-1;j++)
                {
                    recenica.at(j)=polu.at(i).at(j-nPos);
                }
            }
            nPos++;
            nPos=Nadji(recenica,s,nPos);
        } 
        i++;
    }
    return recenica;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze)
{
    
    std::vector<std::string> polindromi;
    for(std::string s : fraze)
    {
        std::string a;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            a+=s.at(i);
        }
        polindromi.push_back(a);
    }
    
    
    int i=0;
    for(std::string s : fraze)
    {
        if(recenica.length()<s.length()) continue;
        int nPos(Nadji(recenica,s,0));
        while(nPos != -1)
        {
            bool zamijeni=false;
            if(nPos==0)
            {
                if(s.length()==recenica.length()) zamijeni=true;
                else if (!((recenica.at(nPos+s.length())>='a' && recenica.at(nPos+s.length())<='z') || (recenica.at(nPos+s.length())>='A' && recenica.at(nPos+s.length())<='Z'))) zamijeni=true;
            }
            else if(nPos+s.length()==recenica.length() && !((recenica.at(nPos-1)>='a' && recenica.at(nPos-1)<='z') || (recenica.at(nPos-1)>='A' && recenica.at(nPos-1)<='Z')))
            {
                zamijeni=true;
            }
            else if(!((recenica.at(nPos-1)>='a' && recenica.at(nPos-1)<='z') || (recenica.at(nPos-1)>='A' && recenica.at(nPos-1)<='Z')) && !((recenica.at(nPos+s.length())>='a' && recenica.at(nPos+s.length())<='z') || (recenica.at(nPos+s.length())>='A' && recenica.at(nPos+s.length())<='Z')))
            {
                zamijeni=true;
            }
            if(zamijeni) recenica.insert(nPos+s.length(),polindromi.at(i));;
            nPos++;
            nPos=Nadji(recenica,s,nPos);
        }
        i++;
    }
    return recenica;
}

int main ()
{
    std::string recenica;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,recenica);
    std::cout<<"Unesite fraze: ";
    std::vector<std::string> fraze;
    while(1)
    {
        std::string fraza;
        std::getline(std::cin,fraza);
        if(fraza=="") break;
        fraze.push_back(fraza);
    }
    std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,fraze)<<std::endl;
    std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,fraze);
    /*std::string recenica("Danas je lijep i suncan dan");
    std::vector<std::string> fraze{"danas","lijep","suncan"};
    std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,fraze)<<std::endl;
    std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,fraze);*/

    return 0;
}