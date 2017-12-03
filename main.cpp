//Program that deletes repeated letters of an array.
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cmath>
using namespace std;

void deleteRepeats(char a[], int& numberUsed);
//Precondition: Array a is partially filled. numberUsed >= 1.
//Postcondition: Deletes all repeated letters of array a.

int indexOfReplica(char a[], int& numberUsed, int targetIndex);
//Precondition: Array a is partially filled. numberUsed >= 1.targetIndex is either 
//positive or negative.
//Postcondition: Returns the index of the element containing the repeated letter.

void fillGap(char a[], int& numberUsed, int indexOfReplica);
//Precondition: Array a is partially filled. numberUsed >= 1.
//indexOfReplica is either negative or positive.
//Postcondition: All remaining letters are moved forward to fill in the gap.

int main()
{
	int nU = 0;
	char a[20];
    
    cout<<"Enter up to 19 letters: ";
    char ans;
    do
    {
        cin>>a[nU++];
    }while(cin.peek() != '\n');

	deleteRepeats(a, nU);

	for (int i = 0; i < nU; i++)
		cout<<a[i]<<" ";
    cout<<endl;

	return 0;
}

void deleteRepeats(char a[], int& numberUsed)
{
	int indexOfNextReplica;

	for(int i = 0; i < numberUsed; i++)
	{
		indexOfNextReplica = indexOfReplica(a, numberUsed, i);
		fillGap(a, numberUsed, indexOfNextReplica);
	}
}

int indexOfReplica(char a[], int& numberUsed, int targetIndex)
{
	bool found = false;
	int index = targetIndex + 1;

	while (!(found) && index < numberUsed)
	{
		if (tolower(a[index]) == tolower(a[targetIndex]))
			found = true;
		else
			index++;
	}

	if(found)
		return index;
	else
		return - 1;
}

void fillGap(char a[], int& numberUsed, int indexOfReplica)
{
	if (indexOfReplica == -1)
		return;
	
	for(int i = indexOfReplica; i < numberUsed; i++)
		a[i] = a[i + 1];

	numberUsed--;
}
