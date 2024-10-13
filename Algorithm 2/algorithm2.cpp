// ============================================================================
// File: AlgorithmTwo.cpp
// ============================================================================
// Programmer: Thomas Ortiz, Alexander Sanchez, Ansh Tomar, Edgar Cardenas
// Date: October 2024
// Class: CPSC 335 Algorithm Engineering
// Instructor: Kavil Jain
// Project 1: Algorithm 2, Greedy Approach to Hamiltonian Problem
//
// Description:
//      Algorithm 2: Greedy Approach to Hamiltonian Problem.
//
//      This algorithm finds the preferred starting city of a circular road,
//      where each city has a gas station for fuel and distances to neighboring
//      cities are known.
//      Given city distances, available fuel, and MPG, it returns the index of
//      the city where a car can start, visit all cities, and return with fuel
//      left. Exactly one valid starting city is guaranteed.
//
// ============================================================================

#include <iostream>

// function prototype
int GreedyHamiltonian(int cityDistances[], int fuel[], int mpg);

// ==== main ===================================================================
//
//  The main funciton provides test inputs for testing the GreedyHamiltonian
//  function. Will be commented out when not in use. Remove /*  and  */ at the
//  beginning and end to use. 
//
// ============================================================================

/*
int main()
{
	int distancesInput[] = {5, 25, 15, 10, 15};
	int fuelInput[]      = {1, 2, 1, 0, 3};
	int mpgInput         = 10;
	int starting_city;

	starting_city = GreedyHamiltonian(distancesInput, fuelInput, mpgInput);

	std::cout << "The preferred starting city is indexed at " << starting_city;

	return 0;
}
*/


// ==== GreedyHamiltonian =====================================================
//
// Input:
//      city_distances: array that holds the distance from one city to the next.
//      fuel: array that holds the available fuel at each city.
//      mpg: the cars MPG. 
//
// Output:
//      An integer value representing the index of the preferred city to serve
//      as a starting point.
//
// ============================================================================

int GreedyHamiltonian(int city_distances[], int fuel[], int mpg)
{
	int startCity   = -1;   // guaranteed solution, will set to -1 as fallback
	int currentCity = 0;    // holds the current city that is visited
	int nextCity    = 0;    // used to get the next city to travel to
	int tankLevel   = 0;    // holds the updated fuel level in car
	int visitCount  = 0;    // used as counter for visted cities
	
	// note each city has a gas station that used to keep track of city index
	int fuelLength  = 5;   // holds the length of fuel[], hardcoded to 5 cities
    
    // used to iterate thorugh each element starting at 0
	for (int index = 0; index < fuelLength; index++)
	{
		tankLevel   = 0;        // tank level will reset to test new start city
		currentCity = index;    // currentCity dictated by index 
		visitCount  = 0;        // visitCount will reset for new trip
        
        // cycle is complete when all cities are visited
		while (visitCount < 5)
		{
		    // update tankLevel with available fuel at currentCity,
		    // calculate the miles that can be travelled with fuel
			tankLevel = tankLevel + (mpg * fuel[currentCity]);

            // success: if there is enough fuel to travel to next city
			if (tankLevel >= city_distances[currentCity])
			{
				tankLevel = tankLevel - city_distances[currentCity];
				
				// calculates next city in array, modulus allows for wrapping
				nextCity = (currentCity + 1) % fuelLength;
				currentCity = nextCity;     // move to new city
				visitCount++;               // +1 to our visited cities
			}

            // fail: we do not have enough fuel to get to next city
			else
			{
				break;
			}

		}

        // If all cities are visited, preferred starting city = currentCity
		if (visitCount == 5)
		{
			startCity = index;      // we found our preferred starting city
			break;                  // we can break out of the for loop		
		}

	}

	return startCity;      // return the index of the preferred starting city

}