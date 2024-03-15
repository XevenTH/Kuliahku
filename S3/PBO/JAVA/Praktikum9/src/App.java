import java.util.HashMap;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        HashMap<String, Integer> Mahasiswa = new HashMap<String, Integer>();

        Integer loop = 0;
        Integer choice = 0;

        while (loop == 0) {
            System.out.println("Menu:");
            System.out.println("1. Tambah Data Mahasiswa");
            System.out.println("2. Hapus Data Mahasiswa");
            System.out.println("3. Tampilkan Nilai Mahasiswa");
            System.out.println("4. Tampilkan Semua Mahasiswa");
            System.out.println("5. Keluar");

            Scanner scanner = new Scanner(System.in);
            System.out.print("Pilih Menu(1-5) : ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    TambahDataMahasiswa(Mahasiswa);
                    break;
                case 2:
                    DeleteDataMahasiswa(Mahasiswa);
                    break;
                case 3:
                    TampilNilaiMahasiswa(Mahasiswa);
                    break;
                case 4:
                    TampilMahasiswa(Mahasiswa);
                    break;
                case 5:
                    loop = 1;
                    break;
                default:
                    loop = 1;
                    break;
            }
        }
    }

    private static void TambahDataMahasiswa(HashMap<String, Integer> mahasiswa) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Masukan Nama Mahasiswa : ");
        String dataNama = scanner.nextLine();
        System.out.print("Masukan Nilai Mahasiswa : ");
        Integer dataNilai = scanner.nextInt();
        
        mahasiswa.put(dataNama, dataNilai);

        System.out.println("Data Berhasil Ditambahkan");
        System.out.println();
    }
    
    private static void DeleteDataMahasiswa(HashMap<String, Integer> mahasiswa) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Masukan Nama Mahasiswa yang ingin di hapus : ");
        String deletedData = scanner.nextLine();
        
        for (String M : mahasiswa.keySet()) {
            if (M.equalsIgnoreCase(deletedData)) {
                mahasiswa.remove(M);
                continue;
            }
            System.out.println("Data Tidak Ditemukan");
        }
        
        System.out.println("Data Berhasil DiHapus!!");
        System.out.println();
    }
    
    private static void TampilMahasiswa(HashMap<String, Integer> mahasiswa) {
        System.out.println();
        System.out.println("Daftar Mahasiswa : ");
        for (String M : mahasiswa.keySet()) {
            System.out.println("-) " + M);
        }
        System.out.println();
    }

    private static void TampilNilaiMahasiswa(HashMap<String, Integer> mahasiswa) {
        System.out.println();
        System.out.println("Daftar Nilai Mahasiswa : ");
        for (String M : mahasiswa.keySet()) {
            System.out.println("-) " + M + " : " + mahasiswa.get(M));
        }
        System.out.println();
    }
}
