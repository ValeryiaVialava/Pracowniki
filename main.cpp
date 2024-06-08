#include <iostream>
#include "bibl.h"
using namespace std;
int main() {
        Firma F ("SpaceX");
        F+= new PracownikEtatowy ("Kumi", "Kumi", "himik_jaderszyk", 300);
        F+= new PracownikAkordowy ("Haba", "Haba", "klik_pusk", 10,50);
        F+= new PracownikEtatowy  ("Am miam", "Ivanowicz", "senior eblan", 800);
        cout << F << endl;

        Firma A ("Tesla");
        A+= new PracownikEtatowy ("Laka", "Laka", "inzynier", 300);
        A+= new PracownikAkordowy ("Kapi", "Toszka", "klik_pusk", 20,60);
        A+= new PracownikEtatowy ("Mew", "Mew", "Kisa",900);
        A+= new PracownikAkordowy ("Haba", "Starszyj", "uwazajemyj klik_pusk", 10,70);
        cout << A << endl;

        if (F>A)
            cout << F.GetName() << " zatrudnia wiecej osob niz " << A.GetName()<<endl;
        else if (F<A)
            cout << A.GetName() << " zatrudnia wiecej osob niz " << F.GetName()<<endl;
        else
            cout << " zatrudnia jednokowa liość osob " << endl;

        F.DeletePracownikAkordowy();
        A.DeletePracownikAkordowy();

        cout << "----------------------------------"<<endl;

        cout << F << endl;
        cout << A << endl;

    return 0;
}
