public class Enemy extends Unit{
    @Override 
    protected void Attack(int dmg, Unit target) {
        if (target instanceof Player) {
            super.Attack(dmg, target);
        }
    }
}
