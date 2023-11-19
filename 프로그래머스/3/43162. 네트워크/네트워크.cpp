#include <string>
#include <vector>
using namespace std;

vector<int> parent(200, -1);

int find_parent(int c1)
{
    while(parent[c1] != - 1)
		c1 = parent[c1];
	return c1;
}

void union_com(int c1, int c2)
{
    c1 = find_parent(c1);
    c2= find_parent(c2);

    if (c1 > c2)
        parent[c1] = c2;
    else if (c1 < c2)
        parent[c2] = c1;
	else
		return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(computers[i][j] == 1)
                union_com(i, j);
        }
    }
    
    for (int k = 0; k < n; k++)
    {
        if(parent[k] == -1)
            answer++;
    }
            
    return answer;
}