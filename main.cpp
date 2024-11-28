#include <iostream>
#include <fstream>
#include<queue>

int main() 
{
    
    std::ifstream in("huffman.in");
    std::ofstream out("huffman.out");

    int numOfEl(0);
    long long sumOfTwoMin(0);
    long long codeLength(0);

    in>>numOfEl;

    std::priority_queue<long long ,std::vector<long long>,std::greater<long long>> heap;
    
    int tmp(0);
    in>>tmp;
    sumOfTwoMin+=tmp;
    in>>tmp;
    sumOfTwoMin+=tmp;
    heap.push(sumOfTwoMin);
    codeLength+=sumOfTwoMin;

    for(int i(2),tmp(0);i<numOfEl;++i)
    {
        in>>tmp;
        heap.push(tmp);
    }


    while(heap.size()!=1)
    {
        sumOfTwoMin=heap.top();
        heap.pop();
        sumOfTwoMin+=heap.top();
        heap.push(sumOfTwoMin);
        heap.pop();
        codeLength+=sumOfTwoMin;
    }
   



    out<<codeLength;

    return 0;
}
