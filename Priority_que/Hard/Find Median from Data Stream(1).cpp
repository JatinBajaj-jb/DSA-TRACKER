// Approach : we use two heaps one on the left side being max heap storing left median or median value and the other one being min heap storing right median value in 
//            in case of the list is even
class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    int s1=0,s2=0; 
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(pq1.empty() ||num<pq1.top()){
            pq1.push(num);
            s1++;
        }
        else{
            pq2.push(num);
            s2++;
        }
        if(s2>s1){
            pq1.push(pq2.top());
            pq2.pop();
            s2--;
            s1++;
        }
        if(s1-s2>1){
            pq2.push(pq1.top());
            pq1.pop();
            s2++;
            s1--;
        }
    }
    
    double findMedian() {
        if(s2==s1){
            return((pq1.top()+pq2.top())*0.5);
        }
        else return pq1.top();
    }
};
