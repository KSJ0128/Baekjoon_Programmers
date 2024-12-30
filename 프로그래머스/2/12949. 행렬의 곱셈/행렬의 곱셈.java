import java.util.*;

class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int row = arr1.length;
        int col = arr2[0].length;
        int common = arr1[0].length;
        int[][] answer = new int[row][col];
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < common; k++) {
                    answer[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        return answer;
    }
}
/*
arr1 열 = arr2 행
arr3 : arr1 행 * arr2 열
*/
/*
2 3 2
4 2 4
3 1 4
    
5 4 3
2 4 1
3 1 1
    
22 22 11
36 28 18
29 20 14
*/