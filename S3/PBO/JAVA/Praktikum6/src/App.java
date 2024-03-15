import java.util.ArrayList;
import java.util.List;

import Classes.Animal;
import Classes.Fish;
import Classes.Zebra;
import Classes.Duck;

import Interfaces.ISwim;

public class App {
    public static void main(String[] args) throws Exception {
        List<Animal> animals = new ArrayList<Animal>();

        Zebra zebra = new Zebra();
        Fish fish = new Fish();
        Duck duck = new Duck();

        animals.add((Animal)zebra);
        animals.add((Animal)fish);
        animals.add((Animal)duck);

        for (Animal animal : animals) {
            System.out.println("\n");

            if (animal instanceof Zebra) {
                Zebra tempAnimal = (Zebra)animal;
                
                tempAnimal.Run();
                tempAnimal.Mate("Beranak");
            }
            else if (animal instanceof Duck) {
                Duck tempAnimal = (Duck)animal;

                if (tempAnimal instanceof ISwim) {
                    tempAnimal.Swim();
                }
                tempAnimal.Quack();
                tempAnimal.Mate("Bertelur");
            }
            else if (animal instanceof Fish) {
                Fish tempAnimal = (Fish)animal;

                if (tempAnimal instanceof ISwim) {
                    tempAnimal.Swim();
                }
                tempAnimal.Mate("Bertelur");
            }
        }

        System.out.println("\n");
    }
}
