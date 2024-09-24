// song.h
#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
private:
    // TODO #1: Definir los campos requeridos para una canción
    std::string id;
    std::string name;
    std::string genre;
    std::string artist;
    std::string album;
    int duration;
    int popularity;
    bool explicito; 

public:
    // TODO #2: Definir las funciones getters
    std::string getID() const;
    std::string getName() const;
    std::string getGenre() const;
    std::string getArtist() const;
    std::string getAlbum() const;
    int getDuration() const;
    int getPopularity() const;
    bool getExplicito() const;

    // TODO #3: Definir las funciones setters
    void setID(const std::string& id);
    void setName(const std::string& name);
    void setGenre(const std::string& genre);
    void setArtist(const std::string& artist);
    void setAlbum(const std::string& album);
    void setDuration(int duration);
    void setPopularity(int popularity);
    void setExplicito(bool explicito);

    // TODO #6: Sobrecarga de operadores
    bool operator>(const Song& other) const;
    bool operator<(const Song& other) const;
    bool operator==(const Song& other) const;
};

#endif // SONG_H