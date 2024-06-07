#include <iostream>
#include "bibl.h"
using namespace std;
int main() {
        Firma F ("SpaceX");
        F+= new PracownikEtatowy ("kumi", "kumi", "himik_jaderszyk", 300);
        F+= new PracownikAkordowy ("haba", "haba", "klik_pusk", 10,400);
        F+= new PracownikEtatowy  ("am miam", "Ivanowicz", "senior eblan", 80);
        cout << F << endl;


    return 0;
}
