/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <tuple>
#include <initializer_list>
#include <algorithm>

class Datum
{
    int dan, mjesec, godina;
    bool TestIspravnosti (int d, int m, int g) {
        int DaniUMjesecu [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (g >= 1 && m >=1 && m <= 12) {
            int ZadnjiDanMjeseca = DaniUMjesecu [m-1];
            if (m == 2 && ((g % 4 == 0 && g % 100 != 0) || (g % 400 == 0))) {
                ZadnjiDanMjeseca = 29;
            }
            return (d >= 1 && d <= ZadnjiDanMjeseca);
        } else {
            return false;
        }
    }
public:
    Datum() { }
    Datum (int dan, int mjesec, int godina) {
        if (!TestIspravnosti(dan, mjesec, godina)) throw std::domain_error ("Neispravan datum");
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }

    void Postavi (int dan, int mjesec, int godina) {
        if (!TestIspravnosti(dan, mjesec, godina)) throw std::domain_error ("Neispravan datum");
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }

    std::tuple <int, int, int > Ocitaj() const {
        return std::make_tuple (dan, mjesec, godina);
    }

    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme
{
    int sati, minute;
public:
    Vrijeme() { }
    Vrijeme(int sati, int minute) {
        if ((sati < 0 || sati > 23) || (minute < 0 || minute > 59)) throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }

    void Postavi(int sati, int minute) {
        if ((sati < 0 || sati > 23) || (minute < 0 || minute > 59)) throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }

    std::pair <int, int > Ocitaj() const {
        return std::make_pair (sati, minute);
    }

    void Ispisi() const {
        if (sati < 10)
            std::cout << "0";
        std::cout << sati << ":";
        if (minute < 10)
            std::cout << "0";
        std::cout << minute;
    }
};

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        Pregled::ime_pacijenta = ime_pacijenta;
        Pregled::datum_pregleda = datum_pregleda;
        Pregled::vrijeme_pregleda = vrijeme_pregleda;
    }

    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        try {
            Pregled::ime_pacijenta = ime_pacijenta;
            Pregled::datum_pregleda.Postavi(dan_pregleda, mjesec_pregleda, godina_pregleda);
            Pregled::vrijeme_pregleda.Postavi(sati_pregleda, minute_pregleda);
        }

        catch (std::domain_error poruka) {
            throw std::domain_error (poruka.what());
        }
    }

    void PromijeniPacijenta (const std::string &ime_pacijenta);
    void PromijeniDatum (const Datum &novi_datum);
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

void Pregled::PromijeniPacijenta (const std::string &ime_pacijenta)
{
    Pregled::ime_pacijenta = ime_pacijenta;
}

void Pregled::PromijeniDatum (const Datum &novi_datum)
{
    Pregled::datum_pregleda = novi_datum;
}

void Pregled::PromijeniVrijeme (const Vrijeme &novo_vrijeme)
{
    Pregled::vrijeme_pregleda = novo_vrijeme;
}

void Pregled::PomjeriDanUnaprijed()
{
    int DaniUMjesecu[] =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::tuple <int, int, int > datumPregleda = datum_pregleda.Ocitaj();
    int ZadnjiDanMjeseca = DaniUMjesecu [std::get < 1 > (datumPregleda)-1];
    if (std::get < 1 > (datumPregleda) == 2 && ((std::get < 2 > (datumPregleda) % 4 == 0 && std::get < 2 > (datumPregleda) % 100 != 0) || (std::get < 2 > (datumPregleda) % 400 == 0))) {
        ZadnjiDanMjeseca = 29;
    }

    std::get < 0 > (datumPregleda) += 1;
    if (std::get < 0 > (datumPregleda)) {
    std::get < 0 > (datumPregleda) = 1;
        std::get < 1 > (datumPregleda) += 1;
        if (std::get < 1 > (datumPregleda) > 12) {
            std::get < 1 > (datumPregleda) = 1;
            std::get < 2 > (datumPregleda) += 1;
        }
    }
}

void Pregled::PomjeriDanUnazad()
{
    int DaniUMjesecu[] =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::tuple <int, int, int > datumPregleda = datum_pregleda.Ocitaj();
    int ZadnjiDanMjeseca = DaniUMjesecu [std::get < 1 > (datumPregleda)-1];
    if (std::get < 1 > (datumPregleda) == 2 && ((std::get < 2 > (datumPregleda) % 4 == 0 && std::get < 2 > (datumPregleda) % 100 != 0) || (std::get < 2 > (datumPregleda) % 400 == 0))) {
        ZadnjiDanMjeseca = 29;
    }

    std::get < 0 > (datumPregleda) -= 1;
    if (std::get < 0 > (datumPregleda) < 1) {
        std::get < 0 > (datumPregleda) = ZadnjiDanMjeseca;
        std::get < 1 > (datumPregleda) -=1;
        if (std::get < 1 > (datumPregleda) < 1) {
            std::get < 1 > (datumPregleda) = 12;
            std::get < 2 > (datumPregleda) -= 1;
        }
    }
}

std::string Pregled::DajImePacijenta() const
{
    return ime_pacijenta;
}

Datum Pregled::DajDatumPregleda() const
{
    return datum_pregleda;
}

Vrijeme Pregled::DajVrijemePregleda() const
{
    return vrijeme_pregleda;
}

bool Pregled::DolaziPrije (const Pregled &p1, const Pregled &p2)
{
    std::tuple < int, int, int > datumPregledaP1 = p1.DajDatumPregleda().Ocitaj();
    std::pair < int, int > vrijeme_pregledaP1 = p1.DajVrijemePregleda().Ocitaj();
    std::tuple < int, int, int > datumPregledaP2 = p2.DajDatumPregleda().Ocitaj();
    std::pair < int, int > vrijeme_pregledaP2 = p2.DajVrijemePregleda().Ocitaj();
    if (std::get < 2 > (datumPregledaP1) > std::get < 2 > (datumPregledaP2)) {
        return false;
    } else if (std::get < 2 > (datumPregledaP1) == std::get < 2 > (datumPregledaP2)) {
        if (std::get < 1 > (datumPregledaP1) > std::get < 1 > (datumPregledaP2)) {
            return false;
        } else if (std::get < 1 > (datumPregledaP1) == std::get < 1 > (datumPregledaP2)) {
            if  (std::get < 0 > (datumPregledaP1) > std::get < 0 > (datumPregledaP2)) {
                return false;
            } else if (std::get < 0 > (datumPregledaP1) == std::get < 0 > (datumPregledaP2)) {
                if (vrijeme_pregledaP1.first > vrijeme_pregledaP2.first) {
                    return false;
                } else if (vrijeme_pregledaP1.first == vrijeme_pregledaP2.first) {
                    if (vrijeme_pregledaP1.second > vrijeme_pregledaP2.second) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void Pregled::Ispisi() const
{
    std::cout << std::setw(30) << std::left << ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout << " ";
    vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}

class Pregledi
{
    Pregled** preglediPok;
    int max_broj_pregleda;
    int broj_pregleda;
public:
    explicit Pregledi (int max_broj_pregleda):max_broj_pregleda(max_broj_pregleda), broj_pregleda(0) {
        if (max_broj_pregleda < 0) throw std::domain_error ("Pogresan parametar");
        preglediPok = new Pregled *[max_broj_pregleda];
    }

    Pregledi (std::initializer_list < Pregled > spisak_pregleda) {
        preglediPok = new Pregled* [spisak_pregleda.size()];
        int index {0};
        broj_pregleda = spisak_pregleda.size();
        max_broj_pregleda = spisak_pregleda.size();
        for (auto i = spisak_pregleda.begin(); i !=spisak_pregleda.end(); i++) {
            preglediPok[index] = new Pregled (*i);
            index++;
        }
    }

    ~Pregledi();
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    Pregledi &operator = (const Pregledi &pregledi);
    Pregledi &operator = (Pregledi &&pregledi);
    void RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled (Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum (const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta (const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum (const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::~Pregledi()
{
    for (int i = 0; i < broj_pregleda; i++)
        delete preglediPok[i];
    delete [] preglediPok;
}

Pregledi::Pregledi (const Pregledi &pregledi):preglediPok(new Pregled *[pregledi.max_broj_pregleda]), broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda)
{
    for (int i = 0; i < pregledi.broj_pregleda; i++) {
        preglediPok[i] = new Pregled (*pregledi.preglediPok[i]);
    }
}

Pregledi::Pregledi (Pregledi &&pregledi):preglediPok(pregledi.preglediPok), broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda)
{
    pregledi.preglediPok = nullptr;
    pregledi.broj_pregleda = 0;
}

Pregledi &Pregledi::operator = (const Pregledi &pregledi)
{
    if (&pregledi != this) {
        this -> ~ Pregledi();
        max_broj_pregleda = pregledi.max_broj_pregleda;
        preglediPok = new Pregled *[pregledi.max_broj_pregleda];
        broj_pregleda = pregledi.broj_pregleda;
        for (int i = 0; i < broj_pregleda; i++) {
            preglediPok[i] = new Pregled (*pregledi.preglediPok[i]);
        }
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    if (&pregledi != this) {
        this -> ~Pregledi();
        max_broj_pregleda = pregledi.max_broj_pregleda;
        broj_pregleda = pregledi.broj_pregleda;
        preglediPok = pregledi.preglediPok;
        pregledi.preglediPok = nullptr;
        pregledi.broj_pregleda = 0;
    }
    return *this;
}

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if (max_broj_pregleda == broj_pregleda) throw std::range_error ("Dostignut maksimalan broj pregleda");
    preglediPok[broj_pregleda] = new Pregled {ime_pacijenta, datum_pregleda, vrijeme_pregleda };
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    if (max_broj_pregleda == broj_pregleda) throw std::range_error ("Dostignut maksimalan broj pregleda");
    try {
        preglediPok[broj_pregleda] = new Pregled {ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda };
        broj_pregleda++;
    } catch(std::domain_error poruka) {
        throw std::domain_error(poruka.what());
    }
}

void Pregledi::RegistrirajPregled (Pregled *pregled)
{
    if (max_broj_pregleda == broj_pregleda) throw std::range_error ("Dostignut maksimalan broj pregleda");
    preglediPok[broj_pregleda] = pregled;
    broj_pregleda++;
}

int Pregledi::DajBrojPregleda() const
{
    return broj_pregleda;
}

int Pregledi::DajBrojPregledaNaDatum (const Datum &datum) const
{
    return std::count_if (preglediPok, preglediPok+broj_pregleda, [&datum](Pregled *pregled) {
        std::tuple < int, int, int > datumPregledaP1 = datum.Ocitaj();
        std::tuple < int, int, int > datumPregledaP2 = pregled-> DajDatumPregleda().Ocitaj();
        return (std::get < 0 > (datumPregledaP1) == std::get < 0 > (datumPregledaP2) && std::get < 1 > (datumPregledaP1) == std::get < 1 > (datumPregledaP2) && std::get < 2 > (datumPregledaP1) == std::get < 2 > (datumPregledaP2));
    });
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if (broj_pregleda == 0) throw std::domain_error ("Nema registriranih pregleda");
    return **std::min_element (preglediPok, preglediPok + broj_pregleda, [] (Pregled *p1, Pregled *p2) {
        std::tuple < int, int, int > datumPregledaP1 = p1->DajDatumPregleda().Ocitaj();
        std::pair < int, int > vrijeme_pregledaP1 = p1->DajVrijemePregleda().Ocitaj();
        std::tuple < int, int, int > datumPregledaP2 = p2->DajDatumPregleda().Ocitaj();
        std::pair < int, int > vrijeme_pregledaP2 = p2->DajVrijemePregleda().Ocitaj();
        if (std::get < 2 > (datumPregledaP1) > std::get < 2 > (datumPregledaP2)) {
            return false;
        } else if (std::get < 2 > (datumPregledaP1) == std::get < 2 > (datumPregledaP2)) {
            if (std::get < 1 > (datumPregledaP1) > std::get < 1 > (datumPregledaP2)) {
                return false;
            }

            else if (std::get < 1 > (datumPregledaP1) == std::get < 1 > (datumPregledaP2)) {
                if (std::get < 0 > (datumPregledaP1) > std::get < 0 > (datumPregledaP2)) {
                    return false;
                }

                else if (std::get < 0 > (datumPregledaP1) == std::get < 0 > (datumPregledaP2)) {
                    if (vrijeme_pregledaP1.first > vrijeme_pregledaP2.first) {
                        return false;
                    } else if (vrijeme_pregledaP1.first == vrijeme_pregledaP2.first) {
                        if (vrijeme_pregledaP1.second > vrijeme_pregledaP2.second) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    });
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if (broj_pregleda == 0) throw std::domain_error ("Nema registriranih pregleda");
    return **std::min_element (preglediPok, preglediPok + broj_pregleda, [] (Pregled *p1, Pregled *p2) {
        std::tuple < int, int, int > datumPregledaP1 = p1->DajDatumPregleda().Ocitaj();
        std::pair < int, int > vrijeme_pregledaP1 = p1->DajVrijemePregleda().Ocitaj();
        std::tuple < int, int, int > datumPregledaP2 = p2->DajDatumPregleda().Ocitaj();
        std::pair < int, int > vrijeme_pregledaP2 = p2->DajVrijemePregleda().Ocitaj();
        if (std::get < 2 > (datumPregledaP1) > std::get < 2 > (datumPregledaP2)) {
            return false;
        } else if (std::get < 2 > (datumPregledaP1) == std::get < 2 > (datumPregledaP2)) {
            if (std::get < 1 > (datumPregledaP1) > std::get < 1 > (datumPregledaP2)) {
                return false;
            }

            else if (std::get < 1 > (datumPregledaP1) == std::get < 1 > (datumPregledaP2)) {
                if (std::get < 0 > (datumPregledaP1) > std::get < 0 > (datumPregledaP2)) {
                    return false;
                }

                else if (std::get < 0 > (datumPregledaP1) == std::get < 0 > (datumPregledaP2)) {
                    if (vrijeme_pregledaP1.first > vrijeme_pregledaP2.first) {
                        return false;
                    } else if (vrijeme_pregledaP1.first == vrijeme_pregledaP2.first) {
                        if (vrijeme_pregledaP1.second > vrijeme_pregledaP2.second) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    });
}

void Pregledi::IsprazniKolekciju()
{
    for (int i = 0; i < broj_pregleda; i++) {
        delete preglediPok[i];
    }
    broj_pregleda = 0;
}

void Pregledi::ObrisiNajranijiPregled()
{
    if (broj_pregleda == 0) throw std::range_error ("Prazna kolekcija");
    Pregled *p = &DajNajranijiPregled();
    for(int i=0;i<broj_pregleda;i++)
    {
        if(preglediPok[i]==p)
        {
            delete preglediPok[i];
            for(int j=i;j<broj_pregleda-1;j++)
                preglediPok[j]=preglediPok[j+1];
            break;
        }
    }
    broj_pregleda--;
}

void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta)
{
    for (int i = 0; i < broj_pregleda; i++) {
        if (preglediPok[i] -> DajImePacijenta() == ime_pacijenta) {
            delete preglediPok[i];
            for (int j = i; j < broj_pregleda - 1; j++)
                preglediPok[j] = preglediPok [j+1];
            broj_pregleda--;
            i--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum (const Datum &datum) const
{
    std::sort (preglediPok, preglediPok + broj_pregleda, [] (Pregled *p1, Pregled *p2) {
        std::tuple < int, int, int > datumPregledaP1 = p1->DajDatumPregleda().Ocitaj();
        std::pair < int, int > vrijeme_pregledaP1 = p1->DajVrijemePregleda().Ocitaj();
        std::tuple < int, int, int > datumPregledaP2 = p2->DajDatumPregleda().Ocitaj();
        std::pair < int, int > vrijeme_pregledaP2 = p2->DajVrijemePregleda().Ocitaj();
        if (std::get < 2 > (datumPregledaP1) > std::get < 2 > (datumPregledaP2)) {
            return false;
        } else if (std::get < 2 > (datumPregledaP1) == std::get < 2 > (datumPregledaP2)) {
            if (std::get < 1 > (datumPregledaP1) > std::get < 1 > (datumPregledaP2)) {
                return false;
            }

            else if (std::get < 1 > (datumPregledaP1) == std::get < 1 > (datumPregledaP2)) {
                if (std::get < 0 > (datumPregledaP1) > std::get < 0 > (datumPregledaP2)) {
                    return false;
                }

                else if (std::get < 0 > (datumPregledaP1) == std::get < 0 > (datumPregledaP2)) {
                    if (vrijeme_pregledaP1.first > vrijeme_pregledaP2.first) {
                        return false;
                    } else if (vrijeme_pregledaP1.first == vrijeme_pregledaP2.first) {
                        if (vrijeme_pregledaP1.second > vrijeme_pregledaP2.second) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    });
    std::tuple < int, int, int > datumPregledaP1 = datum.Ocitaj();
    std::tuple < int, int, int > datumPregledaP2;
    for (int i = 0; i < broj_pregleda; i++) {
        datumPregledaP2 = preglediPok[i] ->DajDatumPregleda().Ocitaj();
        if (std::get < 0 > (datumPregledaP1) == std::get < 0 > (datumPregledaP2) && std::get < 1 > (datumPregledaP1) == std::get < 1 > (datumPregledaP2) && std::get < 2 > (datumPregledaP1) == std::get < 2 > (datumPregledaP2))
            preglediPok[i] -> Ispisi();
    }
}

void Pregledi::IspisiSvePreglede() const
{
    std::sort (preglediPok, preglediPok + broj_pregleda, [] (Pregled *p1, Pregled *p2) {
        std::tuple < int, int, int > datumPregledaP1 = p1->DajDatumPregleda().Ocitaj();
        std::pair < int, int > vrijeme_pregledaP1 = p1->DajVrijemePregleda().Ocitaj();
        std::tuple < int, int, int > datumPregledaP2 = p2->DajDatumPregleda().Ocitaj();
        std::pair < int, int > vrijeme_pregledaP2 = p2->DajVrijemePregleda().Ocitaj();
        if (std::get < 2 > (datumPregledaP1) > std::get < 2 > (datumPregledaP2)) {
            return false;
        } else if (std::get < 2 > (datumPregledaP1) == std::get < 2 > (datumPregledaP2)) {
            if (std::get < 1 > (datumPregledaP1) > std::get < 1 > (datumPregledaP2)) {
                return false;
            }

            else if (std::get < 1 > (datumPregledaP1) == std::get < 1 > (datumPregledaP2)) {
                if (std::get < 0 > (datumPregledaP1) > std::get < 0 > (datumPregledaP2)) {
                    return false;
                }

                else if (std::get < 0 > (datumPregledaP1) == std::get < 0 > (datumPregledaP2)) {
                    if (vrijeme_pregledaP1.first > vrijeme_pregledaP2.first) {
                        return false;
                    } else if (vrijeme_pregledaP1.first == vrijeme_pregledaP2.first) {
                        if (vrijeme_pregledaP1.second > vrijeme_pregledaP2.second) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    });
    for (int i = 0; i < broj_pregleda; i++) {
        preglediPok[i] -> Ispisi();
    }
}


int main ()
{
    int maxBrojPregleda;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin >> maxBrojPregleda;
    Pregledi preglediP(maxBrojPregleda);
    for(int i=0;i<maxBrojPregleda;i++)
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::string imePacijenta;
        std::cout <<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::getline (std::cin,imePacijenta);
        if(imePacijenta=="kraj")
        {
            break;
        }
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan,mjesec,godina;
        std::cin>>dan>>mjesec>>godina;
        std::cout << "Unesite sate i minute pregleda: ";
        int sati,minute;
        std::cin>>sati>>minute;
        try
        {
            Pregled *p=new Pregled(imePacijenta,dan,mjesec,godina,sati,minute);
            preglediP.RegistrirajPregled(p);
            p=nullptr;
        }
        catch(std::domain_error poruka)
        {
            std::cout << poruka.what()<< std::endl;
        }
        catch(std::range_error poruka)
        {
            std::cout << poruka.what()<< std::endl;
        }
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    preglediP.IspisiSvePreglede();
    for(;;)
    {
        std::cout<<"\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
        int opcija;
        std::cin>>opcija;
        if(opcija==1)
        {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int dan,mjesec,godina;
            std::cin>>dan>>mjesec>>godina;
            Datum datum(dan,mjesec,godina);
            int brojPregledaNaDatum=preglediP.DajBrojPregledaNaDatum(datum);
            std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<brojPregledaNaDatum;
        }
        else if(opcija==2)
        {
            try
            {
                Pregled p=preglediP.DajNajranijiPregled();
                std::cout<<"Najraniji pregled je:\n";
                p.Ispisi();
            }
            catch(std::domain_error poruka)
            {
                std::cout<<poruka.what();
            }
            
        }
        else if(opcija==3)
        {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::string imePacijenta;
            std::cout<<"Unesite ime pacijenta: ";
            std::getline (std::cin,imePacijenta);
            int brP=preglediP.DajBrojPregleda();
            preglediP.ObrisiPregledePacijenta(imePacijenta);
            int brP1=preglediP.DajBrojPregleda();
            std::cout<<"Uspjesno obrisano "<< brP-brP1 <<" pregleda";
        }
        else if(opcija==4)
        {
            try
            {
                preglediP.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan";
            }
            catch(std::range_error poruka)
            {
                std::cout<<poruka.what();
            }
        }
        else if(opcija==5)
        {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int dan,mjesec,godina;
            std::cin>>dan>>mjesec>>godina;
            Datum datum(dan,mjesec,godina);
            std::cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:\n";
            preglediP.IspisiPregledeNaDatum(datum);
        }
        else if(opcija==6)
        {
            preglediP.IspisiSvePreglede();
        }
        else if(opcija==7)
        {
            return 0;
        }
        std::cout<<std::endl;
    }
    return 0;
}
