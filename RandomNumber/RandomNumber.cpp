// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <map>

using namespace std;

int random(int lower, int upper)
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL));
        first = false;
    }
    int toReturn = lower+ rand()%(upper+1-lower);
    return toReturn;
}
int main()
{
    map<int, bool> numbermap;
    
    int count=numbermap.size();
    vector<int> toPopulate;
    while(count  < 52)
    {
        int numtoadd = random(1,52);
        auto exist = numbermap.find(numtoadd);
        while (exist != numbermap.end())
        {
            numtoadd = random(1, 52);
            exist = numbermap.find(numtoadd);
        }
        numbermap.insert(std::pair<int,bool>(numtoadd,true));
        toPopulate.push_back(numtoadd);
        count = numbermap.size();
    
    }
   
    std::for_each(toPopulate.begin(), toPopulate.end(), []( int valin)
    {
        
        std::cout << "\n";
        std::cout << valin;
    });
    
    numbermap.count(count);
    
    
    
    return 1;
}
