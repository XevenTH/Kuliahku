package Classes;

public class Circle extends Shape {
    private int Radius;

    public Circle(int radius) {
        this.Radius = radius;
    }

    @Override
    public void Draw() {
        System.out.println("Menggambar lingkaran dengan radius" + Radius);
    }

    @Override
    public double CalculateArea() {
        return Math.PI * Radius * Radius;
    }
}
