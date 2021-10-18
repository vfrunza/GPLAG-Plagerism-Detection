#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

string palindrom(string s)
{
    string t(s);
    for (int i(0); i < s.length(); i++)
        t.at(i) = s.at(s.length()-1 - i);
    return t;
}
string polupalindrom(string s)
{
    for (int i(0); i < s.length()/2; i++)
        s.at(s.length()-1 - i) = s.at(i);
    return s;
}
bool slovo(char c)
{
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}
bool fraza(string s)
{
    for (char c : s)
        if (slovo(c)) return true;
    return false;
}
string NapraviPalindrom(string rec, vector<string> v)
{
    for (string s : v)
        if (s.length() && rec.length() >= s.length())
            for (int i(0); i <= rec.length() - s.length(); i++)
                if (rec.substr(i, s.length()) == s && (i == 0 || !slovo(rec.at(i-1)) || !slovo(s.at(0)))
                && (i + s.length() == rec.length() || !slovo(rec.at(i + s.length())) || !slovo(s.at(s.length() - 1))))
                {
                    rec = rec.substr(0, i + s.length()) + palindrom(s) + rec.substr(i + s.length(), rec.length() - i - s.length());
                    i += 2*s.length() - 1;
                }
    return rec;
}
string NapraviPoluPalindrom(string rec, vector<string> v)
{
    for (string s : v)
        if (s.length() && rec.length() >= s.length())
            for (int i(0); i <= rec.length() - s.length(); i++)
                if (rec.substr(i, s.length()) == s && (i == 0 || !slovo(rec.at(i-1)) || !slovo(s.at(0)))
                && (i + s.length() >= rec.length() || !slovo(rec.at(i + s.length())) || !slovo(s.at(s.length() - 1))))
                {
                    rec = rec.substr(0, i) + polupalindrom(s) + rec.substr(i + s.length(), rec.length() - i - s.length());
                    i += s.length() - 1;
                }
    return rec;
}
int main()
{
    std::cout << "Unesite recenicu: ";
    string recenica, s;
    std::getline(std::cin, recenica);
    std::cout << "Unesite fraze: ";
    vector<string> v;
    while (std::getline(std::cin, s) && s.length())
        v.push_back(s);
    std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, v)
    << "\nRecenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, v);
	return 0;
}