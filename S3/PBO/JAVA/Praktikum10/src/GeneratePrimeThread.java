public class GeneratePrimeThread implements Runnable {
    private final int number;

    public GeneratePrimeThread(int number) {
        this.number = number;
    }

    @Override
    public void run() {
        if (isPrime(number)) {
            System.out.println("Angka " + number + " adalah Bilangan Prima");
        } else {
            System.out.println("Angka " + number + " bukan Bilangan Prima");
        }
    }

    private boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}