/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
[
]
###End banned keyword*/
#include <iostream>
#include <cmath>

using namespace std;
//###INSERT CODE HERE -

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

int main()
{
    LinkedList list;
    int n;
    cin >> n;
    double b, e;
    for (int i = 0; i < n; i++)
    {
        Point3D point;
        point.Input();
        list.AddTail(point);
    }
    cin >> b >> e;
    Point3D O (0, 0, 0);
    bool empty = true;
    Node* tmp = list.GetHead();
    while (tmp != nullptr)
    {
        if (tmp->data.DistanceTo(O) > b && tmp->data.DistanceTo(O) < e)
        {
            tmp->data.Display();
            empty = false;
        }
        tmp = tmp->next;
    }
    if (empty)
    {
        cout << "KHONG";
    }
    return 0;
}
