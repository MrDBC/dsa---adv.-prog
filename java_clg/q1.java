import java.util.Scanner;

// A Java program to print "Hello World" 
public class q1 {
    public static void main(String args[]) {
        short a, b;
        Scanner sc = new Scanner(System.in);
        a = sc.nextShort();
        b = sc.nextShort();
        System.out.print(a + b);
        // System.out.println("Hello World");

        sc.close();
    }
}