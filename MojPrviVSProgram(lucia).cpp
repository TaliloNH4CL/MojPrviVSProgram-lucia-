#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	fstream imenik;

	char ispis[50];

	imenik.open("imenik.txt", ios::in);
	while (imenik.getline(ispis, 50))
		cout << ispis << endl;

	imenik.close();

	int n;
	cin >> n;
	string* polje = new string[n];
	cin.ignore();

	for (int i = 0; i < n; i++)
		getline(cin, polje[i]);
	sort(polje, polje + n);

	imenik.open("imenik.txt", ios::out | ios::app);
	for (int i = 0; i < n; i++)
		imenik << polje[i] << endl;
	imenik.close();


	imenik.open("imenik.txt", ios::in | ios::trunc);
	for (int i = 0; i < n; i++)
		imenik << polje[i] << endl;
	sort(polje, polje + n);
	imenik.close();
	return 0;
}