#include <iostream>
using namespace std;
class Complex {
 double real;
 double img;
public:
 Complex();
 friend istream &operator>>(istream &in, Complex &c);
 friend ostream &operator<<(ostream &out, const Complex &c);
 Complex operator+(const Complex &c) const;
 Complex operator*(const Complex &c) const;
};
Complex::Complex() {
 real = 0;
 img = 0;
}
istream &operator>>(istream &in, Complex &c) {
 cout << "Enter Real and Imaginary parts: ";
  in >> c.real >> c.img;
 return in;
}
ostream &operator<<(ostream &out, const Complex &c) {
 out << c.real;
 if (c.img >= 0)
 out << " + " << c.img << "i";
 else
 out << " - " << -c.img << "i";
 return out;
}
Complex Complex::operator+(const Complex &c) const {
 Complex result;
 result.real = real + c.real;
 result.img = img + c.img;
 return result;
}
Complex Complex::operator*(const Complex &c) const {
 Complex result;
 result.real = (real * c.real) - (img * c.img);
 result.img = (real * c.img) + (img * c.real);
 return result;
}
int main() {
 Complex C1, C2, C3, C4;
 char choice;
 do {
 cin >> C1;
 cin >> C2;
 cout << "Complex Number 1: " << C1 << endl;
 cout << "Complex Number 2: " << C2 << endl;
 cout << "**********MENU**********" << endl;
 cout << "1. Addition of Complex Numbers" << endl;
 cout << "2. Multiplication of Complex Numbers" << endl;
 cout << "3. Exit" << endl;
 int operation;
 cout << "Enter your choice from the MENU (1 to 3): ";
 cin >> operation;
 switch (operation) {
 case 1:
 C3 = C1 + C2;
 cout << "Addition: " << C3 << endl;
 break;
 case 2:
 C4 = C1 * C2;
 cout << "Multiplication: " << C4 << endl;
 break;
 case 3:
 cout << "Thanks for using this program!" << endl;
 return 0;
 default:
 cout << "Invalid choice. Exiting..." << endl;
 return 0;
 }
 cout << "Do you want to perform another operation (y/n): ";
 cin >> choice;
 } while (choice == 'y' || choice == 'Y');
 cout << "Thanks for using this program!" << endl;
 return 0;
}

