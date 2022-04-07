import java.util.Scanner;

public class q4 {
    public static void main(String args[]) {
        int r;
        double pi = 3.14;
        System.out.print("enter radius : ");
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        System.out.print("area of the circle = " + pi * r * r);

        sc.close();
    }
}
