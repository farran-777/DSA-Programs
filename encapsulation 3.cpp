#include <iostream>
using namespace std;

class DigitalLock {
public:
    DigitalLock() : lockedState(false) {}

    void secure() {
        if (!lockedState) {
            lockedState = true;
            cout << "Lock secured." << endl;
        } else {
            cout << "Lock is already secured." << endl;
        }
    }

    void release() {
        if (lockedState) {
            lockedState = false;
            cout << "Lock released." << endl;
        } else {
            cout << "Lock is already released." << endl;
        }
    }

    bool isLocked() const {
        return lockedState;
    }

private:
    bool lockedState;
};

int main() {
    DigitalLock myDigitalLock;

    myDigitalLock.release();
    myDigitalLock.secure();
    myDigitalLock.secure();
    myDigitalLock.release();
    myDigitalLock.release();

    return 0;
}
