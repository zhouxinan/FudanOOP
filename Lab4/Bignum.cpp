#include "lab4.h"

Bignum::Bignum() {
    setNumber("0");
}

Bignum::Bignum(const string& str) {
    setNumber(str);
}

void Bignum::setNumber(const string& str) {
    if (isTooLong(str)) {
        cout << "The input number " << str << " is too long, set its value to 0 instead." << endl;
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
    resetLength();
}

string Bignum::toString() {
    string str = "";
    for (int i = length - 1; i >= 0; --i) {
        str += char(digit[i] + '0');
    }
    return str;
}

bool isTooLong(const string& str) {
    if (str.length() > BIGNUM_INPUT_MAXLEN) {
        return true;
    }
    return false;
}

// return 1 if a > b, return 0 if a = b, return -1 if a < b.
int compare(const Bignum& a, const Bignum& b) {
    if (a.length > b.length) {
        return 1;
    } else if (a.length < b.length) {
        return -1;
    } else {
        for (int i = a.length - 1; i >= 0; --i) {
            if (a.digit[i] > b.digit[i]) {
                return 1;
            } else if (a.digit[i] < b.digit[i]) {
                return -1;
            }
        }
    }
    return 0;
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

Bignum operator+(const Bignum& a, const Bignum& b) {
    Bignum c;
    c.length = 0;
    for (int i = 0, carry = 0; carry || i < max(a.length, b.length); ++i) {
        int currentDigit = carry;
        if (i < a.length) {
            currentDigit += a.digit[i];
        }
        if (i < b.length) {
            currentDigit += b.digit[i];
        }
        c.digit[i] = currentDigit % 10;
        c.length++;
        carry = currentDigit / 10;
    }
    return c;
}

Bignum operator-(const Bignum& a, const Bignum& b) {
    Bignum c;
    c.length = 0;
    for (int i = 0, borrow = 0; i < a.length; ++i) {
        int currentDigit = a.digit[i] - borrow;
        borrow = 0;
        if (i < b.length) {
            currentDigit -= b.digit[i];
        }
        if (currentDigit < 0) {
            borrow = 1;
            currentDigit += 10;
        }
        c.digit[i] = currentDigit;
        c.length++;
    }
    c.resetLength();
    return c;
}

Bignum operator*(const Bignum& a, const Bignum& b) {
    Bignum c;
    c.length = a.length + b.length; // set the largest possible length first, and reset it to the proper value later.
    for (int i = 0; i < a.length; ++i) {
        for (int j = 0; j < b.length; ++j) {
            c.digit[i + j] += a.digit[i] * b.digit[j]; 
        }
    }
    for (int i = 0; i < c.length; ++i) {
        c.digit[i + 1] += c.digit[i] / 10;
        c.digit[i] %= 10;
    }
    c.resetLength(); 
    return c;
}

Bignum operator/(const Bignum& a, const Bignum& b) {
    Bignum c;
    Bignum f;
    for (int i = a.length - 1; i >= 0; --i) {
        f = f * Bignum("10");
        f.digit[0] = a.digit[i];
        while (compare(f, b) >= 0) {
            f = f - b;
            c.digit[i]++;
        }
    }
    c.length = a.length; // set the largest possible length first, and reset it to the proper value later.
    c.resetLength();
    return c;
}

void Bignum::resetLength() {
    while (length > 1 && (digit[length - 1] == 0)) {
        length--;
    }
}