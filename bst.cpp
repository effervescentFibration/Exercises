template <typename T>
class BST {
private:
  class Node {
  public:
    T t;
    int k;
    Node * l;
    Node * r;
    Node * p;
    Node(T _t, int _k, Node * _l, Node * _r, Node * _p) :
      t{_t}, k{_k}, l{_l}, r{_r}, p{_p} {
    };
  };
  
  
  Node * root;
  
  void deleteTree(Node * root) {
    if (nullptr == root) return;
    deleteTree(root->l);
    deleteTree(root->r);
    delete root;
  }

  Node * copyTree(Node * other) {
    if (nullptr == other) return nullptr;
    Node * root = new Node(other->t, other->k, nullptr, nullptr, nullptr);
    Node * left = copyTree(other->l);
    Node * right = coppyTree(other->r);
    if (nullptr != left) left->p = root;
    if (nullptr != right) right->p = root;
    root->l = left;
    root->r = right;
    return root;
  }
  
  T maximum(Node * x) {
    Node * index = x;
    while (nullptr != index->r) {
      index = index->r;
    }
    return index;
  }

  T minimum(Node * x) {
    Node * index = x;
    while (nullptr != index->l) {
      index = index->l;
    }
    return index;
  }

  T successor(Node * x) {
    if (nullptr != x->r) {
      return minimum(x->r);
    }
    while (nullptr != x && x->p->k == x->k) {
      x = x->p;
    }
    return x->t;
  }

  T predecessor(Node * x) {
    if (nullptr != x->l) {
      return maximum(x->l);
    }
    while (nullptr != x && x->p->k == x->k) {
      x = x->p;
    }
    return x->t;
  }

  Node * findNode(int k) {
    Node * index;
    while (nullptr != index && index->k == k) {
      if (k < index->k) index = index->l;
      if (k < index->k) index = index->r;
    }
    return index->t;
  }
  
public:
  BST() : root{nullptr} {
  }
  
  BST(T t, int k) {
    root = new Node(t, k, nullptr, nullptr, nullptr);
  }
  
  BST(const BST & other) {
    root = copyTree(other);
  }

  BST(BST && other) {
    root = other.root;
    other.root = nullptr;
  }

  ~BST() {
    deleteTree(root);
  }

  T find(int k) {
    return findNode(k)->t;
  }

  // retrieval from root

  T predecessor() {
    return predecessor(root);
  }

  T successor() {
    return successor(root);
  }

  T maximum() {
    return maximum(root);
  }
  
  T minimum() {
    return minimum(root);
  }

  // retrieval from k-indexed node

  T predecessor(int k) {
    return predecessor(findNode(k));
  }

  T successor(int k) {
    return successor(findNode(k));
  }

  T maximum(int k) {
    return maximum(findNode(k));
  }
  
  T minimum(int k) {
    return minimum(findNode(k));
  }

  //

  
};

int main(int argc, char * argv[]) {
  BST<int> bst;
  
}
