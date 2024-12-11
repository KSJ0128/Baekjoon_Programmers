import java.util.*;
import java.io.*;

class Solution {
    public String solution(int[] numbers) {
        List<String> arr = new ArrayList<>();
        for (int i = 0; i < numbers.length; i++) {
            arr.add(Integer.toString(numbers[i]));
        }
        Collections.sort(arr, (a,b) -> (b+a).compareTo(a+b));
        
        StringBuilder answer = new StringBuilder();
        for (String num : arr) {
            answer.append(num);
        }
        
        if (answer.charAt(0) == '0')
            return "0";
        
        return answer.toString();
    }
}