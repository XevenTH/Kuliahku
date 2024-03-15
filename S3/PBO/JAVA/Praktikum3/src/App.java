import java.util.Scanner;

import javax.lang.model.util.ElementScanner14;
import javax.swing.plaf.synth.SynthStyle;

import Class.Element;
import Class.Skill;
import Class.Weapon;

public class App {
    public static void main(String[] args) {
        Boolean ChoiceEnd = false;
        Scanner scanner = new Scanner(System.in);

        Enemy Org = new Enemy();
        Player XevenTH = new Player();
        Npc Npc = new Npc();

        Org.Respawn("Org", 300, Element.Dark, Skill.ShadowBond, Weapon.Bow);
        XevenTH.Respawn("XevenTH", 600, Element.Lightning, Skill.LightningSpeed, Weapon.RailGun);
        Npc.Respawn("Robert", 100000000);

        while (!ChoiceEnd) {
            System.out.println("Talk To Npc Or Battle With Org : ");
            System.out.println("1. Talk To Npc");
            System.out.println("2. Battle");
            System.out.println("3. Run");
            System.out.print("Choice : ");
            int Choice = scanner.nextInt();
            scanner.nextLine();
            switch (Choice) {
                case 1:
                    Npc.Talk();
                    break;
                case 2:
                    while (Org.Hp >= 0 && XevenTH.Hp >= 0) {
                        System.out.println(String.format("%s Attack %s By %d", XevenTH.Name, Org.Name, XevenTH.Dmg));

                        XevenTH.Attack(XevenTH.Dmg, Org);

                        System.out.println(String.format("%s Attack %s By %d", Org.Name, XevenTH.Name, Org.Dmg));

                        Org.Attack(Org.Dmg, XevenTH);

                        System.out.println();
                        System.out.println(String.format("%s Current Hp : %d", XevenTH.Name, XevenTH.Hp));
                        System.out.println(String.format("%s Current Hp : %d", Org.Name, Org.Hp));
                        System.out.println();
                    }

                    if (Org.Hp > 0) {
                        System.out.println("YOU DIED NOOOBB!!!!");
                        ChoiceEnd = true;
                        continue;
                    } else {
                        System.out.println("You Won Againts Org");
                    }

                    break;
                case 3:
                    ChoiceEnd = true;
                    System.out.println("You Choose To Run....");
                    break;
                default:
                    ChoiceEnd = true;
                    break;
            }
        }
    }
}
