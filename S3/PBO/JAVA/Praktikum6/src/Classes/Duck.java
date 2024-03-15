package Classes;

import Interfaces.ISwim;

public class Duck extends Animal implements ISwim {
    private String BeakColor = "yellow";

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
        System.out.println("Duck Is Swimming.....");
    }

    public void Quack() {
        System.out.println("Duck Is Quacking.....");
    }
    
    public String getBeakColor() {
        return BeakColor;
    }

    public void setBeakColor(String beakColor) {
        BeakColor = beakColor;
    }

}
