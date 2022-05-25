#include <iostream>
#include <cmath>
using namespace std;
class KVADRAT {
    public:
        float a , b , c;
        virtual void KvildizO (float a , float b , float c) {
            float D;
            D = b * b - 4 * a * c;
            cout << "Natija (asosiy sinf):\n\n";
            if (D < 0 && a != 0) {
                cout << "Berilgan tenglama yechimga ega emas! (Haqiqiy sonlarda)" << endl;
            }
            if (D > 0 && a != 0) {
                cout << "x1 = " << (- b + sqrt(D)) / (2 * a) << endl;
                cout << "\nx2 = " << (- b - sqrt(D)) / (2 * a) << endl;
            }
            if (D == 0 && a != 0) {
                cout << "x = " << (- b) / (2 * a) << endl;
            }
            if (a == 0) {
                cout << c / b << endl;
            }
        }
};
class BIKVADRAT : public KVADRAT {
    public:
        int d;
        float d1;
        int Power (int x) {
            d = x;
            d1 = x;
        }
        void KvildizO (float a , float b , float c) override {
            float D , x1 , x2;
            D = b * b - 4 * a * c;
            cout << "\nNatija (voris sinf):\n\n";
            if (D < 0) {
                cout << "Berilgan tenglama yechimga ega emas! (Haqiqiy sonlarda)" << endl;
            }
            if (D > 0) {
                x1 = (- b + sqrt(D)) / (2 * a);
                x2 = (- b - sqrt(D)) / (2 * a);
            }
            if (D == 0) {
                x1 = (- b) / (2 * a);
            }
            if (a > 0 && b > 0 && c > 0) {
                cout << "Berilgan tenglama yechimga ega emas! (Haqiqiy sonlarda)" << endl;
            }
            if (d % 2 == 0) {
                if (x1 < 0) {
                cout << "Tenglamaning 1 - , 2 - ildizi mavjud emas!" << endl;
                }
                if (x1 > 0 || (a * pow(x1 , 2 * d1) + b * pow(x1 , d1) + c) == 0) {
                    cout << "x1 = " << pow(x1 , 1 / d1) << endl;
                    cout << "x2 = " << -pow(x1 , 1 / d1) << endl;
                }
                if (x2 < 0) {
                    cout << "Tenglamaning 3 - , 4 - ildizi mavjud emas!" << endl;
                }
                if (x2 > 0 || (a * pow(x2 , 2 * d1) + b * pow(x2 , d1) + c) == 0) {
                    cout << "x3 = " << pow(x2 , 1 / d1) << endl;
                    cout << "x4 = " << -pow(x2 , 1 / d1) << endl;
                }
            }
            if (d % 2 == 1) {
                cout << "x1 = " << pow(x1 , 1 / d1) << endl;
                cout << "x2 = " << pow(x2 , 1 / d1) << endl;
            }
        }
};
int main() {
    float A , B , C;
    int D;
    string sample;
    cout << "Enter the value of A : ";
    cin >> A;
    cout << "Enter the value of B : ";
    cin >> B;
    cout << "Enter the value of C : ";
    cin >> C;
    cout << "Berilgan tenglama bikvadratmi ? ( Yes / No )\n";
    cin >> sample;
    if (sample == "Yes" || sample == "y" || sample == "yes" || sample == "Y") {
        cout << "Uning eng kichik darajasini kiriting : ";
        cin >> D;
        BIKVADRAT myobj2;
        cout << "*************************\n";
        myobj2.Power(D);
        myobj2.KvildizO(A,B,C);
        cout << "\n*************************";
    }
    else {
        KVADRAT myobj1;
        cout << "*************************\n";
        myobj1.KvildizO(A,B,C);
        cout << "\n*************************";
    }
    return 0;
}
