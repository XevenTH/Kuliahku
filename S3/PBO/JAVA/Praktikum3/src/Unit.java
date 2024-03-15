import Class.Element;
import Class.Skill;
import Class.Weapon;

public class Unit {
    protected String Name;
    protected int Hp;
    protected int Dmg;
    protected Element Element;
    protected Skill Skill;
    protected Weapon Weapon;
    protected boolean IsKillable;

    protected void Attack(int dmg, Unit target) {
        TakeDamage(dmg);
    }

    protected void TakeDamage(int dmg) {
        this.Hp -= dmg;
    }

    protected void Respawn(String name, int hp, Element element, Skill skill, Weapon weapon) {
        this.Name = name;
        this.Hp = hp;
        this.Element = element;
        this.Skill = skill;
        this.Weapon = weapon;

        switch (Weapon) {
            case Sword:
            this.Dmg = 50;
            break;
            case Bow:
                this.Dmg = 80;
                break;
            case Claw:
                this.Dmg = 40;
                break;
            case Dagger:
                this.Dmg = 30;
                break;
            case Staf:
                this.Dmg = 80;
                break;
            case Katana:
                this.Dmg = 70;
                break;
                case RailGun:
                this.Dmg = 120;
                break;
            case Shield:
            this.Dmg = 10;
            break;
            default:
                break;
        }
    }

    // For NPC
    protected void Respawn(String name, int hp) {
        this.Name = name;
        this.Hp = hp;
    }
}
