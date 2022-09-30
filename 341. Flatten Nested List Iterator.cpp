/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push(nestedList);
        index.push(0);
    }
    
    int next() {
        return s.top()[index.top()++].getInteger();
    }
    
    bool hasNext() {
        if (index.top() < s.top().size()) {
            NestedInteger &curr = s.top()[index.top()];
            if (curr.isInteger()) return true;
            s.push(curr.getList());
            index.push(0);
            return hasNext();
        }
        else {
            index.pop();
            s.pop();
            if (index.empty()) return false;
            index.top() += 1;
            return hasNext();
        }
    }
private:
    stack<vector<NestedInteger>> s;
    stack<int> index;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
