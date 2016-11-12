#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    string value;
    order ob;
    int choise;

    while(choise)
    {
        cout << "Введіть вираз (інфіксний): "; getline(cin, value);
        cout << "Postfix: "; ob.Postfix(value); ob.Show();
        cout << "Prefix: "; ob.Prefix(value); ob.Show();

        cout << "Введіть вираз (постфіксний): "; getline(cin, value);
        cout << "Infix: " ; ob.PostInfix(value); ob.Show();
        cout << "Введіть вираз (префіксний): "; getline(cin, value);
        cout << "Infix: " ; ob.PrefInfix(value); ob.Show();
        cout << "Продовжити? (1/0)" << endl; cin >> choise; cin.ignore();
    }
    return 0;
}
