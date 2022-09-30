class MedianFinder {
public:    
    void addNum(int num) {
        myset.insert(num);
        if (myset.size() == 1) {mid = myset.begin(); return;}
        if(myset.size()%2 && num >= *mid) mid++;
        else if (!(myset.size()%2) && num < *mid) mid--;
    }
    
    double findMedian() {
        if(myset.size()%2) {
            return *mid;
        }
        else {
            return double(*mid + *next(mid,1))/2;
        }
    }
private:
    multiset<int> myset;
    multiset<int>::iterator mid;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
