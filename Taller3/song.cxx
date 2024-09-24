// song.cxx
#include "song.h"

// TODO #4: Implementar las funciones getters
std::string Song::getID() const { 
    return id; 
}
std::string Song::getName() const { 
    return name; 
    }
std::string Song::getGenre() const { 
    return genre; 
    }
std::string Song::getArtist() const { 
    return artist; 
    }
std::string Song::getAlbum() const { 
    return album; 
    }
int Song::getDuration() const { 
    return duration; 
    }
int Song::getPopularity() const { 
    return popularity; 
    }


// TODO #5: Implementar las funciones setters
void Song::setID(const std::string& id) { 
    this->id = id; 
    }
void Song::setName(const std::string& name) { 
    this->name = name; 
    }
void Song::setGenre(const std::string& genre) { 
    this->genre = genre; 
    }
void Song::setArtist(const std::string& artist) { 
    this->artist = artist; 
    }
void Song::setAlbum(const std::string& album) { 
    this->album = album; 
    }
void Song::setDuration(int duration) { 
    this->duration = duration; 
    }
void Song::setPopularity(int popularity) { 
    this->popularity = popularity; 
    }
void Song::setExplicito(bool explicito){
    this->explicito = explicito;
}

// TODO #6: Implementar sobrecarga de operadores
bool Song::operator>(const Song& other) const {
    return id > other.id;
}

bool Song::operator<(const Song& other) const {
    return id < other.id;
}

bool Song::operator==(const Song& other) const {
    return id == other.id;
}
