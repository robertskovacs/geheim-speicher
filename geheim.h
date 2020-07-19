#ifndef GEHEIM_H
#define GEHEIM_H
#include <string>
#include <iostream>

using namespace std;

class Geheim {

    string info;
    string pwd;

public:

    int len() const;
    bool lock(const string&);
    bool unlock(const string&);

    Geheim(const string& information) {
        info = information;
    }

    Geheim(const string& information, const string& passwort) {
        info = information;
        pwd = passwort;
    }

    friend ostream& operator<<(ostream& os, const Geheim& other);
    friend istream& operator>>( istream  &input, Geheim & g );
    friend Geheim operator+(const Geheim& lg, const Geheim& rg);

};

#endif