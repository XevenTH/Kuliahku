package com.angga.game.Tools;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Preferences;

public class SaveLoadService {
    public static Preferences SaveFile = Gdx.app.getPreferences("MyGame");

    public static void SetHighScore(int value) {
        SaveFile.putInteger("highscore", value);
        SaveFile.flush();
    }

    public static Integer GetHighScore() {
        return SaveFile.getInteger("highscore");
    }
}
