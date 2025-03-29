#include <iostream>
#include <string>

using namespace std;

#define MAX_LEVELS 10

class Level
{
private:
    string levelName;
    int difficulty;

public:
    Level() {}
    Level(string name, int diff) : levelName(name), difficulty(diff) {}

    void display() const
    {
        cout << "Level: " << levelName << ", Difficulty: " << difficulty << endl;
    }

    bool isEmpty() const
    {
        return levelName.empty();
    }
};

class VideoGame
{
private:
    string title;
    string genre;
    Level levels[MAX_LEVELS];
    int levelCount;

public:
    VideoGame(string t, string g) : title(t), genre(g), levelCount(0) {}

    void addLevel(const Level &lvl)
    {
        if (levelCount < MAX_LEVELS)
        {
            levels[levelCount] = lvl;
            levelCount++;
        }
        else
        {
            cout << "Maximum level limit reached!" << endl;
        }
    }

    void display() const
    {
        cout << "Game: " << title << ", Genre: " << genre << endl;
        cout << "Levels:" << endl;
        for (int i = 0; i < levelCount; i++)
        {
            levels[i].display();
        }
    }
};

int main()
{

    VideoGame game("Adventure Quest", "RPG");

    game.addLevel(Level("Forest of Doom", 3));
    game.addLevel(Level("Cave of Shadows", 5));
    game.addLevel(Level("Dragon's Lair", 8));

    game.display();

    return 0;
}
