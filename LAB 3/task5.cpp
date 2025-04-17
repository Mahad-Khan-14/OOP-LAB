#include <iostream>
#include <string>
using namespace std;

class MusicPlayer
{
private:
    string *playlist;
    string CurrentSong;
    int capacity;
    int totalsongs = 0;

public:
    MusicPlayer(int size)
    {
        capacity = size;
        playlist = new string[capacity];
    }

    ~MusicPlayer()
    {
        delete[] playlist;
    }

    void Addsongs(const string &song)
    {
        if (totalsongs < capacity)
        {
            playlist[totalsongs++] = song;
            cout << "(" << song << ") added" << endl;
        }
        else
        {
            cout << "Playlist is full. Cannot add more Songs.\n";
        }
    }

    void Removesong(const string &song)
    {
        bool found = false;
        for (int i = 0; i < totalsongs; i++)
        {
            if (playlist[i] == song)
            {
                for (int j = i; j < totalsongs - 1; j++)
                {
                    playlist[j] = playlist[j + 1];
                }
                totalsongs--;
                cout << "Song " << song << " Removed" << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Song " << song << " not available to remove" << endl;
        }
    }

    void Playsong(const string &song)
    {
        bool found = false;
        for (int i = 0; i < totalsongs; i++)
        {
            if (playlist[i] == song)
            {

                cout << "Song (" << song << ") Playing" << endl;
                CurrentSong = song;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Song " << song << " not available to play" << endl;
        }
    }

    void displayPlaylist() const
    {
        cout << "The Playlist includes: " << endl;
        for (int i = 0; i < totalsongs; i++)
        {
            cout << i + 1 << " - " << playlist[i] << endl;
        }
    }

    void showCurrentSong()
    {
        if (CurrentSong != "")
        {
            cout << "Currently playing: " << CurrentSong << endl;
        }
        else
        {
            cout << "No song is currently playing." << endl;
        }
    }
};

int main()
{
    MusicPlayer atifAslam(5);
    atifAslam.Addsongs("Jeena Jeena");
    atifAslam.Addsongs("Aadat");
    atifAslam.Addsongs("Humsafar");
    atifAslam.Addsongs("Sharbaton ka");
    atifAslam.Addsongs("Yaariyan");
    atifAslam.Addsongs("Dosti");

    atifAslam.Playsong("Humsafar");
    atifAslam.Playsong("Jalebi");

    atifAslam.Removesong("Aadat");

    atifAslam.showCurrentSong();

    atifAslam.displayPlaylist();

    return 0;
}