#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> djeca,int br_timova){
    if((br_timova<1) or(br_timova>djeca.size()))
        throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<int> brojaci(br_timova);
    for(int i=0; i<brojaci.size(); i++){
        brojaci[i]=djeca.size()/br_timova;
        if(i<djeca.size()%br_timova)
            brojaci[i]++;
    }
    Dijete *prvi=nullptr,*prethodni;
    for(int i=0; i<djeca.size(); i++){
        Dijete *novi(nullptr);
        novi=new Dijete;
        novi->ime=djeca[i];
        novi->sljedeci=nullptr;
        if(i+1==djeca.size())
            novi->sljedeci=prvi;
        if(!prvi)
            prvi=novi;
        else
            prethodni->sljedeci=novi;
        
        prethodni=novi;
    }
/*    for(int i=0; i<brojaci.size(); i++)
        std::cout<<brojaci[i]<<" kjafs ";
     Dijete *k=prvi; int l(0);
    for(; k!=k->sljedeci; k=k->sljedeci){
        std::cout<<k->ime<<"   ";
        std::cout<<std::endl;
        if(l==5) break;
        l++;
    }   */
  //  std::cout<<prethodni->ime;
    std::vector<std::set<std::string>> timovi(br_timova);
    int i(0);
    Dijete *p=prvi;
    for(; ; ){
        int br_slova(p->ime.size());
        if(brojaci[i]!=0){
            timovi[i].insert(p->ime);
            brojaci[i]--;
            for(auto x : p->ime){
                if( (x==' ') or (((((x<'0')or(x>'9'))and(x<'a'))or(x>'z'))and((x<'A')or(x>'Z'))))
                    br_slova--;
            }
        //    std::cout<<br_slova;
        if(p==p->sljedeci) break;
            if(p==prethodni)
                for( ;prethodni->sljedeci!=p ; prethodni=prethodni->sljedeci );
            prethodni->sljedeci=p->sljedeci;
            delete p;
            p=prethodni->sljedeci;
            
            
            
            for(int j(1); j<br_slova; j++)
                p=p->sljedeci;
        }else i++;
    }
    delete p;
    return timovi;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int br;
    std::cin>>br;
    std::cin.ignore(10000,'\n');
    std::vector<std::string> a(br);
    std::cout<<"Unesite imena djece: ";
    for(int i=0; i<br; i++){
        std::getline(std::cin,a[i]);
    }
    int b;
    std::cout<<std::endl<<"Unesite broj timova: ";
    std::cin>>b;
    try{
        auto c(Razvrstavanje(a,b));
        for(int i=0;i<c.size(); i++){
            std::cout<<"Tim "<<i+1<<": ";
            for(auto it(c[i].begin()); it!=c[i].end(); it++){
                if(++it==c[i].end()){
                    it--;
                    std::cout<<*it;
                }else{
                    it--;
                    std::cout<<*it<<", ";
                }
            }
            std::cout << std::endl;
            
        }
        
    }catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}