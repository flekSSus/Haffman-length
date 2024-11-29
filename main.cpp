#include <iostream>
#include <fstream>
#include <vector>

int main() 
{
    
    std::ifstream in("huffman.in");
    std::ofstream out("huffman.out");

    int numOfEl(0);
    long long codeLength(0);

    std::vector<long long> freq;
    std::vector<long long> sum;
    in>>numOfEl;

    freq.resize(numOfEl,0);

    for(int i(0);i<numOfEl;++i)
    {
        in>>freq[i];
    }

    int firstMinIndex(0),secondMinIndex(0);

    while(firstMinIndex<numOfEl ||  secondMinIndex<sum.size()-1)
    {
        long long firstMin(0),secondMin(0);
        long long sumOfTwo(0);

        if(secondMinIndex>=sum.size() || (firstMinIndex<numOfEl && freq[firstMinIndex]<=sum[secondMinIndex]))
        {
            firstMin=freq[firstMinIndex];
            ++firstMinIndex;
        }
        else 
        {
            firstMin=sum[secondMinIndex];
            ++secondMinIndex;
        }

        if(secondMinIndex>=sum.size() || (firstMinIndex<numOfEl && freq[firstMinIndex]<=sum[secondMinIndex]))
        {
            secondMin=freq[firstMinIndex];
            ++firstMinIndex;
        }
        else 
        {
            secondMin=sum[secondMinIndex];
            ++secondMinIndex;
        }

        sumOfTwo=firstMin+secondMin;
        codeLength+=sumOfTwo;
        sum.push_back(sumOfTwo);
    }

    out<<codeLength;

    return 0;
}
