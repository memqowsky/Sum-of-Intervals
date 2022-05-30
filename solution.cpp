#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

    // vector par z ktorych powstaja przedziały
    vector<std::pair<int, int>> intervals2 = {
                                                  {1,5},
                                                  {10, 20},
                                                  {1, 6},
                                                  {16, 19},
                                                  {5, 11}
                                             };

    vector<int> v1 = {};    
    vector<vector<int>> filledVector;

    for (int i = 0; i < filledVector.size(); ++i) {
        for (int j = 0; j < filledVector[i].size(); ++j) {
            cout << filledVector[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> repeats{};
    vector<int> allEndsOfIntervals{};
    pair<int, int> combinedInterval;
    vector<pair<int, int>> allIntervals;
 
    // poniższe dwie petle przechodzą przez wszzystkie przedziały
    for (int f = 0; f < intervals2.size(); ++f) {

        for (int s = 0; s < intervals2.size(); ++s) {

            // jeśli f == s nie ma sensu wykonywać petli
            if (f != s) {

                filledVector.clear();

                // tworzymy vector ktory posiada wektory uzupelnione liczbami calkowitymi od [i].first do [i].second                

                v1.clear();

                // wypełniamy wektor liczbami całkowitymi od poczatku do konca przedziału
                for (int i = intervals2[f].first; i <= intervals2[f].second; ++i) {
                    v1.push_back(i);
                }                
                    // i wrzucamy go do filledVector, ktory zawiera dwa przedziały na których będziemy działać. Są one wypełnione liczbami całkowitymi
                    filledVector.push_back(v1);

                v1.clear();                

                for (int i = intervals2[s].first; i <= intervals2[s].second; ++i) {
                    v1.push_back(i);
                }
                    filledVector.push_back(v1);
          
                repeats.clear();
                allEndsOfIntervals.clear();

                // liczymy powtorzenia TODO: zmienić zliczanie powtorzeń na boola
                for (auto i = filledVector[0].begin(); i != filledVector[0].end(); ++i)
                {
                    if (std::find(filledVector[1].begin(), filledVector[1].end(), *i) != filledVector[1].end())
                    {
                        repeats.push_back(*i);
                    }
                }
                cout << endl;

                // jeżeli występują powtórzenia
                if (repeats.size() > 0) {
                    
                    // wrzucamy krance przedziałów do vectora allEndsOfIntervals
                    allEndsOfIntervals.push_back(intervals2[f].first);
                    allEndsOfIntervals.push_back(intervals2[f].second);
                    allEndsOfIntervals.push_back(intervals2[s].first);
                    allEndsOfIntervals.push_back(intervals2[s].second);

                    // sortujemy by wyznaczyć krance nowego przedziału
                    sort(allEndsOfIntervals.begin(), allEndsOfIntervals.end());

                    //wybieramy najmniejszy i najwiekszy element z krancow przedzialow i
                    // zamieniamy krance jednego z przedziałów na skrajne wartości dwóch połączonych przedziałów


                    intervals2[f] = { {allEndsOfIntervals[0]},{allEndsOfIntervals[allEndsOfIntervals.size() - 1]} };

                    //usuwamy pozostały, niepotrzebny przedział
                    intervals2.erase(intervals2.begin() + s);

                    // zerujemy f i s - zmienne które są wyznacznikiem dla pętli. Dzięki temu nie pominiemy żadnego przedziału
                    f = 0; s = 0;

                }                
            } // if (f != s)
        } // s
    } // f

    map<int, int> allIntervalsMap;

    // wrzucamy wszystko do mapy aby uniknąc powtórek przedziałów
    for (auto& e : allIntervals) {
        allIntervalsMap.insert({ e.first, e.second });
    }

    vector<int> differences{};

    // do vectora differences wrzucamy róznice przedziałów
    for (auto& e : intervals2) {
        differences.push_back(e.second - e.first);
    }

    // zwracamy sumę różnic

    return accumulate(differences.begin(), differences.end(), 0);

}
