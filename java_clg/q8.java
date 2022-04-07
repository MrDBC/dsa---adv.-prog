class Student {
    int roll;
    String name;
    int score;

    Student(int roll) {
        this.roll = roll;
    }

    Student(int roll, String name) {
        this.roll = roll;
        this.name = name;

    }

    Student(int roll, String s, int score) {
        this.roll = roll;
        this.name = s;
        this.score = score;
    }

    Student() {
        System.out.println("no arguments \n");
    }

    void display() {
        System.out.println("roll : " + this.roll + " name : " + name + " score : " + score);
    }

    void copy(Student stu) {
        roll = stu.roll;
        name = stu.name;
        score = stu.score;
    }
}

public class q8 {
    public static void main(String args[]) {
        Student obj = new Student(42, "Dhan bahadur chhettri", 75);
        Student obj2 = new Student(14);
        Student obj3 = new Student(15, "fucku");
        Student obj4 = new Student();
        Student obj5 = new Student();
        obj5.copy(obj);

        obj.display();
        obj2.display();
        obj3.display();
        obj4.display();
        obj5.display();

    }
}
