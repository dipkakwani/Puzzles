#include <iostream>
using namespace std;

class Node {
public:
    Node *next;
    int data;
};

Node* insertIntoList(Node *cur, int data) {
    if(cur == nullptr) {
        cur = new Node();
        cur->data = data;
        cur->next = nullptr;
    }
    else {
        cur->next = insertIntoList(cur->next, data);
    }
    return cur;
}

long long getNumber(Node *head) {
    int count = 0;
    bool a[64];
    Node *temp = head;
    for (int i = 0; temp != nullptr; i++)
    {
        a[i] = (temp->data);
        temp = temp->next;
        count++;
    }
    long long res = 0, power = 1;
    for (int i = count - 1; i >= 0; i--)
    {
        res += (a[i] * power);
        power *= 2;
    }
    return res;
    
}

int main()
{
    int N;
    cin >> N;
    Node *head = nullptr;

    for(int i = 0; i < (int)N; ++i) {
        int curData;
        cin >> curData;
        head = insertIntoList(head, curData);
    }

    cout << getNumber(head) << endl;

    return 0;
}