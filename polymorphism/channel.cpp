#include <iostream>
#include <list>

using namespace std;

class YoutubeChannel {
private:
    string Name;
    int SubscribeCount;
    list<string> Titles;
protected:
    string OwnerName;
    int ContentQuality;
public:
    YoutubeChannel(string name, string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribeCount = 0;
        ContentQuality = 0;
    }
    void GetInfo() {
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "SubscribeCount" << SubscribeCount << endl;
        cout << "Videos Published" << endl;
        for (string videoTitle : Titles) {
            cout << videoTitle << endl;
        }
    }

    void Subscribe() {
        SubscribeCount++;
    }
    void Unsubscribe() {
        if(SubscribeCount > 0) {
            SubscribeCount--;
        }
    }
    void PublishVideo(string title) {
        Titles.push_back(title);
    } 

    void CheckQuality() {
        if (ContentQuality > 5) {
            cout << Name << " is a good quality channel" << endl;
        } else {
            cout << Name << ", this channel has bad analytics" << endl;
        }
    }
};

class CookingChannel : public YoutubeChannel {
public:
    CookingChannel(string name, string ownername) : YoutubeChannel(name, ownername){

    }

    void Pratice() {
        cout << OwnerName << " is praticing cooking" << endl;
        ContentQuality++;
    }
};


class DancingChannel : public YoutubeChannel {
public:
    DancingChannel(string name, string ownername) : YoutubeChannel(name, ownername){

    }

    void Pratice() {
        cout << OwnerName << " is praticing dancing" << endl;
        ContentQuality++;
    }
};

int main() {
    CookingChannel cookingchannel1("Booby's kitchen", "Bobby");
    DancingChannel dancingchannel1("Jesicca's Danceroom", "Jessi");
    cookingchannel1.Pratice();
    dancingchannel1.Pratice();
    dancingchannel1.Pratice();
    dancingchannel1.Pratice();
    dancingchannel1.Pratice();
    dancingchannel1.Pratice();
    dancingchannel1.Pratice();
    dancingchannel1.Pratice();

    // use pointer to point to derived class 
    //assign a pointer of a base class on address of a derived class 
    YoutubeChannel* yt1 = &cookingchannel1;
    YoutubeChannel* yt2 = &dancingchannel1;

    //invoke func use pointers of base class
    yt1->CheckQuality();
    yt2->CheckQuality();

    return 0;
}