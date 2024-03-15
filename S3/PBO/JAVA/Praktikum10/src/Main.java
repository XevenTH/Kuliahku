import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        List<Integer> numbers = new ArrayList<Integer>();
        List<Thread> threads = new ArrayList<>();

        Scanner scanner = new Scanner(System.in);

        System.out.print("Masukan 10 Angka disini : ");
        for (int i = 1; i <= 10; i++) {
            int data = scanner.nextInt();
            numbers.add(data);
        }

        for (int i = 0; i < numbers.size(); i++) {
            threads.add(new Thread(new GeneratePrimeThread(numbers.get(i))));
        }

        Collections.shuffle(threads);

        for (Thread thread : threads) thread.start();

        for (Thread thread : threads) thread.join();
    }
}
