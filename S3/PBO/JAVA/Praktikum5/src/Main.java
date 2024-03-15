public class Main {
    public static void main(String[] args) {
        
    }
}

class Obj {
    private String Data;

    public Obj(String data) {
        this.Data = data;
    }

    public String getData() {
        return Data;
    }

    public void PrintData() {
        System.out.println("Data Contains : " + this.Data);
    }
}
