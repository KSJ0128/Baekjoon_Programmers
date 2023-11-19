#include <iostream>
#include <vector>
#include <algorithm> // find 함수를 사용하기 위해 필요합니다.
using namespace std;

vector<int> inorderIndex;
vector<int> postorderIndex;

void preorder(int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd || postStart > postEnd)
        return;

    int rootValue = postorderIndex[postEnd];
    cout << rootValue << " ";

    int rootIndex = find(inorderIndex.begin() + inStart, inorderIndex.begin() + inEnd, rootValue) - inorderIndex.begin();

    int leftSubtreeSize = rootIndex - inStart;
    int rightSubtreeSize = inEnd - rootIndex;

    // 왼쪽 서브트리를 순회
    preorder(inStart, rootIndex - 1, postStart, postStart + leftSubtreeSize - 1);

    // 오른쪽 서브트리를 순회
    preorder(rootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    inorderIndex.resize(n);
    postorderIndex.resize(n);

    for (int i = 0; i < n; i++)
        cin >> inorderIndex[i];
    for (int i = 0; i < n; i++)
        cin >> postorderIndex[i];

    preorder(0, n - 1, 0, n - 1);

    return 0;
}
