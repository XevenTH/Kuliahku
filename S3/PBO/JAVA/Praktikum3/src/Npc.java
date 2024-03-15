public class Npc extends Unit {
    @Override
    protected void TakeDamage(int dmg) {
        if (IsKillable) {
            super.TakeDamage(dmg);
        } else {
            System.out.println("Immortal Object");
            return;
        }
    }

    public void Talk() {
        System.out.println("Hello My Friend..");
        System.out.println("You Finally Awake..");
    }
}
