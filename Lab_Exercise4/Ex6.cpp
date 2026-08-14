#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    int year;
    string director;
    string actor;
    string actress;

public:

    void setTitle(string t) {
        title = t; }

    void setYear(int y) {
        year = y; }

    void setDirector(string d) {
        director = d; }

    void setActor(string a) {
        actor = a; }

    void setActress(string ac) {
        actress = ac; }

    void displayMovieDetails() {
        cout << "Movie Title : " << title << endl;
        cout << "Release Year : " << year << endl;
        cout << "Director : " << director << endl;
        cout << "Movie Actor : " << actor << endl;
        cout << "Movie Actress : " << actress << endl; }
};

int main() {

    Movie myFavoriteMovie;
    myFavoriteMovie.setTitle("Harry Potter and the Half-Blood Prince");
    myFavoriteMovie.setYear(2009);
    myFavoriteMovie.setDirector("David Yates");\
    myFavoriteMovie.setActor("Daniel Radcliffe");
    myFavoriteMovie.setActress("Emma Watson");
    myFavoriteMovie.displayMovieDetails();

    return 0;
}
