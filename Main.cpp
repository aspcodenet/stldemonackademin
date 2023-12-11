#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>


class Movie{
public:
    typedef enum {
        MovieType_Film,
        MovieType_Tv
    }MovieType;

    Movie(){

    }

    Movie(std::string name, int year,MovieType type, int price)
    :name(name),year(year),type(type),price(price){
    }
    std::string getName() const{
        return name;
    }
    int getYear() const{
        return year;
    }
    int getPrice() const{
        return price;
    }
    MovieType getMovieType() const{
        return type;
    }
private:
    std::string name;
    MovieType type;
    int year;
    int price;
};

// TISDAG = distans :( 
// TEORI STL Iterators, Containers, Algorithms
//foreach for_each
//accumulate
//count_if
//any of
//filters LAMBDA
//sort
// 10:45 ca - 11:30 ÖVNINGAR  + redovisningar
//templates

//EFTERMIDDAG 13:00:
// C++ 20 
// coolest thing ever in C++ = views 

int main(){
    std::vector<Movie> greatMovies{
        Movie("The Mummy returns",2022,Movie::MovieType::MovieType_Film,40), // <- begin
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film,99),  // <-items
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv,50),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film,88),
       Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv,82),
    };    


    std::sort(std::begin(greatMovies),std::end(greatMovies),[](const Movie &item1, const Movie &item2){
        return item1.getPrice() < item2.getPrice();        
    });
    for(auto &m : greatMovies ){
        std::cout << m.getName() << std::endl;
    }


    // bool any2000 = std::ranges::any_of(greatMovies,[](const Movie &m){
    //     return m.getYear() == 2000;
    // });


    // Finns det nån film som är gjord år 2000
    bool any2000 = std::any_of(std::begin(greatMovies),std::end(greatMovies),[](const Movie &m){
        return m.getYear() == 2000;
    });
    // bool any2000 = false;
    // for(const Movie  &m : greatMovies)
    //     if(m.getYear() == 2000){
    //         any2000 = true;
    //         break;
    //     }
    // }

    // for(int i = 0; i < greatMovies.size();i++){
    //     if(greatMovies[i].getYear() == 2000){
    //         any2000 = true;
    //         break;
    //     }
    // }
    // if(any2000) {
    //     std::cout << "Yes" << std::endl;
    // }



    //Hur många filmer kostar > 60 kr
    // int count = 0;
    // for(int i = 0; i < greatMovies.size();i++){
    //     if(greatMovies[i].getPrice() > 60){
    //         count++;
    //     }
    // }
    int count = std::count_if(std::begin(greatMovies), std::end(greatMovies),[](const Movie &m){
        return m.getPrice() > 60;
    });

    // int total = 0;
    // for(int i = 0; i < greatMovies.size();i++){
    //     total += greatMovies[i].getPrice();
    // }

    // int total = std::accumulate(std::begin(greatMovies),std::end(greatMovies),0,[](int sum, const Movie &m){
    //         return sum + m.getPrice();
    //     });


        // if(m.getPrice() > 60)
        //     return true;
        // return false;

    std::cout << "Antal: " << count << std::endl;
     






}