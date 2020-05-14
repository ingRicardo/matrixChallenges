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
    const int mMaxSize;
    int mFront;
    int mBack;
    T *mData;
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
    for (int i = 0; i < skip; ++i)
    {
        outDeck[i] = left[i];
    }

    for (int i = 0; i < (deckSize / 2) - skip; i++)
    {
        const int lIndex = i * 2 + skip;
        const int rIndex = lIndex + 1;
        outDeck[lIndex] = left[skip + i];
        outDeck[rIndex] = right[i];
    }

    for (int i = (deckSize / 2) - skip; i < (deckSize / 2); ++i)
    {
        outDeck[deckSize / 2 + i] = right[i];
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int shuffled[MAX_CARDS]; // int vector with max cards size
    Queue<State> states(1000000); //initialization of queue with State structure

    int tc;
    cin >> tc;
    for (int c = 1; c <= tc; ++c)
    {
        int deckSize;
        cin >> deckSize;

        State initial;
        for (int i = 0; i < deckSize; ++i)
        {
            cin >> initial.deck[i]; // add values to the initial state
        }
        states.push(initial);  //add the initial state to the states queue

        int answer = -1;
        while (!states.empty())
        {
            const State &current = states.front();
            states.pop();

            if (isSorted(current.deck, deckSize)) // if current deck is sorted
            {
                answer = current.shuffles;
                states.clear();
                break;
            }

            if (current.shuffles <= 4) //maximum number of shuffles is limited to 5 
            {
                for (int skip = 0; skip < deckSize / 2; ++skip) //takes the half of the deck
                {
                    const int *left = current.deck;
                    const int *right = current.deck + (deckSize / 2);

                    join(left, right, skip, deckSize, shuffled);
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
