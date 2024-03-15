package com.angga.game;

import com.angga.game.Screen.GameScreen;
import com.badlogic.gdx.Game;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class SpeedRunTubes extends Game {
	public static final int VIRUTAL_WIDTH = 800;
	public static final int VIRTUAL_HEIGHT = 480;
	public static final float PPM = 100;

	public static final short GROUND_BIT = 1;
	public static final short PLAYER_BIT = 2;
	public static final short ENEMY_BIT = 4;
	public static final short KILLED_ENEMY_BIT = 8;
	public static final short ENEMY_HEAD_BIT = 16;
	public static final short OBJECT_BIT = 32;
	public static final short NOTHING_BIT = 64;

	public SpriteBatch Batch;

	@Override
	public void create () {
		Batch = new SpriteBatch();
		setScreen(new GameScreen(this));
	}

	@Override
	public void render () {
		super.render();
	}
	
	@Override
	public void dispose () {

	}
}
