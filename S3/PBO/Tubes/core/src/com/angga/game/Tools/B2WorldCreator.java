package com.angga.game.Tools;

import com.angga.game.SpeedRunTubes;
import com.angga.game.Screen.GameScreen;
import com.angga.game.Sprites.Enemies.Plant;
import com.angga.game.Sprites.InteractiveObject.Ground;
import com.angga.game.Sprites.InteractiveObject.InteractObject;
import com.badlogic.gdx.maps.MapObject;
import com.badlogic.gdx.maps.objects.RectangleMapObject;
import com.badlogic.gdx.maps.tiled.TiledMap;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.utils.Array;

public class B2WorldCreator {
    Array<Plant> plants;

    public B2WorldCreator(GameScreen screen) {
        TiledMap tiledMap = screen.GetMap();

        for (MapObject object : tiledMap.getLayers().get(4).getObjects().getByType(RectangleMapObject.class)) {
            Rectangle shape = ((RectangleMapObject) object).getRectangle();

            new Ground(screen, shape);
        }

        for (MapObject object : tiledMap.getLayers().get(5).getObjects().getByType(RectangleMapObject.class)) {
            Rectangle shape = ((RectangleMapObject) object).getRectangle();

            new InteractObject(screen, shape);
        }

        plants = new Array<Plant>();
        for (MapObject object : tiledMap.getLayers().get(6).getObjects().getByType(RectangleMapObject.class)) {
            Rectangle shape = ((RectangleMapObject) object).getRectangle();

            plants.add(new Plant(screen, shape.getX() / SpeedRunTubes.PPM, shape.getY() / SpeedRunTubes.PPM));
        }
    }

    public Array<Plant> getPlants() {
        return plants;
    }
}
