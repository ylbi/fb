public class Main {
    public int maxProfix(Interval[] customers) {
        if (customers == null || customers.length == 0) {
            return 0;
        }
        PriorityQueue<Price> timeline = new PriorityQueue<Price>(new Comparator<Price>() {
            public int compare(Price p1, Price p2) {
                if (p1.value == p2.value) {
                     if (p1.acceptable) {
                         return -1;
                     }
                     return 1;
                }
                return p1.value - p2.value;
            }
        });
        for (int i = 0; i < customers.length; i++) {
            timeline.offer(new Price(customers[i].start,true));
            timeline.offer(new Price(customers[i].end,false));
        }
        int maxPro = -1;
        int count = 0;
        while (!timeline.isEmpty()) {
            Price curt = timeline.poll();
            int price = curt.value;
            if (curt.acceptable) {
                count ++;
            }
            else {
                count --;
            }
            maxPro = Math.max(maxPro,count * price);
        }
        return maxPro;
    }
}