//
// Created by musiek on 12/14/20.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "../../header/Menu/Leaderboard.h"

using namespace std;

Leaderboard::Leaderboard(sf::RenderWindow *window, string filename, int *gameStatePtr) {
    //assign fields
    this->window = window;
    this->gameStatePtr = gameStatePtr;
    this->filename = filename;

    //open scores file
    ifstream inputStream;
    inputStream.open(filename, ios::in);

    //open the main font
    if (!textFont.loadFromFile("gbfont.ttf")) {
        std::cout << "Failed to load font:" << "gbfont.ttf" << std::endl;
    }

    //add scores to scores vector
    string line;
    if (inputStream.is_open()) {
        while (getline(inputStream, line)) {
            //Create a new stringstream to parse text file's line to the Score class
            stringstream ss(line);
            string nick;
            int score;
            ss >> nick >> score;
            scores.push_back(new Score(nick, score, &textFont));
        }
    } else {
        cout << "Unable to open file:" << filename << endl;
    }

    inputStream.close();

    sortScores();

    //update scores and their positions on the screen
    for (int i = 0; i < scores.size(); i++) {
        scores[i]->update(50, 50 * (i + 1), i + 1);
    }

}

Leaderboard::~Leaderboard() {
    for (Score* single : scores)
        delete single;
}

void Leaderboard::sortScores() {
    //sort scores using stl's sort and a lambda expression
    sort(scores.begin(), scores.end(), [](Score* first, Score* second) {
        return first->getScore() < second->getScore();
    });
}
