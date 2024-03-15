package com.angga.game.Sprites.InteractiveObject;

import com.badlogic.gdx.physics.box2d.World;
import com.badlogic.gdx.physics.box2d.Body;
import com.angga.game.Screen.GameScreen;
import com.badlogic.gdx.maps.tiled.TiledMap;
import com.badlogic.gdx.maps.tiled.TiledMapTile;
import com.badlogic.gdx.math.Rectangle;

public abstract class InteractiveObject {
    protected World World;
    protected TiledMap Map;
    protected TiledMapTile Tile;
    protected Rectangle RShape;
    protected Body Body;

    public InteractiveObject(GameScreen screen, Rectangle shape) {
        this.World = screen.GetWorld();
        this.Map = screen.GetMap();
        this.RShape = shape;
    }
}
