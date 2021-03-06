public List<Point> kthNearst(List<Point> points, int k) {
    List<Point> res = new ArrayList<>();
    if (k == 0) return res;
    if (k > points.size()) return points;
    PriorityQueue<Point> heap = new PriorityQueue<>(new Comparator<Point>() {
      public int compare(Point p1, Point p2) {
        return getDistance(p2) - getDistance(p1);
      }
    });
    for (Point item : points) {
      if (heap.size() < k) {
        heap.offer(item);
      }
      else {
        Point curt = heap.peek();
        if (getDistance(item) < getDistance(curt)) {
          heap.offer(item);
          heap.poll();
        }
      }
    }
    while (!heap.isEmpty()) {
      res.add(heap.poll());
    }
    return res;
  }
  public int getDistance(Point p) {
    return p.x * p.x + p.y * p.y;
  }