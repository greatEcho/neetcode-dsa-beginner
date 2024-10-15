#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


// my solution
class MinStack {
private:
  std::vector<int> v{};
public:
    MinStack()  {
    }
    
    void push(int val) {
      v.push_back(val);
    }
    
    void pop() {
       v.pop_back(); 
    }
    
    int top() {
       return v.back(); 
    }
    
    int getMin() {
      std::vector<int> tmp;
      int min = top();
      while (v.size()) {
        if (top() < min)
          min = top();
        tmp.push_back( top() );
        pop();
      }

      // return all values to vector v
      while (tmp.size()) {
        push( tmp.back() );
        tmp.pop_back();
      }
      return min;
    }
};

// solution from neetcode and leetcode
class MinStack_nc {
private:
    std::stack<int> stk;
    std::stack<int> min_stk;
public:
    void push(int val)
    {
        stk.push(val);
        if (min_stk.empty())
            min_stk.push(val);
        else {
            // push only the current minimum
            min_stk.push(std::min(val, min_stk.top()));
        }
    }
    void pop(void)
    {
        min_stk.pop();
        stk.pop();
    }
    int top(void)
    {
        return stk.top();
    }
    int getMin(void)
    {
        return min_stk.top();
    }
};


int main(void)
{
    MinStack stk;
    stk.push(1); stk.push(2); stk.push(0);
    std::cout << stk.top() << ' ' << stk.getMin() << std::endl;
    stk.pop();
    std::cout << stk.top() << ' ' << stk.getMin() << std::endl;
    stk.pop();
    std::cout << stk.top() << ' ' << stk.getMin() << std::endl;

    std::cout << "------------------\n";

    MinStack_nc nc_stk;
    nc_stk.push(1); nc_stk.push(2); nc_stk.push(0);
    std::cout << nc_stk.top() << ' ' << nc_stk.getMin() << std::endl;
    nc_stk.pop();
    std::cout << nc_stk.top() << ' ' << nc_stk.getMin() << std::endl;
    nc_stk.pop();
    std::cout << nc_stk.top() << ' ' << nc_stk.getMin() << std::endl;

    return 0;
}
