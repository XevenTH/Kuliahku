import java.util.ArrayList;
import java.util.List;

public class Inventory {
    // buat array Product dan atribut size
    List<Product> productAry = new ArrayList<Product>();
    int size = 0;
    int currentSize = 0;

    // buat constructor Inventory untuk set panjang kapasitas product, dan set size
    // = 0
    public Inventory(int size) {
        this.size = size;
    }

    // buat method void addProduct untuk menambahkan data ke array products, dan
    // buat percabangan untuk mengukur apabila kapasitas penuh maka tidak bisa
    // menambahkan data lagi dan muncul kalimat "Inventory is full. Cannot add more
    // products."
    public void addProduct() {
        if (currentSize < size) {
            Product newProduct = new Product();
            productAry.add(newProduct);

            size++;
            currentSize++;
        } else {
            System.out.println("Inventory is full. Cannot add more products.");
        }
    }

    // buat method displayProducts untuk menampilkan semua data product
    public void displayAllProducts() {
        System.out.println();
        for (Product product : productAry) {
            System.out.println("---------------------------------------");
            System.out.println("Name : " + product.getProductName());
            System.out.println("price : " + product.getPrice());
            System.out.println("stock : " + product.getStock());
        }
        System.out.println("---------------------------------------");
    }

    // buat method deleteProductByName untuk menghapus data
    public void deleteProductByName(String productName) {
        System.out.println(currentSize);
        if (currentSize > 0) {
            for (Product product : productAry) {
                if (product.getProductName().compareToIgnoreCase(productName) == 1) {
                    productAry.remove(product);
                    size--;
                    currentSize--;
                } else {
                    continue;
                }
            }
        } else {
            System.out.println("Nothing That Can be Delete");
        }
    }

    @Override
    protected void finalize() throws Throwable {
        System.out.println("Product Array Has Been Destroyed");
    }
}
