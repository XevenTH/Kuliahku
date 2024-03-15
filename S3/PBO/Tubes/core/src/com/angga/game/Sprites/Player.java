package com.angga.game.Sprites;

import com.angga.game.SpeedRunTubes;
import com.angga.game.Screen.GameScreen;
import com.badlogic.gdx.graphics.g2d.Animation;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.physics.box2d.Body;
import com.badlogic.gdx.physics.box2d.BodyDef;
import com.badlogic.gdx.physics.box2d.CircleShape;
import com.badlogic.gdx.physics.box2d.Filter;
import com.badlogic.gdx.physics.box2d.Fixture;
import com.badlogic.gdx.physics.box2d.FixtureDef;
import com.badlogic.gdx.physics.box2d.World;
import com.badlogic.gdx.utils.Array;

public class Player extends Sprite {
    float CommonStateTimer;
    float IdleStateTimer;

    // Common Variable for player to world
    public World World;
    public Body Body2;

    // Collision Control Variable Player
    boolean IsAttacking = false;

    // Animation Variables
    public enum State {
        FALLING,
        JUMPING,
        IDLE,
        ATTACKING,
        RUNNING,
        DEAD
    }

    public State CurrentState;
    public State PrevState;
    boolean RunningRigth;
    boolean IsPlayerDead;

    // Animation Handler
    Animation<TextureRegion> PlayerRun;
    Animation<TextureRegion> PlayerJump;
    Animation<TextureRegion> PlayerAttack;
    Animation<TextureRegion> PlayerDead;
    Animation<TextureRegion> PlayerIdle;

    public Player(GameScreen screen) {
        super(screen.GetPlayerAtlasPkg().findRegion("Idle"));
        this.World = screen.GetWorld();

        CurrentState = State.IDLE;
        PrevState = State.IDLE;
        CommonStateTimer = 0;
        IdleStateTimer = 0;
        RunningRigth = true;
        IsPlayerDead = false;

        Array<TextureRegion> frames = new Array<TextureRegion>();
        // Run Animation
        for (int i = 0; i < 4; i++) {
            frames.add(new TextureRegion(getTexture(), i * 128, 521, 128, 128));
        }
        PlayerRun = new Animation<TextureRegion>(0.1f, frames);
        frames.clear();

        // Jump Animation
        for (int i = 0; i < 8; i++) {
            frames.add(new TextureRegion(getTexture(), i * 128, 651, 128, 128));
        }
        PlayerJump = new Animation<TextureRegion>(0.1f, frames);
        frames.clear();

        // Idle Animation
        for (int i = 8; i < 12; i++) {
            frames.add(new TextureRegion(getTexture(), i * 128, 651, 128, 128));
        }
        PlayerIdle = new Animation<TextureRegion>(0.1f, frames);
        frames.clear();

        // Dead Animation
        for (int i = 10; i < 15; i++) {
            frames.add(new TextureRegion(getTexture(), i * 128, 781, 128, 128));
        }
        PlayerDead = new Animation<TextureRegion>(0.1f, frames);

        DefinePlayer();
        setBounds(0, 0, 64 / SpeedRunTubes.PPM, 64 / SpeedRunTubes.PPM);
    }

    public void Update(float dt) {
        setPosition(Body2.getPosition().x - getWidth() / 2, Body2.getPosition().y - getHeight() / 4.1f);
        setRegion(GetFrame(dt));
    }

    private TextureRegion GetFrame(float dt) {
        CurrentState = GetState(dt);

        TextureRegion region;
        switch (CurrentState) {
            case JUMPING:
                region = PlayerJump.getKeyFrame(CommonStateTimer);
                break;
            case RUNNING:
                region = PlayerRun.getKeyFrame(CommonStateTimer, true);
                break;
            case FALLING:
            case IDLE:
                region = PlayerIdle.getKeyFrame(IdleStateTimer, true);
                break;
            case DEAD:
                region = PlayerDead.getKeyFrame(CommonStateTimer);
                break;
            default:
                region = PlayerIdle.getKeyFrame(IdleStateTimer, true);
                break;
        }

        if ((Body2.getLinearVelocity().x < 0 || !RunningRigth) && !region.isFlipX()) {
            region.flip(true, false);
            RunningRigth = false;
        } else if ((Body2.getLinearVelocity().x > 0 || RunningRigth) && region.isFlipX()) {
            region.flip(true, false);
            RunningRigth = true;
        }

        CommonStateTimer = CurrentState == PrevState ? CommonStateTimer + dt : 0;
        IdleStateTimer = CurrentState == PrevState ? IdleStateTimer + dt * 0.7f : 0;

        PrevState = CurrentState;
        return region;
    }

    private State GetState(float dt) {
        if (Body2.getLinearVelocity().y > 0 || (Body2.getLinearVelocity().y < 0 && PrevState == State.JUMPING)) {
            return State.JUMPING;
        } else if (Body2.getLinearVelocity().y < 0) {
            return State.FALLING;
        } else if (Body2.getLinearVelocity().x != 0) {
            return State.RUNNING;
        } else if (IsAttacking == true) {
            return State.ATTACKING;
        } else if (IsPlayerDead == true) {
            return State.DEAD;
        }

        return State.IDLE;
    }

    public void DefinePlayer() {
        BodyDef bDef = new BodyDef();
        bDef.position.set(200 / SpeedRunTubes.PPM, 200 / SpeedRunTubes.PPM);
        bDef.type = BodyDef.BodyType.DynamicBody;
        Body2 = World.createBody(bDef);

        FixtureDef circleFixtureDef = new FixtureDef();

        // FixtureDef untuk circle
        CircleShape circleShape = new CircleShape();
        circleShape.setRadius(15 / SpeedRunTubes.PPM);
        circleFixtureDef.shape = circleShape;
        circleFixtureDef.filter.categoryBits = SpeedRunTubes.PLAYER_BIT;
        circleFixtureDef.filter.maskBits = SpeedRunTubes.ENEMY_BIT | SpeedRunTubes.GROUND_BIT
                | SpeedRunTubes.ENEMY_HEAD_BIT | SpeedRunTubes.OBJECT_BIT;
        Body2.createFixture(circleFixtureDef).setUserData(this);

        circleShape.dispose();
    }

    public void Hit() {
        IsPlayerDead = true;
        Filter filter = new Filter();
        filter.maskBits = SpeedRunTubes.GROUND_BIT | SpeedRunTubes.OBJECT_BIT;
        for (Fixture fix : Body2.getFixtureList()) {
            fix.setFilterData(filter);
        }
    }

    public boolean GetIsPlayerDead() {
        return IsPlayerDead;
    }

    public float GetStateTimer() {
        return CommonStateTimer;
    }
}
