#include <iostream>
using namespace std;

void sort(double* ARR, int N);
void ARR_COUT(double* ARR, int N);

void sort(double ARR[], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (ARR[j] > ARR[j + 1]) {
				double temp = ARR[j];
				ARR[j] = ARR[j + 1];
				ARR[j + 1] = temp;
			}
		}
	}
	ARR_COUT(ARR, N);
}

void ARR_COUT(double ARR[], int N) {
	for (int i = 0; i < N; i++) {
		cout << ARR[i] << " ";
	}
}


int main()
{
	int n;
	cin >> n;
	double* a = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, n);
}

