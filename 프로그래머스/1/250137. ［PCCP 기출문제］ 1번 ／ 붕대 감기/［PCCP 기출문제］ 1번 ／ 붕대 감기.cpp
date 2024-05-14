#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int size = attacks.size();
    int attack_i = 0;
    int full = health;
    int time = 0;
    
    for (int i = 0; i <= attacks[size - 1][0]; i++)
    {
        if (attacks[attack_i][0] > i && health < full) // 공격X, 최대 체력 X
        {
            health += bandage[1];
            time++;
            if (time == bandage[0])
            {
                health += bandage[2];
                time = 0;
            }
            if (health > full)
                health = full;
        }
        else if (attacks[attack_i][0] == i) // 공격O
        {
            time = 0;
            health -= attacks[attack_i][1];
            if (health <= 0)
                return -1;
            attack_i++;
        }
    }
    
    return health;
}