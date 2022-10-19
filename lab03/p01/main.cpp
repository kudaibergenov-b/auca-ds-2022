#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<vector<int>> readShuffles();
vector<int> createDeck();
void applyShuffleDeck(vector<int>& deck, const vector<int>& shuffle);
void printDeck(const vector<int>& deck);

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        auto shuffles = readShuffles();
        auto deck = createDeck();

        for (string line; getline(cin, line) && !line.empty();)
        {
            int m = stoi(line);
            applyShuffleDeck(deck, shuffles[m - 1]);
        }

        if (test != 0)
        {
            cout << "\n";
        }

        printDeck(deck);
    }
}

void printDeck(const vector<int>& deck)
{
    vector<string> values = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};

    for (auto c : deck)
    {
        cout << values[c % 13] << " of " << suits[c / 13] << endl;
    }
}

vector<int> createDeck()
{
    vector<int> r(52);

    for (int i = 0; i < 52; i++)
    {
        r[i] = i;
    }

    return r;
}

vector<vector<int>> readShuffles()
{
    int n;
    cin >> n;

    vector<vector<int>> r(n, vector<int>(52));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            cin >> r[i][j];
        }
    }

    cin.ignore(1024, '\n');

    return r;
}

void applyShuffleDeck(vector<int>& deck, const vector<int>& shuffle)
{
    vector<int> r(52);

    for (int i = 0; i < 52; i++)
    {
        r[i] = deck[shuffle[i] - 1];
    }

    deck = r;
}