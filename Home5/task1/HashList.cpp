#include "HashList.h"
#include "iostream"

HashList::~HashList()
{
    for (int i = 0; i < SIZE; i++)
        delete HashTable[i];
    delete func;
}

void HashList::add(string str)
{
    HashTable[func->call(str,SIZE)]->add(str);
}

void HashList::remove(string str)
{
    HashTable[func->call(str,SIZE)]->remove(str);
}

bool HashList::search(string str)
{
    return HashTable[func->call(str, SIZE)]->search(str);
}

void HashList::selectOfFunction(int x)
{
    func->change(x);
    reboot();
}

void HashList::status()
{
    int sum = 0;
    int free = 0;
    int coll = 0;
    int max = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (HashTable[i]->isEmpty())
            free++;
        else
        {
            List *tmp = HashTable[i];
            if (max < tmp->length())
                max = tmp->length();
            if (tmp->length() > 1)
                coll++;
            do
                sum = sum + tmp->curRepeats();
            while (tmp->further());
        }
    }
    cout << "Number of words = " << sum << endl;
    cout << "Number of empty cells = " << free << endl;
    cout << "Number of conflicts = " << coll << endl;
    cout << "Maximum length of conflict = " << max << endl;
    cout << "Load Factor = " << double(sum) / SIZE << endl;
}

void HashList::reboot()
{
    List *tmp[SIZE];
    for (int i = 0; i < SIZE; i++)
        tmp[i] = new List;
    for (int i = 0; i < SIZE; i++)
    {
        if (!HashTable[i]->isEmpty())
        {
            do
            {
                for(int j = 0; j < HashTable[i]->curRepeats(); j++)
                    tmp[func->call(HashTable[i]->curValue(), SIZE)]->add(HashTable[i]->curValue());
            }
            while(HashTable[i]->further());
        }
    }
    List *tmp2;
    for (int i = 1; i < SIZE; i++)
    {
        tmp2 = HashTable[i];
        HashTable[i] = tmp[i];
        delete tmp2;
    }
}
