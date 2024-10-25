#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Page {
    string link;        
    string name;        

    Page(string u, string t) : link(u), name(t) {}
};


class History {
private:
    stack<Page> pages;  

public:
    
    void visitPage(const string& link, const string& name) {
        pages.push(Page(link, name));
        cout << "Added URL: " << link << " - " << name << endl;
    }


    void eraseHistory() {
        while (!pages.empty()) {
            pages.pop();
        }
        cout << "Browsing history cleared." << endl;
    }

    
    void showHistory() const {
        if (pages.empty()) {
            cout << "No browsing history available." << endl;
            return;
        }

        stack<Page> temp = pages;  
        cout << "Browsing History (most recent to oldest):" << endl;
        while (!temp.empty()) {
            Page current = temp.top();
            cout << "Title: " << current.name << ", URL: " << current.link << endl;
            temp.pop();
        }
    }
};

int main() {
    History history;

    
    history.visitPage("https://www.google.com", "Google");
    history.visitPage("https://www.youtube.com", "YouTube");
    history.visitPage("https://www.github.com", "GitHub");

    
    history.showHistory();
    history.eraseHistory();
    history.showHistory();

    return 0;
}
