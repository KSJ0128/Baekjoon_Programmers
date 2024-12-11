import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        List<Integer> answer = new ArrayList<>();
        
        for (int i = 0; i < commands.length; i++) {
            int start = commands[i][0];
            int end = commands[i][1];
            int n = commands[i][2];
            
            List<Integer> arr = new ArrayList<>();
            for (int j = start-1; j < end; j++) {
                arr.add(array[j]);
            }
            Collections.sort(arr);
            answer.add(arr.get(n-1));
        }
        
        return answer.stream().mapToInt(i->i).toArray();
    }
}