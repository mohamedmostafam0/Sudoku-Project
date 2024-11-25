#include "Sodoku_Class.h"
Sodoku::Sodoku()
{
    str_board = "-----------------------------------------------------------------------------------------";
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int index = i * 9 + j;
            cout << str_board[index] << " ";
        }
        cout << endl;
    }
}
Sodoku::Sodoku(int difficulty)
{
    switch (difficulty)
    {
    case 1:
    {
        str_board = "53--7----6--195---98----68---6---34--8-3--17---2---6-6----28----419--5----8--79--";
        for (int i = 0; i < str_board.size(); i++)
        {
            Board.enqueue(str_board[i]);
        }
        cout << Board;
        break;
    }
    case 2:
    {
        str_board = "--4-7-----2-5--1-------3-4------9--98--7--2-----61----7-1--------2--5----3--8----";

        for (int i = 0; i < str_board.size(); i++)
        {
            Board.enqueue(str_board[i]);
        }
        cout << Board;
        break;
    }

    case 3:
    {
        str_board = "-2--8-5--1---43---9------7-------1-8-8-------6-3-5------5------3---95---7--4-2--9";

        for (int i = 0; i < str_board.size(); i++)
        {
            Board.enqueue(str_board[i]);
        }
        cout << Board;

        break;
    }
    }
}
void Sodoku::insert(char data, int row, int col, int difficulty)
{
    int firstRowInd = (row * 9) - 9;
    int pos = firstRowInd + (col - 1);
    if (isValidPos(pos))
    {
        if (isNotPreFilled(pos))
        {
            if ((data >= 49) && (data <= 57))
            {
                if (isValidData(data, difficulty, pos))
                {
                    char value;
                    for (int i = 0; i <= pos; i++)
                    {
                        value = Board.front();
                        Reserve.push(value);
                        Board.dequeue();
                    }
                    Board.undodequeue(data);
                    Reserve.pop();
                    for (int i = 0; i < pos; i++)
                    {
                        value = Reserve.top();
                        Board.undodequeue(value);
                        Reserve.pop();
                    }
                }
                else
                {
                    cout << "Wrong Answer" << endl;
                }
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        }
        else
        {
            cout << "Prefilled Cell" << endl;
        }
    }
    else
    {
        cout << "Invalid Position" << endl;
    }
}
bool Sodoku::isNotPreFilled(int pos)
{
    return (Board.traverse(pos) == '-');
}
bool Sodoku::isValidData(char data, int difficulty, int pos)
{
    if (Board.empty())
    {
        cout << "Board is Empty" << endl;
    }
    else
    {
        switch (difficulty)
        {
        case 1:
            str_rightanswer = "534678912672195348198342567859761423426853791713924856961537284287419635345286179";
            return (data == str_rightanswer[pos]);
            break;
        case 2:
            str_rightanswer = "694871325723654198851932467368295714219748653547316982472589136186427539935163874";
            return (data == str_rightanswer[pos]);
            break;
        case 3:
            str_rightanswer = "426789531157243986938516274579324168284167395613958742895671423342895617761432859";
            return (data == str_rightanswer[pos]);
            break;
        }
    }
    return false;
}
bool Sodoku::isValidPos(int pos)
{
    return ((pos >= 0) && (pos < 81));
}
void Sodoku::display()
{
    cout << Board;
}
bool Sodoku::isComplete()
{
    while (true)
    {
        if (Board.returnvalue())
            return false;
        else
            return true;
    }
}
