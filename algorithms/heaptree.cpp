#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using std::cout; using std::vector; using std::max; using std::pow; using std::log2;
using std::ceil; using std::swap;

class Binarytree
{
    private:
        vector<double> tree;
        int insind;
    public:
        Binarytree(vector<double> v)
        {
            tree = v;
            insind = v.size();
        }

        int size()
        {
            return tree.size();    
        }

        double at(int index)
        {
            return tree[index];
        }

        int getParentInd(int index)
        {
            return (index + 1) / 2 - 1;            
        }

        int getGreaterChildInd(int index)
        {
            int first = (index + 1) * 2 - 1;
            int second = (index + 1) * 2;
            if (first > size() - 1 || second > size() - 1) {
                return -1;
            }

            return max(tree[first], tree[second]) == tree[first] ? first : second;
        }

        void insert(double val)
        {
            static bool level1 = true;
            if (level1) {
                tree.push_back(val);
            }

            const int parentind = getParentInd(insind);
            if (val > tree[parentind] && parentind >= 0) {
                tree[insind] = tree[parentind];
                tree[parentind] = val;
                insind = parentind;
                level1 = false;

                return insert(val);
            }
            insind = size();
            level1 = true;
        }

        void deleteroot()
        {
            tree[0] = tree[size() - 1];
            int index = 0;
            tree.pop_back();
            int gc = getGreaterChildInd(index);
            while (gc != -1) {
                if (tree[gc] > tree[index]) {
                    swap(tree[index], tree[gc]);
                    index = gc;
                }
                else {
                    break;
                }
            }
        }

        /*void sort(int restrict = -1)
        {
            if (restrict == -1) {
                restrict = size();
            }
            int temp0 = tree[0];
            tree[0] = tree[restrict - 1];
            int index = 0;
            while (getGreaterChildInd(index) != -1) {
                int temp = tree[index];
                if (tree[getGreaterChildInd(index)] > temp) {
                    tree[index] = tree[getGreaterChildInd(index)];
                    tree[getGreaterChildInd(index)] = temp;
                    index = getGreaterChildInd(index);
                }
                else {
                    break;
                }
            }
            if (restrict > 1) {
                return sort(restrict - 1);
            }
        }*/
};

int main()
{
    vector<double> initvec {50, 30, 20, 15, 10, 8, 16};
    Binarytree tree(initvec);
    /*tree.insert(60);
    for (int i = 0; i < tree.size(); ++i) {
        cout << tree.at(i) << " ";
    }
    cout << "\n";*/
    tree.deleteroot();
    for (int i = 0; i < tree.size(); ++i) {
        cout << tree.at(i) << " ";
    }
}