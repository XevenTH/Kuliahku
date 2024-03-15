import java.util.ArrayList;
import java.util.List;

import Class.Tipe;

public class App {
    public static void main(String[] args) {
        List<Kendaraan> ListKendaraan = new ArrayList<Kendaraan>();

        Mobil Tesla = new Mobil("S 6530 AAA", 50, "Tesla", 2);
        Motor Honda = new Motor("L 6565 AX", 4, Tipe.matic, 0.05, "32 September 2018");
        Sepeda Polygon = new Sepeda(null, 0, "Sepeda Gunung", "Hijau Telur Asin");

        ListKendaraan.add(Tesla);
        ListKendaraan.add(Honda);
        ListKendaraan.add(Polygon);
        
        for (Kendaraan kendaraan : ListKendaraan) {
            kendaraan.RevealAllData();
            System.out.println();
        }
        
    }
}

class Kendaraan {
    protected String nomor_plat;
    protected float kapasitas_bahan_bakar;

    public Kendaraan(String nomor_plat, float kapasitas_bahan_bakar) {
        this.nomor_plat = nomor_plat;
        this.kapasitas_bahan_bakar = kapasitas_bahan_bakar;
    }

    public void RevealAllData() {
        System.out.println("Nomor Plat : " + nomor_plat);
        System.out.println("Kapasitas Bahan Bakar : " + kapasitas_bahan_bakar);
    }
}

class Mobil extends Kendaraan {
    String Merk;
    float konsumsi_bbm;

    public Mobil(String nomor_plat, float kapasitas_bahan_bakar, String Merk, float konsumsi_bbm) {
        super(nomor_plat, kapasitas_bahan_bakar);
        this.Merk = Merk;
        this.konsumsi_bbm = konsumsi_bbm;
    }

    public float HitungJarakTempuh() {
        return kapasitas_bahan_bakar / konsumsi_bbm;
    }

    @Override
    public void RevealAllData() {
        super.RevealAllData();
        System.out.println("\nMobil\n");
        System.out.println("Merk : " + Merk);
        System.out.println("Konsumsi BBM : " + konsumsi_bbm);
        System.out.println("Maksimal Jarak Tempuh : " + HitungJarakTempuh());
    }
}

class Motor extends Kendaraan {
    Tipe jenis_sepeda;
    Double konsumsi_bbm;
    String tahun_pembuatan;

    public Motor(String nomor_plat, int kapasitas_bahan_bakar, Tipe tipe, Double konsumsi_bbm, String tahun_pembuatan) {
        super(nomor_plat, kapasitas_bahan_bakar);
        this.jenis_sepeda = tipe;
        this.konsumsi_bbm = konsumsi_bbm;
        this.tahun_pembuatan = tahun_pembuatan;
    }

    public Double HitungJarakTempuh() {
        return kapasitas_bahan_bakar / konsumsi_bbm;
    }

    @Override
    public void RevealAllData() {
        System.out.println("Motor\n");
        super.RevealAllData();
        System.out.println("Jenis Sepeda : " + jenis_sepeda);
        System.out.println("Konsumsi BBM : " + konsumsi_bbm);
        System.out.println("Tahun Pembuatan : " + tahun_pembuatan);
        System.out.println("Maksimal Jarak Tempuh : " + HitungJarakTempuh());
    }
}

class Sepeda extends Kendaraan {
    String jenis_sepeda;
    String warna;

    public Sepeda(String nomor_plat, float kapasitas_bahan_bakar, String jenis, String warna) {
        super(nomor_plat, kapasitas_bahan_bakar);
        this.jenis_sepeda = jenis;
        this.warna = warna; 
    }

    @Override
    public void RevealAllData() {
        System.out.println("Sepeda\n");
        System.out.println("Jenis Sepeda : " + jenis_sepeda);
        System.out.println("Warna : " + warna);
    }
}
