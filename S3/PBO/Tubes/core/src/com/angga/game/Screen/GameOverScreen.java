package com.angga.game.Screen;

import com.angga.game.SpeedRunTubes;
import com.angga.game.Tools.SaveLoadService;
import com.badlogic.gdx.Game;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.badlogic.gdx.utils.viewport.Viewport;

public class GameOverScreen implements Screen {
    Viewport ViewPort;
    Stage Stage;

    Game Game;
    Integer HighScore;
    

    public GameOverScreen(Game game) {
        this.Game = game;

        ViewPort = new FitViewport(SpeedRunTubes.VIRUTAL_WIDTH, SpeedRunTubes.VIRTUAL_HEIGHT, new OrthographicCamera());
        Stage = new Stage(ViewPort, ((SpeedRunTubes) Game).Batch);

        HighScore = SaveLoadService.GetHighScore();

        Label.LabelStyle font = new Label.LabelStyle(new BitmapFont(), Color.WHITE);

        Table table = new Table();
        table.center();
        table.setFillParent(true);

        Label GameOverLabel = new Label("Game Over", font);
        Label PlayAgainLabel = new Label("Click Anywhere To PlayAgain", font);
        Label HighScoreLabel = new Label("HighScore: " + HighScore, font);

        table.add(GameOverLabel).expandX();
        table.row();
        table.add(PlayAgainLabel).expandX().padTop(10f);
        table.row();
        table.add(HighScoreLabel).expandX().padTop(30f);
        
        Stage.addActor(table);
    }

    @Override
    public void show() {
    }

    @Override
    public void render(float delta) {
        if (Gdx.input.justTouched()) {
            Game.setScreen(new GameScreen((SpeedRunTubes) Game));
            dispose();
        }

        Gdx.gl.glClearColor(0, 0,0,1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
        Stage.draw();
    }

    @Override
    public void resize(int width, int height) {
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
        Stage.dispose();
    }
    
}
