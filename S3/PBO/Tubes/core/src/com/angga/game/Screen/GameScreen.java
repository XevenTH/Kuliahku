package com.angga.game.Screen;

import com.angga.game.SpeedRunTubes;
import com.angga.game.Scenes.Hud;
import com.angga.game.Sprites.Enemy;
import com.angga.game.Sprites.Player;
import com.angga.game.Sprites.Enemies.Plant;
import com.angga.game.Tools.B2WorldCreator;
import com.angga.game.Tools.WorldContactListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.maps.tiled.TiledMap;
import com.badlogic.gdx.maps.tiled.TmxMapLoader;
import com.badlogic.gdx.maps.tiled.renderers.OrthogonalTiledMapRenderer;
import com.badlogic.gdx.math.MathUtils;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.Box2DDebugRenderer;
import com.badlogic.gdx.physics.box2d.World;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.badlogic.gdx.utils.viewport.Viewport;

public class GameScreen implements Screen {
    SpeedRunTubes Game;
    TextureAtlas PlayerAtlasPkg;
    TextureAtlas PlantAtlasPkg;

    OrthographicCamera GameCam;
    Viewport ViewPort;
    B2WorldCreator WorldCreator;
    Hud Hud;

    TmxMapLoader MapLoader;
    TiledMap Map;
    OrthogonalTiledMapRenderer Renderer;

    World World;
    Box2DDebugRenderer B2dr;

    Player Player;
    Plant Plant;

    public GameScreen(SpeedRunTubes game) {
        this.Game = game;
        PlayerAtlasPkg = new TextureAtlas("EnchantressPkg/EnchentressPkg.atlas");
        PlantAtlasPkg = new TextureAtlas("PlantPkg/PlantPkg.pack");

        GameCam = new OrthographicCamera();
        GameCam.position.x = 4;
        ViewPort = new FitViewport(SpeedRunTubes.VIRUTAL_WIDTH / SpeedRunTubes.PPM,
                SpeedRunTubes.VIRTUAL_HEIGHT / SpeedRunTubes.PPM, GameCam);
        Hud = new Hud(Game.Batch);

        MapLoader = new TmxMapLoader();
        Map = MapLoader.load("arena.tmx");
        Renderer = new OrthogonalTiledMapRenderer(Map, 1 / SpeedRunTubes.PPM);

        GameCam.position.set(ViewPort.getWorldWidth() / 2, ViewPort.getWorldHeight() / 2, 0);

        World = new World(new Vector2(0, -9.8f), true);
        B2dr = new Box2DDebugRenderer();

        this.WorldCreator = new B2WorldCreator(this);

        Player = new Player(this);

        World.setContactListener(new WorldContactListener());
    }

    @Override
    public void show() {
    }

    public void HandleInput(float dt) {
        if (Player.CurrentState != com.angga.game.Sprites.Player.State.DEAD) {
            if (Gdx.input.isKeyJustPressed(Input.Keys.UP)) {
                Player.Body2.applyLinearImpulse(new Vector2(0, 4f), Player.Body2.getWorldCenter(), true);
            }

            if (Gdx.input.isKeyPressed(Input.Keys.RIGHT) && Player.Body2.getLinearVelocity().x <= 2) {
                Player.Body2.applyLinearImpulse(new Vector2(0.1f, 0), Player.Body2.getWorldCenter(), true);
            }

            if (Gdx.input.isKeyPressed(Input.Keys.LEFT) && Player.Body2.getLinearVelocity().x >= -2) {
                Player.Body2.applyLinearImpulse(new Vector2(-0.1f, 0), Player.Body2.getWorldCenter(), true);
            }
        }
    }

    public void update(float dt) {
        Player.Update(dt);

        World.step(1 / 60f, 6, 2);

        for (Enemy enemy : WorldCreator.getPlants()) {
            enemy.update(dt);
        }
        Hud.Update(dt);

        HandleInput(dt);

        if (Player.CurrentState != com.angga.game.Sprites.Player.State.DEAD) {
            GameCam.position.x = MathUtils.clamp(Player.Body2.getPosition().x, 4, 12);
        }

        GameCam.update();
        Renderer.setView(GameCam);
    }

    @Override
    public void render(float delta) {
        update(delta);

        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

        Renderer.render();

        B2dr.render(World, GameCam.combined);

        Game.Batch.setProjectionMatrix(GameCam.combined);
        Game.Batch.begin();
        Player.draw(Game.Batch);
        for (Enemy enemy : WorldCreator.getPlants()) {
            enemy.draw(Game.Batch);
        }
        Game.Batch.end();

        Game.Batch.setProjectionMatrix(Hud.Stage.getCamera().combined);
        Hud.Stage.draw();

        if (CheckGameOver()) {
            Game.setScreen(new GameOverScreen(Game));
            dispose();
        }
    }

    public TiledMap GetMap() {
        return Map;
    }

    public World GetWorld() {
        return World;
    }

    @Override
    public void resize(int width, int height) {
        ViewPort.update(width, height);
    }

    @Override
    public void pause() {
    }

    @Override
    public void resume() {
    }

    @Override
    public void hide() {
    }

    @Override
    public void dispose() {
        Map.dispose();
        World.dispose();
        B2dr.dispose();
        Renderer.dispose();
        Hud.dispose();
    }

    public boolean CheckGameOver() {
        if (Player.CurrentState == com.angga.game.Sprites.Player.State.DEAD && Player.GetStateTimer() > 3) {
            return true;
        }

        return false;
    }

    public TextureAtlas GetPlayerAtlasPkg() {
        return PlayerAtlasPkg;
    }

    public TextureAtlas GetPlantAtlasPkg() {
        return PlantAtlasPkg;
    }
}
