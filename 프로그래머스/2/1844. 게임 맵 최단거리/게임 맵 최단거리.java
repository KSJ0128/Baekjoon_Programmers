import java.util.Queue;
import java.util.LinkedList;

class Solution {
    int[][] visited;
    int[] dr = {1,0,-1,0};
    int[] dc = {0,1,0,-1};
    int n, m;
    
    class Point {
        int row, col;
        Point(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }
    
    public void BFS(int[][] maps) {
        Queue<Point> que = new LinkedList();
        que.add(new Point(0, 0));
        visited[0][0] = 1;
        
        while (!que.isEmpty()) {
            int row = que.element().row;
            int col = que.element().col;
            que.remove();
            
            for (int i = 0; i < 4; i++) {
                if (row + dr[i] >= 0 && row + dr[i] < n && col + dc[i] >= 0 && col + dc[i] < m)
                {
                    if (maps[row + dr[i]][col + dc[i]] == 1 && 
                        (visited[row + dr[i]][col + dc[i]] == -1 || 
                         visited[row + dr[i]][col + dc[i]] > visited[row][col] + 1)) { 
                        que.add(new Point(row + dr[i], col + dc[i]));
                        visited[row + dr[i]][col + dc[i]] = visited[row][col] + 1;
                    }
                }
            }
        }
    }
    
    public int solution(int[][] maps) {
        n = maps.length;
        m = maps[0].length;
        visited = new int[n][m];

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                visited[i][j] = -1;
            
        BFS(maps);
        
        return visited[n-1][m-1];
    }
}