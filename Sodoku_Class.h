#include "Stack_Class.h"
#include "Queue_Class.h"
class Sodoku
{
private:
    Queue Board;
    Stack Reserve;
    string str_board;
    string str_rightanswer;

public:
    Sodoku();
    Sodoku(int difficulty);
    void insert(char data, int row, int col, int difficulty);
    bool isNotPreFilled(int pos);
    bool isValidPos(int pos);
    bool isValidData(char data, int difficulty, int pos);
    void display();
    bool isComplete();
};