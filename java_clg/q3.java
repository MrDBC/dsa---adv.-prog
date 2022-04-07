import java.util.Scanner;

public class q3 {
    public static void main(String args[]) {
        int cm;
        Scanner sc = new Scanner(System.in);
        cm = sc.nextInt();

        int feet;
        double inches;
        feet = (int) (cm / 30.5);
        inches = (cm - (feet * 30.5)) / 2.54;

        System.out.println(feet + " feet & " + String.format("%.2f", inches) + " inches");
        sc.close();
    }
}
