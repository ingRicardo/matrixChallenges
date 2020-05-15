/*
    when the action button is pressed the cards 

    value x, the starting time of mixing the cards can be modified by the user

    split half and half
    the cards 1 to n/2 are put on the left side 
    the cards from n/2+1 to n are put on the right side

    after the x is modified with the dial that is on the side of the card shuffler, the action button is pressed

    input 1  

    4
    1 2 3 4

    split half and half
    N =4
    L = 1 to 4/2 = 1 to 2
    L -> 1,2
    R = 4/2 + 1 to 4 = 3 to 4 
    R -> 3,4





*/

//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAX_CARDS 12

using namespace std;

struct carts
{
	bool X;
	int value;
};

struct infoSecuence
{
	carts cards[MAX_CARDS];
	int shuffles;
	bool visited[MAX_CARDS];
	infoSecuence(int s = 0)
		:shuffles(s)
	{
		for(int v = 0; v < MAX_CARDS; ++v)
		{
			visited[v] = false;
		}
	}
};

int N;
int minimumShuffles;
int half;

bool isSorted(carts [MAX_CARDS]);
void generateSecuence(int, infoSecuence &);
void findMinimum(infoSecuence);

int main()
{
	int T;

	freopen("input.txt", "r", stdin);
	
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		minimumShuffles = 2147483647;
		cin >> N;
		half = N / 2;
		
		infoSecuence node;
		int value;
		for (int c = 0; c < N; ++c)
		{
			cin >> value;
			node.cards[c].value = value;
			node.cards[c].X = (c >= half);
		}

		findMinimum(node);

		cout << "#" << tc << " " << ((minimumShuffles == 2147483647) ? - 1: minimumShuffles) << endl;
	}

	return 0;
}

void findMinimum(infoSecuence node)
{
	if (node.shuffles > 5)
	{
		return;
	}
	
	if (node.shuffles > minimumShuffles)
	{
		return;
	}

	if (isSorted(node.cards))
	{
		if (node.shuffles < minimumShuffles)
		{
			minimumShuffles = node.shuffles;
		}
		return;
	}

	for (int x_value = 0; x_value < N; ++x_value)
	{
		infoSecuence copy;
		copy = node;
		copy.shuffles += 1;

		generateSecuence(x_value, copy);
		findMinimum(copy);
	}
}

void generateSecuence(int x_value, infoSecuence &copy)
{
	for (int x = 0; x < x_value; ++x)
	{
		for (int c = N - 1; c >= 0; --c)
		{
			if (copy.cards[c].X && !copy.cards[c - 1].X) //can swap
			{
				swap(copy.cards[c - 1], copy.cards[c]);
				c -= 1;
			}
		}
	}

	for (int c = 0; c < N; ++c)
	{
		copy.cards[c].X = false;
		if (c >= N / 2)
		{
			copy.cards[c].X = true;
		}
	}
}

bool isSorted(carts secuence[MAX_CARDS])
{
	int min = 0;
	bool ascendent = true;
	for (int c = 0; c < N; ++c)
	{
		if (secuence[c].value >= min)
		{
			min = secuence[c].value;
		}
		else
		{
			ascendent = false;
			break;
		}
	}

	if (ascendent)
	{
		return true;
	}
	
	int max = 2147483647;
	for (int c = 0; c < N; ++c)
	{
		if (secuence[c].value <= max)
		{
			max = secuence[c].value;
		}
		else
		{
			return false;

		}
	}
	return true;
}
