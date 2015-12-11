/*************************************************************************
    > File Name: OptimalDecompositionProblem.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2015年12月11日 星期五 10时48分03秒
 ************************************************************************/
#include<iostream>
#include<cstdlib>

class Solution{
    public:
        int num;

        void SetNumber(){
            std::cout << "Please set the number" << std::endl;
            std::cin >> num;
        }

        void GetMax() {
            int pos = 0, i, max = 1;
            int factor[100];
            int temp;
            if(num < 1) {
                std::cout << "Input error!" << std::endl;
                return;
            }
            if(num == 1 || num == 2) {
                std::cout << "Max of all factor is 1" << std::endl;
                std::cout << "All factor: 1 + " << num-1 << " = " << num << std::endl;
                return;
            }

            if(num <= 4) {
                std::cout << "Max of all factor is "  << num-1 << std::endl;
                std::cout << "All factor: 1 + " << num-1 << " = " << num << std::endl;
            }else {
                factor[pos] = 2;
                num -=2 ;
                for(; num > factor[pos];)  {
                    factor[++pos] = (factor[pos] + 1);
                    num -= factor[pos];
                }

                if(num == factor[pos]) {
                    factor[pos]++;
                    num--;
                }
                for(i = 0; i < num; i++) {
                    factor[pos-i]++;
                    num--;
                }

                std::cout << "pos:" << pos << std::endl;
                for(i = 0; i <= pos; i++) {
                    std::cout << "No."<< i << " = "<< factor[i] << std::endl;
                    max *= factor[i];
                }
                std::cout << "Product is " << max << std::endl;
            }
        }

};

int main(int argc, char *argv[])
{
    Solution s;
    s.SetNumber();
    s.GetMax();
    return EXIT_SUCCESS;
}

