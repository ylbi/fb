 public int countTime(String s, int cooldown) {
        if (s.length() <= 1) {
            return s.length();
        }
        int time = 0;
        int pos = 0;
        Map<Character,Integer> ch2index = new HashMap<>();
        while (pos < s.length()) {
            char curt = s.charAt(pos);
            if (ch2index.containsKey(curt)) {
                time = Math.max(time+1, ch2index.get(curt)  + cooldown + 1);
            }
            else {
                time ++;
            }
            ch2index.put(curt,time);
            pos ++;

        }
        return time;
        }