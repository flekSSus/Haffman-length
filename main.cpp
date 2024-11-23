#include <fstream>
#include <iostream>
#include <vector>


int main()
{
    std::ifstream in("huffman.in");
    std::ofstream out("huffman.out");

    size_t sz(0);
    size_t code_length(0);
    std::vector<int> arr_freq;
    size_t num_of_unif(0);

    in>>sz;

    num_of_unif=sz-1;
    arr_freq.resize(sz,0);
    for(size_t i(0);i<sz;++i)
    {
        in>>arr_freq[i];
    }

    code_length+=num_of_unif*arr_freq[0];
    code_length+=num_of_unif*arr_freq[1];
    for(size_t i(2);i<arr_freq.size();++i)
    {
        code_length+=arr_freq[i]*(num_of_unif-i+1);    
    }

    out<<code_length;

    in.close();
    out.close();
    
}
