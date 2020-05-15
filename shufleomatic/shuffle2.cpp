#include <iostream>

#define MAX_CARDS 12

using namespace std;

template <typename T>
struct Queue
{
    Queue(int maxSize) : mMaxSize(maxSize), mFront(0), mBack(0), mData(new T[mMaxSize]) {}
    ~Queue() { delete[] mData; }
    void clear() { mFront = mBack = 0; }
    bool empty() const { return (mFront == mBack); }
    int size() const { return mBack - mFront; }
    T front() { return (mData[mFront % mMaxSize]); }
    void pop() { ++mFront; }
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

struct State
{
    int deck[MAX_CARDS];
    int shuffles;

    State() : shuffles(0) {}
    State(const int *inDeck, const int deckSize, const int shuffles)
        : shuffles(shuffles)
    {
        for (int i = 0; i < deckSize; ++i)
        {
            deck[i] = inDeck[i];
        }
    }
};

bool isSorted(const int *deck, const int deckSize)
{
    bool isAscOrder = true, isDescOrder = true;

    int min = deck[0];
    int max = deck[0];
    for (int i = 1; (isAscOrder || isDescOrder) && i < deckSize; ++i)
    {
        if (min > deck[i]) { isAscOrder = false; }
        else { min = deck[i]; }

        if (max < deck[i]) { isDescOrder = false; }
        else { max = deck[i]; }
    }
    return isAscOrder || isDescOrder;
}

void join(const int *left, const int *right, const int skip, const int deckSize, int *outDeck)
{
    for (int i = 0; i < skip; ++i) // 1 to N/2
    {
        outDeck[i] = left[i];  // saves the lef cards based on skip size
    }

    //skip=1, 4/2 - 1 = 1, lIndex = 0 * 2 + 1 = 1,rIndex = 1+1 = 2, outDeck[1] = left[1+0], outDeck[2] = right[0]
    for (int i = 0; i < (deckSize / 2) - skip; i++)  // 
    {
        const int lIndex = i * 2 + skip;
        const int rIndex = lIndex + 1;
        outDeck[lIndex] = left[skip + i];
        outDeck[rIndex] = right[i];
    }

    for (int i = (deckSize / 2) - skip; i < (deckSize / 2); ++i)   // N/2 +1 to N
    {
        outDeck[deckSize / 2 + i] = right[i];
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int shuffled[MAX_CARDS]; // shuffle vector with max cards size
    Queue<State> states(1000000); //initialization of queue with State structure

    int tc;
    cin >> tc;
    for (int c = 1; c <= tc; ++c)
    {
        int deckSize;  //N
        cin >> deckSize;

        State initial;
        for (int i = 0; i < deckSize; ++i) // N=deckSize
        {
            cin >> initial.deck[i]; // add values to the initial state
        }
        states.push(initial);  //add the initial state to the states queue

        int answer = -1; // if the cards cannot be sorted even after 5 times of shuffling, print -1 as the answer
        while (!states.empty())
        {
            const State &current = states.front();
            states.pop();

            if (isSorted(current.deck, deckSize)) // if current deck is sorted
            {
                answer = current.shuffles; // print the answer if cards are sorted
                states.clear();
                break;
            }

            if (current.shuffles <= 4) //maximum number of shuffles is limited to 5 , it goes from 0 to 4 (0,1,2,3,4)
            {
                for (int skip = 0; skip < deckSize / 2; ++skip) //takes the half of the deck
                {
                    const int *left = current.deck; // 1 to N/2
                    const int *right = current.deck + (deckSize / 2); // N/2 +1 to N

                    join(left, right, skip, deckSize, shuffled); // shuffle left 
                    states.push(State(shuffled, deckSize, current.shuffles + 1));

                    join(right, left, skip, deckSize, shuffled);
                    states.push(State(shuffled, deckSize, current.shuffles + 1));
                }
            }
        }

        cout << "#" << c << " " << answer << endl;
    }

    return 0;
}
