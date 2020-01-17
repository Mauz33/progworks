
#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int* a = new int[n+1];
	a[n] = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	cout << endl;
	int k = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) {
			k++;
		}
		else {
			cout << a[i] << " : " << k << endl;
			k = 1;
		}
	}
	delete[] a;

	return 0;
}

