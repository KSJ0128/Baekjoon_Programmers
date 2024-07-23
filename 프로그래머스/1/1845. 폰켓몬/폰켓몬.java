import java.util.*;
    
class Solution {
    public int solution(int[] nums) {
        
        Set<Integer> set = new HashSet<Integer>();
        
        for (int num : nums) {
             set.add(num);
        }
        
        int max = set.size() > nums.length / 2 ? nums.length / 2 : set.size();
        
        return max;
    }
}