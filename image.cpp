#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
void print(int h, int v);
int func(int c);
int main() {
	int horizontal, vertical;
	cout << "Enter the horizontal and vertical pixels." << endl;
	cin >> horizontal >> vertical;
	print(horizontal,vertical);
	return 0;
}
void print(int h, int v) {
	int val;
	srand(time(NULL));
	ofstream image("image.ppm");
	int hor = h;
	int vert = v;
	double totalPixels = hor * vert;
	double c = 1;
	double percent;
	if (image.is_open()) {
		image << "P3\n" << hor << " " << vert << "\n" << "255\n" << endl;
		for (int i = 1; i < totalPixels; i++) {
			val = func(i);
			image << val << " " << val << " " << val << endl;
			cout << i << endl;
		}
		image.close();
		cout << "Image saved as image.ppm." << endl;
		system("pause");

	}
	else {
		cout << "Failed to open file." << endl;
		system("pause");
	}
}
int func(int c) {
	const int MAX_ITER = 256;
	int f[255];
	f[0] = 0;
	for (int i = 1; i <= MAX_ITER; i++) {
		f[i] = (f[i - 1] * f[i - 1]) + c;
	}
	bool div = false;
	for (int i = 0; i < MAX_ITER; i++) {
		if (f[i] >= f[i + 1]){
			div = true;
			return i;
		}
	}
	return f[255] % 256;
}
