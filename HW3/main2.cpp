#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void assignInputTo();
void printMovies();
string getLastName(string);
void titleSwap();
void nameSwap();


struct movie
{
	string Name;
	string Date;
	string Actors[20];
	int count;
};

string line;
int i;
int j = 0;
int n = 10;
movie Movies[10];
string inputAr[71];

int main()
{
	assignInputTo();
	//titleSwap();
	//nameSwap();
	//printMovies();
}

void assignInputTo()
{
	// copying input file into an array, line by line
	ifstream myfile("input.txt");
	while (getline(myfile, line))
	{
		inputAr[j] = line;
		j++;
	}
	myfile.close();
	int cutoff = j;
	j = 0;
	// assigning info to movie struct
	for (i = 0; i < n; i++)
	{
		cout << i << " | " << j << endl;
		int k = 0;
		Movies[i].count = 0;
		Movies[i].Name = inputAr[j];
		j++;
		cout << i << " | " << j << endl;
		Movies[i].Date = inputAr[j];
		j++;
		cout << i << " | " << j << endl;
		/*
		if (inputAr[j] == "")
		{
			j++;
			break;
		}*/
		int pl = j;
		while ((j < cutoff))
		{
			string e = inputAr[j];
			cout << e << endl;
			Movies[i].Actors[k] = e;
			cout << i << " " << k << " " << Movies[i].Actors[k] << endl;
			k++;
			j++;
			Movies[i].count++;
			cout << "       InputAr is " << inputAr[j] << endl;
			cout << "       " << i << " | " << j << " | " << k << " | " << Movies[i].Actors[k -1] << endl;
			if(inputAr[j] == "") {
				j = cutoff;
				cout << "BUTTTTTTTT" << endl;
			}
		}

		j = pl + Movies[i].count;
	}
}
/*
void printMovies()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		int e = Movies[i].count;
		cout << endl << "Movie " << i + 1 << " Title : " << Movies[i].Name << endl;
		cout << "Date Released : " << Movies[i].Date << endl;
		for (j = 0; j < e; j++)
		{
			cout << "      Actor " << j + 1 << " : " << Movies[i].Actors[j] << endl;
		}
	}
}

void titleSwap()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		int x = 1;
		while (x)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (Movies[j].Name > Movies[j + 1].Name)
				{
					swap(Movies[j], Movies[j + 1]);
				}
			}
			x = 0;
		}
	}
}

string getLastName(string s)
{
	int w = s.size() - 1;
	while (s.substr(w - 1, 1) != " ")
		w--;
	return s.substr(w);
}

void nameSwap()
{
	int i, j, m;
	for (i = 0; i < n; i++)
	{
		for (m = 0; m < Movies[i].count - 1; m++)
		{
			for (j = 0; j < Movies[i].count - 1; j++)
			{
				if (getLastName(Movies[i].Actors[j]) > getLastName(Movies[i].Actors[j + 1]))
				{
					swap(Movies[i].Actors[j], Movies[i].Actors[j + 1]);
				}
			}
		}
	}
}
*/