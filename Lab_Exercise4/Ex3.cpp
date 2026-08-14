#include <iostream>
#include <string>
using namespace std;

void movieInfo(string movieName, int runningTime = 90) {
    cout << "Movie: " << movieName << endl;
    cout << "Running time: " << runningTime << " minutes" << endl;
}

int main() {
    movieInfo("Dark");
    movieInfo("1996", 152);

    return 0;
}
