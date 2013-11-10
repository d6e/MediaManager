#ifndef MEDIA_H
#define MEDIA_H
#include <map>
#include <string>
#include <iostream>
using namespace std;
const string SORTED_DATA_TYPE_ARRAY [] = {"director","title","date","lead actor"};    //TODO: movie this somewhere else, (maybe factory?)
                                                                                    //TODO: should be sorted by a specific genre's sorting scheme (and maybe placed in that genre's class)
//most generic Media type
class Media {
public:
    Media();
    virtual ~Media();
    virtual string genre() = 0;    //returns the work's genre. Overridden for each specific media type/genre combination.
    string dataString();    //represents the work's data as a string (based on proper sorting)
    virtual Media* create() = 0;
    void addData(string,object);    //TODO: find proper syntax to replace "object"
private:
    MediaFormat format;    //should this be a part of mediaData?
    map<string,object> mediaData;    //IDEA: use a <string,string> map for simplicity (since data input comes from strings anyway),
                                    //for special cases, (like performing arithmetic operations on year), just make temp variables parsed from the string data.
};

//generic Movie
class Movie: public Media {
    const MediaFormat format("DVD"));    //these are const templates for the format data member, not instance-specific.
    const MediaFormat format("blu-ray"));    //this format storage method is temporary. Figue out  what format will be used for and base format storage around this.
    //TODO: movie-specific methods
};
//movie genres
    class ClassicMovie: public Movie {
    public:
        //TODO: consider putting const, sorted dataType string/struct arrays that will be used by factories
        const string CLASSIC_MOVIE_DATA_TYPES [] = {"date","famous actor","director"};    
        //classic movies are sorted by date, then famous actor. (how to limit sorting to this point? Do we not need to worryL)
        virtual ClassicMovie* create(){return new ClassicMovie();}
        virtual string genre();
};

    class DramaMovie: public Movie {
    public:
        const string DRAMA_MOVIE_DATA_TYPES [] = {"director","title","date","lead actor"};    //drama movies are sorted by director, then title
        virtual DramaMovie* create(){return new DramaMovie();}
        virtual string genre();
    };
    class ComedyMovie: public Movie {
    public:
        const string COMEDY_MOVIE_DATA_TYPES [] = {"title","date","director"}; //comedy movies are sorted by title, then date
        virtual ComedyMovie* create(){return new ComedyMovie();}
        virtual string genre();
    };

//generic Music
class Music: public Media {
    const MediaFormat format("CD"));    //these are const templates for the format data member, not instance-specific.
    const MediaFormat format("cassette"));
    //TODO: music-specific methods    
};
//music genres
    class RockMusic: public Music {
        const string ROCK_MUSIC_DATA_TYPES [] = {"artist","title","date"};
        virtual DramaMovie* create(){return new RockMusic();}
        virtual string genre();
    };

    class JazzMusic: public Music {
        const string ROCK_MUSIC_DATA_TYPES [] = {"artist","date","title"};    
        virtual DramaMovie* create(){return new JazzMusic();}
        virtual string genre();
    };
class Book: public Media {
    const MediaFormat format("book"));
    const MediaFormat format("book on tape"));
    //TODO: book-specific methods    
};
//book genres
    class MysteryBook: public Book {
        const string MYSTERY_BOOK_DATA_TYPES [] = {"author","title","date"};
        virtual DramaMovie* create(){return new DramaMovie();}
        virtual string genre();
    };
#endif