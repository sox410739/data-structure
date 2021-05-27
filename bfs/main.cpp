#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int num;
    int stage;
    vector<Node*> edge;
};
struct Node* newNode(int num);
struct Node* sear(int num, vector<Node*>& allNode);
void connect(struct Node* temp1, struct Node* temp2);
int BFS(struct Node* start);

int main()
{
    int num = 0;
    vector<Node*> allNode;
    cin >> num;
    for(int i=0;i<num;i++){
        int temp1 = 0;
        int temp2 = 0;
        cin >> temp1 >> temp2;
        Node* node1 = sear(temp1, allNode);
        Node* node2 = sear(temp2, allNode);
        connect(node1, node2);
    }
    if(BFS(allNode.at(0)) == allNode.size()){
        cout << "Connected!!" << endl;
    }
    else{
        cout << "Not connected!!" << endl;
    }

    return 0;
}

struct Node* newNode(int num){
    Node* temp = new Node;
    temp->num = num;
    temp->stage = 0;

    return temp;
}

struct Node* sear(int num, vector<Node*>& allNode){
    for(int i=0;i<allNode.size();i++){
        if(allNode.at(i)->num == num){
            return allNode.at(i);
        }
    }
    Node* temp = newNode(num);
    allNode.push_back(temp);

    return temp;
}

void connect(struct Node* temp1, struct Node* temp2){
    temp1->edge.push_back(temp2);
    temp2->edge.push_back(temp1);
}

int BFS(struct Node* start){
    int cou = 0;
    queue<Node*> q;
    start->stage = 1;
    q.push(start);
    while(!q.empty()){
        for(int i=0;i<q.front()->edge.size();i++){
            if(q.front()->edge.at(i)->stage == 0){
                q.front()->edge.at(i)->stage = 1;
                q.push(q.front()->edge.at(i));
            }
        }
        q.pop();
        cou++;
    }

    return cou;
}
