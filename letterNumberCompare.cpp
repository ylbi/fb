//数字比字母小，数字是一个
//注意两个指针都是数字的情况

public int compare(String s1, String s2) {
   if (s1.length() == 0 && s2.length() == 0) return 0;
   if (s1.length() == 0) return -1;
   if (s2.length() == 0) return 1;
   int s1pos = 0;
   int s2pos = 0;
   int num1 = 0;
   int num2 = 0;
   while (s1pos < s1.length() && s2pos < s2.length()) {
     char s1curt = s1.charAt(s1pos);
     char s2curt = s2.charAt(s2pos);
     if (Character.isDigit(s1curt) || Character.isDigit(s2curt)) {
       if (Character.isDigit(s1curt) && Character.isDigit(s2curt)) {
         while (s1pos < s1.length() && Character.isDigit(s1.charAt(s1pos))) {
           num1 = num1 * 10 + s1.charAt(s1pos) - '0';
           s1pos ++;
         }
         while (s2pos < s2.length() && Character.isDigit(s2.charAt(s2pos))) {
           num2 = num2 * 10 + s2.charAt(s2pos) - '0';
           s2pos ++;
         }
         if (num1 < num2) {
           return 1;
         }
         else if (num1 > num2) {
           return -1;
         }
         continue;
       }
       else if (Character.isDigit(s1curt)) {
         return 1;
       }
       return -1;
     }
     else {
       if (s1curt > s2curt) {
         return 1;
       }
       else if (s1curt < s2curt){
         return -1;
       }
       s1pos ++;
       s2pos ++;
     }
   }
   if (s1.length() == s2.length()) {
     return 0;
   }
   return s1.length()  < s2.length()?-1:1;
 }