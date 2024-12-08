import java.util.*;

class Solution {
    public int first(int[] answers) {
        int solve = 0;
        int num[] = {1,2,3,4,5};
        int size = 5;
        for (int i = 0; i < answers.length; i++) {
            if (num[i % size] == answers[i])
                solve++;
        }
        return solve;
    }
    
    public int second(int[] answers) {
        int solve = 0;
        int num[] = {2,1,2,3,2,4,2,5};
        int size = 8;
        
        for (int i = 0; i < answers.length; i++) {
            if (answers[i] == num[i % size])
                solve++;
        }
        return solve;
    }
    
    public int third(int[] answers) {
        int solve = 0;
        int num[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int size = 10;
        
        for (int i = 0; i < answers.length; i++) {
            if (answers[i] == num[i % size])
                solve++;
        }
        return solve;
    }
    
    
    public int[] solution(int[] answers) {
        int score1 = first(answers);
        int score2 = second(answers);
        int score3 = third(answers);
        int maxScore = Math.max(score1, Math.max(score2, score3));

        List<Integer> answer = new ArrayList<>();
      
        if (maxScore == score1) answer.add(1);
        if (maxScore == score2) answer.add(2);
        if (maxScore == score3) answer.add(3);
        
        return answer.stream().mapToInt(i -> i).toArray();
    }
}