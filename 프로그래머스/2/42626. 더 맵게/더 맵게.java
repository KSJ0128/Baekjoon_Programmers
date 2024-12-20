import java.util.*;
    
class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Long> pq = new PriorityQueue();
        int cnt = 0;
        
        for (int num : scoville) {
            pq.offer(Long.valueOf(num));
        }
        
        while (true) {
            Long first = pq.poll();
            
            if (first != null && first >= K)
                return cnt;
            
            Long second = pq.poll();
            
            if (first == null || second == null)
                return -1;
            else {
                pq.add(first + second * 2);
                cnt++;
            }
        }
    }
}