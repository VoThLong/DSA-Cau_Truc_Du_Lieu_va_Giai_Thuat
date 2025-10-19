/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
[
]
###End banned keyword*/
#include <iostream>
#include <cmath>

using namespace std;

class Point3D
{
    private:
        double x, y, z;
    public:
        Point3D(double x = 0, double y = 0, double z = 0)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        void Input()
        {
            cin >> x >> y >> z;
        }
        void Display() const
        {
            cout << x << " " << y << " " << z << "\n";
        }
        double DistanceTo(const Point3D& other) const
        {
            return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
        }
               friend bool operator==(const Point3D& p1, const Point3D& p2)
        {
            return (p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z);
        }
};

struct Node
{
    Point3D data;
    Node* next;
};

class LinkedList
{
    private:
        Node* pHead;
        Node* pTail;
        int count;
    public:
        LinkedList()
        {
            pHead = nullptr;
            pTail = nullptr;
            count = 0;
        }
        ~LinkedList()
        {
            Node* tmp = this->pHead;
            while(tmp != nullptr)
            {
                this->pHead = this->pHead->next;
                delete tmp;
                tmp = this->pHead;
            }
        }
        void AddHead(Point3D value)
        {
            Node* newNode = new Node{value, pHead};
            pHead = newNode;
            if (pTail == nullptr)
            {
                pTail = newNode;
            }
            count++;
        }
        void AddTail(Point3D value)
        {
            Node* newNode = new Node{value, nullptr};
            if (pTail != nullptr)
            {
                pTail->next = newNode;
            }
            pTail = newNode;
            if (pHead == nullptr)
            {
                pHead = newNode;
            }
            count++;
        }
        Node* GetHead() const
        {
            return pHead;
        }

};

void run() {
    int n;
    cin >> n;
    LinkedList list1;
    for (int i = 0; i < n; i++) {
        Point3D point;
        point.Input();
        list1.AddTail(point);
    }
    int m;
    cin >> m;
    LinkedList list2;
    for (int i = 0; i < m; i++) {
        Point3D point;
        point.Input();
        list2.AddTail(point);
    }

    for (Node* p1 = list2.GetHead(); p1 != nullptr; p1 = p1->next) {
        Node* temp = list1.GetHead();
        int count = 0;
        bool check = false;
        while (temp != nullptr)
        {
            if (temp->data == p1->data) {
                cout << count << "\n";
                check = true;
            }
            count++;
            temp = temp->next;
        }
        if (!check) {
            cout << "KHONG\n";
        }
    }

}

int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}