#include "song.h"

// Constructor
Song::Song(std::string id, std::string name, std::string genre,
           std::string artists, std::string album,
           int popularity, int durationMs, bool explicitContent)
    : id(id), name(name), genre(genre), artists(artists),
      album(album), popularity(popularity),
      durationMs(durationMs), explicitContent(explicitContent) {}

// Getters
// TODO #4: Implementar las funciones getters de cada uno de los campos que definen una cancion. (Total de getters: 8)
std::string Song::getID() const { 
    return id; 
}
std::string Song::getName() const { 
    return name; 
}
std::string Song::getGenre() const { 
    return genre; 
}
std::string Song::getArtists() const { 
    return artists; 
}
std::string Song::getAlbum() const { 
    return album; 
}
int Song::getDurationMs() const { 
    return durationMs; 
}
int Song::getPopularity() const { 
    return popularity; 
}
bool Song::getExplicitContent() const { 
    return explicitContent; 
}

// Setters
// TODO #5: Implementar las funciones setters de cada uno de los campos que definen una cancion. (Total de setters: 8)
void Song::setID(const std::string& id) { 
    this->id = id; 
    }
void Song::setName(const std::string& name) { 
    this->name = name; 
    }
void Song::setGenre(const std::string& genre) { 
    this->genre = genre; 
    }
void Song::setArtists(const std::string& artists) { 
    this->artists = artists; 
    }
void Song::setAlbum(const std::string& album) { 
    this->album = album; 
    }
void Song::setDurationMs(int duration) { 
    this->durationMs = durationMs; 
    }
void Song::setPopularity(int popularity) { 
    this->popularity = popularity; 
    }
void Song::setExplicitContent(bool explicitContent){
    this->explicitContent = explicitContent;
}

// Overloaded operators
// TODO #6: Implementar las funciones de sobrecarga de operadores >, < e ==.
bool Song::operator>(const Song& other) const {
    if (id > other.id){
        return true;
    }
    return false;
}

bool Song::operator<(const Song& other) const {
    if (id < other.id){
        return true;
    }
    return false;
}

bool Song::operator==(const Song& other) const {
    if (id == other.id){
        return true;
    }
    return false;
}