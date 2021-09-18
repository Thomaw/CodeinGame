#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string expression;
    cin >> expression; cin.ignore();

    int round = 0;  // (
    int square = 0; // [
    int curly = 0;  // {

    for (const char c : expression)
    {
        switch (c)
        {
        case '(':
            ++round;
            break;
        
        case ')':
            --round;
            break;

        case '[':
            ++square;
            break;

        case ']':
            --square;
            break;

        case '{':
            ++curly;
            break;

        case '}':
            --curly;
            break;
        }

        if (round < 0 || square < 0 || curly < 0)
            break;
    }

    if (round == 0 && square == 0 && curly == 0)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
