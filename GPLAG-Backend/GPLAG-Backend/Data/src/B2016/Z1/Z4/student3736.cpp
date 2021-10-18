/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cctype>
using namespace std;
vector<string>split (string data,vector<string> token)
{
	vector<string> output;
	size_t pos=string::npos;
	unsigned int i=0;
	do{
		pos=data.find(token[0]);
		output.push_back(data.substr(0,pos));
		if(string::npos!=pos)
			data=data.substr(pos+token.size());
			i++;
	}while(string::npos !=pos);
	return output;
}

string IzmijeniUPigLatin(string recenica,vector<string> rijec)
{
	vector<string> nova_recenica;
	vector<string> separator;
	separator={" "};
	nova_recenica=split(recenica,separator);
	for(unsigned int i=0;i<rijec.size();i++)
	{
		string str{rijec[i]};
		for(unsigned int j=0;j<str.size();j++)
		{
			if(isalpha(str[j])) continue;
			else
			{
				throw domain_error("Nekorektan izbor rijeci");
			}
		}
	}
	for(unsigned int i=0;i<rijec.size();i++)
	{
		if(rijec[i].size()==0) continue;
		vector<size_t> positions;
		size_t broj=recenica.find(rijec[i],0);
		while(broj!=string::npos)
		{
			positions.push_back(broj);
			broj=recenica.find(rijec[i],broj+1);
		}
		unsigned int j{0};
		for(;;)
		{
			if(find(nova_recenica.begin(),nova_recenica.end(),rijec[i] )  != nova_recenica.end() && recenica.find(rijec[i])!=string::npos)
			{
				string rotiraj_rijec{rijec[i]};
				rotate(rotiraj_rijec.begin(),rotiraj_rijec.begin()+1,rotiraj_rijec.end());
				rotiraj_rijec+="ay";
				
				if((positions[j]+rijec[i].size())==recenica.size())
					recenica.replace(positions[j],rijec[i].size(),rotiraj_rijec);
				else if(isspace(recenica[positions[j]+rijec[i].size()]))
					recenica.replace(positions[j],rijec[i].size(),rotiraj_rijec);
				if(j==positions.size()-1) break;
				j++;
			}
			else break;
		}
		positions.clear();
	}
	return recenica;
}

void Razmijeni(char &x,char &y)
{
	char pomocna{move(x)};
	x=move(y);
	y=move(pomocna);
}

string IzvrniString (string str)
{
	for(unsigned int i=0;i<str.length()/2;i++)
	{
		Razmijeni(str[i],str[str.length()-1-i]);
	}
	return str;
}

string ObrniFraze (string recenica,vector<string>rijec)
{
	for(unsigned int i=0;i<rijec.size();i++)
	{
		for(;;)
		{
			if(rijec[i].size()!=0 && recenica.find(rijec[i])!=string::npos)
			{
				string obrni_rijec;
				obrni_rijec=IzvrniString(rijec[i]);
				recenica.replace(recenica.find(rijec[i]),rijec[i].size(),obrni_rijec);
			}
			else break;
		}
	}
	return recenica;
}


int main ()
{
	cout<<"Unesite recenicu: ";
	string recenica;
	getline(cin,recenica);
	
	cout<<"Unesite fraze: ";
	
	vector<string> fraza;
	int i{-1};
	do{
		string str;
		i++;
		getline(cin,str);
		fraza.push_back(str);
	}while(fraza[i].size()!=0);
	
	
	try{
		string PigLatinRecenica;
		PigLatinRecenica=IzmijeniUPigLatin(recenica,fraza);
		cout<<"Recenica nakon PigLatin transformacije: ";
		cout<<PigLatinRecenica<<endl;
	}
	catch(domain_error e)
	{
		cout<<"Izuzetak: "<<e.what()<<endl;
	}
	
	cout <<"Recenica nakon obrtanja fraza: ";
	string nova_recenica;
	nova_recenica=ObrniFraze(recenica,fraza);
	cout <<nova_recenica<<endl;
	
	return 0;
}