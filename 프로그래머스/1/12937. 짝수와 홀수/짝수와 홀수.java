import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
    public String solution(int num) {
        String answer = "";
        if (num % 2 == 0)
            answer = "Even";
        else
            answer = "Odd";
        
        return answer;
    }
}