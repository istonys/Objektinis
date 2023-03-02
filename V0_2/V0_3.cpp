#include "Header.h"
#include "Source.h"

int main()
{
    string skaityti;
    vector<Studentas> grupe;
    vector<string> pirmaEilute;
    srand(time(NULL));
    cout << "Ar norite duomenis skaityti is failo? Jei ne, irasysite ranka. Y / N: ";
    do {
        cin >> skaityti;
        transform(skaityti.begin(), skaityti.end(), skaityti.begin(), ::tolower);
        if (skaityti != "y" && skaityti != "n") {
            cout << "Netinkama ivestis. Iveskite Y arba N." << endl;
        }
    } while (skaityti != "y" && skaityti != "n");
    if (skaityti == "y") {
        Skaityti(grupe, pirmaEilute);
        sort(grupe.begin(), grupe.end(), lygintiVardus);
    }
    else Ivestis(grupe);
    Vidurkis(grupe);
    Mediana(grupe);
    Spausdinti(grupe);
    cout << "Programos pabaiga.";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
