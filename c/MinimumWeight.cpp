/*************************************************************************
  > File Name: MinimumWeight.cpp
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Organization: Xiyou Linux Group
  > Created Time: 2015年12月16日 星期三 15时32分17秒
 ************************************************************************/
#include<iostream>

#define N 1000

class Solution {
    public:
        int ComponentNum;
        int SupplierNum;
        int Price;
        int cp;
        int cw;
        int sum;
        int c[N][N], w[N][N];

        Solution():cp(0), cw(0), sum(N) {}
        ~Solution() {}
        void callback(int i) {
            if(i > ComponentNum) {
                if(cw < sum) {
                    sum = cw;
                }
                return;
            }
            for(int j = 0; j < SupplierNum; j++) {
                cw += w[i][j];
                cp += c[i][j];
                if(cw < sum && cp <= Price) {
                    callback(i+1);
                }
                cw -= w[i][j];
                cp -= c[i][j];
            }
        }

        void SetTheWeightAndPrice() {
            std::cout << "Please input the every price:" << std::endl;
            for(int i = 0; i < ComponentNum; i++)  {
                for(int j = 0; j < SupplierNum; j++)  {
                    std::cin >> c[i][j];
                }
            }

            std::cout << "Please input the every weight:" << std::endl;
            for(int i = 0; i < ComponentNum; i++) {
                for(int j = 0; j < SupplierNum; j++)  {
                    std::cin >> w[i][j];
                }
            }
        }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::cout << "Input the number of the Component :";
    std::cin >> s.ComponentNum;
    std::cout << "Input the number of the Supplier :";
    std::cin >> s.SupplierNum;
    std::cout << "Lowest price?";
    std::cin >> s.Price;

    s.SetTheWeightAndPrice();
    s.callback(0);

    std::cout << "Min weight = " << s.sum << std::endl;
    return EXIT_SUCCESS;
}

