
template <T>
class BST {
private:
  struct Node {
    T t;
    Node * r;
    Node * l;
    Node * p;
  };
  
  Node * root;
  
  void deleteTree(Node * root) {
    if (nullptr == root) {
      return;
    }
    if (nullptr != root->l) {
      deleteTree(root->l);
    }
    if (nullptr != root->r) {
      deleteTree(root->l);
    }
    delete root;
  }
  
  Node * copyTree(const Node * root) {
    if (nullptr == root) return nullptr;
    Node * copy = new Node;
    copy->t = root->t;
    copy->r = copyTree(root->r);
    copy->l = copyTree(root->l);
    return copy;
  }
public:
  BST() {
    root = nullptr;
  }
  BST(T t) {
    root = new Node;
    root->t = t;
    root->l = nullptr;
    root->r = nullptr;
    root->p = nullptr;
  }
  BST(const BST & other) {
    root = copyTree(other.root);
    root->p = nullptr;
  }
  BST(BST && other) {
    root = other.root;
    other.root = nullptr;
  }
  void insert(T t) {
    Node * index = root;
    Node * parent = root->p;
    while (index != nullptr) {
      parent = index;
      if (index->t < t) {
        index = index->l;
      } else {
        index = index->r;
      }
    }
    index = new Node;
    Node->t = t;
    Node->l = nullptr;
    Node->r = nullptr;
    Node->p = parent;
  }
  int remove(T t) {
    Node * index = root;
    // Node * parent = root->p;
    while (index != nullptr) {
      parent = index;
      if (index->t == t) {
        if (nullptr != index->l && nullptr != index->r) {
          index->l->p = parent;
          if (index == parent->l) parent->l = index->l;
          else parent->r = index->l;
          Node * subindex = index->l;
          subparent = index;
          while (nullptr != subindex) {
            subparent = subindex;
            if (index->r->t < subindex->t) {
              subindex = subindex->l;
            }
            else {
              subindex = subindex->r;
            }
          }
          if (subparent->t < index->r>t) {
            subparent->l = index->r;
          }
          else {
            subparent->r = index->r;
          }
          index->r->p = subparent;
        }
        else if (nullptr != index->l) {
          index->l->p = parent;
          if (index == parent->l) parent->l = index->l;
          else parent->r = index->l;
        }
        else if (nullptr != index->r) {
          index->r->p = parent;
          if (index == parent->l) parent->l = index->r;
          else parent->r = index->r;
        }
        delete index;
        return 0;
      }
      else if (index->t < t) {
        index = index->l;
      }
      else {
        index = index->r;
      }
    }
    return -1;
  }
};
