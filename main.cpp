//Program that deletes repeated letters of an array.
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cmath>
using namespace std;

void input(char a[], int& numberUsed);
//Fills array a with user input.

void deleteRepeats(char a[], int& numberUsed);
//Precondition: Array a is partially filled. numberUsed >= 1.
//Postcondition: Deletes all repeated letters of array a.

void fillGap(char a[], int& numberUsed, int indexOfReplica);
//Precondition: Array a is partially filled. numberUsed >= 1.
//indexOfReplica is either negative or positive.
//Postcondition: All remaining letters are moved forward to fill in the gap.

void output(char a[], int numberUsed);
//Precondition: Array a is partially filled. numberUsed >= 1.
//Postcondition: Prints the contents of array a.

int main()
{
	int numberUsed = 0;
	char a[20];
    
    input(a, numberUsed);
	deleteRepeats(a, numberUsed);
    output(a, numberUsed);
    
	return 0;
}

void input(char a[], int& numberUsed)
{
    cout<<"Enter up to 19 letters: ";
    do
    {
        cin>>a[numberUsed++];
    }while(cin.peek() != '\n');
}

void deleteRepeats(char a[], int& numberUsed)
{
    //Boolean array that stores flags indicating if a letter has been found.
    bool found[256] = {false};

	int indexOfNextReplica;

	for(int i = 0; i < numberUsed; i++)
	{
		if (found[a[i]] == false)
            found[a[i]] = true;
        else
        {
		    fillGap(a, numberUsed, i);
            i -= 1;
        }
	}
}

void fillGap(char a[], int& numberUsed, int indexOfReplica)
{
	for(int i = indexOfReplica; i < numberUsed; i++)
		a[i] = a[i + 1];

	numberUsed--;
}

void output(char a[], int numberUsed)
{
	for (int i = 0; i < numberUsed; i++)
		cout<<a[i]<<" ";
    cout<<endl;
}
