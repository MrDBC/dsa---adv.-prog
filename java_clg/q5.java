import java.util.Scanner;

public class q5 {
    public static void main(String args[]) {
        String s1, s2;
        Scanner sc = new Scanner(System.in);
        s1 = sc.next();
        s2 = s1;

        System.out.println(s1 == s2);
        System.out.println(s1.equals(s2));

        String s3, s4;
        s3 = sc.next();
        s4 = sc.next();

        System.out.println(s3 == s4);
        System.out.println(s3.equals(s4));

        sc.close();

    }
}
