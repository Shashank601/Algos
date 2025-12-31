

class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> entries; 
    unordered_map<string, pair<int,int>> runSum; // stations -> t and num of rides

    void checkIn(int id, string stationName, int t) {
        entries[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [name, checkinT] = entries[id];
        entries.erase(id);

        int timeTaken = t - checkinT;


        string hashKey = name + "->" + stationName;
        if (runSum.count(hashKey)) {                         <--- no need
            runSum[hashKey].first += timeTaken; 
            runSum[hashKey].second++; 
        } else {
            runSum[hashKey] = {timeTaken, 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string hashKey = startStation + "->" + endStation;
        auto [cumSum, rides] = runSum[hashKey];
        double avg = cumSum/(double)rides;
        return avg;

    }
};

/*
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]


black box that store 
entries
id name t
id name t
id name t
id name t
id name t
id name t
id name t

checkouts
id name t
id name t
id name t
id name t
id name t
id name t
id name t

ds that store time of a ride from name1 and name2, => runningSum, to get avg 
every checkout will add to that key


getAvgT => n1, n2 


checkin
id name t
i stores it

using id as a key

checkout happens i will check the key => calc time take and add it to that 
s1 to s2 running sum


checkout


getavgtime


c_in adds a pair of info 
c_in adds
c_in adds

error 

a ab
aa b

both have collison use a separator in hashing

 */

