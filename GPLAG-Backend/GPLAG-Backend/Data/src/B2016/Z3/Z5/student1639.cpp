/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>

using namespace std;

struct Dijete{
    string ime;
    Dijete* sljedeci;
};

void NapraviCvorove(int broj_djece, Dijete*& novi)
{
  vector<Dijete*> djeca(broj_djece, nullptr);
  try
  {
     for(int i=0; i<broj_djece; i++)
     {
         novi=new Dijete;
         cin >> novi->ime;
         djeca.at(i)=novi;
         
     }
    // sad svako dijete ima svoje mjesto u vektoru i treba ih uvezati
    
    for(int i=0; i<broj_djece; i++)
    {
        if(i==broj_djece-1) djeca.at(i)->sljedeci=djeca.at(0); // ako je zadnji nek pokazuje na prvoga
        else djeca.at(i)->sljedeci=djeca.at(i+1);
        
    }
    
    novi=djeca.at(0); // da mi vrati pokazivac na pocetak
    
  }
  catch(bad_alloc)
  {
      for(int i=0; i<broj_djece; i++)
        delete djeca.at(i);
      throw;
  }
}

int DuzinaImena (string ime)
{
    int duzina(0);
    for(int i=0; i<ime.size();i++)
    {
       if((ime.at(i)>='0' and ime.at(i)<='9') or (ime.at(i)>='a' and ime.at(i)<='z') or (ime.at(i)>='A' and ime.at(i)<='Z')) 
            duzina++;
    }
    return duzina;
}


Dijete* dajProsli(Dijete* dijete) {
    Dijete* t = dijete;
    while ( t->sljedeci != dijete ) t = t->sljedeci;
    return t;
}

vector<string> SrediDjecu(Dijete* novi)
{
    vector<string> djeca;
    // prvo dijete rijeseno izvan petlje
    auto a = dajProsli(novi);
    a->sljedeci = novi->sljedeci;
    
    Dijete* zapamti=novi-> sljedeci; 
    djeca.push_back(novi->ime);
    delete novi;
    novi=zapamti; 
    
    Dijete* prethodnik; 
    while(1)
    {
        if(novi->sljedeci==novi) // ako pokazuje sam na sebe tj ako je zadnji clan koji je ostao
        {
            djeca.push_back(novi->ime); 
            a = dajProsli(novi);
            a->sljedeci = novi->sljedeci;
            delete novi;
            break;
        }
        
        zapamti=novi->sljedeci; // kad obrisemo da znamo ko je poslije
        int duzina(DuzinaImena(novi->ime));
        
        while(duzina>=1) // ovako dolazimo do djeteta ispred onog kojeg mi treba
        {
           novi=novi->sljedeci;
           duzina--;
        }
        
        //novi=novi->sljedeci; // dolazi na pravo dijete
        //prethodnik->sljedeci=novi->sljedeci; // sad pokazuje na dijete sljedbenik
        
        djeca.push_back(novi->ime);
        a = dajProsli(novi);
        a->sljedeci=novi->sljedeci;
        delete novi;
        if ( novi == zapamti ) break;
        
        novi=zapamti;
        
    }
    
    return djeca;
}

vector<set<string>> RasporediUTimove(vector<string> djeca, int broj_timova)
{
    int sa_vise_clanova((djeca.size())%(broj_timova));
    int min_br_clanova((djeca.size())/(broj_timova));
    vector<set<string>> timovi;
        
    for(int it=0; it<djeca.size(); it++){
    for(int i=0; i<sa_vise_clanova; i++) // oni timovi sto imaju +1 clanova
    {
        for(int j=0; j<min_br_clanova+1; j++)
        {
            timovi.at(i).insert(djeca.at(it));
            it++;
        }
    }
    
    
    for(int i=sa_vise_clanova; i<timovi.size(); i++)
    {
        for(int j=0; j<min_br_clanova; j++)
        {
            timovi.at(i).insert(djeca.at(it));
            it++;
        }
    }
    }

    return timovi;
}


vector<set<string>> Razvrstavanje (Dijete* novi, int broj_timova)
{
    if(broj_timova<1) throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>> povratni;
    vector<string> djeca = SrediDjecu(novi);
    povratni=RasporediUTimove(djeca, broj_timova);
    return povratni;
}


void IspisiSet1(set<string> setic)
{
    int brojac(1);
    for(auto i = setic.begin(); i!=setic.end(); i++)
    {
        if(brojac==setic.size()) cout << *i;
        else cout << *i << ", ";
        brojac++;
    }
}


void IspisiTimove (vector<set<string>> timovi)
{
    for(int i=0; i<timovi.size(); i++)
    {
        cout << "Tim " << i+1 << ": ";
        IspisiSet1(timovi.at(i));
        cout << endl;
        
    }
}


int main ()
{
    try{
    cout << "Unesite broj djece: ";
    int broj_djece;
    cin >> broj_djece;
    cout << "Unesite imena djece: ";
    Dijete* prvi(nullptr);
    NapraviCvorove(broj_djece, prvi);
    cout << endl << "Unesite broj timova: ";
    int broj_timova;
    cin >> broj_timova;
    IspisiTimove(Razvrstavanje(prvi, broj_timova));
    } catch(bad_alloc){
        cout << "Losa alokacija or whatever";
    } catch(logic_error e)
    {
        cout << e.what();
    }
	return 0;
}









    