class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum_ = 0;
        size_ = size;
    }
    
    double next(int val) {
        data_.push(val);
        sum_ += val;
        if (data_.size() > size_) {
            int first = data_.front();
            data_.pop();
            sum_ -= first;
        }
        return (double) sum_ / data_.size();
    }
    
private:
    int sum_, size_;
    queue<int> data_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
