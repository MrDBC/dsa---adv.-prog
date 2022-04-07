
class BankAcct {
    long ac;
    float bal;
    float rate;

    BankAcct(long ac, float bal, float rate) {
        this.ac = ac;
        this.bal = bal;
        this.rate = rate;
    }

    void change_rate(float rate) {
        this.rate = rate;
    }

    void display_rate() {
        System.out.println("current interest rate = " + this.rate);
    }

    float calc_bal() {
        return bal = bal + (bal * rate) / 100;
    }

    float calc_si() {
        return (bal * rate) / 100;
    }
}

public class q9 {
    public static void main(String args[]) {
        BankAcct obj = new BankAcct(12345, 10000, 5);
        System.out.println("current balance = " + obj.calc_bal());
        obj.change_rate(10);
        obj.display_rate();
        System.out.println("current balance = " + obj.calc_bal());
        System.out.println("current simple interest = " + obj.calc_si());

    }
}
