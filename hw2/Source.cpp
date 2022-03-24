#include <iostream>
using namespace std;
int decN = 0, decT[15];
void modExp(int b, int a, int m) {
	//******Start of Decimal to Binary************
	int dec[15], temp, decT[15], k = 0, num = b;
	cout << "\n " << num << " is equivalent to (";
	for (int i = 0; num > 0; i++) {
		dec[i] = num % 2; // if it is fully substracted dec[i] = 0, if its not it is 1
		num = num / 2; 
		decN++; // For counting how many dec input there is.
	}
	for (int i = decN - 1; i >= 0; i--) {
		decT[k] = dec[i]; // To get the inverted version
		k++;
	}
	for (int i = 0; i < decN; i++) {
		cout << decT[i]; //printing out the inverted version.
	}
	cout << ") as binary number...\n";
	//******End of Decimal to Binary*************

	//*************Start of the Modular Exponentiation Calculator**********
	int x = 1, power = a % m;
	// Power = Base mod M
	for (int i = 0; i < decN; i++) {
		cout << "\n Because b" << i << " is " << dec[i] << ", we have x = "; 
		if (dec[i] == 1) { // if binary is 1 
			int x2 = (x*power)% m; //x2 for the second print x2 = ((previous x)*power) mod M
			if(i == decN - 1) //For the final one.
				cout << "(" << x << " * " << power << ") mod " << m << " ==>";
			else { 
				cout << "(" << x << " * " << x2 << ") and power = " << power << " ^ 2 mod " << m << " = ";
				power = (power*power) % m; // Power = power^2 mod M
				cout << power; // Printing power after the calculation.
			}
			x = x2;
		}
		else {
			cout << " " << x << " and power = " << power << " ^ 2" << " mod " << m << " = ";
			power = (power*power) % m;
			cout << power;
		}
	}
	cout << "\n\n Modular Exponention of (" << a << "^" << b << ") mod (" << m << ") = " << x;
	//************End of the Modular Exponentiation Calculator************
}

int main() {
	int a, b, m;
	cout << " MODULAR EXPONENTIATION CALCULATOR" << "\n (a^b mod m solver)";
	cout << "\n\n Enter Base (a): ";
	cin >> a;
	cout << " Enter Exponent (b): ";
	cin >> b;
	cout << " Enter Modulus (m): ";
	cin >> m;
	modExp(b, a, m);
	return 0;
}