#include <iostream>
#include "assignInputTo.cpp"
using namespace std;
/*
struct movie
{
	string Name;
	string Date;
	string Actors[9];
	int count;
};*/

int main()
{
	/*
	string line;
	ifstream myfile("input.txt");
	int i;
	int j = 0;
	int n = 10;
	movie Movies[n];
	string inputAr[70];

	// copying input file into an array, line by line
	while (getline(myfile, line))
	{
		inputAr[j] = line;
		j++;
	}
	int cutoff = j;
	j = 0;
	// assigning info to movie struct
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
		while ((inputAr[j] != "") && (j < cutoff))
		{
			Movies[i].Actors[k] = inputAr[j];
			k++;
			j++;
			Movies[i].count++;
		}
		j++;
	}*/

	assignInputTo();
	int i = 0;
	int j = 0;
	// print all movies
	for(i = 0; i < 10; i++) {
		int e = Movies[i].count; 
		cout << "Movie " << i+1 << " Title : " << Movies[i].Name << endl;
		cout << "Date Released : " << Movies[i].Date << endl;
		for (j = 0; j < e; j++) {
			cout << "Actor " << j+1 << " : " << Movies[i].Actors[j] << endl;
		}
		cout << endl;
	}
	//myfile.close();
}