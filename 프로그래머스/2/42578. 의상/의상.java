import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        HashMap<String, List<String>> hm = new HashMap<String, List<String>> ();
        
        for (int i = 0; i < clothes.length; i++) {
            hm.putIfAbsent(clothes[i][1], new ArrayList<>());
            hm.get(clothes[i][1]).add(clothes[i][0]);
        }
        
        int count = 1;
        for (String key : hm.keySet()) {
            count *= hm.get(key).size() + 1;
        }
        
        return count - 1;
    }
}