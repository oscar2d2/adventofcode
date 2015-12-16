#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int maxOf2(int a, int b) {
    return a >= b? a: b;
}

int maxOf3(int a, int b, int c) {
    return max(max(a,b), max(b,c));
}

int minOf2(int a, int b) {
    return a <= b? a: b;
}

int minOf3(int a, int b, int c) {
        return min(min(a,b), min(b,c));
}

int main() {

        int arr[3];
        int l, w, h;
        int total = 0;
        int feet = 0;
        string str, word;

        while (cin >> str) {
                stringstream stream(str);

                int i = 0;
                while( getline(stream, word, 'x') ) {
                        arr[i] = stoi(word);
                        ++i;
                }
                l = arr[0];
                w = arr[1];
                h = arr[2];

                total += 2*(l*w + w*h + h*l);                
                total += minOf3(l*w, w*h, h*l);

                feet += 2*(l+w+h-maxOf3(l,w,h));
                feet += l*w*h;
        }

        cout << total << endl;
        cout << feet << endl;

        return 0;
}
