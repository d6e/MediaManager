/*
#include "lab4IoPrep.h"
	//will probably end up making an object array in Movie
Lab4IoPrep::Lab4IoPrep(){}
//TODO: make a linked list set of bintrees
void Lab4IoPrep::readInputFile(ifstream& inputFile){	//might want to make this return movies
	MovieFactory movieMaker;
	MovieCollection allMovies;//TODO
	//BinTree movieTree;
	for(;;){
		
		infile >> movieCode                 // reads the 'C' code

   		infile.get();                       // get (and ignore) blank before director
   		getline(infile, director, ',');     // input director
   
   		infile.get();                       // get (and ignore) blank before title
   		getline(infile, title, ',');        // input title
   
   		infile.get();                       // get (and ignore) blank before actor
   		infile >> actorFirst >> actorLast;  // input star's name
   		infile >> month >> year;            // input month and year
   		
		//OLD VERSION:
		if(inputFile.eof()) break;
		string genre = "";		//TODO: break this up into its own methods
		inputFile >> genre;		
		if(!validGenre(genre)){
			string temp;
			getline(inputFile,temp);
			continue;
		}
		//TODO: do not put different genres of movies in the same bintree.
		Movie *nextMovie = (movieMaker.createMovie(genre,inputFile));
		allMovies.insert(nextMovie);
		
	}
	cout << allMovies << endl;

}

bool Lab4IoPrep::validGenre(string genre){
	int genreCount = 3; //TODO: get this better
	for(int i = 0; i < genreCount; i++){
		if(genre == VALID_GENRES[i]) return true;
	}
	return false;
}
*/