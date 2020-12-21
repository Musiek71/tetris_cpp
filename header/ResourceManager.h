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

/**
 * Class representing the main resource manager.
 *
 * Allows to load just one piece of every resource to the program's memory, which can be later shared among every
 * SFML object, for example buttons sharing the same texture.
 */
class ResourceManager {
private:
    /// Map containing all SFML textures (pointers).
    map<string, sf::Texture*> textureMap;

    /// Map containing all SFML fonts (pointers).
    map<string, sf::Font*> fontMap;

    /// Map containing all SFML sound buffers (pointers).
    map<string, sf::SoundBuffer*> soundBufferMap;

    /// Map containing all SFML music resources (pointers).
    map<string, sf::Music*> musicMap;

    /// Adds a single texture to textures map.
    bool addTexture(string filename);

    /// Adds a single font to the font map.
    bool addFont(string filename);

    /// Adds a single sound buffer to the sound buffer map.
    bool addSoundBuffer(string filename);

    /// Adds a single music resource to the music resources map.
    bool addMusic(string filename);

public:
    /// Main constructor adding all the resources.
    ResourceManager();

    /// Destructor freeing the allocated memody.
    virtual ~ResourceManager();

    /// Get certain texture pointer.
    sf::Texture* getTexture(string filename);

    /// Get certain font pointer.
    sf::Font* getFont(string filename);

    /// Get certain sound buffer pointer.
    sf::SoundBuffer* getSoundBuffer(string filename);

    /// Get certain music pointer.
    sf::Music* getMusic(string filename);

};


#endif //TETRIS_CPP_RESOURCEMANAGER_H
