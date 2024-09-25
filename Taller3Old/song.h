#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
public:
    // Constructor
    Song(std::string id, std::string name, std::string genre,
         std::string artists, std::string album,
         int popularity, int durationMs, bool explicitContent);

    // Getters
    // TODO #2: Definir las funciones getters de cada uno de los campos que definen una cancion. (Total de getters: 8)
    std::string getID() const;
    std::string getName() const;
    std::string getGenre() const;
    std::string getArtists() const;
    std::string getAlbum() const;
    int getDurationMs() const;
    int getPopularity() const;
    bool getExplicitContent() const;
    
    // Setters
    // TODO #3: Definir las funciones setters de cada uno de los campos que definen una cancion. (Total de setters: 8)
    void setID(const std::string& id);
    void setName(const std::string& name);
    void setGenre(const std::string& genre);
    void setArtists(const std::string& artists);
    void setAlbum(const std::string& album);
    void setDurationMs(int durationMs);
    void setPopularity(int popularity);
    void setExplicitContent(bool explicitContent);

    // Overloaded operators
    bool operator>(const Song& other) const;
    bool operator<(const Song& other) const;
    bool operator==(const Song& other) const;

private:
    // TODO #1: Definir cada uno de los campos de la cancion. (Total de campos: 8)
    std::string id;
    std::string name;
    std::string genre;
    std::string artists;
    std::string album;
    int durationMs;
    int popularity;
    bool explicitContent; 
};

#endif // SONG_H