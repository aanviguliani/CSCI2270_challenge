#include <iostream>
#include <fstream>
using namespace std;

int randomNum(int min, int max)
{
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

string pickAirlineFunction(string airport)
{
    if(airport == "ATL")
    {

    }
}

string pickDestination(string airportArray[],string airport)
{
    int rand = randomNum(0,9);
    string dest = airportArray[rand];
    while(dest == airport)
    {
        int rand = randomNum(0,9);
        string dest = airportArray[rand];
    }
    return dest;
}

int getDistance(string airport,string destination)
{
    
}

int main()
{
    int index = randomNum(0,9);
    string airportArray[] = {"ATL","LAX","ORD","DFW","DEN","JFK","SFO","LAS","SEA","CLT"};
    int numFlightsArray[] = {1000,1600,};
    string airport = airportArray[index];
    int numFlights = numFlightsArray[index];

    ofstream myfile("flightData.csv");
    if(myfile.is_open())
    {
        for(int i = 0; i < numFlights; i++)
        {
            string airline = pickAirlineFunction(airport);
            string destination = pickDestination(airportArray,airport);
            getDistance(airport,destination);
        }
    }
}