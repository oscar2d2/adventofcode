#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
        stack<char> s;
        string str;

        cin >> str;

        int level = 0;
        int base = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                    ++level;
            } else {
                    --level;
            }

            if (level == -1 && base == 0) {
                base = i + 1;
            }
        }

        cout << level << endl;
        cout << base << endl;

        return 0;
}
