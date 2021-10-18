/*B 2017/2018, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <string>
#include <vector>

std::string PoluPalindrom(std::string s)
{
 std::string pp;
 for(int i((s.length()-1)/2);i>=0;i--)
  pp+=s.at(i);
 return pp;
}

std::string Palindrom(std::string s)
{
 std::string p;
 for(int i(s.length()-1);i>=0;i--)
  p+=s.at(i);
return p;
}

std::string NapraviPalindrom(std::string s1, std::vector<std::string> f)
{
 for(std::string s : f)
 {
  for(int i(0);i<=s1.length()-s.length();i++)
  {
   if(s1.length()<s.length()) break;
   if(s1.substr(i,s.length())==s) 
   {
    if(i>0 && i+s.length()<s1.length())
	   {
	    if(!((s1.at(i-1)>='A' && s1.at(i-1)<='Z') || (s1.at(i-1)>='a' && s1.at(i-1)<='z')) &&  !((s1.at(i+s.length())>='A' && s1.at(i+s.length())<='Z') || (s1.at(i+s.length())>='a' && s1.at(i+s.length())<='z')))
	     s1.insert(i+s.length(),Palindrom(s));
	   }
	   else if(i>0)
	   {
	    if(!((s1.at(i-1)>='A' && s1.at(i-1)<='Z') || (s1.at(i-1)>='a' && s1.at(i-1)<='z')))
	     s1.insert(i+s.length(),Palindrom(s));
    }
	   else
	   {
	    if(!((s1.at(i+s.length())>='A' && s1.at(i+s.length())<='Z') || (s1.at(i+s.length())>='a' && s1.at(i+s.length())<='z')))
	     s1.insert(i+s.length(),Palindrom(s));
    }
   }
  }
 }
 return s1;
}

std::string NapraviPoluPalindrom(std::string s1,std::vector<std::string> f)
{
 for(std::string s : f)
 {
  for(int i(0);i<=s1.length()-s.length();i++)
  {
   if(s1.length()<s.length()) break;
   if(s1.substr(i,s.length())==s)
   {
   	if(i>0 && i+s.length()<s1.length())
   	{
   	 if(!((s1.at(i-1)>='A' && s1.at(i-1)<='Z') || (s1.at(i-1)>='a' && s1.at(i-1)<='z')) && !((s1.at(i+s.length())>='A' && s1.at(i+s.length())<='Z') || (s1.at(i+s.length())>='a' && s1.at(i+s.length())<='z')))
   	 {
   	  if(s.length()%2!=0)
   	  {
       s1.insert(i+s.length(),PoluPalindrom(s));
       s1.erase(i+(s.length()/2),(s.length()/2)+1);
   	  }
      else
      {
       s1.insert(i+(s.length()/2),PoluPalindrom(s));
   	   s1.erase(i+s.length(),(s.length()/2));
      }
   	 }
   	}
   	else if(i>0)
   	{
   	 if(!((s1.at(i-1)>='A' && s1.at(i-1)<='Z') || (s1.at(i-1)>='a' && s1.at(i-1)<='z')))
   	 {
   	  if(s.length()%2!=0)
   	  {
       s1.insert(i+s.length(),PoluPalindrom(s));
       s1.erase(i+(s.length()/2),(s.length()/2)+1);
   	  }
      else
      {
       s1.insert(i+(s.length()/2),PoluPalindrom(s));
       s1.erase(i+s.length(),(s.length()/2));
      }
   	 }
   	}
   	else
   	{
   	 if(!((s1.at(i+s.length())>='A' && s1.at(i+s.length())<='Z') || (s1.at(i+s.length())>='a' && s1.at(i+s.length())<='z')))
   	 {
   	  if(s.length()%2!=0)
   	  {
       s1.insert(i+s.length(),PoluPalindrom(s));
       s1.erase(i+(s.length()/2),(s.length()/2)+1);
   	  }
      else
      {
       s1.insert(i+(s.length()/2),PoluPalindrom(s));
   	   s1.erase(i+s.length(),(s.length()/2));
      }
   	 }
   	}
   }
  }
 }
 return s1;
}

int main ()
{
	std::string recenica;
	std::vector<std::string> fraze;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout << "Unesite fraze: ";
 for(;;)
	{	 
	 std::string fraza;
  std::getline(std::cin,fraza);
  if(fraza.length()==0) break;
  fraze.push_back(fraza);	
	}
 std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica,fraze);
	std::cout << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica,fraze);
	return 0;
}