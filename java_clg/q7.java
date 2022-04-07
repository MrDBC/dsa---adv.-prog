class Student {
    int roll;
    String name;
    int score;

    void set(int roll, String s, int score) {
        this.roll = roll;
        this.name = s;
        this.score = score;
    }

    void display() {
        System.out.println("roll : " + roll + " name : " + name + " score : " + score);
    }

    void copy(Student stu) {
        roll = stu.roll;
        name = stu.name;
        score = stu.score;
    }
}

public class q7 {
    public static void main(String args[]) {
        Student obj = new Student();
        Student obj2 = new Student();
        obj.set(42, "Dhan bahadur chhettri", 75);
        obj2.set(34, "shahid", 80);
        obj.display();
        obj2.display();

        obj.copy(obj2);
        obj.display();
    }
}
