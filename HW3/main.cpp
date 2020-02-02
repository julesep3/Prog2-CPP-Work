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
		Movies[i].count = 0;
		Movies[i].Name = inputAr[j];
		j++;
		Movies[i].Date = inputAr[j];
		j++;

		if (inputAr[j] == "")
		{
			j++;
			break;
		}

		while ((inputAr[j] != "") && (j < 70))
		{
			Movies[i].Actors[k] = inputAr[j];
			k++;
			j++;
			Movies[i].count++;
		}
		j++;
	}
	
	for(i = 0; i < 10; i++) {
		int e = Movies[i].count;
		cout << "Movie Title : " << Movies[i].Name << endl;
		cout << "Date Released : " << Movies[i].Date << endl;
		for (j = 0; j < e; j++) {
			cout << "Actor " << j+1 << " : " << Movies[i].Actors[j] << endl;
		}
		cout << endl;
	}
	myfile.close();
}