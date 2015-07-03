#include "lab4.h"

Bignum::Bignum() {
    setNumber("0");
}

Bignum::Bignum(const string& str) {
    setNumber(str);
}

void Bignum::setNumber(const string& str) {
    if (isTooLong(str)) {
        setNumber("0");
        return;
    }
    for (int i = 0; i < BIGNUM_MAXLEN; ++i) {
        digit[i] = 0;
    }
    length = str.length();
    for (int i = 0; i < length; ++i) {
        digit[i] = str[length - 1 - i] - '0';
    }
}

string Bignum::toString() {
    string str = "";
    for (int i = length - 1; i >= 0; --i) {
        str += char(digit[i] + '0');
    }
    return str;
}

bool isTooLong(const string& str) {
    if (str.length() > BIGNUM_MAXLEN) {
        return true;
    }
    return false;
}

istream& operator>>(istream& is, Bignum& bignum) {
    string str;
    is >> str;
    bignum.setNumber(str);
    return is;
}

ostream& operator<<(ostream& os, Bignum& bignum) {
    os << bignum.toString();
    return os;
}