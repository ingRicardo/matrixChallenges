#include <iostream>
using namespace std;

#define MAX_CARDS 12

struct State
{
    int deck[MAX_CARDS];
    int shuffles;

    State() : shuffles(0) {} // empty constructor definition
    State(const int *inDeck, const int deckSize, const int shuffles) //parameterized constructor definition
        : shuffles(shuffles)
    {

        for (int i = 0; i < deckSize; ++i)
        {
            deck[i] = inDeck[i]; // saves the values  
        }
    }
};

int main()
{

    int t;

    freopen("input.txt","r",stdin);

    cin>> t;

    cout << "t "<<t <<endl;

    for(int tc =1; tc<=t; tc++)
    {
        int deckSize,c;
        cin >>deckSize;
        int *vec = new int[deckSize];
        

        State initial;
        for (int i = 0; i < deckSize; ++i) // N=deckSize
        {
            cin >> initial.deck[i]; // add values to the initial state
            cout << " "<<initial.deck[i];
        }
        cout << "\ninitial shuffles "<< initial.shuffles<<endl;
    
        /*
        for (int v=0; v<deckSize; v++)
        {
            cin>>c;
            vec[v] =c;
            cout <<" "<<vec[v];

        }*/
        cout <<endl;
    }


    return 0;
}