
// when will C++ get an actual sum type? :(
enum Color {red, black};


template <typename T>
class RedBlackTree {
private:
  class Node {
  public:
    T t;
    Color c;
    Node * l;
    Node * r;
    Node(T t, Color c, Node * l, Node * r) {
      this.t = t;
      this.c = c;
      this.l = l;
      this.r = r;
    }
  };
  Node * root;
  void deleteTree(Node * root) {
    if (nullptr != root->l) {
      deleteTree(root->l);
    }
    if (nullptr != root->r) {
      deleteTree(root->r);
    }
    delete root;
  }
  Node * copyTree(Node * other) {
    if (nullptr == other) return nullptr;
    Node * root;
    root = new Node(other->t, other->c, nullptr, nullptr);
    Node * left  = copyTree(other->l);
    Node * right = copyTree(other->r);
    root->l = left;
    root->r = right;
    return root;
  }
private:
  RedBlackTree() {
    root = nullptr;
  }
  
  RedBlackTree(T t) {
    root = new Node(t, black, nullptr, nullptr);
  }

  RedBlackTree(const RedBlackTree & other) {
    root = copyTree(other.root);
  }

  RedBlackTree(RedBlackTree && other) {
    root = other.root;
    other.root = nullptr;
  }
  
  ~RedBlackTree() {
    deleteTree(root);
  }
};
