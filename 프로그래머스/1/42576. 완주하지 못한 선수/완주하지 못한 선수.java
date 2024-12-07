import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        
        for (String person : participant) {
            map.putIfAbsent(person, 0);
            map.replace(person, map.get(person) + 1);
        }
        
        for (String person : completion) {
            map.replace(person, map.get(person) - 1);
            if (map.get(person) == 0)
                map.remove(person);
        }
        
        return map.keySet().iterator().next();
    }
}