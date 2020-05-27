/*
 * File: UniversalHealthCoverage.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the UniversalHealthCoverage problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */
#include <iostream>
#include <string>
#include "simpio.h"
#include "set.h"
#include "vector.h"
//#include "console.h"
using namespace std;

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */
bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result);
Vector<Vector<Set<string> > > generateSubsets(Vector<Set<string> >& locations, int numHospitals);
Vector<Set<string> > chooseSubsets(Set<string>& cities, 
								  Vector<Vector<Set<string> > >& subsets);
bool checkArea(Set<string>& cities, Vector<Set<string> >& subset);
bool containsCity(Vector<Set<string> >& subset, string city);

int main() {
	// testing code:
	Set<string> cities;
	cities += "A", "B", "C", "D", "E", "F";
	Vector<Set<string> > locations;
	Set<string> set;
	for (int i = 0; i < 4; i++){
		locations.add(set);
	}
	locations[0] += "A", "B", "C", "F";
	locations[1] += "A", "C", "D", "E";
	locations[2] += "B", "F";
	locations[3] += "C", "E", "F";
	Vector<Set<string> > result;
	int numHospitals = getInteger("Enter max number of hospitals: ");
	cout << canOfferUniversalCoverage(cities, locations, numHospitals, result) << endl;
	cout << result << endl;
	return 0;
}

// this method determines if there are any combination of hospitals to cover cities given in Set of "cities"
bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
							   Vector< Set<string> >& result){
	Vector<Vector<Set<string> > > subsets = generateSubsets(locations, numHospitals);
	result = chooseSubsets(cities, subsets);
	if (result.size() > 0)
		return true;
	return false;
}

// this method generates all possible combinations of placing hospitals.
Vector<Vector<Set<string> > > generateSubsets(Vector<Set<string> >& locations, int numHospitals){
	Vector<Vector<Set<string> > > vect;
	if (locations.size() == 0){
		Vector<Set<string> > empty;
		vect += empty;
		return vect;
	}
	Set<string> first = locations[0];
	Vector<Set<string> > copy = locations;
	copy.remove(0);
	vect = generateSubsets(copy, numHospitals);
	Vector<Vector<Set<string> > > result = vect;
	foreach (Vector<Set<string> > v in vect){
		v.add(first);
		if (v.size() <= numHospitals)
			result.add(v);
	}
	return result;
}

// this method tries combinations whether choosen combination covers all cities. 
Vector<Set<string> > chooseSubsets(Set<string>& cities,
								  Vector<Vector<Set<string> > >& subsets){
	Vector<Set<string> > result;
	foreach(Vector<Set<string> > subset in subsets){
		if (checkArea(cities, subset))
			return subset;
	}
	return result;
}

// this method checks if given combination coveres all cities.
bool checkArea(Set<string>& cities, Vector<Set<string> >& subset){
	foreach (string city in cities){
		if (!containsCity(subset, city))
			return false;
	}
	return true;
}

// this method checks if given city is in given combination of hospitals.
bool containsCity(Vector<Set<string> >& subset, string city){
	foreach (Set<string> set in subset){
		if (set.contains(city))
			return true;
	}
	return false;
}