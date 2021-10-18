#include<iostream>
using namespace std;
class Datum
{   
    int dan,mjesec,godina;
    public:
    Datum(int dan, int mjesec, int godina){
        
    }
    void Postavi(int dan, int mjesec, int mjesec){
        *this=Datum(dan,mjesec,godina);
    }
    int DajDan() const{return dan;}
    int DajMjesec() const{return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi() const{
        cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

int main()
{


    return 0;
}