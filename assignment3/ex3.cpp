#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void Nhap(DATHUC &B, double heso, int somu) {
    DONTHUC* x = new DONTHUC(heso, somu);
    Node* node = new Node(x);
    if (B.head == nullptr) {
        B.head = node;
        B.tail = node;
    } else {
        B.tail -> next = node;
        B.tail = node;
    }
}

void Xuat(DATHUC B) {
    Node* node = B.head;
    int c1 = 0;
    int c2 = 0;
    int first = 1;
    while (node != nullptr) {
        c1++;
        double hs = node -> data -> heso;
        int sm = node -> data -> somu;
        if (first == 1) {
            if (hs == 0) { 
                c2++;
            } else if (hs == 1) {
                first = 0;
                if (sm == 0) {
                    cout << 1;
                } else if (sm == 1) {
                    cout << "x";
                } else {
                    cout << "x^" << sm;
                }
            } else if (hs == -1) {
                first = 0;
                if (sm == 0) {
                    cout << -1;
                } else if (sm == 1) {
                    cout << "-x";
                } else {
                    cout << "-x^" << sm;
                }
            } else {
                first = 0;
                if (sm == 0) {
                    cout << hs;
                } else if (sm == 1) {
                    cout << hs << "x";
                } else {
                    cout << hs << "x^" << sm;
                }
            }
        } else {
// ko phai la dau dong
            if (hs == 0) {
                c2++;
            } else if (hs == 1) {
                if (sm == 0) {
                    cout << "+1";
                } else if (sm == 1) {
                    cout << "+x";
                } else {
                    cout << "+x^" << sm;
                }
            } else if (hs == -1) {
                if (sm == 0) {
                    cout << "-1";
                } else if (sm == 1) {
                    cout << "-x";
                } else {
                    cout << "-x^" << sm;
                }
            } else {
                if (hs > 0) {
                    if (sm == 0) {
                        cout << "+" << hs;
                    } else if (sm == 1) {
                        cout << "+" << hs << "x";
                    } else {
                        cout << "+" << hs << "x^" << sm;
                    }
                } else {
                    if (sm == 0) {
                        cout << hs;
                    } else if (sm == 1) {
                        cout << hs << "x";
                    } else {
                        cout << hs << "x^" << sm;
                    }
                }
            }
        }
        node = node -> next;
    }
    if (c1 == c2) {
        cout << 0;
    }
}

double TinhDaThuc(DATHUC B, double x) {
    Node* node = B.head;
    double ans = 0;
    while (node) {
        ans += node -> data -> heso * pow(x, node -> data -> somu);
        node = node -> next;
    }
    return ans;
}


int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
