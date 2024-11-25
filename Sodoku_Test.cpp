// Test Case 1 : Invalid Input(Any number other than 1~9)->Done
// Test Case 2: Enter Number in Prefilled Cell->Done
// Test Case 3: Enter Wrong Input->Done
// Test Case 4: Invalid Position(Any number other than 1-81)->Done
// Test Case 5: Difficulty level->Done
// Test Case 6: Easy level->Done
// Test Case 7: Medium level->Done
// Test Case 8: Hard level->Done
// Test Case 9: Insert at last position->Done
// Test Case 10: Complete Board->Done
// Test Case 11: Exit Game->Done

/* 1   2   3   4   5   6   7   8   9
1  1   2   3   4   5   6   7   8   9
2  10  11  12  13  14  15  16  17  18
3  19  20  21  22  23  24  25  26  27
4  28  29  30  31  32  33  34  35  36
5  37  38  39  40  41  42  43  44  45
6  46  47  48  49  50  51  52  53  54
7  55  56  57  58  59  60  61  62  63
8  64  65  66  67  68  69  70  71  72
9  73  74  75  76  77  78  79  80  81

*/
#include "Sodoku_Class.h"
using namespace std;
int main()
{
    int difficulty, row, col;
    char data;
    cout << "---------------------------------Sudoku----------------------------------\n";
    cout << "Difficulty : \n1-Easy\n2-Medium\n3-Hard\n";
    cout << "Choose Difficulty : ";
    cin >> difficulty;
    Sodoku s(difficulty);
    while (!s.isComplete())
    {
        cout << "Enter Row : ";
        cin >> row;
        cout << "Enter Column : ";
        cin >> col;
        cout << "Enter Data(Enter E to exit) : ";
        cin >> data;
        if (data == 'E')
        {
            system("cls");
            cout << "Exiting......" << endl;
            break;
        }
        s.insert(data, row, col, difficulty);
        s.display();
    }
    system("cls");
    cout << "\nBoard is Complete";
}
