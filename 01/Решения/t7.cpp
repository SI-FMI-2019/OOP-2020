#include <iostream>
#include <stdio.h>
#include <string.h>

enum Category
{
    ACTION,
    COMEDY,
    THRILLER,
    CRIME,
    HORROR
};

struct Movie
{
    char name[30];
    int length;
    Category category;
};

void sort(Movie* movies, int movieCount)
{
    for (int i = 0; i < movieCount; i++)
    {
        for (int j = i + 1; j < movieCount; j++)
        {
            if (strcmp(movies[i].name, movies[j].name) > 0)
            {
                char temp[30];
                strcpy(temp, movies[i].name);
                strcpy(movies[i].name, movies[j].name);
                strcpy(movies[j].name, temp);

                int tempLength = movies[i].length;
                movies[i].length = movies[j].length;
                movies[j].length = tempLength;

                Category tempCategory = movies[i].category;
                movies[i].category = movies[j].category;
                movies[j].category = tempCategory;
            }
        }
    }
}

void print(Movie* movies, const int movieCount)
{
    for (int i = 0; i < movieCount; i++)
    {
        std::cout << movies[i].name << std::endl;
        std::cout << movies[i].length << std::endl;
        std::cout << movies[i].category << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int moviesCount = 0;
    std::cout << "Enter movies count: ";
    std::cin >> moviesCount;

    Movie* movies = new Movie [moviesCount];


    for (int i = 0; i < moviesCount; i++)
    {
        std::cout << "Movie #" << i + 1 << " name: ";
        std::cin >> movies[i].name;
        std::cout << "Movie #" << i + 1 << " length: ";
        std::cin >> movies[i].length;
        std::cout << "Movie #" << i + 1 << " category: " << std::endl;
        std::cout << "1) Action" << std::endl;
        std::cout << "2) Comedy" << std::endl;
        std::cout << "3) Thriller" << std::endl;
        std::cout << "4) Crime" << std::endl;
        std::cout << "5) Horror" << std::endl;
        int category = 0;
        std::cin >> category;
        movies[i].category = (Category) (category - 1);
    }

    sort(movies, moviesCount);
    print(movies, moviesCount);

    delete[] movies;

    return 0;
}