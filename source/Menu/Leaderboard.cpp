//
// Created by musiek on 12/14/20.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "../../header/Menu/Leaderboard.h"

using namespace std;

Leaderboard::Leaderboard(sf::RenderWindow *window, string filename, int *gameStatePtr, int* scorePtr, ResourceManager* resourceManager) {
    //assign fields
    this->window = window;
    this->gameStatePtr = gameStatePtr;
    this->scorePtr = scorePtr;
    this->filename = filename;
    this->resourceManager = resourceManager;

    //initializing window
    window->setSize(sf::Vector2u(800, 800));

    sf::View gameView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(gameView);

    //open the main font
    textFontPtr = this->resourceManager->getFont("gbfont.ttf");

    //init for top text
    leaderboardText.setFont(*textFontPtr);
    leaderboardText.setCharacterSize(32);
    leaderboardText.setString("Leaderboard:");
    leaderboardText.setPosition(window->getSize().x / 2 - leaderboardText.getGlobalBounds().width / 2, 0);

    menuButton = new Button(sf::Vector2f(window->getSize().x/ 2 - 100, window->getSize().y - 100),
                             sf::Vector2f(200, 100),
                             "Menu",
                             this->resourceManager);

    //open scores file
    ifstream inputStream;
    inputStream.open(filename, ios::in);

    //add scores to scores vector
    string line;
    if (inputStream.is_open()) {
        while (getline(inputStream, line)) {
            //Create a new stringstream to parse text file's line to the Score class
            stringstream ss(line);
            string nick;
            long score;
            ss >> nick >> score;
            scores.push_back(new Score(nick, score, textFontPtr));
        }
    } else {
        cout << "Unable to open file:" << filename << endl;
        cout << "Making a new scores.txt file" << endl;
        ofstream outputStream;
        outputStream.open(filename, ios::out);
        outputStream.close();
    }

    inputStream.close();

    sortScores();

    //remove excessing scores
    while (scores.size() > 10)
        scores.pop_back();

    //update scores and their positions on the screen
    for (int i = 0; i < scores.size(); i++) {
        scores[i]->update(window->getSize().x, 50 + 50 * (i + 1), i + 1);
    }

}

Leaderboard::~Leaderboard() {
    for (Score* single : scores)
        delete single;
    delete menuButton;
}

void Leaderboard::sortScores() {
    //sort scores using stl's sort and a lambda expression
    sort(scores.begin(), scores.end(), [](Score* first, Score* second) {
        return first->getScore() > second->getScore();
    });
}

void Leaderboard::run() {

    sf::Sprite background;
    sf::Texture* backgroundText = resourceManager->getTexture("background.png");
    background.setTexture(*backgroundText);
    background.setScale((float)window->getSize().x / backgroundText->getSize().x, (float)window->getSize().y / backgroundText->getSize().y );

    while (window->isOpen()) {

        if (*gameStatePtr != LEADERBOARD)
            break;

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.key.code == sf::Keyboard::Escape)
                *gameStatePtr = MENU;
        }

        sf::Vector2f mouseViewPos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

        if (menuButton->updateButton(mouseViewPos)) {
            *gameStatePtr = MENU;
        }

        window->clear();
        window->draw(background);
        window->draw(leaderboardText);
        window->draw(*menuButton);

        for (Score* single : scores)
            window->draw(*single);

        window->display();
    }
}
