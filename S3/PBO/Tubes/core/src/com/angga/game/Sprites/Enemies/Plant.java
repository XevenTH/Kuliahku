package com.angga.game.Sprites.Enemies;

import com.angga.game.SpeedRunTubes;
import com.angga.game.Scenes.Hud;
import com.angga.game.Screen.GameScreen;
import com.angga.game.Sprites.Enemy;
import com.badlogic.gdx.graphics.g2d.Animation;
import com.badlogic.gdx.graphics.g2d.Batch;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.BodyDef;
import com.badlogic.gdx.physics.box2d.CircleShape;
import com.badlogic.gdx.physics.box2d.FixtureDef;
import com.badlogic.gdx.physics.box2d.PolygonShape;
import com.badlogic.gdx.utils.Array;

public class Plant extends Enemy {
    GameScreen screen;
    Array<TextureRegion> frames;
    Animation<TextureRegion> IdleAnimation;
    Animation<TextureRegion> DeadAnimation;
    Animation<TextureRegion> WalkAnimation;
    float StateTime;
    boolean SetToDestroy;
    boolean Destroy;

    public Plant(GameScreen screen, float x, float y) {
        super(screen, x, y);

        this.screen = screen;

        StateTime = 0;
        SetToDestroy = false;
        Destroy = false;

        // Idle Animation
        frames = new Array<TextureRegion>();
        for (int i = 9; i < 14; i++) {
            frames.add(new TextureRegion(getTexture(), i * 128, 521, 128, 128));
        }
        IdleAnimation = new Animation<TextureRegion>(0.25f, frames);
        frames.clear();
        
        // Dead
        for (int i = 8; i < 10; i++) {
            frames.add(new TextureRegion(getTexture(), i * 128, 391, 128, 128));
        }
        DeadAnimation = new Animation<TextureRegion>(0.25f, frames);
        frames.clear();

        // Walk
        for (int i = 0; i < 8; i++) {
            frames.add(new TextureRegion(getTexture(), i * 128, 521, 128, 128));
        }
        WalkAnimation = new Animation<TextureRegion>(0.25f, frames);

        setBounds(getX(), getY(), 64 / SpeedRunTubes.PPM, 64 / SpeedRunTubes.PPM);
    }

    public void draw(Batch batch) {
        if (!Destroy || StateTime <= 2) {
            super.draw(batch);
        }
    }

    @Override
    protected void DefineEnemy() {
        BodyDef bDef = new BodyDef();
        bDef.position.set(getX(), getY());
        bDef.type = BodyDef.BodyType.DynamicBody;
        Body2 = World.createBody(bDef);

        // Body
        FixtureDef bodyFixtureDef = new FixtureDef();

        CircleShape shape = new CircleShape();
        shape.setRadius(15 / SpeedRunTubes.PPM);
        bodyFixtureDef.shape = shape;
        bodyFixtureDef.filter.categoryBits = SpeedRunTubes.ENEMY_BIT;
        bodyFixtureDef.filter.maskBits = SpeedRunTubes.PLAYER_BIT | SpeedRunTubes.GROUND_BIT | SpeedRunTubes.OBJECT_BIT | SpeedRunTubes.ENEMY_BIT;
        Body2.createFixture(bodyFixtureDef).setUserData(this);

        // Head
        FixtureDef headFixtureDef = new FixtureDef();

        PolygonShape head = new PolygonShape();
        Vector2[] vertice = new Vector2[4];
        vertice[0] = new Vector2(-12, 17).scl(1 / SpeedRunTubes.PPM);
        vertice[1] = new Vector2(12, 17).scl(1 / SpeedRunTubes.PPM);
        vertice[2] = new Vector2(-12, 13).scl(1 / SpeedRunTubes.PPM);
        vertice[3] = new Vector2(12, 13).scl(1 / SpeedRunTubes.PPM);
        head.set(vertice);

        headFixtureDef.shape = head;
        headFixtureDef.restitution = 0.5f;
        headFixtureDef.filter.categoryBits = SpeedRunTubes.ENEMY_HEAD_BIT;

        Body2.createFixture(headFixtureDef).setUserData(this);

    }

    @Override
    public void OnHit() {
        SetToDestroy = true;
        Hud.AddScore(200);
    }

    @Override
    public void update(float dt) {
        StateTime += dt;
        if (SetToDestroy && !Destroy) {
            World.destroyBody(Body2);
            Destroy = true;
            setRegion(DeadAnimation.getKeyFrame(StateTime));
            StateTime = 0;
        } else if (!Destroy) {
            Body2.setLinearVelocity(Velocity);
            setPosition(Body2.getPosition().x - getWidth() / 2, Body2.getPosition().y - getHeight() / 4);
            setRegion(IdleAnimation.getKeyFrame(StateTime, true));
        }
    }

}
