#include <iostream>
using namespace std;
class Card
{
    char suite;
    string val;
    int ival;

    static char validsuite[4];
    static string validval[13];
    // one copy in memory
    // the definiition og the above is moved to class memory
    static int IsValidSuite(char c)
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            if (c == validsuite[i])
            {
                return i;
            }
        }
        return -1;
    }
    static int isValidValue(string v)
    {
        int i;
        for (i = 0; i < 13; i++)
        {
            if (v == validval[i])
            {
                return i;
            }
        }
        return -1;
    }

public:
    static char validsuite[4];
    static string validval[13];
    Card()
    {
        suite = '\0';
        val = "";
    }
    void SetValue(char s, string v)
    {
        int t;
        t = isValidValue(v);
        if (IsValidSuite(s) == -1 || isValidValue(v) == -1)
        {
            cout << "\nInvalid Card";
            return;
        }
        ival = t;
        suite = s;
        val = v;
    }
    string Print()
    {
        string s = "";
        s = val;
        s.push_back(suite);
        return s;
    }
    int operator<(Card other)
    {
        return ival < other.ival;
    }
    int operator>(Card other)
    {
        return ival > other.ival;
    }
    int operator==(Card other)
    {
        return ival == other.ival;
    }
    int operator!=(Card other)
    {
        return ival != other.ival;
    }
    int operator<=(Card other)
    {
        return ival <= other.ival;
    }
    int operator>=(Card other)
    {
        return ival >= other.ival;
    }
};
char Card::validsuite[4] = {'H', 'D', 'C', 'S'};
string Card::validval[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
class Deck{
    int count;
    Card cards[52];

    void PopulateDeck(){
        int i, j;
        for(i = 0; i < 13; i++){
            for(j = 0; j < 4; j++){
                cards[count].SetValue(Card::validsuite[j], Card::validval[i]);
                count++;
            }
        }
        //cards[i].SetValue(Card::validsuite[i/13], Card::validval[i%13]);
    }
    public:
        Deck(){
            count = 0;
            PopulateDeck();
        }
        int CardCount(){
            return count;
        }
        void PrintDeck(){
            int i;
            for(i = 0; i < count; i++){
                cout<<cards[i].Print()<<" ";
            }
            cout<<"\n";
        }

};
int main()
{
}