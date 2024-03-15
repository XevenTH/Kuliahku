package Classes;

import Interfaces.ISwim;

public class Fish extends Animal implements ISwim {
    private int SizeFt;
    private boolean CanEat;
    
    @Override
    public boolean IsMammal() {
        return false;
    }
    
    @Override
    public void Mate() {
        System.out.println("Tidak diketahui cara Berkembang biaknya");
    }

    @Override
    public void Mate(String cara) {
        System.out.println("Fish Berkembang biak dengan cara " + cara);
    }

    @Override
    public void Swim() {
        System.out.println("FIsh Is Swimming.....");
    }

    public boolean isCanEat() {
        return CanEat;
    }

    public void setCanEat(boolean canEat) {
        CanEat = canEat;
    }

    public int getSizeFt() {
        return SizeFt;
    }

    public void setSizeFt(int sizeFt) {
        SizeFt = sizeFt;
    }

}
