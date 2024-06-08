#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Pracownik {
protected:
    string FirstName;
    string LastName;
    string Stanowisko;
    bool CzyAkordowy = false;

public:
    Pracownik (string firstName, string lastName, string stanowisko){
        this->FirstName = firstName;
        this->LastName = lastName;
        this->Stanowisko=stanowisko;

    }
    virtual ~Pracownik(){};
    virtual double obliczWyplate() const = 0;
    virtual void print (ostream& os) const {
        os << "Person: " <<FirstName << " " << LastName << ", job: " << Stanowisko << ", salary: " << obliczWyplate() << endl;
    }

    bool GetCzyAkordowy (){
        return CzyAkordowy;
    }

    friend ostream& operator<<(ostream& os, Pracownik& P){
        P.print(os);
        return os;
    }

};

class PracownikEtatowy : public Pracownik{
private:
    double pensja;
public:
    PracownikEtatowy(string imie=" ", string nazwisko=" ", string stan=" ", double pensjaM=0): Pracownik (imie, nazwisko, stan){
        pensja=pensjaM;

    }
    double obliczWyplate() const override{
        return pensja;
    }


};

class PracownikAkordowy: public Pracownik{
private:
    int stuka;
    double kwota;

public:
    PracownikAkordowy(string imie=" ", string nazwisko=" ", string stan="", int counter=0, double cost=0): Pracownik(imie, nazwisko, stan){
        stuka=counter;
        kwota=cost;
        CzyAkordowy=true;
    }

    double obliczWyplate() const override{
        return kwota*stuka;
    }

};

class Firma {
private:
    string nazwa;
    vector <Pracownik*> pracowniki;
//  int counter =0;

    void clear (){
        for (int i=0; i < pracowniki.size(); i++ ){
            delete pracowniki[i] ;
        }
        pracowniki.clear();
    }

public:
    Firma (string name){
        nazwa = name;
    }
    ~Firma(){
        clear ();
    }

    Firma& operator+=(Pracownik* p){
        pracowniki.push_back(p);
//        counter++;
        return *this;
    }

    double obliczSumWyplate () const{
        double sum=0;
        for (auto & i : pracowniki){
            sum += i -> obliczWyplate();
        }
        return sum;
    }

     friend ostream& operator<<(ostream& os, const Firma& F) {
         os << "Firma: "<< F.nazwa;
         os << endl;
         for (int i = 0; i < F.pracowniki.size(); i++) {
             F.pracowniki[i] -> print (os);
         }
         os << "Total Salary: " << F.obliczSumWyplate() << endl;
         return os;
     }

//     int GetCounter (){
//        return counter;
//    }

//    bool operator>(const Firma& F) const{
//        return counter>F.counter;
//    }
//    bool operator<(const Firma& F) const{
//        return counter<F.counter;
//    }

    bool operator>(const Firma& F) const{
        return pracowniki.size()>F.pracowniki.size();
    }

    bool operator<(const Firma& F) const{
        return pracowniki.size()<F.pracowniki.size();
    }

    string GetName () {
        return nazwa;
    }

    Firma& DeletePracownikAkordowy() {
        for (auto it = pracowniki.begin(); it != pracowniki.end();) {
            if ((*it)->GetCzyAkordowy()) {
                it = pracowniki.erase(it);
            } else {
                ++it;
            }
        }
        return *this;
    }
};
template <typename T>
class MojSzab {
private:
    vector <T*> Pracowniki;
public:
    ~MojSzab() {
        for (T* pracownik : Pracowniki) {
            delete pracownik;
        }
    }
    void dodaj (T* pracownik){
        Pracowniki.push_back(pracownik);
    }
    void drukuj (){
        for (const T* pracownik : Pracowniki){
            cout << *pracownik <<endl;
        }
    }

};
