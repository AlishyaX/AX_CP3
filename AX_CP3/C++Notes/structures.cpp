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
- use == so that it can be used with a data type and compare them
- you use symbols like +, -, ==
-example below


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


};

struct Customer {
    int id;
    string name;
    string email;

};


bool operator== (const Movie& first, const Movie& second){
        return (first.title == second.title &&
            first.releaseDate.year == second.releaseDate.year &&
            first.releaseDate.month == second.releaseDate.month &&
            first.releaseDate.day == second.releaseDate.day &&
            first.isPopular == second.isPopular
        );
}

ostream& operator<<(ostream& stream, Movie& movie){
    stream << movie.title;
    return stream;
}

ostream& operator<<(ostream& stream, Customer& customer){
    stream << customer.name;
    return stream;
}

void showMovie(Movie& movie){
    cout << movie -> title << endl;
}
int main(){
    vector<Movie> movies;

    //Movie movie = {"Terminator", 1984};
    movies.push_back({"Terminator", 1984, 6, 1});
    movies.push_back({"Terminator 2", 1987});

    Movie movie1 = {"Terminator", 1984, 6, 1};
    Movie movie2 = {"Terminator", 1987};
    showMovie(&movie1);

    //auto [title, releaseYear, isPopular] {movie};

    for (auto movie: movies){
        auto [title, releaseDate, isPopular] {movie};
        cout << "Movie Title: " << title << endl;
        cout << "Movie Date: " << releaseDate.year << endl;
        cout << "Movie Popular: " <<  isPopular << endl;
    }
    if(movie1 == movie2){
        cout << movie1 << "is equal" << endl;
    }else{
        cout << movie1 << "is not" << movie2 << endl;
    }
    
    Customer customer;
    customer.id = 1435323;
    customer.name = "Bob";
    customer.email = "bob.richard@gmail.com";
    cout << customer.name << "'s ids is " << customer.id << " and his email is " << customer.email << endl;
    return 0;

}