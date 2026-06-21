class BrowserHistory {
public:
    vector<string> visits;
    int current;
    int size;
    BrowserHistory(string homepage) {
        visits.push_back(homepage);
        size = 1;
        current = 0;
    }
    
    void visit(string url) {
        ++current;
        if(current == size) {
            visits.push_back(url);
            ++size;
            
        } else {
            visits[current] = url;
            size = current + 1;
        } 
    }
    
    string back(int steps) {
        current = max(0, current - steps);
        return visits[current];
    }
    
    string forward(int steps) {
        current = min(size - 1, current + steps);
        return visits[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */