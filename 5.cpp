#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool hasThreeVowels(string str) {
    int count = 0;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'a' ||
            str[i] == 'e' ||
            str[i] == 'i' ||
            str[i] == 'o' ||
            str[i] == 'u') {
            ++count;
        }
    }

    if (count >= 3) {
        return true;
    }

    return false;
}

bool hasTwoInARow(string str) {
    if (str.size() < 2) {
        return false;
    }

    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == str[i-1]) {
            return true;
        }
    }

    return false;
}

bool noBad(string str) {
    if (str.size() < 2) {
        return true;
    }

    for (int i = 0; i < str.size() - 1; ++i) {
        string sub = str.substr(i, 2);
        if (sub == "ab" ||
            sub == "cd" ||
            sub == "pq" ||
            sub == "xy") {
            return false;
        }
    }

    return true;
}

bool hasPairTwice(string str) {
        if (str.size() < 4) {
            return false;
        }

        for (int i = 0; i < str.size() - 1; ++i) {
            string subA = str.substr(i, 2);
            for (int j = i+2; j < str.size() - 1; ++j) {
                string subB = str.substr(j, 2);
                if (subA == subB) {
                    return true;
                }
            }
        }

        return false;
}

bool hasSandWich(string str) {
    if (str.size() < 3) {
        return false;
    }

    for (int i = 0; i < str.size() - 2; ++i) {
            if (str[i] == str[i+2]) {
                return true;
            }
    }

    return false;
}

int main() {
        string temp;

        int count = 0;

        while (cin >> temp) {
           //if (hasThreeVowels(temp) && hasTwoInARow(temp) && noBad(temp)) {
           if (hasPairTwice(temp) && hasSandWich(temp)) {
            ++count;
           } 
        }

        cout << count << endl;

        return 0;
}
