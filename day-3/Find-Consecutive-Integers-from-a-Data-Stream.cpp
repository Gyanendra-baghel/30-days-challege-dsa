class DataStream {
    int k;
    int value;
    map<int, int> m;
    queue<int> q;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        q.push(num);
        m[num]++;
        if(q.size() >= k) {
            if(q.size() > k) {
                m[q.front()]--;
                if(m[q.front()] == 0) {
                    m.erase(q.front());
                }
                q.pop();
            }
            
            if(m.size() == 1 && m[value] > 0) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */