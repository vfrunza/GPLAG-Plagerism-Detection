#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cctype>
#include <stdexcept>
#include <tuple>
#include <set>
#include <iterator>
#include <map>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::string Izbaci_rijeci(std::string s){
    std::string s1, s2, s3, s4;
    int z(0), k(0);
    for(int i=0; i<s.length()-1; i++){
        s.at(i)=char(std::tolower(s.at(i)));
    	if((s.at(i)==' ')&&s.at(i+1)!=' ')
    	z++;
    }
    z++;
    while(z!=0){
    	int n(0);
    	if(s.length()!=0){
    for(int i=0; i<s.length(); i++){
        if(s.at(i)==' '&&i==0)
        continue;
        if(s.at(i)==' ')
        break;
        s1+=s.at(i);
        n++;
    } 
    s2+=(s1+" ");
    for(int i=n; i<s.length(); i++){
    	s3+=s.at(i);
    }
    s=s3;
    s3.clear();
    if(s.length()==0) break;
    if(s.at(0)==' ');
    k++;
    for(int i=k; i<s.length(); i++){
        if(s.at(i)==' '&&s4!=s1){
            s3+=(s4+" ");
            s4.clear();
            continue;
        }
        if(s.at(i)==' '&&s4==s1){
            s4.clear();
            continue;
        }
        s4+=s.at(i);
        if(i==s.length()-1&&s4!=s1){
            s3+=s4;
            s4.clear();
        }
    }
    s=s3;
    s1.clear();
    s3.clear();
    z--;
    k=0;
    	}
    else break;
}
    return s2;
}

bool Postoji(std::string rijec_v, std::string rec, int pozicija_u_s)
{
	int k(0);
	if(pozicija_u_s+rijec_v.length()<=rec.length()){
	for(int i=pozicija_u_s; i<pozicija_u_s+rijec_v.length();i++){
		if(rijec_v.at(k)!=rec.at(i))
		return false;
		k++;
	}
	int broj=k+pozicija_u_s;
	if(broj<rec.length()&&((rec.at(k+pozicija_u_s)>='A'&&rec.at(k+pozicija_u_s)<='z')||(rec.at(k+pozicija_u_s)>='0'&&rec.at(k+pozicija_u_s)<='9')))
	return false;
	else if(broj<rec.length()&&rec.at(k+pozicija_u_s)==' '&&pozicija_u_s!=0&&((rec.at(pozicija_u_s-1)>='A'&&rec.at(pozicija_u_s-1)<='z')||(rec.at(k+pozicija_u_s)>='0'&&rec.at(k+pozicija_u_s)<='9')))
	return false;
	if(broj>rec.length())
	return false;
	if(broj>rec.length()-1)
	return true;
	return true;
	}
	return false;
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>>KreirajIndeksPojmova(Knjiga k){
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> vrati;
    for(auto ite=k.begin(); ite!=k.end(); ite++){
    std::string poglavlje=ite->first;
        std::vector<std::string> vs(ite->second);
        std::string s;
        for(int i=0; i<vs.size(); i++)
            for(int j=0; j<vs.at(i).size(); j++){
                if(!((vs.at(i).at(j)>='A'&&vs.at(i).at(j)<='z')||(vs.at(i).at(j)>='1'&&vs.at(i).at(j)<='9'))) 
                vs.at(i).at(j)=' ';
                vs.at(i).at(j)=char(std::tolower(vs.at(i).at(j)));
            }
        for(int i=0; i<vs.size(); i++){
            s+=Izbaci_rijeci(vs.at(i));
        }
        s=Izbaci_rijeci(s);
        std::string rijec;
        for(int i=0; i<s.length(); i++){
            if((s.at(i)==' '&&i==0)||(s.at(i)==' '&&i>0&&s.at(i-1)==' ')) continue;
            if(s.at(i)!=' ')
            rijec+=s.at(i);
            else{
                for(int j=0; j<vs.size(); j++){
                    for(int z=0; z<vs.at(j).size(); z++){
                        if(rijec.at(0)==vs.at(j).at(z)&&Postoji(rijec,vs.at(j), z)){
                            vrati[rijec].insert(std::make_tuple(poglavlje, 1+j, z));
                        }
                    }
                }
                rijec.clear();
            }
        }
    } 
    return vrati;
}

std::set<std::tuple<std::string, int, int>>PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<std::tuple<std::string, int, int>>> b){
    int a(0);
    for(auto it=b.begin(); it!=b.end(); it++){
        auto p(it->second.begin());
        if(s==it->first){
            a++;
        }
    }
    if(a==0) throw std::logic_error("Unesena rijec nije nadjena!");
    return b[s];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> b){
    for(auto it=b.begin(); it!=b.end(); it++){
        std::cout<<it->first<<": ";
        auto p(it->second.begin());
        for(int i=0; i<it->second.size(); i++){
            if(i!=it->second.size()-1)
            std::cout<<std::get<0>(*p)<<"/"<<std::get<1>(*p)<<"/"<<std::get<2>(*p)<<", ";
            else
            std::cout<<std::get<0>(*p)<<"/"<<std::get<1>(*p)<<"/"<<std::get<2>(*p)<<std::endl;
            p++;
        }
    }
}

int main ()
{
    Knjiga k;
    std::vector<std::string> vs;
    while(1){
        std::cout<<"Unesite naziv poglavlja: ";
        std::string pogl, tekst;
        std::getline(std::cin, pogl);
        if(pogl==".") break;
        int g(1);
        while(1){
        std::cout<<"Unesite sadrzaj stranice "<<g<<": ";
        std::getline(std::cin, tekst);
        g++;
        if(tekst==".") break;
        vs.push_back(tekst);
        }
          k.insert(std::pair<std::string, std::vector<std::string>>(pogl, vs));
          vs.clear();
    }
    auto b(KreirajIndeksPojmova(k));
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(b);
    while(1){
        std::cout<<"Unesite rijec: ";
        std::string r;
        std::getline(std::cin, r);
        if(r==".") break;
        try{
            auto q(PretraziIndeksPojmova(r, b));
            auto p(q.begin());
            for(int i=0; i<q.size(); i++){
                if(i!=q.size()-1)
                std::cout<<std::get<0>(*p)<<"/"<<std::get<1>(*p)<<"/"<<std::get<2>(*p)<<" ";
                else
                std::cout<<std::get<0>(*p)<<"/"<<std::get<1>(*p)<<"/"<<std::get<2>(*p)<<" "<<std::endl;
                p++;
            }
        }
        catch(std::logic_error iz){
            std::cout<<iz.what()<<std::endl;
        }
    }
	return 0;
}