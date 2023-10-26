/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//вариант4
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int size;
    setlocale(LC_ALL,"russian");
    cout << "Введите кол-во заказов: ";
    cin >> size;
    vector <string> tov(size);
    vector <int> kv(size);
    vector <double> pr(size);
    double sum = 0;
    for(int i = 0; i < size;i++)
    {
        string s;
        int a;
        double b;
        cin.ignore();
        cout <<"Введите название товара " << i + 1 << " ";
        getline(cin,s);
        cout <<"Введите количество товара " << i + 1 << " ";
        cin >> a;
        cout <<"Введите стоимость товара " << i + 1 << " ";
        cin >> b;
        tov[i] = s;
        kv[i] = a;
        pr[i] = b;
        sum += double(double(a) * b);
        cout << "Общая стоимость заказа " << i + 1 << " =" << b * double(a) << endl;
    }
    for(int i = 0;i < size;i++)
    {
        for(int j = i + 1;j < size;j++)
        {
            string is = tov[i];
            string js = tov[j];
            int si = is.size();
            int sj = js.size();
            int ms = min(si,sj);
            for(int k = 0;k < ms;k++)
            {
                if(js[k] < is[k])
                {
                    swap(tov[i],tov[j]);
                    swap(kv[i],kv[j]);
                    swap(pr[i],pr[j]);
                    break;
                }
            }
        }
    }
    for(int i = 0; i < size;i++)
    {
        cout << tov[i] << " - Количество: " <<kv[i] <<", Цена за единицу: " <<pr[i] << endl; 
    }
    cout << "Общая сумма всех заказов: " << sum;
}