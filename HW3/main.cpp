#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct movie
{
	string Name;
	string Date;
	string Actors[9];
	int count;
};

int main()
{
	string line;
	ifstream myfile("input.txt");
	/*
	if (myfile.is_open()) {
		while(getline(myfile, line)) {
			cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Nope, ain't gonna do it";
	*/
	int i;
	int j = 0;
	int n = 10;
	movie Movies[n];
	string inputAr[70];

	while (getline(myfile, line))
	{
		inputAr[j] = line;
		j++;
	}
	int cutoff = j;
	j = 0;
	for (i = 0; i < n; i++)
	{
		int k = 0;
		Movies[i].Name = inputAr[j];
		j++;
		cout << Movies[i].Name << endl
			 << "i : " << i << " || k : " << k << " || j : " << j << endl;

		Movies[i].Date = inputAr[j];
		j++;
		cout << Movies[i].Date << endl
			 << "i : " << i << " || k : " << k << " || j : " << j << endl;
		cout << i << endl;
		cout << inputAr[j] << endl;
		while (inputAr[j] != "")
		{
			cout << i << endl;

			Movies[i].Actors[k] = inputAr[j];
			k++;
			j++;
			cout << Movies[i].Actors[k] << endl
				 << "i : " << i << " || k : " << k << " || j : " << j << endl;
		}
		j++;
		cout << "J is " << j << endl;
	}
	cout << Movies[0].Name << endl;

	myfile.close();
}