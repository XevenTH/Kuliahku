package com.angga.game.Sprites;

import com.angga.game.Screen.GameScreen;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.Body;
import com.badlogic.gdx.physics.box2d.World;

public abstract class Enemy extends Sprite {
    protected World World;
    protected GameScreen Screen;
    public Body Body2;
    public Vector2 Velocity;

    public Enemy(GameScreen screen, float x, float y) {
        super(screen.GetPlantAtlasPkg().findRegion("Idle"));
        this.World = screen.GetWorld();
        this.Screen = screen;
        setPosition(x, y);
        DefineEnemy();
        Velocity = new Vector2(0.7f, 0);
    }

    protected abstract void DefineEnemy();

    public abstract void OnHit();
    public abstract void update(float dt);

    public void ReverseVeocity(boolean x, boolean y) {
        if (x)
            Velocity.x = -Velocity.x;
        if (y)
            Velocity.y = -Velocity.y;
    }
}
