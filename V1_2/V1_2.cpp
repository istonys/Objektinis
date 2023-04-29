#include "Header.h"
#include "Source.h"

int main()
{
    Studentas studentas1;
    studentas1.vardas("Pirmas");
    studentas1.pavarde("Antras");
    studentas1.nustatyti_egzamino_bala(6);
    studentas1.prideti_pazymi(6);
    studentas1.prideti_pazymi(6);
    studentas1.prideti_pazymi(6);
    Studentas studentas2 = studentas1;
    Studentas studentas3(studentas1);
    cout << studentas3.vardas() << " " << studentas3.pavarde() << endl;
    // start the timer
    auto start = std::chrono::high_resolution_clock::now();
    string skaityti;
    vector<Studentas> grupe;
    vector<string> pirmaEilute;
    srand(time(NULL));
    arGeneruoti(skaityti);
    arSkaityti(skaityti);
    if (skaityti == "t") {
        SkaitymoCiklas(grupe, pirmaEilute, skaityti);
        if (skaityti == "n") {
            Ivestis(grupe);
        }
    }
    else {
        Ivestis(grupe);
    }
    // stop the timer
    auto stop = std::chrono::high_resolution_clock::now();

    // calculate the time taken and print it out
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Visos programos vykdymo laikas: " << duration.count() / 1000.0 << " s" << endl;
    cout << "Programos pabaiga.";
    return 0;
}