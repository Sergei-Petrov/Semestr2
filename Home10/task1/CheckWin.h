#pragma once

class CheckWin
{
public:
    CheckWin()
    {
        restart();
    }
    bool check(int i);
    void addX(int i);
    void addO(int i);
    void restart();
    short count;
private:
    bool horizont(int tmp);
    bool vertical(int tmp);
    bool diagonals();
    short table[3][3];
};

