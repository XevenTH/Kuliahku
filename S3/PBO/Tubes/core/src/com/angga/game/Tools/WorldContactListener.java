package com.angga.game.Tools;

import com.angga.game.SpeedRunTubes;
import com.angga.game.Sprites.Enemy;
import com.angga.game.Sprites.Player;
import com.badlogic.gdx.physics.box2d.Contact;
import com.badlogic.gdx.physics.box2d.ContactImpulse;
import com.badlogic.gdx.physics.box2d.ContactListener;
import com.badlogic.gdx.physics.box2d.Fixture;
import com.badlogic.gdx.physics.box2d.Manifold;

public class WorldContactListener implements ContactListener {

    @Override
    public void beginContact(Contact contact) {
        Fixture FixA = contact.getFixtureA();
        Fixture FixB = contact.getFixtureB();

        int cDef = FixA.getFilterData().categoryBits | FixB.getFilterData().categoryBits;

        // Check Enemy Collison
        // if (FixA.getUserData() == "HitBox" || FixB.getUserData() == "HitBox") {
        // Fixture hitBox = FixA.getUserData() == "HitBox" ? FixA : FixB;
        // Fixture object = hitBox == FixA ? FixB : FixA;

        // if (hitBox.isSensor()) {
        // if (object.getUserData() != null &&
        // Enemy.class.isAssignableFrom(object.getUserData().getClass())) {
        // ((Enemy) object.getUserData()).OnHit();
        // }
        // }
        // }

        switch (cDef) {
            case SpeedRunTubes.ENEMY_HEAD_BIT | SpeedRunTubes.PLAYER_BIT:
                if (FixA.getFilterData().categoryBits == SpeedRunTubes.ENEMY_HEAD_BIT) {
                    ((Enemy) FixA.getUserData()).OnHit();
                } else if (FixB.getFilterData().categoryBits == SpeedRunTubes.ENEMY_HEAD_BIT) {
                    ((Enemy) FixB.getUserData()).OnHit();
                }
                break;
            case SpeedRunTubes.ENEMY_BIT | SpeedRunTubes.OBJECT_BIT:
                if (FixA.getFilterData().categoryBits == SpeedRunTubes.ENEMY_BIT) {
                    ((Enemy) FixA.getUserData()).ReverseVeocity(true, false);
                } else {
                    ((Enemy) FixB.getUserData()).ReverseVeocity(true, false);
                }
                break;
            case SpeedRunTubes.PLAYER_BIT | SpeedRunTubes.ENEMY_BIT:
                if (FixA.getFilterData().categoryBits == SpeedRunTubes.PLAYER_BIT) {
                    ((Player) FixA.getUserData()).Hit();
                } else {
                    ((Player) FixB.getUserData()).Hit();
                }
                break;
            case SpeedRunTubes.ENEMY_BIT | SpeedRunTubes.ENEMY_BIT:
                ((Enemy) FixA.getUserData()).ReverseVeocity(true, false);
                ((Enemy) FixB.getUserData()).ReverseVeocity(true, false);
                break;
            default:
                break;
        }
    }

    @Override
    public void endContact(Contact contact) {
    }

    @Override
    public void preSolve(Contact contact, Manifold oldManifold) {
    }

    @Override
    public void postSolve(Contact contact, ContactImpulse impulse) {
    }

}
