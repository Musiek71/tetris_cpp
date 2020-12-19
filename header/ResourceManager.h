//
// Created by musiek on 12/19/20.
//

#ifndef TETRIS_CPP_RESOURCEMANAGER_H
#define TETRIS_CPP_RESOURCEMANAGER_H

#include <string>
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

using namespace std;

class ResourceManager {
private:
    map<string, sf::Texture*> textureMap;
    map<string, sf::Font*> fontMap;
    map<string, sf::SoundBuffer*> soundBufferMap;
    map<string, sf::Music*> musicMap;

    bool addTexture(string filename);
    bool addFont(string filename);
    bool addSoundBuffer(string filename);
    bool addMusic(string filename);

public:
    ResourceManager();
    virtual ~ResourceManager();

    sf::Texture* getTexture(string filename);
    sf::Font* getFont(string filename);
    sf::SoundBuffer* getSoundBuffer(string filename);
    sf::Music* getMusic(string filename);

};


#endif //TETRIS_CPP_RESOURCEMANAGER_H
