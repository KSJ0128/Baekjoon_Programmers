import java.io.*;

class Solution {
    public int[] solution(int n) {
        int total = (1 + n) * n / 2;
        int[] answer = new int[total];
        int[][] triangle = new int[n][n];

        int x = -1, y = 0, num = 1, state = 0;
        
        while (num <= total) {
				if (state == 0) {
                    if (x + 1 < n && triangle[x+1][y] == 0)
                        x++;
                    else {
                        state = (state + 1) % 3;
                        continue;
                    }
				}
				else if (state == 1) {
                    if (y + 1 < n && triangle[x][y+1] == 0)
                        y++;
                    else {
                        state = (state + 1) % 3;
                        continue;
                    }
				}
				else if (state == 2) {
                    if (x - 1 >= 0 && y - 1 >= 0 && triangle[x-1][y-1] == 0) {
                        x--;
                        y--;
                    }
                    else {
                        state = (state + 1) % 3;
                        continue;
                    }
				}
                triangle[x][y] = num++;
        }
        
        int index = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(triangle[i][j] != 0){
                    answer[index++] = triangle[i][j];
                }
            }   
        }
        
        return answer;
    }
}