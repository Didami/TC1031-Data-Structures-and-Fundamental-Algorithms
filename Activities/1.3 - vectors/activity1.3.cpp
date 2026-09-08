#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Track {
    private:
    int id;
    string title;
    int duration;
    int count_played;

    public:
    Track() {}

    Track(int id, string title, int duration, int count_played) {
        this->id = id;
        this->title = title;
        this->duration = duration;
        this->count_played = count_played;
    }

    void print() {
        cout << setw(4) << left << id << setw(10) << left << title << setw(4) << left << duration << setw(3) << left << count_played << endl; 
    }

    void save(ofstream &file) {
        file << id << " "
             << title << " "
             << duration << " "
             << count_played << endl;

    }
};

void saveTracks(vector<Track> &tracks) {
    ofstream file("./tracks.txt");

    for (Track track : tracks) {
        track.save(file);
    }

    file.close();
}

Track inputTrack() {
    int id, duration, count_played;
    string title;
    
    cout << "Enter id: ";
    cin >> id;
    
    cout << "Enter title: ";
    cin >> title;

    cout << "Enter duration: ";
    cin >> duration;

    cout << "Enter count played: ";
    cin >> count_played;

    return Track(id, title, duration, count_played);
}

int main() {
    vector<Track> tracks;

    string line, values[4];
    int i;
    ifstream file("./tracks.txt");

    while (getline(file, line))
    {
        stringstream ss(line);
        i = 0;
        while (getline(ss, values[i], ' ')) i++;

        string title = values[1];
        int id = stoi(values[0]), duration = stoi(values[2]), count_played = stoi(values[3]);
        tracks.push_back(Track(id, title, duration, count_played));
    }

    int option;
    while (option != 5) {
        cout << "1. Add a new track" << endl;
        cout << "2. Modify a specific track" << endl;
        cout << "3. Delete a track" << endl;
        cout << "4. Save update to the text file" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter an option: ";
        cin >> option;

        int index;
        Track track;

        switch (option) {
            case 1: {
                // Add
                Track track = inputTrack();
                tracks.push_back(track);
                break;
            }

            case 2: {
                // Modify
                Track track = tracks[index];
                cout << "TRACKS: " << endl;

                for (int i = 0; i < tracks.size(); i++) {
                    cout << i << ": ";
                    tracks[i].print();
                }

                cout << "Enter index: ";
                cin >> index;

                Track modified = inputTrack();
                tracks[index] = (modified);

                break;
            }

            case 3: {
                // Delete
                cout << "Enter index: ";
                cin >> index;
                tracks.erase(tracks.begin() + index);
                break;
            }

            case 4: {
                // Save update
                cout << "Saving ..." << endl;
                saveTracks(tracks);
                cout << "Changes saved." << endl;
                break;
            }

            case 5: {
                cout << "Exiting ...";
                break;
            }
        }
    }

    return 0;
}