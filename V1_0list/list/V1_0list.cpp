#include "Header.h"
#include "Source.h"

int main()
{
    // start the timer
    auto start = std::chrono::high_resolution_clock::now();
    string skaityti;
    list<Studentas> grupe;
    list<string> pirmaEilute;
    srand(time(NULL));
    arGeneruoti(skaityti);
    arSkaityti(skaityti);
    if (skaityti == "t") {
        SkaitymoCiklas(grupe, pirmaEilute, skaityti);
        if (skaityti == "n") {
            Ivestis(grupe);
            Vidurkis(grupe);
            Mediana(grupe);
        }
    }
    else {
        Ivestis(grupe);
        Vidurkis(grupe);
        Mediana(grupe);
    }
    //Spausdinti(grupe);
    //for (int i = 0; i < Failai.size(); i++) {
    //    remove(Failai[i].c_str());
    //}
    // stop the timer
    auto stop = std::chrono::high_resolution_clock::now();

    // calculate the time taken and print it out
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Visos programos vykdymo laikas: " << duration.count() / 1000.0 << " s" << endl;
    cout << "Programos pabaiga.";
    return 0;
}