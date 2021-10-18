#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Palindrom(string s)
{
    string s1;
    s1.resize(s.length());
    int j(0);
    for(int i=s.length()-1; i>=0; i--) {
        s1.at(j)=s.at(i);
        j++;
    }
    return s1;
}

string PoluPalindrom(string s)
{
    string s1, s2;
    s1.resize(s.length());
    if(s.size()%2==0) {
        s2.resize(s.length()/2);
        for(int i=0; i<(int)(s.length()/2); i++)
            s1.at(i)=s.at(i);
        for(int i=0; i<(int)(s.length()/2); i++)
            s2.at(i)=s1.at(i);
        s2=Palindrom(s2);
        for(int i=0; i<(int)(s.length()/2); i++)
            s1.at(s.length()/2+i)=s2.at(i);
    } else {
        s2.resize(s.length()/2);
        for(int i=0; i<=(int)(s.length()/2); i++)
            s1.at(i)=s.at(i);
        for(int i=0; i<(int)(s.length()/2); i++)
            s2.at(i)=s1.at(i);
        s2=Palindrom(s2);
        for(int i=0; i<(int)(s2.length()); i++)
            s1.at(s.length()/2+1+i)=s2.at(i);
    }
    return s1;
}

bool Slovo(char c)                                          //Provjerava da li je znak slovo
{
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

string NapraviPalindrom(string s10, vector<string> v)
{
    string s1, s2, s3, s=s10;
    int pomocni, pomocni2, pomocni3;

    if(s.length()==0)
        return s1;
    if(v.size()==0)
        return s10;

    bool prazan(true);
    for(int i=0; i<v.size(); i++)
        if(v.at(i).length()!=0)
            prazan=false;
    if(prazan)
        return s;

    for(int i=0; i<(int)(v.size()); i++) {
        s1=v.at(i);

        for(int j=0; j<(int)(s.length()-s1.length()+1); j++) {
            s2=s.substr(j, s1.length());
            if(s2.size()>0 && s2==s1 && (j + s1.length() >= s.length() || !Slovo(s.at(j+s1.length()))) && (j == 0 || !Slovo(s.at(j-1)))) {
                pomocni3=s.length();
                s.resize(s.length()+s1.length());
                pomocni2=1;
                for(int k=pomocni3-1; k>=int(j+s1.length()); k--) {
                    s.at(s.length()-pomocni2)=s.at(k);
                    pomocni2++;
                }
                s3=Palindrom(s1);
                pomocni=0;
                int pomocni4(j);
                for(int l=j+s1.length(); l<(int)(j+2*s1.length()); l++) {
                    s.at(l)=s3.at(pomocni);
                    pomocni++;
                    pomocni4=l+1;
                }
                j=pomocni4;
            }
        }
    }
    return s;
}

string NapraviPoluPalindrom(string s, vector<string> v)
{
    string s1, s2, s3;
    int pomocni, pomocni2;

    if(s.length()==0)
        return s1;
    if(v.size()==0)
        return s;

    bool prazan(true);
    for(int i=0; i<v.size(); i++)
        if(v.at(i).length()!=0)
            prazan=false;
    if(prazan)
        return s;

    for(int i=0; i<(int)v.size(); i++) {
        s1=v.at(i);

        for(int j=0; j<(int)(s.length()-s1.length()+1); j++) {
            s2=s.substr(j, s1.length());

            if(s2.size()>0 && s2==s1 && (j + s1.length() >= s.length() || !Slovo(s.at(j+s1.length()))) && (j == 0 || !Slovo(s.at(j-1)))) {
                s3=PoluPalindrom(s2);

                pomocni=0;
                pomocni2=j;
                for(int k=j; k<(int)(j+s3.length()); k++) {
                    s.at(k)=s3.at(pomocni);
                    pomocni++;
                    pomocni2=k;
                }
                j=pomocni2;
            }
        }
    }
    return s;
}

int main ()
{
    string s, pomocni, PalS, PolS;
    vector<string> v;
    cout<<"Unesite recenicu: ";
    getline(cin, s);
    cout<<"Unesite fraze: ";
    while(getline(cin, pomocni)) {
        if(pomocni.length()!=0)
            v.push_back(pomocni);
        if(cin.peek()=='\n')
            break;
    }
    PalS=NapraviPalindrom(s, v);
    PolS=NapraviPoluPalindrom(s, v);
    cout<<"Recenica nakon Palindrom transformacije: "<<PalS<<endl<<"Recenica nakon PoluPalindrom transformacije: "<<PolS;
    return 0;
}