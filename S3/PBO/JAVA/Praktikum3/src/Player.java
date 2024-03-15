public class Player extends Unit {
    @Override
    protected void Attack(int dmg, Unit target) {
        if (target instanceof Enemy) {
            super.Attack(dmg, target);
        }
    }
}
