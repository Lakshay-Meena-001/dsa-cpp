#include <iostream>
#include <string>

using namespace std;

class BrowserHistory
{
private:
    struct Node
    {
        string url;

        Node *prev;
        Node *next;

        Node(string u)
        {
            url = u;
            prev = NULL;
            next = NULL;
        }
    };

    Node *current;

public:
    // Constructor
    BrowserHistory(string homepage)
    {
        current = new Node(homepage);
    }

    // Visit a new URL
    void visit(string url)
    {
        Node *newNode = new Node(url);

        // Connect new node with current
        newNode->prev = current;
        current->next = newNode;

        // New node becomes current
        current = newNode;
    }

    // Move backward
    string back(int steps)
    {
        while (steps > 0 && current->prev != NULL)
        {
            current = current->prev;
            steps--;
        }

        return current->url;
    }

    // Move forward
    string forward(int steps)
    {
        while (steps > 0 && current->next != NULL)
        {
            current = current->next;
            steps--;
        }

        return current->url;
    }
};

int main()
{
    BrowserHistory browser("Google");

    browser.visit("YouTube");
    browser.visit("Amazon");
    browser.visit("LinkedIn");

    cout << "Back 1: "
         << browser.back(1) << endl;

    cout << "Back 1: "
         << browser.back(1) << endl;

    cout << "Forward 1: "
         << browser.forward(1) << endl;

    browser.visit("Netflix");

    cout << "Forward 2: "
         << browser.forward(2) << endl;

    return 0;
}