#include "geheim.h"
#include <string>
#include <iostream>

using namespace std;

Geheim operator+(const Geheim& lg, const Geheim& rg) {
    if(lg.pwd.size()==0 && rg.pwd.size()==0)
        return lg.info + rg.info;
    throw runtime_error("Zumindest eine Information ist mit Passwort geshuetzt!");
}

istream& operator>>(istream& input, Geheim& g ) {
    input >> g.info >> g.pwd;
    return input;
}

ostream& operator<<(ostream& output, const Geheim& g)
{
    if(g.pwd.size()==0) {
        output << g.info;
        return output;
    }
    else
        return output;
}

bool Geheim::lock(const string& passwort) {
    if(pwd.size()==0) {
        pwd=passwort;
        return true;
    }
    return false;
}

bool Geheim::unlock(const string& passwort) {
    if(pwd.size()>0 && passwort == pwd) {
        pwd.clear();
        return true;
    }
    return false;
}

int Geheim::len() const{
    if(pwd.size()==0)
        return info.size();
    return 0;
}

