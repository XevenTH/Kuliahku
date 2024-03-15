import java.util.Scanner;

public class Product {
    private String productName;
    private int price;
    private int stock;

    public Product() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter The Product Name : ");
        this.productName = scanner.nextLine();
        System.out.print("Enter The Product Price : ");
        this.price = Integer.parseInt(scanner.nextLine());
        System.out.print("Enter The Product Stock : ");
        this.stock = Integer.parseInt(scanner.nextLine());
    }

    @Override
    protected void finalize() throws Throwable {
        System.out.println(productName + " Has Been Destroyed");
    }

    public String getProductName() {
        return productName;
    }

    public int getPrice() {
        return price;
    }

    public int getStock() {
        return stock;
    }
}