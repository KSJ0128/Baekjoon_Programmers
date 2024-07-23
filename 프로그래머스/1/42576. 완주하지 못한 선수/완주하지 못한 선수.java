import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> hash = new HashMap<String, Integer>(100000);
        
        for (String complete : completion) { // 중복 반영
            if (!hash.containsKey(complete)) {
                hash.put(complete, 1);
            }
            else {
                hash.replace(complete, hash.get(complete) + 1);
            }
        }
        
        for (String part : participant) {
            if (hash.containsKey(part)) {
                if (hash.get(part) == 1)
                    hash.remove(part);
                else
                    hash.replace(part, hash.get(part) - 1);
            }
            else return part;
        }
        return null;
    }
}