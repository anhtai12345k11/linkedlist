#include <iostream>
using namespace std;


struct node{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

struct list{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

void khoitao(LIST &l ){
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE *khoitaoNode(int x){
    NODE *p = new NODE;
    if (p == NULL){
        cout << "\nko du bo nho";
        return NULL;
    }
    p -> data = x;
    p -> pNext = NULL;
    return p;
}


void themvaodau(LIST &l, NODE *p){
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else{
    p -> pNext = l.pHead;
    l.pHead = p;
    }
}

void themvaocuoi(LIST &l, NODE *p){
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else{
        l.pTail -> pNext = p;
        l.pTail = p;
    }
}

void input(LIST &l){
    khoitao(l);
    int n;
    cout << "\nNhap so luong can them: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cout << "\nNhap cac so nguyen: ";
        cin >> x;
        NODE *p = khoitaoNode(x);
        themvaodau(l, p);
    }
}

void output(LIST l){
    for (NODE *k = l.pHead; k != NULL; k = k -> pNext){
        cout << k -> data << " ";
    }
}

int main(){
    LIST l;
    khoitao(l);
    input(l);
    cout << "\nDS la: ";
    output(l);
    
    system("pause");
}


