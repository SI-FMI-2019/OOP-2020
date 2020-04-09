//
// Created by lyubo on 9.04.20 г..
//

#include "HighScoreHandler.h"

HighScoreHandler::HighScoreHandler()
{
    std::ofstream try_to_open;
    try_to_open.open(HighScoreHandler::filename, std::ios::out | std::ios::app);
    try_to_open.close();
}

void HighScoreHandler::write_high_score(const unsigned int &score, const char *name) {
    std::ofstream high_score_writer;
    high_score_writer.open(HighScoreHandler::filename, std::ios::out | std::ios::app);

    high_score_writer << name << " - " << score << "\n";

    high_score_writer.close();
}