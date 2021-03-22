/*#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int make_palindrome(string s) {
    int n = s.size();
    int actions = 0;
    for(int i = 0, j = n-1; i < j; i++, j--)
        if (s[i] != s[j])
            actions ++;
    return actions;
}

int main() {
    ifstream cin("input.txt");

    string s;
    cin >> s;
    cout << make_palindrome(s);

    return 0;
}
 */


//MERGE SORT ALGORITHM
/*
 #include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
  int i = s + 1,j = s + 1;
  int pivot = s;

  while (j <= e) {
    if (arr[j] < arr[pivot]) {
      swap(arr[j], arr[i]);
      i ++;
    }
    j ++;
  }
  swap(arr[pivot], arr[i-1]);
  return i - 1;
}

void quick_sort(int arr[], int s, int e) {
  if (s >= e)
    return;
  int p = partition(arr, s, e);

  quick_sort(arr, s, p - 1);
  quick_sort(arr, p + 1, e);
}

int main() {
  int N = 8;
  int arr[N] = {4, 7, 5, 2, 6, 1, 3, 8};

  quick_sort(arr, 0, N-1);

  for (int i = 0; i < N; i++)
    cout << arr[i] << " ";

  return 0;
}
 */

/*
 * //ARRAY sort
 #include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 8;
  int arr[N] = {5, 3, 6, 4, 8, 1, 7, 2};

  sort(arr, arr + N);
  for(int i = 0; i < N; i++)
    cout << arr[i] << " ";

  return 0;
}
 */

/*
 * vector sort
 * #include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vect{5, 3, 6, 4, 8, 1, 7, 2};
  sort(vect.begin(), vect.end());

  for(int i = 0; i < vect.size(); i++)
    cout << vect[i] << " ";

  return 0;
}
 */

/*
 * Question: Given a list of integers, rearrange them so that all odd numbers
 * appear before even numbers. Additionally, odd numbers are in non-decreasing order and
 * even numbers are in non-increasing order.
 * #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compare(int a, int b) {
  int r1 = a%2;
  int r2 = b%2;
  if (r1 == 0 && r2 == 0)
    return a > b;
  if (r1 == 1 && r2 == 1)
    return a < b;
  if (r1 == 0) // r2 == 1
    return 0;
  else  // r1 == 1 & r2 == 0
    return 1;
}

int main() {
  vector<int> v = {1,2,3,4,5,6,7,8,9};
  sort(v.begin(), v.end(), compare);

  for (auto it : v) cout << it << " ";
  return 0;
}
 */

/*
 * INSERTION AT THE HEAD IN A SINGLY LINKED LIST
 * #include<iostream>

using namespace std;

struct Node {
  int val;
  Node* next;

  Node(int val) {
    this -> val = val;
  }
};

void print_list(Node* head) {
  struct Node* pCrawl = head;
  cout << " -> ";
  while (pCrawl != NULL) {
    cout << (pCrawl -> val) << " -> ";
    pCrawl = pCrawl -> next;
  }
  cout << "\n";
}

void insert_at_head(Node* &head, int val) {
  if (head == NULL) {     // Empty List
    head = new Node(val);
    return;
  }
  Node* newNode = new Node(val);
  newNode -> next = head;
  head = newNode;
}

int main() {
  Node* head = NULL;
  print_list(head);
  insert_at_head(head, 3); print_list(head);
  insert_at_head(head, 2); print_list(head);
  insert_at_head(head, 1); print_list(head);
}
 */

/*
 * INSERT AT THE GIVEN POSITION IN THE SINGLY LINKED LIST
 * #include<iostream>

using namespace std;

struct Node {
  int val;
  Node* next;

  Node(int val) {
    this -> val = val;
  }
};

void print_list(Node* head) {
  struct Node* pCrawl = head;
  cout << " -> ";
  while (pCrawl != NULL) {
    cout << (pCrawl -> val) << " -> ";
    pCrawl = pCrawl -> next;
  }
  cout << "\n";
}

void insert_at_head(Node* &head, int val) {
  if (head == NULL) {     // Empty List
    head = new Node(val);
    return;
  }
  Node* newNode = new Node(val);
  newNode -> next = head;
  head = newNode;
}


void insert_at_position(Node* &head, int val, int pos) {
  struct Node* pCrawl = head;
  for (int i = 0; i < pos - 1; i++)
    pCrawl =  pCrawl -> next;

  Node *A = pCrawl;
  Node *B = pCrawl->next;
  Node* C = new Node(val);
  A -> next = C;
  C -> next = B;
}


int main() {
  Node* head = NULL;
  print_list(head);
  insert_at_head(head, 4); print_list(head);
  insert_at_head(head, 1); print_list(head);
  insert_at_position(head, 2, 1); print_list(head);  // 0-based position
  insert_at_position(head, 3, 2); print_list(head);
}
 */


/*
 * INSERT AT THE END IN A SINGLY LINKED LIST
 * #include<iostream>

using namespace std;

struct Node {
  int val;
  Node* next;

  Node(int val) {
    this -> val = val;
  }
};

void print_list(Node* head) {
  struct Node* pCrawl = head;
  cout << " -> ";
  while (pCrawl != NULL) {
    cout << (pCrawl -> val) << " -> ";
    pCrawl = pCrawl -> next;
  }
  cout << "\n";
}

void insert_at_end(Node* &head, int val) {
  // List is empty
  if (head == NULL) {
    head = new Node(val);
    return ;
  }
  struct Node* pCrawl = head;
  while(pCrawl->next != NULL) {        // iterate to last node
    pCrawl =  pCrawl -> next;
  }
  pCrawl -> next = new Node(val);
}


int main() {
  Node* head = NULL;
  print_list(head);
  insert_at_end(head, 1); print_list(head);
  insert_at_end(head, 2); print_list(head);
  insert_at_end(head, 3); print_list(head);
}
 */



/*
 * DELETING AT A GIVEN POSITION IN SINGLY LINKED LIST
 * #include<iostream>

using namespace std;

struct Node {
  int val;
  Node* next;

  Node(int val) {
    this -> val = val;
  }
};

void print_list(Node* head) {
  struct Node* pCrawl = head;
  cout << " -> ";
  while (pCrawl != NULL) {
    cout << (pCrawl -> val) << " -> ";
    pCrawl = pCrawl -> next;
  }
  cout << "\n";
}

void insert_at_end(Node* &head, int val) {
  // List is empty
  if (head == NULL) {
    head = new Node(val);
    return ;
  }
  struct Node* pCrawl = head;
  while(pCrawl->next != NULL) {        // iterate to last node
    pCrawl =  pCrawl -> next;
  }
  pCrawl -> next = new Node(val);
}

void delete_at_position(Node* &head, int pos) {
  struct Node* A = head;
  for (int i = 0; i < pos - 1; i++) {
    A =  A->next;
  }
  Node *C = A->next;
  Node *B = A->next->next;
  A->next = B;
  delete C;
}

int main() {
  Node* head = NULL;
  insert_at_end(head, 1);
  insert_at_end(head, 2);
  insert_at_end(head, 3);
  insert_at_end(head, 4);
  insert_at_end(head, 5);

  print_list(head);
  delete_at_position(head, 2); print_list(head);  // 0-based position
  delete_at_position(head, 3); print_list(head);
}
 */


/*
 * PRINTING STACKS
 * #include <bits/stdc++.h>
using namespace std;

struct Stack {
  static const int SZ = 4;
  int arr[SZ];
  int top;

  Stack() {
    top = -1;
  }

  bool isEmpty() {
    return (top < 0);
  }

  void push(int x) {
    if (top == SZ - 1) {
      cout << "Stack Overflow";
      return;
    }
    arr[++top] = x;
  }

  int peek() {
      if (top < 0) {
        cout << "Empty Stack";
        return -1;
      }
      return arr[top];
  }

  int pop() {
    if (top < 0) {
      cout << "Stack Underflow";
      return - 1;
    }
    return arr[top--];
  }

  void print_stack() {
    for (int i = 0; i <= top; i++)
      cout << arr[i] << " <- ";
    cout << "\n";
  }
};

int main() {
  Stack stack;
  stack.print_stack();
  stack.push(1);  stack.print_stack();
  stack.push(2);  stack.print_stack();
  stack.push(3);  stack.print_stack();
  stack.pop();  stack.print_stack();
  stack.pop();  stack.print_stack();
  return 0;
}
 */


/*
#include <iostream>
#include <vector>
using namespace std;

char opening(char c) { // get opening bracket of same type
    if (c == ')') return '(';
    if (c == ']') return '[';
    if (c == '}') return '{';
}

bool is_opening(char c){
    return c == '(' || c == '[' || c == '{';
}

bool is_closing(char c) {
    return !is_opening(c);
}

string is_balanced(string s) {
    int N = s.size();
    vector<bool> matched(N, false);

    for (int i = 0; i < N ;i ++) {
        if (is_closing(s[i])) {
            int found_pos = -1; // position of mathcing opening bracket
            for (int j = i - 1; j >= 0; j--){
                if ( !matched[j] && is_opening(s[j]) && s[j] == opening(s[i]) ) {
                    found_pos = j;
                    break;
                }
            }
            if (found_pos == -1) // didn't find matching bracket
                return "No\n";

            matched[i] = matched[found_pos] = true;
        }
    }

    return "Yes\n"; //Nothing went wrong, all brackets matched
}

int main() {
    cout << is_balanced("[()]{}{[()()]()}");
    cout << is_balanced("]]");
    cout << is_balanced("[(){[]({})}]");
    cout << is_balanced("[(){[)({})}]");
    return 0;
}

*/



/*
 * PARANTEZLERI ACMA KAPAMAYI DOGRU OLP OLMADIGINI GOSTEREN STACK YAPISI KULLANAN KOD

#include <iostream>
#include <stack>
using namespace std;

char opening(char c) { // get opening bracket of same type
    if (c == ')') return '(';
    if (c == ']') return '[';
    if (c == '}') return '{';
}

bool is_opening(char c){
    return c == '(' || c == '[' || c == '{';
}

bool is_closing(char c) {
    return !is_opening(c);
}

string is_balanced(string s) {
    int N = s.size();
    stack<char> S;

    for (int i = 0; i < N ;i ++) {
        if (is_opening(s[i]))
            S.push(s[i]);
        else {
            if (S.empty())
                return "No\n"; // Looking for opening brakcet but stack it empty => Not balanced
            char c = S.top();

            if (c != opening(s[i]))  // top is not mathcing!
                return "No\n";

            S.pop(); // top matched, remove from stack
        }
    }

    return "Yes\n"; //Nothing went wrong, all brackets matched
}

int main() {
    cout<<is_balanced("[()]{}{[()()]()}");
    cout<<is_balanced("]]");
    cout<<is_balanced("[(){[]({})}]");
    cout<<is_balanced("[(){[)({})}]");
    return 0;
}
 */

