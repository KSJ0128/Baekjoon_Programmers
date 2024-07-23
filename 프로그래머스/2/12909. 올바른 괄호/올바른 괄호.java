import java.util. *;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> stack = new Stack<Character>();
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') stack.push('(');
            else if (s.charAt(i) == ')' && !stack.empty() && 
                     stack.peek() == '(') stack.pop();
            else {
                answer = false;
                break;
            }
        }
        if (answer && !stack.empty()) return false;
        
        return answer;
    }
}