Suppose that you are the Minister of Health for a small country. You are interested in building a set of
state-of-the-art hospitals to ensure that every city in your country has access to top-quality care. Your
Hospital Task Force has come to you with a set of proposed locations for these hospitals, along with
the cities that each one would service.
Although you are interested in providing excellent health care to all, you do not have the funds to build
an unlimited number of hospitals. Using your newfound skills with recursion, you are interested in
seeing whether or not it is possible to provide quality health care to every city given a limit on the number
of hospitals you can construct.
Suppose that you are given a Set<string> representing the names of all of the cities in your country.
You are also provided with a list of all the proposed hospital locations, each of which is represented by
the set of cities that the hospital could service. Given your funding restrictions, you can purchase at
most numHospitals total hospitals. 
function
bool canOfferUniversalCoverage(Set<string>& cities,
Vector< Set<string> >& locations,
int numHospitals,
Vector< Set<string> >& result)
that accepts as input the set of all cities and a list of the cities that would be covered by each hospital,
along with the maximum number of hospitals that can be constructed, and returns whether or not it is
possible to provide coverage to all cities using the limited number of hospitals. If so, your function
should update the result parameter to contain one such choice of hospitals.If not, it does not need to
use the result parameter.