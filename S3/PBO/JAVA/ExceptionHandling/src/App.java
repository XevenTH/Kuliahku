import java.util.InputMismatchException;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Masuk bilangan : ");
            int input = scanner.nextInt();

            if (input % 2 == 0) {
                System.out.println("Ini adalah Bilangan Bulat");
            } else {
                throw new IllegalArgumentException("Error : Bilangan yang anda masukan adalah bilangan ganjil");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}
