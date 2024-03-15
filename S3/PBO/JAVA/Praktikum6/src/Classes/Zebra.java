package Classes;

public class Zebra extends Animal {
    private boolean IsWild;

    @Override
    public boolean IsMammal() {
        return true;
    }

    @Override
    public void Mate() {
        System.out.println("Tidak diketahui cara Berkembang biaknya");
    }

    @Override
    public void Mate(String cara) {
        System.out.println("Zebra Berkembang biak dengan cara " + cara);
    }

    public void Run() {
        System.out.println("Zebra Is Running.....");
    }

    public boolean isIsWild() {
        return IsWild;
    }

    public void setIsWild(boolean isWild) {
        IsWild = isWild;
    }

}
