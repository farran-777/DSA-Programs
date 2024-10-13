#include <iostream>
using namespace std;

class RemoteControl {
public:
    void changeChannel(int channel) {
        updateChannel(channel);
        displayChannel();
    }

    void adjustVolume(int level) {
        setVolume(level);
        displayVolume();
    }

private:
    int currentChannel = 1;
    int currentVolume = 10;

    void updateChannel(int channel) {
        currentChannel = channel;
    }

    void setVolume(int level) {
        currentVolume = level;
    }

    void displayChannel() {
        cout << "Changed to channel: " << currentChannel << endl;
    }

    void displayVolume() {
        cout << "Volume set to: " << currentVolume << endl;
    }
};

int main() {
    RemoteControl myRemote;

    myRemote.changeChannel(5);
    myRemote.adjustVolume(15);

    myRemote.changeChannel(10);
    myRemote.adjustVolume(8);

    return 0;
}
