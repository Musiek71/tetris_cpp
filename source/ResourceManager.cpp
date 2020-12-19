//
// Created by musiek on 12/19/20.
//

#include <iostream>
#include "../header/ResourceManager.h"

ResourceManager::ResourceManager() {
    //add textures
    addTexture("tileset.png");
    addTexture("background.png");
    addTexture("button_pressed.png");
    addTexture("button_released.png");
    addTexture("next_field.png");
    addTexture("score_field.png");

    //add font
    addFont("gbfont.ttf");

    //add sounds
    addSoundBuffer("fall.wav");
    addSoundBuffer("clear.wav");

    //add music
    addMusic("tetris.ogg");
}

ResourceManager::~ResourceManager() {
    //deleting all textures
    for (auto const& tex : textureMap) {
        delete tex.second;
    }

    //deleting all fonts
    for (auto const& font : fontMap) {
        delete font.second;
    }

    //deleting all SoundBuffers
    for (auto const& sB : soundBufferMap) {
        delete sB.second;
    }

    //deleting all music
    for (auto const& music : musicMap) {
        delete music.second;
    }
}

bool ResourceManager::addTexture(string filename) {
    textureMap[filename] = new sf::Texture;
    if (!textureMap[filename]->loadFromFile(filename)) {
        cout << "Failed to load texture:" << filename << endl;
        return false;
    }
    return true;
}

bool ResourceManager::addFont(string filename) {
    fontMap[filename] = new sf::Font;
    if (!fontMap[filename]->loadFromFile(filename)) {
        cout << "Failed to load font:" << filename << endl;
        return false;
    }
    return true;
}

bool ResourceManager::addSoundBuffer(string filename) {
    soundBufferMap[filename] = new sf::SoundBuffer;
    if (!soundBufferMap[filename]->loadFromFile(filename)) {
        cout << "Failed to load sound:" << filename << endl;
        return false;
    }
    return true;
}

bool ResourceManager::addMusic(string filename) {
    musicMap[filename] = new sf::Music;
    if (!musicMap[filename]->openFromFile(filename)) {
        cout << "Failed to load music:" << filename << endl;
        return false;
    }
    return true;
}

sf::Texture *ResourceManager::getTexture(string filename) {
    return textureMap[filename];
}

sf::Font *ResourceManager::getFont(string filename) {
    return fontMap[filename];
}

sf::SoundBuffer *ResourceManager::getSoundBuffer(string filename) {
    return soundBufferMap[filename];
}

sf::Music *ResourceManager::getMusic(string filename) {
    return musicMap[filename];
}
