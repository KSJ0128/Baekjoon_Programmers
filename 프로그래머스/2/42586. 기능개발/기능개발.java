import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> queue = new LinkedList<>();
        int day = 0;
        
        // 큐에 각 기능에 소요되는 일자 기록
        for (int i = 0; i < progresses.length; i++) {
            while (progresses[i] + speeds[i] * day < 100) day++;
            queue.offer(day);
        }
        
        ArrayList<Integer> arrs = new ArrayList<Integer>();
        int prev = queue.poll();
        arrs.add(1);
        while (!queue.isEmpty()) {
            if (prev >= queue.peek()) {
                arrs.set(arrs.size()-1, arrs.get(arrs.size() - 1) + 1);
                queue.remove();
            }
            else {
                prev = queue.poll();
                arrs.add(1);
            }
        }
        
        int[] answer = new int[arrs.size()];

        for (int i = 0; i < arrs.size(); i++) {
            answer[i] = arrs.get(i);
        }
        
        return answer;
    }
}