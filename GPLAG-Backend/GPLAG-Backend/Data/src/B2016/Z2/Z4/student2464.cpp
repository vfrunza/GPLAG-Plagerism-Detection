#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int PotencijalniKrivci(char **&imena, vector<string> spisak)
{
    try
    {
        char **npok=new char*[spisak.size()]{};
        try
        {
            for(int i=0;i<spisak.size();i++)
            {
                npok[i]=new char[spisak[i].length()+1];
                for(int k=0;k<spisak[i].length();k++) npok[i][k]=spisak[i][k];
                npok[i][spisak[i].length()]='\0';
            }
        }
        catch(std::bad_alloc)
        {
            for(int i=0;i<spisak.size();i++) delete[] npok[i];
            delete[] npok;
            throw;
        }
        imena=npok;
        return spisak.size();
    }
    catch(std::bad_alloc)
    {
        throw;
    }
}

int OdbaciOptuzbu(char **&imena, int vel, string lik)
{
    bool ima=false;
    for(int i=0;i<vel;i++)
    {
        bool isti=true;
        int j, duz=0;;
        while(imena[i][duz]!='\0') duz++;
        for(j=0;j<lik.length() && j<duz;j++)
        {
            if(imena[i][j]!=lik[j]) isti=false;
        }
        if(j!=lik.length() || j!=duz) isti=false;
        if(isti)
        {
            ima=true;
            delete[] imena[i];
            imena[i]=nullptr;
        }
    }
    if(!ima) throw std::domain_error("Osoba sa imenom "+lik+" nije bila optuzena\n");
    
    int brnul=0;
    for(int i=0;i<vel;i++) if(imena[i]==nullptr) brnul++;
    if(brnul>10)
    {
        try
        {
            int nvel=vel-brnul;
            char **npok=new char*[nvel]{};
            try
            {
                int m=0;
                for(int i=0;i<vel;i++)
                {
                    if(imena[i]!=nullptr)
                    {
                        int duz=0;
                        while(imena[i][duz]!='\0') duz++;
                        duz++;
                        npok[m]=new char[duz];
                        for(int k=0;k<duz;k++) npok[m][k]=imena[i][k];
                        m++;
                    }
                    delete[] imena[i];
                }
                delete[] imena;
                vel=nvel;
                imena=npok;
            }
            catch(...)
            {
                for(int i=0;i<nvel;i++) delete[] npok[i];
                delete[] npok;
                throw;
            }
        }
        catch(...){;}
    }
    
    return vel;
}

int DodajOptuzbu(char **&imena, int vel, string lik)
{
    char *nime=new char[lik.length()+1];
    for(int i=0;i<lik.length();i++) nime[i]=lik[i];
    nime[lik.length()]='\0';
    bool ima=false;
    for(int i=0;i<vel;i++)
    {
        if(imena[i]==nullptr)
        {
            ima=true;
            imena[i]=nime;
            return vel;
        }
    }
    if(!ima)
    {
        try
        {
            char **npok=new char*[vel+1]{};
            try
            {
                for(int i=0;i<vel;i++)
                {
                    int duz=0;
                    while(imena[i][duz]!='\0') duz++;
                    duz++;
                    npok[i]=new char[duz];
                    for(int j=0;j<duz;j++) npok[i][j]=imena[i][j];
                    delete[] imena[i];
                }
                delete[] imena;
                npok[vel]=nime;
                imena=npok;
                vel++;
            }
            catch(...)
            {
                for(int i=0;i<vel+1;i++) delete[] npok[i];
                delete[] npok;
                throw;
            }
        }
        catch(std::bad_alloc)
        {
            throw;
        }
    }
    return vel;
}

void IzlistajOptuzbu(char **imena, int vel)
{
    for(int i=0;i<vel;i++)
    {
        if(imena[i]!=nullptr) cout << imena[i] << "\n";
    }
}

int main ()
{
    int n;
    cout <<"Koliko potencijalnih krivaca zelite unijeti?\n";
    cin >> n;
    vector<string> v(n);
    cout <<"Unesite potencijalne krivce:\n";
    for(string &x : v) cin >> x;
    char **a;
    n=PotencijalniKrivci(a, v);
    int op;
    string ime;
    do
    {
        cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:\n";
        cin >> op;
        if(op==1)
        {
            cout << "Unesite ime novog optuzenog:\n";
            cin >> ime;
            n=DodajOptuzbu(a, n, ime);
        }
        if(op==2)
        {
            cout << "Unesite ime koje zelite izbaciti:\n";
            cin >> ime;
            n=OdbaciOptuzbu(a, n, ime);
        }
        if(op==3) IzlistajOptuzbu(a, n);
    } while(op!=0);
    for(int i=0;i<n;i++) delete[] a[i];
    delete[] a;
	return 0;
}