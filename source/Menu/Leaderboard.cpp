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

    //add scores to scores vector
    string line;
    if (inputStream.is_open()) {
        while (getline(inputStream, line)) {
            //Create a new stringstream to parse text file's line to the Score class
            stringstream ss(line);
            string nick;
            int score;
            ss >> nick >> score;
            scores.push_back(new Score(nick, score));
        }
    } else {
        cout << "Unable to open file:" << filename << endl;
    }

    inputStream.close();

    sortScores();

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
