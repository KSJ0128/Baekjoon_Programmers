import java.util.Queue;
import java.util.LinkedList;
import java.util.Arrays;


class Solution {
    boolean[] visited;
    int network = 0;
    
    void BFS(int[][] computers, int n, int idx) {
        Queue<Integer> que = new LinkedList();
        que.add(idx);
        visited[idx] = true;
        
        while (!que.isEmpty())
        {
            int front = que.element();
            que.remove();
            
            for (int i = 0; i < n; i++) {
                if (i != front && computers[front][i] == 1 && visited[i] == false) {
                    visited[i] = true;
                    que.add(i);
                }
            }
        }    
    }
    
    public int solution(int n, int[][] computers) {
        visited = new boolean[n];
        Arrays.fill(visited, false);
      
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                BFS(computers, n, i);
                network += 1;
            }
        }
        
        return network;
    }
}