#include <iostream>
#include <string>

using namespace std;

class BrowserTab {
private:
  static int num_tabs;

public:
  string url;
  static int get_tabs() { return num_tabs; }
  // modified this constructor to use the colon syntax
  BrowserTab(string u) : url(u) { num_tabs++; }

  ~BrowserTab() { num_tabs -= 1; }

  // copy constructors take a const reference to another object
  // I didn't know that you could init members before the constructor using a
  // colon and you can't init const members in a constructor
  BrowserTab(BrowserTab const &other) : url(other.url) {};

  // makes sense to make the object being copied FROM const so we don't modify
  BrowserTab &operator=(const BrowserTab &other) = default;

  // this will modify other as we MOVE resources from other into the new
  BrowserTab &operator=(BrowserTab &&other) = default;
};

int BrowserTab::num_tabs = 0;

int main() {
  BrowserTab t1("google.com");
  BrowserTab t2("meta.com");

  // copy or assignment, when using = it'll copy, we have to explicitly call
  // move()
  {
    BrowserTab t3 = t1;
    cout << format("url of t3 is {}\n", t3.url);
    cout << format("Total tabs is: {}\n", BrowserTab::get_tabs());
  }

  cout << format("Total tabs after t3 goes out of scope is: {}\n",
                 BrowserTab::get_tabs());
}