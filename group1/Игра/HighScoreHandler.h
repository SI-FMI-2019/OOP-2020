//
// Created by lyubo on 9.04.20 г..
//

#ifndef CPP_GAME_HIGHSCOREHANDLER_H
#define CPP_GAME_HIGHSCOREHANDLER_H

#include <fstream>
#include <cstring>

class HighScoreHolder
{
public:
    HighScoreHolder() = default;
    HighScoreHolder(const unsigned& score, const char* name): score(score)
    {
        int size = strlen(name);

        this->name = new char[size + 1];
        strcpy(this->name, name);

        this->name[size] = '\0';
    }

    HighScoreHolder(const HighScoreHolder& from): score(from.score)
    {
        int size = strlen(from.name);

        this->name = new char[size + 1];
        strcpy(this->name, from.name);

        this->name[size] = '\0';
    }

    HighScoreHolder& operator=(const HighScoreHolder& from)
    {
        if(this != &from)
        {
            this->score = from.score;

            delete[] this->name;
            int size = strlen(from.name);

            this->name = new char[size + 1];
            strcpy(this->name, from.name);

            this->name[size] = '\0';
        }
        return *this;
    }

    ~HighScoreHolder()
    {
        delete[] this->name;
    }

    unsigned get_score() const
    {
        return this->score;
    }

    friend std::ostream& operator<<(std::ostream& out, const HighScoreHolder& instance);
private:
    unsigned score;
    char* name;
};

std::ostream& operator<<(std::ostream& out, const HighScoreHolder& instance)
{
    out << instance.name << " - " << instance.score;
    return out;
}

class HighScoreHandler {
private:



    const char* filename = "highscores.txt"; //Този текст не е в динамичната памет. Той е в СТАТИЧНАТА памет (static code segment)
public:
    HighScoreHandler();
    void write_high_score(const unsigned& score, const char* name);
};


#endif //CPP_GAME_HIGHSCOREHANDLER_H
