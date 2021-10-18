#include<iostream>

class Temperatura {
    std::list<int> minimalna;
    std::list<int> maksimalna;
    public:
    Temperatura()=default;
    Temperatura(int min, int maks) {
        if(min>maks) throw std::range_error("Nekorektne temperature!");
        minimalna.push_back(min);
        maksimalna.push_back(maks);
    }
    void RegistrirajTemperature(std::pair<int,int> parovi) const {
        if(parovi.first>parovi.second) throw std::range_error("Nekorektne temperature!");
        minimalna.push_back(parovi.first);
        maksimalna.push_back(parovi.second);
    }
    void BrisiSve() const {
        //dva nacina:
        //prvi: minimalna.resize(0); maksimalna.resize(0);
        minimalna.clear();
        maksimalna.clear();
    }
    void BrisiNegativneTemperature() {
        
    }
    int DajBrojRegitiranihTemperature() const {
        auto vrijednost=std::distance(maksimalna.begin(), maksimalna.end());
        return vrijednost;
    }
    int DajMinimalnuTemperaturu() const {
        if(std::distance(minimalna.begin(), minimalna.end())==0) throw std::logic_error("Nema registrovanih temperatura!");
        //ili if(minimalna.size()==0) throw...
        auto pomocna=*(std::min_element(minimalna.begin(),minimalna.end(),std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2)));
        return pomocna;
    }
    int DajMaksimalnuTemperaturu() const {
        if(maksimalna.size()==0) throw std::logic_error("Nema regitrovanih temperatura!");
        auto pomocna=*(std::max_element(maksimalna.begin(),maksimalna.end(),std::bind(std::greater<int>(),std::placeholders::_1,std::placeholders::_2)));
        return pomocna;
    }
    int DajBrojTemperaturaVecihOd(int x) const {
        if(std::distance(maksimalna.begin(),maksimalna.end())==0) throw std::logic_error("Nema registrovanih temperatura!");
        int vrijednost=std::count_if(maksimalna.begin(),minimalna.begin(),std::bind(std::greater<int>(),std::placeholders::_1,x));
        return vrijednost;
    }
    int DajBrojTemperaturaManjihOd(int x) const {
        if(std::distance(minimalna.begin(),minimalna.end())==0) throw std::logic_error("Nema registrovanih temperatura!");
        int vrijednost=std::count_if(minimalna.begin(),minimalna.end(),std::bind(std::less<int>(),std::placeholders::_1,x));
        return vrijednost;
    }
    friend bool operator !(const Temperatura &t);
    
};

bool operator !(const Temperatura &t) {
    if(std::distance(maksimalna.begin(),maksimalna.end())==0) return true;
    else return false;
}

Temperatura &operator ++(Temperatura &t) {
    std::transform(t.maksimalna.begin(),t.minimalna.end(),t.maksimalna.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    std::transform(t.minimalna.begin(),t.minimalna.end(),t.minimalna.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    return t;
}
std::vector<int> operator *(const Temperatura &t) {
    std::vector<int> v(t.maksimalna.size());
    std::transform(t.maksimalna.begin(),t.maksimalna.end(),t.minimalna.begin(),v.begin(),std::bind(std::minus<int>(),std:.placeholders::_1,std::placeholders::_2));
    //ako imamo dva placejolders-a oda mozemo pisati i samo ovako
    //std::transform(t.maksimanlna.begin(),t.maksimalna.end(),t.minimalna.begin(),v.begin(),std::minus<int>());
    return v;
}
bool operator ==(const Temperatura &t1, const Temperatura &t2) {
    if(std::distance(t1.maksimalna.begin(),t1.maksimalna.end())==std::distance(t2.minimalna.begin(),t2.minimalna.end()) && std::equal(t1.maksimalna.begin(),t1.maksimalna.end(),t2.maksimalna.begin()) && std::equal(t1.minimalna.begin(),t1.minimalna.end(),t2.minimalna.begin())) return true;
    else return false;
}
std::ostream &operator <<(stD::ostream &tok, const Temperatura &t) {
    int vel=std::distance(t.minimalna.begin(),t.minimalna.end());
    int brojac=0;
    std::for_each(t.minimalna.begin(),t.minimalna.end(),[&brojac,vel,&tok](int broj){
        if(brojac==vel-1) tok<<broj<<"\n";
        else tok<<broj<<" ";
        brojac++;
    });
    brojac=0;
    std::for_ech(t.maksimalna.begin(),t.maksimalna.end(),[&brojac,vel,&tok](int broj){
        if(brojac==vel-1) tok<<broj<<"\n";
        else tok<<broj<<" ";
        brojac++;
    });
}
    
    
}
    
    
}
    
    
    
    
    
    
    
    
    
}