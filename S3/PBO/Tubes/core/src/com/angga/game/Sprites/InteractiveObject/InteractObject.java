package com.angga.game.Sprites.InteractiveObject;

import com.angga.game.SpeedRunTubes;
import com.angga.game.Screen.GameScreen;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.physics.box2d.BodyDef;
import com.badlogic.gdx.physics.box2d.FixtureDef;
import com.badlogic.gdx.physics.box2d.PolygonShape;

public class InteractObject extends InteractiveObject {

    public InteractObject(GameScreen screen, Rectangle shape) {
        super(screen, shape);

        BodyDef Bdef = new BodyDef();
        FixtureDef FDef = new FixtureDef();
        PolygonShape Polygon = new PolygonShape();

        Bdef.type = BodyDef.BodyType.StaticBody;
        Bdef.position.set((RShape.getX() + RShape.getWidth() / 2) / SpeedRunTubes.PPM,
                (RShape.getY() + RShape.getHeight() / 2) / SpeedRunTubes.PPM);
        FDef.filter.categoryBits = SpeedRunTubes.OBJECT_BIT;
        FDef.filter.maskBits = SpeedRunTubes.ENEMY_BIT | SpeedRunTubes.PLAYER_BIT;

        Body = World.createBody(Bdef);

        Polygon.setAsBox(RShape.getWidth() / 2 / SpeedRunTubes.PPM, RShape.getHeight() / 2 / SpeedRunTubes.PPM);
        FDef.shape = Polygon;
        Body.createFixture(FDef).setUserData(this);
    }
    
}
