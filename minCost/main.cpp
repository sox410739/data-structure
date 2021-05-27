#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int num;
    int stage;
    vector<Node*> edge;
    vector<int> distance;
};
struct Node* newNode(int num);
struct Node* build(int num, vector<Node*>& allNode);
void connect(struct Node* node1, struct Node* node2, int dis);
int cost(struct Node* start, int numOfNode, int Maxdis);


int main()
{
    int num = 0;
    cin >> num;
    vector<Node*> allNode;
    int Maxdis = 0;
    for(int i=0;i<num;i++){
        int temp1 = 0;
        int temp2 = 0;
        int temp3 = 0;
        cin >> temp1 >> temp2 >> temp3;
        if(temp3 > Maxdis){
            Maxdis = temp3;
        }
        Node* node1 = build(temp1, allNode);
        Node* node2 = build(temp2, allNode);
        connect(node1, node2, temp3);
    }

    cout << cost(allNode.at(0), allNode.size(), Maxdis) << endl;

    return 0;
}

struct Node* newNode(int num){
    Node* temp = new Node;
    temp->num = num;
    temp->stage = 0;

    return temp;
}

struct Node* build(int num, vector<Node*>& allNode){
    for(int i=0;i<allNode.size();i++){
        if(allNode.at(i)->num == num){
            return allNode.at(i);
        }
    }

    Node* temp = newNode(num);
    allNode.push_back(temp);

    return temp;
}

void connect(struct Node* node1, struct Node* node2, int dis){
    node1->edge.push_back(node2);
    node1->distance.push_back(dis);
    node2->edge.push_back(node1);
    node2->distance.push_back(dis);
}

int cost(struct Node* start, int numOfNode, int Maxdis){
    int cost = 0;
    vector<Node*> found;
    start->stage = 1;
    found.push_back(start);
    while(found.size() < numOfNode){
        int mini = Maxdis;
        Node* temp = NULL;
        for(int i=0;i<found.size();i++){
            for(int j=0;j<found.at(i)->edge.size();j++){
                if(found.at(i)->edge.at(j)->stage == 0){
                    if(found.at(i)->distance.at(j) <= mini){
                        mini = found.at(i)->distance.at(j);
                        temp = found.at(i)->edge.at(j);
                    }
                }
            }
        }
        cost = cost + mini;
        temp->stage = 1;
        found.push_back(temp);
    }

    return cost;
}

