#include <iostream>
#include <string>


using namespace std;

class Car
{
private:
    string company;
    string model;
    int year;
public:

    Car()
    {
        company = "Unknown";
        model = "Unknown";
        year = 0;
    } 

    /* Setters */
    void set_company(string comp) 
    { 
        company = comp;
    }
    void set_model(string mod) 
    { 
        model = mod;
    }
    void set_year(int y) 
    { 
        year = y;
    }

    /* Getters*/
    string get_company()
    {
        return company;
    }
    string get_model()
    {
        return model;
    }
    int get_year()
    {
        return year;
    }
};

int main()
{
    Car myCar;

    // Initialize Car object
    myCar.set_company("Toyota");
    myCar.set_model("Curulla");
    myCar.set_year(2020);

    // Display car details
    cout << "Car Details:" << endl;
    cout << "Company: " << myCar.get_company() << endl;
    cout << "Model: " << myCar.get_model() << endl;
    cout << "Year: " << myCar.get_year() << endl;

    return 0;
}