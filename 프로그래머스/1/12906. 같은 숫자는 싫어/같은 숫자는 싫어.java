import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Stack<Integer> stack = new Stack<Integer>();
        ArrayList<Integer> array = new ArrayList<>();
        
        for (int i = 0; i < arr.length; i++) {
            if (stack.empty()) { // 스택이 비어있는 경우
                stack.push(arr[i]);
                array.add(arr[i]);
            }
            else if (stack.peek() != arr[i]) { // 마지막에 입력 받은 요소와 동일한 경우
                stack.push(arr[i]);
                array.add(arr[i]);
            }
        }

        int[] answer = new int[array.size()];
        for (int i = 0; i < array.size(); i++) {
            answer[i] = array.get(i);
        }
        return answer;
    }
}