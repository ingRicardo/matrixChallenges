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

template <typename T>
struct Queue
{
    Queue(int maxSize) : 
        mMaxSize(maxSize),
        mFront(0),
        mBack(0),
        mData(new T[mMaxSize]) {}

    ~Queue()
    {
        delete[] mData;
    }
    void clear()
    {
        mFront = mBack = 0;
    }
    bool empty() const
    {
        return (mFront == mBack);
    }
    int size() const 
    {
        return mBack - mFront;
    }
    T front()
    {
        return (mData[mFront % mMaxSize]);
    }
    void pop()
    {
         ++mFront;
    }
    bool push(const T& item)
    {
        if (size() < mMaxSize)
        {
            mData[mBack % mMaxSize] = item;
            ++mBack;
            return true;
        }
        return false;
    }

private:
    const int mMaxSize; //max size of the queue
    int mFront; //front value of the queue
    int mBack; 
    T *mData; // data structure
};

void join(const int *left, const int *right, const int skip, const int deckSize, int *outDeck)
{
    cout << " ======== join ========= "<<endl;
    for (int i = 0; i < skip; ++i) // 1 to N/2
    {
        outDeck[i] = left[i];  // saves the lef cards based on skip size

        cout << "outDeck["<< i << "] "<<outDeck[i] <<endl;
    }

    //skip=1, 4/2 - 1 = 1, lIndex = 0 * 2 + 1 = 1,rIndex = 1+1 = 2, outDeck[1] = left[1+0], outDeck[2] = right[0]
    for (int i = 0; i < (deckSize / 2) - skip; i++)  // 
    {
        const int lIndex = i * 2 + skip;
        cout << " lIndex  "<< lIndex<<endl;
        const int rIndex = lIndex + 1;
        cout<< " rIndex "<< rIndex <<endl;
        outDeck[lIndex] = left[skip + i];
        cout << " outDeck["<<lIndex<<"] lIndex -> "<< outDeck[lIndex] <<endl;
        outDeck[rIndex] = right[i];
        cout << " outDeck["<<rIndex<<"] rIndex -> "<< outDeck[rIndex] <<endl;
    }

    for (int i = (deckSize / 2) - skip; i < (deckSize / 2); ++i)   // N/2 +1 to N
    {
        outDeck[deckSize / 2 + i] = right[i];
        cout << "*outDeck["<<deckSize / 2 + i<<"] " <<  right[i] << endl;
    }
}
bool isSorted(const int *deck, const int deckSize)
{
    bool isAscOrder = true, isDescOrder = true;
    cout << " ------ isSorted -----" <<endl;
    int min = deck[0];
    cout << " min "<< min << endl; 
    int max = deck[0];
    cout << " max "<< max << endl;

    cout << "isAscOrder "<< isAscOrder << " isDescOrder "<< isDescOrder << endl;
    for (int i = 1; (isAscOrder || isDescOrder) && i < deckSize; ++i)
    {
        if (min > deck[i]) // if min > deck current value
        { 
            isAscOrder = false;  // is not ascent order 
        }
        else
        {
            min = deck[i]; // save the min
        }

        if (max < deck[i])  // if max is minor than current deck value
        {
            isDescOrder = false; // is not descent order
        }
        else
        {
            max = deck[i]; //save the max
        }

        cout <<"\n for i : "<< i << " min "<< min << " max "<< max << " isAscOrder "<< isAscOrder << " isDescOrder "<< isDescOrder;
    }
    cout << "\n -------------------------  "<<endl;
    return isAscOrder || isDescOrder;
}
int main()
{

    int t;

    freopen("input.txt","r",stdin);
    int shuffled[MAX_CARDS]; // shuffle vector with max cards size

    Queue<State> states(1000000);
    cin>> t;

    cout << "t "<<t <<endl;

    for(int tc =1; tc<=1; tc++)
    {
        int deckSize,c;
        cin >>deckSize;
        int *vec = new int[deckSize];
        
        cout << " deck size "<< deckSize<<endl;
        State initial;
        for (int i = 0; i < deckSize; ++i) // N=deckSize
        {
            cin >> initial.deck[i]; // add values to the initial state
            cout << " "<<initial.deck[i];
        }
        cout << "\ninitial shuffles "<< initial.shuffles<<endl;
    
        states.push(initial); 
        cout << " pushing values.."<<endl;
        int answer = -1; //

        cout << " is states empty ? "<< states.empty() << endl; 

        while (!states.empty())
        {
            
            const State &current = states.front(); // get the front values
           // cout << " front -> " << states.front().deck[0] <<endl;
            for (int i = 0; i < deckSize; ++i) // N=deckSize
            {
                cout << "\n current "<< current.deck[i] << " shuffles -> "<< current.shuffles;
            }
            cout << endl;

            cout << "states queue size ->  "<< states.size()<<endl;
          

            states.pop(); // delete the front value 
            cout << " popping.. "<<endl;
            if (isSorted(current.deck, deckSize)) // if current deck is sorted
            {
                cout << "\n is sorted "<<endl;
                answer = current.shuffles; // print the answer if cards are sorted
                states.clear();
                break;
            }


             if (current.shuffles <= 4) //maximum number of shuffles is limited to 5 , it goes from 0 to 4 (0,1,2,3,4)
            {
                    cout << "\n current shuffle is minor than 5 -->  "<< current.shuffles<<endl;
                    int m = deckSize / 2;
                    cout << " deckSize / 2 ---> " << m <<endl;
                for (int skip = 0; skip < deckSize / 2; ++skip) //takes the half of the deck
                {
                    const int *left = current.deck; // 1 to N/2
                    const int *right = current.deck + (deckSize / 2); // N/2 +1 to N

                     /*cout<<"---- skip ---- "<< skip<<endl;
                     for (int i = 0; i < deckSize; ++i)
                     {
                        
                         cout<<"left "<< left[i]<<endl;
                         cout<<"right "<< right[i]<<endl;
                     } 
                    cout << endl;*/
                    join(left, right, skip, deckSize, shuffled); // shuffle left 
                    states.push(State(shuffled, deckSize, current.shuffles + 1));

                    
                    join(right, left, skip, deckSize, shuffled);
                    states.push(State(shuffled, deckSize, current.shuffles + 1));

                   // const int *right = current.deck + (deckSize / 2); // N/2 +1 to N

                }
            }


        }

        /*
        for (int v=0; v<deckSize; v++)
        {
            cin>>c;
            vec[v] =c;
            cout <<" "<<vec[v];

        }*/
        cout <<endl;
          cout << "#" << tc << ":" << answer << endl;
    }


    return 0;
}