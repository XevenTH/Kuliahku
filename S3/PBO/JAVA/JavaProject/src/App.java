import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        List<Mahasiswa> datas = new ArrayList<Mahasiswa>();

        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Masukan Jumlah Mahasiswa : ");
            int jumlah = scanner.nextInt();

            for (int i = 0; i < jumlah; i++) {
                scanner.nextLine();
                Mahasiswa mahasiswa = new Mahasiswa();

                System.out.print("Masukan Nama Mahasiswa ke-" + (i + 1) + " : ");
                mahasiswa.setNama(scanner.nextLine());
                System.out.print("Masukan Jurusan Mahasiswa ke-" + (i + 1) + " : ");
                mahasiswa.setJurusan(scanner.nextLine());
                System.out.print("Masukan NIM Mahasiswa ke-" + (i + 1) + " : ");
                mahasiswa.setNIM(scanner.nextInt());

                System.out.println("\n");
                datas.add(mahasiswa);
            }
            
            System.out.println("\nDaftar Biodata");
            for (Mahasiswa mahasiswa : datas) {
                System.out.println("Nama : " + mahasiswa.getNama());
                System.out.println("NIM : " + mahasiswa.getNIM());
                System.out.println("Jurusan : " + mahasiswa.getJurusan());
                
                System.out.println("\n");
            }
        }
    }
}

class Mahasiswa {
    private String Nama;
    private int NIM;
    private String Jurusan;

    public String getJurusan() {
        return this.Jurusan;
    }

    public void setJurusan(String jurusan) {
        this.Jurusan = jurusan;
    }

    public int getNIM() {
        return this.NIM;
    }

    public void setNIM(int NIM) {
        this.NIM = NIM;
    }

    public String getNama() {
        return this.Nama;
    }

    public void setNama(String nama) {
        this.Nama = nama;
    }
}
