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
#include <cstdlib>
#include <cctype>
typedef std::string String;
typedef std::vector<String> Vex;

String ObrniRijec(String s,bool Polovina)
{
	if(Polovina == false){
		String naopako;
		naopako.resize(s.length());
	//	int k(0);
		for(int i=s.length()-1; i>=0; i--){
			naopako.at(s.length()-1-i)=s.at(i);
		}
		return naopako;
	}
	else {
		String naopako;
		for(int i=0; i<=(s.length()-1)/2; i++){
			naopako.resize(i+1);
			naopako.at(i)=s.at(i);
		}
		return ObrniRijec(naopako,false);
	}
}


String NapraviPalindrom(String s, Vex v)
{
/*
	bool isti(true);
	int brojac(0);
	int k(0),m(0);
	   int l(0),n(0);
	   int duzina(0);
	
	for(int i=0; i<v.size()-1; i++)
	{
	   for(int j=0; j<v.at(i).size()-1; j++)
	   {
	   		if(j != v[i].size()) brojac++;	 
	   
	   
	   
	   
	   if (s.at(l)==' ' || s.at(l)==',')l++;
	   while((s.at(l)!=' ' && s.at(l)!=',') || (s.at(l)==' ' && s.at(l)==',' && s.at(l)!=v.at(i).at(n)))
	   {
	   	
	   		duzina++;
	   		l++;
	   		n++;
	   		if(l == s.length() && n == v.at(i).size()) break;
	   		if(l >= s.length()) l--;
	   		if(n >= v.at(i).size()) n--;
	   		
	   }	
	   std::cout << duzina << std::endl;
	   while(v.at(i).at(m) == s.at(k))
	   {
	   	std::cout << k << "||||" <<std::endl;
	   		isti = true;
	   		if(k > m) 
	   		{
	   			isti = false;
	   			break;
	   		}
	   	//	if(isti == true) std::cout<<"HHHH"<<std::endl;
	   		k++;
	   		m++;
	   		if(k == s.length() && m == v.at(i).size()) break;
	   		if(k >= s.length()) k--;
	   		if(m >= v.at(i).size()) m--;
	   	
	   } 
	  // std::cout << l << "||||" <<std::endl;
	   if(isti==true)
	   {
	   		isti=false;
	   		m=0;
	   		n=0;
	   		if(l!=s.length())i--;
	   }
	   }
	  // std::cout<<brojac<<std::endl;
	   brojac=0;duzina=0;
	}  
	   
	*/
	
	
	for(int i=0; i<v.size(); i++)
	{
		int brojac(0),vel_fraze(0),prvo_slovo(0);
		for(int j=0; j<s.length(); j++)
		{
			int k(0),m(j);
			if(m<s.length() && k<v.at(i).length() && (s.at(m) == ' ' || s.at(m) == ','))  m++;
		
			while(vel_fraze == 0)
			{
				
				if((m<s.length() && (s.at(m) == ' ' || s.at(m) == ',') && s.at(m) != v.at(i).at(k))) break;
				brojac++;
				
				if(m<s.length() && s.at(m) == v.at(i).at(k))
				{
					m++; k++;
				}
				
				if(m == s.length() && k == v.at(i).length()) break;
				if(brojac > k) break;
				if(k >= v.at(i).length()) k--;
				if(m >= s.length()) m--;
				
			}
			k = 0;
			m = j;
			
			
			
			
			if(m > 0 && m<s.length() && (s.at(m) != ' ' || s.at(m) != ',')) m++;
			while(m<s.length() && s.at(m) == v.at(i).at(k))
			{
				
				vel_fraze++;
				if(vel_fraze == 1) prvo_slovo = m;
				k++; m++;
				
				if(k == v.at(i).length() && m == s.length()) break;
				if(k >= v.at(i).length()) k--;
				if(m >= s.length()) m--; 
				
			}
			
			
			if(vel_fraze != v.at(i).length()) vel_fraze=0;
			if(brojac != vel_fraze)
			{
				brojac=0;
				vel_fraze=0;
			}
			
			else if(vel_fraze == v.at(i).length())
			{
				k = 0; break;
			}
			
		}
		bool Palindrom(true);
    	int n(0);
    	for(int l=s.length()-1; l>=0; l--)
    	{
    	if(s.at(l) == s.at(n++)) Palindrom=true;
    	else
    		{
    			Palindrom = false; break;
    		}
		 }
		if(vel_fraze == v.at(i).length()){
			int duzina(s.length()+vel_fraze);
			s.resize(duzina);
			s=s.substr(0,prvo_slovo+vel_fraze) + ObrniRijec(v.at(i),false) + s.substr(prvo_slovo + vel_fraze,duzina-prvo_slovo+vel_fraze);
			s.resize(duzina);
			i--;
		}
		
	}
	
	return s;
}

String NapraviPoluPalindrom(String s, Vex v)
{
/*
	bool isti(true);
	int brojac(0);
	int k(0),m(0);
	   int l(0),n(0);
	   int duzina(0);
	
	for(int i=0; i<v.size()-1; i++)
	{
	   for(int j=0; j<v.at(i).size()-1; j++)
	   {
	   		if(j != v[i].size()) brojac++;	 
	   
	   
	   
	   
	   if (s.at(l)==' ' || s.at(l)==',')l++;
	   while((s.at(l)!=' ' && s.at(l)!=',') || (s.at(l)==' ' && s.at(l)==',' && s.at(l)!=v.at(i).at(n)))
	   {
	   	
	   		duzina++;
	   		l++;
	   		n++;
	   		if(l == s.length() && n == v.at(i).size()) break;
	   		if(l >= s.length()) l--;
	   		if(n >= v.at(i).size()) n--;
	   		
	   }	
	   std::cout << duzina << std::endl;
	   while(v.at(i).at(m) == s.at(k))
	   {
	   	std::cout << k << "||||" <<std::endl;
	   		isti = true;
	   		if(k > m) 
	   		{
	   			isti = false;
	   			break;
	   		}
	   	//	if(isti == true) std::cout<<"HHHH"<<std::endl;
	   		k++;
	   		m++;
	   		if(k == s.length() && m == v.at(i).size()) break;
	   		if(k >= s.length()) k--;
	   		if(m >= v.at(i).size()) m--;
	   	
	   } 
	  // std::cout << l << "||||" <<std::endl;
	   if(isti==true)
	   {
	   		isti=false;
	   		m=0;
	   		n=0;
	   		if(l!=s.length())i--;
	   }
	   }
	  // std::cout<<brojac<<std::endl;
	   brojac=0;duzina=0;
	}  
	   
	*/
	
	
	for(int i=0; i<v.size(); i++)
	{
		int brojac(0),vel_fraze(0),prvo_slovo;
		for(int j=0; j<s.length(); j++)
		{
			int k(0),m(j);
			if(m<s.length() && k<v.at(i).length() && (s.at(m) == ' ' || s.at(m) == ',')) m++;
			
			while(vel_fraze == 0)
			{
				
				if(m<s.length() && (s.at(m) == ' ' || s.at(m) == ',') && s.at(m) != v.at(i).at(k)) break;
				brojac++;
				
				if(m<s.length() && k<v.at(i).length() && s.at(m) == v.at(i).at(k))
				{
					m++; k++;
				}
				
				if(m == s.length() && k == v.at(i).length()) break;
				if(brojac > k) break;
				if(k >= v.at(i).length()) k--;
				if(m >= s.length()) m--;
			}
			k = 0;
			m = j;
			
			
			if(m > 0 && m<s.length() && (s.at(m) != ' ' || s.at(m) != ',')) m++;
			while(m<s.length() && s.at(m) == v.at(i).at(k))
			{
				
				vel_fraze++;
				if(vel_fraze == 1) prvo_slovo = m;
				k++; m++;
				
				if(k == v.at(i).length() && m == s.length()) break;
				if(k >= v.at(i).length()) k--;
				if(m >= s.length()) m--;
			}
			
			if(vel_fraze != v.at(i).length()) vel_fraze=0;
			if(vel_fraze != brojac)
			{
				vel_fraze=0;
				brojac=0;
			}
			else if(vel_fraze == brojac && vel_fraze == v.at(i).length())
			{
				k = 0; break;
			}
		}
		bool Palindrom(true);
    	int n(0);
    	for(int l=s.length()-1; l>=0; l--)
    	{
    	if(s.at(l) == s.at(n++)) Palindrom=true;
    	else
    		{
    			Palindrom = false; break;
    		}
		 }
		 
		// if(Palindrom == true) std::cout<<"Palindrom!!"<<std::endl; break;
			
		if(vel_fraze == v.at(i).length() && Palindrom != true){
			s=s.substr(0,prvo_slovo+vel_fraze/2) + ObrniRijec(v.at(i),true) + s.substr(prvo_slovo + vel_fraze,s.length()-prvo_slovo+3*vel_fraze/2);
			i--;
		}
		
	}
	
	return s;
}





int main ()
{
	Vex v(1);
	String s;
	
	std::cout<<"Unesite recenicu: ";
	getline(std::cin,s);
	
	std::cout<<"Unesite fraze: ";
	
	for(int i=0; i<=v.size(); i++)
	{
		v.resize(i+1);
		getline(std::cin,v.at(i));
		if(v.at(i).size()==0){
			v.resize(i);
			break;
		}
	}
	
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(s,v) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: "<< NapraviPoluPalindrom(s,v) << std::endl;
	
	return 0;
}