// AX Structures notes

/*

QUESTIONS:
What are structures?
- a custom data type
- an abstract data type known as a adt
- general model of something
How do you build a structure?
- You use struct and then mae your structure and then you put a value for properties inside of it
- When you want to display it you do it in the main
What can be held in a structure?
- various elements
How do you access the information in a structure?
- You can access info in structure by using the struct name. whatever you want from it.
How do you overload an operator?
- you use symbols like +, -, ==


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Date{
    short year = 1900;
    short month = 1;
    short day = 1;

};

//pascal case for structures
struct Movie {
    string title;
    //camel case for properties
    Date releaseDate;
    bool isPopular = true;

    bool equals(Movie movie){
        if (title == movie.title &&
            releaseDate.year == movie.releaseDate.year &&
            releaseDate.month == movie.releaseDate.month &&
            releaseDate.day == movie.releaseDate.day &&
            isPopular == movie.isPopular
        ){
        return true;
    }else{
        return false;
    }
    }
};

struct Customer {
    int id;
    string name;
    string email;

};

int main(){
    vector<Movie> movies;

    //Movie movie = {"Terminator", 1984};
    movies.push_back({"Terminator", 1984, 6, 1});
    movies.push_back({"Terminator 2", 1987});

    Movie movie1 = {"Terminator", 1984, 6, 1};
    Movie movie2 = {"Terminator", 1987};

    //auto [title, releaseYear, isPopular] {movie};

    for (auto movie: movies){
        auto [title, releaseDate, isPopular] {movie};
        cout << "Movie Title: " << title << endl;
        cout << "Movie Date: " << releaseDate.year << endl;
        cout << "Movie Popular: " <<  isPopular << endl;
    }
    cout << movie1 = movie2 << endl;

    
    Customer customer;
    customer.id = 1435323;
    customer.name = "Bob";
    customer.email = "bob.richard@gmail.com";
    cout << customer.name << "'s ids is " << customer.id << " and his email is " << customer.email << endl;
    return 0;

}