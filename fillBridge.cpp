public String fillBridge(String s) {
    if (s.length() <= 1) {
      return s;
    }
    char[] letters = s.toCharArray();
    int cut = 0;
    char prev = '*';
    for (int i = 0; i < letters.length; i++) {
      if (letters[i] == '-') {
        continue;
      }
      if (letters[i] == prev) {
        fill(letters,cut,i);
        cut = i + 1;
      }
      else {
        cut = i;
        prev = letters[i];
      }
    }
    return String.valueOf(letters);
  }
  private void fill(char[] letters, int start, int end) {
    for (int i = start; i <= end; i++) {
      letters[i] = '+';
    }
  }