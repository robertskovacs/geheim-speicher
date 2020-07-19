#include <iostream>
#include <string>
#include "geheim.h"

using namespace std;

void test(Geheim& g1, Geheim& g2) {
    string pwd1{"xxx"};
    string pwd2{"01234Password"};
    string wrongpwd{"wrongpwd"};

    //Initialisieren mit unlocked Information
    cout << "Initialisieren mit unlocked Information: " << g1 << " - die Information hat die Laenge: " << g1.len() << '\n';

    //Sperren unlocked Information 2x
    g1.lock(pwd1);
    g1.lock(pwd1);
    cout << "Nachdem Schliessen mit Passwort: " << g1 << " - die Information hat die Laenge: " << g1.len() << '\n';

    //Initialisieren mit locked Information
    cout << "Initialisieren mit locked Information: " << g2 << " - die Information hat die Laenge: " << g2.len() << '\n';

    //Unlock unlocked Information
    g2.unlock(wrongpwd);
    cout << "Aufsperren mit falschem Passwort: " << g2 << " - die Information hat die Laenge: " << g2.len() << '\n';

    //2x aufsperren
    g2.unlock(pwd2);
    g2.unlock(pwd2);
    cout << "Aufsperren mit richtigem Passwort: " << g2 << " - die Information hat die Laenge: " << g2.len() << '\n';

    //Zusammensetzungen
    g1.unlock(pwd1);
    auto c {g1 + g2};
    cout << "Alle Geheime sind unlocked: " << c << '\n';

    //g1.lock(pwd1);
    //c = g1 + g2;
    //cout << "Einige Geheim ist locked: " << c << '\n';
}

int main() {
    Geheim g1{"Max"};
    Geheim g2{"Hugo", "01234Password"};
    test(g1, g2);
    return 0;
}