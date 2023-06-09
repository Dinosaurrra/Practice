#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
//прототип функции
inline bool IsSimple(unsigned long);
int Generator();
int Encrypt(string, int, int);
int Decrypt(string, int, int);

int main()
{
    int p, q, fi, mod;
    p = Generator();
    q = p;
    do {
        p = Generator();
    } while (q == p);

    mod = p * q;
    fi = (p - 1) * (q - 1);

    int e = 2, d = 2;
    for (e;; e++) {
        if (IsSimple(e) and e < fi and (fi % e != 0))
            break;
    }
    for (d;; d++) {
        if ((e * d) % fi == 1)
            break;
    }
    //cout << p << " " << q << endl << mod << " " << fi << endl << e << " " << d;
    cout << "Enter your text :" << endl;
    string text;
    cin >> text;
    Encrypt(text, e, mod);
    //Decrypt(text,d,mod);
}
//проверка на простое число
inline bool IsSimple(unsigned long n)
{
    if (n < 2)
        return false;
    for (unsigned long j = 2; j * j <= n; ++j)
        if (n % j == 0)
            return false;
    return true;
}
 
//генератор простых чисел
int Generator() {
    srand(time(NULL));
    int a;
    unsigned int b = -1;
    for (unsigned long i = 1; i <= 100000; i++)
    {
        a = 2 + rand() % b;
        if (IsSimple(a))
            return a;
    }
}

//зашифровка
int Encrypt(string text, int e, int mod) {
    vector <int> a;
    for (int i = 0; i < text.size(); i++) {
        a.push_back(text[i]);
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < e; j++) {
            a[i] *= e;
        }
        cout << a[i] % mod << " ";
    }
    cout << endl;
    return 0;
}

//расшифровка
int Decrypt(string text, int d, int mod){
    vector<int> b;
    for (int i = 0; i < text.size(); i++) {
        int n;
        cin >> n;
        b.push_back(n);
    }
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < d; j++) {
            b[i] *= d;
        }
        b[i] = b[i] % mod;
    }
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] <<" ";
    }
    return 0;
}