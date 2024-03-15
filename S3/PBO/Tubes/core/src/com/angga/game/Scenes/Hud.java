package com.angga.game.Scenes;

import com.angga.game.SpeedRunTubes;
import com.angga.game.Tools.SaveLoadService;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.utils.Disposable;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.badlogic.gdx.utils.viewport.Viewport;

public class Hud implements Disposable {
    public Stage Stage;
    private Viewport ViewPort;

    private Integer worldTimer;
    private float TimeCount;
    private static Integer Score;

    private Label CountdownLabel;
    private static Label ScoreLabel;
    private Label TimeLabel;
    private Label LevelLabel;
    private Label WorldLabel;
    private Label PlayerLabel;

    public Hud(SpriteBatch spriteBatch) {
        worldTimer = 300;
        TimeCount = 0;
        Score = 0;

        ViewPort = new FitViewport(SpeedRunTubes.VIRUTAL_WIDTH, SpeedRunTubes.VIRTUAL_HEIGHT, new OrthographicCamera());
        Stage = new Stage(ViewPort, spriteBatch);

        Table Table = new Table();
        Table.top();
        Table.setFillParent(true);

        Label.LabelStyle LabelStyle = new Label.LabelStyle();
        LabelStyle.font = new BitmapFont();
        LabelStyle.fontColor = Color.WHITE;
        LabelStyle.font.getData().setScale(1.2f);

        CountdownLabel = new Label(String.format("%03d", worldTimer), LabelStyle);
        ScoreLabel = new Label(String.format("%01d", Score), LabelStyle);
        TimeLabel = new Label(String.format("TIME: %.2f", TimeCount), LabelStyle);
        LevelLabel = new Label("1-1", LabelStyle);
        WorldLabel = new Label("World", LabelStyle);
        PlayerLabel = new Label("Player", LabelStyle);

        Table.add(PlayerLabel).expandX().padTop(10);
        Table.add(WorldLabel).expandX().padTop(10);
        Table.add(TimeLabel).expandX().padTop(10);
        Table.row();
        Table.add(ScoreLabel).expandX();
        Table.add(LevelLabel).expandX();
        Table.add(CountdownLabel).expandX();

        Stage.addActor(Table);

        Table.setDebug(true);
    }

    public void Update(float dt) {
        TimeCount += dt;
        if (TimeCount >= 1) {
            worldTimer--;
            CountdownLabel.setText(String.format("%03d", worldTimer));
            TimeCount = 0;
        }
    }

    public static void AddScore(int value) {
        Score += value;
        ScoreLabel.setText(String.format("%03d", Score));

        if (Score > SaveLoadService.GetHighScore()) {
            SaveLoadService.SetHighScore(Score);
        }
    }

    @Override
    public void dispose() {
        Stage.dispose();
    }
}
